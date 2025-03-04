class Solution {
public:
    bool solve(int n,int i){
        int x=pow(3,i);
        if(n==x)return true;
        if(x>n || n<0)return false;
        return (solve(n,i+1)  || solve(n-x,i+1));
    }
    bool checkPowersOfThree(int n) {
    
        return solve(n,0);
    }
};