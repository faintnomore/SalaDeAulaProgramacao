#ifndef BANKINGSERVICES_H
#define BANKINGSERVICES_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <string>


extern sql::mysql::MySQL_Driver *driver;
extern sql::Connection *con;

void connectToDatabase();

class BankingServices {
    public:

        /** @brief Constructs a new `BankingServices` object.
         * 
         */
        BankingServices();

        /** @brief Destroys the `BankingServices` object. */
        ~BankingServices();

        /** 
         * @brief Deposits an amount into a specified account.
         * 
         * This method adds a specified amount to the balance of the account identified by
         * `account_id`.
         * 
         * @param account_id The ID of the account into which the amount will be deposited.
         * @param amount The amount of money to deposit.
         */
        void deposit(int account_id, double amount);

        /** 
         * @brief Withdraws an amount from a specified account.
         * 
         * This method subtracts a specified amount from the balance of the account identified by
         * `account_id`.
         * 
         * @param account_id The ID of the account from which the amount will be withdrawn.
         * @param amount The amount of money to withdraw.
         */
        void withdraw(int account_id, double amount);

        /** 
         * @brief Transfers an amount from one account to another.
         * 
         * This method moves a specified amount from the account identified by `source_account_id`
         * to the account identified by `destination_account_id`.
         * 
         * @param source_account_id The ID of the account from which the amount will be transferred.
         * @param destination_account_id The ID of the account to which the amount will be transferred.
         * @param amount The amount of money to transfer.
         */
        void transfer(int source_account_id, int destination_account_id, double amount);

        /** 
         * @brief Views the details of a specified account.
         * 
         * This method retrieves and displays the details of the account identified by
         * `account_id`.
         * 
         * @param account_id The ID of the account whose details are to be viewed.
         */
        void viewAccountDetails(int account_id);

        /** 
         * @brief Views the transaction history of a specified account.
         * 
         * This method retrieves and displays the transaction history of the account identified by
         * `account_id`.
         * 
         * @param account_id The ID of the account whose transaction history is to be viewed.
         */
        void viewTransactionHistory(int account_id);
};

#endif // BANKINGSERVICES_H
