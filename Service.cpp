#include "Service.h"

int Service::getServiceID() {
    return ServiceID;
}

void Service::setServiceID(int id) {
    ServiceID = id;
}

std::string Service::getServiceName() {
    return ServiceName;
}

void Service::setServiceName(std::string name) {
    ServiceName = name;
}

std::string Service::getDescription() {
    return Description;
}

void Service::setDescription(std::string description) {
    Description = description;
}

float Service::getPrice() {
    return Price;
}

void Service::setPrice(float price) {
    Price = price;
}