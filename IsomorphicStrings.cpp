class Solution {
public:
    bool isIsomorphic(string s, string t) 
	{
		int hash1[128];
		int hash2[128];
		for(int i = 0; i < 128; i++)
			hash1[i] = hash2[i] = -1;
		int index1 = 0;
		int index2 = 0;
        for(int i = 0; i < s.size(); i++)
        {
        	int i1 = s[i];
        	int i2 = t[i];
        	if(hash1[i1] == -1)hash1[i1] = index1++;
        	if(hash2[i2] == -1)hash2[i2] = index2++;
        	if (hash1[i1] != hash2[i2])return false;
		}
		return true;
    }
};
