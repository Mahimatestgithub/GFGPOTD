class Node{
    public:
    vector<Node*>child;
    bool isend;
    Node(){
        child.resize(26,NULL);
        isend=false;
    }
};
class Trie{
  Node* root;
  public:
  Trie(){
      root=new Node();
  }
  void insert(string word){
      Node* temp=root;
      for(char c:word){
          int idx=c-'a';
          if(!temp->child[idx]){
              temp->child[idx]=new Node();
          }
          temp=temp->child[idx];
      }
      temp->isend=true;
  }
  bool check(string word){
      Node* temp=root;
      for(char c:word){
          int idx=c-'a';
          temp=temp->child[idx];
          if(!temp || !temp->isend) return false;
      }
      return true;
  }
};
class Solution {
  public:
    string longestString(vector<string> &arr) {
        // code here
        // could do using map but trie saves space
        // Time taken : 6mins
        Trie trie;
        for(auto it:arr){
            trie.insert(it);
        }
        string ans="";
        for(auto it:arr){
            if(trie.check(it)){
                if(ans=="" || it.length()>ans.length() || (it.length()==ans.length() && it<ans)){
                    ans=it;
                }
            }
        }
        return ans;
    }
};
