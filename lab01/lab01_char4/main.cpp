#include "function.h"

int main() {

    string buff;

    getline(cin,buff);
    cout << capitalizeWords(buff);
    cout << endl;

    getline(cin,buff);
    cout << capitalizeWords(buff);
    cout << endl;

    getline(cin,buff);
    cout << capitalizeWords(buff);
    cout << endl;

    return 0;
}
