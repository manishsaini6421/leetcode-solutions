class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m=str1.size();
        int n=str2.size();
        int i=0,j=0;
        while(i<m){
            if(str2[j]==str1[i] || str2[j]=='a'+((str1[i]-'a'+1))%26){
                cout<<i<<endl;
                i++;
                j++;
            }
            else i++;
        }
        if(j==n) return true;
        return false;
    }
};