// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
 Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        if(root == NULL || root == n1 || root == n2){
            return root;
        }
        Node* l = LCA(root->left,n1,n2);
        Node* r = LCA(root->right,n1,n2);
        
        if(l == NULL){
            return r;
        }
        if(r == NULL){
            return l;
        }
        
        return root;
        
    }
};
