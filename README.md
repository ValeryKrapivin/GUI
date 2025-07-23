This project implements a graphical administrator interface for managing the server, displaying messages and a list of users, as well as providing functions for banning and disconnecting users.
The interface is built using the Qt framework.
Project structure
main.cpp — entry point to the application, creates and displays the main window.
ServerAdminWindow.h — declaration of the main window class, defining the interface and basic functions.
ServerAdminWindow.cpp — implementation of class methods, interface setup, and event handling logic.
Main functions
View messages in a table.
View a list of users.
Select a user to perform actions:
Ban (ban a user).
Disable a user.
Simple dummy data loading (in a real implementation - connecting to a database).
