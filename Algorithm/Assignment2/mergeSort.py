arr=[3,6,9,12,34,50]



def merge(arr,start,mid,end):
    temp=[]
    
    left=start
    right=mid+1
    
    while left<= mid and right<=end:
        if arr[left]<= arr[right]:
            temp.append(arr[left])
            left +=1
        else:
            temp.append(arr[right])
            right+=1
    
    # What if left array exhausted, there miight be some element left in right array
    
    while right<=end:
        temp.append(arr[right])
        right +=1
    
    
    # What if right array exhausted, there miight be some element remain in left array
    
    while left<=mid:
        temp.append(arr[left])
        left +=1
    
    # Copy the sorted temp array back to the original array
    for i in range(len(temp)):
        arr[start +i] = temp[i]

def mergeSort(arr,start,end):
    if start==end:
        # Only single element in the array
        # We have break the array till single element
        return
    # To get mid index of an array without overflow condition
    
    mid= start +(end-start)//2
    
    # Now recursively call for divide left part
    mergeSort(arr,start,mid)
    
    # To recursively divide right part of the array
    mergeSort(arr,mid+1,end)
    
    # Merge method call
    merge(arr,start,mid,end)

    
    
#MergeSort Call
mergeSort(arr,0,len(arr)-1)

print(f"Sorted Array is {arr}") 

    
    
    