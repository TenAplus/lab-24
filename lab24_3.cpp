#include<iostream>
#include<set>  // Include the set container

using namespace std;

// Function to count unique elements in an array
int count(int data[], int size) {
    set<int> uniqueElements;  // Set to store unique elements
    
    // Insert each element from the array into the set
    for (int i = 0; i < size; i++) {
        uniqueElements.insert(data[i]);
    }
    
    // Return the size of the set, which is the number of unique elements
    return uniqueElements.size();
}

