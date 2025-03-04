class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)return false;
       if((int)pow(3,19)%n)return false;
       
        return true;
    }
};