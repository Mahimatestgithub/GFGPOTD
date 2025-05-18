class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        vector<int> result;
        if (!root) return result;

        deque<Node*> dq;
        dq.push_back(root);
        bool leftToRight = false;

        while (!dq.empty()) {
            int levelSize = dq.size();
            vector<int> levelNodes(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                Node* curr = dq.front();
                dq.pop_front();

                // Place the value in reverse or normal order based on level
                int index = (leftToRight) ? i : (levelSize - 1 - i);
                levelNodes[index] = curr->data;

                if (curr->left)
                    dq.push_back(curr->left);
                if (curr->right)
                    dq.push_back(curr->right);
            }

            for (int val : levelNodes)
                result.push_back(val);

            // Toggle the direction for next level
            leftToRight = !leftToRight;
        }

        return result;
    }
};
