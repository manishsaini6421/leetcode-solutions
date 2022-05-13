class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left[n];
        int right[n];
        for(int i=0; i<n; i++)
          left[i]=(i>0) ? max(left[i-1],height[i]):height[i];
        for(int i=n-1; i>=0; i--)
            right[i]=(i<n-1) ? max(right[i+1],height[i]):height[i];
        int ans=0;
        for(int i=0; i<n; i++)
            ans+=min(left[i],right[i])-height[i];
        return ans;
    }
};