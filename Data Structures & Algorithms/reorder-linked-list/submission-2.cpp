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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }

        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;    

    }
public:
    void reorderList(ListNode* head) {

        if(!head || !head->next){
            return;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next=head;

        ListNode* slow=dummy;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* list2=slow->next;
        slow->next=NULL;
        ListNode* list1=head;
        list2=reverseList(list2);

        bool first=true;
        ListNode* curr=dummy;
        while(list1 && list2){
            if(first){
                curr->next=list1;
                list1=list1->next;
            }else{
                curr->next=list2;
                list2=list2->next;
            }
            curr=curr->next;
            first=!first;
        }
        if(list2){
            curr->next=list2;
        }
        head=dummy->next;
        // return dummy->next;
    }
};
