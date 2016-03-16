#include<iostream>
using namespace std;
struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
		ListNode* p = head;
    if(n >1)
    {
		
        for(int i =  1 ; i < n; i++)
        {
        	p = p->next;
		}
		
		ListNode* nthend = head;
		
		while(p->next != NULL)
		{
			p = p->next;
			nthend = nthend->next;
		}
		
		swap(nthend->val,nthend->next->val);
		ListNode* dele = nthend->next;
		nthend->next = dele->next;
		delete dele;
	}
	else  
	{
		if(p->next != NULL)
		{
			while(p->next->next != NULL)
				p = p->next;
			delete p->next;
			p->next =NULL;
		}
		else 
		{
			delete p;
			head = NULL;
		}
	}
		return head;
		
    }
};
int main()
{
}
