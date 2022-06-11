def linear_search(array, target):
    for index, val in enumerate(array):
        if val == target:
            return index
    return 'value not found'


def recursive_linear_search(array, target, index=0):
    if index == len(array):
        return 'value not found'
    elif array[index] == target:
        return index
    else:
        return recursive_linear_search(array, target, index=index + 1)


def binary_search(array, target):
    low = 0
    high = len(array) - 1
    mid = len(array) + 1
    while mid != (low + high) // 2:
        mid = (low + high) // 2
        if array[mid] == target:
            return mid
        elif array[mid] > target:
            high = mid - 1
        elif array[mid] < target:
            low = mid + 1
    return 'value not found'


def recursive_binary_search(array, target, low=0, high=None):
    if high is None:
        high = len(array) - 1
    mid = (low + high) // 2
    if array[mid] == target:
        return mid
    elif low == high:
        return 'value not found'
    elif array[mid] > target:
        return recursive_binary_search(array, target, low=low, high=mid-1)
    elif array[mid] < target:
        return recursive_binary_search(array, target, low=mid+1, high=high)
