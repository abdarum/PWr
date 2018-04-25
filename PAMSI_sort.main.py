#/usr/bin/python3
"""Merge sort, quick sort, introspective sort and testing functions"""

#import built-in modules
import time
import csv
import random
import math
import copy
import sys

__author__ = 'Kornel Stefańczykr'
__license__ = 'CC BY-SA'
__version__ = '0.6'
__maintainer__ = 'Kornel Stefańczyk'
__email__ = 'kornelstanczyk@wp.pl'


def debug(msg, active_debugging=True, end_=None):
    """Print msg to terminal"""
    if active_debugging:
        if end_:
            print(msg, end=end_)
        else:
            print(msg)


def progress(count, total, status=''):
    """Function copied from 'vladignatyev' on GitHub
    
    It show progress of process"""
    bar_len = 60
    filled_len = int(round(bar_len * count / float(total)))

    percents = round(100.0 * count / float(total), 1)
    bar = '=' * filled_len + '-' * (bar_len - filled_len)

    sys.stdout.write('[%s] %s%s ...%s\r' % (bar, percents, '%', status))
    sys.stdout.flush()  # As suggested by Rom Ruben (see: http://stackoverflow.com/questions/3173320/text-progress-bar-in-the-console/27871113#comment50529068_27871113)


def quick_sort(list_to_sort, l=None, r=None):
    """Quick sort function
    list_to_sort - list that will be sorted
    l - index of lower border of list to sort
    r - index of higher border of list to sort"""
    if l is None:
        l = 0
    if r is None:
        r = len(list_to_sort)-1
    if l < r:
        i = split_list(list_to_sort, l, r)
        quick_sort(list_to_sort, l, i-1)
        quick_sort(list_to_sort, i+1, r)

def split_list(list_to_split, l, r):
    """Split list and move elements with lower key to left"""
    key_of_split_point = list_to_split[r]
    current_index = l - 1
    for i in range(l, r):
        if list_to_split[i] < key_of_split_point:
            current_index += 1
            exchange_elements(list_to_split, i, current_index)
    exchange_elements(list_to_split, current_index+1, r)
    return current_index + 1

def exchange_elements(list_to_edit, i1, i2):
    """Change place of two elemts in list"""
    list_to_edit[i1], list_to_edit[i2] = list_to_edit[i2], list_to_edit[i1]

def merge_sort(list_to_sort, l=None, r=None):
    """Merge sort function
    list_to_sort - list that will be sorted
    l - index of lower border of list to sort
    r - index of higher border of list to sort"""
    if l is None:
        l = 0
    if r is None:
        r = len(list_to_sort)-1
    if l<r:
        i = (l + r)//2
        merge_sort(list_to_sort, l, i)
        merge_sort(list_to_sort, i+1, r)
        merge(list_to_sort, l, i, r)

def merge(list_to_merge, l, m, r):
    l1 = list(list_to_merge[l:m+1])
    l2 = list(list_to_merge[m+1:r+1])
    current_index = l
    if r-l > 0:
        while l1 or l2:
            if not len(l1):
                list_to_merge[current_index] = l2.pop(0)
            elif not len(l2):
                list_to_merge[current_index] = l1.pop(0)
            elif l1[0] < l2[0]:
                list_to_merge[current_index] = l1.pop(0)
            else:
                list_to_merge[current_index] = l2.pop(0)
            current_index += 1

def heapify(arr, n, i):

    largest = i  
    l = 2 * i + 1 
    r = 2 * i + 2 
    if l < n and arr[i] < arr[l]:
        largest = l
    if r < n and arr[largest] < arr[r]:
        largest = r
    if largest != i:
        arr[i],arr[largest] = arr[largest],arr[i]
        heapify(arr, n, largest)

def heap_sort(arr, l=None, r=None):
    """Heap sort function
    arr - list that will be sorted
    l - index of lower border of list to sort
    r - index of higher border of list to sort"""
    if l is None:
        l = 0
    if r is None:
        r = len(arr)-1
    n = r-l+1
    for i in range(n, l-1, -1):
        heapify(arr, n, i)
    for i in range(n-1, l, -1):
        arr[i], arr[0] = arr[0], arr[i] 
        heapify(arr, i, 0)

def introsort(list_to_sort, l=None, r=None, M=None):
    """Introsort function
    list_to_sort - list that will be sorted
    l - index of lower border of list to sort
    r - index of higher border of list to sort
    M - max depth of recrsive call"""

    if l is None:
        l = 0
    if r is None:
        r = len(list_to_sort)-1
    if M is None:
        M = int(math.floor(math.log(len(list_to_sort)))) * 2
    introhelp(list_to_sort, M, 0, len(list_to_sort)-1)

def introhelp(list_to_sort, M, l, r):
    """Help function to realise introspective sorting"""
    n = len(list_to_sort)
    if n <= 1:
        pass
    elif M == 0:
        heap_sort(list_to_sort)
    else:
        i = split_list2(list_to_sort, l, r)
        introhelp(list_to_sort, M - 1, l, i - 1)
        introhelp(list_to_sort, M - 1, i + 1, r)

def split_list2(list_to_split, l, r):
    """Split list and move elements with lower key to left
    
    Second algorithm for this function because introsort don't work 
    with first"""
    pivotpoint = list_to_split[l]
    left = l + 1
    right = r
    while True:
        while left <= right and list_to_split[left] <= pivotpoint:
            left += 1

        while right >= left and list_to_split[right] >= list_to_split[left]:
            right -= 1

        if right < left:
            break

        else:
            temp = list_to_split[left]
            list_to_split[left] = list_to_split[right]
            list_to_split[right] = temp
    temp = list_to_split[l]
    list_to_split[l] = list_to_split[right]
    list_to_split[right] = temp

    return right



class TestedData:
    """Contain data from testing function"""

    def __init__(self, length_of_list=None, number_of_sorted_elements=None, reverse_sorted=None,
            percent_of_sorted_list=None, sorting_type=None): 
        self.sorting_time = []
        if length_of_list:
            self.length_of_list = length_of_list
            if percent_of_sorted_list:
                self.percent_of_sorted_list = percent_of_sorted_list  
                self.number_of_sorted_elements = int(self.percent_of_sorted_list\
                                                 *self.length_of_list       \
                                                 /100)
            elif number_of_sorted_elements: 
                self.number_of_sorted_elements = number_of_sorted_elements
                self.percent_of_sorted_list = self.number_of_sorted_elements\
                                          /self.length_of_list * 100
            else:
                self.percent_of_sorted_list = 0 
                self.number_of_sorted_elements = 0
        self.sorting_type = sorting_type
        self.reverse_sorted = reverse_sorted
        self.comment = []

    def time_mean(self):
        """Return mean time of sorting list"""
        return sum(self.sorting_time)/len(self.sorting_time)
    
    def print_data(self, active_list_of_sorting_time=True):
        """Printing data of class"""
        print('Type of sorted algorythm', self.sorting_type)
        print('Length: ' + str(self.length_of_list))
        if active_list_of_sorting_time:
            print('List of sorting time: ' + str(self.sorting_time))
        print('Mean sorting time: ' + str(self.time_mean()))
        print('First element sorted: ' + str(self.number_of_sorted_elements))
        print('Percent of sorted: ' + str(self.percent_of_sorted_list) + '%')
        if self.reverse_sorted:
            print('List reverse sorted')
        print('Comments: '+str(self.comment))
        print()



class TestingClass:
    """Contain functions make testing easier"""
    
    def __init__(self):
        self.list_of_tested_data = []

    def is_sorted(self, list_to_check, show_all_errors=False):
        """If list_to_check is not sortet it return False"""
        if show_all_errors:
            list_of_errors = []
            for i in range(1, len(list_to_check)):
                if list_to_check[i] < list_to_check[i-1]:
                    list_of_errors.append(i)
            if len(list_of_errors):
                print('List of error indexes',list_of_errors)
                for j in list_of_errors:
                    print('Index', j, 'values', list_to_check[j-1], list_to_check[j])

                return False
            else:
                return True
        else:
            for i in range(1, len(list_to_check)):
                if list_to_check[i] < list_to_check[i-1]:
                    print('Sorted fail in:',i)
                    return False
            return True

    def create_random_list(self, size=None, low=None, high=None, sorted_to=None,
            reverse=None):
        """Creating list with pseudo random elements"""
        if not size:
            size = 20
        if not low:
            low = 0
        if not high:
            high = 1000
        if not reverse:
            reverse = False
        
        random_elements_list = []
        start_time = time.time()
        if sorted_to:
            param = high/sorted_to
            for idx in range(0, sorted_to+1):
                random_elements_list.append(int(idx*param))
            for i in range(sorted_to+1,size):
                random_elements_list.append(random.randrange(low, high))
            #quick_sort(random_elements_list, r=sorted_to)
        elif reverse:
            param = high/size
            for idx in range(size-1, -1, -1):
                random_elements_list.append(int(idx*param))
            #quick_sort(random_elements_list)
            #random_elements_list = list(reversed(random_elements_list))
        else:
            for i in range(0,size):
                random_elements_list.append(random.randrange(low, high))
        stop_time = time.time()
        return random_elements_list, stop_time - start_time

    def sort(self, list_to_sort, l=None, r=None, sorting_type=None):
        """Sorting list using diffrent types of sorting. Return sorting time
        
        quick - quick sort
        merge - mergesort"""
        start_time = time.time()
        if sorting_type == None:
            sorting_type='quick'
        if sorting_type == 'quick':
            quick_sort(list_to_sort, l, r)
        elif sorting_type == 'merge':
            merge_sort(list_to_sort, l, r)
        elif sorting_type == 'heap':
            heap_sort(list_to_sort, l, r)
        elif sorting_type == 'introsort':
            introsort(list_to_sort, l, r)
        else:
            print('!!! Wrong algorythmic !!!')
        stop_time = time.time()
        return self.is_sorted(list_to_sort, True), stop_time - start_time

    def testing_gear(self, percent_of_sorted_list=None, list_of_lists_size=None,
                    number_of_sorting=None, low_number=None, high_number=None,
                    sorting_type='quick'):
        print('Tests started',time.ctime())
        #name_of_tmp_csv = 'test.csv'
        name_of_tmp_csv = sys.argv[0].replace('.py','__sort_backup_data.csv')
        time_list = []
        if percent_of_sorted_list is None:
            percent_of_sorted_list = [0, 25, 50, 75, 95, 99, 99.7]
        if list_of_lists_size is None:
            list_of_lists_size = [10000, 50000, 100000, 500000, 1000000] 
        if number_of_sorting is None:
            number_of_sorting = 100
        #self.csv_write(name_of_tmp_csv, 'format1')
        debug('Number of repeting proces: ' + str(number_of_sorting) + '\n')
        for how_much_sorted in percent_of_sorted_list:
            for list_size in list_of_lists_size:
                self.list_of_tested_data.append(TestedData(length_of_list = list_size,
                        percent_of_sorted_list=how_much_sorted,
                        reverse_sorted = False, sorting_type = sorting_type)) 
                tmp_gen_time = []
                tmp_sort_time = []
                for i in range(0,number_of_sorting):
                    tmp_list, time_generate = self.create_random_list(size=list_size, 
                            low=low_number, high=high_number, 
                            sorted_to=self.list_of_tested_data[-1].number_of_sorted_elements-1)
                    is_sorted, time_sort = self.sort(tmp_list, sorting_type=sorting_type)
                    self.list_of_tested_data[-1].sorting_time.append(time_sort)
                    if not is_sorted:
                        self.list_of_tested_data[-1].comment.append('NOT sorted')
                        debug('\n!!! list is NOT sorted !!!\n')
                    tmp_gen_time.append(time_generate)
                    tmp_sort_time.append(time_sort)
                    time_list.append([sum(tmp_gen_time), sum(tmp_sort_time)])
                    progress(i+1,number_of_sorting, 'Type '+sorting_type+' Size '\
                            + str(list_size)+' Time: G '+str(format(tmp_gen_time[-1], '.3f'))\
                            +' S '+str(format(tmp_sort_time[-1],'.3f')))
                debug('Complete processing ' + str(list_size) \
                        + ' Percent of sorted ' + str(format(how_much_sorted, '.2f'))
                        + '%' + ' Type of sorting ' + sorting_type \
                        + '\n' + str(time.ctime()) \
                        + '\nTotal genering time ' \
                        + str(format(time_list[-1][0], '.1f')) \
                        + ' Total sorting time ' \
                        + str(format(time_list[-1][1], '.1f')) \
                        + '\nTotal time ' \
                        + str(format(time_list[-1][0] + time_list[-1][1], '.1f'))\
                        + '\n')
                self.csv_write(name_of_tmp_csv, 'format2')
        debug('Reverse sorted\n')        
        for list_size in list_of_lists_size:
            self.list_of_tested_data.append(TestedData(length_of_list = list_size,
                    percent_of_sorted_list=0, reverse_sorted = True, sorting_type = sorting_type)) 
            tmp_gen_time = []
            tmp_sort_time = []
            for i in range(0,number_of_sorting):
                tmp_list, time_generate = self.create_random_list(size=list_size, 
                        low=low_number, high=high_number, 
                        reverse=True)
                is_sorted, time_sort = self.sort(tmp_list, sorting_type=sorting_type)
                self.list_of_tested_data[-1].sorting_time.append(time_sort)
                if not is_sorted:
                    self.list_of_tested_data[-1].comment.append('NOT sorted')
                    debug('\n!!! list is NOT sorted !!!\n')
                tmp_gen_time.append(time_generate)
                tmp_sort_time.append(time_sort)
                progress(i+1,number_of_sorting, 'Type '+sorting_type+' Size '\
                        + str(list_size)+' Time: G '+str(format(tmp_gen_time[-1], '.3f'))\
                        +' S '+str(format(tmp_sort_time[-1],'.3f')))
            time_list.append([sum(tmp_gen_time), sum(tmp_sort_time)])
            debug('Complete processing ' + str(list_size) \
                    + ' reverse sorted' + ' Type of sorting '\
                    + sorting_type \
                    + '\n' + str(time.ctime()) \
                    + '\nTotal genering time ' \
                    + str(format(time_list[-1][0], '.1f')) \
                    + ' Total sorting time ' \
                    + str(format(time_list[-1][1], '.1f')) \
                    + '\nTotal time ' \
                    + str(format(time_list[-1][0] + time_list[-1][1], '.1f'))\
                    + '\n')
            self.csv_write(name_of_tmp_csv, 'format2')

    def print_data(self, active_list_of_sorting_time=True):   
        for i in self.list_of_tested_data:
            i.print_data(active_list_of_sorting_time)

    def print_status_of_sorting(self, list_to_sort, l=None, r=None, sorting_type=None):
        """Print list before sort, time of sort, is sorted and list after"""
        print('\nNumber of elements', len(list_to_sort))
        print('Type of sorting', sorting_type)
        print('\n',list_to_sort)
        is_sorted, sort_time = self.sort(list_to_sort, l, r, sorting_type)
        print('Time of sorting', sort_time, end='') 
        if is_sorted:
            print(' List is sorted')
        else: print(' List is NOT sorted')
        print('\n\n', list_to_sort)        
        if is_sorted:
            print(' List is sorted')
        else: print(' List is NOT sorted')
        self.is_sorted(list_to_sort, show_all_errors=True)

    def csv_write(self, filename, output_data_format='format1'):
        """Write data into CSV file 

        output_data_format:
            format1 - data saved in simplest version"""
        if output_data_format == 'format1':
            with open(filename, 'w', newline='') as csvfile:
                writer = csv.writer(csvfile, delimiter=';',
                                    quoting = csv.QUOTE_NONE)
                writer.writerow(['Length of list', 
                        'Percent of sorted elements', 'Average time of sort',
                        'Reverse sorted','Type of sorting algotythm','time'])
                for row in self.list_of_tested_data:
                    writer.writerow([row.length_of_list, 
                        str(row.percent_of_sorted_list).replace('.',','), 
                        str(row.time_mean()).replace('.',','),
                        row.reverse_sorted,row.sorting_type,time.ctime()])
        elif output_data_format == 'format2':
            with open(filename, 'a', newline='') as csvfile:
                writer = csv.writer(csvfile, delimiter=';',
                                    quoting = csv.QUOTE_NONE)
                row = self.list_of_tested_data[-1]
                writer.writerow([row.length_of_list, 
                    str(row.percent_of_sorted_list).replace('.',','), 
                    str(row.time_mean()).replace('.',','),
                    row.reverse_sorted,row.sorting_type,time.ctime()])

        debug('CSV file: ' + filename + ' saved properly\n')

def user_menu():
    tests = TestingClass()
    if len(sys.argv) > 1:
        tests.testing_gear(sorting_type='quick')
        tests.testing_gear(number_of_sorting=10, sorting_type='merge')
        tests.testing_gear(list_of_lists_size=[ 1371, 1501, 1751, 2001, 2501], 
                number_of_sorting=10)
        tests.csv_write(sys.argv[1])
        print('\nTests complete!!!\n')
    else:
        print('\nImplementation of sorting types for PAMSI written by '\
                +'Kornel Stefańczyk\n')
        usr_choice = None
        while usr_choice != 'q':
            print('Choose one of option:')
            print('\t1 - insert list and sort it')
            print('\t2 - sort random list')
            print('\t3 - run time consuming analitics')
            print('\t4 - show time consuming analitics data')
            print('\t5 - save to csv file time consuming analitics data')
            print('\tq - quit program')
            usr_choice = input('Enter your choice: ')
            print()
            if usr_choice == '1' or usr_choice == '2':
                if usr_choice == '1':
                    usr_list = [int(x) for x in input().split()]
                elif usr_choice == '2':
                    usr_size = input('Size of generating table(default 20 - press ENTER) ')
                    if usr_size == '':
                        usr_size = None
                    else:
                        usr_size = int(usr_size)
                    usr_low = input('Low value of generating table(default 0 - press ENTER) ')
                    if usr_low == '':
                        usr_low = None
                    else:
                        usr_low = int(usr_low)
                    usr_high = input('High value of generating table(default 1000 - press ENTER) ')
                    if usr_high == '':
                        usr_high = None
                    else:
                        usr_high = int(usr_high)
                    usr_reverse = input('Reverse sorted table False(N,n,F,f,False), True(Y,y,T,t,True)'\
                            +'\n(default False - press ENTER) ')
                    if usr_reverse == '':
                        usr_reverse = None
                    else:
                        if usr_reverse in ('N', 'n', 'F', 'f', 'False'):
                            usr_reverse = bool(False)
                        elif usr_reverse in ('Y', 'y', 'T', 't', 'True'):
                            usr_reverse = bool(True)
                        else:
                            print('Wrong option => False(yor option\"'+ usr_reverse +'\")' )
                            usr_reverse = None
                    usr_sorted = None
                    if not usr_reverse:
                        usr_sorted= input('Number of first elements sorted(default 0 - press ENTER) ')
                        if usr_sorted == '':
                            usr_sorted = 0
                        else:
                            usr_sorted = float(usr_sorted)
                            if not usr_size:
                                size_of_table = 20
                            if usr_sorted > 19:
                                print('Too high value. Set 0')
                                usr_sorted = 0
                    usr_list, generation_time = tests.create_random_list(
                            size=usr_size, low=usr_low, high=usr_high, 
                            reverse=usr_reverse, sorted_to=usr_sorted)
                    print(usr_list)
                    print('\nGeneration time', generation_time)            
                l_indx = input('Index of left border(default 0 - press ENTER) ')
                if l_indx == '':
                    l_indx = None
                else:
                    l_indx = int(l_indx)
                r_indx = input('Index of right border(default last - press ENTER) ')
                if r_indx == '':
                    r_indx = None
                else:
                    r_indx = int(r_indx)
                sort_type = input('Type of sorting: (default quick - press ENTER)'\
                        + '\nquick - quick sort' + '\tmerge - merge sort'\
                        + '\n\tintrosort - introsort'+'\theap - heap sort'+'\n')
                if sort_type == '':
                    sort_type = None
                tests.print_status_of_sorting(list_to_sort=usr_list, r=r_indx, l=l_indx,
                        sorting_type=sort_type)
            elif usr_choice == '3':
                tests.testing_gear(sorting_type='quick')
                tests.testing_gear(number_of_sorting=10, sorting_type='merge')
                tests.testing_gear(list_of_lists_size=[ 1371, 1501, 1751, 2001, 2501], 
                        number_of_sorting=10)
                print('Tests complete!!!')
            elif usr_choice == '4':
                tests.print_data(False)
            elif usr_choice == '5':
                file_name = ''
                while file_name == '':
                    file_name = input('Input csv file name with extension')
                tests.csv_write(sys.argv[1])
            elif usr_choice == 'q':
                pass
            else:
                print('\nWrong option was choosen. Please type option again\n')


user_menu()
