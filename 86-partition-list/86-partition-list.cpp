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
    
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* left=new  ListNode(0);
         ListNode* right=new  ListNode(0);
         ListNode* ans=left;
        ListNode*rightstarting=right;
        while(head!=NULL)
        {
            if(head->val<x)
            {
                left->next=head;
                left=left->next;
                head=head->next;
                left->next=NULL;
            }
            else
            {
                right->next=head;
                right=right->next;
                head=head->next;
                right->next=NULL;
            }
        }
       left->next=rightstarting->next;
        return ans->next;
    }
    
};