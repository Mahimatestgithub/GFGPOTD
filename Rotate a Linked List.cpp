class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // Edge case: if the list is empty or has only one node
        if (!head || !head->next || k == 0) return head;

        // Step 1: Compute the length of the linked list
        Node* current = head;
        int length = 1;
        while (current->next) {
            current = current->next;
            length++;
        }

        // Step 2: Update k to ensure it is within bounds
        k %= length;
        if (k == 0) return head;

        // Step 3: Make the list circular
        current->next = head;

        // Step 4: Find the new head
        int newHeadPos = k; // Position of the new head for left rotation
        Node* newTail = head;
        for (int i = 1; i < newHeadPos; i++) {
            newTail = newTail->next;
        }

        // Step 5: Break the circular list
        Node* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
