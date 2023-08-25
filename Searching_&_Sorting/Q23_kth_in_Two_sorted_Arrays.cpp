#include<iostream>
#include<limits.h>
using namespace std;


class ques23
{
    public:

    //Approach-1 using counter
    int kth_element_App_1(int arr1[],int arr2[],int n,int m,int k)
    {
        int p1=0,p2=0,counter=0,answer=0;
    
        while(p1<m && p2<n) 
        {
            if(counter == k) 
            break;
            
            else if(arr1[p1]<arr2[p2]) 
            {
                answer = arr1[p1];
                ++p1;
            }
            else
            {
                answer = arr2[p2];
                ++p2;
            }
            ++counter;
        }
    
        if(counter != k) 
        {
            if(p1 != m-1) 
            answer = arr1[k-counter];
            else 
            answer = arr2[k-counter];
        }
        return answer;
    }

    //Approach-2 USING BINARY SEARCH
    int kth_element_App_2(int arr1[],int arr2[],int n,int m,int k)
    {
        if(n > m)
        {
            return kth_element_App_2(arr2, arr1, m, n, k); 
        }
        
        int low = max(0,k-n), high = min(k,m);
        
        while(low <= high) 
        {
            int cut1 = (low + high)/2; 
            int cut2 = k - cut1; 

            int l1,l2,r1,r2;

            if(cut1==0)
            l1=INT_MIN;
            else
            l1=arr1[cut1-1];

            if(cut2==0)
            l2=INT_MIN;
            else
            l2=arr2[cut2-1];

            if(cut1==m)
            r1=INT_MAX;
            else
            r1=arr1[cut1];

            if(cut2==n)
            r2=INT_MAX;
            else
            r2=arr2[cut2];
            
            if(l1 <= r2 && l2 <= r1) 
            {
                return max(l1, l2);
            }
            else if (l1 > r2)
            {
                high = cut1 - 1;
            }
            else 
            {
                low = cut1 + 1; 
            }
        }
        return 1; 
    }
};

int main()
{
    int arr1[]={2,3,6,7,9};
    int arr2[]={1,4,8,10};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int m=sizeof(arr2)/sizeof(arr2[0]);
    int k=5;


    ques23 q;
    
    //Approach-1
    //cout<<q.kth_element_App_1(arr1,arr2,n,m,k);

    // //Approach-2 ->Binary search
    cout<<q.kth_element_App_2(arr1,arr2,n,m,k);

    return 0;
}