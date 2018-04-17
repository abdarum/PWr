#/usr/bin/python3
"""Merge sort, quick sort, introspective sort and testing functions"""

#import built-in modules
import time
import csv

__author__ = 'Kornel Stefańczykr'
__license__ = 'CC BY-SA'
__version__ = 'Kornel Stefańczyk'
__maintainer__ = 'Kornel Stefańczyk'
__email__ = 'kornelstanczyk@wp.pl'



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
    for i in range(l, r-1):
        if list_to_split[i] <= key_of_split_point:
            exchange_elements(list_to_split, i, current_index)
            current_index += 1
    exchange_elements(list_to_split, current_index, r)
    return current_index
    
def exchange_elements(list_to_move_elements, i1, i2):
    """Change place of two elemts in list"""
    list_to_move_elements[i1], list_to_move_elements[i2] = \
            list_to_move_elements[i2], list_to_move_elements[i1]

class TestingClass:
    """Contain functions make testing easier"""
    
    def is_sorted(self, list_to_check):
        """If list_to_check is not sortet it return False"""
        for i in range(1, len(list_to_check)):
            if list_to_check[i] < list_to_check[i-1]:
                return False
        return True

    def print_status_of_sorting(self, list_to_sort):
        """Print list before sort, time of sort, is sorted and list after"""
        print(list_to_sort)
        start_time = time.time()
        quick_sort(list_to_sort)
        stop_time = time.time()
        print('Time of sorting '+str(stop_time - start_time), end='') 
        if self.is_sorted(list_to_sort):
            print(' List is sorted')
        else: print(' List is NOT sorted')
        print(list_to_sort)        

tests = TestingClass()
tmp_list = [1, 7, 5, 6, 2, 4, 5, 9, 15, 3]
tests.print_status_of_sorting(tmp_list)
