class Solution {
public:
   
       void backtrack(vector<string> &ans,vector<string> &v,string &digits, int index, string s){
            if(s.size()==digits.size()){
                ans.push_back(s);
                return;
            }
            
            for(auto x:v[digits[index]-'0']){
                backtrack(ans,v,digits,index+1,s+x);
            }
        }
    
    vector<string> letterCombinations(string digits) {
       
        vector<string> ans;
         if(digits.size()==0) return ans;
       vector<string> v={
           "",
           "",
           "abc",
           "def",
           "ghi",
           "jkl",
           "mno",
           "pqrs",
           "tuv",
           "wxyz"
       };
        string curr="";
     
        
        backtrack(ans,v,digits,0,curr);
        return ans;
        
    }
};