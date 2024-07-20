#ifndef BANKINGSERVICES_H
#define BANKINGSERVICES_H

class BankingServices {
public:
    // Methods for banking operations
    void deposit(int account_id, double amount);
    void withdraw(int account_id, double amount);
    void transfer(int source_account_id, int destination_account_id, double amount);
    void viewAccountDetails(int account_id);
    void viewTransactionHistory(int account_id);
};

#endif // BANKINGSERVICES_H