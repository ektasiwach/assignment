/*
Build a min heap from array and make sure that heap order property is maintainedafterevery input. The input is checked if it is greater than it’s parent, if it’s not, it is swapped. You can take the sample array as: arr = [1,5,6,8,9,7,3]
Write a generalized program so that user can input any set of values. Your insertion functionshould take O(n) time as compared to O(n log n) time.
*/

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int smallest = i; // Initialize smalles as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is smaller than root
    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    // If right child is smaller than smallest so far
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    // If smallest is not root
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, smallest);
    }
}

// Function to build a Min-Heap from the given array
void buildHeap(int arr[], int n)
{
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

// A utility function to print the array
// representation of Heap
void printHeap(int arr[], int n)
{
    cout << "Array representation of Heap is:\n";

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << "\n";
}

// Driver Code
int main()
{
    // Binary Tree Representation
    // of input array
    // 1
    //           /     \
    // 3         5
    //      /    \     /  \
    // 4      6   13  10
    //    / \    / \
    // 9   8  15 17
    int arr[] = {1, 5, 6, 8, 9, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildHeap(arr, n);

    printHeap(arr, n);
    // Final Heap:
    // 1
    //           /     \
    // 3         5
    //      /    \     /  \
    // 4      6   13  10
    //    / \    / \
    // 9   8  15 17

    return 0;
}