class Solution {
public:
    //Using minHeap
    // int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    //     int n=arr.size();
    //     unordered_map<int,int> mp;
    //     vector<int> v;
    //     for(int i=0; i<n; i++){
    //         mp[arr[i]]++;
    //     }
    //     for(auto pair:mp){
    //         v.push_back(pair.second);
    //     }
    //     priority_queue<int,vector<int>, greater<int>> pq(v.begin(),v.end());
    //     while(k>0){
    //         int temp=pq.top();
            
            
    //         if(temp<=k){
    //             k-=temp;
    //             pq.pop();
    //         }
    //         else break;

    //     }
    //     return pq.size();

    // }

    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int num:arr){
            mp[num]++;
        }
        vector<int> freq;
        for(auto pair:mp){
            freq.push_back(pair.second);
        }
        sort(freq.begin(),freq.end());
        
        int count=freq.size();
        int i=0;
        for(int c:freq){
            if(c<=k){
                k-=c;
                count--;
            }
            else break;
        }
        return count;
    }
};