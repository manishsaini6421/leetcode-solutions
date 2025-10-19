class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> mp;
        vector<int> v;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        for(auto pair:mp){
            v.push_back(pair.second);
        }
        priority_queue<int,vector<int>, greater<int>> pq(v.begin(),v.end());
        while(k>0){
            int temp=pq.top();
            
            pq.pop();
            if(temp<=k)k-=temp;
            else {
                pq.push(temp-k);
                k=0;
            }

        }
        return pq.size();

    }
};