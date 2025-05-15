class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        
        long long totalEnergy=currentEnergy;
        int mini=INT_MAX;
        for(auto energy:enemyEnergies){
            mini=min(mini,energy);
            totalEnergy+=energy;
        }
        totalEnergy-=mini;
        if(currentEnergy<mini)return 0;
        return totalEnergy/mini;
        
    }
};