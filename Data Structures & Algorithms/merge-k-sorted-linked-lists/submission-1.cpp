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
    bool exists(vector<ListNode*>& lists){
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                return true;
            }
        }
        return false;
    }

    int minList(vector<ListNode*>& lists){
        int n = lists.size();
        int mn = INT_MAX;
        int ans = -1;
        for(int i=0;i<n;i++){
            if(lists[i] && lists[i]->val<mn){
                mn=lists[i]->val;
                ans=i;
            }
        }
        return ans;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(true){
            int i = minList(lists);
            if(i==-1){
                break;
            }
            temp->next=lists[i];
            lists[i]=lists[i]->next;
            temp=temp->next;
        }

        return dummy->next;
    }
};
