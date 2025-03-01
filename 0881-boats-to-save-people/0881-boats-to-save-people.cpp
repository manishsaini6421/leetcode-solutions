class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size();
        int ans=0;
        for(int i=0; i<n-1; i++){
            if(people[i]+people[i+1]<=limit){
                ans++;
                i++;
            }
            else ans++;
        }
        if(people[n-1]+people[n-2]>limit)ans++;
        return ans;
    }
};