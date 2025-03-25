class Solution {
public:
    static bool cmp(vector<int> &v1,vector<int> &v2){

        if(v1[1]!=v2[1])
            return v1[1]<v2[1];
        return v1[3]<v2[3];
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        sort(rectangles.begin(),rectangles.end());
       
        
        
        vector<pair<int,int>> x;
        x.push_back({rectangles[0][0],rectangles[0][2]});

        for(int i=1; i<rectangles.size(); i++){
            if(x.back().second <= rectangles[i][0]){
               x.push_back({rectangles[i][0],rectangles[i][2]});
            }
            
            else{
                x.back().second=max(x.back().second,rectangles[i][2]);
            }

           

        }
        
        if(x.size()>2)return true;

        sort(rectangles.begin(),rectangles.end(),cmp);
        for(auto v:rectangles){
            cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<endl;
        }
        vector<pair<int,int>> y;

        y.push_back({rectangles[0][1],rectangles[0][3]});

        for(int i=1; i<rectangles.size(); i++){
            if(y.back().second <= rectangles[i][1]){
               y.push_back({rectangles[i][1],rectangles[i][3]});
            }
            
            else{
                y.back().second=max(y.back().second,rectangles[i][3]);
            }
            
        }

         if(y.size()>2)return true;

         return false;
        
    }
};