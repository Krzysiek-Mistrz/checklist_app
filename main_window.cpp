#include "main_window.h"
#include <QWidget>
#include <QMessageBox>
#include <QFont>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    QHBoxLayout *inputLayout = new QHBoxLayout();
    QHBoxLayout *btnLayout = new QHBoxLayout();

    taskInput = new QLineEdit(this);
    addButton = new QPushButton("Add Task", this);
    inputLayout->addWidget(taskInput);
    inputLayout->addWidget(addButton);

    taskList = new QListWidget(this);
    removeButton = new QPushButton("Remove Task", this);
    doneButton = new QPushButton("Mark as Done", this);
    btnLayout->addWidget(removeButton);
    btnLayout->addWidget(doneButton);

    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(taskList);
    mainLayout->addLayout(btnLayout);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::addTask);
    connect(removeButton, &QPushButton::clicked, this, &MainWindow::removeTask);
    connect(doneButton, &QPushButton::clicked, this, &MainWindow::markTaskDone);
}

void MainWindow::addTask() {
    QString taskText = taskInput->text();
    if (taskText.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a task.");
        return;
    }
    QListWidgetItem *item = new QListWidgetItem(taskText);
    taskList->addItem(item);
    taskInput->clear();
}

void MainWindow::removeTask() {
    QListWidgetItem *item = taskList->currentItem();
    if (!item) {
        QMessageBox::information(this, "Mark as Done", "Please select a task to mark as done.");
        return;
    }
    delete taskList->takeItem(taskList->row(item));
}

void MainWindow::markTaskDone() {
    QListWidgetItem *item = taskList->currentItem();
    if (!item) {
        QMessageBox::information(this, "Mark as Done", "Please select a task to mark as done.");
        return;
    }
    QFont font = item->font();
    font.setStrikeOut(true);
    item->setFont(font);
}