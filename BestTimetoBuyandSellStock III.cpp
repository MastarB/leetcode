#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
    	int i = 0;
    	vector<int>Nprices;
        while(i < prices.size())
        {
        	while(i+1 < prices.size() && prices[i] >= prices[i+1])i++;
        	int buy = i;
        	i++;
        	if(i == prices.size())break;
        	while(i+1 < prices.size() && prices[i] <= prices[i+1])i++;
        	int sell = i;
        	Nprices.push_back(prices[buy]);
        	Nprices.push_back(prices[sell]);
        	i++;
        }
        
        int max = 0;
    	for(int i = 0; i < Nprices.size(); i+=2)
    	{
    		int profits = maxProfit(Nprices,i);
    		max = max > profits? max : profits;
    	}
    	return max;
        
    }

 	int maxProfit(vector<int>& prices, int med)
    {
    	return maxProfit(prices,0,med-1)+maxProfit(prices,med,prices.size()-1);
    }
    int maxProfit(vector<int>& prices, int b, int e)
    {
    	if(b > e)return 0;
    	int max = prices[b];
    	int min = prices[b];
    	int maxpro = 0;
    	 for(int i = b+1; i <= e; i++)
    	 {
    	 	if(prices[i] < min)
    	 	{
    	 		max = 0;
    	 		min = prices[i];
    	 	}
    	 	else if(prices[i] > max)
    	 	{
    	 		max = prices[i];
    	 		maxpro = maxpro > max-min ? maxpro : max-min;
    	 	}
    	 }
    	 return maxpro;
    }
};
