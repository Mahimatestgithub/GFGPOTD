class Solution {
  public:
    
    int countNodes(Node* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    bool isComplete(Node* root, int index, int node_count) {
        if (!root) return true;
        if (index >= node_count) return false;
        
        return isComplete(root->left, 2*index + 1, node_count) &&
               isComplete(root->right, 2*index + 2, node_count);
    }
    
    bool isHeapUtil(Node* root) {
        if (!root->left && !root->right)
            return true;
        
        if (!root->right) {
            // Only left child exists
            return (root->data >= root->left->data) && isHeapUtil(root->left);
        }
        else {
            // Both children exist
            if (root->data >= root->left->data && root->data >= root->right->data)
                return isHeapUtil(root->left) && isHeapUtil(root->right);
            else
                return false;
        }
    }
    
    bool isHeap(Node* tree) {
        int node_count = countNodes(tree);
        int index = 0;
        
        if (isComplete(tree, index, node_count) && isHeapUtil(tree))
            return true;
        
        return false;
    }
};
