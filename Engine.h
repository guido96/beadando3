#ifndef ENGINE_H
#define ENGINE_H
#include "Text.h"
#include <vector>


class Engine
{
    public:
        Engine();
        ~Engine(){};
        bool ell(std::vector<Widget*> &w, int index, std::vector<int> nothing, std::vector<std::string> line_vektor);
        void ellenorzes(std::vector<Widget*> &w, int index, std::vector<int> nothing, bool &gameover, std::vector<std::string> lijne_vektor);
    protected:
        bool mistake=true;
    private:
};

#endif // ENGINE_H
