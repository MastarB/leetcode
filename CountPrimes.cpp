#include<unordered_set>
#include<iostream>
using namespace std;

class Solution {
public:
    int countPrimes(int n) 
    {
    	if(n <= 2)return 0;
    	int count = 0;
		bool set[n];
		for(int i = 2; i < n; i++)
			set[i] = true;
		for(int i = 2; i*i < n; i++)
		{
			if(set[i] == false)continue;
			else
			{
				int t(i*i);
				while(t < n)
				{
					set[t] = false;;
					t += i;
				}
			}
		}
		
		for(int i = 2; i < n; i++)
			count += set[i] ?1:0;
		return count;
    }
};

int main()
{
	Solution so;
	std::cout<<so.countPrimes(120);
}
