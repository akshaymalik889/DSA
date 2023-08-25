#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

class ques27
{
    public:

    //APPROACH -1 (SORTING)

    string array_subset_Ap_1(int arr1[],int arr2[],int n ,int m)
    {
        string str="";
    

        int matchCount=0;
    
        //sort both arrays
        sort(arr1,arr1+n);
        sort(arr2,arr2+m);
    
    
        //matching arr2[i],with arr1[i];
        for(int i=0,j=0;i<n && j<m;)
        {
            if(arr1[i]==arr2[j])
            {
                matchCount++;
                i++;
                j++;
            }
            else if(arr1[i]>arr2[j])
            j++;
            else
            i++;
        }
    
        if(matchCount==m)
        str.append("Yes");
        else
        str.append("No"); 
        return str;
    }

    //APPROACH -2 (HASHING)

    string array_subset_Ap_2(int arr1[],int arr2[],int n ,int m)
    {
        string str="";

        unordered_map<int,int>m1;

        //store arr1 in map
        for(int i=0;i<n;i++)
        {
            m1[arr1[i]]++;
        }

        //now check arr2 is present or not one by one
        for(int i=0;i<m;i++)
        {
            if(m1.count(arr2[i]) && m1[arr2[i]]>0)
            {
                m1[arr2[i]]--;
            }
            else
            {
                str.append("No");
                return str;
            }
        }
        str.append("Yes");
        return str;
    }
};


int main()
{
    int arr1[]={1,2,3,4,5,6,7,8};
    int arr2[]={1,2,3,1};

    int n=sizeof(arr1)/sizeof(arr1[0]);
    int m=sizeof(arr2)/sizeof(arr2[0]);

    ques27 q;
    string ans=q.array_subset_Ap_1(arr1,arr2,n,m);
    cout<<ans;
    // string ans=q.array_subset_Ap_2(arr1,arr2,n,m);
    // cout<<ans;

    return 0;

}