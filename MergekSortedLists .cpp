#include<vector>
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
    	if(lists.size()==0)return NULL; 
     while(lists.size() > 1)
	 {
		vector<ListNode*>listsNew;
    	int i;
        for(i = 0 ;i< lists.size()-1 ; i+=2)
        	listsNew.push_back(mergeTwoLists(lists[i],lists[i+1]));
        if(i == lists.size()-1)
        		listsNew.push_back(lists[i]);
		lists.clear();
		lists = listsNew;
	 }
    	return lists[0];
    	
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		 ListNode * ans = new ListNode(0);
		 ListNode * p = ans;
        while (l1!=NULL&&l2!=NULL)
        {
        	if(l1->val > l2->val)
        	{
        		ListNode * temp = new ListNode(l2->val);
        		p->next = temp;
        		ListNode * del = l2;
        		l2 = l2->next;
        		p = p->next;
        		delete del;
			}
			else
			{
				ListNode * temp = new ListNode(l1->val);
        		p->next = temp;
        		ListNode * del = l1;
        		l1 = l1->next;
        		p = p->next;	
        		delete del;
			}
		}
		while(l1!=NULL)
		{
			ListNode * temp = new ListNode(l1->val);
        		p->next = temp;
        		ListNode * del = l1;
        		l1 = l1->next;
        		p = p->next;
        		delete del;
		}
		while(l2!=NULL)
		{
			ListNode * temp = new ListNode(l2->val);
        		p->next = temp;
        		ListNode * del = l2;
        		l2 = l2->next;
        		p = p->next;
        		delete del;
		}
		ListNode * del = ans;
		ans = ans->next;
		delete del;
		return ans;
		
    }
};

int main()
{
	
}
