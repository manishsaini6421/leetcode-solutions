class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans='z'+1;
        for(char ch:letters){
            if(ch>target)
                ans=min(ans,ch);
        }
        if(ans=='z'+1)return letters[0];
        return ans;
    }
};