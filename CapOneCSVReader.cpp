#include "CapOneCSVReader.h"

CapOneCSVReader::CapOneCSVReader(std::string file_name) {
    std::ifstream in(file_name);
    if (!in.is_open())
        std::cout << "ERROR: File Open" << '\n';

    if (in) {
        std::string line;

        while (getline(in, line)) {
            std::stringstream sep(line); // used for breaking words
            std::string datum; // to store individual words

            dataVec.push_back(std::vector<std::string>());

            while (getline(sep, datum, ',')) {
                dataVec.back().push_back(datum);
            }
        }
    }

    for (int i = 0; i < dataVec.size(); i++)
        dataVecTuple.push_back(make_tuple(dataVec[i][0], stod(dataVec[i][1])));

    in.close();
}

double CapOneCSVReader::getTotalAirfare() {
    for (int i = 0; i < dataVecTuple.size(); i++) {
        std::string category = std::get<0>(dataVecTuple[i]);

        if (category == AIRFARE)
            sumAirfare += std::get<1>(dataVecTuple[i]);
    }
    return sumAirfare;
}

double CapOneCSVReader::getTotalCarRental() {
    for (int i = 0; i < dataVecTuple.size(); i++) {
        std::string category = std::get<0>(dataVecTuple[i]);

        if (category == CAR_RENTAL)
            sumCarRental += std::get<1>(dataVecTuple[i]);
    }
    return sumCarRental;
}

double CapOneCSVReader::getTotalDining() {
    for (int i = 0; i < dataVecTuple.size(); i++) {
        std::string category = std::get<0>(dataVecTuple[i]);

        if (category == DINING)
            sumDining += std::get<1>(dataVecTuple[i]);
    }
    return sumDining;
}

double CapOneCSVReader::getTotalEntertainment() {
    for (int i = 0; i < dataVecTuple.size(); i++) {
        std::string category = std::get<0>(dataVecTuple[i]);

        if (category == ENTERTAINMENT)
            sumEntertainment += std::get<1>(dataVecTuple[i]);
    }
    return sumEntertainment;
}

double CapOneCSVReader::getTotalFeeIntCharge() {
    for (int i = 0; i < dataVecTuple.size(); i++) {
        std::string category = std::get<0>(dataVecTuple[i]);

        if (category == FEE_INT_CHARGE)
            sumFeeIntCharge += std::get<1>(dataVecTuple[i]);
    }
    return sumFeeIntCharge;
}

double CapOneCSVReader::getTotalGasAutomotive() {
    for (int i = 0; i < dataVecTuple.size(); i++) {
        std::string category = std::get<0>(dataVecTuple[i]);

        if (category == GAS_AUTOMOTIVE)
            sumGasAutomotive += std::get<1>(dataVecTuple[i]);
    }
    return sumGasAutomotive;
}

double CapOneCSVReader::getTotalHealthcare() {
    for (int i = 0; i < dataVecTuple.size(); i++) {
        std::string category = std::get<0>(dataVecTuple[i]);

        if (category == HEALTHCARE)
            sumHealthcare += std::get<1>(dataVecTuple[i]);
    }
    return sumHealthcare;
}

double CapOneCSVReader::getTotalMerchandise() {
    for (int i = 0; i < dataVecTuple.size(); i++) {
        std::string category = std::get<0>(dataVecTuple[i]);

        if (category == MERCHANDISE)
            sumMerchandise += std::get<1>(dataVecTuple[i]);
    }
    return sumMerchandise;
}

double CapOneCSVReader::getTotalOther() {
    for (int i = 0; i < dataVecTuple.size(); i++) {
        std::string category = std::get<0>(dataVecTuple[i]);

        if (category == OTHER)
            sumOther += std::get<1>(dataVecTuple[i]);
    }
    return sumOther;
}

double CapOneCSVReader::getTotalOtherServices() {
    for (int i = 0; i < dataVecTuple.size(); i++) {
        std::string category = std::get<0>(dataVecTuple[i]);

        if (category == OTHER_SERVICES)
            sumOtherServices += std::get<1>(dataVecTuple[i]);
    }
    return sumOtherServices;
}

double CapOneCSVReader::getTotalOtherTravel() {
    for (int i = 0; i < dataVecTuple.size(); i++) {
        std::string category = std::get<0>(dataVecTuple[i]);

        if (category == OTHER_TRAVEL)
            sumOtherTravel += std::get<1>(dataVecTuple[i]);
    }
    return sumOtherTravel;
}

double CapOneCSVReader::getTotalPaymentCredit() {
    for (int i = 0; i < dataVecTuple.size(); i++) {
        std::string category = std::get<0>(dataVecTuple[i]);

        if (category == PAYMENT_CREDIT)
            sumPaymentCredit += std::get<1>(dataVecTuple[i]);
    }
    return sumPaymentCredit;
}

double CapOneCSVReader::getTotalUtilities() {
    for (int i = 0; i < dataVecTuple.size(); i++) {
        std::string category = std::get<0>(dataVecTuple[i]);

        if (category == UTILITIES)
            sumUtilities += std::get<1>(dataVecTuple[i]);
    }
    return sumUtilities;
}

double CapOneCSVReader::getTotal() {
    for (int i = 0; i < dataVecTuple.size(); i++)
        sumTotal += std::get<1>(dataVecTuple[i]);
    return sumTotal;
}