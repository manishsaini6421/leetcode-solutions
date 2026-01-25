class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int x=0;
        vector<int> res(2,0);
        for(int num:nums){
            x^=num;
        }
        
        unsigned int temp=x& (-x);
        for(int num:nums){
            if(temp&num)res[1]^=num;
            else res[0]^=num;
        }
        return res;

    }
};