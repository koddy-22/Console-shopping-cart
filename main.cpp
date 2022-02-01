#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    int qnty,  instlmnt, totalCost = 0;
    float totalCostWithTax;
    char choice, proceed, instlmntOption, taxDisplay;
    string name;
    int prices [4] = {250, 50, 25, 150};
    string month [12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    const float tax = 1.18;
    ofstream bill;

    cout <<" --------------------------------------------- \n";
    cout <<"|                Shopping cart                |\n";
    cout <<" --------------------------------------------- \n";
    cout << "Please enter your name below\n--> ";
    getline(cin,name);
    cout << "\nMr(s) " << name << ", You can start shopping from the menu below\n\n";

    do {
        do{
            cout <<" ---------------------------------------------- \n";
            cout <<"|                     Menu                     |\n";
            cout <<"|----------------------------------------------|\n";
            cout <<"|[1] A manufacture Laptop               : 250$ |\n";
            cout <<"|[2] A manufacture Headphones           :  50$ |\n";
            cout <<"|[3] A manufacture Keyboard & mouse set :  25$ |\n";
            cout <<"|[4] A manufacture Monitor              : 150$ |\n";
            cout <<"|[5] Proceed to checkout                       |\n";
            cout <<"|[] Proceed to checkout                       |\n";
            cout <<"|[0] Cancel all and exit                       |\n";
            cout <<" ---------------------------------------------- \n\n\n";
            cout <<"Your choice --> ";
            cin >> choice;
            cout << endl;
        }
        while (!(choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5' || choice == '0'));
        if (choice == '0') {
            bill.open("test.txt", ofstream::out | ofstream::trunc);
            bill.close();
            return 0;
        }
        if (choice == '5') {
            break;
        }
        do {
            cout << "Enter the quantity\n--> ";
            cin >> qnty;
            cout << endl;
        }
        while (qnty < 0);

        int intChoice = (int) (choice - '0');
        totalCost = totalCost + prices[intChoice-1] * qnty;
        totalCostWithTax = totalCost * tax;
        cout << "Your current total cost is " << totalCost << endl;

        do {
            cout << "[1] Continue shopping\n[2] Proceed to checkout\n--> ";
            cin >> proceed;
            cout << endl;
        }
        while (!(proceed == '1' || proceed == '2'));
    }
    while (proceed == '1');
    
    bill.open("bill.txt");
    bill << "Customer name : " << name << "\n\n";
    bill << "Total cost    : " << totalCostWithTax << endl;

    cout << "We're adding %18 tax \n[1] Continue\n--> ";
    cin >> taxDisplay;
    if (taxDisplay == '1') {
        cout << "Total cost = " << totalCostWithTax << endl;
        cout << "Would you like to have an installement payment? \n[1] Yes\n[2] No\n--> ";
        cin >> instlmntOption;
        cout << endl;

        if (instlmntOption == '1') {
            do {
                cout << "Enter the amount of months you will pay in\n--> ";
                cin >> instlmnt;
                cout << endl;
            }
            while (instlmnt < 1 || instlmnt > 12);

            float monthlyPayment = totalCostWithTax / instlmnt;
            cout <<"Your monthly payment will be "<<monthlyPayment<<" for "<<instlmnt<<" months "<<endl;
            cout << "Payment schedule: "<<endl;
            bill << "Payment schedule: "<<endl;
            cout <<"------------------------"<<endl;
            bill <<"------------------------"<<endl;

            for (int i = 1; i <= instlmnt; i++) {
                cout << month[i-1] <<" : "<<monthlyPayment<<endl;
                bill << month[i-1] <<" : "<<monthlyPayment<<endl;
            }
        }
    }
    cout << endl << endl;
    bill.close();
    cout << "Thanks for shopping." << endl;
    return 0;
}