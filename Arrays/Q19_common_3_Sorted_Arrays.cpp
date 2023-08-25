#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class ques19
{
    public:

    //Approach-1 . using space
    void common_element_Ap_1(int arr1[],int arr2[],int arr3[],int n1,int n2,int n3)
    {
        vector<int>ans;

        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        unordered_map<int,int>m3;

        for(int i=0;i<n1;i++)
        {
            m1[arr1[i]]++;
        }
        for(int i=0;i<n2;i++)
        {
            m2[arr2[i]]++;
        }
        for(int i=0;i<n3;i++)
        {
            m3[arr3[i]]++;
        }

        for(int i=0;i<n1;i++)
        {
            if(m1.count(arr1[i]) && m2.count(arr1[i]) && m3.count(arr1[i]))
            ans.push_back(arr1[i]);
            
            //for unique elements
            m1[arr1[i]]=0;
        }

        for(auto i:ans)
        cout<<i<<" ";
    }

    //Approach-2 without space

    void common_element_Ap_2(int arr1[],int arr2[],int arr3[],int n1,int n2,int n3)
    {
          vector<int>ans;
            for(int i=0,j=0,k=0;i<n1 && j<n2 && k<n3;)
            {
                if(arr1[i]==arr2[j] && arr2[j]==arr3[k])
                {
                    ans.push_back(arr1[i]);
                    i++;
                    j++;
                    k++;
                }
                else if(arr1[i] < arr2[j] )
                i++;
                else if(arr2[j] < arr3[k] )
                j++;
                else
                k++;
                
                //for unique elements only
                int prev1=arr1[i-1];
                while(arr1[i]==prev1)
                i++;
                
                int prev2=arr2[j-1];
                while(arr2[j]==prev2)
                j++;
                
                int prev3=arr3[k-1];
                while(arr3[k]==prev3)
                k++;
                
            }

            for(auto i:ans)
            cout<<i<<" ";
    }

};

int main()
{
    int arr1[]={1,5,10,20,40,80};
    int arr2[]={6,7,20,80,100};
    int arr3[]={3,4,15,20,30,70,80,120};
    int n1=6,n2=5,n3=8;

    ques19 q;
    q.common_element_Ap_1(arr1,arr2,arr3,n1,n2,n3);

    return 0;
}
