class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int k=1;
        for(int i=digits.size()-1; i>=0 && k>0; i--){
            int num=digits[i]+k;
            digits[i]=num%10;
            k=num/10;
        }
        if(k>0){
            digits.insert(digits.begin(),k);
        }
        return digits;
    }
};