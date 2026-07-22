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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1=reverseList(l1);
        // l2=reverseList(l2);
        // if(l1->next==NULL && l2->next==NULL && l1->val==9 && l2->val==9){
        //     ListNode* ans = new ListNode(8);
        //     ans->next = new ListNode(1);
        //     return ans;
        // }

        int carry=0;
        ListNode *dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(l1 || l2 || carry){
            int a=0;
            int b=0;

           if(l1){
            a=l1->val;
            l1=l1->next;
           }
           
           if(l2){
            b=l2->val;
            l2=l2->next;
           }

           int sum = a+b+carry;
           temp->next = new ListNode(sum%10);
           carry=sum/10;
           temp=temp->next;
        }

        return (dummy->next);
    }
};
