#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) 
    {
    	unordered_set<string>set;
    	
		string nn(to_string(n));
		set.insert(nn);
		while(nn.compare("1") != 0)
		{
			int tmp = 0;
			for(int i = 0; i < nn.size(); i++)
				tmp += (nn[i] - '0')*(nn[i] - '0');
			nn = to_string(tmp);
			if(set.find(nn) == set.end())set.insert(nn);
			else return false;
		}
		return true;
    }
};
