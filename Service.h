#ifndef SERVICE_H
#define SERVICE_H

#include <string>

class Service {
private:
    int ServiceID;
    std::string ServiceName;
    std::string Description;
    float Price;
public:
    int getServiceID();
    void setServiceID(int id);

    std::string getServiceName();
    void setServiceName(std::string name);

    std::string getDescription();
    void setDescription(std::string description);

    float getPrice();
    void setPrice(float price);
};

#endif  // SERVICE_H