#include<bits/stdc++.h>
using namespace std;
bool checkValidString(string s) {
    int left, right;
    left = right = 0;
    for (int i = 0; i<s.size(); i++){
    	if(s[i] == '('){
    		left++;
    		right++;
    	}
    	else if(s[i] == ')'){
    		left--;
    		right--;
    	}
    	else{
    		left--;
    		right++;
    	}
    	if(right < 0) return false;
    	if(left < 0) left = 0;
    }
    return left ==0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s = "(*)";
	cout<<checkValidString(s);
	return 0;
}