#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <string>


extern sql::mysql::MySQL_Driver *driver;
extern sql::Connection *con;

void connectToDatabase();

/** 
 * @class Customer
 * @brief Represents a customer in the banking system.
 * 
 * The `Customer` class encapsulates the details of a customer, including their ID, name, address,
 * and contact information. It provides methods to manage customer records in the database.
 */
class Customer {
private:
    int customer_id;            ///< Unique identifier for the customer
    std::string name;           ///< Name of the customer
    std::string address;        ///< Address of the customer
    std::string contact_info;   ///< Contact information of the customer

public:
    /** 
     * @brief Default constructor for the Customer class.
     * 
     * Initializes a new instance of the `Customer` class with default values.
     */
    Customer() {}

    /** 
     * @brief Parameterized constructor for the Customer class.
     * 
     * Initializes a new instance of the `Customer` class with the specified values.
     * 
     * @param id The unique identifier for the customer.
     * @param n The name of the customer.
     * @param addr The address of the customer.
     * @param contact The contact information of the customer.
     */
    Customer(int id, std::string n, std::string addr, std::string contact)
        : customer_id(id), name(n), address(addr), contact_info(contact) {}

    /**
     * @brief Destroy the Customer object
     * 
     */
    ~Customer();

    /** 
     * @brief Gets the customer ID.
     * 
     * Retrieves the unique identifier for the customer.
     * 
     * @return The customer ID.
     */
    int getCustomerID() const { return customer_id; }

    /** 
     * @brief Gets the customer's name.
     * 
     * Retrieves the name of the customer.
     * 
     * @return The name of the customer.
     */
    std::string getName() const { return name; }

    /** 
     * @brief Gets the customer's address.
     * 
     * Retrieves the address of the customer.
     * 
     * @return The address of the customer.
     */
    std::string getAddress() const { return address; }

    /** 
     * @brief Gets the customer's contact information.
     * 
     * Retrieves the contact information of the customer.
     * 
     * @return The contact information of the customer.
     */
    std::string getContactInfo() const { return contact_info; }

    /** 
     * @brief Sets the customer ID.
     * 
     * Updates the unique identifier for the customer.
     * 
     * @param id The new customer ID.
     */
    void setCustomerID(int id) { customer_id = id; }

    /** 
     * @brief Sets the customer's name.
     * 
     * Updates the name of the customer.
     * 
     * @param n The new name of the customer.
     */
    void setName(const std::string &n) { name = n; }

    /** 
     * @brief Sets the customer's address.
     * 
     * Updates the address of the customer.
     * 
     * @param addr The new address of the customer.
     */
    void setAddress(const std::string &addr) { address = addr; }

    /** 
     * @brief Sets the customer's contact information.
     * 
     * Updates the contact information of the customer.
     * 
     * @param contact The new contact information of the customer.
     */
    void setContactInfo(const std::string &contact) { contact_info = contact; }

    /** 
     * @brief Adds a new customer to the database.
     * 
     * This method inserts a new customer record into the database using the current attributes
     * of the `Customer` instance.
     */
    void addCustomer();

    /** 
     * @brief Updates an existing customer record in the database.
     * 
     * This method updates the customer record in the database with the current attributes
     * of the `Customer` instance.
     */
    void updateCustomer();

    /** 
     * @brief Deletes a customer record from the database.
     * 
     * This method removes the customer record identified by the current `customer_id` from
     * the database.
     */
    void deleteCustomer();
};

#endif // CUSTOMER_H
