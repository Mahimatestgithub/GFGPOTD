/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to find the height of a binary tree.
   int height(Node* node) {
        if(node==NULL)
        return -1;
        int x=height(node->left);
        int y=height(node->right);
        return max(x,y)+1;
    }
};
