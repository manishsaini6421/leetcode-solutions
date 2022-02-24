class Solution {
public:
    int singleNumber(vector<int>& nums) {
       map<int,int> m;
        int ans;
    for(int i=0; i<nums.size(); i++){
        m[nums[i]]=m[nums[i]]+1;
    }
        for(auto x:m){
            if(x.second==1){
                ans =x.first;
            }
        }
        return ans;
    }
};