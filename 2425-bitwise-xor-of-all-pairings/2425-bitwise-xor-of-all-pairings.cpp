class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans;
        int n1=nums1.size(),n2=nums2.size();
        if(n1%2==0 && n2%2==0){
            ans=0;
        }
        else if(n1%2==0 && n2%2!=0){
            ans=nums1[0];
            for(int i=1; i<n1; i++){
            ans^=nums1[i];
            }
        }
        else if(n1%2!=0 && n2%2==0){
            ans=nums2[0];
            for(int i=1; i<n2; i++){
            ans^=nums2[i];
            }
        }
        else{
            ans=nums1[0];
            for(int i=1; i<n1; i++){
            ans^=nums1[i];
            }
            for(int i=0; i<n2; i++){
            ans^=nums2[i];
            }
        }
        
        return ans;
    }
};