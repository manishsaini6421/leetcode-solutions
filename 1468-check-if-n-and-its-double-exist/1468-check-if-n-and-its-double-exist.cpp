class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j && arr[i]==2*arr[j])return true;
            }
        }
        return false;
    }
};