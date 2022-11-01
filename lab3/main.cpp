#include <iostream>
#include "./myVector/myVector.h"
#include "./lib/sam.h"

using namespace std;

int main() {
    Sam a;
    a.PushBack(0.5);
    cout << a << endl;
}
