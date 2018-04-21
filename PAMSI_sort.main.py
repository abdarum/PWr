#/usr/bin/python3
"""Merge sort, quick sort, introspective sort and testing functions"""

#import built-in modules
import time
import csv
import random

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


def quick_sort(list_to_sort, l=0, r=None):
    """Quick sort function
    list_to_sort - list that will be sorted
    l - index of lower border of list to sort
    r - index of higher border of list to sort"""
    if r is None:
        r = len(list_to_sort)-1
    if l<r:
        i = split_list(list_to_sort, l, r)
        quick_sort(list_to_sort, l, i-1)
        quick_sort(list_to_sort, i+1, r)

def split_list(list_to_split, l, r):
    """Split list and move elements with lower key to left"""
    index_of_split_point = l + (r-l)//2 
    key_of_split_point = list_to_split[index_of_split_point]
    exchange_elements(list_to_split, index_of_split_point, r)
    current_index = l
    for i in range(l, r):
        if list_to_split[i] < key_of_split_point:
            exchange_elements(list_to_split, i, current_index)
            current_index += 1
    exchange_elements(list_to_split, current_index, r)
    return current_index
    
def exchange_elements(list_to_edit, i1, i2):
    """Change place of two elemts in list"""
    #print('List len: '+str(len(list_to_edit))+' Index1: '+str(i1)+' Index2: '+str(i2))
    list_to_edit[i1], list_to_edit[i2] = list_to_edit[i2], list_to_edit[i1]

def merge_sort(list_to_sort, l=0, r=None):
    """Quick sort function
    list_to_sort - list that will be sorted
    l - index of lower border of list to sort
    r - index of higher border of list to sort"""
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

class TestedData:
    """Contain data from testing function"""

    def __init__(self, length_of_list=None, number_of_sorted_elements=None, reverse_sorted=None,
            percent_of_sorted_list=None): 
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
        self.reverse_sorted = reverse_sorted
        self.comment = []

    def time_mean(self):
        """Return mean time of sorting list"""
        return sum(self.sorting_time)/len(self.sorting_time)
    
    def print_data(self, active_list_of_sorting_time=True):
        """Printing data of class"""
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

    def is_sorted(self, list_to_check):
        """If list_to_check is not sortet it return False"""
        for i in range(1, len(list_to_check)):
            if list_to_check[i] < list_to_check[i-1]:
                return False
        return True

    def create_random_list(self, size, low=None, high=None, sorted_to=None,
            reverse=False):
        """Creating list with pseudo random elements"""
        if not low:
            low = 0
        if not high:
            high = 10000
        random_elements_list = []
        start_time = time.time()
        for i in range(0,size):
            random_elements_list.append(random.randrange(low, high))
        stop_time = time.time()
        if sorted_to:
            quick_sort(random_elements_list, r=sorted_to)
        if reverse:
            quick_sort(random_elements_list)
            random_elements_list = list(reversed(random_elements_list))
        return random_elements_list, stop_time - start_time

    def sort(self, list_to_sort, sorting_type='quick'):
        """Sorting list using diffrent types of sorting. Return sorting time
        
        quick - quick sort
        merge - mergesort"""
        start_time = time.time()
        if sorting_type == 'quick':
            quick_sort(list_to_sort)
        elif sorting_type == 'merge':
            merge_sort(list_to_sort)
        stop_time = time.time()
        return self.is_sorted(list_to_sort), stop_time - start_time

    def testing_gear(self, percent_of_sorted_list=None, list_of_lists_size=None,
                    number_of_sorting=None, low_number=None, high_number=None,
                    sorting_type='quick'):
        time_list = []
        if percent_of_sorted_list is None:
            percent_of_sorted_list = [50, 100]
        if list_of_lists_size is None:
            list_of_lists_size = [5, 10, 15]
        if number_of_sorting is None:
            number_of_sorting = 10000

        debug('Number of repeting proces: ' + str(number_of_sorting) + '\n')
        for how_much_sorted in percent_of_sorted_list:
            for list_size in list_of_lists_size:
                self.list_of_tested_data.append(TestedData(length_of_list = list_size,
                        percent_of_sorted_list=how_much_sorted,
                        reverse_sorted = False)) 
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
                debug('Complete processing ' + str(list_size) \
                        + ' Percent of sorted ' + str(how_much_sorted) + '%'\
                        + '\nTotal genering time ' + str(time_list[-1][0]) \
                        + ' Total sorting time ' + str(time_list[-1][1]) \
                        + '\nTotal time ' + str(time_list[-1][0] + time_list[-1][1])\
                        + '\n')
        debug('Reverse sorted\n')        
        for list_size in list_of_lists_size:
            self.list_of_tested_data.append(TestedData(length_of_list = list_size,
                    percent_of_sorted_list=0, reverse_sorted = True)) 
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
            time_list.append([sum(tmp_gen_time), sum(tmp_sort_time)])
            debug('Complete processing ' + str(list_size) \
                    + ' reverse sorted' \
                    + '\nTotal genering time ' + str(time_list[-1][0]) \
                    + ' Total sorting time ' + str(time_list[-1][1]) \
                    + '\nTotal time ' + str(time_list[-1][0] + time_list[-1][1])\
                    + '\n')

    def print_data(self, active_list_of_sorting_time=True):   
        for i in self.list_of_tested_data:
            i.print_data(active_list_of_sorting_time)

    def print_status_of_sorting(self, list_to_sort, sorting_type='quick'):
        """Print list before sort, time of sort, is sorted and list after"""
        print('\n',list_to_sort)
        is_sorted, sort_time = self.sort(list_to_sort, sorting_type='merge')
        print('Time of sorting', sort_time, end='') 
        if is_sorted:
            print(' List is sorted')
        else: print(' List is NOT sorted')
        print('\n\n', list_to_sort)        
        if is_sorted:
            print(' List is sorted')
        else: print(' List is NOT sorted')

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
                        'Reverse sorted'])
                for row in self.list_of_tested_data:
                    writer.writerow([row.length_of_list, 
                        str(row.percent_of_sorted_list).replace('.',','), 
                        str(row.time_mean()).replace('.',','),
                        row.reverse_sorted])
        debug('CSV file: ' + filename + ' saved properly\n')


tests = TestingClass()
tmp_list, generation_time = tests.create_random_list(10000, high=1000)
print('\nGeneration time', generation_time)
tests.print_status_of_sorting(tmp_list)
#tests.testing_gear()
#tests.csv_write('./test.csv')
#tests.print_data(False)
