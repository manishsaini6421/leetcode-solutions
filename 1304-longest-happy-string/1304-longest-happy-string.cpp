class Solution {
public:
   
    string longestDiverseString(int a, int b, int c) {
        string s="";
        int maxlen=a+b+c,i=0,currA=0,currB=0,currC=0;
        while(i<maxlen){
            if(currA!=2 && a>=b && a>=c || a>0 &&(currB==2 || currC==2)){
                s+='a';
                a--;
                currA++;
                currB=0;
                currC=0;
               
            }
            else if(currB!=2 && b>=c && b>=a || b>0 && (currA==2 || currC==2)){
                s+="b";
                b--;
                currB++;
                currA=0; currC=0;
            }
            else if(currC!=2 && c>=a && c>=b || c>0 && (currA==2 || currB==2)){
                s+='c';
                c--;
                currC++;
                currA=0; currB=0;
            }
            
           i++;


        }
        
        return s;
    }
};