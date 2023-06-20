#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
    int ClientID;
    std::string FirstName;
    std::string LastName;
    std::string Email;
    std::string Phone;
    std::string Address;
public:
    int getClientID();
    void setClientID(int id);

    std::string getFirstName();
    void setFirstName(std::string name);

    std::string getLastName();
    void setLastName(std::string name);

    std::string getEmail();
    void setEmail(std::string email);

    std::string getPhone();
    void setPhone(std::string phone);

    std::string getAddress();
    void setAddress(std::string address);
};

#endif  // CLIENT_H