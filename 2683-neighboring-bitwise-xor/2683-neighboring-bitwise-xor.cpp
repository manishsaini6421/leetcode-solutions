class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        vector<int> v(n,0);
        v[0]=derived[0]^1;
        for(int i=0; i<n-1; i++){
            v[i+1]=derived[i]^v[i];
        }
        bool x =(v[0]==(derived[n-1]^v[n-1]));
        // v[0]=1;
        // for(int i=0; i<n-1; i++){
        //     v[i+1]=derived[i]^v[i];
        // }
        // bool y =(v[0]==(derived[n-1]^v[n-1]));

        return x;
    }
};