#include "Lawyer.h"

int Lawyer::getLawyerID() {
    return LawyerID;
}

void Lawyer::setLawyerID(int id) {
    LawyerID = id;
}

std::string Lawyer::getFirstName() {
    return FirstName;
}

void Lawyer::setFirstName(std::string name) {
    FirstName = name;
}

std::string Lawyer::getLastName() {
    return LastName;
}

void Lawyer::setLastName(std::string name) {
    LastName = name;
}

std::string Lawyer::getEmail() {
    return Email;
}

void Lawyer::setEmail(std::string email) {
    Email = email;
}

std::string Lawyer::getPhone() {
    return Phone;
}

void Lawyer::setPhone(std::string phone) {
    Phone = phone;
}

std::string Lawyer::getSpecialization() {
    return Specialization;
}

void Lawyer::setSpecialization(std::string specialization) {
    Specialization = specialization;
}

float Lawyer::getWinRate() {
    return WinRate;
}

void Lawyer::setWinRate(float winRate) {
    WinRate = winRate;
}