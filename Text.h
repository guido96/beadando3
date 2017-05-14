#ifndef TEXT_H
#define TEXT_H
#include <string>
#include "Widget.h"

class Text: public Widget {
public:
    Text(int x, int y, int sx, int sy ,std::string);
    virtual ~Text();
    void setText(int s) override;
    virtual void draw() override;
    bool contains(int x, int y) override;
    virtual void handle(genv::event)override;
    std::string getText();
    std::string to_string(int numb);
    int to_int(std::string text);
    void up(genv::event);
    void up_down_draw();
    void down(genv::event);
protected:

private:
    std::string _text;
};

#endif // TEXT_H
