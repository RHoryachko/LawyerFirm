#include "Case.h"
#include <iostream>

// Реалізація методів класу Case

int Case::getCaseID() { return CaseID; }
void Case::setCaseID(int id) { CaseID = id; }

std::string Case::getCaseName() { return CaseName; }
void Case::setCaseName(std::string name) { CaseName = name; }

int Case::getClientID() { return ClientID; }
void Case::setClientID(int id) { ClientID = id; }

int Case::getLawyerID() { return LawyerID; }
void Case::setLawyerID(int id) { LawyerID = id; }

std::string Case::getCaseStatus() { return CaseStatus; }
void Case::setCaseStatus(std::string status) { CaseStatus = status; }

std::string Case::getOutcome() { return Outcome; }
void Case::setOutcome(std::string outcome) { Outcome = outcome; }

std::string Case::getServicesProvided() { return ServicesProvided; }
void Case::setServicesProvided(std::string services) { ServicesProvided = services; }

std::string Case::getOpeningDate() { return OpeningDate; }
void Case::setOpeningDate(std::string date) { OpeningDate = date; }

std::string Case::getClosingDate() { return ClosingDate; }
void Case::setClosingDate(std::string date) { ClosingDate = date; }

void Case::displayCaseDetails() {
    std::cout << "Case ID: " << CaseID << "\n";
    std::cout << "Case Name: " << CaseName << "\n";
    std::cout << "Client ID: " << ClientID << "\n";
    std::cout << "Lawyer ID: " << LawyerID << "\n";
    std::cout << "Case Status: " << CaseStatus << "\n";
    std::cout << "Outcome: " << Outcome << "\n";
    std::cout << "Services Provided: " << ServicesProvided << "\n";
    std::cout << "Opening Date: " << OpeningDate << "\n";
    std::cout << "Closing Date: " << ClosingDate << "\n";
    std::cout << "-------------------------------------\n";
}