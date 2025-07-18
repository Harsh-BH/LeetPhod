class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect left half from mid
        if (prev) prev->next = nullptr;

        // Make mid the root
        TreeNode* root = new TreeNode(slow->val);

        // Recur for left and right halves
        root->left = sortedListToBST(prev ? head : nullptr);  // Only if left exists
        root->right = sortedListToBST(slow->next);

        return root;
    }
};
