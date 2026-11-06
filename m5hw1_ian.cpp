// CSC 134 
// ivan
// 11/6/26



#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

// CSC 134 - M5HW1
// Gold Tier - Questions 1 through 6

double getNumber(string message) {
    double number;

    while (true) {
        cout << message;

        if (cin >> number) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }

        cout << "Please enter a valid number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int getWholeNumber(string message) {
    int number;

    while (true) {
        cout << message;

        if (cin >> number) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }

        cout << "Please enter a valid whole number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double getNonNegative(string message) {
    double number = getNumber(message);

    while (number < 0) {
        cout << "The value cannot be less than zero.\n";
        number = getNumber(message);
    }

    return number;
}

double getPositive(string message) {
    double number = getNumber(message);

    while (number <= 0) {
        cout << "The value must be greater than zero.\n";
        number = getNumber(message);
    }

    return number;
}

// Question 1 - Average Rainfall
void question1() {
    string month1, month2, month3;
    double rain1, rain2, rain3;

    cout << "Enter month: ";
    cin >> month1;
    rain1 = getNonNegative("Enter rainfall for " + month1 + ": ");

    cout << "Enter month: ";
    cin >> month2;
    rain2 = getNonNegative("Enter rainfall for " + month2 + ": ");

    cout << "Enter month: ";
    cin >> month3;
    rain3 = getNonNegative("Enter rainfall for " + month3 + ": ");

    double average = (rain1 + rain2 + rain3) / 3.0;

    cout << "The average rainfall for "
         << month1 << ", " << month2
         << ", and " << month3 << " is "
         << fixed << setprecision(2)
         << average << " inches.\n";

    cout << defaultfloat << setprecision(6);
}

// Question 2 - Volume of a Block
void question2() {
    double width, length, height, volume;

    width = getPositive("Enter width: ");
    length = getPositive("Enter length: ");
    height = getPositive("Enter height: ");

    volume = width * length * height;

    cout << "The volume of the block is "
         << volume << ".\n";
}

// Question 3 - Roman Numerals
void question3() {
    int number;
    string roman;

    number = getWholeNumber("Enter a number (1 - 10): ");

    while (number < 1 || number > 10) {
        cout << "Please enter a number from 1 through 10.\n";
        number = getWholeNumber("Enter a number (1 - 10): ");
    }

    switch (number) {
        case 1: roman = "I"; break;
        case 2: roman = "II"; break;
        case 3: roman = "III"; break;
        case 4: roman = "IV"; break;
        case 5: roman = "V"; break;
        case 6: roman = "VI"; break;
        case 7: roman = "VII"; break;
        case 8: roman = "VIII"; break;
        case 9: roman = "IX"; break;
        case 10: roman = "X"; break;
    }

    cout << "The Roman numeral version of "
         << number << " is " << roman << ".\n";
}

// Question 4 - Geometry Calculator
void question4() {
    int choice;
    double area;

    cout << "\nGeometry Calculator\n";
    cout << "1. Calculate the Area of a Circle\n";
    cout << "2. Calculate the Area of a Rectangle\n";
    cout << "3. Calculate the Area of a Triangle\n";
    cout << "4. Quit\n";

    choice = getWholeNumber("Enter your choice (1-4): ");

    if (choice == 1) {
        double radius;

        radius = getNonNegative("Enter the circle's radius: ");

        area = 3.14159 * radius * radius;

        cout << "The area is " << area << ".\n";
    }
    else if (choice == 2) {
        double length, width;

        length = getNonNegative("Enter the rectangle's length: ");
        width = getNonNegative("Enter the rectangle's width: ");

        area = length * width;

        cout << "The area is " << area << ".\n";
    }
    else if (choice == 3) {
        double base, height;

        base = getNonNegative("Enter the triangle's base: ");
        height = getNonNegative("Enter the triangle's height: ");

        area = base * height * 0.5;

        cout << "The area is " << area << ".\n";
    }
    else if (choice == 4) {
        cout << "Returning to the main menu.\n";
    }
    else {
        cout << "The valid choices are 1 through 4.\n";
    }
}

// Question 5 - Distance Traveled
void question5() {
    double speed;
    int hours;

    speed = getNonNegative(
        "What is the speed of the vehicle in mph? "
    );

    hours = getWholeNumber(
        "How many hours has it traveled? "
    );

    while (hours < 1) {
        cout << "Time must be at least 1 hour.\n";
        hours = getWholeNumber(
            "How many hours has it traveled? "
        );
    }

    cout << left << setw(10) << "Hour"
         << "Distance Traveled\n";

    cout << "--------------------------------\n";

    for (int hour = 1; hour <= hours; hour++) {
        cout << left << setw(10) << hour
             << speed * hour << "\n";
    }
}

// Question 6 - Main Menu
int main() {
    int choice;

    do {
        cout << "\nCSC 134 - M5HW1 Main Menu\n";
        cout << "1. Average Rainfall\n";
        cout << "2. Volume of a Block\n";
        cout << "3. Roman Numerals\n";
        cout << "4. Geometry Calculator\n";
        cout << "5. Distance Traveled\n";
        cout << "6. Exit\n";

        choice = getWholeNumber("Enter your choice (1-6): ");

        switch (choice) {
            case 1:
                question1();
                break;

            case 2:
                question2();
                break;

            case 3:
                question3();
                break;

            case 4:
                question4();
                break;

            case 5:
                question5();
                break;

            case 6:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Please choose a number from 1 through 6.\n";
        }

    } while (choice != 6);

    return 0;
}
