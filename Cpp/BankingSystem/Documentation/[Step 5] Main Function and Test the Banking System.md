### Step 5: Implement the Main Function and Test the Banking System

In this step, we'll put everything together by implementing a `main.cpp` file to interact with the banking system and test the functionality of the classes.

#### 5.1 Implement the `main.cpp` File

**main.cpp**
```cpp
#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include "Customer.h"
#include "Account.h"
#include "Transaction.h"
#include "BankingServices.h"

sql::mysql::MySQL_Driver *driver;
sql::Connection *con;

void connectToDatabase() {
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "your_password");
    con->setSchema("banking_system");
}

void displayMenu() {
    std::cout << "Banking System Menu:" << std::endl;
    std::cout << "1. Add Customer" << std::endl;
    std::cout << "2. Update Customer" << std::endl;
    std::cout << "3. Delete Customer" << std::endl;
    std::cout << "4. Create Account" << std::endl;
    std::cout << "5. Update Account" << std::endl;
    std::cout << "6. Delete Account" << std::endl;
    std::cout << "7. Deposit" << std::endl;
    std::cout << "8. Withdraw" << std::endl;
    std::cout << "9. Transfer" << std::endl;
    std::cout << "10. View Account Details" << std::endl;
    std::cout << "11. View Transaction History" << std::endl;
    std::cout << "12. Exit" << std::endl;
}

int main() {
    connectToDatabase();

    int choice;
    BankingServices services;

    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 12) {
            break;
        }

        int id;
        std::string name, address, contact, type, date;
        double amount;
        Customer customer;
        Account account;
        Transaction transaction;

        switch (choice) {
            case 1:
                std::cout << "Enter name: ";
                std::cin >> name;
                std::cout << "Enter address: ";
                std::cin >> address;
                std::cout << "Enter contact info: ";
                std::cin >> contact;
                customer = Customer(0, name, address, contact);
                customer.addCustomer();
                std::cout << "Customer added successfully!" << std::endl;
                break;

            case 2:
                std::cout << "Enter customer ID to update: ";
                std::cin >> id;
                std::cout << "Enter new name: ";
                std::cin >> name;
                std::cout << "Enter new address: ";
                std::cin >> address;
                std::cout << "Enter new contact info: ";
                std::cin >> contact;
                customer = Customer(id, name, address, contact);
                customer.updateCustomer();
                std::cout << "Customer updated successfully!" << std::endl;
                break;

            case 3:
                std::cout << "Enter customer ID to delete: ";
                std::cin >> id;
                customer.setCustomerID(id);
                customer.deleteCustomer();
                std::cout << "Customer deleted successfully!" << std::endl;
                break;

            case 4:
                std::cout << "Enter customer ID: ";
                std::cin >> id;
                std::cout << "Enter account type: ";
                std::cin >> type;
                std::cout << "Enter initial balance: ";
                std::cin >> amount;
                account = Account(0, id, type, amount);
                account.createAccount();
                std::cout << "Account created successfully!" << std::endl;
                break;

            case 5:
                std::cout << "Enter account ID to update: ";
                std::cin >> id;
                std::cout << "Enter new account type: ";
                std::cin >> type;
                std::cout << "Enter new balance: ";
                std::cin >> amount;
                account = Account(id, 0, type, amount);
                account.updateAccount();
                std::cout << "Account updated successfully!" << std::endl;
                break;

            case 6:
                std::cout << "Enter account ID to delete: ";
                std::cin >> id;
                account.setAccountID(id);
                account.deleteAccount();
                std::cout << "Account deleted successfully!" << std::endl;
                break;

            case 7:
                std::cout << "Enter account ID: ";
                std::cin >> id;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                services.deposit(id, amount);
                std::cout << "Amount deposited successfully!" << std::endl;
                break;

            case 8:
                std::cout << "Enter account ID: ";
                std::cin >> id;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                services.withdraw(id, amount);
                std::cout << "Amount withdrawn successfully!" << std::endl;
                break;

            case 9:
                int source_id, destination_id;
                std::cout << "Enter source account ID: ";
                std::cin >> source_id;
                std::cout << "Enter destination account ID: ";
                std::cin >> destination_id;
                std::cout << "Enter amount to transfer: ";
                std::cin >> amount;
                services.transfer(source_id, destination_id, amount);
                std::cout << "Amount transferred successfully!" << std::endl;
                break;

            case 10:
                std::cout << "Enter account ID to view details: ";
                std::cin >> id;
                services.viewAccountDetails(id);
                break;

            case 11:
                std::cout << "Enter account ID to view transaction history: ";
                std::cin >> id;
                services.viewTransactionHistory(id);
                break;

            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
                break;
        }
    }

    delete con;
    return 0;
}
```

#### 5.2 Implement BankingServices Methods

Update `BankingServices.cpp` to include the implementation for the `BankingServices` methods.

**BankingServices.cpp**
```cpp
#include "BankingServices.h"
#include "Account.h"
#include "Transaction.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <iostream>

extern sql::mysql::MySQL_Driver *driver;
extern sql::Connection *con;

void BankingServices::deposit(int account_id, double amount) {
    connectToDatabase();
    sql::PreparedStatement *pstmt;
    pstmt = con->prepareStatement("UPDATE Accounts SET balance = balance + ? WHERE account_id = ?");
    pstmt->setDouble(1, amount);
    pstmt->setInt(2, account_id);
    pstmt->executeUpdate();

    Transaction transaction(0, "Deposit", amount, "", account_id, account_id);
    transaction.recordTransaction();

    delete pstmt;
    delete con;
}

void BankingServices::withdraw(int account_id, double amount) {
    connectToDatabase();
    sql::PreparedStatement *pstmt;
    pstmt = con->prepareStatement("UPDATE Accounts SET balance = balance - ? WHERE account_id = ?");
    pstmt->setDouble(1, amount);
    pstmt->setInt(2, account_id);
    pstmt->executeUpdate();

    Transaction transaction(0, "Withdraw", amount, "", account_id, account_id);
    transaction.recordTransaction();

    delete pstmt;
    delete con;
}

void BankingServices::transfer(int source_account_id, int destination_account_id, double amount) {
    connectToDatabase();
    sql::PreparedStatement *pstmt;

    pstmt = con->prepareStatement("UPDATE Accounts SET balance = balance - ? WHERE account_id = ?");
    pstmt->setDouble(1, amount);
    pstmt->setInt(2, source_account_id);
    pstmt->executeUpdate();

    pstmt = con->prepareStatement("UPDATE Accounts SET balance = balance + ? WHERE account_id = ?");
    pstmt->setDouble(1, amount);
    pstmt->setInt(2, destination_account_id);
    pstmt->executeUpdate();

    Transaction transaction(0, "Transfer", amount, "", source_account_id, destination_account_id);
    transaction.recordTransaction();

    delete pstmt;
    delete con;
}

void BankingServices::viewAccountDetails(int account_id) {
    connectToDatabase();
    sql::Statement *stmt;
    sql::ResultSet *res;
    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT * FROM Accounts WHERE account_id = " + std::to_string(account_id));
    while (res->next()) {
        std::cout << "Account ID: " << res->getInt("account_id")
                  << " Customer ID: " << res->getInt("customer_id")
                  << " Account Type: " << res->getString("account_type")
                  << " Balance: " << res->getDouble("balance") << std::endl;
    }
    delete res;
    delete stmt;
    delete con;
}

void BankingServices::viewTransactionHistory(int account_id) {
    connectToDatabase();
    sql::Statement *stmt;
    sql::ResultSet *res;
    stmt = con->createStatement

();
    res = stmt->executeQuery("SELECT * FROM Transactions WHERE source_account = " + std::to_string(account_id) + " OR destination_account = " + std::to_string(account_id));
    while (res->next()) {
        std::cout << "Transaction ID: " << res->getInt("transaction_id")
                  << " Type: " << res->getString("transaction_type")
                  << " Amount: " << res->getDouble("amount")
                  << " Date: " << res->getString("date") << std::endl;
    }
    delete res;
    delete stmt;
    delete con;
}
```

#### 5.3 Compile and Run the Project

1. **Compile the Project:**
   - If using CMake, navigate to your project directory and run:
     ```sh
     mkdir build
     cd build
     cmake ..
     make
     ```

2. **Run the Executable:**
   - After successful compilation, run the resulting executable:
     ```sh
     ./BankingSystem
     ```

#### 5.4 Testing the Functionality

1. **Add a Customer:**
   - Choose option `1` and enter the required details.

2. **Create an Account:**
   - Choose option `4` and enter the required details, including the customer ID from the previous step.

3. **Deposit Money:**
   - Choose option `7` and enter the account ID and the amount to deposit.

4. **Withdraw Money:**
   - Choose option `8` and enter the account ID and the amount to withdraw.

5. **Transfer Money:**
   - Choose option `9` and enter the source and destination account IDs along with the amount to transfer.

6. **View Account Details:**
   - Choose option `10` and enter the account ID.

7. **View Transaction History:**
   - Choose option `11` and enter the account ID.

By following these steps, you will have a fully functional banking system project in C++ that you can further extend and enhance.