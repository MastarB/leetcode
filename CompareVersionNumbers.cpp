class Solution {
public:
    int compareVersion(string version1, string version2) 
	{
    	vector<int>a(phase(version1));
    	vector<int>b(phase(version2));
    	while(a.size() < b.size())
    		a.push_back(0);
    	while(a.size() > b.size())
    		b.push_back(0);
    	int l = b.size();
    	int index = 0;
    	while(index < l)
    	{
    		if(a[index] > b[index])return 1;
    		if(a[index] < b[index])return -1;
    		index++;
		}
   		return 0;	
    }
    
    vector<int> phase(string& a)
    {
    	vector<int>v;
    	int acc = 0;
    	for(int i = 0; i < a.size(); i++)
    	{
    		if(a[i] != '.')
			{
				acc *= 10;
				acc += (a[i]-'0');	
			}
			else
			{
				v.push_back(acc);
				acc = 0;
			}
		}
		v.push_back(acc);
		return v;
	}
};
