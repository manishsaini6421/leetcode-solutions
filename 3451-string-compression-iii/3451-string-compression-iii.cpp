class Solution {
public:
    string compressedString(string word) {
        int count=1;
        string ans="";
        char temp=word[0];
        for(int i=1; i<=word.size(); i++){
            if(temp!=word[i] && count!=9){
                ans+='0'+count;
                ans+=temp;
                count=1;
                temp=word[i];
            }
            else if(count==9){
                ans+='0'+count;
                ans+=temp;
                count=1;
                temp=word[i];
            } 
            else count++;
        }
        return ans;
    }
};