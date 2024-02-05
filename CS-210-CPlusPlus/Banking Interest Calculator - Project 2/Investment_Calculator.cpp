/*
Domenick Dobbs
5-3 Project Two - CS-210-R3217 Programming Languages 24EW3
The purpose of this program is to be a calculator that can calculator investment growth over
time for different amounts, interest rates, and with/without monthly deposits.
*/


#include <iostream>
#include <iomanip>
using namespace std;

class Banking {
    double initialInvestment, annualInterest;
    int numYears;

public:
    Banking(double initInvestment, double annualInterest, int numYears): initialInvestment(initInvestment), annualInterest(annualInterest), numYears(numYears) {}

    void generateReport(double monthlyDeposit) {
        //This function will do the heavy lifting. From calculating to displaying
        //The following line will use a logical if else statement in one line. ? :
        cout << (monthlyDeposit > 0 ? "\nBalance and Interest With Additional Monthly Deposits\n" : "\nBalance and Interest Without Additional Monthly Deposits\n");
        cout << setw(10) << "Year" << setw(20) << "Year End Balance" << setw(25) << "Year End Earned Interest" << endl;

        double currentBalance = initialInvestment;

        for (int year = 1; year <= numYears; year++) {
            double yearlyInterest = 0;

            for (int month = 1; month <= 12; month++) {
                double monthlyInterest = (currentBalance + monthlyDeposit) * (annualInterest / 100 / 12);
                yearlyInterest += monthlyInterest;
                currentBalance += monthlyDeposit + monthlyInterest;
            }
            //The magic! Printing it all out row by row for each year in the for loop!
            cout << setw(10) << year << setw(20) << fixed << setprecision(2) << currentBalance << setw(25) << yearlyInterest << endl;
        }
    }
};

int main() {
    double initialInvestment, annualInterest, monthlyDeposit;
    int numYears;
    //formating to match requirements
    cout << "*******************************" << endl;
    cout << "********** Data Input *********" << endl;
    cout << "Initial Investment Amount: $";
    cin >> initialInvestment;
    cout << "Monthly Deposit: $";
    cin >> monthlyDeposit;
    cout << "Annual Interest: %";
    cin >> annualInterest;
    cout << "Number Of Years: ";
    cin >> numYears;

    Banking account(initialInvestment, annualInterest, numYears);

    account.generateReport(0); // Without monthly deposits
    account.generateReport(monthlyDeposit); // With specified monthly deposits

    return 0;
}
