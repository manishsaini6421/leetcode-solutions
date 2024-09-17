class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int> count;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){
                count[nums[i][j]]++;
            }
        }
        vector<int> result;
        for(auto& pair:count){
            if(pair.second==nums.size()){
                         result.push_back(pair.first);
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};