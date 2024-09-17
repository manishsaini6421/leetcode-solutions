class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int ,int> count1;

        for(int i=0; i<nums1.size(); i++){
            count1[nums1[i]]++;
        }
        unordered_map<int ,int> count2;

        for(int i=0; i<nums2.size(); i++){
            count2[nums2[i]]++;
        }
        vector<int> res1;
        for(auto& pair:count1){
            if(count2[pair.first]==0){
                res1.push_back(pair.first);
            }
        }
        vector<int> res2;
        for(auto& pair:count2){
            if(count1[pair.first]==0){
                res2.push_back(pair.first);
            }
        }
        vector<vector<int>> result;
        result.push_back(res1); 
        result.push_back(res2); 

        return result;

    }
};