#include "Text.h"
#include "graphics.hpp"
#include <sstream>


Text::Text(int x, int y, int sx, int sy ,std::string t)
    : Widget(x,y,sx,sy), _text(t) {}

Text::~Text() {
}

std::string Text::getText() {
    return _text;
}

int Text::to_int(std::string s) {
    std::stringstream ss (s);
    int numb;
    ss >> numb;
    return numb;
}
std::string Text::to_string(int numb) {
    std::stringstream SS;
    std::string help_str;
    SS<<numb;
    SS>>help_str;
    return help_str;
}
void Text::setText(int text) {
    _text = text;
}

using namespace genv;

void Text::draw() {
    gout <<move_to(x()+sx/2-gout.twidth(_text)/2,y()+gout.cascent()/2+(sy/2))<< color(255,255,255) << text(_text);
}

bool Text::contains(int xx, int yy) {
    if(xx>x() && xx< x()+sx && yy>y() && yy<y()+sy) {
        return true;
    } else {
        return false;
    }
}
void Text::handle(event ev) {
    Widget::handle(ev);
    if(write) {
        gout<<move_to(x(),y())<<color(255,153,204)<<box(sx,sy);
        up_down_draw();
    } else {
        gout<<move_to(x(),y())<<color(255,31,143)<<box(sx,sy);
    }
    if(write && focused) {
        gout<<move_to(x(),y())<<color(122,255,149)<<box(sx,sy);
        up(ev);
        down(ev);
        if (focused && ev.type == ev_key) {
            if (49 <= ev.keycode && ev.keycode <= 58) {
                setText(ev.keycode);
            }
        }
    }
}
void Text::up_down_draw() {
    gout<<move_to(x()+sx-(sx/6),y()+(sy/3))<<color(0,0,255)<<text("+")<<
        move_to((x())+sx-(sx/6),y()+sy/2)<<line_to(x()+sx,y()+sy/2)<<
        move_to(x()+sx-(sx/6),y()+sy/2+(sy/3))<<text("-");
}
void Text::up(event ev) {
    up_down_draw();
    if(ev.pos_x>x()+sx-(sx/5) && ev.pos_x<x()+sx && ev.pos_y>y() && ev.pos_y<y()+sy/2) {
        if(ev.button==btn_left) {
            int szam=to_int(_text);
            if(szam<9)
                szam++;
            _text=to_string(szam);
        }
    }
}
void Text::down(event ev) {
    up_down_draw();
    if(ev.pos_x>x()+sx-(sx/5) && ev.pos_x<x()+sx && ev.pos_y>y()+sy/2 && ev.pos_y<y()+sy) {
        if(ev.button==btn_left) {
            int szam=to_int(_text);
            if(szam>1)
                szam--;
            _text=to_string(szam);
        }
    }
}

