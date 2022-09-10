/**
 * @file main.cpp
 * @author Adrian Hernandez (a01747038@tec.com)
 * @brief Tarea de sorts y de busquedas
 * @version 0.1
 * @date 2022-09-05
 * 
 * TODO:
 *     - Correctly implement quicksort 
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

/**
 * @brief Displays vector for facility while debugging
 * @param arr arry of type T
 * @param n size of array n
 */
template<typename T>
void printArr(T *arr, int n) {
    for (int i=0; i<n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

/**  
 * Ordena los numeros en arr
 * 
 * Se ordenan los numeros dentro de arr con el algoritmo
 * de bubblesort con complejidad O(n^2) 
 * 
 * @param n numero de llaves en el array
 */
template <typename T>
void bubbleSort(T *arr, int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-1; j++) {
            int helper = arr[j+1];
            if (helper < arr[j]) {
                arr[j+1] = arr[j];
                arr[j] = helper;
            }
        }
    }
}

/**
 * @brief Sorts an array in non-decreasing order using Swap sort algorithm
 *        thus the complexity of the process is O(n^2) 
 * 
 * @tparam T type of the elements in the array
 * @param arr T* pointer t the start of the array
 * @param n int size of the array
 */
template <typename T>
void swapSort(T *arr, int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            int helper = arr[i]; 
            if (arr[j] < helper) {
                arr[i] = arr[j];
                arr[j] = helper; 
            }
        }
    }    
} 

/**
 * @brief Sorts an array using the insertion sort algorithm.
 *        complexity is O(n^2)
 * 
 * @tparam T type of the elemens in the array
 * @param arr array of keyss
 * @param n size of the array
 */
template <typename T>
void insertionSort(T *arr, int n) {
    for (int i=1; i<n; i++) {
        int helper = arr[i];
        // move helper to the left each time that we encounter a
        // greater element
        for (int j=i-1; j>=0; j--) {
            if (arr[j] > helper) {
                arr[j+1] = arr[j];
                arr[j] = helper;
            } else {
                break;
            }
        }
    }
}

/**
 * @brief Merges two sorted arrays into a sorted array
 *        This process has complexity O(n)
 * 
 * @tparam T type of the array keys and returned array 
 * @param arr1 sorted array of type T
 * @param arr2 sorted array of type 
 * @return merged sorted array array 
 */
template <typename T>
T *mergeArr(T *arr1, T *arr2, int l1, int l2) {
    T *array = new T[l1+l2]; 
    int ptr = 0;
    int ptr1 = 0;
    int ptr2 = 0;
    while (ptr1 < l1 && ptr2 < l2) {
        if (arr1[ptr1] < arr2[ptr2]) {
            array[ptr] = arr1[ptr1];
            ptr1++;
            ptr++;
        } else {
            array[ptr] = arr2[ptr2];
            ptr2++;
            ptr++;
        }
    }
    
    while (ptr1 < l1) {
        array[ptr] = arr1[ptr1];
        ptr1++;
        ptr++;
    }
    
    while (ptr2 < l2) {
        array[ptr] = arr2[ptr2];
        ptr2++;
        ptr++;
    }
    return array;
}

/**
 * @brief Sorts an array using the iterative mergesort algorithm
 *        this process has a complexity of O(nlog_2(n)) 
 * 
 * @tparam T type of keys in array arr
 * @param arr array of keys type T
 * @param n size of the array 
 */
template <typename T>
void mergeSort(T *arr, int n) {
    if (n < 2) {
        return;
    }
    
    mergeSort(arr, n/2);
    mergeSort(arr + (n/2), (n/2) + (n%2));

    T *merged = mergeArr<T>(arr, arr+(n/2), n/2, (n/2) + (n % 2));

    printArr<T>(merged, n);
    
    std::copy(merged, merged+n, arr);
}   

// auxiliary for quick sort

int swapping(std::vector<int> &arr, int lowest_index, int max_index){
    int pivot = arr[max_index];
    int i = (lowest_index - 1);
    for (int j = lowest_index; j <= max_index - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[max_index]);
    return (i + 1);
}

/**
 * @brief Sorts array using the quicksort algorithm which has O(n^2) and Omega(nlog(n)) 
 * 
 * @tparam T type of the keys in the array
 * @param arr array to be sorted
 * @param n size of the array
 */
void quickSort(std::vector<int> &arr, int lowest_index, int max_index) {
  int i;
    if (lowest_index < max_index)
    {
        int part_index = swapping(arr, lowest_index, max_index);
        quickSort(arr, lowest_index, part_index - 1);
        quickSort(arr, part_index + 1, max_index);
    }  
}

// SEARCHES

/**
 * @brief Search a key k in an array arr of size n 
 *        using sequential search. The complexity of this is O(n)
 * 
 * @param arr T* pointer to the beggining of the array 
 * @param n int number of items in the array
 * @param k T key looked for in the array
 * 
 * @return int index of the item looked for or -1 if it doesnt exist
 */
template <typename T>
int sequentiaSearch(T* arr, int n, T key) {
    for (int i=0; i<n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Search a key k in an array arr of size n 
 *        using binary search. The complexity of this is O(log_2(n))
 * 
 * @param arr T* pointer to the beggining of the array 
 * @param n int number of items in the array
 * @param k T key looked for in the array
 * 
 * @return int index of the item looked for or -1 if it doesnt exist
 */
template <typename T>
int binarySearch(T* arr, int n, T key) {
    int lower = 0;
    int upper = n - 1;
    int middle = (n - 1) / 2;
    
    while (lower <= upper) {
        middle = (lower + upper) / 2;

        if (arr[middle] == key) {
            return middle;
        } 
        if (arr[middle] > key) {
            upper = middle - 1;
        } else {
            lower = middle + 1;
        }
    } 

    return -1;
}

int main()
{
    std::vector<int> vec = {10, 9, 8, 7, 6, 4, 5, 3, 2, 1};
    quickSort(vec, 0, 9);

    for (int item : vec) {
        std::cout << item << " ";
    }
    // st::cout << binarySearch<int>(arr, 10, 10) << "\n";
}
