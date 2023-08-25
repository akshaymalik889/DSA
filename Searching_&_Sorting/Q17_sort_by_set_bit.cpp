#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class ques17
{
    private:
    static bool compare(int a,int b)
    {
        int c1 = __builtin_popcount(a);
        int c2 = __builtin_popcount(b);
        if(c1 == c2)
        return a < b;
        
        return c1 < c2;
    }

    public:
    vector<int> sort_by_Set_Bit(vector<int>arr)
    {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};


int main()
{
    vector<int>arr={5,2,3,9,4,6,7,15,32};

    ques17 q;
    vector<int>ans=q.sort_by_Set_Bit(arr);

    //print
    for(auto i:ans)
    cout<<i<<" ";

    return 0;
}