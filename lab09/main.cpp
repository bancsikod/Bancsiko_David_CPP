#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() {
    cout << "--------------------" << endl;

    cout << "1.";
    vector<string> fruits {
            "melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"
    };

    auto berry = find_if(fruits.begin(),fruits.end(), [](const string &value) {
        return value.find("berry") != string::npos;
    });
    cout << " Contains \"berry\": " << ((berry != fruits.end()) ? "Yes" : "No") << endl;
    cout << "--------------------" << endl;


    cout << "2.";
    vector<int> numsZ { 2, 0, 4, 6, 8};

    auto even = all_of(numsZ.begin(),numsZ.end(), [](const int value) {
        return value % 2 == 0;
    });
    cout << " Even: " << (even ? "Yes" : "No") << endl;
    cout << "--------------------" << endl;


    cout << "3.";
    vector<int> numsZ2 { 2, 0, 4, 6, 8};
    auto print = [](const int &n) { cout << " " << n;};
    auto multi = [](int &value) {value*=2;};

    cout << "\t*before*:";
    for_each(numsZ2.begin(),numsZ2.end(), print);
    for_each(numsZ2.begin(),numsZ2.end(), multi);
    cout << "\n\t*after* :";
    for_each(numsZ2.begin(),numsZ2.end(), print);
    cout << endl;
    cout << "--------------------" << endl;


    cout << "4.";
    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    int sum = 0;
    for_each(months.begin(), months.end(), [&sum](const string &month) {
       month.length() == 5 ? sum++ : 1;
    });
    cout << " Num of months with 5 letters: " << sum << endl;
    cout << "--------------------" << endl;


    cout << "5.a.";
    vector<int> numsZ3 { 2, 0, 4, -6, 4, 21, 11, 32, 3, 6, 10, 12, 10};
    cout << "\t*before*:";
    for_each(numsZ3.begin(),numsZ3.end(), print);
    sort(numsZ3.begin(),numsZ3.end(), [](const int &a, const int &b) {
        return a>b;
    });
    cout << "\n\t*after* :";
    for_each(numsZ3.begin(),numsZ3.end(), print);
    cout << endl;
    cout << "--------------------" << endl;

    cout << "5.b.";
    greater<> great;
    vector<int> numsZ4 { 2, 11, -32, 3, 6, 10, 12, 10};
    cout << "\t*before*:";
    for_each(numsZ4.begin(),numsZ4.end(), print);
    sort(numsZ4.begin(),numsZ4.end(), great);
    cout << "\n\t*after* :";
    for_each(numsZ4.begin(),numsZ4.end(), print);
    cout << endl;
    cout << "--------------------" << endl;


    cout << "6.";
    vector< pair<string,double> > avgMonth {
            {"January", 12}, {"February", 13}, {"March", 11.7}, {"April", 15.1}, {"May", 13.5}, {"June",15},
            {"July",12.2}, {"August",12.5}, {"September",12.1}, {"October",11.6}, {"November",12.2}, {"December",13}
    };


    auto printPair = [](const pair<string,double> &avgM) {
        cout << " {" << avgM.first << ", " << avgM.second << "}";
    };

    cout << " ***Before***:" << endl;
    for_each(avgMonth.begin(), avgMonth.end(), printPair);
    sort(avgMonth.begin(), avgMonth.end(), [](const pair<string,double> &a, const pair<string,double> &b) {
        return a.second < b.second;
    }) ;
    cout << endl << "   ***After*** :" << endl;
    for_each(avgMonth.begin(), avgMonth.end(), printPair);
    cout << endl;
    cout << "--------------------" << endl;


    cout << "7.";
    vector<int> numsZ5 { 2, 0, 4, 6, 4, -21, 11, -32, 3, -6, -10, -12, 10};

    cout << " *Before*:";
    for_each(numsZ5.begin(), numsZ5.end(), print);
    sort(numsZ5.begin(), numsZ5.end(), [](const int &a, const int &b) {
        return abs(a) < abs(b);
    });
    cout << "\n   *After* :";
    for_each(numsZ5.begin(), numsZ5.end(), print);
    cout << endl;
    cout << "--------------------" << endl;


    cout << "8.";
///    vector<string> months {
///            "January", "February", "March", "April", "May", "June",
///            "July", "August", "September", "October", "November", "December" };
    for_each(months.begin(), months.end(), [](string &value) {
        value[0] = tolower(value[0]);
    });
    cout << " [l]owercase:";
    for_each(months.begin(), months.end(), [](const auto &value) {
        cout << " " << value;
    });
    cout << endl;
    cout << "--------------------" << endl;


    cout << "9.";
    string abc = "abcdefghijklmnopqrstuvwxyz";
    random_shuffle(abc.begin(), abc.end());
    cout << " Random ABC: " << abc << endl;
    unordered_map<char, int> wierdAbc;
    wierdAbc.clear();
    for (int i = 0; i < abc.size(); ++i) {
        wierdAbc[abc[i]] = i;
    }
    cout << endl << "*Before*:";
    for_each(months.begin(), months.end(), [](const string &m) {
        cout << " " << m;
    });
    sort(months.begin(), months.end(), [&wierdAbc](const string &a, const string &b) {
        for (int i = 0; i < min(a.size(), b.size()); ++i) {
            if (wierdAbc[a[i]] == wierdAbc[b[i]])
                continue;
            return wierdAbc[a[i]] < wierdAbc[b[i]];
        }
        return a.size() < b.size();
    });
    cout << endl << "*After* :";
    for_each(months.begin(), months.end(), [](const string &m) {
        cout << " " << m;
    });
    cout << endl;
    cout << "--------------------" << endl;

    return 0;
}
