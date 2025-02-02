class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n);
        for(int i=0; i<n; i++){
            temp[i]=nums[i];
        }
        sort(nums.begin(),nums.end());
        int i=0;
        while(temp[0]!=nums[i]){
            i++;
        }
        for(int j=0; j<n; j++){
            if(temp[j]!=nums[i%n])return false;
            i++;
        }
        return true;
    }
};