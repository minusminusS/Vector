

#include "vector.h"

#include <algorithm>

using namespace vectors;

int main() {
    // simple test :>
    vector<int> a;
    a.reserve(11);
    for (int i = 10; i >=0 ; i--) {
        a.push_back(i);
    }
    a.erase(9, 2);
    for (int i = 0; i < a.size(); i++) std::cout << a[i] << std::endl;
    a.clear();

}