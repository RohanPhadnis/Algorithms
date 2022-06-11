import random
import time
from search import *
from sort import *


random_list = [random.randint(0, 4000) for _ in range(1000)]
sorted_list = list(range(1000))


print('Linear Search:')
print(random_list)
tgt = random.choice(random_list)
print('target:', tgt)
start = time.time()
print('index:', linear_search(random_list, tgt))
print('time:', time.time() - start)


print()
print()
print()

print('Binary Search:')
print(sorted_list)
tgt = random.choice(sorted_list)
print('target:', tgt)
start = time.time()
print('index:', binary_search(sorted_list, tgt))
print('time:', time.time() - start)


print()
print()
print()


print('Bubble Sort:')
print(random_list)
start = time.time()
print('output:', bubble_sort(random_list.copy()))
print('time:', time.time() - start)


print()
print()
print()


print('Insertion Sort:')
print(random_list)
start = time.time()
print('output:', insertion_sort(random_list.copy()))
print('time:', time.time() - start)


print()
print()
print()


print('Selection Sort:')
print(random_list)
start = time.time()
print('output:', selection_sort(random_list.copy()))
print('time:', time.time() - start)
