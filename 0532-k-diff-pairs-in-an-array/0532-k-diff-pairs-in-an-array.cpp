class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> count;
        int i=0,j=1;
        while(j<nums.size()){
            if(nums[j]-nums[i]==k && i<j){
                count[nums[i]]++;
                i++; j++;
            }
            else if(nums[j]-nums[i]>k){
               i++;
            }
            else
            j++;
        }
        return count.size();
    }
};