#include <iostream>
#include "./lib_curve/curve.h"

using namespace std;

vector<string> menu = {
    "0. SetA",
    "1. SetL",
    "2. GetA",
    "3. GetL",
    "4. GetYbyX",
    "5. DistByFi",
    "6. RadiysCurvature",
    "7. SquareOfLoop",
    "8. GetInflectionPoints"
};

void printMenu() {
    for (auto& x : menu)
        cout << x << '\n';
}

vector<string> OK_MENU = {
    "0. Continue",
    "1. Finish"
};

bool readOK() {
    for (auto& x : OK_MENU)
        cout << x << '\n';
    int x;
    cin >> x;
    if (x == 0)
        return true;
    if (x == 1)
        return false;
    return readOK();
}

ostream& operator <<(ostream& out, Point& p) {
    return cout << "(" << p.x << ", " << p.y << ")";
}

ostream& operator <<(ostream& out, DoubleOrError& x) {
    if (x.errorCode == OK) {
        return cout << x.x;
    } else {
        if (x.errorCode == ERROR_NO_Y_BY_X)
            return cout << "ERROR NO Y BY X";
        else if (x.errorCode == ERROR_INVALID_FI)
            return cout << "ERROR INVALID FI";
        else if (x.errorCode == ERROR_NO_X_BY_FI)
            return cout << "ERROR NO X BY FI";
    }
    return out;
}

int main() {
   KonhoidNicomed a;
   while (true) {
        printMenu();
        int status; cin >> status;
        if (0 <= status && status < menu.size()) {
            if (status == 0) {
               double new_A;
               cout << "Enter new A" << endl;
               cin >> new_A;
               a.SetA(new_A);
            } else if (status == 1) {
               double new_L;
               cout << "Ener new L" << endl;
               cin >> new_L;
               a.SetL(new_L);
            } else if (status == 2) {
                cout << "A = " << a.GetA() << endl;   
            } else if (status == 3) {
                cout << "L = " << a.GetL() << endl;
            } else if (status == 4) {
                double x;
                cout << "Enter x" << endl;
                cin >> x;
                DoubleOrError res_l = a.GetYbyX(x);
                cout << "res_l: " << res_l << endl;
            } else if (status == 5) {
                double fi;
                cout << "Enter fi" << endl;
                cin >> fi;
                DoubleOrError res_l = a.DistByFi(fi, 0);
                DoubleOrError res_r = a.DistByFi(fi, 1);
                cout << "left is " << res_l << endl;
                cout << "right is " << res_r << endl;
            } else if (status == 6) {
                double l = a.RadiusCurvature(0);
                double r = a.RadiusCurvature(1);
                cout << "left is " << l << endl;
                cout << "right is " << r << endl;
            } else if (status == 7) {
                cout << a.SquareOfLoop() << endl;
            } else if (status == 8) {
               vector<Point> res = a.GetInflectionPoints();
               for (auto& x : res)
                    cout << x << endl;
            }
        }
        if (!readOK())
            break;
        system("clear");
   }
   return 0;
}
