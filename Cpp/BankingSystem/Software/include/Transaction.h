#ifndef TRANSACTION_H
#define TRANSACTION_H


#include <string>
#include <mysql_driver.h>
#include <mysql_connection.h>

extern sql::mysql::MySQL_Driver *driver;
extern sql::Connection *con;

void connectToDatabase();

class Transaction {
private:
    int transaction_id;
    std::string transaction_type;
    double amount;
    std::string date;
    int source_account;
    int destination_account;

public:
    // Constructors
    Transaction() {}
    Transaction(int trans_id, std::string type, double amt, std::string dt, int src_acc, int dest_acc)
        : transaction_id(trans_id), transaction_type(type), amount(amt), date(dt), source_account(src_acc), destination_account(dest_acc) {}

    // Getters and setters
    int getTransactionID() const { return transaction_id; }
    std::string getTransactionType() const { return transaction_type; }
    double getAmount() const { return amount; }
    std::string getDate() const { return date; }
    int getSourceAccount() const { return source_account; }
    int getDestinationAccount() const { return destination_account; }

    void setTransactionID(int id) { transaction_id = id; }
    void setTransactionType(const std::string &type) { transaction_type = type; }
    void setAmount(double amt) { amount = amt; }
    void setDate(const std::string &dt) { date = dt; }
    void setSourceAccount(int src_acc) { source_account = src_acc; }
    void setDestinationAccount(int dest_acc) { destination_account = dest_acc; }

    // Methods for recording and retrieving transactions
    void recordTransaction();
    void getTransactionHistory();
};

#endif // TRANSACTION_H