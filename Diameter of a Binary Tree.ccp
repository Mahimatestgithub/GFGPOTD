class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:

    int solve(Node* node,int &d){
        if(!node)
        return 0;
        
        int l=solve(node->left,d);
        int r=solve(node->right,d);
        
        d=max(d,l+r+1);
        
        return 1 + max(l,r);
    }
    int diameter(Node* root) {
        int d=0;
        solve(root,d);
        
        return d-1;
        
    }
};
