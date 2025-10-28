class Solution {
public:
    // bool check(vector<int>& nums) {
    //     for (auto num : nums) {
    //         if (num)
    //             return false;
    //     }
    //     return true;
    // }
    // int countValidSelections(vector<int>& nums) {
    //     int n = nums.size();
    //     int ans = 0;
    //     for (int i = 0; i < n; i++) {
    //         if (nums[i] == 0) {
    //             int curr = i;
    //             int dir = -1;
    //             vector<int> temp = nums;
    //             while (curr >= 0 && curr < n) {

    //                 if (temp[curr] > 0) {
    //                     temp[curr]--;
    //                     dir = -dir;
    //                 }
    //                 curr += dir;
    //             }
    //             if (check(temp)) {
    //                 ans++;
    //             }

    //             // right
    //             curr = i;
    //             temp = nums;
    //             dir = 1;
    //             while (curr >= 0 && curr < n) {

    //                 if (temp[curr] > 0) {
    //                     temp[curr]--;
    //                     dir = -dir;
    //                 }
    //                 curr += dir;
    //             }
    //             if (check(temp))
    //                 ans++;
    //         }
    //     }
    //     return ans;
    // }


    //Optimized
    // int countValidSelections(vector<int>& nums) {
    //     int n=nums.size();
    //     int count=0,ans=0;
    //     for(int num:nums){
    //         if(num)count++;
    //     }
    //     for(int i=0; i<n; i++){
    //         if(nums[i]==0){
    //             vector<int> temp=nums;
    //             int curr=i;
    //             int dir=1;
    //             int tempCount=count;
    //             while(curr>=0 && curr<n && tempCount!=0){
    //                 if(temp[curr]){
    //                     temp[curr]--;
    //                     dir= -dir;
    //                     if(temp[curr]==0)tempCount--;
    //                 }
    //                 curr+=dir;
    //             }
    //             if(tempCount==0)ans++;

    //             temp=nums;
    //             curr=i;
    //             dir=-1;
    //             tempCount=count;
    //             while(curr>=0 && curr<n && tempCount!=0){
    //                 if(temp[curr]){
    //                     temp[curr]--;
    //                     dir= -dir;
    //                     if(temp[curr]==0)tempCount--;
    //                 }
    //                 curr+=dir;
    //             }
    //             if(tempCount==0)ans++;
    //         }
    //     }
    //     return ans;
    // }

    //Most Optimized
    int countValidSelections(vector<int>& nums) {
        
        int ans=0,currSum=0,totalSum=0;
        for(int num:nums){
            totalSum+=num;
        }
        for(int num:nums){
            if(num==0){
                int leftSum=currSum;
                int rightSum=totalSum-currSum;
                if(leftSum==rightSum)ans+=2;
                else if(abs(leftSum-rightSum)==1)ans+=1;
            }
            currSum+=num;
        }
        return ans;
    }
};