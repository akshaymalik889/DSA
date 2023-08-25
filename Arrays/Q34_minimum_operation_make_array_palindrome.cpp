#include<iostream>
using namespace std;


class ques34
{
    public:
    int minimum_operations(int arr[],int n)
    {
        int ans = 0;

	    for (int i=0,j=n-1; i<=j;)
	    {
		    // If corner elements are same,
		    // problem reduces arr[i+1..j-1]
		    if (arr[i] == arr[j])
		    {
			    i++;
			    j--;
		    }

		    // If left element is greater, then
		    // we merge right two elements
		    else if (arr[i] > arr[j])
		    {
			    // need to merge from tail.
			    j--;
			    arr[j] += arr[j+1] ;
			    ans++;
		    }

		    // Else we merge left two elements
		    else
		    {
			    i++;
			    arr[i] += arr[i-1];
			    ans++;
		    }
	    }

	    return ans;
    }
};

int main()
{
    int arr[]={11,14,15,99};
    int n=sizeof(arr)/sizeof(arr[0]);

    ques34 q;
    cout<<q.minimum_operations(arr,n);

    return 0;
}