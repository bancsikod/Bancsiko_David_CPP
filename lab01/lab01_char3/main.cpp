#include "function.h"

int main() {

    string text = "Abcz 123 zcba";
    cout << code(text) << endl;
    cout << decode(code(text));

    return 0;
}
