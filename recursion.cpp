#include <iostream>
using namespace std;

int ArraySum(int[], int);

int main() {
    int size;
    int *num;
    int sum;

    cout << "Enter the size of the array: ";
    cin >> size;
    num = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter element #" << i+1 << ": ";
        cin >> num[i];
    }

    sum = ArraySum(num, size);
    cout << "Sum of all elements: " << sum;
}

int ArraySum(int num[], int size) {
    if (size == 0)
    return 0;

    return num[size- 1] + ArraySum(num, size-1);
}
