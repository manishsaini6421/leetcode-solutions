class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss1(sentence1);
        string word;

       vector<string> v1;
       while(ss1>>word){
        v1.push_back(word);
       }

       stringstream ss2(sentence2);
       vector<string> v2;
       while(ss2>>word){
        v2.push_back(word);
       }

       int l=0,r1=v1.size()-1,r2=v2.size()-1;

       while(l<=r1 && l<=r2){
        if(v1[l]==v2[l]){
            cout<<v1[l]<<endl;
            l++;
            
        }
        else if(v1[r1]==v2[r2]){
            cout<<v1[r1]<<v2[r2]<<endl;
            r1--;
            r2--;

        }
        else break;
       }
       return (r1+1==l || r2+1==l)?true:false;
    }
    
};