#include <iostream>
using namespace std;

// To store actual element value and its index
struct Element {
    int value;  
    int index; 
};

// Function to merge two halves and count the smaller elements
void merge(Element arr[], int left, int mid, int right, int count[]) {
    int i = left;  
    int j = mid + 1;  

    // Counts how many elements from the right subarray are smaller
    int rightCount = 0;  
    
    // Temporary array to hold the merged elements
    Element temp[right - left + 1];
    int k = 0;  // Pointer to temp array
    
    // Counting number of elements greater than cureent element while merging
    while (i <= mid && j <= right) {
        if (arr[i].value > arr[j].value) {
            // If an element in the right subarray is smaller than in the left
            rightCount++;
            temp[k++] = arr[j++];
        } else {
            // Element in left subarray is greater than or equal to the right one
            count[arr[i].index] += rightCount;  
            temp[k++] = arr[i++];
        }
    }
    
    // Remaining elements in the left subarray
    while (i <= mid) {
        count[arr[i].index] += rightCount;  // Add the accumulated rightCount
        temp[k++] = arr[i++];
    }

    // Remaining elements in the right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back the merged elements into the original array
    for (int p = 0; p < k; p++) {
        arr[left + p] = temp[p];
    }
}


void mergeSortAndCount(Element arr[], int left, int right, int count[]) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Find the midpoint
        
        // Recursively sort and count the left and right halves
        mergeSortAndCount(arr, left, mid, count);
        mergeSortAndCount(arr, mid + 1, right, count);
        
        // Merge the two halves and count smaller elements
        merge(arr, left, mid, right, count);
    }
}

int main() {

    int size;
    cout<<"Enter size of an numbers array :";
    cin>>size;
    // Initialization of numbers array
    int arr[size];

    // Taking input numbers and storing it into the arr of integers

    for(int num=0;num<size;num++){
        cout<<"Enter "<<num+1<<" number :";
        cin>>arr[num];
    }
    
    // Array to store the number of smaller elements for each position
    int count[size] = {0};  
    
    // Create an array of elements where we store both value and index
    Element elements[size];
    for (int i = 0; i < size; i++) {
        elements[i].value = arr[i];
        elements[i].index = i;
    }
    
    // Apply merge sort and count
    mergeSortAndCount(elements, 0, size - 1, count);
    
    // Output the results
    cout << "Output: ";
    for (int i = 0; i < size; i++) {
        cout << count[i] << " ";
    }
    cout << endl;

    return 0;
}
