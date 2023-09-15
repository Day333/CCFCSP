#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a, b;
    cin >> a >> b;

    double area = M_PI * pow(a + b, 2);

    cout << fixed << setprecision(10) << area << endl;

    return 0;
}
