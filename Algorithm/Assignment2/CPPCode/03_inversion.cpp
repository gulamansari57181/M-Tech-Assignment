#include <iostream>
using namespace std;

// Merge function to count inversions
int mergeAndCount(int arr[], int left, int mid, int right) {
    int i = left;     
    int j = mid + 1;  
    int k = 0;        
    int invCount = 0; 

    // Temporary array to hold merged elements
    int temp[right - left + 1];

    // Merge and count inversions
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // There is an inversion, as arr[i] > arr[j]
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);  // All elements from arr[i] to arr[mid] are greater than arr[j]
        }
    }

    // Copy the remaining elements of the left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // To copy remaining elements of the right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // To copy back the merged elements into the original array
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }

    return invCount;
}

// Divide and conquer function to count inversions
int mergeSortAndCount(int arr[], int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Count inversions in the left subarray
        invCount += mergeSortAndCount(arr, left, mid);

        // Count inversions in the right subarray
        invCount += mergeSortAndCount(arr, mid + 1, right);

        // Count inversions during the merge step
        invCount += mergeAndCount(arr, left, mid, right);
    }
    return invCount;
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

    int result = mergeSortAndCount(arr, 0, size - 1);
    cout << "Number of inversions: " << result << endl;

    return 0;
}
