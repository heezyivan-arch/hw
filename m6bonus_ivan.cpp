// CSC 134
// Ivan
// M6Bonus
// 11/16/26



#include <iostream>
#include <string>
using namespace std;

// M6BONUS - Haunted Mansion Escape
// AI Assistance: I used ChatGPT to help customize the
// room names, descriptions, and key interaction.
// using regular arrays, directions, and a hidden key.

// Directions
enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
    NUM_DIRECTIONS = 4
};

const string DIRECTION_NAMES[NUM_DIRECTIONS] = {
    "north", "east", "south", "west"
};

// Rooms
enum Room {
    ENTRANCE_HALL = 0,
    BEDROOM = 1,
    LIBRARY = 2,
    EXIT_DOOR = 3,
    BASEMENT = 4,
    NUM_ROOMS = 5
};

int main() {

    // Room names
    string roomNames[NUM_ROOMS] = {
        "Entrance Hall",
        "Haunted Bedroom",
        "Secret Library",
        "Locked Exit",
        "Underground Basement"
    };

    // Room descriptions
    string roomDescriptions[NUM_ROOMS] = {
        "You enter a dark mansion. The front door closes behind you.",
        "An old bedroom with broken furniture. You hear footsteps.",
        "A secret library filled with dusty books and strange symbols.",
        "You find the exit door, but it is locked.",
        "A cold basement with a small golden key on the floor."
    };

    // Room connections
    int connections[NUM_ROOMS][NUM_DIRECTIONS];

    // Set all connections to -1
    for (int i = 0; i < NUM_ROOMS; i++) {
        for (int j = 0; j < NUM_DIRECTIONS; j++) {
            connections[i][j] = -1;
        }
    }

    // Entrance Hall
    connections[ENTRANCE_HALL][NORTH] = BEDROOM;
    connections[ENTRANCE_HALL][EAST] = LIBRARY;
    connections[ENTRANCE_HALL][WEST] = EXIT_DOOR;

    // Bedroom
    connections[BEDROOM][SOUTH] = ENTRANCE_HALL;

    // Library
    connections[LIBRARY][WEST] = ENTRANCE_HALL;
    connections[LIBRARY][SOUTH] = BASEMENT;

    // Exit Door
    connections[EXIT_DOOR][EAST] = ENTRANCE_HALL;

    // Basement
    connections[BASEMENT][NORTH] = LIBRARY;

    // Game variables
    int currentRoom = ENTRANCE_HALL;
    bool gameRunning = true;
    bool hasKey = false;

    cout << "================================" << endl;
    cout << "      HAUNTED MANSION ESCAPE     " << endl;
    cout << "================================" << endl;

    cout << "You are trapped inside a haunted mansion!" << endl;
    cout << "Find the golden key and escape!" << endl;
    cout << "Commands: north, south, east, west," << endl;
    cout << "take, open, help, quit" << endl;

    // Main game loop
    while (gameRunning) {

        cout << "\n-----------------------------" << endl;
        cout << "You are in the " << roomNames[currentRoom] << endl;
        cout << roomDescriptions[currentRoom] << endl;

        // Show key if player is in basement
        if (currentRoom == BASEMENT && !hasKey) {
            cout << "You see a golden key!" << endl;
        }

        // Show available exits
        cout << "Exits: ";
        bool hasExits = false;

        for (int dir = 0; dir < NUM_DIRECTIONS; dir++) {
            if (connections[currentRoom][dir] != -1) {
                cout << DIRECTION_NAMES[dir] << " ";
                hasExits = true;
            }
        }

        if (!hasExits) {
            cout << "none";
        }

        cout << endl;

        // Player input
        string command;
        cout << "\nWhat would you like to do? ";
        if (!(cin >> command)) {
            break;
        }

        // Movement commands
        int direction = -1;

        if (command == "north" || command == "n") {
            direction = NORTH;
        }
        else if (command == "east" || command == "e") {
            direction = EAST;
        }
        else if (command == "south" || command == "s") {
            direction = SOUTH;
        }
        else if (command == "west" || command == "w") {
            direction = WEST;
        }

        if (direction != -1) {
            if (connections[currentRoom][direction] != -1) {
                currentRoom = connections[currentRoom][direction];
            }
            else {
                cout << "You can't go that way." << endl;
            }
        }

        // Take the key
        else if (command == "take") {
            if (currentRoom == BASEMENT && !hasKey) {
                hasKey = true;
                cout << "You picked up the golden key!" << endl;
            }
            else {
                cout << "There is nothing to take." << endl;
            }
        }

        // Open exit door
        else if (command == "open") {
            if (currentRoom == EXIT_DOOR) {
                if (hasKey) {
                    cout << "\nYou used the golden key!" << endl;
                    cout << "The door opens and you escape!" << endl;
                    cout << "CONGRATULATIONS! YOU WIN!" << endl;
                    gameRunning = false;
                }
                else {
                    cout << "The door is locked. Find a key!" << endl;
                }
            }
            else {
                cout << "There is no door to open here." << endl;
            }
        }

        // Help command
        else if (command == "help") {
            cout << "Available commands:" << endl;
            cout << "north (n), south (s)" << endl;
            cout << "east (e), west (w)" << endl;
            cout << "take - Pick up an item" << endl;
            cout << "open - Open the exit door" << endl;
            cout << "quit - Exit the game" << endl;
        }

        // Quit command
        else if (command == "quit" || command == "q") {
            gameRunning = false;
        }

        // Invalid command
        else {
            cout << "I don't understand that command." << endl;
        }
    }

    cout << "\nThanks for playing!" << endl;

    return 0;
}
