class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> count1;

        for(int i=0; i<nums1.size(); i++){
            count1[nums1[i]]++;
        }
        unordered_map<int,int> count2;

        for(int i=0; i<nums2.size(); i++){
            count2[nums2[i]]++;
        }
        vector<int> result;
        for(auto & pair:count1){
            if(count2[pair.first]>0){
                result.push_back(pair.first);
            }
        }
        return result;
    }
};