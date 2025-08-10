class Solution {
public:
    bool reorderedPowerOf2(int n) {
        array<int,10> freq;
        while(n){
            freq[n%10]++;
            n/=10;
        }
        for(int i=0; i<31; i++){
            int temp=(1<<i);
            array<int,10> freq1;
            while(temp){
                freq1[temp%10]++;
                temp/=10;
            }
            
            bool flag=0;
            for(int j=0; j<10; j++){
                    if(freq1[j]!=freq[j])flag=1;
                        

            }
            if(!flag)return true;
            

        }
        return false;
    }
};