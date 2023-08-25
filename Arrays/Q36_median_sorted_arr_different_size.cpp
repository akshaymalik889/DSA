#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

class ques36
{
    public:

    //Approach -1 -> brute force
    float median_approach_1(int arr1[],int arr2[],int n1,int n2)
    {
        float ans;

        int newarray[n1+n2];
        int k=0;

        //copy first array
        for(int i=0;i<n1;i++)
        {
            newarray[k]=arr1[i];
            k++;
        }

        //copy second array
        for(int i=0;i<n2;i++)
        {
            newarray[k]=arr2[i];
            k++;
        }

        //sort new array
        sort(newarray,newarray+n1+n2);

        int n3=n1+n2;
        
        if(n3%2==0)
        ans=1.0 * (newarray[n3/2]+newarray[(n3/2)-1])/2;

        else
        ans=1.0 * (newarray[n3/2]);

        return ans;

    }

    //Approach -2 ->Two pointer
    float median_approach_2(int arr1[],int arr2[],int n1,int n2)
    {
        int n3=n1+n2;
        int newarray[n3];
        int k=0;
        float ans;
        int i=0,j=0;
        
        for(i=0,j=0;i<n1 && j<n2;)
        {
            if(arr1[i]<=arr2[j])
            {
                newarray[k]=arr1[i];
                i++;
                k++;
            }
            else
            {
                newarray[k]=arr2[j];
                j++;
                k++;
            }
        }

        while(i<n1)
        {
            newarray[k]=arr1[i];
            i++;
            k++;
        }
        while(j<n2)
        {
            newarray[k]=arr2[j];
            j++;
            k++;
        }

        if(n3%2==0)
        ans=1.0 * (newarray[n3/2]+newarray[(n3/2)-1])/2;
        else
        ans=1.0 * (newarray[n3/2]);

        return ans;
    }

    //Approach -3 ->Two pointer + counter
    float median_approach_3(int arr1[],int arr2[],int n1,int n2)
    {
        int m1=-1;
        int m2=-1;
        int count=0;
        int total_size=n1+n2;
        int i=0,j=0;
        double ans;

        for(count=0;count<=total_size/2;count++)
        {
            if(i==n1)
            {
                m1=m2;
                m2=arr2[j];
                break;
            }
            else if(j==n2)
            {
                m1=m2;
                m2=arr1[i];
                break;
            }

            if(arr1[i]<=arr2[j])
            {
                m1=m2;
                m2=arr1[i];
                i++;
            }
            else if(arr2[j]<arr1[i])
            {
                m1=m2;
                m2=arr2[j];
                j++;
            }
            
        }
        if(total_size%2==0)
        {
            ans=1.0 * (m1+m2)/2;
        } 
        else
        ans=m2;

        return ans;
    }

    //Approach -4 ->Using merge Sort
    float median_approach_4(int arr1[],int arr2[],int n1,int n2)
    {
        //ensuring that binary search happens on minimum size array
        if(n1>n2)
        return median_approach_4(arr1,arr2,n2,n1);
        
    int low=0,high=n1,medianPos=((n1+n2)+1)/2;
    while(low<=high) {
        int cut1 = (low+high)>>1;
        int cut2 = medianPos - cut1;
        
        int l1 = (cut1 == 0)? INT_MIN:arr1[cut1-1];
        int l2 = (cut2 == 0)? INT_MIN:arr2[cut2-1];
        int r1 = (cut1 == n1)? INT_MAX:arr1[cut1];
        int r2 = (cut2 == n2)? INT_MAX:arr2[cut2];
        
        if(l1<=r2 && l2<=r1) {
            if((n1+n2)%2 != 0)
                return max(l1,l2);
            else 
                return (max(l1,l2)+min(r1,r2))/2.0;
        }
        else if(l1>r2) high = cut1-1;
        else low = cut1+1;
    }
    return 0.0;
    }

};

int main()
{
    int arr1[]={3,5,8,10,15};
    int arr2[]={2,4,12};

    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);

    ques36 q;
    //cout<<q.median_approach_1(arr1,arr2,n1,n2);
    //cout<<q.median_approach_2(arr1,arr2,n1,n2);
    //cout<<q.median_approach_3(arr1,arr2,n1,n2);
    cout<<q.median_approach_4(arr1,arr2,n1,n2);

    return 0;
}

