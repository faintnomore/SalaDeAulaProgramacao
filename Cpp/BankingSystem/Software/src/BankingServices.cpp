#include "BankingServices.h"
#include "Account.h"
#include "Transaction.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <iostream>

extern sql::mysql::MySQL_Driver *driver;
extern sql::Connection *con;

BankingServices::BankingServices()
{
}

BankingServices::~BankingServices()
{
    delete con;
}

void BankingServices::deposit(int account_id, double amount)
{
    connectToDatabase();
    sql::PreparedStatement *pstmt;
    pstmt = con->prepareStatement("UPDATE Accounts SET balance = balance + ? WHERE account_id = ?");
    pstmt->setDouble(1, amount);
    pstmt->setInt(2, account_id);
    pstmt->executeUpdate();

    Transaction transaction(0, "Deposit", amount, "", account_id, account_id);
    transaction.recordTransaction();

    delete pstmt;
    delete con;
}

void BankingServices::withdraw(int account_id, double amount) {
   connectToDatabase();
    sql::PreparedStatement *pstmt;
    sql::ResultSet *res;
    pstmt = con->prepareStatement("SELECT balance FROM Accounts WHERE account_id = ?");
    pstmt->setInt(1, account_id);
    res = pstmt->executeQuery();
    
    if (res->next() && res->getDouble("balance") >= amount) {
        pstmt = con->prepareStatement("UPDATE Accounts SET balance = balance - ? WHERE account_id = ?");
        pstmt->setDouble(1, amount);
        pstmt->setInt(2, account_id);
        pstmt->executeUpdate();
        
        Transaction transaction(0, "Withdraw", amount, "", account_id, account_id);
        transaction.recordTransaction();
    } else {
        std::cerr << "Insufficient funds for withdrawal!" << std::endl;
    }

    delete res;
    delete pstmt;
    delete con;
}

void BankingServices::transfer(int source_account_id, int destination_account_id, double amount) {

    connectToDatabase();
    sql::PreparedStatement *pstmt;
    sql::ResultSet *res;

    pstmt = con->prepareStatement("SELECT balance FROM Accounts WHERE account_id = ?");
    pstmt->setInt(1, source_account_id);
    res = pstmt->executeQuery();
    
    if (res->next() && res->getDouble("balance") >= amount) {
        pstmt = con->prepareStatement("UPDATE Accounts SET balance = balance - ? WHERE account_id = ?");
        pstmt->setDouble(1, amount);
        pstmt->setInt(2, source_account_id);
        pstmt->executeUpdate();

        pstmt = con->prepareStatement("UPDATE Accounts SET balance = balance + ? WHERE account_id = ?");
        pstmt->setDouble(1, amount);
        pstmt->setInt(2, destination_account_id);
        pstmt->executeUpdate();

        Transaction transaction(0, "Transfer", amount, "", source_account_id, destination_account_id);
        transaction.recordTransaction();
    } else {
        std::cerr << "Insufficient funds for Transfer!" << std::endl;
    }

    delete res;
    delete pstmt;
    delete con;

}

void BankingServices::viewAccountDetails(int account_id) {
    connectToDatabase();
    sql::Statement *stmt;
    sql::ResultSet *res;
    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT * FROM Accounts WHERE account_id = " + std::to_string(account_id));
    while (res->next()) {
        std::cout << "Account ID: " << res->getInt("account_id")
                  << " Customer ID: " << res->getInt("customer_id")
                  << " Account Type: " << res->getString("account_type")
                  << " Balance: " << res->getDouble("balance") << std::endl;
    }
    delete res;
    delete stmt;
    delete con;
}

void BankingServices::viewTransactionHistory(int account_id) {
    connectToDatabase();
    sql::Statement *stmt;
    sql::ResultSet *res;
    stmt = con->createStatement

();
    res = stmt->executeQuery("SELECT * FROM Transactions WHERE source_account = " + std::to_string(account_id) + " OR destination_account = " + std::to_string(account_id));
    while (res->next()) {
        std::cout << "Transaction ID: " << res->getInt("transaction_id")
                  << " Type: " << res->getString("transaction_type")
                  << " Amount: " << res->getDouble("amount")
                  << " Date: " << res->getString("date") << std::endl;
    }
    delete res;
    delete stmt;
    delete con;
}