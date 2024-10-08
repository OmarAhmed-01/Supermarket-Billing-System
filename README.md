﻿# Supermarket-Billing-System
 This C++ project is a simple console-based shopping system. It features a class called shopping that handles basic functionalities for an e-commerce-like platform. The system allows administrators to manage products (add, update, remove) and provides users with the ability to browse products and generate a receipt for purchases.

Key Features:
Admin Menu:

Add Product: Allows admins to add new products to the database.
Update Product: Facilitates updating existing product details.
Delete Product: Enables the deletion of products from the database.
User Menu:

Purchase: Users can select products, specify quantities, and generate a purchase receipt.
File Management:

The project uses a text file (database.txt) to store product information, making it easy to persist and retrieve product data.
Code Overview:
Classes and Methods:

The shopping class encapsulates all functionalities, with methods like menu(), admin(), user(), add(), update(), removeProduct(), display(), and receipt().
Input/Output:

The program takes input through the console and outputs menus, product lists, and receipts.
Persistence:

Product data is stored in a text file, enabling data persistence across sessions.
This project demonstrates basic object-oriented programming principles and file handling in C++. It's suitable for beginners learning about classes, methods, file I/O, and basic data management in C++.
