/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/


class Solution {
public:
    Node* cloneLinkedList(Node* head) { // Renamed to match the expected function name
        if (!head) return NULL; // If the list is empty, return NULL.
        
        // Step 1: Interleave the copied nodes with the original list.
        Node* curr = head;
        while (curr) {
            Node* temp = new Node(curr->data);  // Create a new node with the same data.
            temp->next = curr->next;            // Point the new node's next to curr's next.
            curr->next = temp;                  // Link the original node to the new node.
            curr = temp->next;                  // Move to the next original node.
        }
        
        // Step 2: Set the random pointers for the copied nodes.
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;  // Copy the random pointer.
            }
            curr = curr->next->next;  // Move to the next original node.
        }
        
        // Step 3: Separate the original and copied lists.
        curr = head;
        Node* copiedHead = head->next;
        Node* copiedCurr = copiedHead;
        while (curr) {
            curr->next = curr->next->next;  // Restore the original list.
            if (copiedCurr->next) {
                copiedCurr->next = copiedCurr->next->next;  // Link the copied list.
            }
            curr = curr->next;         // Move to the next original node.
            copiedCurr = copiedCurr->next;  // Move to the next copied node.
        }
        
        return copiedHead;  // Return the head of the copied list.
    }
};
