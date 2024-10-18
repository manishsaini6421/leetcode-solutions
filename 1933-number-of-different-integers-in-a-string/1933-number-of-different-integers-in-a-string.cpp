class Solution {
public:
    int numDifferentIntegers(string word) {
       unordered_map<int,int> map;
        long long x=0;
        int flag=0;
        for(auto s:word){
            if(s>='0' && s<='9'){
                x=x*10+(s-'0');
                x%=10000000000; // To avoid overflow
                flag=1;
            }
            else if(flag){
                map[x]++;
                cout<<x<<endl;
                x=0;
                flag=0;
            }
        }
        if(flag){
            map[x]++;
        }
        
        
        return map.size();
    }
};