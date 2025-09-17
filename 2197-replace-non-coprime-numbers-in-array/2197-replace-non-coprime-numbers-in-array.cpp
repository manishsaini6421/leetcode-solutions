class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            
            while (!st.empty() && gcd(st.top(), val) != 1) {
                val = lcm(st.top(), val);
                st.pop();
            }
            st.push(val);
        }
        int size=st.size();
        vector<int> v(size, 0);
        for(int i=size-1; i>=0; i--) {
            v[i] = st.top();
            st.pop();
        }
        return v;
    }
};
