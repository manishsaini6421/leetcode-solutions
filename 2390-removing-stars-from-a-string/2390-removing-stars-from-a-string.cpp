class Solution {
public:
    string removeStars(string s) {
        vector<char> v;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='*')v.pop_back();
            else v.push_back(s[i]);
        }
        string result="";
        for(int i=0; i<v.size(); i++){
            result+=v[i];
        }
        return result;
    }
};