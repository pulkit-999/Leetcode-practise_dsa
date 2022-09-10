/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL|| head->next==NULL)
            return head;
        ListNode* ptr=new ListNode();
        ListNode* p=head; 
        ListNode* temp=ptr;
        while(p&& p->next!=NULL)
        {
          temp->next=p->next;
            p->next=temp->next->next;
             temp->next->next=p;
              temp=p;
            p=p->next;
        }
        
            return ptr->next;
    }
};