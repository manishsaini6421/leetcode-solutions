class Solution {
public:
    bool isPrime(int n){
        if(n==1)return false;
        for(int i=2; i<=sqrt(n); i++){
            if(n%i==0)return false;
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int x=-1,y=-1;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(isPrime(nums[i])){
                if(x==-1)x=i,y=i;
                else y=i;
            }
        }
        return y-x;


    }
};