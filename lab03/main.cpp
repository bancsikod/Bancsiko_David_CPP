#include "Stack.h"

int main() {
    List x;

    auto n = 0;
    auto y = 0;
    cout << "n=";
    cin >> n;
    cout << "read array elements:";
    for (int i = 0; i < n; ++i) {
        cin >> y;
        x.insertFirst(y);
    }

    cout << "Search for:";
    cin >> y;
    auto string = (x.exists(y)) ? " is found" : " is not found";
    cout << y << string << endl;

    cout << "size of list = " << x.size() << endl;
    string = (x.empty()) ? "The list is empty" : "The list is not empty";
    cout << string << endl;

    x.print();
    cout << endl;
    cout << "Removing the first element" << endl;
    x.removeFirst();
    x.print();
    cout << endl;

    cout << "Remove first element less than/equal to/greater than:";
    cin >> y;
    x.remove(y,List::DeleteFlag::LESS);
    cout << "less" << endl;
    x.print();
    cout << endl;
    x.remove(y,List::DeleteFlag::EQUAL);
    cout << "equal" << endl;
    x.print();
    cout << endl;
    x.remove(y,List::DeleteFlag::GREATER);
    cout << "greater" << endl;
    x.print();
    cout << endl;

    cout << "emptying the list" << endl;
    for (int i = 0; i < x.size(); ++i) {
        x.removeFirst();
    }
    cout << ((x.empty()) ? "succes" : "failed") << endl;

    cout << "\n\nStack class:\n";
    Stack a;
    cout << "n=";
    cin >> n;
    cout << "read stack elements:";
    for (int i = 0; i < n; ++i) {
        cin >> y;
        a.push(y);
    }
    cout << (a.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
    cout << "pop elements from stack" << endl;
    for (int i = 0; i < n; ++i) {
        cout << a.pop() << endl;
    }
    cout << (a.isEmpty() ? "Stack is empty" : "Stack is not empty") << "\n\n";

    return 0;
}
