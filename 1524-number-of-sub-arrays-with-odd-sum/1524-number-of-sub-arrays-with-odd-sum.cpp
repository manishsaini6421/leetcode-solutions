class Solution {
public:
  
    int numOfSubarrays(vector<int>& arr) {
        int ans=0;
        int prefixSum=0;
        int odd=0,even=1;

        for(auto num:arr){
            prefixSum+=num;
            if(prefixSum%2){
                ans+=even;
                odd++;
            }
            else{
                ans+=odd;
                even++;
            }
        }
        return ans%1000000007;
    }
};