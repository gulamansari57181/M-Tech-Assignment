arr=[10,7,9,8]
print(arr)


def merge(arr,start,mid,end):
    temp=[]
    left=start
    right=mid+1
    # Change 1
    inv=0
    
    while left<= mid and right<=end:
        if arr[left]<= arr[right]:
            temp.append(arr[left])
            left +=1
        else:
            
            # change 2
            inv +=(mid-left +1)
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
    
    return inv


def mergeSort(arr,start,end):
    # Change-3
    inversion=0
    if start==end:
        # Only single element in the array
        # We have break the array till single element
        # Change-4
        return inversion
    # To get mid index of an array without overflow condition
    
    mid= start +(end-start)//2
    
    # Now recursively call for divide left part
    inversion += mergeSort(arr,start,mid)
    # print(inversion)
    
    # To recursively divide right part of the array
    inversion += mergeSort(arr,mid+1,end)
    
    # Merge method call
    inversion += merge(arr,start,mid,end)
    
    return inversion

    
    
#MergeSort Call
print(mergeSort(arr,0,len(arr)-1))

print(f"Sorted Array is {arr}") 

    
    
    
    