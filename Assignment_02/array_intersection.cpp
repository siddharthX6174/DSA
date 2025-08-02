#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr_1[n], arr_2[n], ans[n];
    int index = 0;

    for (int i = 0; i < n; i++) cin >> arr_1[i];
    for (int j = 0; j < n; j++) cin >> arr_2[j];

    // Find common elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr_1[i] == arr_2[j]) {
                ans[index++] = arr_1[i];
                arr_2[j] = 100000001; // mark as used
                break; // move to next element in arr_1
            }
        }
    }

    // Sort the result using simple selection sort
    for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
            if (ans[i] > ans[j]) {
                int temp = ans[i];
                ans[i] = ans[j];
                ans[j] = temp;
            }
        }
    }

    // Print result in correct format
    cout << "[";
    for (int i = 0; i < index; i++) {
        cout << ans[i];
        if (i != index - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
