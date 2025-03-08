class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int count=0;
        int maxCount=0;
        for(int i=0; i<k; i++){
           if(blocks[i]=='B')count++;
            maxCount=max(maxCount,count);
        }
        int index=0;
        for(int i=k; i<n; i++){
            if(blocks[i]=='B')count++;
            if(blocks[index]=='B')count--;
            index++;
            maxCount=max(maxCount,count);
        }
        cout<<maxCount<<endl;
        return (maxCount>=k)?0:k-maxCount;
    }
};