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
  void leftpart(Node*root, vector<int>&ans ){
        if(root==NULL||(root->left==NULL&&root->right==NULL)){
            return;
        }
     ans.push_back(root->data);
        if(root->left)
        leftpart(root->left,ans);
        else
          leftpart(root->right,ans);
        
    }
    void bottompart(Node*root, vector<int>&ans){
      if(root==NULL)
      return;
      if((root->left==NULL&&root->right==NULL))
      {
          ans.push_back(root->data);
          return ;
      }
        
      bottompart(root->left,ans);
      bottompart(root->right,ans);
        
        
        
    }
    void rightpart(Node*root, vector<int>&ans){
        
        if(root==NULL||(root->left==NULL&&root->right==NULL)){
            return;
        }
    
        if(root->right)
        rightpart(root->right,ans);
        else
          rightpart(root->left,ans);
          ans.push_back(root->data);
    }
    
    vector <int> boundaryTraversal(Node *root)
    {   
        vector<int>ans;
        if(root==NULL)
        return ans;
        ans.push_back(root->data);
        
        leftpart(root->left,ans);
        bottompart(root->left,ans);
        bottompart(root->right,ans);
        rightpart(root->right,ans);
        return ans;
    }
};
