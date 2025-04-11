#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Ajilchin {
private:
    int dugaar;             //Ajilchinii dugaar
    char *ner;              //Ajilchinii ner
    char *albanTushaal;     //Alban tushaal
    float ajillasanTsag;    //ajillasantsagг

public:
    //Ankhdagch khubilbar (tuslamjiin uusgegch)
    Ajilchin() {
        dugaar=0;
        ner=new char[1];          //Neriin temdegtei khusnegt uusgekh
        ner[0]='\0';              //Khooson temdegt
        albanTushaal=new char[1]; //Alban tushaaliin temdegt khusnegt uusgekh
        albanTushaal[0]='\0';     //Khooson temdegt
        ajillasanTsag=0;         //Ajillasan tsag
    }

    //Parameterized baiguulagch
    Ajilchin(int d, const char *n, const char *aT, float aTsg) {
        dugaar=d;
        ner=new char[strlen(n) + 1];  //Neriin urt khemjeeg abch chine khusnegt uusgekh
        strcpy(ner, n);                  //Neriig khuulj oruulakh
        albanTushaal=new char[strlen(aT) + 1];  //Alban tushaaliin urt khemjeeg abch shine husnegt uusgekh
        strcpy(albanTushaal, aT);        //Alban tushaaliig khuulj oruulakh
        ajillasanTsag=aTsg;           //Ajillasan tsag
    }

    //Khuulagch baiguulagch
    Ajilchin(const Ajilchin &other) {
        copy(other);  //Busad objectuudiin medeelliig khuulj abakh
    }

    // Destructor (Ustgagch funkts)
    ~Ajilchin() {
        delete[] ner;           //Neriin khusnegtiig ustgakh
        delete[] albanTushaal;  //Alban tushaaliin husnegtiig ustgakh
    }

    //Khuulagch funkts
    void copy(const Ajilchin &other) {
        if (this != &other) {  //Uuriiguu butsakhgui baikh
            delete[] ner; //Umnukh khusnegtiig ustgakh
            delete[] albanTushaal; //Umnukh khusnegtiig ustgakh
            ner=new char[strlen(other.ner) + 1]; //Shine khusnegt uusgekh
            strcpy(ner, other.ner); //Medeelliig khuulj oruulakh
            albanTushaal=new char[strlen(other.albanTushaal) + 1];  //Shine khusnegtiig ustgakh
            strcpy(albanTushaal, other.albanTushaal); //Medeelliig khuulj oruulakh
            dugaar=other.dugaar; //Dugaar
            ajillasanTsag=other.ajillasanTsag;//Ajillsan tsag
        }
    }

    //Garaas ugugdul abakh funkts
    int getDugaar() const { return dugaar; }
    const char* getNer() const { return ner; }
    const char* getAlbanTushaal() const { return albanTushaal; }
    float getAjillasanTsag() const { return ajillasanTsag; }

    //Ajilchinii medeelliig delgtsend kheblekh
    void medeelliigDelgetsendHaruulah() const {
        cout<<"Dugaar: "<<dugaar<<"\nNer: "<<ner<<"\nAlban tushaal: "<<albanTushaal<<"\nAjillasan tsag: "<<ajillasanTsag<<" tsag\n";
    }
};

//Ajilchidiin nereer eremblekh funkts
void nerErembleh(vector<Ajilchin> &ajilchid) {
    int n=ajilchid.size();
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            //Khoyor ajilchinii neriig khartsuulakh
            if (strcmp(ajilchid[j].getNer(), ajilchid[j+1].getNer())>0) {
                Ajilchin temp=ajilchid[j];
                ajilchid[j]=ajilchid[j+1];
                ajilchid[j+1] =temp; // Khoyor ajilchinii bairlaliig solikh
            }
        }
    }
}

int main() {
    int n;
    cout<<"Ajilchdiin too: ";  //Ajilchidiin toog asuukh
    cin>>n;
    cin.ignore();  //Engiin muriig ugugdliin unshikhaas umnu delgtsend shine mur khayakh

    vector<Ajilchin> ajilchid;  //Ajilchidiig khadgalakh khusnegt
    for (int i=0; i<n; i++) {
        int dugaar;
        char ner[50], albanTushaal[50];
        float ajillasanTsag;

        cout<<"\nAjilchnii dugaar: ";  //Ajilchinii dugaar
        cin>>dugaar;
        cin.ignore();

        bool davhtsah=false;
        for (const auto &ajilchin : ajilchid) {
            //Dugaar davkhadsan esekhiig shalgakh
            if (ajilchin.getDugaar()==dugaar) {
                davhtsah=true;
                break;
            }
        }
        if (davhtsah) {
            cout<<"Dugaar davhtsaj baina!"<<endl;
            continue;
        }

        cout<<"Ner: ";  //Ajilchinii neriig kharyulakh
        cin.getline(ner, 50);

        cout<<"Alban tushaal: ";  //Ajilchinii alban tushaliig oruulakh
        cin.getline(albanTushaal, 50);

        cout<<"Ajillasan tsag: ";  //Ajillsan tsag
        cin>>ajillasanTsag;
        cin.ignore();

        //Shine ajilchin nemekh
        ajilchid.push_back(Ajilchin(dugaar, ner, albanTushaal, ajillasanTsag));
    }

    nerErembleh(ajilchid);  //Nereer eremblekh funkts duudakh
    cout << "\nAjilchdiin medeelel (neriin daraalalaar):" << endl;
    //Ajilchidiin medeelliig delgtsend kharuulakh
    for (const auto &ajilchin : ajilchid) {
        ajilchin.medeelliigDelgetsendHaruulah();
    }

    return 0;
}
