class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data);

        // Case 1: List is empty
        if (head == NULL) {
            newNode->next = newNode;
            return newNode;
        }

        Node* current = head;

        // Case 2: Insert before head (either smaller than head or largest value wrapping around)
        if (data <= head->data) {
            // Find the last node to fix circular reference
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
            return newNode; // new node becomes new head
        }

        // Case 3: Insert somewhere after head
        current = head;
        while (current->next != head && current->next->data < data) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        return head;
    }
};
