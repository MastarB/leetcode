#include<vector>
#include<random>
#include<iostream>
using namespace std;

class Solution 
{
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) 
	{
		shuffle(candidates);
		quicksort(candidates,0,candidates.size()-1);
        vector<vector<int> > ans;
        vector<int> accumv;
        findCom(candidates,target,ans,accumv,0,0,-1);
        return ans;
    }
    
    void findCom(vector<int>& candidates, int target, vector<vector<int> >& ans, vector<int> &accumv, int accum, int pointer, int same)
    {
    	if(accum ==target)ans.push_back(accumv);
    	else if(accum < target)
    	{
    		if(pointer < candidates.size())
    		{	
    			if(same != candidates[pointer])
				{
					/*原地加完指针右移一格*/
    				accumv.push_back(candidates[pointer]);
    				findCom(candidates,target,ans,accumv,accum+candidates[pointer],pointer+1,same);
    				accumv.pop_back();
    			}
    			/*不加直接移动*/ 
				findCom(candidates,target,ans,accumv,accum,pointer+1,candidates[pointer]);
			} 
    		
    	}
    }
    
    void shuffle(vector<int>& v)
    {
    	for(int i = 0; i < v.size(); i++)
    		swap(v[i],v[rand()%(i+1)]);
	}
	
	void quicksort(vector<int>& v, int b, int e)
	{
		if(b < e)
		{
			int p = partition(v,b,e);
			quicksort(v,b,p-1);
			quicksort(v,p+1,e);
		}
	}
	
	int partition(vector<int>& v, int b, int e)
	{
		int i = b+1;
		int j = e;
		while(i<=j)
		{
			if(v[i] > v[b])
			{
				swap(v[i],v[j]);
				j--;
			}
			else i++;
		}
		swap(v[i-1],v[b]);
		return i-1;
	}
};

int main()
{
	Solution so;
	vector<int>can;
	int t = 1;
	can.push_back(1);can.push_back(1);
	vector<vector<int>>ans;
	ans = so.combinationSum2(can,t);
	for(int i = 0 ;i<ans.size();i++)
	{
		for(int j = 0; j<ans[i].size();j++)
			cout<<ans[i][j]<<' ';
		cout<<endl;
	}
 } 
