#include <iostream> 
#include <cstring> //strcpy(), strlen()
#include <cmath> // M_PI, sqrt()
using namespace std;


//Shape class
class shape {
protected:
    char *name; //Дүрсийн нэр хадгалах
public:
    shape() : name(nullptr) {} //Анхдагч байгуулагч
    virtual ~shape() { delete[] name; } //name-г санах ойгоос чөлөөлөх
    char *get_name() { return this->name; } 
    void set_name(const char *n) { 
        if (name != nullptr) 
            delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    virtual void print() { cout << name << " "; }
};


class twod : public shape {
protected:
    int a;
public:
    twod(int _a) : a(_a) {}
    virtual float area() = 0; //хоосон функц
    virtual void print() {
        shape::print();
        cout << a << " ";
        cout << this->area() << endl;
    }
};
class circle : public twod {
public:
    circle(int _a) : twod(_a) { set_name("Circle"); }
    float area() override {
        return M_PI * a * a;
    }
};




class square : public twod
{
public:
    square(int _a) : twod(_a) 
    {
        set_name("Square");
    }
    float area()
    {
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


int main()
{
    int size;
    cout<<"heden durs oruulah ve?: "<<endl;
    cin>>size;
    twod **shapes = new twod*[size];  //twod* руу заасан динамик массив зарлаж байна.
    for(int i=0; i<size; i++){
        int k;
        int a;
        cout<<"durs "<<i<<": "<<endl<<"1. Square"<<endl<<"2. Triangle"<<endl<<"3. Circle"<<endl;
        cin>>k;
        cout<<"a: ";
        cin>>a;
        switch (k)
        {
        case 1:
            shapes[i] = new square(a);
            break;
        case 2:
            shapes[i] = new triangle(a);
            break;
        case 3:
            shapes[i] = new circle(a);
            break;
        default:
            cout<<"Buruu songolt hiilee, dahin hiine uu: "<<endl;
            i--;
            break;
        }
    }
    // Bubble sort ашиглан талбайгаар эрэмбэлнэ.
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (shapes[j]->area() > shapes[j + 1]->area()) {
                twod *temp = shapes[j];
                shapes[j] = shapes[j+1];
                shapes[j+1] = temp;
            }
        }
    }
    //Талбайгаар эрэмбэлсэн дүрсүүдээ хэвлэнэ.
    cout << "Talbaigaar erembelegdsen ni:" << endl;
    for (int i = 0; i < size; i++) {
        shapes[i]->print();
        cout<<endl;
    }
   //Санах ойгоос чөлөөлөх
    for(int i=0; i<size; i++){
        delete shapes[i];
    }
    delete[] shapes;
    return 0;
}
