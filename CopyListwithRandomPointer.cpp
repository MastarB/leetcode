class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode* head) 
    {
        if(head == NULL)return NULL;
        map<int,RandomListNode*>tab;
        RandomListNode* h = new RandomListNode(head->label);
        tab[head->label] = h;
        RandomListNode* p = h;
        RandomListNode* q = head;
        while(q->next != NULL)
        {
        	p->next = new RandomListNode(q->next->label);
        	p = p->next;
        	tab[p->label] = p;
        	q = q->next;
		}
        p = h;
        q = head;
        while(q != NULL)
        {
        	if(q->random != NULL)
        		p->random = tab[q->random->label];
			p = p->next;
			q = q->next;
		}
		return h;
    }
};
