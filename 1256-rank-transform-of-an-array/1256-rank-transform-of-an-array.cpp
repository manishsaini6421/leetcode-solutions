class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> res;
        vector<int> temp=arr;

        if(arr.size()==0) return res;

        sort(temp.begin(),temp.end());

        unordered_map<int,int> map;
        int rank=1;
        map[temp[0]]=1;
        for(int i=1; i<temp.size(); i++){
            if(temp[i-1]!=temp[i]) rank++;
            map[temp[i]]=rank;
        }

       
        for(int i=0; i<arr.size(); i++){
            res.push_back(map[arr[i]]);
        }
        return res;
    }
};