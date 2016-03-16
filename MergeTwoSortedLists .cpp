/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include<iostream>
 using namespace std;
class Solution 
{
public:
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
        		l2 = l2->next;
        		p = p->next;
			}
			else
			{
				ListNode * temp = new ListNode(l1->val);
        		p->next = temp;
        		l1 = l1->next;
        		p = p->next;	
			}
		}
		while(l1!=NULL)
		{
			ListNode * temp = new ListNode(l1->val);
        		p->next = temp;
        		l1 = l1->next;
        		p = p->next;
		}
		while(l2!=NULL)
		{
			ListNode * temp = new ListNode(l2->val);
        		p->next = temp;
        		l2 = l2->next;
        		p = p->next;
		}
		ans = ans->next;
		return ans;
		
    }
};
