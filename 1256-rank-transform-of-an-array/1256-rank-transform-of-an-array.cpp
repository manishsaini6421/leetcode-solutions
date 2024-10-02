class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        vector<int> temp;
        if(arr.size()==0) return temp;
        for(auto num: arr){
            temp.push_back(num);
        }
        sort(temp.begin(),temp.end());
        unordered_map<int,int> map;
        int j=1;
        map[temp[0]]=1;
        for(int i=1; i<temp.size(); i++){
            if(temp[i-1]==temp[i])
                map[temp[i]]=j;
            else
                j++;
            map[temp[i]]=j;
        }
        vector<int> res;
        for(int i=0; i<arr.size(); i++){
            res.push_back(map[arr[i]]);
        }
        return res;
    }
};