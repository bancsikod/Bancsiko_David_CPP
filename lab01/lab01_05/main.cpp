
#include "function.h"

int main() {

    int n;
    cout << "n= ";
    cin >> n;
    auto *arr = new double (n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    pair<double, double> min_max = max2(arr,n);
    cout << min_max.first << " " << min_max.second;

    return 0;
}
