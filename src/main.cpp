#include <QApplication>
#include <QFile>
#include "main_window.hpp"

/**
 * @brief Main function for the To-Do List App.
 *
 * Sets up a QApplication, loads a stylesheet from "style.qss", and
 * creates a MainWindow, setting its window title and showing it.
 *
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 * @return The result of QApplication::exec().
 */
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QFile file("style.qss");
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        app.setStyleSheet(styleSheet);
        file.close();
    }

    MainWindow window;
    window.setWindowTitle("To-Do List App");
    window.show();

    return app.exec();
}