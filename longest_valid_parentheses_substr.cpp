#include<iostream>
#include <string.h>
#include<stack>
using namespace std;

int longestValidParentheses(string s) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int len = s.size();

    // less than 2 cant be valid
    if(len<2){
        return 0;
    }
    stack<char> paren;
    stack<int> index;
    index.push(0);
    // put them in stack and count remaining ones..
    for(int i = 0; i<s.size(); i++){
        if(s[i] == ')'){
            if(!paren.empty() && paren.top() == '('){
                index.pop();
                paren.pop();
                continue;
            }
        }
        paren.push(s[i]);
        index.push(i+1);
    }
    // if stack is empty not need to check obv
    if(paren.empty()){
        return len;
    }
    // find the longest valid substr
    int maxlen = 0, temp;
    // len--;
    while(!index.empty()){
        temp = len - index.top();
        len = index.top()-1;
        index.pop();
        if(temp > maxlen){
            maxlen = temp;
        }
    }
    return maxlen;
}


int main(int argc, char const *argv[])
{
	string s = "()(()";
	cout<<"Longest Valid Parenthese Substring: "<<longestValidParentheses(s);
	return 0;
}