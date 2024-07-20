#include "Account.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>

extern sql::mysql::MySQL_Driver *driver;
extern sql::Connection *con;



Account::~Account() {
    delete con;
}

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

void Account::listAccounts(const std::string &phone_number) {
    connectToDatabase();

    sql::Statement *stmt;
    sql::ResultSet *res;
    std::string query;

    if (phone_number.empty()) {
        // If no phone number is provided, get the last 100 accounts added
        query = "SELECT * FROM Accounts ORDER BY created_at DESC LIMIT 100";
    } else {
        // If phone number is provided, find accounts associated with that phone number
        query = "SELECT a.* FROM Accounts a "
                "JOIN Customers c ON a.customer_id = c.customer_id "
                "WHERE c.contact_info = ? "
                "ORDER BY a.created_at DESC";
    }

    try {
        stmt = con->createStatement();
        if (phone_number.empty()) {
            res = stmt->executeQuery(query);
        } else {
            sql::PreparedStatement *pstmt = con->prepareStatement(query);
            pstmt->setString(1, phone_number);
            res = pstmt->executeQuery();
            delete pstmt;
        }

        while (res->next()) {
            std::cout << "Account ID: " << res->getInt("account_id")
                      << ", Customer ID: " << res->getInt("customer_id")
                      << ", Account Type: " << res->getString("account_type")
                      << ", Balance: " << res->getDouble("balance") << std::endl;
        }
        delete res;
        delete stmt;
    } catch (sql::SQLException &e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }

    delete con;
}
