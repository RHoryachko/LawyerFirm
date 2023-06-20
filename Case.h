#ifndef CASE_H
#define CASE_H

#include <string>

class Case {
private:
    int CaseID;
    std::string CaseName;
    int ClientID;
    int LawyerID;
    std::string CaseStatus;
    std::string Outcome;
    std::string ServicesProvided;
    std::string OpeningDate;
    std::string ClosingDate;

public:
    Case();
    Case(int caseID, const std::string& caseName, int clientID, int lawyerID, const std::string& caseStatus,
        const std::string& outcome, const std::string& servicesProvided, const std::string& openingDate,
        const std::string& closingDate);

    int getCaseID() const;
    void setCaseID(int caseID);

    const std::string& getCaseName() const;
    void setCaseName(const std::string& caseName);

    int getClientID() const;
    void setClientID(int clientID);

    int getLawyerID() const;
    void setLawyerID(int lawyerID);

    const std::string& getCaseStatus() const;
    void setCaseStatus(const std::string& caseStatus);

    const std::string& getOutcome() const;
    void setOutcome(const std::string& outcome);

    const std::string& getServicesProvided() const;
    void setServicesProvided(const std::string& servicesProvided);

    const std::string& getOpeningDate() const;
    void setOpeningDate(const std::string& openingDate);

    const std::string& getClosingDate() const;
    void setClosingDate(const std::string& closingDate);
};

#endif  // CASE_H