#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <string>

extern sql::mysql::MySQL_Driver *driver;
extern sql::Connection *con;

void connectToDatabase();

class Customer {
private:
    int customer_id;
    std::string name;
    std::string address;
    std::string contact_info;

public:
    // Constructors
    Customer() {}
    Customer(int id, std::string n, std::string addr, std::string contact)
        : customer_id(id), name(n), address(addr), contact_info(contact) {}

    // Getters and setters
    int getCustomerID() const { return customer_id; }
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    std::string getContactInfo() const { return contact_info; }

    void setCustomerID(int id) { customer_id = id; }
    void setName(const std::string &n) { name = n; }
    void setAddress(const std::string &addr) { address = addr; }
    void setContactInfo(const std::string &contact) { contact_info = contact; }

    // Methods for adding, updating, and deleting customers
    void addCustomer();
    void updateCustomer();
    void deleteCustomer();
};

#endif // CUSTOMER_H