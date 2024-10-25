class Solution {
public:
   static bool custom(const string& s1,const string& s2){
        return s1.back()<s2.back();
    }
    string sortSentence(string s) {
        vector<string> v;
        stringstream ss(s);
        string word;

        while(ss>>word){
            v.push_back(word);
        }
        sort(v.begin(),v.end(),custom);

        string ans="";
        for(auto val:v){
            ans+=val.substr(0,val.size()-1);
            ans+=" ";
        }
        ans=ans.substr(0,ans.size()-1);
        return ans;
    }
};