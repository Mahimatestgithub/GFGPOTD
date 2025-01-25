class Solution {
public:
    Node* findFirstNode(Node* head) {
        if (!head || !head->next) return NULL; // No loop possible in an empty or single-node list

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect if a loop exists using Floyd's Cycle Detection
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { // Loop detected
                break;
            }
        }

        // If no loop exists
        if (!fast || !fast->next) return NULL;

        // Step 2: Find the first node of the loop
        slow = head; // Reset `slow` to the head
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // `slow` is now pointing to the first node of the loop
    }
};
