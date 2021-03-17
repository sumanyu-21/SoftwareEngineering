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
/*class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        int n = 0;
        ListNode *node = head;
        while(node!=NULL)
        {
            node = node->next;
            n++;
        }
        //cout<<size<<endl;
        
        // Find kth element and n-k+1 elements from begining;
        ListNode* first = head;
        ListNode* second = head;
        int i = 1;
        while(i<k)
        {
            first = first->next;
            i++;
        }
        
        i = 1;
        while(i<n-k+1)
        {
            second = second->next;
            i++;
        }
        swap(first->val, second->val);
        return head;
        
    }
};*/

class Solution
{
    public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        auto B = head;
        for(int i=1;i<k;i++)
            B = B->next;
        
        //cout<<node->val<<endl;
        auto A = head;
        auto first = B;
        while(B->next!=NULL)
        {
            B = B->next;
            A = A->next;
        }
        auto second = A;
        
        swap(first->val, second->val);
        return head;
    
    }
};