# Big O notion to measure

an overview of how we use Big O notation to measure the time complexity of sorting algorithms. By understanding the time complexity of different algorithms, we can choose the most efficient algorithm for the size and type of data that we need to sort. This can lead to significant improvements in program performance.

## Bubble Sort

Bubble sort is a type of sorting algorithm you can use to arrange a set of values in ascending order. If you want, you can also implement bubble sort to sort the values in descending order.

![bubble sort](img/bubble-short.png)

## Insertion Sort

Insertion sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time by comparisons. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

![Insertion sort](img/Insertion_sort.png)

## Quick sort

Quicksort is a sorting algorithm based on **the divide and conquer** approach where

- An array is divided into subarrays by selecting a pivot element (element selected from the array).

- While dividing the array, the pivot element should be positioned in such a way that elements less than pivot are kept on the left side and elements greater than pivot are on the right side of the pivot.
- The left and right subarrays are also divided using the same approach. This process continues until each subarray contains a single element.
- At this point, elements are already sorted. Finally, elements are combined to form a sorted array.

![Quick sort](img/quick_sort.png)

## selection sort

Selection sort is a sorting algorithm that selects the smallest element from an unsorted list in each iteration and places that element at the beginning of the unsorted list.

![selection sort](img/selection_sort.webp)
