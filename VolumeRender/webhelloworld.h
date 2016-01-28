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

            /// TEST
            int S = 64;
            float *_RVE = new float[S*S*S];
            for(int i=0; i<S; ++i)
                for(int j=0; j<S; ++j)
                    for(int k=0; k<S; ++k)
                        //_RVE[k+j*S+i*S*S] = float(i) / float(S-1);
                        _RVE[k+j*S+i*S*S] = 0.0 + std::rand()*(1.0-0.0)/RAND_MAX;
//                        if(k<S/4)
//                            _RVE[k+j*S+i*S*S] = 0.1;
//                        else if(k>=S/4 && k<S*3/4)
//                            _RVE[k+j*S+i*S*S] = 0.5;
//                        else if(k>=S*3/4)
//                            _RVE[k+j*S+i*S*S] = 0.9;

            VolumeRender *_render = new VolumeRender(S, _RVE, root());
            _render->setWidth(800);
            _render->setHeight(600);
            root()->addWidget(_render);

        }
        /// Common destructor
        public : ~WebHelloWorld(){}
    };
}

#endif // WEBHELLOWORLD_H

