#include "BinarySearchTree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void loadCourses(BinarySearchTree& bst, const std::string& fileName) {
    std::ifstream file(fileName);
    std::string line;

    if (!file.is_open()) {
        std::cout << "Failed to open file: " << fileName << std::endl;
        return;
    }

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string item;
        std::vector<std::string> tokens;

        // Split the line by commas
        while (getline(ss, item, ',')) {
            tokens.push_back(item);
        }

        if (tokens.size() < 2) { // Basic validation
            std::cout << "Invalid line format: " << line << std::endl;
            continue;
        }

        std::string courseNumber = tokens[0];
        std::string title = tokens[1];
        std::vector<std::string> prerequisites;

        // Convert the course number to uppercase for consistency
        for (char &c : courseNumber) c = toupper(c);

        // Starting from the third element, if any, are prerequisites
        for (size_t i = 2; i < tokens.size(); ++i) {
            prerequisites.push_back(tokens[i]);
        }

        Course course(courseNumber, title, prerequisites);
        bst.insertCourse(course);
    }

    std::cout << "Courses loaded successfully." << std::endl;
}


void printMenu() {
    std::cout << "\nWelcome to the course planner.\n";
    std::cout << "1. Load Data Structure.\n";
    std::cout << "2. Print Course List.\n";
    std::cout << "3. Print Course.\n";
    std::cout << "9. Exit\n";
    std::cout << "What would you like to do? ";
}

int main() {
    BinarySearchTree bst;
    std::string choice;
    std::string fileName;

    while (true) {
        printMenu();
        std::cin >> choice;

        if (choice == "1") {
            // std::cout << "Enter filename: ";
            // std::cin >> fileName;
            std::string fileName = "course.csv";
            std::cout << "Loading courses from " << fileName << "..." << std::endl;
            loadCourses(bst, fileName);

        } else if (choice == "2") { //print all the courses
            bst.printCourseList();

        } else if (choice == "3") { // will ask user what course. now it is case insensitive
            std::string courseNumber;
            std::cout << "Enter course number: ";
            std::cin >> courseNumber;
            for (char &c : courseNumber) c = toupper(c); //beacuase of this magic right here
            bst.printCourseInformation(courseNumber);
        } else if (choice == "9") {
            std::cout << "Thank you for using the course planner!\n";
            break;
        } else {
            std::cout << choice << " is not a valid option.\n";
        }
    }

    return 0;
}
