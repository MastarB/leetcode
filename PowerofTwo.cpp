class Solution {
public:
    bool isPowerOfTwo(int n)
	{
		int i = n;
        if(i <= 0)return false;
        while((i&1) != 1)
        	i = i>>1;
        return i == 1;
    }
};

int main()
{
	Solution so;
	cout<<(so.isPowerOfTwo(2)?"true":"false");
}
