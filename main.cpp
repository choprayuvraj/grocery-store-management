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
            cout << "-----------------------\n";
            cout << "1. Sign Up\n";
            cout << "2. Login\n";
            cout << "-----------------------\n";
            cout << "Enter your choice: ";
            cin >> choice;

            string name, email, password, PhoneNo;
            bool isValid = false;
            if (choice == 1)
            {
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter password: ";
                cin >> password;
                while (true)
                {
                    cout << "Enter your phone number for Billing purposes=";
                    cin >> PhoneNo;
                    if (PhoneNo.size() == 10)
                    {
                        for (int i = 0; i < PhoneNo.size(); i++)
                        {
                            if ((PhoneNo[i] >= '0' && PhoneNo[i] <= '9'))
                            {
                                isValid = true;
                            }
                            else
                            {
                                isValid = false;
                            }
                        }
                        if (isValid)
                        {
                            break;
                        }
                        else
                        {
                            cout << "You Can't type Any other character Other than Intergers\n";
                        }
                    }
                    else
                    {
                        cout << "The Phone Number you Typed is Of inncorrect Size, Try Again!\n";
                    }
                }
                users.signup(name, email, password, false, PhoneNo);
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
                break;
            }
        }
    }
    while (true)
    {

        cout << "\n===== Grocery Store Management System =====\n";

        cout << "\nWelcome to the system!\n";
        if (isAdmin)
        {
            cout << "---------------------\n";
            cout << "1.Inventory\n";
            cout << "2.Customers\n";
            cout << "3.Billing\n";
            cout << "4.Employees\n";
            cout << "5.Exit\n";
            cout << "---------------------\n";
            cout << "Enter your choice: ";
            cin >> choice;
            if (choice == 1)
            {
                cout << "----------------------------\n";
                cout << "1.Add Item\n";
                cout << "2.Update Item Price\n";
                cout << "3.Delete Item\n";
                cout << "4.Search item by Id\n";
                cout << "5.Show items alphabetically\n";
                cout << "6.Show items by category\n";
                cout << "----------------------------\n";
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1)
                {
                    string itemId, itemName, price, category;
                    cout << "Enter Item ID: ";
                    cin >> itemId;
                    cin.ignore();
                    cout << "Enter Item Name: ";
                    getline(cin, itemName);
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
                    cout << "Item found successfully" << endl;
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
                else
                {
                    cout << "Invalid choice!" << endl;
                }
            }
            else if (choice == 2)
            {
                string phone_number;
                cout << "Enter phone number of customer: ";
                cin >> phone_number;
                cc.SearchCustomerByPhoneNumber(phone_number);
            }
            else if (choice == 3)
            {
                cout << "-----------------------\n";
                cout << "1.Fetch Sales\n";
                cout << "2.No.of Billings\n";
                cout << "3.Billings History\n";
                cout << "4.Search Customer By Name From Billing\n";
                cout << "-----------------------\n";
                cout << "Enter your choice: ";
                cin >> choice;
                if (choice == 1)
                {
                    bc.FetchSales();
                }
                else if (choice == 2)
                {
                    bc.NoofBillings();
                }
                else if (choice == 3)
                {
                    bc.ShowingBillingHistory();
                }
                else if (choice == 4)
                {
                    string Name;
                    cout << "enter the name:";
                    cin >> Name;
                    bc.searchCustomerByNameInBilling(Name);
                }
                else
                {
                    cout << "invalid choice\n";
                }
            }
            else if (choice == 4)
            {
                cout << "-----------------------------\n";
                cout << "1).Add employee\n";
                cout << "2).Update employee salary\n";
                cout << "3).Delete info of employee\n";
                cout << "4).Show employees by name\n";
                cout << "5).Show employee by id\n";
                cout << "-----------------------------\n";
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1)
                {
                    string employ_id, name, salary;
                    cout << "Enter id of employee: ";
                    cin >> employ_id;
                    cin.ignore();
                    cout << "Enter name of employee: ";
                    getline(cin,name);
                    cout << "Enter salary: ";
                    cin >> salary;
                    employees.addEmployee(employ_id, name, salary);
                    cout << "Employ added successfully" << endl;
                }
                else if (choice == 2)
                {
                    string employ_id, newsalary;
                    cout << "Enter id of employee: ";
                    cin >> employ_id;
                    cout << "Enter new salary of employee: ";
                    cin >> newsalary;
                    employees.updateEmployeeSalary(employ_id, newsalary);
                    cout << "Employ salary updated successfully" << endl;
                }
                else if (choice == 3)
                {
                    string employ_id;
                    cout << "Enter id of employee: ";
                    cin >> employ_id;
                    employees.deleteEmployee(employ_id);
                    cout << "Info of employ deleted successfully" << endl;
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
                    cout << "Enter employ id: ";
                    cin >> employ_id;
                    ec.showEmployeeById(employ_id);
                }
                else
                {
                    cout<<"Invalid choice!\n";
                }
            }
            else if (choice == 5)
            {
                cout << "Hope your information is updated\n";
                cout << "Thank you!";
                break;
            }
            else
            {
                cout << "Invalid choice!" << endl;
            }
        }
        else if (isLoggedIn)
        {
            cout << "---------------------------------\n";
            cout << "1.Show all Items\n";
            cout << "2.Select item\n";
            cout << "3.Search item by ID\n";
            cout << "4.Show items alphabetically\n";
            cout << "5.Show items by category\n";
            cout << "6.Exit\n";
            cout << "---------------------------------\n";
            cout << "Enter your choice: ";
            cin >> choice;
            if (choice == 1)
            {
                inventorycore.ShowAllItems();
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
                cout << "Item found successfully" << endl;
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
                cout << "Thanks for Visiting our store, please recommend other to visit here";
                break;
            }
            else
            {
                cout << "Invalid choice!" << endl;
            }
        }
        else
        {
            cout << "Invalid Choice!" << endl;
            break;
        }
    }

    return (0);
}
