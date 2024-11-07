class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
       unordered_map<int,int> map;

        int count=0;
        int ans;
        for(auto num:nums){
            map[num]++;
            if(map[num]>count){
                count=map[num];
                ans=num;
            }
        }
        return ans;
    }
};