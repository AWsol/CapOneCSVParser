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

    /*
    // create vector of doubles to store the debits
    vector<double> vDebits;
    string debit;
    for (int i = 0; i < dataVec.size(); i++)
    {
        debit = dataVec[i][1];
        vDebits.push_back(stod(debit));
    }
    */

    /*
    // sums the debits
    double sumDebits = 0;
    for (auto elem : vDebits)
        sumDebits += elem;
    */

    // store the data into a vector<tuple<string, double>>
    vector<tuple<string, double>> myTupleVec;
    for (int i = 0; i < dataVec.size(); i++) {
        //string sDebit = dataVec[i][1];
        //double dDebit = stod(dataVec[i][1]);
        //myTupleVec.push_back(make_tuple(dataVec[i][0], vDebits[i]));
        myTupleVec.push_back(make_tuple(dataVec[i][0], stod(dataVec[i][1])));
    }

    // print the tuple
    cout << "\nFinancial Data:\n";
    for (const auto& i : myTupleVec) {
        cout << "Category: " << get<0>(i) << '\n';
        cout << "Debit: $" << get<1>(i) << '\n';
        cout << endl;
    }
    
    in.close();
    std::system("pause");
}


   /*
    for (auto row : dataVec) {
        for (auto datum : row) {
            cout << datum;
        }
    }
   */

