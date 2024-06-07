#include <iostream>
using namespace std;

int Fibonacci(int);
void Output(int);

int main() {
    int numHolder;

    cout << "Input the position in the fibonacci sequence you want to know: ";
    cin >> numHolder;
    Output(numHolder);
}

int Fibonacci(int num) {
    if (num == 0) 
    return 0;
    else if (num == 1)
    return 1;

    return Fibonacci(num - 1) + Fibonacci(num - 2); 
}

void Output(int num) {
    int fibonacci;
    fibonacci = Fibonacci(num);

    cout << "\nFibonacci Sequence:\n";
    for (int i = 1; i <= num; i++) {
        cout << Fibonacci(i) << " ";
    }
    cout << "\n\n";

    switch (num) {
        case 1: 
        cout << "The " << num << "st Fibonacci number is " << fibonacci;
        break;
        case 2:
        cout << "The " << num << "nd Fibonacci number is " << fibonacci;
        break;
        case 3:
        cout << "The " << num << "rd Fibonacci number is " << fibonacci;
        break;
        default:
        cout << "The " << num << "th Fibonacci number is " << fibonacci;
        break;
    }
}