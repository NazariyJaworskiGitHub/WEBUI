#include "webserver.h"

using namespace Web;

WebServer::WebServer() throw (std::exception)
{
    _myWServer = new WServer();
    /// \todo this should be at some configuration file
    char *_param[] = {
        "WebServer",
        "--docroot", ".",
        "--http-address", "0.0.0.0",
        "--http-port", "8080",
        "--approot", ".",
        "--config", "wt_config.xml",
        "--accesslog", "AccesLog.log"};
    _myWServer->setServerConfiguration(13, _param);
    _myWServer->addEntryPoint(Wt::Application, &createApplication);
}

void WebServer::startServer() throw (std::exception)
{
    _myWServer->start();
}

void WebServer::stopServer() throw (std::exception)
{
   _myWServer->stop();
}

WApplication* WebServer::createApplication(const WEnvironment& env)
{        
    WebHelloWorld *_myApp = new WebHelloWorld(env);
    return _myApp;
}

WebServer::~WebServer()
{
    if(_myWServer)
    {
        if(_myWServer->isRunning())
            _myWServer->stop();
        delete _myWServer;
    }
}
