#include "Polynomial.h"

int main() {
    /**try for this:
p1: f(x) = { 2 0 1 3 };
p2: f(x) = { 0 1 3 2 };
     */
    Polynomial p1(3, nullptr);
    cout << "p1(x) =";
    cin >> p1;
    cout << "p1: " <<p1;
    Polynomial p2(3, nullptr);
    cout << "p2(x) =";
    cin >> p2;
    cout << "p2: " <<p2;
    cout << "*****************************************************\n";
    cout << "p1 degree:" << p1.degree() << endl;
    int x;
    cout << "enter x to evaluate:";
    cin >> x;
    cout << "p1 evaluate: " << p1.evaluate(x) << endl;
    cout << "p1 derivative: " << p1.derivative();
    cout << "-p1: " << -p1;
    cout << "p1+p2: " << p1+p2;
    cout << "p1-p2: " << p1-p2;
    cout << "p1*p2: " << p1*p2;

    return 0;
}
