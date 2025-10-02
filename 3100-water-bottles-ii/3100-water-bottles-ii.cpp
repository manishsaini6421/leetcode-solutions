class Solution {
public:
    // int maxBottlesDrunk(int numBottles, int numExchange) {
    //     int ans=0;
    //     while(numBottles>=numExchange){
    //         ans+=numExchange;
    //         numBottles-=numExchange;
    //         numBottles+=1;
    //         numExchange++;
    //     }
    //     ans+=numBottles;
    //     return ans;
    // }
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int a=1;
        int b=2*numExchange -3;
        double delta= (double)(b*b - 4 * a * (-2*numBottles));

        double ans=ceil(((-b)+(double)sqrt(delta))/2);
        return numBottles+ans-1;
    }
};