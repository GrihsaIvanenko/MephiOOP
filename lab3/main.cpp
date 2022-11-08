#include <iostream>
#include "./myVector/myVector.h"
#include "./lib/sam.h"
#include <vector>

using namespace std;

void printMenu(const vector<string>& options) {
    for (int i = 0; i < options.size(); ++i)
        cout << to_string(i) << ". " << options[i] << endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
}

int main() {
    Sam a;
    vector<string> options = {
        "exit",
        "create emptySam",
        "create Sam with size",
        "create Sam with MyVector",
        "create Sam with otherSam",
        "Reset",
        "PushBack rand",
        "PushBack numer",
        "check []",
        "Mean()",
        "increaseSizeTo",
        "Select from to",
        "GetSize",
        "print"
    };
    while (true) {
        printMenu(options);
        int ans; cin >> ans;
        if (ans == 0) {
            break;
        } else if (ans == 1) {
            Sam b;
            a = move(b);
        } else if (ans == 2) {
            unsigned int size;
            cin >> size;
            Sam b(size);
            a = move(b);
        } else if (ans == 3) {
            unsigned int size;
            cin >> size;
            MyVector v(size);
            for (int i = 0; i < size; ++i)
                cin >> v[i];
            Sam b(v);
            a = move(b);
        } else if (ans == 4) {
            Sam b(a);
            a = move(b);
        } else if (ans == 5) {
            a.Reset();
        } else if (ans == 6) {
            a.PushBack();
        } else if (ans == 7) {
            double toPushBack;
            cin >> toPushBack;
            a.PushBack(toPushBack);
        } else if (ans == 8) {
            cout << "Enter number in [0, " << a.Size() - 1 << "]\n";
            int id;
            cin >> id;
            cout << a[id] << endl;
        } else if (ans == 9) {
            cout << a.Mean() << endl;
        } else if (ans == 10) {
            unsigned int newSize;
            cin >> newSize;
            a.IncreaseSizeTo(newSize);
        } else if (ans == 11) {
            double from, to;
            cin >> from >> to;
            Sam ans = a.SelectFromTo(from, to);
            cout << ans << endl;
        } else if (ans == 12) {
            cout << a.Size() << endl;
        } else if (ans == 13) {
            cout << a << endl;
        } else {
            cout << "WROND COMMAND!\n";
        }
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
    }
    return 0;
}
