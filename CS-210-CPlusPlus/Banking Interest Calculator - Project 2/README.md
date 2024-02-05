# Banking Interest Calculator

**This C++ program simulates the growth of an investment account over time, considering both interest and optional monthly deposits.**

**Key Features:**

- **Custom `Banking` class to model an investment account**
- **Calculates interest compounded monthly**
- **Generates detailed reports with year-end balances and earned interest**
- **Demonstrates the impact of regular deposits on investment growth**

**How to Use:**

1. **Compile the program:**

  -bash
  `g++ banking_program.cpp -o banking_program`

2. **Run the program:**

    `./banking_program`

3. **Provide the following information when prompted:**

  -Initial investment amount
  -Monthly deposit (optional)
  -Annual interest rate
  -Number of years

4. **The program will generate two reports:**

  -Balance and interest without additional monthly deposits
  -Balance and interest with the specified monthly deposits

**Possible Enhancements:**

  -Add error handling for invalid user input
  -Incorporate different interest compounding frequencies (e.g., daily, quarterly)
  -Allow for variable interest rates
  -Create options for different investment types (e.g., savings accounts, CDs)
  -Implement a graphical user interface (GUI) for a more user-friendly experience
