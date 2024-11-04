#include <iostream>
#include <string>
#include "fileHandling.h"
#include "coreFunctionality.h"

using namespace std;

int main()
{
    Users users;
    Inventory inventory;
    InventoryCore inventorycore;
    Employees employees;
    customerCore cc;
    BillingCore bc;
    EmployeeCore ec;

    int choice;
    bool isLoggedIn = false;
    bool isAdmin = false;
    
    while (true)
    {
        if (!isLoggedIn)
        {
            cout << "1. Sign Up\n";
            cout << "2. Login\n";
            cout << "Enter your choice: ";
            cin >> choice;

            string name, email, password, phone_num;
            if (choice == 1)
            {
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter password: ";
                cin >> password;
                cout << "Enter phone number: ";
                cin >> phone_num;
                users.signup(name, email, password, false, phone_num);
                cout << "Signup successful!\n";
            }
            else if (choice == 2)
            {
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter password: ";
                cin >> password;
                vector<string> userData = users.login(email, password);
                if (!userData.empty())
                {
                    isLoggedIn = true;
                    isAdmin = userData[1] == "1";
                    break;
                }
            }
            else
            {
                cout << "Invalid choice!" << endl;
                continue;
            }
        }
    }

    while (true)
    {
        cout << "\n===== Grocery Store Management System =====\n";

        cout << "\nWelcome to the system!\n";
        if (isAdmin)
        {
            cout << "1. Inventory\n";
            cout << "2. Customers\n";
            cout << "3. Billing\n";
            cout << "4. Employees\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1)
            {
                cout << "1. Add Item\n";
                cout << "2. Update Item Price\n";
                cout << "3. Delete Item\n";
                cout << "4. Search item by Id\n";
                cout << "5. Show items alphabetically\n";
                cout << "6. Show items by category\n";
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1)
                {
                    string itemId, itemName, price, category;
                    cout << "Enter Item ID: ";
                    cin >> itemId;
                    cout << "Enter Item Name: ";
                    cin >> itemName;
                    cout << "Enter Item Price: ";
                    cin >> price;
                    cout << "Enter Category: ";
                    cin >> category;
                    inventory.addItem(itemId, itemName, price, category);
                    cout << "Item added successfully!" << endl;
                }
                else if (choice == 2)
                {
                    string itemId, newPrice;
                    cout << "Enter Item ID: ";
                    cin >> itemId;
                    cout << "Enter new Price: ";
                    cin >> newPrice;
                    inventory.updateItemPrice(itemId, newPrice);
                    cout << "Item price updated successfully" << endl;
                }
                else if (choice == 3)
                {
                    string itemId;
                    cout << "Enter Item ID: ";
                    cin >> itemId;
                    inventory.deleteItem(itemId);
                    cout << "Item deleted successfully" << endl;
                }
                else if (choice == 4)
                {
                    string itemId;
                    cout << "Enter Item ID: ";
                    cin >> itemId;
                    inventorycore.searchItemById(itemId);
                }
                else if (choice == 5)
                {
                    cout << "Show items alphabetically =>  " << endl;
                    inventorycore.showItemsAlphabetically();
                }
                else if (choice == 6)
                {
                    string category;
                    cout << "Enter category: ";
                    cin >> category;
                    inventorycore.showItemsByCategory(category);
                }
                else if (choice == 7)
                {
                    cout << "Exiting inventory menu." << endl;
                }
                else
                {
                    cout << "Invalid choice!" << endl;
                }
            }
            else if (choice == 2)
            {
                string phone_number;
                cout << "Enter phone number of customer (or type 'exit' to go back): ";
                cin >> phone_number;
                if (phone_number == "exit") continue;
                cc.SearchCustomerByPhoneNumber(phone_number);
            }
            else if (choice == 3)
            {
                cout << "1. Fetch Sales\n";
                cout << "2. No. of Billings\n";
                cout << "Enter your choice: ";
                cin >> choice;
                if (choice == 1){
                    bc.FetchSales();
                }
                else if (choice == 2){
                    bc.NoofBillings();
                }
                else {
                    cout << "Invalid choice\n";
                }
            }
            else if (choice == 4)
            {
                cout << "1. Add employee\n";
                cout << "2. Update employee salary\n";
                cout << "3. Delete info of employee\n";
                cout << "4. Show employees by name\n";
                cout << "5. Show employee by id\n";
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1)
                {
                    string employ_id, name, salary;
                    cout << "Enter id of employee: ";
                    cin >> employ_id;
                    cout << "Enter name of employee: ";
                    cin >> name;
                    cout << "Enter salary: ";
                    cin >> salary;
                    employees.addEmployee(employ_id, name, salary);
                    cout << "Employee added successfully" << endl;
                }
                else if (choice == 2)
                {
                    string employ_id, newsalary;
                    cout << "Enter id of employee: ";
                    cin >> employ_id;
                    cout << "Enter new salary of employee: ";
                    cin >> newsalary;
                    employees.updateEmployeeSalary(employ_id, newsalary);
                    cout << "Employee salary updated successfully" << endl;
                }
                else if (choice == 3)
                {
                    string employ_id;
                    cout << "Enter id of employee: ";
                    cin >> employ_id;
                    employees.deleteEmployee(employ_id);
                    cout << "Info of employee deleted successfully" << endl;
                }
                else if (choice == 4)
                {
                    string name;
                    cout << "Enter name of employee: ";
                    cin >> name;
                    ec.showEmployeesByName(name);
                }
                else if (choice == 5)
                {
                    string employ_id;
                    cout << "Enter employee id: ";
                    cin >> employ_id;
                    ec.showEmployeeById(employ_id);
                }
                else
                {
                    cout << "Invalid choice!" << endl;
                }
            }
            else if (choice == 5)
            {
                cout << "Exiting admin menu. Thank you!" << endl;
                break; 
            }
            else
            {
                cout << "Invalid choice!" << endl;
            }
        }
        else // Customer menu
        {
            cout << "You are our customer, please buy anything except our store's land." << endl;
            cout << "1. Show all Items\n";
            cout << "2. Select item\n";
            cout << "3. Search item by ID\n";
            cout << "4. Show items alphabetically\n";
            cout << "5. Show items by category\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1)
            {
                inventorycore.showItemsAlphabetically();
            }
            else if (choice == 2)
            {
                bc.PurchasingItems();
            }
            else if (choice == 3)
            {
                string itemId;
                cout << "Enter Item ID: ";
                cin >> itemId;
                inventorycore.searchItemById(itemId);
            }
            else if (choice == 4)
            {
                cout << "Show items alphabetically =>  " << endl;
                inventorycore.showItemsAlphabetically();
            }
            else if (choice == 5)
            {
                string category;
                cout << "Enter category: ";
                cin >> category;
                inventorycore.showItemsByCategory(category);
            }
            else if (choice == 6)
            {
                cout << "Thanks for visiting our store, please recommend others to visit here." << endl;
                break;
            }
            else
            {
                cout << "Invalid choice!" << endl;
            }
        }
    }

    return 0;
}
