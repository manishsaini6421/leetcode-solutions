class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v1;
        vector<int> v2;
        vector<int> v;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==pivot)v.push_back(nums[i]);
            else if(nums[i]<pivot)v1.push_back(nums[i]);
            else v2.push_back(nums[i]);
        }
        for(auto num:v){
            v1.push_back(num);
        }
        for(auto num:v2){
            v1.push_back(num);
        }
        return v1;
    }
};