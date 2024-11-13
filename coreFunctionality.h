#ifndef COREFUNCTIONALITY_H
#define COREFUNCTIONALITY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

class InventoryCore
{
public:
    void ShowAllItems()
    {
        ifstream fin("db/inventory.csv");
        if (!fin)
        {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        string line;
        bool itemFound = false;
        cout << "ID,Name,Price" << endl;
        while (getline(fin, line))
        {
            stringstream s(line);
            string id, name, price;

            getline(s, id, ',');
            getline(s, name, ',');
            getline(s, price, ',');

            cout << id << "," << name << "," << price << endl;
        }

        fin.close();
    }
    void searchItemById(const string &itemId)
    {
        ifstream fin("db/inventory.csv");
        if (!fin)
        {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        string line;
        bool itemFound = false;

        while (getline(fin, line))
        {
            stringstream s(line);
            string id, name, price;

            getline(s, id, ',');
            getline(s, name, ',');
            getline(s, price, ',');

            if (id == itemId)
            {
                itemFound = true;
                cout << "Item Details:\n";
                cout << "ID: " << id << ", Name: " << name << ", Price: " << price << endl;
                break;
            }
        }

        fin.close();

        if (!itemFound)
        {
            cout << "Item with ID \"" << itemId << "\" not found." << endl;
        }
    }

    void showItemsAlphabetically()
    {
        ifstream fin("db/inventory.csv");
        if (!fin)
        {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        vector<pair<string, string>> items;
        string line;

        while (getline(fin, line))
        {
            stringstream s(line);
            string itemId, itemName, price;

            getline(s, itemId, ',');
            getline(s, itemName, ',');
            getline(s, price, ',');

            items.emplace_back(itemId, itemName);
        }

        fin.close();

        sort(items.begin(), items.end(), [](const pair<string, string> &a, const pair<string, string> &b)
             { return a.second < b.second; });

        cout << "Items in Inventory:\n";
        for (const auto &item : items)
        {
            cout << "ID: " << item.first << ", Name: " << item.second << endl;
        }
    }

    void showItemsByCategory(const string &category)
    {
        ifstream fin("db/inventory.csv");
        if (!fin)
        {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        vector<string> items;
        string line;

        while (getline(fin, line))
        {
            stringstream s(line);
            string itemId, itemName, price, itemCategory;

            getline(s, itemId, ',');
            getline(s, itemName, ',');
            getline(s, price, ',');
            getline(s, itemCategory, ',');

            if (itemCategory == category)
            {
                items.push_back("ID: " + itemId + ", Name: " + itemName + ", Price: " + price);
            }
        }

        fin.close();

        if (!items.empty())
        {
            cout << "Items in Category \"" << category << "\":\n";
            for (const auto &item : items)
            {
                cout << item << endl;
            }
        }
        else
        {
            cout << "No items found in category \"" << category << "\"." << endl;
        }
    }
};

class EmployeeCore
{
public:
    void showEmployeesByName(const string &name)
    {
        ifstream fin("db/employees.csv");
        if (!fin)
        {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        vector<string> employees;
        string line;

        while (getline(fin, line))
        {
            stringstream s(line);
            string empId, empName, salary;

            getline(s, empId, ',');
            getline(s, empName, ',');
            getline(s, salary, ',');

            if (empName == name)
            {
                employees.push_back("ID: " + empId + ", Name: " + empName + ", Salary: " + salary);
            }
        }

        fin.close();

        if (!employees.empty())
        {
            cout << "Employees with the name \"" << name << "\":\n";
            for (const auto &employee : employees)
            {
                cout << employee << endl;
            }
        }
        else
        {
            cout << "No employees found with the name \"" << name << "\"." << endl;
        }
    }

    void showEmployeeById(const string &empId)
    {
        ifstream fin("db/employees.csv");
        if (!fin)
        {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        string line;
        bool employeeFound = false;

        // Read each line from the file
        while (getline(fin, line))
        {
            stringstream s(line);
            string id, name, salary;

            getline(s, id, ',');
            getline(s, name, ',');
            getline(s, salary, ',');

            // Check if the empId matches the current line
            if (id == empId)
            {
                employeeFound = true;
                cout << "Employee Details:\n";
                cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
                break; // Stop searching after finding the employee
            }
        }

        fin.close();

        // If the employee was not found, notify the user
        if (!employeeFound)
        {
            cout << "Employee with ID \"" << empId << "\" not found." << endl;
        }
    }
};
class customerCore
{
public:
    void SearchCustomerByPhoneNumber(const string &PhoneNumber)
    {
        ifstream fin("db/users.csv");
        if (!fin)
        {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        string line;
        bool CustomerFound = false;

        while (getline(fin, line))
        {
            stringstream s(line);
            string name, phoneNumber;

            getline(s, name, ',');
            getline(s, phoneNumber, ',');

            if (phoneNumber == PhoneNumber)
            {
                CustomerFound = true;
                cout << "Item Details:\n";
                cout << "Name: " << name << ", Phone Number: " << phoneNumber << endl;
                break;
            }
            fin.close();

            if (!CustomerFound)
            {
                cout << "Customer with Name :" << name << "not found." << endl;
            }
        }
    }
};
class BillingCore
{
public:
    long int Sales;
    void print(vector<string> &items)
    {
        for (int i = 0; i < items.size(); i++)
        {
            cout << items[i] << endl;
        }
    }
    void ReceiptGenerator(vector<string> &BuyItems, const int &TotalPrice, const string &Name, const string &PhoneNumber, const string &Date)
    {

        cout << "======================================================" << endl;
        cout << "        Grocery Store - Billing Receipt         " << endl;
        cout << "======================================================" << endl;
        cout << "                                    " << endl;
        cout << " Name :" << Name << "                       " << endl;
        cout << " Phone Number:" << PhoneNumber << "                  " << endl;
        cout << " Date :" << Date << "                       " << endl;
        cout << "======================================================" << endl;
        cout << "                                    " << endl;
        cout << "Items:                 price:        quantity(in grams):" << endl;
        print(BuyItems);
        cout << "                                    " << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "Total:                 " << TotalPrice << "                        " << endl;
        cout << "======================================================" << endl;
        cout << "                                     " << endl;
        cout << "      Thanks for visiting us         " << endl;
    }
    void NoofBillings()
    {
        ifstream fin("db/receipt.csv");
        if (!fin)
        {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        string line;
        int count = 0;
        while (getline(fin, line))
        {
            count++;
        }

        fin.close();
        cout << "Total Billing: " << count << endl;
    }
    void FetchSales()
    {
        ifstream file("db/receipt.csv");
        string line, customerName, phoneNumber, itemsList;
        int totalSales = 0, price;

        if (!file.is_open())
        {
            cerr << "Error opening file!" << endl;
        }

        while (getline(file, line))
        {
            stringstream ss(line);

            getline(ss, customerName, ',');
            getline(ss, phoneNumber, ',');
            getline(ss, itemsList, ',');

            ss >> price;

            totalSales += price;
        }

        file.close();
        cout << "Total Sales: " << totalSales << endl;
    }
    void AddItemsToReciept(vector<string> &ItemsQtyArray, const string &PhoneNumber, const string &Name, const int &TotalPrice, const string &Date)
    {
        ofstream fout("db/receipt.csv", ios::out | ios::app);

        if (!fout)
        {
            cerr << "Error opening file for writing." << endl;
            return;
        }

        fout << Name << ","
             << PhoneNumber << ",[";

        for (int i = 0; i < ItemsQtyArray.size() - 1; i++)
        {
            fout << ItemsQtyArray[i] << " ";
        }
        fout << ItemsQtyArray[ItemsQtyArray.size() - 1];
        fout << "],";
        fout << TotalPrice << ",";
        fout << Date << "\n";

        fout.close();
    }
    void searchCustomerByNameInBilling(const string &Name)
    {
        ifstream fin("db/receipt.csv");
        if (!fin)
        {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        string line;
        bool itemFound = false;

        while (getline(fin, line))
        {
            stringstream s(line);
            string name, PhoneNo, Items, price, date;

            getline(s, name, ',');
            getline(s, PhoneNo, ',');
            getline(s, Items, ',');
            getline(s, price, ',');
            getline(s, date, ' ');

            if (Name == name)
            {
                itemFound = true;
                cout << "Item Details:\n";
                cout << "name: " << Name << ", phone number: " << PhoneNo << ", Items: " << Items << ", price: " << price << ",Date:" << date << endl;
                break;
            }
        }

        fin.close();

        if (!itemFound)
        {
            cout << "customer with \"" << Name << "\" not found." << endl;
        }
    }
    void ShowingBillingHistory()
    {
        ifstream fin("db/receipt.csv");
        if (!fin)
        {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        string line;
        bool itemFound = false;
        cout << "Name,Phone Number,Items,price " << endl;
        while (getline(fin, line))
        {
            stringstream s(line);
            string name, phone, arr, Price;
            getline(s, name, ',');
            getline(s, phone, ',');
            getline(s, arr, ',');
            getline(s, Price, ',');

            cout << name << ",";
            cout << phone << ",";
            cout << arr << ",";
            cout << Price << "\n";
        }

        fin.close();
    }
    void PurchasingItems()
    {

        ifstream fin("db/inventory.csv");
        if (!fin)
        {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        string line;
        bool itemFound = false;
        cout << "ID,Name,Price" << endl;
        while (getline(fin, line))
        {
            stringstream s(line);
            string id, name, price;

            getline(s, id, ',');
            getline(s, name, ',');
            getline(s, price, ',');

            cout << id << "," << name << "," << price << endl;
        }

        fin.close();

        vector<string> BuyItems;
        vector<string> ItemQtyArray;
        int TotalPrice = 0;
        string ItemId;
        string qty;
        while (true)
        {
            cout << "select the item id of an item you want to purchase or type end to discontinue:" << endl;
            cin >> ItemId;
            if (ItemId == "end")
            {
                break;
            }
            cout << "select the weight of item(in grams):" << endl;
            cin >> qty;
            ifstream fin2("db/inventory.csv");
            if (!fin2)
            {
                cerr << "Error opening file for reading." << endl;
                return;
            }

            string Secondline;
            bool itemFound = false;

            while (getline(fin2, Secondline))
            {
                stringstream s(Secondline);
                string id, name, price;

                getline(s, id, ',');
                getline(s, name, ',');
                getline(s, price, ',');

                if (id == ItemId)
                {
                    itemFound = true;

                    cout << "Item Details:\n";

                    cout << "ID: " << id << ", Name: " << name << ", Price: " << price << endl;
                    int PriceReal = stoi(price) * (stoi(qty)) / 1000;

                    string Price = to_string(PriceReal);
                    string TotalItemsAndPrice;
                    if (name.size() <= 7)
                    {
                        TotalItemsAndPrice = name + "" + "\t\t\t" + Price + "\t\t\t" + qty;
                    }
                    else if (name.size() > 15)
                    {
                        TotalItemsAndPrice = name + " \t" + Price + "\t\t\t" + qty;
                    }
                    else
                    {
                        TotalItemsAndPrice = name + "" + "  \t\t" + Price + "\t\t\t" + qty;
                    }

                    string ItemQty = name + "(" + qty + ")";

                    BuyItems.push_back(TotalItemsAndPrice);

                    ItemQtyArray.push_back(ItemQty);

                    TotalPrice += (PriceReal);

                    break;
                }
            }
            if (!itemFound)
            {
                cout << "Item with ID " << ItemId << " not found." << endl;
            }
            fin2.close();
        }
        string PhoneNo;
        string CustomerName;
        string Date;
        bool isValid = false;
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
                        break;
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
        cout << "Enter your name for Billing purposes=";
        cin >> CustomerName;
        time_t now = time(0);
        tm *ltm = localtime(&now);

        int CurrDate = ltm->tm_mday;
        int Month = 1 + ltm->tm_mon;
        int Year = 1900 + ltm->tm_year;
        

        Date = to_string(CurrDate) + "/" + to_string(Month) + "/" + to_string(Year);

        ReceiptGenerator(BuyItems, TotalPrice, CustomerName, PhoneNo, Date);

        AddItemsToReciept(ItemQtyArray, PhoneNo, CustomerName, TotalPrice, Date);
    }
};

#endif