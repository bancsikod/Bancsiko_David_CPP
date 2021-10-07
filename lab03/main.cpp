#include "List.h"

int main() {

    List x;
    x.insertFirst(5);
    x.insertFirst(8);
    x.insertFirst(9);
    cout << "exists = " << x.exists(8);
    cout << endl;
    x.print();
    x.removeFirst();
    cout << endl;
    x.print();
    cout << endl;
    cout << x.empty();
    x.removeFirst();
    x.removeFirst();
    cout << endl;
    cout << "exists = " <<x.exists(8);
    cout << endl;
    cout << x.empty();
    x.removeFirst();
    x.removeFirst();
    x.print();
    x.empty();

    cout << endl;
    int n;
    cin >> n;
    int d;
    for (int i = 0; i < n; ++i) {
        cin >> d;
        x.insertFirst(d);
    }
    cout << endl;
    x.print();

    cout << endl << x.size();
    cout << endl;
    x.remove(5,List::DeleteFlag::EQUAL);
    x.print();

    return 0;
}
