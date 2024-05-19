#include <iostream>
#include <string>
#include <stack>
using namespace std;


bool isValid(string s) {
    stack<char> paren;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            paren.push(s[i]);
        }
        else if(!paren.empty()){
            if(s[i] == ')' && paren.top() == '('){
                paren.pop();
            }
            else if(s[i] == '}' && paren.top() == '{'){
                paren.pop();
            }
            else if(s[i] == ']' && paren.top() == '['){
                paren.pop();
            }
            else {
                return false;
            }
        }
        else{
            return false;
        }
    }
    // cout<<paren.top()<<endl;
    return paren.empty();
}

int main(int argc, char const *argv[])
{
    cout<<"Total  valid parenthees: "<<isValid("(]{})");
    return 0;
}