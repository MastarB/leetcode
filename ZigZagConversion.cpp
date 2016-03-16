#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) 
	{
		if(numRows==1)return s;
		vector<string>rows;
		for(int i=0;i<numRows;i++)
			rows.push_back("");	
		bool down = true;
		int l = 0;
		for(int row = 0;;l<s.size();down?++row:--row)
		{
			if(row==-1)
			{
				down =true;
				row = 1;
			}
			if(row==numRows)
			{
				down = false;
				row = numRows -2;
			}
			rows[row].push_back(s[l]);
			l++;
			
		}
		string ans;
		for(int i=0 ;i<numRows;i++)
		ans.append(rows[i]);
		return ans;	
	}
};

int main()
{
	Solution so;
	cout<<so.convert("PAYPALISHIRING",3);
}
