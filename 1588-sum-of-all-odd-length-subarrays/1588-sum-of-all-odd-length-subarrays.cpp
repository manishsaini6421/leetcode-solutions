class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
       for(int i=0; i<n; i++){
           ans+=(((n-i)*(i+1)+1)/2*arr[i]);
       }
        return ans;
    }
};