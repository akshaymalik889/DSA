#include<iostream>
using namespace std;


class ques34
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
    //Approach-1
    int inversion_Count_Ap_1(int arr[],int n)
    {
        int count;
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


    //Approach-2 using merge sort
    int inversion_Count_Ap_2(int arr[],int n)
    {
        int temp[n];
        
        return mergeSort(arr,temp,0,n-1);
    }
};

int main()
{
    int arr[]={2,4,1,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    ques34 q;

    //Approach-1
    //cout<<q.inversion_Count_Ap_1(arr,n);

    //Approach-2
    cout<<q.inversion_Count_Ap_2(arr,n);

    return 0;
}