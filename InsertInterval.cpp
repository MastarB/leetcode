#include<vector>
#include<random>
using namespace std;
 /* Definition for an interval.*/
struct Interval 
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals,Interval newInterval) 
	{
		vector<Interval>ans;
		intervals.push_back(newInterval);
		shuffle(intervals);
        sort(intervals,0,intervals.size()-1);
        Interval guard = intervals[0];
        for(int i = 1; i < intervals.size(); i++)
        {
        	if(guard.end >= intervals[i].start)guard = Interval(guard.start,max(guard.end,intervals[i].end));
        	else 
			{
				ans.push_back(guard);
        		guard = intervals[i];
			}
		}
		ans.push_back(guard);
		return ans;
    }
    
    void shuffle(vector<Interval>& in)
    {
    	for(int i = 0; i < in.size(); i++)
    		swap(in[i],in[rand()%(i+1)]);
	}
	
	void sort(vector<Interval>& in, int b, int e)
	{
		if(b < e)
		{
			int p =	partition(in,b,e);
			sort(in,b,p-1);
			sort(in,p+1,e);
		}
	}
	
	int partition(vector<Interval>&in, int b, int e)
	{
		int i = b+1;
		int j = e;
		while(i <= j)
		{
			if(in[i].start > in[b].start)
			{
				swap(in[i],in[j]);
				j--;
			}
			else i++;
		}
		swap(in[i-1],in[b]);
		return i-1;
	}
};

int main()
{
	vector<Interval> in;
	vector<Interval> ans;
	in.push_back(Interval(1,4));
	in.push_back(Interval(1,4));
	Solution so;
	
}
