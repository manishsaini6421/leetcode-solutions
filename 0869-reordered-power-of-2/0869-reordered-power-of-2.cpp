class Solution {
public:
    bool reorderedPowerOf2(int n) {
        map<int,int> freq;
        while(n){
            freq[n%10]++;
            n/=10;
        }
        for(int i=0; i<31; i++){
            int temp=(1<<i);
            map<int,int> freq1;
            while(temp){
                freq1[temp%10]++;
                temp/=10;
            }
            if(freq.size()==freq1.size()){
                int count=0;
                for(auto pair:freq){
                    if(freq1[pair.first]==pair.second)count++;
                }
                if(count==freq.size())return true;
            }

        }
        return false;
    }
};