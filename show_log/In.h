#ifndef IN_H
#define IN_H
#include "Show.h"
#include <vector>
class In {
    private:
        std::string name;
        std::string pass;
        std::vector<Show> shows;
    public:
        std::vector<Show>* getShows();
        void onStart();
};
#endif