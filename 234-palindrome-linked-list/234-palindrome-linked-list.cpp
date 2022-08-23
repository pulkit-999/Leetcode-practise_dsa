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
    ListNode* reverse(ListNode* head)
    {
     ListNode*nex=head;
         ListNode*prev=NULL;
        while(head!=NULL)
        {
            nex=head->next;
            head->next=prev;
            prev=head;
            head=nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head;
         ListNode*fast=head;
        while(fast->next!=NULL &&fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode*dummy=head;
      slow->next= reverse(slow->next);
        slow=slow->next;
        while(slow!=NULL)
        {
            if(dummy->val!=slow->val)
            {
                return false;
            }
            dummy=dummy->next;
            slow=slow->next;
        }
        return true;
    }
};