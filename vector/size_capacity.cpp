//Matthew Muller 1037502 Software Lab 2 Exercise 2.1

/* The output of lines 4 and 5 should both be zero, because there hasn't been any memory
 * allocated for the ints to be stored in the vector yet and no ints have been added yet. 
 * Once the vector begins being filled with integers it will increase in size (the number 
 * of elements stored) and it will dynamically change its capacity to accomodate more 
 * elements. The capacity (or pre-allocated space in memory) doubles each time the size 
 * catches up to the capacity.
 * */

// size_capacity.cpp
// Vector size versus capacity

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec;
    cout << "vec: size: " << vec.size() 
         << " capacity: " << vec.capacity() << endl;

    for(int i = 0; i < 24; i++) {
        vec.push_back(i);
        cout << "vec: size: " << vec.size() 
             << " capacity: " << vec.capacity() << endl;
    }

    return 0;
}
