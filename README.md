# IMT2023052 class diagram coding assignment
Banking System Demo (C++)

This project is a simple banking system simulation implemented in C++ to demonstrate object-oriented programming concepts like classes, inheritance, encapsulation, and polymorphism.

Code Overview

Customer Class

Represents a bank customer with personal details such as name, age, date of birth, PAN, Aadhar number, and credit score.

Includes a method to simulate checking balance.

Account Class (Base Class)

Stores basic account information: account holder name, account number, and password.

Provides methods to check and change passwords.

Savings Class (Derived from Account)

Represents a savings account.

Tracks balance and provides methods to add or reduce funds.

Ensures that funds cannot be reduced below the available balance.

CreditAccount Class (Derived from Account)

Represents a credit account.

Stores the credit score.

Provides methods to grant credit and pay off debts.

Admin Class

Represents an admin or manager.

Includes methods to check and change admin passwords.

Program Flow (Main Function)

Creates a customer and displays a demo balance check.

Creates a savings and credit account for the customer.

Performs basic operations:

Add and reduce balance in the savings account.

Grant credit and fill debts in the credit account.

Demonstrates password checking and updating for accounts and admin.

Prints messages to the console to simulate banking operations.

Key Concepts Demonstrated

Encapsulation: Sensitive data like passwords and balance are kept private.

Inheritance: Savings and CreditAccount classes inherit from Account.

Polymorphism (basic): Account methods are used in derived classes.

Object-Oriented Design: Clear separation between Customer, Account, and Admin functionalities.
