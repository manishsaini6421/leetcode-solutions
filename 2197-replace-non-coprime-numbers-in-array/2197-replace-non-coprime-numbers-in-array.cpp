class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        st.push(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            int val = nums[i];
            
            while (!st.empty() && gcd(st.top(), val) != 1) {
                val = lcm(st.top(), val);
                st.pop();
            }
            st.push(val);
        }
        vector<int> v(st.size(), 0);
        while (!st.empty()) {
            v[st.size() - 1] = st.top();
            st.pop();
        }
        return v;
    }
};
