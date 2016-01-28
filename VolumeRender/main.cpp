#include "webserver.h"
#include <QCoreApplication>

int main(int argc, char** argv)
{
    QCoreApplication _app(argc, argv);

    Web::WebServer server;
    server.startServer();

    _app.exec();
}
