#include <iostream>
#include <string>
using namespace std;


string convert(string s, int numRows) {
    int len = s.size();
    string finalstr;
    
    // Special case handling for numRows = 1 or when string is empty
    if (numRows == 1 || len == 0)
        return s;
    
    // Iterate through each row in the zigzag pattern
    for (int i = 0; i < numRows; ++i) {
        int j = 0;
        while (true) {
            int idx1 = (numRows - 1) * 2 * j - i; // index for downward movement
            int idx2 = (numRows - 1) * 2 * j + i; // index for upward movement
            
            // Check if idx1 is within range and not equal to idx2 to avoid duplicate characters
            if (idx1 >= 0 && idx1 < len && idx1 != idx2)
                finalstr.push_back(s[idx1]);
            
            // Check if idx2 is within range
            if (idx2 >= 0 && idx2 < len)
                finalstr.push_back(s[idx2]);
            
            // Increment j for the next cycle
            j++;
            
            // Break the loop if both indices are out of bounds
            if (idx1 >= len && idx2 >= len)
                break;
        }finalstr.push_back('_');
    }
    
    return finalstr;
}



int main(){
	string a = "PAYPALISHIRING";
	cout<<convert(a, 3);
	return 0;
}