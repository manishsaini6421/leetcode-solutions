class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=0;
        while(numBottles>=numExchange){
            ans+=numExchange;
            numBottles-=numExchange;
            numBottles+=1;
            numExchange++;
        }
        ans+=numBottles;
        return ans;
    }
};