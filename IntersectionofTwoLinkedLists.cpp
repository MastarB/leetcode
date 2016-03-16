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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
	{
        int lenA = 0;
        int lenB = 0;
        ListNode* p;
		p = headA;
        while(p != NULL)
        {
        	lenA++;
        	p = p->next;
        }
        p = headB;
        while(p != NULL)
        {
            lenB++;
        	p = p->next;
	    }
        ListNode* p1 = headA;
		ListNode* p2 = headB;
	   	while(lenA > lenB)
    	{
    		p1 = p1->next;
    		lenA--;
		}
		
		while(lenA < lenB)
		{
			p2 = p2->next;
			lenB--;
		}
		while(p1 != NULL)
		{
			if(p1 == p2)return p1;
			else
			{
				p1 = p1->next;
				p2 = p2->next;
			}
		}
		return NULL;
    }
};
