#include<climits>
class Solution {
public:
    int reverse(int n) {
        long long int res = 0;
        while(n != 0) {
            res = res * 10 + (n % 10);
            n = n / 10;
        }
        if (res > INT_MAX || res < INT_MIN) {
            return 0;
        }
        return res; 
    }
};