class Solution {
public:
    bool check(vector<int>& freq, int k) {
        int n = freq.size();

        for (int i = 0; i < n-k; i++) {
            if (freq[i] >= k && freq[i + k] >= k) {
               return true;
            }
        }
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                freq[i] = freq[i - 1] + 1;
        }

        int a=0,b=n,k=0,mid;
     
        while(a<=b){
            mid=(a+b)/2;
            if(check(freq,mid)){
                k=mid;
                a=mid+1;
            }
            else b=mid-1;
        }
        return k;
    }
};