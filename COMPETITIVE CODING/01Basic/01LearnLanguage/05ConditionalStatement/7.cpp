#include <iostream>
#include <string>
using namespace std;

int main() {
    string n;
    cin >> n;

    int pos = n.find('.');

    if (pos == string::npos) {
        cout << "int " << n;
    }
    else {
        string integerPart = n.substr(0, pos);
        string decimalPart = n.substr(pos + 1);

        double dec = stod("0." + decimalPart);

        if (dec == 0) {
            //cout << "this function is running\n";

            cout << "int " << integerPart;
        }
        else
            cout << "float " << integerPart << " " << dec;
    }

    return 0;
}