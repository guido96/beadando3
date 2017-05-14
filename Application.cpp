#include "Application.h"


using namespace genv;
using namespace std;

Application::Application(int XX, int YY) : XX(XX), YY(YY) {}

void Application::background() {
    gout<<move_to(0,0)<<color(0,0,0)<<box(XX,YY);
}
void Application::hint() {
    string hintt="Hasznald a space-t az ellenorzeshez";
    gout<<move_to(XX/2-gout.twidth(hintt)/2,YY-gout.cdescent()-gout.cdescent())<<color(255,31,143)<<text(hintt);
}

void Application::game_end() {
    background();
    string grt="Gratulálok, nyertél!";
    background();
    gout<<move_to(XX/2-gout.twidth(grt)/2,YY/2)<<color(255,31,143)<<text(grt);

}
void Application::menu(event ev) {
    string play="play";
    background();
    gout<<move_to(XX/2-gout.twidth(play)/2,YY/2)<<color(255,31,143)<<box(gout.twidth(play),gout.cascent()+gout.cdescent())<<color(255,255,255)
        <<move_to(XX/2-gout.twidth(play)/2,YY/2+gout.cascent())<<text(play);
    if(ev.pos_x>XX/2-gout.twidth(play)/2 && ev.pos_x<XX/2+gout.twidth(play) && ev.pos_y>YY/2 && ev.pos_y<YY/2+20) {
        if(ev.type==ev_mouse&& ev.button==btn_left) {
            menuu=false;
        }
    }
    gout<<refresh;
}
int Application::level() {
    cout<<"Adj meg egy nehezsegi szintet, majd kattints a play-re!:)";
    int a;
    cin>>a;
    return a;
}

void Application::is_wrong(int i) {
    gout<<move_to(w[i]->x(),w[i]->y())<<color(0,0,255)<<line_to(w[i]->x()+w[i]->getSx(),w[i]->y()+w[i]->getSy());
}
void Application::run() {

    srand(time(0));
    gout.open(XX,YY);
    event ev;
    Adat a;
    vector<vector<string>>adatok = a.make();
    vector<string>line_vector;

    for(unsigned int i=0; i<adatok.size(); i++) {
        for(unsigned int j=0; j<adatok.size(); j++) {
            line_vector.push_back(adatok[i][j]);
        }
    }
    vector<int>nothing_index;

    for(unsigned int i=0; i<adatok.size(); i++) {
        int a=0;
        int c=0;
        int _sy;
        for(unsigned int j=0; j<adatok.size(); j++) {
            Text* t = new Text(50+b,50+a,50,50,adatok[i][j]);
            t->write=false;
            a=a+t->getSx()+2;
            w.push_back(t);
            c++;
            _sy=t->getSy();
        }
        b=b+_sy+2;
    }
   /* menu(ev); // Nehézségi szintek beálltítása. Nem bolond biztos
    int lev=abs(level());
    if(lev==0){
        lev=1;
    }
while(lev>200){
cout<<"Tul nehez, valassz masikat!"<<endl;
lev=abs(level());
}*/
    int lev=rand()%10;//random nehézségeek
    for(unsigned int i=0; i<lev; i++) {
        d=rand() %w.size();
        w[d]->setText(0);
        w[d]->write=true;
        nothing_index.push_back(d);
    }





    Engine e;
    menuu=true;
    while(gin >> ev && ev.keycode!=key_escape) {
        if(menuu) {
            menu(ev);
            background();
        } else {
            for(unsigned int i=0; i<w.size(); i++) {
                if(!gameover) {
                    w[i]->handle(ev);
                    w[i]->draw();
                    hint();
                }
                e.ellenorzes(w,i,nothing_index,gameover,line_vector);
            }
            if(ev.keycode==key_space && ev.type==ev_key) {
                for(unsigned int i=0; i<nothing_index.size(); i++) {
                    bool wrong = e.ell(w,i,nothing_index,line_vector);
                    if(wrong) {
                        is_wrong(nothing_index[i]);
                    }
                }
            }
            if(gameover) {
                if(ev.type!=ev_mouse && ev.keycode==key_space) {
                    game_end();
                }
            }

            gout<<refresh;
        }
    }
}



