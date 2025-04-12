#include "main_window.h"
#include <QWidget>
#include <QMessageBox>
#include <QFont>

/**
 * @brief Constructs a new MainWindow widget.
 *
 * Creates a window with a text input field at the top, a list of tasks in the
 * middle, and three buttons at the bottom: "Add Task", "Remove Task", and
 * "Mark as Done". The buttons are connected to the addTask, removeTask, and
 * markTaskDone slots, respectively.
 *
 * @param parent The parent of the widget.
 */
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

/**
 * @brief Adds a new task to the task list.
 *
 * Retrieves the text from the task input field and adds it as a new
 * item in the task list. If the input field is empty, a warning message
 * is displayed prompting the user to enter a task. After a task is added,
 * the input field is cleared.
 */
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

/**
 * @brief Removes the currently selected task from the task list.
 *
 * Checks if a task is selected in the task list. If no task is selected,
 * an information message is displayed to prompt the user to select a task.
 * If a task is selected, it is removed from the task list.
 */
void MainWindow::removeTask() {
    QListWidgetItem *item = taskList->currentItem();
    if (!item) {
        QMessageBox::information(this, "Mark as Done", "Please select a task to mark as done.");
        return;
    }
    delete taskList->takeItem(taskList->row(item));
}

/**
 * @brief Strikes out the currently selected task in the task list.
 *
 * Checks if a task is selected in the task list. If no task is selected,
 * an information message is displayed to prompt the user to select a task.
 * If a task is selected, it is marked as done by striking out the text.
 */
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