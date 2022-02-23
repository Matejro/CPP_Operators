// OperatoryLab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
using namespace std;

class Zespolona {
private:
    double re;
    double im;

public:
    Zespolona(double, double);
    Zespolona(double = 0.0);
    Zespolona(const Zespolona& oryginal) {
        re = oryginal.re;
        im = oryginal.im;
    };
    friend ostream& operator <<(ostream&, const Zespolona&);
    friend istream& operator >>(istream&, Zespolona&);
    Zespolona operator +(const Zespolona&);
    Zespolona operator -(const Zespolona&);
    Zespolona operator *(const Zespolona&);
    bool operator ==(const Zespolona&);
    void operator +=(const Zespolona&);
    void operator -=(const Zespolona&);
    double getRe() { return re; }
    double getIm() { return im; }
    void setRe(double re) { this->re = re; }
    void setIm(double im) { this->im = im; }
    ~Zespolona() {};
};

ostream& operator <<(ostream& os, const Zespolona& inna) {
    os <<round(inna.re * 100) / 100 << " + " << round(inna.im * 100) / 100 << "i" << endl;
    return os;
};

istream& operator >>(istream& is, Zespolona& inna) {
    is >> inna.re >> inna.im;
    return is;
};

Zespolona Zespolona::operator+(const Zespolona& y) {
    Zespolona a(re + y.re, im + y.im);
    return a;
};

Zespolona Zespolona::operator-(const Zespolona& y) {
    Zespolona a(re - y.re, im - y.im);
    return a;
};

void Zespolona::operator += (const Zespolona & y) {
    this->re += y.re;
    this->im += y.im;
};

void Zespolona::operator -= (const Zespolona& y) {
    this->re -= y.re;
    this->im -= y.im;
};

bool Zespolona::operator == (const Zespolona& y) {
    if (this->re == y.re && this->im == y.im) return true;
    else
        return false;    
};

Zespolona Zespolona::operator*(const Zespolona& y) {
    Zespolona a(re*y.re+im*y.im*(-1), re*y.im+y.re*im);
    return a;
};

Zespolona::Zespolona(double re, double im) {
    this->re = re;
    this->im = im;
};

Zespolona::Zespolona(double a) {
    this->re = a;
    this->im = a;
};


int main()
{
    char response;
    cout << "Witaj w programie liczb zespolonych\n" << "Co chcesz teraz zrobic?\n" << "N: stworz nowa liczbe zespolona (podaj dwa argumenty)\n" << "R: stworz nowa liczbe zespolona (1 argument)\n";
    cout << "W: wyœwietl wartoœæ liczby zespolonej\n" << "+: oblicz sume dwoch liczb zespolonych\n" << "-: oblicz ró¿nicê dwoch liczb zespolonych\n" << "*: oblicz iloczyn dwoch liczb zespolonych\n";
    cout << "=: porownaj dwie liczby zespolone\n" << "A: Wypisz wszystkie liczby zespolone\n"<<"K: konczy prace programu\n";
    cin >> response;
    Zespolona** a;
    a = new Zespolona * [100];
    int i = 0;

    while(toupper(response) !='K') {
        switch(toupper(response)) {
        case 'N':
            double x;
            double y;
            cout << "Podaj dwa argumenty (double)\n";            
            cin >> x >> y;
            *(a + i) = new Zespolona(x, y);
            cout << "Zostala dodana nowa liczba zespolona, znajdziesz ja pod indeksem " << i << endl;
            cout << "jej wartosc to:" << *(*(a + i)) << endl;
            i++;
            cout <<"Co chcesz teraz zrobic?\n" << "N: stworz nowa liczbe zespolona (podaj dwa argumenty)\n" << "R: stworz nowa liczbe zespolona (1 argument)\n";
            cout << "W: wyœwietl wartoœæ liczby zespolonej\n" << "+: oblicz sume dwoch liczb zespolonych\n" << "-: oblicz ró¿nicê dwoch liczb zespolonych\n" << "*: oblicz iloczyn dwoch liczb zespolonych\n";
            cout << "=: porownaj dwie liczby zespolone\n" << "A: Wypisz wszystkie liczby zespolone\n" << "K: konczy prace programu\n";
            cin >> response;
            break;
        case 'R':
            double z;
            cout << "Podaj jeden argument (double)\n";
            cin >> z;
            *(a + i) = new Zespolona(z);
            cout << "Zostala dodana nowa liczba zespolona, znajdziesz ja pod indeksem " << i << endl;
            cout << "jej wartosc to:" << *(*(a + i)) << endl;
            i++;
            cout << "Co chcesz teraz zrobic?\n" << "N: stworz nowa liczbe zespolona (podaj dwa argumenty)\n" << "R: stworz nowa liczbe zespolona (1 argument)\n";
            cout << "W: wyœwietl wartoœæ liczby zespolonej\n" << "+: oblicz sume dwoch liczb zespolonych\n" << "-: oblicz ró¿nicê dwoch liczb zespolonych\n" << "*: oblicz iloczyn dwoch liczb zespolonych\n";
            cout << "=: porownaj dwie liczby zespolone\n" << "A: Wypisz wszystkie liczby zespolone\n" << "K: konczy prace programu\n";
            cin >> response;
            break;
        case 'W':
            int j;
            cout << "Podaj indeks liczby zespolonej ktora chcesz wyswietlic\n";
            cin >> j;
            if (j >= i) cout << "Nie ma liczby pod tym indeksem\n";
            else cout <<"Wartosc wybranej liczby to"<<*(*(a + i))<<endl;
            cout << "Co chcesz teraz zrobic?\n" << "N: stworz nowa liczbe zespolona (podaj dwa argumenty)\n" << "R: stworz nowa liczbe zespolona (1 argument)\n";
            cout << "W: wyœwietl wartoœæ liczby zespolonej\n" << "+: oblicz sume dwoch liczb zespolonych\n" << "-: oblicz ró¿nicê dwoch liczb zespolonych\n" << "*: oblicz iloczyn dwoch liczb zespolonych\n";
            cout << "=: porownaj dwie liczby zespolone\n" << "A: Wypisz wszystkie liczby zespolone\n" << "K: konczy prace programu\n";
            cin >> response;
            break;
        case '+':
            int k1;
            int l1;
            cout << "Podaj indeksy liczb ktore chcesz dodac\n";
            cin >> k1>> l1;
            if (k1 >= i || l1 >= i) cout << "Nie ma liczby pod jednym z indeksow\n";
            else {
                Zespolona e1 = *(*(a + k1)) + *(*(a + l1));
                *(a + i) = &e1;
                cout << "Zostala dodana nowa liczba zespolona, znajdziesz ja pod indeksem " << i << endl;
                cout << "jej wartosc to:" << *(*(a + i)) << endl;
                i++;
            }

            
          
            cout << "Co chcesz teraz zrobic?\n" << "N: stworz nowa liczbe zespolona (podaj dwa argumenty)\n" << "R: stworz nowa liczbe zespolona (1 argument)\n";
            cout << "W: wyœwietl wartoœæ liczby zespolonej\n" << "+: oblicz sume dwoch liczb zespolonych\n" << "-: oblicz ró¿nicê dwoch liczb zespolonych\n" << "*: oblicz iloczyn dwoch liczb zespolonych\n";
            cout << "=: porownaj dwie liczby zespolone\n" << "A: Wypisz wszystkie liczby zespolone\n" << "K: konczy prace programu\n";
            cin >> response;
            break;
        case '-':
            int k2;
            int l2;
            cout << "Podaj indeksy liczb ktore chcesz odjac od siebie\n";
            cin >> k2 >> l2;
            if (k2 >= i || l2 >= i) cout << "Nie ma liczby pod jednym z indeksow\n";
            else {
                Zespolona e2 = *(*(a + k2)) - *(*(a + l2));
                *(a + i) = &e2;
                cout << "Zostala dodana nowa liczba zespolona, znajdziesz ja pod indeksem " << i << endl;
                cout << "jej wartosc to:" << *(*(a + i)) << endl;
                i++;
            }
            
            cout << "Co chcesz teraz zrobic?\n" << "N: stworz nowa liczbe zespolona (podaj dwa argumenty)\n" << "R: stworz nowa liczbe zespolona (1 argument)\n";
            cout << "W: wyœwietl wartoœæ liczby zespolonej\n" << "+: oblicz sume dwoch liczb zespolonych\n" << "-: oblicz ró¿nicê dwoch liczb zespolonych\n" << "*: oblicz iloczyn dwoch liczb zespolonych\n";
            cout << "=: porownaj dwie liczby zespolone\n" << "A: Wypisz wszystkie liczby zespolone\n" << "K: konczy prace programu\n";
            cin >> response;
            break;
        case '*':
            int k3;
            int l3;
            cout << "Podaj indeksy liczb ktore chcesz pomnozyc\n";
            cin >> k3 >> l3;
            if (k3 >= i || l3 >= i) cout << "Nie ma liczby pod jednym z indeksow\n";
            else {
                Zespolona e3 = (*(*(a + k3)))*(*(*(a + l3)));
                *(a + i) = &e3;
                cout << "Zostala dodana nowa liczba zespolona, znajdziesz ja pod indeksem " << i << endl;
                cout << "jej wartosc to:" << *(*(a + i)) << endl;
                i++;
            }
            
            cout << "Co chcesz teraz zrobic?\n" << "N: stworz nowa liczbe zespolona (podaj dwa argumenty)\n" << "R: stworz nowa liczbe zespolona (1 argument)\n";
            cout << "W: wyœwietl wartoœæ liczby zespolonej\n" << "+: oblicz sume dwoch liczb zespolonych\n" << "-: oblicz ró¿nicê dwoch liczb zespolonych\n" << "*: oblicz iloczyn dwoch liczb zespolonych\n";
            cout << "=: porownaj dwie liczby zespolone\n" << "A: Wypisz wszystkie liczby zespolone\n" << "K: konczy prace programu\n";
            cin >> response;
            break;
        case '=':
            int k4;
            int l4;
            cout << "Podaj indeksy liczb ktore chcesz porownac\n";
            cin >> k4 >> l4;
            if (*(*(a + k4)) == *(*(a + l4)))cout << "Liczby sa sobie rowne\n";
            else cout << "Liczby nie sa sobie rowne";
            cout << "Co chcesz teraz zrobic?\n" << "N: stworz nowa liczbe zespolona (podaj dwa argumenty)\n" << "R: stworz nowa liczbe zespolona (1 argument)\n";
            cout << "W: wyœwietl wartoœæ liczby zespolonej\n" << "+: oblicz sume dwoch liczb zespolonych\n" << "-: oblicz ró¿nicê dwoch liczb zespolonych\n" << "*: oblicz iloczyn dwoch liczb zespolonych\n";
            cout << "=: porownaj dwie liczby zespolone\n" << "A: Wypisz wszystkie liczby zespolone\n" << "K: konczy prace programu\n";
            cin >> response;
            break;
        case 'A':
            for (int j = 0; j < i; j++) {
                cout << "Liczba zespolona o indeksie " << j << " ma wartosc: " << *(*(a + j)) << endl;
            }
            cout << "Co chcesz teraz zrobic?\n" << "N: stworz nowa liczbe zespolona (podaj dwa argumenty)\n" << "R: stworz nowa liczbe zespolona (1 argument)\n";
            cout << "W: wyœwietl wartoœæ liczby zespolonej\n" << "+: oblicz sume dwoch liczb zespolonych\n" << "-: oblicz ró¿nicê dwoch liczb zespolonych\n" << "*: oblicz iloczyn dwoch liczb zespolonych\n";
            cout << "=: porownaj dwie liczby zespolone\n" << "A: Wypisz wszystkie liczby zespolone\n" << "K: konczy prace programu\n";
            cin >> response;
            break;
        case 'K':
            for (int j = 0; j < i; j++) {
                delete* (a + j);
            }            
            break;
        default:
            cout << "Nie ma takiej opcji\n";
            cout << "Co chcesz teraz zrobic?\n" << "N: stworz nowa liczbe zespolona (podaj dwa argumenty)\n" << "R: stworz nowa liczbe zespolona (1 argument)\n";
            cout << "W: wyœwietl wartoœæ liczby zespolonej\n" << "+: oblicz sume dwoch liczb zespolonych\n" << "-: oblicz ró¿nicê dwoch liczb zespolonych\n" << "*: oblicz iloczyn dwoch liczb zespolonych\n";
            cout << "=: porownaj dwie liczby zespolone\n" << "A: Wypisz wszystkie liczby zespolone\n" << "K: konczy prace programu\n";
            cin >> response;
        }
    }    
    delete[] a;
    cout << "Do zobaczenia!\n";
    /*Zespolona z(1,2);
    Zespolona x(1, 2);
    Zespolona y = z + x;
    if (z == x) cout << true<<endl;
    else
        cout << false<<endl;
    cout << z * x;
    z += x;
    cout << z;*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
