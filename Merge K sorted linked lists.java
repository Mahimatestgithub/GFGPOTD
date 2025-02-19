class Solution {
    // Function to merge K sorted linked list.
    Node mergeKLists(List<Node> arr) {
        int i = 0;
        int last = arr.size() - 1;
        int j;
        while(last != 0){
            i = 0;
            j = last;
            while(i < j){
                arr.set(i, merge(arr.get(i), arr.get(j)));
                i++;
                j--;
                if(i >= j){
                    last = j;
                }
            }
        }
        return arr.get(0);
    }
    
    Node merge(Node a, Node b){
        if(a == null) return b;
        if(b == null) return a;
        Node result;
        if(a.data <= b.data){
            result = a;
            result.next = merge(a.next, b);
        }
        else{
            result = b;
            result.next = merge(a, b.next);
        }
        return result;
    }
}
