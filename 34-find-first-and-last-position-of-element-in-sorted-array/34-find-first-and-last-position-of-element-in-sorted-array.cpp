class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        vector<int> v;
       while(i<=j){
              if(target==nums[i] && target==nums[j]){
            v.push_back(i);
            v.push_back(j);
            return v;
        }
        if(target > nums[i]){
            i++;
        }
        if(target<nums[j]){
            j--;
        }
     
           }
        v.push_back(-1);
        v.push_back(-1);
        return v;
    }
};