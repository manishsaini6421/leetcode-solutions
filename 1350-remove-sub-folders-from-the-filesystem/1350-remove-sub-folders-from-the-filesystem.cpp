class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

       vector<string> v; 
      sort(folder.begin(),folder.end());

      v.push_back(folder[0]);
      int n=folder.size();
      for(int i=1; i<n; i++){
        string temp=v.back();
        string s=folder[i].substr(0,temp.size());
        if(temp==s && folder[i][temp.size()]=='/')continue;
        else v.push_back(folder[i]);
      }
      return v;
    }
};