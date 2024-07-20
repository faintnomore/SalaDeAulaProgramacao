#include "Transaction.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>

extern sql::mysql::MySQL_Driver *driver;
extern sql::Connection *con;

/**
 * @brief Destroy the Transaction:: Transaction object
 * 
 */
Transaction::~Transaction()
{
    delete con;
}

void Transaction::recordTransaction()
{
    connectToDatabase();
    sql::PreparedStatement *pstmt;
    pstmt = con->prepareStatement("INSERT INTO Transactions (transaction_type, amount, date, source_account, destination_account) VALUES (?, ?, ?, ?, ?)");
    pstmt->setString(1, transaction_type);
    pstmt->setDouble(2, amount);
    pstmt->setString(3, date);
    pstmt->setInt(4, source_account);
    pstmt->setInt(5, destination_account);
    pstmt->executeUpdate();
    delete pstmt;
    delete con;
}

void Transaction::getTransactionHistory() {
    connectToDatabase();
    sql::Statement *stmt;
    sql::ResultSet *res;
    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT * FROM Transactions WHERE source_account = " + std::to_string(source_account) + " OR destination_account = " + std::to_string(source_account));
    while (res->next()) {
        std::cout << "Transaction ID: " << res->getInt("transaction_id") << " Type: " << res->getString("transaction_type") << " Amount: " << res->getDouble("amount") << " Date: " << res->getString("date") << std::endl;
    }
    delete res;
    delete stmt;
    delete con;
}