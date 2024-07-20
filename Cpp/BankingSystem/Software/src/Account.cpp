#include "Account.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>

extern sql::mysql::MySQL_Driver *driver;
extern sql::Connection *con;

void Account::createAccount() {
    connectToDatabase();
    sql::PreparedStatement *pstmt;
    pstmt = con->prepareStatement("INSERT INTO Accounts (customer_id, account_type, balance) VALUES (?, ?, ?)");
    pstmt->setInt(1, customer_id);
    pstmt->setString(2, account_type);
    pstmt->setDouble(3, balance);
    pstmt->executeUpdate();
    delete pstmt;
    delete con;
}

void Account::updateAccount() {
    connectToDatabase();
    sql::PreparedStatement *pstmt;
    pstmt = con->prepareStatement("UPDATE Accounts SET account_type = ?, balance = ? WHERE account_id = ?");
    pstmt->setString(1, account_type);
    pstmt->setDouble(2, balance);
    pstmt->setInt(3, account_id);
    pstmt->executeUpdate();
    delete pstmt;
    delete con;
}

void Account::deleteAccount() {
    connectToDatabase();
    sql::PreparedStatement *pstmt;
    pstmt = con->prepareStatement("DELETE FROM Accounts WHERE account_id = ?");
    pstmt->setInt(1, account_id);
    pstmt->executeUpdate();
    delete pstmt;
    delete con;
}