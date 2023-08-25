#include<iostream>
using namespace std;


class ques35
{
    private:

    void merge(int arr[],int start,int end,int mid)
    {
        int start2 = mid + 1;
  
        // If the direct merge is already sorted
        if (arr[mid] <= arr[start2])
        return;
    
  
        // Two pointers to maintain start
        // of both arrays to merge
        while (start <= mid && start2 <= end) 
        {
  
            // If element 1 is in right place
            if (arr[start] <= arr[start2])
            start++;
        
            else 
            {
                int value = arr[start2];
                int index = start2;
  
                // Shift all the elements between element 1
                // element 2, right by 1.
                while (index != start)
                {
                    arr[index] = arr[index - 1];
                    index--;
                }
                arr[start] = value;
  
                // Update all the pointers
                start++;
                mid++;
                start2++;
            }
        }
    }

    void mergeSort(int arr[],int low,int high)
    {
        if (low < high) 
        {
            // Same as (l + r) / 2, but avoids overflow
            // for large l and r
            int mid = low + (high - low) / 2;
  
            // Sort first and second halves
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
  
            merge(arr, low, high, mid);
        }
    }

    public:
    void mergeSort_Constant(int arr[],int n)
    {
        mergeSort(arr, 0, n - 1);
    }
};

int main()
{   
    int arr[]={12, 11, 13, 5, 6, 7};
    int n=sizeof(arr)/sizeof(arr[0]);

    ques35 q;
    q.mergeSort_Constant(arr,n);

    //printing array
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}