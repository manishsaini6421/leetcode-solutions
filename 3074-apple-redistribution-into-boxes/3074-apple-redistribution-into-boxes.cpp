class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n=apple.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=apple[i];
        }
        sort(capacity.begin(),capacity.end(),greater<int> ());
        int ans=0;
        int count=0;
        cout<<sum<<endl;
        for(auto cap:capacity){
            count+=cap;
            ans++;
            cout<<count<<endl;
            if(count>=sum)return ans;
        }
        return -1;
    }
};