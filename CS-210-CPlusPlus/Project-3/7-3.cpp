/*
Domenick Dobbs
7-3 Project Three
Program will display a menu, display inventory number of an item in the first option - based on a txt file.
Item 2 will display frequency of all items
Item 3 will create a rudimentary histogram of the item frequencies to provide a visual aspect to the numbers.
The assignment did not ask for me to make things case sensitive but when I tried to anyway, the file did not run.
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

// Function Declarations
void displayMenu();
void processChoice(int choice, map<string, int>& itemFrequencies);
void loadDataFromFile(map<string, int>& itemFrequencies);
void displayItemFrequency(const map<string, int>& itemFrequencies, const string& item);
void displayAllFrequencies(const map<string, int>& itemFrequencies);
void displayHistogram(const map<string, int>& itemFrequencies);
void writeBackupData(const map<string, int>& itemFrequencies);

//Trying to make everything case insensitive
string toLower(const string& str) {
    string lowerStr = str;
    for (char& characterCase : lowerStr) {
        characterCase = tolower(characterCase);
    }
    return lowerStr;
} //this is not working for some reason.


void displayMenu() {
    cout << "1. Search for an item frequency" << endl;
    cout << "2. Display frequency of all items" << endl;
    cout << "3. Display histogram" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

void displayItemFrequency(const map<string, int>& itemFrequencies, const string& item) {
    map<string, int>::const_iterator iterator_item = itemFrequencies.find(item);
    if (iterator_item != itemFrequencies.end()) {
        cout << iterator_item->first << " frequency: " << iterator_item->second << endl;
    } else {
        cout << "Item not found." << endl;
    }
}

void processChoice(int choice, map<string, int>& itemFrequencies) {
    string item; // Variable to store the item name for option 1
    switch (choice) {
        case 1:
            cout << "Enter the item name: ";
            cin >> item; // Read the item name from user

            // Convert to lowercase
            //item = toLower(item);
            displayItemFrequency(itemFrequencies, item); // Pass both the map and the item name
            break;
        case 2:
            displayAllFrequencies(itemFrequencies);
            break;
        case 3:
            displayHistogram(itemFrequencies);
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}


void loadDataFromFile(map<string, int>& itemFrequencies) {
    // Should read from the txt file I made in the same folder. May need to play around with file pathways
    ifstream inFile("CS210_Project_Three_Input_File.txt");
    string item;
    int frequency;

    while (inFile >> item >> frequency) {
        // Convert item to lowercase before storing it in the map
        itemFrequencies[item] = frequency;
        //itemFrequencies[toLower(item)] = frequency;
    }
    //Close the file
    inFile.close();

    // Write backup data
    writeBackupData(itemFrequencies);
}



void displayAllFrequencies(const map<string, int>& itemFrequencies) {
    for (map<string, int>::const_iterator iterator_item = itemFrequencies.begin(); iterator_item != itemFrequencies.end(); ++iterator_item) {
        cout << iterator_item->first << ": " << iterator_item->second << endl;
    }
}

void displayHistogram(const map<string, int>& itemFrequencies) {
    for (map<string, int>::const_iterator iterator_item = itemFrequencies.begin(); iterator_item != itemFrequencies.end(); ++iterator_item) {
        cout << iterator_item->first << " ";
        for (int integer = 0; integer < iterator_item->second; ++integer) {
            cout << "*";
        }
        cout << endl;
    }
}

void writeBackupData(const map<string, int>& itemFrequencies) {
    ofstream outFile("frequency.dat");
    for (map<string, int>::const_iterator iterator_item = itemFrequencies.begin(); iterator_item != itemFrequencies.end(); ++iterator_item) {
        outFile << iterator_item->first << " " << iterator_item->second << endl;
    }
    outFile.close();
}


int main() {
    map<string, int> itemFrequencies;
    int choice;

    // Load data from file and write backup data
    loadDataFromFile(itemFrequencies);

    do {
        displayMenu();
        cin >> choice;
        processChoice(choice, itemFrequencies);
    } while (choice != 4);

    return 0;
}
