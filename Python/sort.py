def bubble_sort(array):
    for x in range(len(array)):
        for y in range(len(array) - 1):
            if array[y] > array[y+1]:
                temp = array[y]
                array[y] = array[y+1]
                array[y+1] = temp
    return array


def recursive_bubble_sort(array, x=0, y=0):
    if x == len(array) - 1:
        return array
    else:
        if y == len(array) - 1:
            return recursive_bubble_sort(array, x=x+1, y=0)
        else:
            if array[y] > array[y+1]:
                temp = array[y]
                array[y] = array[y+1]
                array[y+1] = temp
            return recursive_bubble_sort(array, x=x, y=y+1)


def insertion_sort(array):
    for x in range(1, len(array)):
        for y in range(0, x):
            if array[x] < array[y]:
                array.insert(y, array[x])
                array.pop(x+1)
    return array


def recursive_insertion_sort(array, x=1, y=0):
    if x == len(array):
        return array
    elif y >= x:
        return recursive_insertion_sort(array, x=x+1, y=0)
    elif array[x] < array[y]:
        array.insert(y, array[x])
        array.pop(x+1)
        return recursive_insertion_sort(array, x=x+1, y=0)
    else:
        return recursive_insertion_sort(array, x=x, y=y+1)


def selection_sort(array):
    index = 0
    while index < len(array) - 1:
        val = min(array[index:])
        array.pop(array[index:].index(val) + index)
        array.insert(index, val)
        index += 1
    return array


def recursive_selection_sort(array, new=None):
    if len(array) == 0:
        return new
    if new is None:
        new = []
    new.append(min(array))
    array.remove(min(array))
    return recursive_selection_sort(array, new=new)


def splitter(array):
    if len(array) == 1:
        return array
    else:
        return [splitter(array[:len(array)//2]), splitter(array[len(array)//2:])]


def join(array1, array2):
    if type(array1[0]) == int and type(array2[0]) == int:
        combined = array1 + array2
        output = []
        while len(combined) > 0:
            output.append(min(combined))
            combined.remove(min(combined))
        return output
    elif type(array1[0]) == int and type(array2[0]) != int:
        return join(array1, join(array2[0], array2[1]))
    elif type(array1[0]) != int and type(array2) == int:
        return join(join(array1[0], array1[1]), array2)
    else:
        return join(join(array1[0], array1[1]), join(array2[0], array2[1]))


def merge_sort(array):
    array = splitter(array)
    return join(array[0], array[1])
