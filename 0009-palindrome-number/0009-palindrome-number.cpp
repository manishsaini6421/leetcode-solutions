class Solution {
public:
    // bool isPalindrome(int x) {
    //     if(x<0)return false;
    //     string s="";
    //     int num=x;
    //     while(num){
    //         s+=(char(num%10));
    //         num/=10;
    //     }

    //     int i=0,j=s.size()-1;
    //     while(i<=j){
    //         if(s[i]!=s[j])return false;
    //         i++;
    //         j--;
            
    //     }
    //     return true;
    // }
    bool isPalindrome(int x) {
        if(x<0)return false;
        int num=x;

        int y=0;
        while(x){
            y=y*1l*10 + (x%10);
            x/=10;
        }
        return y==num;
        
    }
};