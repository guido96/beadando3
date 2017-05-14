#include "Engine.h"


Engine::Engine() {}

void Engine::ellenorzes(std::vector<Widget*> &w, int index, std::vector<int> nothing, bool &gameover, std::vector<std::string> line_vector) {

    if(Text* t=dynamic_cast<Text*>(w[index])) {
        if(t->getText()!="") {
            for(unsigned int i=0; i<w.size(); i++) {
                if(Text* tt=dynamic_cast<Text*>(w[i])) {
                    if(tt->getText()=="") {
                        mistake=true;
                        break;
                    } else {
                        mistake=false;
                    }
                }
            }
            if (!mistake) {
                for(unsigned int i=0; i<nothing.size(); i++) {
                    if(Text* f=dynamic_cast<Text*>(w[nothing[i]])) {
                        if(line_vector[nothing[i]]==f->getText()) {
                            gameover=true;
                        } else {
                            gameover = false;
                            break;
                        }
                    }
                }
            }

        }
    }
}
bool Engine::ell(std::vector<Widget*> &w, int i, std::vector<int> nothing, std::vector<std::string> line_vector) {
    if(Text* f=dynamic_cast<Text*>(w[nothing[i]])) {
        if(line_vector[nothing[i]]!=f->getText()) {
            return true;
        }
    }
    return false;
}
