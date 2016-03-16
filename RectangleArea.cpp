#include<iostream>
using namespace std;
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
	{
        return (C-A)*(D-B)+(G-E)*(H-F)-(!isOverlaped(A,B,C,D,E,F,G,H)?0:(min(C,G)- max(A,E)) * (min(D,H) - max(B,F)));
    }
    
    bool isOverlaped(int A, int B, int C,int D, int E, int F, int G, int H)
    {
    	return  min(C,G) > max(A,E) &&  max(B,F) < min(D,H);
	}
};

int main()
{
	Solution so;
}
