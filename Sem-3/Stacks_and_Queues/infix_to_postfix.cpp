#include <iostream>
#include <string.h>
#include <stack>
#include<string>
using namespace std;

int pre(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if(op == '*' || op == '/')
        return 2;
    return 0;
}

bool isOperand(char ch)
{
    if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
        return true;
    return false;
}

char *postfix(char *infix)
{
    stack<char> st;
    char *postfix = new char[strlen(infix)+2];
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (st.empty() || pre(infix[i]) > pre(st.top()))
            {
                st.push(infix[i++]);
            }
            else
            {
                postfix[j++] = st.top();
                st.pop();
            }
        }
    }

    while (!st.empty())
    {
        postfix[j++] = st.top();
        st.pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char str1[] = "";
    char* str = postfix(str1);
    int i = 0;
    cout << str;
    // while (str[i++] != '\0')
    // {
    //     cout << str[i];
    // }
}