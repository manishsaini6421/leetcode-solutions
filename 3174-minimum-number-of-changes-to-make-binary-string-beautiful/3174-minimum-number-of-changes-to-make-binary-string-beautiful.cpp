class Solution {
public:
    int minChanges(string s) {
        int ans=0;
        int count=1;
        char temp=s[0];
        for(int i=1; i<s.size(); i++){
            if(temp!=s[i] && count%2==0){
                count=1;
                temp=s[i];
            }
            else if(temp!=s[i] && count%2!=0){
                count++;
                ans++;
            }
            else count++;
        }
        return ans;
    }
};