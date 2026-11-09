
/*
CSC 134
M6T1 - Loops and Arrays
Ivan
11/9/26
*/

#include <iostream>
#include <string>
using namespace std;

// Function Declarations
void method1();
void method2();

// main
int main() {
    // Count cars per day, two different ways
    method1();
    method2();

    return 0;
}

void method1() {
    string item = "cars";
    cout << "Count how many " << item
         << " were seen each day." << endl;

    // count for five days
    const int SIZE = 5;
    int count;
    int total = 0;
    double average;

    // Loop without an array
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter cars for day " << i + 1 << ": ";
        cin >> count;
        total = total + count;
    }

    average = total / 5.0;

    cout << "Total cars: " << total << endl;
    cout << "Average per day: " << average << endl;
}

void method2() {
    string item = "cars";
    cout << "\nCount how many " << item
         << " were seen each day using an array." << endl;

    const int SIZE = 5;
    int cars[SIZE];
    int total = 0;
    double average;

    // Loop with an array
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter cars for day " << i + 1 << ": ";
        cin >> cars[i];
        total = total + cars[i];
    }

    average = total / 5.0;

    cout << "Total cars: " << total << endl;
    cout << "Average per day: " << average << endl;

    cout << "\nCars for each day:" << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << "Day " << i + 1 << ": "
             << cars[i] << endl;
    }

    // Simple bar chart
    cout << "\nBar Chart:" << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << "Day " << i + 1 << ": ";
        for (int j = 0; j < cars[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }
}
