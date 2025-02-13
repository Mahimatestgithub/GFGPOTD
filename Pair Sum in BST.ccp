Node is as follows
class Node {
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
    unordered_map<int,int>mp;
    
    bool findTarget(Node *root, int target) {
        // your code here.
        if(!root) return false;
        int val=root->data;
        if(mp.find(target-val)!=mp.end()) return true;
        
        mp[val]++;
        
        if(target<=val) return findTarget(root->left,target);
        
        return findTarget(root->left,target) || findTarget(root->right,target);
    }
};
