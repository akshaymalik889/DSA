#include<iostream>
#include<vector>
using namespace std;


class ques9
{
    public:
    void minimize_heights_ap_1(int arr[],int n,int k)
    {
        
        
        vector<pair<int,int> > v;
        vector<int>visited(n);

    //Insert all posible heights in vector
        for(int i=0;i<n;i++)
        {
            if(arr[i]-k>=0)
            v.push_back(make_pair(arr[i] - k, i));

            v.push_back(make_pair(arr[i] + k, i));
        }

        //sort vector to got maximum diff ie.diff b/w largest-smallest
        sort(v.begin(),v.end());

        int ele=0;
        int left=0;
        int right=0;

        while(ele<n && right<v.size())
        {
            if(visited[v[right].second]==0)
            ele++;
            
            visited[v[right].second]++;
            right++;
        }
        int ans=v[right-1].first-v[left].first;

        while(right<v.size())
        {
            if(visited[v[left].second]==1)
            ele--;

            visited[v[left].second]--;
            left++;
        
            while(ele<n && right<v.size())
            {
                if(visited[v[right].second]==0)
                ele++;

                visited[v[right].second]++;
                right++;
            }

            if(ele==n)
            ans=min(ans,v[right-1].first-v[left].first);
            else
            break;

        }
        cout<<"answer="<<ans<<endl;
        
    }
    
    void minimize_heights_ap_2(int arr[],int n,int k)
    {
        //sort
        sort(arr,arr+n);
        
        int ans=arr[n-1]-arr[0];
    
        int smallest=arr[0]+k;
        int largest=arr[n-1]-k;
        
        
        
        int mi,ma;
        
        for(int i=0;i<n-1;i++)
        {
            int mi=min(smallest,arr[i+1]-k);
            int ma=max(largest,arr[i]+k);
            
            if(mi<0)
            continue;
            ans=min(ans,ma-mi);
        }
        cout<<"answer="<<ans<<endl;
    }
};

int main()
{
    int arr[]={1,5,8,10};
    int n=4;
    
    ques9 q;

    int k=2;
    q.minimize_heights_ap_1(arr,n,k);
    //q.minimize_heights_ap_2(arr,n,k);

    return 0;

}