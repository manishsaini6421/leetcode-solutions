class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        if(n==pow(2,30))return true;
        if(n<INT_MAX/2 && (n | n-1) == n*2-1)return true;
        return false;
    }
};