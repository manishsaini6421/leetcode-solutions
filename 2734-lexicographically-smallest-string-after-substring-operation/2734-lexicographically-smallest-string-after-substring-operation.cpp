class Solution {
public:
    string smallestString(string s) {
        int n=s.size();
        int start=n-1,end=n-1;
        for(int i=0; i<n; i++){
            if(s[i]!='a')
            {
                start=i;
                break;
            }

        }
        for(int i=start; i<n; i++){
            if(s[i]!='a')end=i;
            else break;
        }
        for(int i=start; i<=end; i++){
            s[i]=((s[i]-'a'-1+26)%26)+'a';
        }
        return s;
    }
};