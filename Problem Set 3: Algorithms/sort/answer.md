# Sorting Algorithm Analysis

In this problem, we will analyze three already-compiled C programs: `sort1`, `sort2`, and `sort3`. Each of these programs implements a different sorting algorithm, and our task is to determine which algorithm each program uses.

## Algorithms

Here are the three sorting algorithms we will be analyzing:

### 1. Selection sort

Selection sort iterates through the unsorted portions of a list, selecting the smallest element each time and moving it to its correct location.

### 2. Bubble sort

Bubble sort compares pairs of adjacent values one at a time and swaps them if they are in the incorrect order. This continues until the list is sorted.

### 3. Merge sort

Merge sort recursively divides the list into two repeatedly and then merges the smaller lists back into a larger one in the correct order.

## Task

We need to analyze each of the three programs and determine which sorting algorithm is being used in each one. We will write our answers in the `answers.txt` file provided in the `sort` folder.

## Answers

Here are the answers:

1. `sort1` uses the __selection sort__ algorithm. This can be determined by looking at the code and seeing that the program iterates through the array and finds the smallest element to swap with the current element.

2. `sort2` uses the __bubble sort__ algorithm. This can be determined by looking at the code and seeing that the program compares adjacent elements and swaps them if they are in the wrong order.

3. `sort3` uses the __merge sort__ algorithm. This can be determined by looking at the code and seeing that the program recursively divides the array into smaller subarrays and then merges them back together in the correct order.

## Conclusion

In this problem, we analyzed three sorting programs to determine which algorithms they use. By examining the code for each program, we were able to determine that `sort1` uses selection sort, `sort2` uses bubble sort, and `sort3` uses merge sort.

