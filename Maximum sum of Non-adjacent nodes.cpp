// User function Template for Java
/*class Node
{
    int data;
    Node left, right;

    Node(int data)
    {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}*/

class Solution {
    
    // Helper function that returns an array where
    // arr[0] -> max sum when not including current node
    // arr[1] -> max sum when including current node
    private int[] solve(Node node) {
        if (node == null) {
            return new int[]{0, 0};
        }
        
        int[] left = solve(node.left);
        int[] right = solve(node.right);
        
        int include = node.data + left[0] + right[0];
        int exclude = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
        
        return new int[]{exclude, include};
    }
    
    // Main function
    public int getMaxSum(Node root) {
        int[] ans = solve(root);
        return Math.max(ans[0], ans[1]);
    }
}
