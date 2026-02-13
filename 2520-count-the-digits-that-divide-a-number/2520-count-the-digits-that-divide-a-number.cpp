class Solution {
public:
    int countDigits(int num) {
        int temp=num;
        int ans=0;
        while(temp){
            int digit=(temp%10);
            if(num%digit==0)ans++;
            temp/=10;
        }
        return ans;
    }
};