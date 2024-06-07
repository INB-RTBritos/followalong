#include <iostream>
using namespace std;

int Factorial(int); // function declaration
                    // declaring as int to make the function recursion call become false at some point

int main() {
    int numHolder; // number from main to be passed as parameter to the function
    int factorial; 

    cout << "Input a number to calculate its factorial: ";
    cin >> numHolder;

    factorial = Factorial(numHolder); // putting the functions returned value to the variable to display
    cout << "The Factorial of " << numHolder << " is: " << factorial;
}

int Factorial(int num){
    if (num == 0) // will be the condition to make the recursive call stop
    return 0;
    else if (num == 1)
    return 1; 

    return num * Factorial(num - 1); // cannot be declared as num-- because the parameter expects an int so you
                                    // need to use something of similar variable type               
                                    //  returning the num but uses the value of the function to be part of the 
                                    //  formula and eventually goes to first condition one it hits zero
                                   
}