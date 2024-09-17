class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> count1;

        for(int i=0; i<words1.size(); i++){
            count1[words1[i]]++;
        }
        int result=0;
        unordered_map<string,int> count2;

        for(int i=0; i<words2.size(); i++){
                count2[words2[i]]++;
        }
        for(auto& pair:count1){
            if(pair.second==1 && count2[pair.first]==1){
               result++;
            }
        }
        return result;
    }
};