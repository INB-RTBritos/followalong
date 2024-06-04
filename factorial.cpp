#include <iostream>
using namespace std;

int Factorial(int);

int main() {
    int numHolder;
    int factorial;

    cout << "Input a number to calculate its factorial: ";
    cin >> numHolder;

    factorial = Factorial(numHolder);
    cout << "The Factorial of " << numHolder << " is: " << factorial;
}

int Factorial(int num){
    if (num == 0) 
    return 1;

    return num * Factorial(num - 1);
}