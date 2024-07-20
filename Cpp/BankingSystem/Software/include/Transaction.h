#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <string>


extern sql::mysql::MySQL_Driver *driver;
extern sql::Connection *con;

void connectToDatabase();

/** 
 * @class Transaction
 * @brief Represents a financial transaction in the banking system.
 * 
 * The `Transaction` class encapsulates the details of a transaction, including its ID,
 * type, amount, date, and associated accounts. It provides methods to record a new transaction
 * and retrieve the transaction history for a specific account.
 */
class Transaction {
private:
    int transaction_id;         ///< Unique identifier for the transaction
    std::string transaction_type; ///< Type of the transaction (e.g., deposit, withdrawal)
    double amount;              ///< Amount involved in the transaction
    std::string date;          ///< Date of the transaction
    int source_account;        ///< Account ID from which the amount is debited
    int destination_account;   ///< Account ID to which the amount is credited

public:
    /** 
     * @brief Default constructor for the Transaction class.
     * 
     * Initializes a new instance of the `Transaction` class with default values.
     */
    Transaction() {}

    /** 
     * @brief Parameterized constructor for the Transaction class.
     * 
     * Initializes a new instance of the `Transaction` class with the specified values.
     * 
     * @param trans_id The unique identifier for the transaction.
     * @param type The type of the transaction.
     * @param amt The amount involved in the transaction.
     * @param dt The date of the transaction.
     * @param src_acc The account ID from which the amount is debited.
     * @param dest_acc The account ID to which the amount is credited.
     */
    Transaction(int trans_id, std::string type, double amt, std::string dt, int src_acc, int dest_acc)
        : transaction_id(trans_id), transaction_type(type), amount(amt), date(dt), source_account(src_acc), destination_account(dest_acc) {}


    /**
     * @brief Destroy the Transaction object
     * 
     */
    ~Transaction();

    /** 
     * @brief Gets the transaction ID.
     * 
     * Retrieves the unique identifier for the transaction.
     * 
     * @return The transaction ID.
     */
    int getTransactionID() const { return transaction_id; }

    /** 
     * @brief Gets the transaction type.
     * 
     * Retrieves the type of the transaction (e.g., deposit, withdrawal).
     * 
     * @return The type of the transaction.
     */
    std::string getTransactionType() const { return transaction_type; }

    /** 
     * @brief Gets the amount involved in the transaction.
     * 
     * Retrieves the amount associated with the transaction.
     * 
     * @return The amount of the transaction.
     */
    double getAmount() const { return amount; }

    /** 
     * @brief Gets the date of the transaction.
     * 
     * Retrieves the date when the transaction occurred.
     * 
     * @return The date of the transaction.
     */
    std::string getDate() const { return date; }

    /** 
     * @brief Gets the source account ID.
     * 
     * Retrieves the account ID from which the amount is debited.
     * 
     * @return The source account ID.
     */
    int getSourceAccount() const { return source_account; }

    /** 
     * @brief Gets the destination account ID.
     * 
     * Retrieves the account ID to which the amount is credited.
     * 
     * @return The destination account ID.
     */
    int getDestinationAccount() const { return destination_account; }

    /** 
     * @brief Sets the transaction ID.
     * 
     * Updates the unique identifier for the transaction.
     * 
     * @param id The new transaction ID.
     */
    void setTransactionID(int id) { transaction_id = id; }

    /** 
     * @brief Sets the transaction type.
     * 
     * Updates the type of the transaction.
     * 
     * @param type The new type of the transaction.
     */
    void setTransactionType(const std::string &type) { transaction_type = type; }

    /** 
     * @brief Sets the amount involved in the transaction.
     * 
     * Updates the amount associated with the transaction.
     * 
     * @param amt The new amount of the transaction.
     */
    void setAmount(double amt) { amount = amt; }

    /** 
     * @brief Sets the date of the transaction.
     * 
     * Updates the date when the transaction occurred.
     * 
     * @param dt The new date of the transaction.
     */
    void setDate(const std::string &dt) { date = dt; }

    /** 
     * @brief Sets the source account ID.
     * 
     * Updates the account ID from which the amount is debited.
     * 
     * @param src_acc The new source account ID.
     */
    void setSourceAccount(int src_acc) { source_account = src_acc; }

    /** 
     * @brief Sets the destination account ID.
     * 
     * Updates the account ID to which the amount is credited.
     * 
     * @param dest_acc The new destination account ID.
     */
    void setDestinationAccount(int dest_acc) { destination_account = dest_acc; }

    /** 
     * @brief Records a new transaction in the database.
     * 
     * This method inserts a new transaction record into the database using the current attributes
     * of the `Transaction` instance.
     */
    void recordTransaction();

    /** 
     * @brief Retrieves and displays the transaction history for a specific account.
     * 
     * This method queries the database for transactions involving the specified account and
     * prints the details of each transaction.
     */
    void getTransactionHistory();
};

#endif // TRANSACTION_H
