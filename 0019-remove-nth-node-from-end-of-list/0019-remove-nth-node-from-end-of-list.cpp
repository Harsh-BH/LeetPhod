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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tail = head;
        int count = 1;
        while(tail->next!=nullptr){
            tail = tail->next;
            count++;

        }
        ListNode* temp = head;;
        for(int i=0;i<(count-n-1);i++){
            temp = temp->next;
        }

        if((count-n-1)<0){
           head = temp->next;
           return head;
        }
        
        if(temp->next->next==nullptr){
            temp->next  =nullptr;
        }else{
            temp->next = temp->next->next;

        }

        return head;

    }
};