class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0; i<n; i++){
            int k;
            for(int j=0; j<m; j++){
                if(nums1[i]==nums2[j])
                    k=j;
            }
            int count=0;
            for(int j=k; j<m; j++){
                if(nums2[j]>nums1[i]){
                    ans.push_back(nums2[j]);
                    count++;
                    break;
                }
            }
            if(count==0)
                ans.push_back(-1);
        }
        return ans;
    }
};