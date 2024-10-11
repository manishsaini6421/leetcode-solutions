class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int ans=0;
        for(auto command:commands){
            if(command=="RIGHT") ans++;
            else if(command=="LEFT") ans--;
            else if(command=="DOWN") ans+=n;
            else ans-=n;
        }
        return ans;
    }
};