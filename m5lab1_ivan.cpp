// CSC 134
// Ivan
//  10/26/26

#include <iostream>
using namespace std;

// Name: YOUR NAME
// M5LAB1 - Spooky House

void main_menu();
void choice_front_door();
void choice_back_door();
void choice_go_home();
void open_cellar();
void escape_house();

int main() {
main_menu();
return 0;
}

void main_menu() {
int choice = 0;

while (choice != 4) {
cout << "\nWelcome to the Spooky House!\n";
cout << "1. Front door\n";
cout << "2. Back door\n";
cout << "3. Go home\n";
cout << "4. Quit\n";
cin >> choice;

if (choice == 1)
choice_front_door();
else if (choice == 2)
choice_back_door();
else if (choice == 3)
choice_go_home();
else if (choice == 4)
cout << "Goodbye!\n";
else
cout << "Invalid choice!\n";
}
}

void choice_front_door() {
cout << "The front door is locked!\n";
choice_back_door();
}

void choice_back_door() {
int choice;

cout << "You find the back door.\n";
cout << "1. Enter cellar\n2. Go home\n";
cin >> choice;

if (choice == 1)
open_cellar();
else
choice_go_home();
}

void choice_go_home() {
cout << "You went home safely. The End!\n";
}

void open_cellar() {
int choice;

cout << "You hear a scary noise!\n";
cout << "1. Run\n2. Stay\n";
cin >> choice;

if (choice == 1)
escape_house();
else
cout << "You got trapped! Game Over!\n";
}

void escape_house() {
cout << "You escaped the house! You Win!\n";
}
