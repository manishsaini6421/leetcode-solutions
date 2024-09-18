class Solution {
public:
    bool check(int x){
        int count=0;
        while(x>0){
           count++;
           x/=10;
        }
        if(count%2==0)return true;
        return false;
    }
    int findNumbers(vector<int>& nums) {
      
        
        int result=0;
        for(auto itr:nums){
            if(check(itr))
            result++;
        }
        return result;
    }
};