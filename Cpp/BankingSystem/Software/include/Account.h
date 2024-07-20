#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <string>

extern sql::mysql::MySQL_Driver *driver;
extern sql::Connection *con;

void connectToDatabase();

class Account {
private:
    int account_id;
    int customer_id;
    std::string account_type;
    double balance;

public:
    // Constructors
    Account() {}
    Account(int acc_id, int cust_id, std::string type, double bal)
        : account_id(acc_id), customer_id(cust_id), account_type(type), balance(bal) {}

    // Getters and setters
    int getAccountID() const { return account_id; }
    int getCustomerID() const { return customer_id; }
    std::string getAccountType() const { return account_type; }
    double getBalance() const { return balance; }

    void setAccountID(int id) { account_id = id; }
    void setCustomerID(int id) { customer_id = id; }
    void setAccountType(const std::string &type) { account_type = type; }
    void setBalance(double bal) { balance = bal; }

    // Methods for creating, updating, and deleting accounts
    void createAccount();
    void updateAccount();
    void deleteAccount();
};

#endif // ACCOUNT_H