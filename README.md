# Grocery Store Management System

## Overview
The Grocery Store Management System is a comprehensive application designed to help manage various aspects of a grocery store, including inventory management, customer handling, billing, and employee management. This system provides both admin and customer functionalities, allowing users to perform operations based on their roles.

## Features

### Admin Features
- **User Authentication**: Admins can sign up and log in to access the system.
- **Inventory Management**: 
  - Add new items to the inventory.
  - Update existing item prices.
  - Delete items from the inventory.
  - Search for items by ID.
  - View items in alphabetical order.
  - Filter items by category.
- **Customer Management**: 
  - Search for customers using phone numbers.
- **Billing System**: 
  - Fetch sales data.
  - View the number of billings.
- **Employee Management**: 
  - Add new employees.
  - Update employee salaries.
  - Delete employee records.
  - Search for employees by name or ID.

### Customer Features
- **User Authentication**: Customers can sign up and log in to make purchases.
- **View Inventory**: 
  - Browse all available items.
  - Search for items by ID.
  - View items in alphabetical order.
  - Filter items by category.
- **Purchase Items**: 
  - Select items and specify quantities for purchase.
  - Receive a detailed receipt after the purchase.
- **Customer Details**: 
  - Search for customer details using their phone number for billing purposes.

## Team Members
- **Yuvraj Chopra**: Database (CSV files) design; wrote `fileHandling.h` and `coreFunctionality.h`.
- **Parth Kohli**: Worked on `main.cpp` and assisted with `coreFunctionality.h`.
- **Navkirat Singh**: Worked on `coreFunctionality.h` and `main.cpp`.

## Setup Instructions

### Prerequisites
- Ensure you have a C++ compiler installed on your system.
- Basic understanding of C++ programming.

### Installation Steps
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/grocery-store-management-system.git
   cd grocery-store-management-system
   ```
2. **Create the Database Folder:**
- Manually create a folder named `db` in the root directory of the project. This folder will contain the CSV files for data storage.
3. **Run the Application:**
- Compile and run the `main.cpp` file:

## Usage Instructions
- Follow the on-screen prompts for signing up, logging in, and accessing different features based on your role (admin or customer).
- Admins can manage inventory, customers, billing, and employee details, while customers can view items and make purchases.
- Customers should ensure their phone number is registered for billing purposes.

## Contributions
Feel free to fork the repository and submit pull requests with improvements or new features! For any issues, please raise them in the GitHub issue tracker.

## License
This project is licensed under the MIT License.
