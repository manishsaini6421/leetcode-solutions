class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
      vector<int> maxHeight(n,0);
      vector<int> index(n,0);
      index[0]=0;
      int maxH=height[0];
      for(int i=1; i<height.size(); i++){
            if(height[i]>maxH){
                index[i]=i;
                maxH=height[i];
                
            }
            else    index[i]=index[i-1];

            maxHeight[i]=maxH;
      }
      int ans=0;
      for(int i=n-1; i>=0; i--){
        ans=max(ans,min(maxHeight[i],height[i])*(i-index[i]));
      }
      return ans;
    }
};