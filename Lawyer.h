#ifndef LAWYER_H
#define LAWYER_H

#include <string>

class Lawyer {
private:
    int LawyerID;
    std::string FirstName;
    std::string LastName;
    std::string Email;
    std::string Phone;
    std::string Specialization;
    float WinRate;
public:
    int getLawyerID();
    void setLawyerID(int id);

    std::string getFirstName();
    void setFirstName(std::string name);

    std::string getLastName();
    void setLastName(std::string name);

    std::string getEmail();
    void setEmail(std::string email);

    std::string getPhone();
    void setPhone(std::string phone);

    std::string getSpecialization();
    void setSpecialization(std::string specialization);

    float getWinRate();
    void setWinRate(float winRate);
};

#endif  // LAWYER_H