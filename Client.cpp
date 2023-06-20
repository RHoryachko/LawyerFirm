#include "Client.h"

int Client::getClientID() {
    return ClientID;
}

void Client::setClientID(int id) {
    ClientID = id;
}

std::string Client::getFirstName() {
    return FirstName;
}

void Client::setFirstName(std::string name) {
    FirstName = name;
}

std::string Client::getLastName() {
    return LastName;
}

void Client::setLastName(std::string name) {
    LastName = name;
}

std::string Client::getEmail() {
    return Email;
}

void Client::setEmail(std::string email) {
    Email = email;
}

std::string Client::getPhone() {
    return Phone;
}

void Client::setPhone(std::string phone) {
    Phone = phone;
}

std::string Client::getAddress() {
    return Address;
}

void Client::setAddress(std::string address) {
    Address = address;
}