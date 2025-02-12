#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isOperand(char ch)
{
    if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
        return true;
    return false;
}

int eval(string postfix){
    stack<int> st;
    for(char ch: postfix){
        if(isOperand(ch)) st.push(ch-'0');
        else{
            int val1 = st.top() ;
            st.pop();
            int val2 = st.top();
            st.pop();
            if(ch == '+'){
                int x = val1+val2;
                st.push(x);
            }
            else if(ch == '-'){
                int x = val1-val2;
                st.push(x);
            }
            else if(ch == '/'){
                int x = val1/val2;
                st.push(x);
            }
            else if(ch == '*'){
                int x = val1*val2;
                st.push(x);
            } 
        }
    }

    return st.top();
}
int main(){
    cout << eval("234*+82/-");
}