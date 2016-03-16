#include<cstring>
#include<list>
#include<map>
#include<string>
#include<iostream>
#include<utility>
using namespace std;
class Solution {
public:
	/*struct MyCompare
	{
		bool operator()(const pair<int,int>& a, const pair<int,int>& b)
		{
			return a.first < b.first || a.first == b.first&& a.second <= b.second;
		}
	};
	*/
    string fractionToDecimal(int numerator, int denominator) 
    {
    	long long n = numerator;
    	long long d = denominator;
    	bool neg = n > 0 && d < 0 || n < 0 && d > 0;
    	n = n >= 0 ? n :-n;
    	d = d >= 0 ? d :-d;
    	string a(neg?"-":"");
		a.append(toString(n/d));
		n %= d;
		if(n != 0)
		fractionToDecimal(n,d,a);
		return a;
	}
	
	void fractionToDecimal(long long n, long long d, string& a)
	{
		a.push_back('.');
			//map<pair<int,int>,list<int>::iterator,MyCompare>pmap;
		map<pair<long long,long long>,list<long long>::iterator>pmap;
		list<long long>que; 
		long long nn = n*10;
		while(nn !=0 && pmap.find(make_pair(nn/d,nn%d)) == pmap.end())
		{
			que.push_back(nn/d);
			pmap[make_pair(nn/d,nn%d)] = --que.end();
			nn = (nn%d)*10;
		}
			/*for(int i = 0; i < que.size(); i++)
				cout<<que[i];
			cout<<endl;
			*/
		list<long long>::iterator iter;
		if(nn != 0)
			iter = pmap[make_pair(nn/d,nn%d)];
		else
			iter = que.end();
		for(auto i = que.begin(); i != iter; i++)
			a.push_back('0'+*i);
		if(iter != que.end())
		{
			a.push_back('(');
			for(auto i = iter; i != que.end(); i++)
				a.push_back(*i+'0');
			a.push_back(')');
		}
	}
    
    string toString(long long a)
    {
    	string s("");
    	if(a == 0)
			s.push_back('0');
		else
		{
			long long mul = 1;
			while(a/(mul*10) != 0)
				mul *= 10;
			while(mul != 0)
			{
				s.push_back('0'+a/mul%10);
				mul /= 10;	
			} 
		}
		return s;
	}
};

int main()
{
	Solution so;
	cout<<so.fractionToDecimal(-1,-2147483648);
}
