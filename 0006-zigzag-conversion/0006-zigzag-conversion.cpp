class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(numRows,"");
        int i=0,dir=1;
        for(char ch:s){
            v[i]+=ch;
            i=i+dir;
            if(i==numRows){
                dir=-1;
                if(i-2>-1)i-=2;
                else i--;
            }
            if(i==-1){
                dir=1;
                if(i+2<numRows)i+=2;
                else i++;
            }
        }
        string ans="";
        for(string s1:v){
            ans+=s1;
        }
        return ans;
    }
};