class Solution {
public:
    int sumOfDigits(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int,int> map;
        for(int i=lowLimit; i<=highLimit; i++){
            map[sumOfDigits(i)]++;
        }
        int ans=0;
        for(auto num:map){
            ans=max(ans,num.second);
        }
        return ans;
    }
};