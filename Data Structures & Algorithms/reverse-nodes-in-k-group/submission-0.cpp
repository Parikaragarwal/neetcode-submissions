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
private:
pair<ListNode*,ListNode*> reverseList(ListNode* head) {
        if(!head || !head->next){
            return {head,head};
        }

        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return {prev,head};    
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* curr = dummy;

        while(curr && curr->next){
            ListNode* temp=curr;
            int count=0;
            while(temp->next && count<k){
                count++;
                temp=temp->next;
            }
            if(count<k){
                return dummy->next;
            }
            ListNode* nxt = temp->next;
            temp->next=NULL;
            auto ans = reverseList(curr->next);
            curr->next=ans.first;
            ans.second->next = nxt;
            curr=ans.second;
        }
        return dummy->next;
    }
};
