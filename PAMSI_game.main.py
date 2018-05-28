#/usr/bin/python3
"""Merge sort, quick sort, introspective sort and testing functions"""

#import built-in modules

import os
import math

import pygame

__author__ = 'Kornel Stefańczykr'
__license__ = 'CC BY-SA'
__version__ = '0.4'
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
    def __init__(self, current_data=None, max_player=None, depth=None):
        self.current_data=current_data
        if max_player: self.max_player = max_player
        else:          self.max_player = self.current_data.ai_player
        if depth: self.depth = depth
        else:     self.depth = 0

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

    def evaluate(self, board=None):
        if board == None:
            board = self.current_data.matrix
        winner = self.current_data.detect_win(board)
        if winner:
            if winner == self.max_player:
                return 10
            else:
                return -10
        else:
            return 0


class GameBasicData:
    def __init__(self):
        self.number_columns, self.number_rows = 3, 3 
        self.combo_length = 3
        self.matrix = [[None for i in range(self.number_columns)]\
                for j in range(self.number_rows)]
        self.ai_player = None
        self.current_player = 'X'
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


class TicTacToe:
    def __init__(self):

        self.game = GameBasicData()

        pygame.init()
        self.game_active = True
        
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
        self.game.matrix = [[None for i in range(self.game.number_columns)]\
                for j in range(self.game.number_rows)]
        self.X_list = []
        self.O_list = []
        self.game.current_player = 'X'
        self.game.winner = None

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
            if self.game.current_player == 'X':
                self.game.current_player = 'O'
            elif self.game.current_player == 'O':
                self.game.current_player = 'X'
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
                    self.game.winner = self.game.detect_win()
                    self.detect_full_board()
                    if self.game.winner:
                        print('\''+self.game.winner+'\' won this round')
                        self.button()
                else:
                    self.button(position)

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

    def detect_full_board(self):
        """Return True if board is full"""
        for i in range(0, self.game.number_rows):
            for j in range(0, self.game.number_columns):
                if self.game.matrix[i][j] is None:
                    return False
        self.game.winner = 'full_board'
        return True

    def ai_opponent(self):
        """Handle mode player vs AI"""
        if self.game.ai_player:
            if self.game.current_player == self.game.ai_player:
                pass

        AI = GameAI(self.game)
        print(AI.evaluate())

    def play(self):
        """Join all elements and do most of drawing"""
        debug(self.game.matrix)
        self.draw('basic')
        pygame.display.update()
        while self.game_active:
            self.handle_events()

            self.ai_opponent()
            if self.screen_redraw:
                pygame.display.update()
                self.screen_redraw = False
            pygame.time.wait(50)


Game = TicTacToe()
Game.play()

AI = GameAI()
#tmp_var = [5,7,10,2,3,15,33,8]
tmp_var = [3, 5, 2, 9, 12, 5, 23, 23]
#print(AI.minmax(tmp_var))


