class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
       
        vector<int> ans;
        
        for(int i=1; i<=100; i++){
            auto it1=find(nums1.begin(),nums1.end(),i);
            auto it2=find(nums2.begin(),nums2.end(),i);
            auto it3=find(nums3.begin(),nums3.end(),i);

            if((it1 != nums1.end() && it2 != nums2.end()) || (it1 != nums1.end() && it3 != nums3.end()) || (it2 != nums2.end() && it3 != nums3.end())) ans.push_back(i);
        }
        return ans;
    }
};