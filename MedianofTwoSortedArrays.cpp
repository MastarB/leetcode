#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
		vector<int>& n1 = nums1;
		vector<int>& n2 = nums2;
		bool swapped = false;
        int b1 = 0, e1 = nums1.size()-1;
        int b2 = 0, e2 = nums2.size()-1;
        int odd =(e1+e2)%2;
        if(e1-b1<0)
        {
        	return (odd)?n2[(b2+e2)/2]:(n2[(b2+e2)/2+1]+n2[(b2+e2)/2])/2.0;
		}
		if(e2 -b2 <0)
		{
				return (odd)?n1[(b1+e1)/2]: (n1[(b1+e1)/2]+n1[(b1+e1)/2+1])/2.0;
		}
        if(e1 < e2)
		{
			swap(e1,e2);
			return find(n2,n1,b1,e1,b2,e2,odd);
    	}
    
    	return find(n1,n2,b1,e1,b2,e2,odd);
    }
    double find(vector<int>& n1,vector<int>& n2, int b1, int e1, int b2, int e2, int odd)
    {
    	if(e1-b1 == 0)
			return (n1[b1]+n2[b2])/2.0;
    	else if(e1-b1 == 1)
    	{
    		if(e2-b2 == 0)
    		{
    			if(n2[b2] > n1[e1])return n1[e1];
    			else if(n2[b2] > n1[b1]) return n2[b2];
    			else return n1[b1];
			}
			else
			{
				if(n2[e2]>=n1[e1])
				{
					if(n2[b2]>=n1[b1])
						return (n2[b2]+n1[e1])/2.0;
					else
						return (n1[b1]+n1[e1])/2.0;
				}
				else
				{
				  if(n1[b1]>n2[b2])
				  	return (n2[e2]+n1[b1])/2.0;
				  	else
				  	return (n2[e2]+n2[b2])/2.0;
				
				}
			}	
		}
    	else if(e2-b2 == 0)
    	{
    		if(odd)
    		{
    			int j = (b1+e1)/2;
    			int k = (b1+e1)/2+1;
    			if(n2[b2] > n1[k])return n1[k];
    			else if(n2[b2] > n1[j]) return n2[b2];
    			else return n1[j];
			}
			else
			{
				int m = (b1+e1)/2;
				if(n2[b2] > n1[m+1])return (n1[m]+n1[m+1])/2.0;
				else if(n2[b2] > n1[m-1])return (n1[m]+n2[b2])/2.0;
				else return (n1[m]+n1[m-1])/2.0; 	
			}
		}
		else if(e2-b2==1)
		{
			if(odd)
			{
				int m = (e1+b1)/2;
				if(n2[b2]>=n1[m])
				{
					if(n2[b2] >= n1[m+1])return n1[m+1];
					else return n2[b2];
					
				}
				else if(n2[b2]>=n1[m-1])
				{
					if(n2[e2]>=n1[m])return n1[m];
					else return n2[e2];
				}
				else
				{
					if(n2[e2]>=n1[m])return n1[m];
					else if(n2[e2]>=n1[m-1])return n2[e2];
					else return n1[m-1];
				}
			}
			else
			{
				
				int j = (e1+b1)/2;
				int k = (e1+b1)/2+1;
				if(n2[e2]<n1[j-1])return (n1[j-1]+n1[j])/2.0;
				else if(n2[e2]<n1[j])return (n1[j]+n2[e2])/2.0;
				else if(n2[e2]<n1[k])
				{
					if(n2[b2]<n1[j])return (n1[j]+n2[e2])/2.0;
					else return (n2[b2]+n2[e2])/2.0;
				}
				else if(n2[e2]<n1[k+1])
				{
					if(n2[b2]<n1[j])return (n1[j]+n1[k])/2.0;
					else return (n2[b2]+n1[k])/2.0;		
				}
				else
				{
					if(n2[b2]<n1[j])return (n1[j]+n1[k])/2.0;
					else if(n2[b2]<n1[k+1])return (n2[b2]+n1[k])/2.0;
					else return (n1[k]+n1[k+1])/2.0;
				}			
			}
		}
    	
if((e1-b1)%2==0)
{
    if((e2-b2)%2==0)
    {
		int m1 = (b1 + e1)/2;
    	int m2 = (b2 + e2)/2; 
    	if(n1[m1]>n2[m2])
    	{
    		int m = min(e1 - m1,m2 - b2);
    		 return find(n1,n2,b1,e1-m,b2+m,e2,odd);
		}
		else
		{
			int m = min(e2 - m2,m1 - b1);
			return find(n1,n2,b1+m,e1,b2,e2-m,odd);
		}
	}
	else
	{
	
		
		int j2 = (b2+e2)/2;
		int k2 = (j2+1);
		int m1 = (b1 + e1)/2;
	
		if(n1[m1]>n2[k2])
		{
			int m =min(j2-b2,e1-m1);
			return find(n1,n2,b1,e1-m,b2+m,e2,odd);
		}
		else if(n1[m1]>n2[j2])return n1[m1];
		else
		{
			
			int m =min(e2-k2,m1-b1);
			return find(n1,n2,b1+m,e1,b2,e2-m,odd);
		}	
	}	
}
else
{
	if((e2-b2)%2==0)
	{
		
			
		int j1 = (b1+e1)/2;
		int k1 = (j1+1);
		int m2 = (b2 + e2)/2;
		if(n2[m2]>=n1[k1])
		{
			int m =min(j1-b1,e2-m2);
			return find(n1,n2,b1+m,e1,b2,e2-m,odd);
		}
		else if(n2[m2]>=n1[j1])return n2[m2];
		else
		{
			int m =min(e1-k1,m2-b2);
			return find(n1,n2,b1,e1-m,b2+m,e2,odd);
		}	
	}
	else
	{
		int j1 = (b1+e1)/2;
		int k1 = (j1+1);
		int j2 = (b2+e2)/2;
		int k2 = (j2+1);
		if(n1[j1] <= n2[j2]&& n1[k1] > n2[k2])
		return (n2[j2]+n2[k2])/2.0;
		else if(n2[j2] < n1[j1]&& n2[k2] >= n1[k1] )
		return (n1[j1]+n1[k1])/2.0;
		else if(n1[k1] > n2[k2] && n2[k2] >= n1[j1] && n1[j1] > n2[j2])return (n2[k2]+n1[j1])/2.0;
		else if(n2[k2] >= n1[k1] && n1[k1] > n2[j2] && n2[j2] >= n1[j1]) return  (n1[k1]+n2[j2])/2.0;
		else
		{
			 if(n1[j1]>n2[k2])
			 {
			 	int m = min(e1-k1,j2-b2);
			 	return find(n1,n2,b1,e1-m,b2+m,e2,odd);
			 }
			 else
			 {
			 	int m = min(j1-b1,e2-k2);
			 	return find(n1,n2,b1+m,e1,b2,e2-m,odd);
			 }
		}
		
	}
}
}
};

int main()
{
	int a[] ={1,5,7,8};
	int b[] ={2,3,4,6};
	vector<int>aa;
	for(int i = 0; i < 4; i++)
	aa.push_back(a[i]);
	vector<int>bb;
	for(int i = 0; i < 4; i++)
	bb.push_back(b[i]); 
	Solution s;
	cout<<s.findMedianSortedArrays(aa,bb);
}
