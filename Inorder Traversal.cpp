class Solution {
  public:
   void fun(Node* root,vector<int> &ans){
        if(root==NULL)
            return;
        fun(root->left,ans);
        ans.push_back(root->data);    
        fun(root->right,ans);
        return;
    }
    
    
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        fun(root,ans);
        return ans;
        
    }
};
