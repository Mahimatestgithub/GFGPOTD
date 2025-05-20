class Solution {
  public:
    void markParents(Node* root, unordered_map<Node*, Node*>& parentTrack, Node* &targetNode, int target) {
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            if (current->data == target) {
                targetNode = current;
            }
            if (current->left) {
                parentTrack[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parentTrack[current->right] = current;
                q.push(current->right);
            }
        }
    }
    
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parentTrack;
        Node* targetNode = nullptr;
        markParents(root, parentTrack, targetNode, target);
        
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        
        int time = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool flag = false; // to check if fire spreads in this second
            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();
                
                // Check left child
                if (current->left && !visited[current->left]) {
                    flag = true;
                    visited[current->left] = true;
                    q.push(current->left);
                }
                
                // Check right child
                if (current->right && !visited[current->right]) {
                    flag = true;
                    visited[current->right] = true;
                    q.push(current->right);
                }
                
                // Check parent
                if (parentTrack[current] && !visited[parentTrack[current]]) {
                    flag = true;
                    visited[parentTrack[current]] = true;
                    q.push(parentTrack[current]);
                }
            }
            if (flag) time++;
        }
        
        return time;
    }
};
