/*** 
 * @file main.cpp
 * @brief Main entry point for the Banking System application.
 * 
 * This file contains the main function and the implementation of the
 * menu-driven interface for managing customers, accounts, and transactions
 * in the banking system. It also handles database connections and interactions.
 */

/***
 * @brief Establishes a connection to the MySQL database.
 * 
 * This function attempts to connect to the MySQL database using the
 * specified connection parameters. It sets the schema to "banking_system".
 * If the connection fails, it logs an error message and terminates the program.
 */
void connectToDatabase() {
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "888888");
        con->setSchema("banking_system");
    } catch (sql::SQLException &e) {
        std::cerr << "Error connecting to database: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

/***
 * @brief Displays the main menu and captures user input.
 * 
 * This function uses ncurses to display a menu with options for various
 * banking operations. It captures the user's choice and returns it as an
 * integer value. If the user enters an invalid choice, it returns -1.
 * 
 * @return int The user's menu choice.
 */
int displayMenu() {
    initscr();            // Start ncurses mode
    if (has_colors() == FALSE) {
        endwin();
        std::cerr << "Your terminal does not support color" << std::endl;
        exit(EXIT_FAILURE);
    }
    cbreak();             // Disable line buffering
    noecho();             // Do not echo input
    keypad(stdscr, TRUE); // Enable special keys capture

    clear();              // Clear screen

    printw("Banking System Menu:\n");
    printw("1. Add Customer\n");
    printw("2. Update Customer\n");
    printw("3. Delete Customer\n");
    printw("4. Create Account\n");
    printw("5. Update Account\n");
    printw("6. Delete Account\n");
    printw("7. Deposit\n");
    printw("8. Withdraw\n");
    printw("9. Transfer\n");
    printw("10. View Account Details\n");
    printw("11. View Transaction History\n");
    printw("12. Exit\n");

    refresh();            // Refresh the screen to show the output

    int ch = getch();    // Get user input
    endwin();            // End ncurses mode

    switch (ch) {
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case '0': {
            // Handle '10' separately
            if (getch() == '1') return 10;
            break;
        }
        case 'q': {
            // Handle '11' separately
            if (getch() == '1') return 11;
            break;
        }
        case 'e': {
            // Handle '12' separately
            if (getch() == '2') return 12;
            break;
        }
        default: return -1; // Invalid choice
    }

    return -1; // If no valid choice
}

/***
 * @brief Main function for the Banking System application.
 * 
 * This function initializes the application by connecting to the database
 * and then enters a loop to display the menu and process user choices. It
 * performs operations related to customers, accounts, and transactions based
 * on user input. It exits when the user selects the option to exit.
 * 
 * @return int Exit status of the program.
 */
int main() {
    connectToDatabase();

    spdlog::info("Starting Banking System...");

    int choice;
    BankingServices services;

    while (true) {
        choice = displayMenu();
        if (choice == 12) {
            spdlog::info("Exiting Banking System...");
            break;
        }

        int id;
        std::string name, address, contact, type;
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

    delete con;  // Clean up the database connection
    return 0;
}
