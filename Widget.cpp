#include "Widget.h"

Widget::Widget(int x, int y,int sx, int sy): _x(x), _y(y), sx(sx), sy(sx), focused(false)
{}

Widget::~Widget()
{}

int Widget::x() {return _x;}
int Widget::y() {return _y;}
int Widget:: getSx(){
return sx;
}
int Widget:: getSy(){
return sy;
}
using namespace genv;

void Widget::handle(event ev){
    if (ev.type == ev_mouse && ev.button == btn_left) {
        focused = contains(ev.pos_x, ev.pos_y);
    }
}
