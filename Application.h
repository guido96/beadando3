#ifndef APPLICATION_H
#define APPLICATION_H
#include "graphics.hpp"
#include "Engine.h"
#include "Adat.h"
#include "Widget.h"
#include "Text.h"
#include  <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>

class Application {
public:
    Application(int XX, int YY);
    virtual void run();
    virtual void background();
    virtual void game_end();
    void is_wrong(int i);
    int level();
    void hint();
    void menu(genv::event);
protected:
    int XX, YY,d;
    int b=0;
    bool gameover=false;
    bool menuu;
private:
    std::vector<Widget*> w;
};

#endif // APPLICATION_H
