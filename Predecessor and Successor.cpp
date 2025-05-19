class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        Node* curr = root;
        
        // Step 1: Search for the node with key while updating pre and suc
        while (curr != NULL) {
            if (curr->data < key) {
                pre = curr;
                curr = curr->right;
            } else if (curr->data > key) {
                suc = curr;
                curr = curr->left;
            } else {
                break; // key found
            }
        }
        
        // Step 2: If node is found, check for predecessor in left subtree
        if (curr != NULL) {
            if (curr->left) {
                Node* temp = curr->left;
                while (temp->right)
                    temp = temp->right;
                pre = temp;
            }
            
            // Step 3: Check for successor in right subtree
            if (curr->right) {
                Node* temp = curr->right;
                while (temp->left)
                    temp = temp->left;
                suc = temp;
            }
        }
        
        return {pre, suc};
    }
};
