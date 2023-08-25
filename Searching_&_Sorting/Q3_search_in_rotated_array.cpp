#include<iostream>
#include<vector>
using namespace std;

class ques3
{
    public:
    int search_rotated_arr(vector<int>arr,int target)
    {
        int low=0;
        int high=arr.size()-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(arr[mid]==target)
            return mid;

            //finding mid search-space

            //first search-space
            else if(arr[mid]>=arr[low])
            {
                //finding target search-space

                //first search space
                if(target>=arr[low] && target<=arr[mid]) 
                high=mid-1;

                //second search-space
                else   
                low=mid+1;
            }
            //second search-space
            else
            {
                //second search-space
                if(target>=arr[mid] && target<=arr[high])
                low=mid+1;
                else
                high=mid-1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int>arr{4,5,6,7,0,1,2};
    int target=0;

    ques3 q;
    cout<<q.search_rotated_arr(arr,target);

    return 0;
}