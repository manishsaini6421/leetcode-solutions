class Solution {
public:
    
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
          unordered_map<int,int> m;
          long long valid=0;
        for(int i=0; i<n; i++){
            valid+=m[nums[i]-i];//new came difference will pair with all stored in map with same
            m[nums[i]-i]++;
        }
         
        long long total=n*(n-1)/2;

        return total - valid;

    }
};