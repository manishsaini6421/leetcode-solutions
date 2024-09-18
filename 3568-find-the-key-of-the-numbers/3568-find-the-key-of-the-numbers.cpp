class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string s1=to_string(min(min(num1/1000,num2/1000),num3/1000));
        string s2=to_string(min(min((num1/100)%10,(num2/100)%10),(num3/100)%10));
        string s3=to_string(min(min((num1/10)%10,(num2/10)%10),(num3/10)%10));
        string s4=to_string(min(min(num1%10,num2%10),num3%10));
        return stoi(s1+s2+s3+s4);  
    }
};