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
    ListNode* rotateRight(ListNode* head, int k) {
         if (!head || !head->next || k == 0) return head;

      ListNode* tail = head;
      int count = 1;

      while(tail->next!=nullptr){
        tail = tail->next;
        count++;
      }

       k=k%count;

      tail->next = head;

      ListNode* temp = head;
     for(int i=0;i<count-k-1;i++){
        temp = temp->next;
     }
      ListNode* ans = temp->next;
      temp->next = NULL;

      return ans;
      
    }
};