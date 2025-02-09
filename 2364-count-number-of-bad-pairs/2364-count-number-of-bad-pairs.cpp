class Solution {
public:
    static bool manual(pair<int,int> p1,pair<int,int> p2){
        return p1.second<p2.second;
    }
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
          unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            nums[i]=nums[i]-i;
            m[nums[i]]++;
        }
        long long valid=0;
        for(auto pair:m){
            long long x=pair.second;
            valid+=(x*(x-1))/2;
        }
        long long total=n*(n-1)/2;
        return total - valid;

    }
};