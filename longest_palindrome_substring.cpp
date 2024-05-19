#include <iostream>
#include <string.h>

using namespace std;


string longestPalindrome(string s) {
	int len = s.size();
	if(len < 2){
		return s;
	}
	int high, low, maxlen = 1, start = 0;
	for (int i = 0; i<len; i++){
		low = i - 1;
		high = i+ 1;
		// for s[i] same as s[i--]
		while(low>=0 && s[i] == s[low]){
			low --;
		}
		// for s[i] same as s[i++]
		while(high<len && s[i] == s[high]){
			high++;
		}
		// check palindrome keep s[i] as center character
		while(high < len && low >= 0 && s[high] == s[low]){
			high ++;
			low--;
		}
		if(high - low -1 > maxlen){
			maxlen = high-low -1;
			start = low+1;
		}
	}
	// cout<<start<<" "<<maxlen<<endl;
	return s.substr(start, maxlen);
}


int main(int argc, char const *argv[])
{
	string s = "cbbd";
	cout<<longestPalindrome(s);
	return 0;
}