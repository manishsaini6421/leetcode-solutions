class Solution {
public:
    long long smallestNumber(long long num) {
        long long result;
        if(num>0){
            string num1=to_string(num);
            sort(num1.begin(),num1.end());
            if(num1[0]=='0'){
                for(int i=0; i<num1.size(); i++){
                    if(num1[i]!='0'){
                        char temp=num1[i];
                        num1[i]='0';
                        num1[0]=temp;
                        break;
                    }
                }
            }
            result=stoll(num1);
        }
        else{
            num=-1*num;
            string num1=to_string(num);
            sort(num1.begin(),num1.end());
            reverse(num1.begin(),num1.end());
            result=-1*stoll(num1);
        }
        return result;
    }
};