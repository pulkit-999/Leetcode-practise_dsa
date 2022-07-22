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
    ListNode* merge(ListNode*h1,ListNode*h2)
    {
        ListNode*temp=new ListNode(0);
        ListNode*ans=temp;
        while(h1!=NULL && h2!=NULL )
        {
            if(h1->val<h2->val)
            {
                temp->next=h1;
                temp=temp->next;
                h1=h1->next;
            }
            else
            {
             temp->next=h2;
                temp=temp->next;
                h2=h2->next;
            }
        }   
        if(h1!=NULL)
        {
            temp->next=h1;
        }
        if(h2!=NULL)
        {
            temp->next=h2;
        }
        return ans->next;
        }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        
        int n=lists.size();
        if(n==0)
            return NULL;
        ListNode*head=lists[0];
        for(int i=1;i<n;i++)
        {
            head=merge(head,lists[i]);
        }
            return head;
    }
};