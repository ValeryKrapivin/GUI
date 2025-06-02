#include <QApplication>
#include "ServerAdminWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ServerAdminWindow window;
    window.show();
    return app.exec();
}
