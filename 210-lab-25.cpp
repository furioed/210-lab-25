// COMSC-210 | Lab 25 | Mamadou Sissoko
// IDE used: Visual Studio Code
// Data structure races

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <algorithm>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// Read data into container
template <typename T>
long long raceRead(T& container, const vector<string>& data) {
    auto start = high_resolution_clock::now();
    for (const auto& s : data)
        container.insert(container.end(), s); // vector/list
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

// Specialization for set
long long raceRead(set<string>& st, const vector<string>& data) {
    auto start = high_resolution_clock::now();
    for (const auto& s : data)
        st.insert(s);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

// Sort vector/list
template <typename T>
long long raceSort(T& container) {
    auto start = high_resolution_clock::now();
    container.sort(); // list
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

int main() {
    

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/