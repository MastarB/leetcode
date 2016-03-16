#include<random>
#include<vector>
#include<iostream>
using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>index;
        for(int i = 0; i < nums.size(); i++)
        {
            index.push_back(i+1);
        }
        shuffle(nums,index);//shuffle the vector faciliating the upcoming quicksort
        sort(nums,index);//quicksort the vector
        int i = 0;
        int j = nums.size()-1;
        while(i<j)
        {
            if(nums[i] + nums[j] > target)
            j--;
            else if(nums[i] + nums[j] < target)
            i++;
            else 
            {
                vector<int>ans;
                if(index[i]>index[j])
                {
                    ans.push_back(index[j]);
                    ans.push_back(index[i]);
                }
                else
                {
                    ans.push_back(index[i]);
                    ans.push_back(index[j]);
                }
                
                return ans;
            }
        }
    }
        void shuffle(vector<int>&nums, vector<int>&index)
        {
            srand(52);
            for(int i = 0; i <nums.size(); i++)
            {
                int r =rand()%(i+1);
                swap(nums[i],nums[r]);
                swap(index[i],index[r]);
            }
        }
        
      void sort (vector<int>&nums, vector<int>&index)
      {
          quicksort(nums, index, 0, nums.size() -1 );
          for(int i = 0; i< nums.size(); i++)
          cout<<index[i]<<' ';
      }
      void quicksort(vector<int>&nums, vector<int>&index, int i, int j)
      {
          if(i<j)
          {
            int p = partition(nums,index,i,j);
           
            quicksort(nums,index,i,p-1);
            quicksort(nums,index,p+1,j);
          }
      }
      int partition(vector<int>&nums, vector<int>& index, int i, int j)
    {
           
          int a = i+1;
            int b = j;
            int p =nums[i];
            
           while(a <= b)
            {
                    if(nums[a] > p)
                    {
                        swap(nums[a],nums[b]);
                        swap(index[a],index[b]);
                        b--;
                    }
                    else a++;
            }
            swap(nums[i],nums[a-1]);
            swap(index[i],index[a-1]);
            return a-1;
            /*
            
            int a = i;
            int p = nums[j];
            for(int m = i ;m < j; m++)
            {
                if(nums[m] < p)
                {
                    swap(nums[m],nums[a]);
                    swap(index[m],index[a]);
                    a++;
                }
            }
            swap(nums[j],nums[a]);
            swap(index[j],index[a]);
            return a;
            */
    }
    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
};

int main()
{
	vector<int>test;
	test.push_back(-3);
	test.push_back(4);
	test.push_back(3);
	test.push_back(90);
	Solution a;
	vector<int>ans = a.twoSum(test,0);
	cout<<ans[0]<<' '<<ans[1];
	return 0;
	
}
