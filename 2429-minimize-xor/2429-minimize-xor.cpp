class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ans=num1;
        int n2=num1;
        int count1=0,count2=0;
        vector<int> v(32,0);
        int i=0;
        while(num1){
            count1+=num1&1;
            v[31-i]=num1&1;
            i++;
            num1>>=1;
        }
        while(num2){
            count2+=num2&1;
            num2>>=1;
        }
        int x=count2-count1;
        if(x<0){
            ans=0;
            for(int i=0; i<32 && count2>0; i++){

            if(v[i]==1){
                ans+=pow(2,31-i);
                count2--;
            }
            
        }
        }
        else{
            for(int i=0; i<32 && x>0; i++){

            if(v[31-i]==0){
                ans+=pow(2,i);
                x--;
            }
            
        }
        
        }
        
        return ans;
    }
};