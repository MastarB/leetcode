class Solution {
public:
    int hammingWeight(uint32_t n) 
	{
        int k = 0;
        for(int i = 0; i < 32; i++,n >>= 1)
        	k += n&1;
        return k;
    }
};
