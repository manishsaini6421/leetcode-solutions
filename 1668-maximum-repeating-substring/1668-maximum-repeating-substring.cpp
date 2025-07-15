class Solution {
public:
    bool check(string &sequence, string &word){
        int n=word.size();
        int ans=0;
        for(int i=0; i<sequence.size(); i++){
            cout<<i<<" ";
            int count=0;
            for(int j=0; j<n; j++){
                if(sequence[i+j]==word[j])
                {
                    count++;
                }
                else
                    break;
                
                
            }
            if(count==n){
                return true;
            }
            
        }
        return false;
    }
    int maxRepeating(string sequence, string word) {
        
        int ans=0;
        string str=word;
        while(check(sequence,word)){
            ans++;
            word+=str;
        }
        return ans;
    }
};