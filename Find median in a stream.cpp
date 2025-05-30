class Solution {
public ArrayList<Double> getMedian(int[] arr) {
       ArrayList<Double> list = new ArrayList<>();
        list.add((double)arr[0]);
       for(int i = 1;i<arr.length;i++) {
           int cur = arr[i];
           int prev = i-1;
           while(prev >= 0 && cur < arr[prev]) {
               arr[prev+1] = arr[prev];
               prev--;
           }
           arr[prev+1] = cur;
           
          
           int mid = (i+1)/2;
           if((i&1) == 0) {
               list.add((double)arr[mid]);
           }else {
               list.add((double)((arr[mid]+arr[mid-1])/2.0));
           }
           
       } 
       return list;
    }
}
