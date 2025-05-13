class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size();
        char temp=word[0];
        int count=1;
        int ans=0;
        for(int i=1; i<n; i++){
            if(word[i]==temp)count++;
            else{
                ans+=(count-1);
                temp=word[i];
                count=1;
            }
        }
        ans+=count;
        return ans;
    }
};