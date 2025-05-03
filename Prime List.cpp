/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
    vector<bool> sieve(int maxVal) {
        vector<bool> isPrime(maxVal + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= maxVal; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxVal; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    Node* primeList(Node* head) {
        const int MAX_VAL = 20000;
        vector<bool> isPrime = sieve(MAX_VAL);

        // Precompute nearest primes for 1 to 10000
        vector<int> nearestPrime(10001, 0);
        for (int i = 1; i <= 10000; ++i) {
            int offset = 0;
            while (true) {
                if ((i - offset >= 2 && isPrime[i - offset]) ||
                    (i + offset <= MAX_VAL && isPrime[i + offset])) {
                    if (i - offset >= 2 && isPrime[i - offset]) {
                        nearestPrime[i] = i - offset;
                    }
                    if (i + offset <= MAX_VAL && isPrime[i + offset]) {
                        if (nearestPrime[i] == 0 || (abs(i - (i + offset)) == abs(i - nearestPrime[i]) && (i + offset) < nearestPrime[i])) {
                            nearestPrime[i] = i + offset;
                        }
                    }
                    break;
                }
                ++offset;
            }
        }

        Node* curr = head;
        while (curr) {
            curr->val = nearestPrime[curr->val];
            curr = curr->next;
        }

        return head;
    }
};
