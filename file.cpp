#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include<bits/stdc++.h>

using namespace std;

int main(){
	// Define an unordered_map with int as key and unordered_set of int as value
    std::unordered_map<int, std::unordered_set<int>> myMap;

    // Insert values into the map
    myMap[1].insert(10);
    myMap[1].insert(20);
    myMap[1].insert(30);

    myMap[2].insert(15);
    myMap[2].insert(25);
    myMap[2].insert(35);

    // Access and print values for a specific key
    int key = 1;
    std::cout << "Values for key " << key << ": ";
    for (const auto &value : myMap[key]) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
	return 0;
}