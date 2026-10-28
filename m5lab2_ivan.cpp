// CSC 134
// Ivan 
// 10/28/26


#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
double getLength();
double getWidth();
double getArea(double length, double width);
void displayData(double length, double width, double area);

int main() {
    double length = getLength();
    double width = getWidth();
    double area = getArea(length, width);

    displayData(length, width, area);

    return 0;
}

// Ask the user for the rectangle's length
double getLength() {
    double length;
    cout << "Enter the rectangle's length: ";
    cin >> length;
    return length;
}

// Ask the user for the rectangle's width
double getWidth() {
    double width;
    cout << "Enter the rectangle's width: ";
    cin >> width;
    return width;
}

// Calculate and return the rectangle's area
double getArea(double length, double width) {
    return length * width;
}

// Display the measurements and area
void displayData(double length, double width, double area) {
    cout << fixed << setprecision(2);
    cout << "\n===== Rectangle Information =====\n";
    cout << "Length: " << length << endl;
    cout << "Width:  " << width << endl;
    cout << "Area:   " << area << endl;
    cout << "=================================\n";
}
