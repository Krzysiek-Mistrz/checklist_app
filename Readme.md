## Overview
A Qt-based OOP to-do list application. The project includes a simple GUI that allows you to add tasks (entered by the user), remove selected tasks, and mark a task as complete by striking out the text. You can put the whole thing on GitHub to show off your OOP skills and C++ GUI libraries.

## Project Structure
ToDoListApp/
├── main.cpp
├── mainwindow.h
├── mainwindow.cpp
└── ToDoListApp.pro

## Files summary
1) In the ToDoListApp.pro file we define the project
2) In the main.cpp file we initialize the Qt application and display the main window.
3) In the file mainwindow.h we declare the MainWindow class, which inherits from QMainWindow. This class manages the graphical interface and the logic of adding, removing and marking tasks.
4) in the mainwindow.cpp file we implement the interface logic. In the methods we implement:
    addTask() – adding a task from the text entered in QLineEdit;
    removeTask() – removing the currently selected task;
    markTaskDone() – changing the task font to crossed out, which visually indicates its completion.