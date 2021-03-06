#ifndef MESSENGERH
#define MESSENGERH

//foward declaration
class Simulator;

#include "Request.h"

class Messenger {
    public:
        Messenger(Simulator*);

        //send message to site
        void send (int, int, int, Request*);

    private:
        Queue* timeline;
        int* weighted_delays;
        const int wd_size;

        Simulator* s;

        int compute_delivery_delay ();
};

#endif
