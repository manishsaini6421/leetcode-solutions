class Solution {
public:
  
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<pair<pair<int,int>,int>> events;
        int n=times.size();
        for(int i=0; i<n; i++){
            events.push_back({{times[i][0],1},i});
            events.push_back({{times[i][1],-1},i});
        }
        sort(events.begin(),events.end());

        vector<int> assignedChairs(n);

        priority_queue<int,vector<int>,greater<int>> availableChairs;

        for(int i=0; i<n; i++){
            availableChairs.push(i);
        }

       

        for(auto event:events){
            int time=event.first.first;
            int type=event.first.second;
            int person=event.second;

            if(person==targetFriend && type==1) return availableChairs.top();

            else if(type==1){
                assignedChairs[person]=availableChairs.top();
                availableChairs.pop();
            }
            else if(type==-1){
                availableChairs.push(assignedChairs[person]);
                
            }
        }
        return -1;
        
    }
};