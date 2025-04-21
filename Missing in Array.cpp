int missingNum(int *arr, int size) {
    int result = 0;
    
    // XOR all numbers from 1 to size+1
    for (int i = 1; i <= size + 1; i++) {
        result ^= i;
    }
    
    // XOR with all array elements
    for (int i = 0; i < size; i++) {
        result ^= arr[i];
    }
    
    return result;
}
