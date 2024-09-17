class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> count;
         int result=0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if((nums[j]-nums[i]==k) && (count[nums[i]]==0)){
                result++;
                count[nums[i]]++;
               }
            }
        }
        
    
        return result;
    }
};