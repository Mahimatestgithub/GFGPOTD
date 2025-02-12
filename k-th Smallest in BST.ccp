
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Return the Kth smallest element in the given BST
 

void solve(Node* node, vector<int>&ans){
        if(!node) return;
        solve(node->left, ans);
        ans.push_back(node->data);
        solve(node->right, ans);
    }
    
    int kthSmallest(Node *root, int k) {
        // add code here.
        vector<int>ans;
        solve(root, ans);
        if(ans.size()>=k) return ans[k-1];
        else return -1;
    }
};
