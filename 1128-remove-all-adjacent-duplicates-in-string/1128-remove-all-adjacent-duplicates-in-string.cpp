class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> v;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(v.size()>0 && v[v.size()-1]==s[i])
            {
                v.pop_back();

                while(v.size()>1 && v[v.size()-1]==v[v.size()-2]){
                    v.pop_back();
                    v.pop_back();
                }
            }
            else v.push_back(s[i]);
        }
        string result="";
        for(int i=0; i<v.size(); i++){
            result+=v[i];
        }
        return result;
    }
};