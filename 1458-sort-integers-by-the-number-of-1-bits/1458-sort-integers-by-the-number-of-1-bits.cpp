class Solution {
public:
   static int setBits(int num){
        int count=0;
        while(num){
            count+=num&1;
            num>>=1;
        }
        return count;
    }
    
    static  int manual(int num1,int num2){
        if(setBits(num1)==setBits(num2)) return num1<num2;
        return setBits(num1)<setBits(num2);
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),manual);
        return arr;
    }
};