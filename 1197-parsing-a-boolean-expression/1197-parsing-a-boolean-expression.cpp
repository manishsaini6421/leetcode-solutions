class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<int> stack;
        int n=expression.size()-1;
        for(int i=n; i>=0; i--){
            if(expression[i]==',') continue;
           else if(!(expression[i]=='!'  || expression[i]=='|' || expression[i]=='&'))
            stack.push(expression[i]);
            else{
                stack.pop();

                bool temp=(stack.top()=='f') ? false:true;
                if(expression[i]=='!') {
                    if(temp) temp=false;
                    else temp=true;
                }

                stack.pop();
                
                while(stack.top()!=')'){
                    char c=stack.top();
                    if(c=='t'){
                        if(expression[i]=='&') temp&=true;
                        else if(expression[i]=='|') temp|=true;
                        else if(expression[i]=='!') temp=false;
                    }  
                    else {
                        if(expression[i]=='&') temp&=false;
                        else if(expression[i]=='|') temp|=false;
                        else if(expression[i]=='!') temp=true;
                    }  
                    stack.pop();
                }
                stack.pop();

                stack.push((temp) ? 't':'f');
            }
        }
        return (stack.top()=='t')?true:false;

    }
};