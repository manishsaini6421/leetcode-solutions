class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int count=1,num=nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]==num)count++;
            else if(nums[i]!=num && count>0)count--;
            else{
                num=nums[i];
                count=1;
            }
        }
        count=0;
        
        for(int i=0; i<n; i++){
            if(nums[i]==num)count++;
        }

        int freq=0;

        for(int i=0; i<n; i++){
            if(nums[i]==num)freq++;
            if(freq>(i+1)/2 && count-freq>(n-i-1)/2)return i;
        }
        return -1;
    }
};