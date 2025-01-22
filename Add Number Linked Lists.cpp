class Solution {
    Node* reverseList(Node* head)
    {
        if(head == NULL)
            return NULL;
            
        Node* prev = NULL;
        Node* forward = NULL;
        Node* curr = head;
        
        while(curr != NULL)
        {
            forward = curr -> next;
            
            curr -> next = prev;
            
            prev = curr;
            
            curr = forward;
        }
        
        return prev;
    }
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        
        Node* head1 = reverseList(num1);
        Node* head2 = reverseList(num2);
        
        int carry = 0;
        
        Node* dummy = new Node(-1);
        Node* head = dummy;
        
        while(head1 && head2)
        {
            int val1 = head1 -> data;
            int val2 = head2 -> data;
            
            int sum = val1 + val2 + carry;
            
            carry = sum / 10;
            
            int num = sum % 10;
            
            Node* temp = new Node(num);
            
            dummy -> next = temp;
            
            dummy = temp;
            
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        
        while(head1)
        {
            int val1 = head1 -> data;
            
            int sum = val1 + carry;
            
            carry = sum / 10;
            
            int num = sum % 10;
            
            Node* temp = new Node(num);
            
            dummy -> next = temp;
            
            dummy = temp;
            
            head1 = head1 -> next;
        }
        
        while(head2)
        {
            int val2 = head2 -> data;
            
            int sum = val2 + carry;
            
            carry = sum / 10;
            
            int num = sum % 10;
            
            Node* temp = new Node(num);
            
            dummy -> next = temp;
            
            dummy = temp;
            
            head2 = head2 -> next;
        }
        
        if(carry != 0)
        {
            Node* temp = new Node(carry);
            
            dummy -> next = temp;
            
            dummy = temp;
        }
        
        head = head -> next;
        
        Node* newHead = reverseList(head);
        
        while(newHead -> data == 0)
        {
            newHead = newHead -> next;
        }
        
        return newHead;
    }
};
