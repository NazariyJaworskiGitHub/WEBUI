#ifndef WEBSERVER_H
#define WEBSERVER_H

// For usage of Qt native macro SIGNAL() and SLOT()
#ifndef WT_NO_SLOT_MACROS
#define WT_NO_SLOT_MACROS
#endif // WT_NO_SLOT_MACROS

// For disabling boost warnings
#ifndef BOOST_SIGNALS_NO_DEPRECATION_WARNING
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING
#endif // BOOST_SIGNALS_NO_DEPRECATION_WARNING

#include <Wt/WServer>
#include <Wt/WApplication>

#include "webhelloworld.h"

using namespace Wt;

namespace Web
{
    /// Implements web user interface http server, at its own thread
    class WebServer
    {
        /// Wt web server
        private: WServer *_myWServer = nullptr;
        /// Creates a new user session at myWServer
        private: static WApplication *createApplication(const WEnvironment& env);
        /// Common constructor, don't forget to call startServer(),
        public : WebServer() throw (std::exception);
        /// Starts the _myWServer at its own thread
        public : void startServer() throw (std::exception);
        /// Stops the _myWServer and closes all sessions
        public : void stopServer() throw (std::exception);
        /// Returns true if server was started and is running, elese returns false
        public : bool isRunning() const {
            return _myWServer ? _myWServer->isRunning() : false;}
        /// Common destructor
        public: ~WebServer();
    };
}

#endif // WEBSERVER_H
