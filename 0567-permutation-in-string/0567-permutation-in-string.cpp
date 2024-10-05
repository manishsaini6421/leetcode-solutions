class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        unordered_map<char,int> map1;
        for(auto val:s1){
            map1[val]++;
        }
        unordered_map<char,int> map2;
        int i=0;
        for(i=0; i<s1.size(); i++){
            map2[s2[i]]++;
        }
        int k=0;
        i--;
        for(i; i<s2.size(); i++){
            
            int flag=0;
            for(char j='a'; j<='z'; j++){
                if(map1[j]==map2[j]) {
                    
                    flag++;
                }
                else break;
            }
            if(flag==26) 
                return true;
            
            map2[s2[i+1]]++;
            map2[s2[k]]--;
            k++;

        }
        return false;
    }
};