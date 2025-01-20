
class Solution {
public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // Handle base cases
        if (head1 == NULL) return head2;
        if (head2 == NULL) return head1;
        
        Node* result = NULL;
        
        // Choose head of result list based on smaller first element
        if (head1->data <= head2->data) {
            result = head1;
            result->next = sortedMerge(head1->next, head2);
        } else {
            result = head2;
            result->next = sortedMerge(head1, head2->next);
        }
        
        return result;
    }
};
