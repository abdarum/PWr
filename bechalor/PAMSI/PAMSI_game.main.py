#/usr/bin/python3
"""Merge sort, quick sort, introspective sort and testing functions"""

#import built-in modules

import os
import math
import copy
import time

import pygame
import tkinter as tk


__author__ = 'Kornel Stefańczykr'
__license__ = 'CC BY-SA'
__version__ = '0.5'
__maintainer__ = 'Kornel Stefańczyk'
__email__ = 'kornelstanczyk@wp.pl'


def debug(msg, active_debugging=True, end_=None):
    """Print msg to terminal"""
    if active_debugging:
        if end_:
            print(msg, end=end_)
        else:
            print(msg)


class GameAI:
    def __init__(self, current_data=None, max_player=None, max_depth=None):
        self.current_data=current_data
        if max_player: self.max_player = max_player
        else:          self.max_player = self.current_data.ai_player
        if max_depth: self.max_depth = max_depth
        else:     self.max_depth = self.current_data.ai_max_depth
        self.best_move = None
        self.MIN = -1000
        self.MAX = 1000

    def minmax(self, scores, depth=None, node_index=None, maximalizer=None,
            h=None):
        """
         Returns the optimal value a maximizer can obtain.
           depth     - current depth in game tree.
           nodeIndex - index of current node in scores[].
           isMax     - true if current move is of maximizer, else false
           scores[]  - stores leaves of Game tree.
           h         - maximum height of Game tree
        """
        if scores.__class__.__name__ != 'list':
            raise Exception('scores is not list')
        if depth == None:
            depth = self.depth
        if node_index == None:
            node_index = 0
        if maximalizer == None:
            maximalizer = True
        if h == None:
            h = math.floor(math.log2(len(scores)))

        if h == depth:
            return scores[node_index]
        if maximalizer:
            return max(self.minmax(scores=scores, depth=depth+1, node_index=node_index*2,
                maximalizer=False, h=h),
                self.minmax(scores=scores, depth=depth+1, node_index=node_index*2+1,
                maximalizer=False, h=h))
        else:
            return min(self.minmax(scores=scores, depth=depth+1, node_index=node_index*2,
                maximalizer=True, h=h),
                self.minmax(scores=scores, depth=depth+1, node_index=node_index*2+1,
                maximalizer=True, h=h))

    def minmax_alpha_beta(self, board=None, depth=None, alpha=None, beta=None,
            player=None, max_depth=None):
        if alpha == None:
            alpha = self.MIN
        if beta == None:
            beta = self.MAX
        if depth == None:
            depth = 0
        if board == None:
            board = self.current_data.matrix
        if max_depth == None:
            max_depth = self.max_depth
        if player == None:
            player = self.current_data.current_player
        winner = self.current_data.find_winner(board=board,
                mem_mode=False)
        if winner:
            return self.evaluate(board, depth)
        if depth >= max_depth:
            return self.evaluate(board, depth)
        depth += 1
        posible_moves = self.find_all_moves(board=board)
        if player == self.current_data.ai_player:
            for move in posible_moves:
                tmp_board = self.current_data.return_board(old_board=board,
                        mov_row=move[0], mov_col=move[1],
                        mov_usr=player)
                result = self.minmax_alpha_beta(board=tmp_board,depth=depth,
                        alpha=alpha, beta=beta,
                        player=self.current_data.return_oponent(oponent_to=player))
                if result > alpha:
                    alpha = result
                    if depth == 1:
                        self.best_move = move
                elif alpha >= beta:
                    return alpha
            return alpha
        else:
            for move in posible_moves:
                tmp_board = self.current_data.return_board(old_board=board,
                        mov_row=move[0], mov_col=move[1],
                        mov_usr=player)
                result = self.minmax_alpha_beta(board=tmp_board,depth=depth,
                        alpha=alpha, beta=beta,
                        player=self.current_data.return_oponent(oponent_to=player))
                if result < beta:
                    beta = result
                    if depth == 1:
                        self.best_move = move
                elif alpha >= beta:
                    return beta
            return beta

    def best_move(self):
        """Return row and column of best move"""
        if self.best_move != None:
            return self.best_move[0], self.best_move[1]

    def evaluate(self, board=None, depth=None):
        if board == None:
            board = self.current_data.matrix
        if depth == None:
            depth = 0
        winner = self.current_data.detect_win(board)
        if winner:
            if winner == self.max_player:
                return 10-depth
            else:
                return depth-10
        else:
            return 0

    def find_all_moves(self,board=None):
        moves_list = []
        if board == None:
            board = self.current_data.matrix
        for i in range(0, self.current_data.number_rows):
            for j in range(0, self.current_data.number_columns):
                if board[i][j] is None:
                    moves_list.append([i, j])
        return moves_list



class GameBasicData:
    def __init__(self,matrix=None):
        self.number_columns, self.number_rows = 3, 3
        self.combo_length = 3
        if matrix == None:
            self.matrix = [[None for i in range(self.number_columns)]\
                for j in range(self.number_rows)]
        else: self.matrix = matrix
        self.ai_max_depth = 7
        self.ai_player = 'O'
        self.first_player = 'X'
        self.current_player = self.first_player
        self.winner = None
        self.player_list = ['X', 'O']

    def clear_board(self):
        """Clear current game data"""
        self.matrix = [[None for i in range(self.number_columns)]\
                for j in range(self.number_rows)]
        self.current_player = self.first_player
        self.winner = None


    def detect_win(self, board=None):
        """Detect if user won this round

        Return name of winner"""
        if board == None:
            board = self.matrix
        list_elements_to_check = []
        #detect from top left corner to bottom right corner
        for i in range(0, self.number_rows-self.combo_length+1):
            for j in range(0, self.number_columns-self.combo_length+1):
                for k in range(0, self.combo_length):
                    list_elements_to_check.append(board[i+k][j+k])
                if all(i == list_elements_to_check[0] and i != None\
                        for i in list_elements_to_check):
                    return list_elements_to_check[0]
                list_elements_to_check = []

        #detect from top right corner to bottom left corner
        for i in range(0, self.number_rows-self.combo_length+1):
            for j in range(self.combo_length-1, self.number_columns):
                for k in range(0, self.combo_length):
                    list_elements_to_check.append(board[i+k][j-k])
                if all(i == list_elements_to_check[0] and i != None\
                        for i in list_elements_to_check):
                    return list_elements_to_check[0]
                list_elements_to_check = []

        #detect horizontal
        for i in range(0, self.number_rows):
            for j in range(0, self.number_columns-self.combo_length+1):
                for k in range(0, self.combo_length):
                    list_elements_to_check.append(board[i][j+k])
                if all(i == list_elements_to_check[0] and i != None\
                        for i in list_elements_to_check):
                    return list_elements_to_check[0]
                list_elements_to_check = []

        #detect vertical
        for i in range(0, self.number_rows-self.combo_length+1):
            for j in range(0, self.number_columns):
                for k in range(0, self.combo_length):
                    list_elements_to_check.append(board[i+k][j])
                if all(i == list_elements_to_check[0] and i != None\
                        for i in list_elements_to_check):
                    return list_elements_to_check[0]
                list_elements_to_check = []
        return None

    def detect_full_board(self,board=None):
        """Return True if board is full"""
        if board == None:
            board = self.matrix
        for i in range(0, self.number_rows):
            for j in range(0, self.number_columns):
                if board[i][j] is None:
                    return False
        return True

    def find_winner(self, board=None, mem_mode=True):
        if mem_mode:
            self.winner = self.detect_win(board)
            if not self.winner:
                self.winner = self.detect_full_board(board)
                if self.winner == False:
                    self.winner = None
                else:
                    self.winner = 'full_board'
        else:
            tmp_winner = self.detect_win(board)
            if not tmp_winner:
                tmp_winner = self.detect_full_board(board)
            return tmp_winner

    def return_board(self,old_board=None,mov_row=None,mov_col=None,
            mov_usr=None):
        if old_board == None:
            old_board = self.matrix
        new_board = copy.deepcopy(old_board)
        if mov_row != None and mov_col != None and mov_usr != None:
            new_board[mov_row][mov_col] = mov_usr
        return new_board

    def return_oponent(self, oponent_to=None):
        if oponent_to == None:
            oponent_to = self.current_player
        for tmp_oponent in self.player_list:
            if tmp_oponent != oponent_to:
                return tmp_oponent

    def close_round(self):
        self.current_player = self.return_oponent()

    def is_board_empty(self,board=None):
        """Return True if board is empty"""
        if board == None:
            board = self.matrix
        for i in range(0, self.number_rows):
            for j in range(0, self.number_columns):
                if board[i][j] != None:
                    return False
        return True



class TicTacToe:
    def __init__(self,game=None, menu=True):
        if game:
            self.game = game
        else:
            self.game = GameBasicData()
            if menu:
                set_board = SetGameProperties()
                set_board.get_all_values()
                set_board.save_all_values(data_base=self.game)
                self.game.clear_board()

        pygame.init()
        self.game_active = True
        self.winner_was_displayed = False

        self.size = self.width, self.height = 720, 720
        self.screen = pygame.display.set_mode(self.size)
        self.screen_redraw = False
        self.color_background = 255, 255, 255
        self.color_line = 255, 0, 0
        self.color_button = 51, 51, 51
        self.color_button_font =  255, 255, 255
        self.line_size = 4
        self.pos_dim = self.width/self.game.number_columns, self.height/self.game.number_rows

        self.X = pygame.image.load(os.path.join('game','img','X.png'))
        self.X = pygame.transform.scale(self.X,
                (self.width//self.game.number_columns, self.height//self.game.number_rows))
        self.Xrect = self.X.get_rect()
        self.X_list = []
        self.O = pygame.image.load(os.path.join('game','img','O.png'))
        self.O = pygame.transform.scale(self.O,
                (self.width//self.game.number_columns, self.height//self.game.number_rows))
        self.Orect = self.O.get_rect()
        self.O_list = []

    def clear_data(self):
        """Clear current game data"""
        self.game.clear_board()
        self.X_list = []
        self.O_list = []
        self.winner_was_displayed = False


    def draw(self, type_draw='last_element'):
        """Drawing grid and newly added elements"""
        if type_draw == 'basic':
            self.screen.fill(self.color_background)
            for i in range(1, self.game.number_columns):
                pygame.draw.line(self.screen, self.color_line,
                        [i*self.pos_dim[0], 0],
                        [i*self.pos_dim[0], self.height],
                        self.line_size)
            for i in range(1, self.game.number_rows):
                pygame.draw.line(self.screen, self.color_line,
                        [0, i*self.pos_dim[1]],
                        [self.width, i*self.pos_dim[1]],
                        self.line_size)
        elif type_draw == 'last_element':
            if self.game.current_player == 'X':
                self.screen.blit(self.X, self.X_list[-1])
            if self.game.current_player == 'O':
                self.screen.blit(self.O, self.O_list[-1])

    def add_choose(self, column, row, player):
        """Adding player choice"""
        disp_pos = column*self.pos_dim[0], row*self.pos_dim[1]
        self.game.matrix[row][column] = player
        if player == 'X':
            self.X_list.append(self.Xrect.copy())
            self.X_list[-1] = self.X_list[-1].move(disp_pos[0],
                    disp_pos[1])
            self.screen_redraw = True
            self.draw()
        elif player == 'O':
            self.O_list.append(self.Orect.copy())
            self.O_list[-1] = self.O_list[-1].move(disp_pos[0],
                    disp_pos[1])
            self.screen_redraw = True
            self.draw()
        debug(self.game.matrix)

    def position_choose(self, position):
        """Detecting where user clicked mouse on screen and adding elent to lists"""
        tab_pos = math.floor(position[1]/self.pos_dim[1])\
                , math.floor(position[0]/self.pos_dim[0])
        debug('Position on screen '+str(position)+', pos in game '+str(tab_pos))
        if self.game.matrix[tab_pos[0]][tab_pos[1]] is None:
            self.add_choose(tab_pos[1], tab_pos[0], self.game.current_player)
            self.game.close_round()
        else:
            print('This position is not empty! It was checked by '+
                    str(self.game.matrix[tab_pos[0]][tab_pos[1]])+
                    '. Current player round '+ self.game.current_player)

    def handle_events(self):
        """Handle quit and mouse click"""
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.game_active = False
            elif event.type == pygame.MOUSEBUTTONDOWN:
                position = pygame.mouse.get_pos()
                if self.game.winner is None:
                    debug('Pressed mouse'+str(position))
                    self.position_choose(position)
                else:
                    self.button(position)
        self.game.find_winner()
        if self.game.winner:
            if not self.winner_was_displayed:
                if self.game.winner == 'full_board':
                    debug('You got a draw')
                else:
                    debug('\''+self.game.winner+'\' won this round')
                debug('\n=============================================')
                self.winner_was_displayed = True
                self.button()

    def button(self, position=None, type_button='reset'):
        """Draw and handle buttons"""
        if type_button == 'reset':
            reset_w, reset_h = 300, 150
            reset_x = self.width//2 - reset_w//2
            reset_y = self.height//2 - reset_h//2
            reset_pos = (reset_x, reset_y, reset_w, reset_h)
            if position:
                rst_diff_x = position[0] - reset_x
                rst_diff_y = position[1] - reset_y
                if rst_diff_x < reset_w and rst_diff_x >= 0 and \
                        rst_diff_y < reset_h and rst_diff_y >=0:
                    self.draw('basic')
                    self.screen_redraw = True
                    self.clear_data()
            else:
                pygame.draw.rect(self.screen, self.color_button, reset_pos)
                reset_text_font = pygame.font.SysFont('freesansbold', reset_h-50)
                reset_text_surf = reset_text_font.render('Reset', True, self.color_button_font)
                reset_text_rect = reset_text_surf.get_rect()
                reset_text_rect.center = (self.width//2, self.height//2)
                self.screen.blit(reset_text_surf, reset_text_rect)

    def ai_opponent(self):
        """Handle mode player vs AI"""
        if self.game.ai_player and not self.game.winner:
            if self.game.current_player == self.game.ai_player:
                if not self.game.is_board_empty():
                    pygame.time.wait(250)
                start_time = time.time()
                AI = GameAI(self.game)
                result = AI.minmax_alpha_beta()
                debug('Result of mixmax alfa beta puring '+str(result))
                end_time = time.time()
                debug('Time of calculating move: %.2f' %(end_time-start_time))

                #(end_time-start_time)

                move = AI.best_move
                debug("Move "+str(move))
                move_row, move_col = move[0], move[1]
                #move_row, move_col = AI.best_move()
                self.add_choose(column=move_col, row=move_row,
                        player=self.game.ai_player)
                self.game.close_round()

    def play(self):
        """Join all elements and do most of drawing"""
        debug(self.game.matrix)
        self.draw('basic')
        pygame.display.update()
        while self.game_active:

            self.ai_opponent()
            self.handle_events()

            if self.screen_redraw:
                pygame.display.update()
                self.screen_redraw = False
            pygame.time.wait(50)


class SetGameProperties:
    def __init__(self):
        self.combo_length_min, self.combo_length_max = \
            self.board_size_min, self.board_size_max = 3, 10
        self.max_depth_low, self.max_depth_high = 0, 12
        self.ai_player = [['X', 'X'], ['O', 'O'],
                ['None (Player vs player)', None]]
        self.first_player = [['X', 'X'], ['O', 'O']]
        self.var_board_size = 3
        self.var_combo_length = 3
        self.var_max_depth = 9
        self.var_idx_ai_player = 1
        self.var_ai_player =  self.ai_player[self.var_idx_ai_player][1]
        self.var_idx_first_player = 0
        self.var_first_player =  \
                self.first_player[self.var_idx_first_player][1]

    def get_board_size(self):
        print('Choose board size. You can choose between '+
                str(self.board_size_min)+' and '+str(self.board_size_max)+
                '. Default: '+str(self.var_board_size)+'.')
        val = get_integer(text_to_display='Insert integer or press ENTER to choose default ',
                min_value=self.board_size_min,
                max_value=self.board_size_max,
                nothing_as_None=True)
        if val:
            self.var_board_size = val

    def get_combo_length(self):
        print('Choose combo length. You can choose between '+
                str(self.combo_length_min)+' and '+str(self.combo_length_max)+
                '. Default: '+str(self.var_combo_length)+'.')
        val = get_integer(text_to_display='Insert integer or press ENTER to choose default ',
                min_value=self.combo_length_min,
                max_value=self.combo_length_max,
                nothing_as_None=True)
        if val:
            self.var_combo_length = val

    def get_max_depth(self):
        print('Choose difficult level(number of calculating moves by \
minmax alpha beta pruning). \nYou can choose between '+
                str(self.max_depth_low)+' and '+str(self.max_depth_high)+
                '. Default: '+str(self.var_max_depth)+'.')
        val = get_integer(text_to_display='Insert integer or press ENTER to choose default ',
                min_value=self.max_depth_low,
                max_value=self.max_depth_high,
                nothing_as_None=True)
        if val:
            self.var_max_depth = val

    def get_ai_player(self):
        print('Choose ai player. Default: '+
                self.ai_player[self.var_idx_ai_player][0]+
                ' You can choose between: ')
        for i in range(0, len(self.ai_player)):
            print('{0:25} choose {1:d}'.format(self.ai_player[i][0],i))
        val = get_integer(text_to_display='Insert integer or press ENTER to choose default ',
                min_value=0,
                max_value=len(self.ai_player)-1,
                nothing_as_None=True)
        if val:
            self.var_idx_ai_player = val
            self.var_ai_player = self.ai_player[self.var_idx_ai_player][1]

    def get_first_player(self):
        print('Choose first player. Default: '+
                self.first_player[self.var_idx_first_player][0]+
                ' You can choose between: ')
        for i in range(0, len(self.first_player)):
            print('{0:15} choose {1:d}'.format(self.first_player[i][0],i))
        val = get_integer(text_to_display='Insert integer or press ENTER to choose default ',
                min_value=0,
                max_value=len(self.first_player)-1,
                nothing_as_None=True)
        if val:
            self.var_idx_first_player = val
            self.var_first_player = self.first_player[self.var_idx_first_player][1]

    def get_all_values(self):
        self.get_board_size()
        self.get_combo_length()
        self.get_first_player()
        self.get_ai_player()
        if self.var_ai_player:
            self.get_max_depth()

    def save_all_values(self,data_base=None,debug=False):
        if debug:
            print(self.var_board_size)
            print(self.var_combo_length)
            print(self.var_max_depth)
            print(self.var_idx_ai_player)
            print(self.var_ai_player)
            print(self.var_idx_first_player)
            print(self.var_first_player)
        if data_base:
            data_base.number_rows = data_base.number_columns =\
                self.var_board_size
            data_base.combo_length = self.var_combo_length
            data_base.ai_max_depth = self.var_max_depth
            data_base.ai_player = self.var_ai_player
            data_base.first_player = self.var_first_player


def get_integer(text_to_display='', min_value=None,
        max_value=None, nothing_as_None=False):
    try:
        val = str(input(text_to_display))
        if (val == '') and nothing_as_None:
            return None
        val = int(val)
        if min_value and val<min_value:
            raise NameError('low')
        if max_value and val>max_value:
            raise NameError('high')
        return val
    except ValueError:
        print('You typped wrong value. Please do it again correctly.')
        return get_integer(text_to_display=text_to_display,
                min_value=min_value, max_value=max_value,
                nothing_as_None=nothing_as_None)
    except NameError:
        if min_value and max_value:
            print('You should type value between '+str(min_value)+' and '+
                    str(max_value)+' Please do it again correctly.')
        elif min_value:
            print('You should type value greater or equal than '+str(min_value)+
                    '. Please do it again correctly.')
        elif max_value:
            print('You should type value less or equal than '+str(max_value)+
                    '. Please do it again correctly.')
        else:
            print('You typped wrong value. Please do it again correctly.')

        return get_integer(text_to_display=text_to_display,
                min_value=min_value, max_value=max_value,
                nothing_as_None=nothing_as_None)



Game = TicTacToe()
Game.play()


