class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        vector<vector<int>> arr;
        for(int i=num2.size()-1; i>=0; i--){
            int num=0;
            vector<int>temp;
            for(int j=num1.size()-1; j>=0; j--){
                num+=(num1[j]-'0')*(num2[i]-'0');
                temp.insert(temp.begin(),num%10);
                num/=10;
            }
            if(num>0)
            temp.insert(temp.begin(),num);
            for(int k=0; k<num2.size()-i-1; k++){
                temp.push_back(0);
            }
            arr.push_back(temp);
        }
        for(int i=0; i<arr.size(); i++){
           int k=arr[arr.size()-1].size()-arr[i].size();
            for(int j=0; j<k; j++){
                arr[i].insert(arr[i].begin(),0);
            }
        }
        string result="";
        cout<<arr[0].size()<<endl;
        cout<<arr.size()<<endl;
        for(int i=0; i<arr.size(); i++){
            for(int j=0; j<arr[i].size(); j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        int x=0;
       for(int j=arr[0].size()-1; j>=0; j--){
            
          for(int i=0; i<arr.size(); i++){
            x+=arr[i][j];
            
          }
          result=to_string(x%10)+result;
            x/=10;
          
        }
        if(x>0)
        result=to_string(x)+result;
        return result;

    }
};