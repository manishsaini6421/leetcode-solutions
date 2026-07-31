class Solution {
public:
    
    int minimumPushes(string word) {
        
        vector<int> v(26,0);
        for(char w:word){
            v[w-'a']++;
        }
        int ans=0;
        sort(v.rbegin(),v.rend());
        for(int i=0; i<26; i++){
            if(i<8)ans+=v[i];
            else if(i<16)ans+=(v[i]*2);
            else if(i<24)ans+=(v[i]*3);
            else ans+=(v[i]*4);
        }
        for(auto x:v){
            cout<<x<<endl;
        }
        
       
        return ans;
       
    }
};