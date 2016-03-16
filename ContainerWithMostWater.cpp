#include<iostream>
#include<vector> 
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height)
	{
		/*≥ı ºªØ*/ 
    	int b = 0;
    	int e = height.size()-1;
    	int maxarea = 0;
    	while(b < e)
    	{
    		cout<<b<<' '<<e<<endl;
    		int end = e;
    		int maxleft = -1;
    		int maxindex;
    		
    		while(end >b)
    		{
    			if(height[end]>maxleft)
    			{
    				maxindex = end;
    				maxleft = height[end];
				}
    			if(height[end]>height[b])
    			{
    				
    				break;
				}
				end--;
			}

			int maxareaindex = maxindex;
			int max1area = min(height[maxindex],height[b])*(maxindex -b);
			maxindex++;
			while(maxindex <=e)
			{
				if(height[maxindex]*(maxindex -b) > max1area)
				{
					max1area = height[maxindex]*(maxindex -b);
					maxareaindex = maxindex;
				}
				maxindex++;
			}
			maxarea = maxarea <	max1area?max1area:maxarea;
			if(end == b)break;
			e = end;
			int beg = b;
			while (height[beg]<=height[b])
			beg++;
			b = beg;
			cout<<maxarea<<endl;
    	}
    	return maxarea;
    }
};

int main()
{
	Solution so;
	int v[8]={2,3,5,1,4,1,3,2};
	vector<int>vec;
	for(int i =0;i<8;i++)
	vec.push_back(v[i]);
	cout<<so.maxArea(vec); 
}
