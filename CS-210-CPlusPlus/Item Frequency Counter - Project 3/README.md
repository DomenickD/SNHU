# Item Frequency Counter

This C++ program is a simple item frequency counter that reads data from a file, allows users to search for item frequencies, and displays the frequency of all items and a histogram.

## Features

- Search for the frequency of a specific item.
- Display the frequency of all items.
- Display a histogram showing the frequency distribution of items.
- Automatically saves data to a backup file.

## Prerequisites

Before running the program, make sure you have:

- A C++ compiler installed on your system.

## Usage

1. **Compile the program using a C++ compiler:**

   `g++ -o item_frequency_counter item_frequency_counter.cpp`

2. **Run the program:**

     `./item_frequency_counter`

3. **Follow the on-screen instructions to interact with the program.**

# Module 8 Journal Assignment
   - Summarize the project and what problem it was solving.


     The project is a C++ program designed to solve the problem of counting and managing the frequency of items stored in a data file. It provides a menu-driven interface for users to search for item frequencies, display frequencies of all items, generate a histogram, and save data to a backup file. The program reads data from a file named `CS210_Project_Three_Input_File.txt` and allows users to interact with the data efficiently.
   
   - What did you do particularly well?


     The code was well structured with very modular functions so it will be easy to understand and easy to maintain.
     The program has a user interface that accomplishes its job with no issues.
     It also handles the input and output data files effectively.
   
   - Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?


     My case insensitivty function failed to work correctly. It also does not Account for more robust error handling which means that improper use can break the program. 
   
   - Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

     The most challenging was the case insensitivty function. When applying it, the program kept displaying only a blank screen. I will be coming back to redo the function in the future.
     VSCode as many built in tools to help with program development but I often use CodeBlocks for the C languages just out of habit. Sometimes switching IDEs helps in remembering the rules and syntax of each langauge I have learned. 
   
   - What skills from this project will be particularly transferable to other projects or course work?


   Modular programming and code organization, file input/output handling, working with C++ data structures (maps), and menu-driven user interface design (Although if I spent more time on the menu, it would look much better).
   
   - How did you make this program maintainable, readable, and adaptable?

   
   Maintainability: The code is well-organized into functions, making it easy to modify, extend, and understand in the future.
   Readability: The code includes comments and follows coding conventions like camelCase variable names, enhancing readability.
   Adaptability: The program is adaptable as it can be easily extended to include more features or handle different types of data files. It could benefit from improved error handling to adapt to various scenarios better though.
   
