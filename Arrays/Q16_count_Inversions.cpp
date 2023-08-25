#include<iostream>
using namespace std;

class ques16
{
    private:

        //Approach -2
    
    int merge(int arr[],int temp[],int low,int mid,int high)
    {
        int i,j,k,count=0;
        i=low;
        j=mid;
        k=low;
        
        while( (i<=mid-1) && (j<=high) )
        {
            if(arr[i]<=arr[j])
            {
                temp[k]=arr[i];
                k++;
                i++;
            }
            else
            {
                temp[k]=arr[j];
                k++;
                j++;
                count=count+(mid-i);
            }
        }
        
        while(i<=mid-1)
        {
            temp[k]=arr[i];
            k++;
            i++;
        }
        
        while(j<=high)
        {
            temp[k]=arr[j];
            k++;
            j++;
        }
        
        //update temp array in original array
        for(int m=low;m<=high;m++)
        {
            arr[m]=temp[m];
        }
        
        return count;
    }
    
    int mergeSort(int arr[],int temp[],int low,int high)
    {
        int count=0;
        
        if(low<high)
        {
            int mid=low+ ((high-low)/2);
            
            count=count+mergeSort(arr,temp,low,mid);
            count=count+mergeSort(arr,temp,mid+1,high);
            
            count=count+merge(arr,temp,low,mid+1,high);
        }
        return count;
    }

    public:

    //Approach -1 ->compare all values
    int count_inversions_app_1(int arr[],int n)
    {
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]>arr[j])
                count++;
            }
        }

        return count;
    }

    int count_inversions_app_2(int arr[],int n)
    {
        int temp[n];
        
        return mergeSort(arr,temp,0,n-1);
    }
};

int main()
{
    int arr[]={3,5,2,1,8,6,4,9};
    int n=8;

    ques16 q;

    //cout<<q.count_inversions_app_1(arr,n);
    cout<<q.count_inversions_app_2(arr,n);


    return 0;
}