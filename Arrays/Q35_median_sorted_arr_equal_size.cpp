#include<iostream>
using namespace std;

class ques35
{
    private:

   //Approach-3

   int median(int arr[], int s, int e) 
   {
        return (arr[(s + e) / 2] + arr[(s + e + 1) / 2]) / 2;
   }


    public:

    //Approach-2 -> Two Pointer Technique with counter

    int median_App_2(int arr1[],int arr2[],int n)
    {
        int counter=0;
        int m1=-1;
        int m2=-1;

        int i=0,j=0;

        for(counter=0;counter<=n;counter++)
        {
            //if arr1 have all smaller elements
            if(i==n)
            {
                m1=m2;
                m2=arr2[0];
                break;
            }

            //if arr2 have all smaller elements
            else if(j==n)
            {
                m1=m2;
                m2=arr1[0];
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
        return (m1+m2)/2;
    }

    //Approach-3

int median_App_3(int arr1[], int arr2[], int Sa, int Sb, int Ea, int Eb) 
    {
        //if array is of 2 size
        if (Ea - Sa <= 1)
        return (max(arr1[Sa], arr2[Sb]) + min(arr1[Ea], arr2[Eb])) / 2;

        //find meddian of first array        
        int m1 = median(arr1, Sa, Ea);

        //find median  of second array
        int m2 = median(arr2, Sb, Eb);

        //case-1
        if (m1 == m2)
        return m1;
        
        //case-2
        if (m1 > m2)
        return median_App_3(arr1,arr2, Sa, (Sb + Eb + 1) / 2, (Sa + Ea + 1) / 2, Eb);
        
        //case 3
        else
        return median_App_3(arr1, arr2, (Sa + Ea + 1) / 2, Sb, Ea, (Sb + Eb + 1) / 2);
    }
    
    
};

int main()
{
    int arr1[]={1,2,3,6};
    int arr2[]={4,7,8,10};

    int n=sizeof(arr1)/sizeof(arr1[0]);

    ques35 q;
    //cout<<q.median_App_2(arr1,arr2,n);
    cout<<q.median_App_3(arr1,arr2,0,0,n-1,n-1);

    return 0;
}