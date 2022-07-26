class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char> temp(indices.size());
        for(int i=0; i<indices.size(); i++){
            temp[indices[i]]=s[i];
        }
        string ans="";
        
        for(auto x:temp){
            ans+=x;
        }
        return ans;
    }
};