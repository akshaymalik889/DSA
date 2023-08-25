#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class ques17
{
    public:
    int buy_sell_Stock(vector<int>prices)
    {
        int buy_price=INT_MAX;
        int profit=0;

        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<buy_price)
            buy_price=prices[i];

            else
            {
                if(prices[i]-buy_price>profit)
                profit=prices[i]-buy_price;
            }
        }

        return profit;
    }
};

int main()
{
    vector<int>prices{2,15,9,3,1};
    
    ques17 q;
    cout<<q.buy_sell_Stock(prices);


    return 0;
}
