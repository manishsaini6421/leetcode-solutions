class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> map;
        for(auto num:nums){
            map[num]++;
        }
        for(auto pair:map){
            if(pair.second%2)return false;
        }
        return true;
    }
};