// CapOneCSVParser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <istream>
#include <sstream>
#include <iostream>
#include <tuple>
#include <string>
#include <vector>

using namespace std;

const static string AIRFARE = "Airfare";
const static string CAR_RENTAL = "Car Rental";
const static string DINING = "Dining";
const static string ENTERTAINMENT = "Entertainment";
const static string FEE_INT_CHARGE = "Fee/Interest Charge";
const static string GAS_AUTOMOTIVE = "Gas/Automotive";
const static string HEALTHCARE = "Health Care";
const static string MERCHANDISE = "Merchandise";
const static string OTHER = "Other";
const static string OTHER_SERVICES = "Other Services";
const static string OTHER_TRAVEL = "Other Travel";
const static string PAYMENT_CREDIT = "Payment/Credit";
const static string UTILITIES = "Utilities";

int main() {

    ifstream in("CapOneData2019.csv");
    if (!in.is_open())
        cout << "ERROR: File Open" << '\n';

    vector<vector<string>> dataVec;
    if (in) {
        string line;

        while (getline(in, line)) {
            stringstream sep(line); // used for breaking words
            string datum; // to store individual words

            dataVec.push_back(vector<string>());

            while (getline(sep, datum, ',')) {
                dataVec.back().push_back(datum);
            }
        }
    }

    double sumAirfare = 0;
    double sumCarRental = 0;
    double sumDining = 0;
    double sumEntertainment = 0;
    double sumFeeIntCharge = 0;
    double sumGasAutomotive = 0;
    double sumHealthcare = 0;
    double sumMerchandise = 0;
    double sumOther = 0;
    double sumOtherServices = 0;
    double sumOtherTravel = 0;
    double sumPaymentCredit = 0;
    double sumUtilities = 0;
    double sumInvalid = 0;


    vector<tuple<string, double>> myTupleVec;
    for (int i = 0; i < dataVec.size(); i++)
        myTupleVec.push_back(make_tuple(dataVec[i][0], stod(dataVec[i][1])));

    for (int i = 0; i < myTupleVec.size(); i++)
    {
        string category = get<0>(myTupleVec[i]);

        if(category == AIRFARE)
            sumAirfare += get<1>(myTupleVec[i]);
        else if(category == CAR_RENTAL)
            sumCarRental += get<1>(myTupleVec[i]);
        else if (category == DINING)
            sumDining += get<1>(myTupleVec[i]);
        else if (category == ENTERTAINMENT)
            sumEntertainment += get<1>(myTupleVec[i]);
        else if (category == FEE_INT_CHARGE)
            sumFeeIntCharge += get<1>(myTupleVec[i]);
        else if (category == GAS_AUTOMOTIVE)
            sumGasAutomotive += get<1>(myTupleVec[i]);
        else if (category == HEALTHCARE)
            sumHealthcare += get<1>(myTupleVec[i]);
        else if (category == MERCHANDISE)
            sumMerchandise += get<1>(myTupleVec[i]);
        else if (category == OTHER)
            sumOther += get<1>(myTupleVec[i]);
        else if (category == OTHER_SERVICES)
            sumOtherServices += get<1>(myTupleVec[i]);
        else if (category == OTHER_TRAVEL)
            sumOtherTravel += get<1>(myTupleVec[i]);
        else if (category == PAYMENT_CREDIT)
            sumPaymentCredit += get<1>(myTupleVec[i]);
        else if (category == UTILITIES)
            sumUtilities += get<1>(myTupleVec[i]);
        else
            sumInvalid += get<1>(myTupleVec[i]);
    }

    cout << "Debits by Category" << '\n'
        << "----------------------------" << '\n'
        << endl;

    cout << "Airfare: \t\t$" << sumAirfare << '\n'
        << "Car Rental: \t\t$" << sumCarRental << '\n'
        << "Dining: \t\t$" << sumDining << '\n'
        << "Entertainment: \t\t$" << sumEntertainment << '\n'
        << "Fee/Interest Charge: \t$" << sumFeeIntCharge << '\n'
        << "Gas/Automotive: \t$" << sumGasAutomotive << '\n'
        << "Healthcare: \t\t$" << sumHealthcare << '\n'
        << "Merchandise: \t\t$" << sumMerchandise << '\n'
        << "Other: \t\t\t$" << sumOther << '\n'
        << "Other Services: \t$" << sumOtherServices << '\n'
        << "Other Travel: \t\t$" << sumOtherTravel << '\n'
        << "Payment/Credit: \t$" << sumPaymentCredit << '\n'
        << "Utilities: \t\t$" << sumUtilities << '\n'
        << "Invalid: \t\t$" << sumInvalid << '\n'
        << '\n' << "Total Spent: \t\t$" << sumAirfare + sumCarRental + sumDining + sumEntertainment + sumFeeIntCharge + sumGasAutomotive + sumHealthcare
        + sumMerchandise + sumOther + sumOtherServices + sumOtherTravel + sumPaymentCredit + sumUtilities + sumInvalid << '\n'
        << endl;

    /*
    cout << "\nFinancial Data:\n";
    for (const auto& i : myTupleVec) {
        cout << "Category: " << get<0>(i) << '\n';
        cout << "Debit: $" << get<1>(i) << '\n';
        cout << endl;
    }
    */

    in.close();
    std::system("pause");
}

