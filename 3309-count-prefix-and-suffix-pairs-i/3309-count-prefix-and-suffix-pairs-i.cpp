class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;
        int n=words.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int size=words[i].size();
                 int size1=words[j].size();
                if(size<=size1){
                    int flag=0;
                for(int k=0; k<size; k++){
                    if(words[i][k]!=words[j][k])flag++;
                    
                }
               
                for(int l=size1-size; l<size1; l++){
                    if(words[i][l-(size1-size)]!=words[j][l])flag++;
                   
                }
                cout<<flag<<endl;
                if(flag==0)ans++;
                }
                
            }
        }
        return ans;
    }
};