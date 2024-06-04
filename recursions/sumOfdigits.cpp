#include <iostream>
using namespace std;

int SumOfDigits(int);

int main() {
    int numHolder;
    int sum;

    cout << "Enter a number: ";
    cin >> numHolder;

    sum = SumOfDigits(numHolder);
    cout << "The sum of digits of " << numHolder << " is: " << sum;
}

int SumOfDigits(int num) {
    if (num >= 0 && num <= 9)
    return num;

    return (num % 10) + SumOfDigits(num / 10);
}