#include "IncludeHelper.h"
#include "LC363.cpp"

int main() {
    unordered_map<int, int> a;
    a[0] = 2;
    a[1] ++;
    a[1] -= 2;
    cout << a[0] << " " << a[1] << endl;
    return 0;
}

