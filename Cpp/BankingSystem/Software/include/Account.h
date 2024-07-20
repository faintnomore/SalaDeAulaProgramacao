#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <string>



/** 
 * @brief External MySQL driver and connection pointers.
 * 
 * These external variables should be defined in a source file and are used to establish
 * a connection to the MySQL database.
 */
extern sql::mysql::MySQL_Driver *driver;
extern sql::Connection *con;

/** 
 * @brief Establishes a connection to the database.
 * 
 * This function sets up a connection to the MySQL database using predefined parameters.
 * It should be called before performing any database operations.
 */
void connectToDatabase();

/** 
 * @class Account
 * @brief Represents a bank account with related operations.
 * 
 * The `Account` class provides methods to manage bank accounts, including creating, 
 * updating, and deleting accounts. It also includes member variables to store account 
 * information such as account ID, customer ID, account type, and balance.
 */
class Account {
private:
    int account_id;              /**< The unique identifier for the account. */
    int customer_id;            /**< The unique identifier for the customer who owns the account. */
    std::string account_type;   /**< The type of account (e.g., savings, checking). */
    double balance;             /**< The current balance of the account. */

public:
    /** 
     * @brief Default constructor.
     * 
     * Initializes an `Account` object with default values.
     */
    Account() {}

    /** 
     * @brief Parameterized constructor.
     * 
     * Initializes an `Account` object with specified values for account ID, customer ID, 
     * account type, and balance.
     * 
     * @param acc_id The account ID.
     * @param cust_id The customer ID.
     * @param type The account type.
     * @param bal The account balance.
     */
    Account(int acc_id, int cust_id, std::string type, double bal)
        : account_id(acc_id), customer_id(cust_id), account_type(type), balance(bal) {}


    /** 
     * @brief Parameterized desconstructor.
     * s
     * Desconstructor for the `Account` class.
     */
    ~Account();
    
    /** 
     * @brief Gets the account ID.
     * 
     * @return The account ID.
     */
    int getAccountID() const { return account_id; }

    /** 
     * @brief Gets the customer ID associated with the account.
     * 
     * @return The customer ID.
     */
    int getCustomerID() const { return customer_id; }

    /** 
     * @brief Gets the type of account.
     * 
     * @return The account type.
     */
    std::string getAccountType() const { return account_type; }

    /** 
     * @brief Gets the current balance of the account.
     * 
     * @return The account balance.
     */
    double getBalance() const { return balance; }

    /** 
     * @brief Sets the account ID.
     * 
     * @param id The account ID to set.
     */
    void setAccountID(int id) { account_id = id; }

    /** 
     * @brief Sets the customer ID associated with the account.
     * 
     * @param id The customer ID to set.
     */
    void setCustomerID(int id) { customer_id = id; }

    /** 
     * @brief Sets the type of account.
     * 
     * @param type The account type to set.
     */
    void setAccountType(const std::string &type) { account_type = type; }

    /** 
     * @brief Sets the balance of the account.
     * 
     * @param bal The balance to set.
     */
    void setBalance(double bal) { balance = bal; }

    /** 
     * @brief Creates a new account in the database.
     * 
     * This method inserts a new account record into the database with the current account
     * details.
     */
    void createAccount();

    /** 
     * @brief Updates an existing account in the database.
     * 
     * This method updates the details of an existing account in the database based on the
     * current account information.
     */
    void updateAccount();

    /** 
     * @brief Deletes an account from the database.
     * 
     * This method removes an account record from the database using the current account ID.
     */
    void deleteAccount();

    /** 
     * @brief Lists all accounts or filters by phone number.
     * 
     * This method queries the database for accounts. If a phone number is provided, it will 
     * filter the results based on the phone number. If the phone number is empty, it will
     * return the last 100 accounts added.
     * 
     * @param phone_number (Optional) The phone number to filter accounts by. If empty, 
     *                     the last 100 accounts are listed.
     */
    static void listAccounts(const std::string &phone_number = "");
};

#endif // ACCOUNT_H
