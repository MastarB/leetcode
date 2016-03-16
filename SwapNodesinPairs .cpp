/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode*p = head;
        if(p == NULL)return head;
        ListNode*f;
        if(p->next !=NULL)
        {
        	head = p->next;
        	ListNode* tem = p->next->next;
        	p->next->next = p;
        	p->next = tem;
        	f = p;
        	p = p->next;
		}
		
        while(p!=NULL&&p->next !=NULL)
        {
        	f->next =p->next;
        	ListNode* tem = p->next->next;
        	p->next->next = p;
        	p->next = tem;
        	f = p;
        	p = p->next;
		}
		return head;
    }
};
