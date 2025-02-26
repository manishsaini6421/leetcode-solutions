class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto num:nums){
            map[num]++;

        }
        vector<int> ans;
        for(auto pair:map){
            if(pair.second==1){
                if(map.find(pair.first-1)==map.end() && map.find(pair.first+1)==map.end())ans.push_back(pair.first);
            }
        }
        return ans;
    }
};