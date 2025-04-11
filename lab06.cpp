#include <iostream> //cout, cin zereg std sang ashiglakhiin tuld oruulsan
#include <string.h> //strcpy, strlen zereg C-iin temdegt mur (char*) udirdakh funktsiig ashiglakhiin tuld
#include <cmath> // M_PI, sqrt gekh med mathematiciig funktsiig ashiglakhiin tuld
using namespace std;

//Durs class, abstract class buguud busad 2d dursuud (twod) uunees ubluj abna
class shape {
protected:
    char *name; //dursnii neriig khadgalakh char* turliin khuvtsagch
public:
    shape() : name(nullptr) {} //ankhdagch baiguulagch
    virtual ~shape() { delete[] name; } //sanakh oid dinamic new ashignaj sankh oi nuutsulsun name iig chuluuln
    char *get_name() { return this->name; } //name butsaana
    void set_name(const char *n) { //shine name oruulakh funkts
        if (name != nullptr) //umnun name baigaa esekhiig shalgaj shine name d zai gargana
            delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    virtual void print() { cout << name << " "; }
};

//2D dursuudiin angi
//twod angi n shapesaas udamjsan buguud a khuvtsagch taliin urt buyu radyusiig ilerhiilne
class twod : public shape {
protected:
    int a; 
public:
    twod(int _a) : a(_a) {}
    virtual float area() = 0; //hooson funkts
    virtual void print() {
        shape::print();
        cout << a << " ";
        cout << this->area() << endl;
    }
};
//circle ees angi n twod ees udamjsan
//circle(int _a) → a-d _a-g onooj, set_name("Circle") gej ner ugnu
class circle : public twod {
public:
    circle(int _a) : twod(_a) { set_name("Circle"); }
    float area() override {
        return M_PI * a * a;
    }
};

class square : public twod {
public:
    square(int _a) : twod(_a) { set_name("Square"); }
    float area() override {
        return a * a;
    }
};

class triangle : public twod {
public:
    triangle(int _a) : twod(_a) { set_name("Triangle"); }
    float area() override {
        return (sqrt(3) / 4) * a * a;
    }
};

int main() {
    twod *shapes[10]; //shapes khusnegt twod* turliin uusgene
    shapes[0] = new circle(5); //radius 5 tai circle objectiig usgene
    shapes[1] = new circle(4);
    shapes[2] = new circle(30);

    // Bubble sort ashiglaj bagaas n ikh ruu n eremblene
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (shapes[j]->area() > shapes[j + 1]->area()) {
                swap(shapes[j], shapes[j + 1]);
            }
        }
    }
    //eremblegdsen daraalliin dursuudiig kheblene
    cout << "Shapes sorted by area:" << endl;
    for (int i = 0; i < 3; i++) {
        shapes[i]->print();
    }

    // chuluulukh
    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }

    return 0;
} 
