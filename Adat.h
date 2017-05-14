#ifndef ADAT_H
#define ADAT_H
#include <vector>
#include <iostream>


class Adat
{
    public:
        Adat();
        virtual ~Adat();
        void read();
        void mix();
        std::vector<std::vector<std::string> > make();
    private:
        std::vector<std::vector<std::string> >n;
};

#endif // ADAT_H
