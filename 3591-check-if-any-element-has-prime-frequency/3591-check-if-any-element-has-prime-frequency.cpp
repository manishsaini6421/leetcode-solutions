class Solution {
public:
    bool isPrime(int n){
        if(n==1)return false;
        for(int i=2; i<=sqrt(n); i++){
            if(n%i==0)return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto num:nums){
            mp[num]++;
        }
        for(auto pair:mp){
            if(isPrime(pair.second)) return true;
        }
        return false;
    }
};