#pragma once
#include <fstream>
#include <istream>
#include <sstream>
#include <iostream>
#include <tuple>
#include <string>
#include <vector>

class CapOneCSVReader {
public:
	// Constructors
	CapOneCSVReader(std::string file_name);

	// Reading data
	double getTotalAirfare();
    double getTotalCarRental();
    double getTotalDining();
    double getTotalEntertainment();
    double getTotalFeeIntCharge();
    double getTotalGasAutomotive();
    double getTotalHealthcare();
    double getTotalMerchandise();
    double getTotalOther();
    double getTotalOtherServices();
    double getTotalOtherTravel();
    double getTotalPaymentCredit();
    double getTotalUtilities();
    double getTotal();

private: 
	std::vector<std::vector<std::string>> dataVec;
	std::vector<std::tuple<std::string, double>> dataVecTuple;

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
    double sumTotal = 0;

    const std::string AIRFARE = "Airfare";
    const std::string CAR_RENTAL = "Car Rental";
    const std::string DINING = "Dining";
    const std::string ENTERTAINMENT = "Entertainment";
    const std::string FEE_INT_CHARGE = "Fee/Interest Charge";
    const std::string GAS_AUTOMOTIVE = "Gas/Automotive";
    const std::string HEALTHCARE = "Health Care";
    const std::string MERCHANDISE = "Merchandise";
    const std::string OTHER = "Other";
    const std::string OTHER_SERVICES = "Other Services";
    const std::string OTHER_TRAVEL = "Other Travel";
    const std::string PAYMENT_CREDIT = "Payment/Credit";
    const std::string UTILITIES = "Utilities";
};