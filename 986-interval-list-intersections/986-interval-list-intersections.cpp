class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> v;
        
        int i=0,j=0;
        int m=firstList.size(),n=secondList.size();
        while(i<m && j<n){
            int startA=firstList[i][0] ,endA=firstList[i][1];
            int startB=secondList[j][0],endB=secondList[j][1];
            vector<int> temp;
            if(startA<=endB && startB<=endA){
                
                temp.push_back(max(startA,startB));
                temp.push_back(min(endA,endB));
                 v.push_back(temp);
            }
            if(endB <startA || endB<endA){
                j++;
            }
            else if(endA<startB || endA<endB){
                i++;
            }
            else{
                i++;
                j++;
            }
           
        }
        return v;
    }
};