/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        unordered_map<Node*,Node*> no;
        Node* curr=head;
        vector<Node*> nodelist;
        while(curr){
            Node* newNode = new Node(curr->val);
            no[curr] = newNode;
            nodelist.push_back(newNode);
            curr=curr->next;
        }
        curr=head;
        for(int i=0;i<nodelist.size();i++){
            Node* node = nodelist[i];
            node->next = i<nodelist.size()-1?nodelist[i+1]:NULL;
            node->random = no[curr->random];
            curr=curr->next;
        }
        return nodelist[0];
    }
};
