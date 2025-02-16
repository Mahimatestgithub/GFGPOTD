struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution
{
public:
    
    const int empty = -1;
    
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        vector<int> arr;
        serializeHelper(root, arr);
        return arr;
    }
    
    //Function to deserialize a list and construct the tree.
    Node* deSerialize(vector<int> &data) {
        int index = 0;
        return deserializeHelper(data, index);
    }
    
private:
    void serializeHelper(Node *root, vector<int> &arr) {
        if (root == NULL) {
            arr.push_back(empty);
            return;
        }
        arr.push_back(root->data);
        serializeHelper(root->left, arr);
        serializeHelper(root->right, arr);
    }

    Node* deserializeHelper(vector<int> &data, int &index) {
        if (index >= data.size() || data[index] == empty) {
            index++;
            return NULL;
        }

        Node *root = new Node(data[index]);
        index++;
        root->left = deserializeHelper(data, index);
        root->right = deserializeHelper(data, index);

        return root;
    }
};
