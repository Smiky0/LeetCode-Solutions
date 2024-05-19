#include <iostream>
using namespace std;

string convert(string s, int numRows) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int len = s.size();
    if(numRows <2 || len<2) return s;
    string finalstr;
    int leftind, rightind;
    for(int i =0; i<numRows; i++){
        int j = 0;
        while(true){
            leftind = (numRows - 1) * 2 * j - i;
            rightind = (numRows - 1) * 2 * j + i;
            j++;
            if(leftind != rightind && leftind < len && leftind>=0 && s[leftind] != '_'){
                finalstr.push_back(s[leftind]);
                s[leftind] = '_';
            }
            if(rightind<len && rightind>=0 && s[rightind] != '_'){
                finalstr.push_back(s[rightind]);
                s[rightind] = '_';
            }
            else{
                break;
            }
        }
    }
    return finalstr;
}

int main() {
    string s = "PAYPALISHIRING";
    int numRows = 3;
    cout << convert(s, numRows) << endl;
    return 0;
}
