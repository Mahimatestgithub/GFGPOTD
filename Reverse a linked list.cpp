class Solution {
  public:
    Node* reverseList(struct Node* head) {
         // code here
        Node* prev = NULL; // Initialize previous node as NULL
        Node* curr = head; // Start with the head node
        Node* next = NULL; // Temporary pointer to hold next node
        
        while (curr != NULL) {
            next = curr->next; // Save the next node
            curr->next = prev; // Reverse the current node's pointer
            prev = curr;       // Move the previous pointer forward
            curr = next;       // Move to the next node
        }
        
        return prev; // New head of the reversed list
    }
};
