#include <iostream>
using namespace std;

int FindMax(int[], int, int);
int FindMin(int[], int, int);

int main() {
    int size;
    int *num;
    int max, min;

    cout << "Enter the size of the array: ";
    cin >> size;
    num = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter element #" << i+1 << ": ";
        cin >> num[i];
    }
    cout << "\nElements in the array are: ";
    for (int i = 0; i < size; i++) {
        cout << num[i] << " ";
    }

    max = FindMax(num, 0, size - 1);
    min = FindMin(num, 0, size - 1);

    cout << "\nMaximum element is: " << max << "\n";
    cout << "Minimum element is: " << min << "\n\n";
}

int FindMax(int num[], int start, int end) {
    int mid, maxStart, maxEnd;
    if (start == end) 
    return num[start];

    mid = (start + end) / 2;
    maxStart = FindMax(num, start, mid);
    maxEnd = FindMax(num, mid + 1, end);

    return (maxStart > maxEnd) ? maxStart:maxEnd;
}

int FindMin(int num[], int start, int end) {
    int mid, minStart, minEnd;
    if (start == end) 
    return num[start];

    mid = (start + end) / 2;
    minStart = FindMin(num, start, mid);
    minEnd = FindMin(num, mid + 1, end);

    return (minStart < minEnd) ? minStart:minEnd;
}