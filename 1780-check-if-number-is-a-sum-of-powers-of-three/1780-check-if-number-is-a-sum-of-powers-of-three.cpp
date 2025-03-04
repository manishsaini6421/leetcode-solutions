class Solution {
public:
    bool solve(int n,int i){
        if(n==0)return true;
        if(n<0 || i<0)return false;

        return (solve(n,i-1)  || solve(n-pow(3,i),i-1));
    }
    bool checkPowersOfThree(int n) {
        int x=0;

        while(n>=pow(3,x)){
            x++;
        }
        return solve(n,x-1);
    }
};