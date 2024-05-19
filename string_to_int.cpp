#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int res = 0, sign = 1;
    int i= 0;
    long long resl;
    while(i<s.size()){
        if(s[i] == ' '){
            i++;
            continue;
        }
        else if(s[i] == '-'){
            sign = -1;
            i++;
            break;
        }
        else if(s[i] == '+'){
            i++;
            break;
        }
        else{
            break;
        }
    }
    for(; i<s.size(); i++){
        if(!(s[i]>='0' && s[i]<='9')){
            break;
        }
        resl = res * 10LL + (s[i] - '0');
        if(resl <= INT_MAX){
            res = resl;
        }
        else{
        	if(sign == -1){
        		res = INT_MIN;
        	}
        	else	res = INT_MAX;
        	return res;
        }
    }
    return res * sign;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout<<myAtoi("-500000000000")<<endl;
	return 0;
}