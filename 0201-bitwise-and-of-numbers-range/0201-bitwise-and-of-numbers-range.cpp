class Solution {
public:
    
    int rangeBitwiseAnd(int left, int right) {
       
        int ans=right;
        
        while(ans>left){
            ans=(ans&ans-1);
        }
        return ans;
    }
};