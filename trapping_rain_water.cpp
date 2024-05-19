#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int len = height.size();
    vector<int> leftmax(len);
    vector<int> rightmax(len);
    leftmax[0] = height[0];
    rightmax[len-1] = height[len-1];

    for(int i = 1, j =len-2; i<len; i++, j--){
        if(height[i] > leftmax[i-1]){
            leftmax[i] = height[i];
        }
        else{
            leftmax[i] = leftmax[i-1];
        }
        if(height[j] > rightmax[j+1]){
            rightmax[j] = height[j];
        }
        else{
            rightmax[j] = rightmax[j+1];
        }
    }
    int total_water = 0;
    for(int i = 0; i<len; i++){
        total_water += min(leftmax[i],rightmax[i]) - height[i];
    }
    return total_water;
}

int main(int argc, char const *argv[])
{
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout<<"Water trapped: "<<trap(height);
	return 0;
}