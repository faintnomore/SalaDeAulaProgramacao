#include "Customer.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>

extern sql::mysql::MySQL_Driver *driver;
extern sql::Connection *con;

Customer::~Customer()
{
    delete con;
}

void Customer::addCustomer()
{
    connectToDatabase();
    sql::PreparedStatement *pstmt;
    pstmt = con->prepareStatement("INSERT INTO Customers (name, address, contact_info) VALUES (?, ?, ?)");
    pstmt->setString(1, name);
    pstmt->setString(2, address);
    pstmt->setString(3, contact_info);
    pstmt->executeUpdate();
    delete pstmt;
    delete con;
}

void Customer::updateCustomer() {
    connectToDatabase();
    sql::PreparedStatement *pstmt;
    pstmt = con->prepareStatement("UPDATE Customers SET name = ?, address = ?, contact_info = ? WHERE customer_id = ?");
    pstmt->setString(1, name);
    pstmt->setString(2, address);
    pstmt->setString(3, contact_info);
    pstmt->setInt(4, customer_id);
    pstmt->executeUpdate();
    delete pstmt;
    delete con;
}

void Customer::deleteCustomer() {
    connectToDatabase();
    sql::PreparedStatement *pstmt;
    pstmt = con->prepareStatement("DELETE FROM Customers WHERE customer_id = ?");
    pstmt->setInt(1, customer_id);
    pstmt->executeUpdate();
    delete pstmt;
    delete con;
}