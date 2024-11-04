#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Users
{
public:
    void signup(const string &name, const string &email, const string &password, bool isAdmin,const string &PhoneNumber)
    {
        ofstream fout("db/users.csv", ios::out | ios::app);

        if (!fout)
        {
            cerr << "Error opening file for writing." << endl;
            return;
        }

        fout << name << ","
             << email << ","
             << password << ","
             << PhoneNumber<<","
             << (isAdmin ? "1" : "0") << endl;


        fout.close();
    }
    vector<string> login(const string &email, const string &password)
    {
        ifstream fin("db/users.csv");

        if (!fin)
        {
            cerr << "Error opening file for reading." << endl;
            return {};
        }

        string line;
        while (getline(fin, line))
        {
            stringstream s(line);
            vector<string> row;
            string word;

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            if (row.size() == 5 && email == row[1] && password == row[2])
            {
                cout << "Welcome " << row[0] << endl;
                return {row[0], row[4]};
            }
        }

        cout << "Invalid email or password." << endl;
        return {};
    }
};

class Inventory
{
public:
    void addItem(const string &itemId, const string &itemName, const string &price, const string &category)
    {
        ofstream fout("db/inventory.csv", ios::out | ios::app);

        if (!fout)
        {
            cerr << "Error opening file for writing." << endl;
            return;
        }

        fout << itemId << ","
             << itemName << ","
             << price << ","
             << category << endl;

        fout.close();
    }

    void updateItemPrice(const string &itemId, const string &updatedPrice)
    {
        ifstream fin("db/inventory.csv");
        if (!fin)
        {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        vector<string> updatedLines;
        string line;
        bool itemFound = false;

        while (getline(fin, line))
        {
            stringstream s(line);
            vector<string> row;
            string word;

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            if (row.size() == 4 && row[0] == itemId)
            {
                row[2] = updatedPrice;
                itemFound = true;
            }

            updatedLines.push_back(row[0] + "," + row[1] + "," + row[2] + "," + row[3]);
        }

        fin.close();

        if (itemFound)
        {
            ofstream fout("db/inventory.csv", ios::out | ios::trunc);
            if (!fout)
            {
                cerr << "Error opening file for writing." << endl;
                return;
            }

            for (const string &updatedLine : updatedLines)
            {
                fout << updatedLine << endl;
            }

            fout.close();
            cout << "Price updated successfully." << endl;
        }
        else
        {
            cout << "Item not found." << endl;
        }
    }

    void deleteItem(const string &itemId)
    {
        ifstream fin("db/inventory.csv");
        if (!fin)
        {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        vector<string> updatedLines;
        string line;
        bool itemFound = false;

        while (getline(fin, line))
        {
            stringstream s(line);
            vector<string> row;
            string word;

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            if (row.size() == 4 && row[0] == itemId)
            {
                itemFound = true;
                continue;
            }

            updatedLines.push_back(line);
        }

        fin.close();

        if (itemFound)
        {
            ofstream fout("db/inventory.csv", ios::out | ios::trunc);
            if (!fout)
            {
                cerr << "Error opening file for writing." << endl;
                return;
            }

            for (const string &updatedLine : updatedLines)
            {
                fout << updatedLine << endl;
            }

            fout.close();
            cout << "Item deleted successfully." << endl;
        }
        else
        {
            cout << "Item not found." << endl;
        }
    }
};

class Employees
{
public:
    void addEmployee(const string &empId, const string &name, const string &salary)
    {
        ofstream fout("db/employees.csv", ios::out | ios::app);

        if (!fout)
        {
            cerr << "Error opening file for writing." << endl;
            return;
        }

        fout << empId << ","
             << name << ","
             << salary << endl;

        fout.close();

        cout << "Employee added successfully." << endl;
    }

    void updateEmployeeSalary(const string &empId, const string &newSalary)
    {
        ifstream fin("db/employees.csv");
        if (!fin)
        {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        vector<string> updatedLines;
        string line;
        bool employeeFound = false;

        while (getline(fin, line))
        {
            stringstream s(line);
            vector<string> row;
            string word;

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            if (row.size() == 3 && row[0] == empId)
            {
                row[2] = newSalary; // Update the salary
                employeeFound = true;
            }

            updatedLines.push_back(row[0] + "," + row[1] + "," + row[2]);
        }

        fin.close();

        if (employeeFound)
        {
            ofstream fout("db/employees.csv", ios::out | ios::trunc);
            if (!fout)
            {
                cerr << "Error opening file for writing." << endl;
                return;
            }

            for (const string &updatedLine : updatedLines)
            {
                fout << updatedLine << endl;
            }

            fout.close();
            cout << "Employee salary updated successfully." << endl;
        }
        else
        {
            cout << "Employee not found." << endl;
        }
    }

    void deleteEmployee(const string &empId)
    {
        ifstream fin("db/employees.csv");
        if (!fin)
        {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        vector<string> updatedLines;
        string line;
        bool employeeFound = false;

        while (getline(fin, line))
        {
            stringstream s(line);
            vector<string> row;
            string word;

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            if (row.size() == 3 && row[0] == empId)
            {
                employeeFound = true;
                continue;
            }

            updatedLines.push_back(line);
        }

        fin.close();

        if (employeeFound)
        {
            ofstream fout("db/employees.csv", ios::out | ios::trunc);
            if (!fout)
            {
                cerr << "Error opening file for writing." << endl;
                return;
            }

            for (const string &updatedLine : updatedLines)
            {
                fout << updatedLine << endl;
            }

            fout.close();
            cout << "Employee deleted successfully." << endl;
        }
        else
        {
            cout << "Employee not found." << endl;
        }
    }
};

#endif
