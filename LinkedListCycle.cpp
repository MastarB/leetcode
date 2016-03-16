class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        if(head->next == head) return true;
        ListNode *fakeHead = new ListNode(0);
        ListNode* prev = fakeHead;
        ListNode* cur = head;
        ListNode* tmp;
        // Reverse linked list, if it has cycle, it will end up in the beginning
        while(cur != NULL) {
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        bool res = (prev == fakeHead);
        // Recover linked list
        cur = prev->next;
        prev->next = NULL;
        while(cur != NULL) {
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return res;
    }
};

