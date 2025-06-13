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
        if (head == nullptr) return nullptr;

        Node* newhead = new Node(head->val);
        unordered_map<Node*, Node*> mpp;
        Node* oldtemp = head->next;
        Node* newtemp = newhead;
        mpp[head] = newhead;

        while (oldtemp != nullptr) {
            Node* old = new Node(oldtemp->val);
            mpp[oldtemp] = old;

            newtemp->next = old;
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        oldtemp = head;
        newtemp = newhead;
        while (oldtemp != nullptr) {
            newtemp->random = mpp[oldtemp->random];
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        return newhead;
    }
};