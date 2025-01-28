class Solution {
public:
   
    void gen(vector<string> &ans,int n,string s,int open,int close){
        if(open<close || open>n || close>n)return;
       if(open==n && close==n){
        ans.push_back(s);
        return;
       }
       
       else{
        gen(ans,n,s+')',open,close+1);
        gen(ans,n,s+'(',open+1,close);
       }
       

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen(ans,n,"",0,0);

        
       
        return ans;
    }
};