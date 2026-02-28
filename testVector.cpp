

#include "vector.h"

#include <algorithm>

using namespace vectors;

int main() {
    // simple test :>
    vector<int> a;
    for (int i = 10; i >=0 ; i--) a.push_back(i);
    for (int i = 0; i < 10; i++) std::cout << a[i] << std::endl;
}