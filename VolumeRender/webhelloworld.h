#ifndef WEBHELLOWORLD_H
#define WEBHELLOWORLD_H

// For usage of Qt native macro SIGNAL() and SLOT()
#ifndef WT_NO_SLOT_MACROS
#define WT_NO_SLOT_MACROS
#endif // WT_NO_SLOT_MACROS

// For disabling boost warnings
#ifndef BOOST_SIGNALS_NO_DEPRECATION_WARNING
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING
#endif // BOOST_SIGNALS_NO_DEPRECATION_WARNING

#include <fstream>

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WText>

#include "volumerender.h"

using namespace Wt;

namespace Web
{
    /// Main widget for web users \n
    /// (actually this is not a widget, but the WApplication, which corresponds
    /// to a user web-session, and contains the WApplication::root() main widget) \n

    class WebHelloWorld : public WApplication
    {   
        public : WebHelloWorld(const WEnvironment &env):WApplication(env)
        {
            setTitle("hello world");
            //root()->addWidget(new WText("Hello World!"));

            int S = 64;
            float rS;
            float *_RVE;

//            std::string fileName = "TestRVEInclusions.RVE";
//            std::string fileName = "TestRVEVoronoi.RVE";
            std::string fileName = "TestRVEGaussian.RVE";
//            std::string fileName = "TestRVEBezier.RVE";

            std::ifstream _RVEFileStream;
            try
            {
                _RVEFileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
                _RVEFileStream.open(fileName, std::ios::in | std::ios::binary);
                if (_RVEFileStream.is_open())
                {
                    _RVEFileStream.seekg(0, std::ios::beg);
                    _RVEFileStream.read((char*)&S, sizeof(int));
                    _RVEFileStream.read((char*)&rS, sizeof(float));
                    _RVE = new float[S*S*S];
                    try
                    {
                        _RVEFileStream.read((char*)_RVE, S*S*S*sizeof(float));
                    }
                    catch(std::exception &e)
                    {
                        delete [] _RVE;
                        _RVEFileStream.close();
                        throw(e);
                    }
                    _RVEFileStream.close();
                }
            }
            catch(std::exception &e)
            {
                if(_RVEFileStream.is_open())
                    _RVEFileStream.close();
                std::stringstream _str;
                _str << e.what() << "\n";
                if(_RVEFileStream.fail() || _RVEFileStream.eof() || _RVEFileStream.bad())
                    _str << "  failbit: " << _RVEFileStream.fail() <<"\n"
                         << "  eofbit: " << _RVEFileStream.eof() <<"\n"
                         << "  badbit: " << _RVEFileStream.bad() <<"\n";
                std::cout << _str.str();
                throw(std::runtime_error(_str.str()));
            }

//            /// TEST
//            int S = 64;
//            float *_RVE = new float[S*S*S];
//            for(int i=0; i<S; ++i)
//                for(int j=0; j<S; ++j)
//                    for(int k=0; k<S; ++k)
//                        _RVE[k+j*S+i*S*S] = float(k+j*S+i*S*S) / float(S*S*S);
//            for(int i=S/4; i<S*3/4; ++i)
//                for(int j=S/4; j<S*3/4; ++j)
//                    for(int k=S/4; k<S*3/4; ++k)
//                        _RVE[k+j*S+i*S*S] = float((S-k)+(S-j)*S+(S-i)*S*S) / float(S*S*S);
////                        _RVE[k+j*S+i*S*S] = 0.0 + std::rand()*(1.0-0.0)/RAND_MAX;
////                        if(k<S/4)
////                            _RVE[k+j*S+i*S*S] = 0.1;
////                        else if(k>=S/4 && k<S*3/4)
////                            _RVE[k+j*S+i*S*S] = 1.0;
////                        else if(k>=S*3/4)
////                            _RVE[k+j*S+i*S*S] = 0.5;

            VolumeRender *_render = new VolumeRender(S, _RVE, root());
            _render->setWidth(1200);
            _render->setHeight(650);
//            _render->setWidth(env.screenWidth());
//            _render->setHeight(env.screenHeight());
            root()->addWidget(_render);

        }
        /// Common destructor
        public : ~WebHelloWorld(){}
    };
}

#endif // WEBHELLOWORLD_H

