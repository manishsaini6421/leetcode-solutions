class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int  n=tops.size();

        unordered_map<int,int> map1;
        unordered_map<int,int> map2;

        for(int i=0; i<n; i++){
            map1[tops[i]]++;
        }
        for(int i=0; i<n; i++){
            map2[bottoms[i]]++;
        }
        int max1=0,num1=0;
        for(auto pair:map1){
            if(pair.second>max1){
                max1=pair.second;
                num1=pair.first;
            }
        }
        int max2=0,num2;
        for(auto pair:map2){
            if(pair.second>max2){
                max2=pair.second;
                num2=pair.first;
            }
        }
        cout<<num1<<" "<<max1<<" "<<num2<<" "<<max2;
        int ans=0;
        if(max1>max2){
            for(int i=0; i<n; i++){
                if(tops[i] != num1){
                    if(bottoms[i]== num1)ans++;
                    else return -1;
                }
            }
        }
        else{
            for(int i=0; i<n; i++){
                if(bottoms[i]!= num2){
                    if(tops[i]==num2)ans++;
                    else return -1;
                }
            }
        }
        return ans;
    }
};