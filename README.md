# SortingVisual
This repository contains source code for visualizing commonly used sorting algorithms. <br />
How to use :

-> copy my code (SortingVisual.cpp)<br />
-> Choose any c++ compiler, paste my code and run <br />

## Selection Sort

Steps for Selection Sort:

-> Initialize minimum value(min_idx) to location 0.<br />
-> Traverse the array to find the minimum element in the array.<br />
-> While traversing if any element smaller than min_idx is found then swap both the values.<br />
-> Then, increment min_idx to point to the next element.<br />
-> Repeat until the array is sorted.<br />

Complexity:
Time Complexity - O(n^2)
Space Complexity - O(1)

## Bubble Sort

Steps for Bubble Sort:

-> Run a nested for loop to traverse the input array using two variables i and j, such that 0 ≤ i < n-1 and 0 ≤ j < n-i-1 <br />
-> If arr[j] is greater than arr[j+1] then swap these adjacent elements, else move on <br />
-> Print the sorted array <br />

Complexity:
Time Complexity - O(n^2) <br />
Space Complexity - O(1) <br />

## Insertion Sort

Steps for Insertion Sort:

-> Iterate from arr[1] to arr[N] over the array. <br />
-> Compare the current element (key) to its predecessor. <br />
-> If the key element is smaller than its predecessor, compare it to the elements before. <br /> Move the greater elements one position up to make space for the 
   swapped element.

Complexity:
Time Complexity - O(n^2) <br />
Space Complexity - O(1) <br />

## Quick Sort

Pseudo Code for recursive QuickSort function:

/* low  –> Starting index,  high  –> Ending index */  <br />

quickSort(arr[], low, high) {

    if (low < high) { 

        /* pi is partitioning index, arr[pi] is now at right place */ 

        pi = partition(arr, low, high); 

        quickSort(arr, low, pi – 1);  // Before pi 
        quickSort(arr, pi + 1, high); // After pi

    } 

} <br />

Pseudo code for partition():

/* This function takes last element as pivot, places the pivot element at its correct position in sorted array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */ <br />

partition (arr[], low, high)<br />
{<br />
    // pivot (Element to be placed at right position)
    pivot = arr[high];  

    i = (low – 1)  // Index of smaller element and indicates the 
    // right position of pivot found so far

    for (j = low; j <= high- 1; j++){

        // If current element is smaller than the pivot
        if (arr[j] < pivot){
            i++;    // increment index of smaller element
            swap arr[i] and arr[j]
        }
    }
    swap arr[i + 1] and arr[high])
    return (i + 1)
}<br />

Complexity:
Time Complexity - O(n^2)<br />
Space Complexity - O(1)<br />
