class Solution {
public:
    unordered_map<int, int> inorderMap; // To store indices of inorder elements
    int preIndex = 0; // To keep track of preorder index

    Node* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;
        
        int rootValue = preorder[preIndex++];
        Node* root = new Node(rootValue);
        
        int inorderIndex = inorderMap[rootValue];
        
        root->left = buildTreeHelper(preorder, inorder, inStart, inorderIndex - 1);
        root->right = buildTreeHelper(preorder, inorder, inorderIndex + 1, inEnd);
        
        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        inorderMap.clear();
        preIndex = 0;
        
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1);
    }

    void postorderTraversal(Node* root, vector<int>& result) {
        if (!root) return;
        postorderTraversal(root->left, result);
        postorderTraversal(root->right, result);
        result.push_back(root->data);
    }
};

// Utility function to print postorder traversal
void printPostorder(Node* root) {
    vector<int> result;
    Solution().postorderTraversal(root, result);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}
