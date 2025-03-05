import random


def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


def quickselect(arr, low, high, i):
    if low <= high:
        pivot_index = partition(arr, low, high)

        if pivot_index == i:
            return arr[pivot_index]
        elif pivot_index > i:
            return quickselect(arr, low, pivot_index - 1, i)
        else:
            return quickselect(arr, pivot_index + 1, high, i)

    return None


# Example Usage
arr = [7, 10, 4, 3, 20, 15]
i = 3  # Finding the 3rd order statistic (i.e., the 3rd smallest element)
result = quickselect(arr, 0, len(arr) - 1, i - 1)  # i-1 because of zero-based indexing
print(f"The {i}rd smallest element is {result}")
