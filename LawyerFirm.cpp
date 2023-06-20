#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h> 
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include "Case.h"
#include "Client.h"
#include "Lawyer.h"
#include "Service.h"


bool authenticateUser(std::string username, std::string password) {
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::ResultSet* res;

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306/LawyerFirmDB", "root", "qwerty");

    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT * FROM users WHERE Username = '" + username + "' AND Password = '" + password + "'");

    bool isAuthenticated = res->rowsCount() > 0;

    delete res;
    delete stmt;
    delete con;

    return isAuthenticated;
}

std::string getUserType(std::string username) {
    std::string userType;

    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::ResultSet* res;

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306/LawyerFirmDB", "root", "qwerty");

    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT UserType FROM Users WHERE Username = '" + username + "'");

    if (res->next()) {
        userType = res->getString("UserType");
    }

    delete res;
    delete stmt;

    return userType;
}

void viewAllClients() {
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::ResultSet* res;

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306/LawyerFirmDB", "root", "qwerty");

    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT * FROM Clients");

    while (res->next()) {
        std::cout << "ID: " << res->getInt("ClientID") << "\n";
        std::cout << "First Name: " << res->getString("FirstName") << "\n";
        std::cout << "Last Name: " << res->getString("LastName") << "\n";
        std::cout << "Email: " << res->getString("Email") << "\n";
        std::cout << "Phone: " << res->getString("Phone") << "\n";
        std::cout << "Address: " << res->getString("Address") << "\n";
        std::cout << "-------------------------------------" << "\n";
    }

    delete res;
    delete stmt;
    delete con;
}

void viewAllLawyers() {
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::ResultSet* res;

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306/LawyerFirmDB", "root", "qwerty");

    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT * FROM Lawyers");

    while (res->next()) {
        std::cout << "ID: " << res->getInt("LawyerID") << "\n";
        std::cout << "First Name: " << res->getString("FirstName") << "\n";
        std::cout << "Last Name: " << res->getString("LastName") << "\n";
        std::cout << "Email: " << res->getString("Email") << "\n";
        std::cout << "Phone: " << res->getString("Phone") << "\n";
        std::cout << "Specialization: " << res->getString("Specialization") << "\n";
        std::cout << "Win Rate: " << res->getDouble("WinRate") << "\n";
        std::cout << "-------------------------------------" << "\n";
    }

    delete res;
    delete stmt;
    delete con;
}

void viewAllCases() {
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::ResultSet* res;

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306/LawyerFirmDB", "root", "qwerty");

    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT * FROM Cases");

    while (res->next()) {
        std::cout << "Case ID: " << res->getInt("CaseID") << "\n";
        std::cout << "Case Name: " << res->getString("CaseName") << "\n";
        std::cout << "Client ID: " << res->getInt("ClientID") << "\n";
        std::cout << "Lawyer ID: " << res->getInt("LawyerID") << "\n";
        std::cout << "Case Status: " << res->getString("CaseStatus") << "\n";
        std::cout << "Outcome: " << res->getString("Outcome") << "\n";
        std::cout << "Services Provided: " << res->getString("ServicesProvided") << "\n";
        std::cout << "Opening Date: " << res->getString("OpeningDate") << "\n";
        std::cout << "Closing Date: " << res->getString("ClosingDate") << "\n";
        std::cout << "-------------------------------------" << "\n";
    }

    delete res;
    delete stmt;
    delete con;
}

void viewAllServices() {
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::ResultSet* res;

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306/LawyerFirmDB", "root", "qwerty");

    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT * FROM Services");

    while (res->next()) {
        std::cout << "Service ID: " << res->getInt("ServiceID") << "\n";
        std::cout << "Service Name: " << res->getString("ServiceName") << "\n";
        std::cout << "Description: " << res->getString("Description") << "\n";
        std::cout << "Price: " << res->getDouble("Price") << "\n";
        std::cout << "-------------------------------------" << "\n";
    }

    delete res;
    delete stmt;
    delete con;
}


void addNewClient() {
    std::string firstName, lastName, email, phone, address;

    std::cout << "Enter First Name: ";
    std::cin >> firstName;
    std::cout << "Enter Last Name: ";
    std::cin >> lastName;
    std::cout << "Enter Email: ";
    std::cin >> email;
    std::cout << "Enter Phone: ";
    std::cin >> phone;
    std::cout << "Enter Address: ";
    std::cin >> address;

    sql::mysql::MySQL_Driver* driver;
    std::unique_ptr<sql::Connection> con;
    std::unique_ptr<sql::PreparedStatement> pstmt;

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con.reset(driver->connect("tcp://127.0.0.1:3306/LawyerFirmDB", "root", "qwerty"));

        pstmt.reset(con->prepareStatement("INSERT INTO Clients(FirstName, LastName, Email, Phone, Address) VALUES (?, ?, ?, ?, ?)"));
        pstmt->setString(1, firstName);
        pstmt->setString(2, lastName);
        pstmt->setString(3, email);
        pstmt->setString(4, phone);
        pstmt->setString(5, address);
        pstmt->executeUpdate();

        std::cout << "New client added successfully.\n";
    }
    catch (sql::SQLException& e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
    con->close();
}

void addNewService() {
    std::string serviceName, description;
    float price;

    std::cout << "Enter Service Name: ";
    std::cin >> serviceName;
    std::cout << "Enter Description: ";
    std::cin.ignore();  // ignoring the newline character in the input stream
    std::getline(std::cin, description);
    std::cout << "Enter Price: ";
    std::cin >> price;

    sql::mysql::MySQL_Driver* driver;
    std::unique_ptr<sql::Connection> con;
    std::unique_ptr<sql::PreparedStatement> pstmt;

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con.reset(driver->connect("tcp://127.0.0.1:3306/LawyerFirmDB", "root", "qwerty"));

        pstmt.reset(con->prepareStatement("INSERT INTO Services(ServiceName, Description, Price) VALUES (?, ?, ?)"));
        pstmt->setString(1, serviceName);
        pstmt->setString(2, description);
        pstmt->setDouble(3, price);
        pstmt->executeUpdate();

        std::cout << "New service added successfully.\n";
    }
    catch (sql::SQLException& e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
    con->close();
}


void addNewCase() {
    std::string caseName, outcome, servicesProvided, openingDate, closingDate;
    int clientID, lawyerID;
    std::string caseStatus;

    std::cout << "Enter Case Name: ";
    std::cin.ignore();
    std::getline(std::cin, caseName);

    std::cout << "Enter Client ID: ";
    std::cin >> clientID;

    std::cout << "Enter Lawyer ID: ";
    std::cin >> lawyerID;

    std::cout << "Enter Case Status (Open, Closed, In Progress, On Hold): ";
    std::cin.ignore();
    std::getline(std::cin, caseStatus);

    std::cout << "Enter Outcome (Win, Defeat, NULL): ";
    std::cin.ignore();
    std::getline(std::cin, outcome);

    std::string outcomeValue;

    if (outcome == "Win" || outcome == "Defeat" || outcome == "NULL") {
        outcomeValue = outcome;
    }
    else {
        outcomeValue = "NULL";
    }

    std::cout << "Enter Services Provided: ";
    std::cin.ignore();
    std::getline(std::cin, servicesProvided);

    std::cout << "Enter Opening Date (YYYY-MM-DD): ";
    std::cin >> openingDate;

    std::cout << "Enter Closing Date (YYYY-MM-DD): ";
    std::cin >> closingDate;

    sql::mysql::MySQL_Driver* driver;
    std::unique_ptr<sql::Connection> con;
    std::unique_ptr<sql::PreparedStatement> pstmt;

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con.reset(driver->connect("tcp://127.0.0.1:3306/LawyerFirmDB", "root", "qwerty"));

        pstmt.reset(con->prepareStatement("INSERT INTO Cases(CaseName, ClientID, LawyerID, CaseStatus, Outcome, ServicesProvided, OpeningDate, ClosingDate) VALUES (?, ?, ?, ?, ?, ?, ?, ?)"));
        pstmt->setString(1, caseName);
        pstmt->setInt(2, clientID);
        pstmt->setInt(3, lawyerID);
        pstmt->setString(4, caseStatus);
        pstmt->setString(5, outcomeValue);
        pstmt->setString(6, servicesProvided);
        pstmt->setString(7, openingDate);
        pstmt->setString(8, closingDate);
        pstmt->executeUpdate();

        std::cout << "New case added successfully.\n";
    }
    catch (sql::SQLException& e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
}


void addNewLawyer() {
    std::string firstName, lastName, email, phone, specialization;
    float winRate;

    std::cout << "Enter First Name: ";
    std::cin >> firstName;
    std::cout << "Enter Last Name: ";
    std::cin >> lastName;
    std::cout << "Enter Email: ";
    std::cin >> email;
    std::cout << "Enter Phone: ";
    std::cin >> phone;
    std::cout << "Enter Specialization: ";
    std::cin >> specialization;
    std::cout << "Enter Win Rate: ";
    std::cin >> winRate;

    sql::mysql::MySQL_Driver* driver;
    std::unique_ptr<sql::Connection> con;
    std::unique_ptr<sql::PreparedStatement> pstmt;

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con.reset(driver->connect("tcp://127.0.0.1:3306/LawyerFirmDB", "root", "qwerty"));

        pstmt.reset(con->prepareStatement("INSERT INTO Lawyers(FirstName, LastName, Email, Phone, Specialization, WinRate) VALUES (?, ?, ?, ?, ?, ?)"));
        pstmt->setString(1, firstName);
        pstmt->setString(2, lastName);
        pstmt->setString(3, email);
        pstmt->setString(4, phone);
        pstmt->setString(5, specialization);
        pstmt->setDouble(6, winRate);
        pstmt->executeUpdate();

        std::cout << "New lawyer added successfully.\n";
    }
    catch (sql::SQLException& e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
}

void deleteClient() {
    int clientID;

    std::cout << "Enter Client ID: ";
    std::cin >> clientID;

    sql::mysql::MySQL_Driver* driver;
    std::unique_ptr<sql::Connection> con;
    std::unique_ptr<sql::PreparedStatement> pstmt;

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con.reset(driver->connect("tcp://127.0.0.1:3306/LawyerFirmDB", "root", "qwerty"));

        pstmt.reset(con->prepareStatement("DELETE FROM Clients WHERE ClientID = ?"));
        pstmt->setInt(1, clientID);
        pstmt->executeUpdate();

        std::cout << "Client deleted successfully.\n";
    }
    catch (sql::SQLException& e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
}

void deleteLawyer() {
    int lawyerID;

    std::cout << "Enter Lawyer ID: ";
    std::cin >> lawyerID;

    sql::mysql::MySQL_Driver* driver;
    std::unique_ptr<sql::Connection> con;
    std::unique_ptr<sql::PreparedStatement> pstmt;

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con.reset(driver->connect("tcp://127.0.0.1:3306/LawyerFirmDB", "root", "qwerty"));

        // Delete cases associated with the lawyer
        pstmt.reset(con->prepareStatement("DELETE FROM Cases WHERE LawyerID = ?"));
        pstmt->setInt(1, lawyerID);
        pstmt->executeUpdate();

        // Delete the lawyer
        pstmt.reset(con->prepareStatement("DELETE FROM Lawyers WHERE LawyerID = ?"));
        pstmt->setInt(1, lawyerID);
        pstmt->executeUpdate();

        std::cout << "Lawyer deleted successfully.\n";
    }
    catch (sql::SQLException& e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
}

void deleteServices() {
    int serviceID;

    std::cout << "Enter Service ID: ";
    std::cin >> serviceID;

    sql::mysql::MySQL_Driver* driver;
    std::unique_ptr<sql::Connection> con;
    std::unique_ptr<sql::PreparedStatement> pstmt;

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con.reset(driver->connect("tcp://127.0.0.1:3306/LawyerFirmDB", "root", "qwerty"));

        // Check if the service is used in any case
        pstmt.reset(con->prepareStatement("SELECT COUNT(*) AS count FROM Cases WHERE ServicesProvided LIKE ?"));
        pstmt->setString(1, "%" + std::to_string(serviceID) + "%");
        sql::ResultSet* res = pstmt->executeQuery();

        if (res->next()) {
            int count = res->getInt("count");

            if (count > 0) {
                std::cout << "The service is used in " << count << " case(s). Cannot delete the service.\n";
                delete res;
                return;
            }
        }
        delete res;

        // Delete the service
        pstmt.reset(con->prepareStatement("DELETE FROM Services WHERE ServiceID = ?"));
        pstmt->setInt(1, serviceID);
        pstmt->executeUpdate();

        std::cout << "Service deleted successfully.\n";
    }
    catch (sql::SQLException& e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
}

void deleteCase() {
    int caseID;

    std::cout << "Enter Case ID: ";
    std::cin >> caseID;

    sql::mysql::MySQL_Driver* driver;
    std::unique_ptr<sql::Connection> con;
    std::unique_ptr<sql::PreparedStatement> pstmt;

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con.reset(driver->connect("tcp://127.0.0.1:3306/LawyerFirmDB", "root", "qwerty"));

        // Delete all related records
        pstmt.reset(con->prepareStatement("DELETE FROM Cases WHERE CaseID = ?"));
        pstmt->setInt(1, caseID);
        pstmt->executeUpdate();

        std::cout << "Case deleted successfully.\n";
    }
    catch (sql::SQLException& e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
}


void showMenuAdmin() {
    int choice;

    do {
        std::cout << "========== Menu ==========\n";
        std::cout << "1. View Clients\n";
        std::cout << "2. View Lawyers\n";
        std::cout << "3. View Cases\n";
        std::cout << "4. View Services\n";
        std::cout << "5. Added Clients\n";
        std::cout << "6. Added Services\n";
        std::cout << "7. Added Cases\n";
        std::cout << "8. Added Lawyer\n";
        std::cout << "9. Delete Client\n";
        std::cout << "10. Delete Lawyer\n";
        std::cout << "11. Delete Services\n";
        std::cout << "12. Delete Case\n";
        std::cout << "13. Exit\n";
        std::cout << "==========================\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            // Логіка перегляду клієнтів
            std::cout << "Viewing Clients...\n";
            viewAllClients();
            break;
        case 2:
            // Логіка перегляду адвокатів
            std::cout << "Viewing Lawyers...\n";
            viewAllLawyers();
            break;
        case 3:
            // Логіка перегляду справ
            std::cout << "Viewing Cases...\n";
            viewAllCases();
            break;
        case 4:
            // Логіка перегляду послуг
            std::cout << "Viewing Services...\n";
            viewAllServices();
            showMenuAdmin();
        case 5:
            // Logic for adding clients
            std::cout << "Adding New Client...\n";
            addNewClient();
            showMenuAdmin();
        case 6:
            // Logic for adding clients
            std::cout << "Adding New Service...\n";
            addNewService();
            showMenuAdmin();
        case 7:
            // Логіка перегляду послуг
            addNewCase();
            showMenuAdmin();
        case 8:
            // Логіка перегляду послуг     
            addNewLawyer();
            showMenuAdmin();
        case 9:
            // Логіка перегляду послуг     
            deleteClient();
            showMenuAdmin();
        case 10:
            deleteLawyer();
            showMenuAdmin();
        case 11:
            deleteServices();
            showMenuAdmin();
        case 12:
            deleteCase();
            showMenuAdmin();
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 12);
}

void showMenuLawyer() {
    int choice;

    do {
        std::cout << "========== Menu ==========\n";
        std::cout << "1. View\n";
        std::cout << "2. Edit\n";
        std::cout << "3. Added\n";
        std::cout << "4. Exit\n";
        std::cout << "==========================\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            // Логіка перегляду клієнтів
            std::cout << "Viewing Clients...\n";
            break;
        case 2:
            // Логіка перегляду адвокатів
            std::cout << "Viewing Lawyers...\n";
            break;
        case 3:
            // Логіка перегляду справ
            std::cout << "Viewing Cases...\n";
            break;
        case 4:
            // Логіка перегляду послуг
            std::cout << "Viewing Services...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}



int main() {
    std::string username;
    std::string password;

    std::cout << "Enter username: ";
    std::cin >> username;

    std::cout << "Enter password: ";
    std::cin >> password;

    if (authenticateUser(username, password)) {
    std::cout << "Access granted.\n";

    std::string userType = getUserType(username);
    if (userType == "Admin") {
        // Логіка для адміністратора
        showMenuAdmin();
    }
    else if (userType == "Lawyer") {
        // Логіка для адвоката
    }
    else {
        std::cout << "Unknown user type.\n";
    }
}
else {
    std::cout << "Access denied. Wrong username or password.\n";
}
    return 0;
}
