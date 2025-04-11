#include <iostream>  // cin, cout function ashiglakh
#include <cstring>   // strcpy(), strlen() zereg function ashiglakh
#include <cmath>     // M_PI, sqrt() zereg math-iin function ashiglakh
using namespace std;

// Shape (Durs) class
class shape {
protected:
    char *name;       // Dursnii neriig khadgalakh
    static int count; // Bukh obj-iig toolokh static hibsagch
public:
    shape() : name(nullptr) { count++; }  // counstructor -object uusgekh burd count nemegdene
    virtual ~shape() { delete[] name; count--; }  // sanakh oig chuluulukh count khasagdana

    //Dursnii neriig abakh function
    char *get_name() { return this->name; }

    //Dursnii neriig tokhiruulakh function
    void set_name(const char *n) {
        if (name != nullptr)
            delete[] name; //Khuuchin neriin sanakh oig chuluulnu
        name= new char[strlen(n) + 1]; // Shine sanakh oi uusgene, gargana
        strcpy(name, n); // Neriig khuulne
    }

    virtual void print() { cout<<name<<" "; } // Dursnii neriig kheblekh

    static int get_count() { return count; } // Niit object-iin toog abakh function
};
int shape::count=0; // Static khubtsagchiin ankhnii utga

// Two-dimensional (2 Khemjeetei) shape class
class twod : public shape {
protected:
    int a;
public:
    twod(int _a) : a(_a) {}  // constructor

    virtual float area()=0;      // jinkhene hiisber function - talbai olokh
    virtual float perimeter()=0; // Jinkhen hiisber function - perimeter olokh

    virtual void print() { // Dursnii medeelliig kheblekh
        shape::print(); // Neriig kheblekh
        cout<<this->a<<" ";
        cout<<"Area: "<<this->area()<<" Perimeter: "<<this->perimeter()<<endl;
    }
};

// Circle class
class circle : public twod {
public:
    circle(int _a) : twod(_a) { set_name("Circle"); } // Constructor, neriig tokhiruulakh

    float area() override { // Talbai olokh
        return M_PI*this->a*this->a;
    }

    float perimeter() override { // Perimeter olokh
        return 2*M_PI*this->a;
    }
};

// Square class
class square : public twod {
public:
    square(int _a) : twod(_a) { set_name("Square"); } // Constructor, neriig tokhiruulakh

    float area() override { // Talbai olokh
        return this->a*this->a;
    }

    float perimeter() override { // Perimeter olokh
        return 4*this->a;
    }
};

// Triangle class
class triangle : public twod {
public:
    triangle(int _a) : twod(_a) { set_name("Triangle"); } // constructor, neriig tokhiruulakh

    float area() override { // Talbai olokh
        return (sqrt(3)/4)*this->a*this->a;
    }

    float perimeter() override { // perimeter olokh
        return 3*this->a;
    }
};

// Talbaigaar erembelekh function (Bubble Sort )
void sort_by_area(twod **shapes, int size) {
    for (int i=0; i<size; i++) {
        for (int j=0; j<size-1-i; j++) {
            if (shapes[j]->area()>shapes[j+1]->area()) {
                swap(shapes[j], shapes[j+1]); // Bagaasaa ikh ruu n eremblekh
            }
        }
    }
}

// Perimeter-eer eremblekh function (Bubble Sort)
void sort_by_perimeter(twod **shapes, int size) {
    for (int i=0; i<size; i++) {
        for (int j=0; j<size-1-i; j++) {
            if (shapes[j]->perimeter()>shapes[j+1]->perimeter()) {
                swap(shapes[j], shapes[j+1]); // Mun bagaasaa ikh ruu n eremblsen
            }
        }
    }
}

int main() {
    int size;
    cout<<"Heden durs oruulah be?: ";
    cin>>size; // kheden durs uuzgekh be toog n oruulna uu

    twod **shapes=new twod*[size]; //Dinamic khusnegt uusgekh

    for (int i=0; i<size; i++) {
        int k, a;
        cout<<"Durs "<<i<<": "<<endl<<"1. Square"<<endl<<"2. Triangle"<<endl<<"3. Circle"<<endl;
        cin>>k; //Dursnii turliig songono
        cout<<"a: ";
        cin>>a; //Taliin urtiig oruulakh

        switch (k) { // Songoltiin daguu object uusgene
            case 1: shapes[i]=new square(a); break;
            case 2: shapes[i]=new triangle(a); break;
            case 3: shapes[i]=new circle(a); break;
            default: 
                cout<<"Buruu songolt, dahin oruulna uu: "<<endl; 
                i--; // Buruu songolt khiisen bol dabtana oruulakh
                break;
        }
    }

    //Niit uusgsen objectiin toog kheblekh
    cout<<"Niit uusgesen objectiin too: "<<shape::get_count()<<endl;

    //Talbaigaar eremblekh ba kheblekh
    cout<<"Talbaigaar erembelegdsen ni:"<<endl;
    sort_by_area(shapes, size);
    for (int i=0; i<size; i++) shapes[i]->print();

    //Perimeter-eer eremblekh ba kheblekh
    cout<<"\nPerimeter eer erembelegdsen ni:"<<endl;
    sort_by_perimeter(shapes, size);
    for (int i=0; i<size; i++) shapes[i]->print();

    // Sanakh oig chuluulukh
    for (int i=0; i<size; i++) delete shapes[i]; // Object-uudiig ustgakh
    delete[] shapes; // Dinamic khusnegt uusgekh

    return 0;
}
