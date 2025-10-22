class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n=word.size();
        int ans=0;
        for(int i=1; i<n; i++){
            if(abs(word[i]-word[i-1])<=1){
                ans++;
                i++;
            }

        }
        return ans;
    }
};