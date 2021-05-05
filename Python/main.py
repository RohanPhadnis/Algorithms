import random
import time
from search import *
from sort import *


random_list = [random.randint(0, 100) for _ in range(20)]
sorted_list = list(range(30))


print('Linear Search: an algorithm that finds an element in a list by iterating sequentially.')
print('Linear Search:')
print(random_list)
tgt = random.choice(random_list)
print('target:', tgt)
start = time.time()
print('index:', linear_search(random_list, tgt))
print('time:', time.time() - start)
print('Recursive Linear Search:')
print(random_list)
print('target:', tgt)
start = time.time()
print('index:', recursive_linear_search(random_list, tgt))
print('time:', time.time() - start)

print()
print()
print()


print('Binary Search: an algorithm that finds an element in a sorted list by averaging upper and lower bounds.')
print('Binary Search:')
print(sorted_list)
tgt = random.choice(sorted_list)
print('target:', tgt)
start = time.time()
print('index:', binary_search(sorted_list, tgt))
print('time:', time.time() - start)
print('Recursive Binary Search:')
print(sorted_list)
print('target:', tgt)
start = time.time()
print('index:', recursive_binary_search(sorted_list, tgt))
print('time:', time.time() - start)

print()
print()
print()


print('Bubble Sort: an algorithm that sorts a list by comparing adjacent elements to each other.')
print('Bubble Sort:')
print(random_list)
start = time.time()
print('output:', bubble_sort(random_list.copy()))
print('time:', time.time() - start)
print('Recursive Bubble Sort:')
print(random_list)
start = time.time()
print('output:', recursive_bubble_sort(random_list.copy()))
print('time:', time.time() - start)

print()
print()
print()


print('Selection Sort: an algorithm that sorts a list by comparing a selected element to other elements.')
print('Selection Sort:')
print(random_list)
start = time.time()
print('output:', selection_sort(random_list.copy()))
print('time:', time.time() - start)
print('Recursive Selection Sort:')
print(random_list)
start = time.time()
print('output:', recursive_selection_sort(random_list.copy()))
print('time:', time.time() - start)

print()
print()
print()


print('Insertion Sort: an algorithm that sorts a list by dividing it into sorted and unsorted sections.')
print('Insertion Sort:')
print(random_list)
start = time.time()
print('output:', insertion_sort(random_list.copy()))
print('time:', time.time() - start)
print('Recursive Insertion Sort:')
print(random_list)
start = time.time()
print('output:', recursive_insertion_sort(random_list.copy()))
print('time:', time.time() - start)

print()
print()
print()


print('Merge Sort: an algorithm that sorts a list by dividing it into more basic structures and joining them back.')
print('Merge Sort:')
print(random_list)
start = time.time()
print('output:', merge_sort(random_list.copy()))
print('time:', time.time() - start)