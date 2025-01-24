/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        Node* slow = head;
        Node* fast = head;
        
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            // If slow and fast meet at some point, then there is a loop
            if (slow == fast)
            {
                return true;
            }
        }
        
        // If we reach here, it means there is no loop
        return false;
    }
};

/*Visual Representation:
rust
Copy code
1 -> 2 -> 3 -> 4 -> 5
     ^              |
     |              |
     ----------------
Iteration 1:
slow at 2
fast at 3
Iteration 2:
slow at 3
fast at 5
Iteration 3:
slow at 4
fast at 3
Iteration 4:
slow at 5
fast at 5 (meet point)
Explanation:
In the third iteration, the fast pointer moves two steps from node 5 to node 2 (loop back) and then to node 3.
In the fourth iteration, the fast pointer moves two steps from node 3 to node 4 to node 5.8*/
