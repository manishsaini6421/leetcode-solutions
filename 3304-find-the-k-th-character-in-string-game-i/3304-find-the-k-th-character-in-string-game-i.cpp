class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        string cp=s;
        while(s.size()<k){
            for(auto ch:cp){
                s+='a'+(ch-'a'+2)%26-1;
            }
            cp=s;
        }
        cout<<s;
        return s[k-1];
    }
};