class Solution {
public:
    int hamming(string& s1, string& s2) {
        int count = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i])
                count++;
        }
        return count;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        int n = words.size();

        vector<int> dp(n, 1);
        vector<int> parent(n, -1);

        int longestSub=1;
        int longestSubIdx=0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[j] != groups[i] &&
                    words[j].size() == words[i].size() &&
                    hamming(words[j], words[i]) == 1) {
                        if(dp[j]+1>dp[i]){
                            dp[i]=dp[j]+1;
                            parent[i]=j;
                            if(longestSub<dp[i]){
                                longestSub=dp[i];
                                longestSubIdx=i;
                            }
                        }
                }
            }
        }
        vector<string> ans;
        while(longestSubIdx!=-1){
            ans.push_back(words[longestSubIdx]);
            longestSubIdx=parent[longestSubIdx];
        }
        reverse(ans.begin(),ans.end());
        

        return ans;
    }
};