#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <string>

using namespace std;

class Samochod
    {
        private:
        string marka, model, skrzynia_typ;
        int rocznik, poj, przebieg;

        public:
        Samochod(string ma, string mo, string sk, int ro, int po, int pr)
        {
            marka = ma;
            model = mo;
            skrzynia_typ =  sk;
            rocznik = ro;
            poj = po;
            przebieg = pr;
        }

        void pokaz()
        {
            cout<<marka<<"  "<<model<<"  "<<rocznik<<"r.  "<<poj<<"cm^3  "<<przebieg<<"KM  "<<skrzynia_typ<<endl;
        }
        string pokaz_marka()
        {
            return marka;
        }
        string pokaz_model()
        {
            return model;
        }
        string pokaz_skrzynia()
        {
            return skrzynia_typ;
        }
        int pokaz_rocznik()
        {
            return rocznik;
        }
        int pokaz_poj()
        {
            return poj;
        }
        int pokaz_przebieg()
        {
            return przebieg;
        }
    };

vector <Samochod> samochody;
int wybor, rocz, poje, prz, usun;
string mar, mod, skrz, nazwa_pliku;
fstream dane;
bool zapisane=true;

void wyswietlWarTxt(string parametr, int warunek)
{
    for(int i=0; i <samochody.size(); i++)
    {
        switch(warunek)
        {
            case 1:
                if(samochody[i].pokaz_marka() == parametr) samochody[i].pokaz();
            break;
            case 2:
                if(samochody[i].pokaz_model() == parametr) samochody[i].pokaz();
            break;
            case 3:
                if(samochody[i].pokaz_skrzynia() == parametr) samochody[i].pokaz();
            break;;
        }
    }
    system("pause");
}
void wyswietlWarInt(int wartosc, int zaleznosc, int warunek)
{
    for(int i=0; i <samochody.size(); i++)
    {
        switch(warunek)
        {
            case 4:
                switch(zaleznosc)
                {
                    case 1:
                        if(samochody[i].pokaz_rocznik() > wartosc) samochody[i].pokaz();
                    break;
                    case 2:
                        if(samochody[i].pokaz_rocznik() == wartosc) samochody[i].pokaz();
                    break;
                    case 3:
                        if(samochody[i].pokaz_rocznik() < wartosc) samochody[i].pokaz();
                    break;
                }
            break;
            case 5:
                switch(zaleznosc)
                {
                    case 1:
                        if(samochody[i].pokaz_poj() > wartosc) samochody[i].pokaz();
                    break;
                    case 2:
                        if(samochody[i].pokaz_poj() == wartosc) samochody[i].pokaz();
                    break;
                    case 3:
                        if(samochody[i].pokaz_poj() < wartosc) samochody[i].pokaz();
                    break;
                }
            break;
            case 6:
                switch(zaleznosc)
                {
                    case 1:
                        if(samochody[i].pokaz_przebieg() > wartosc) samochody[i].pokaz();
                    break;
                    case 2:
                        if(samochody[i].pokaz_przebieg() == wartosc) samochody[i].pokaz();
                    break;
                    case 3:
                        if(samochody[i].pokaz_przebieg() < wartosc) samochody[i].pokaz();
                    break;
                }
            break;;
        }
    }
    system("pause");
}

void sortowanieInt(int wyb, int rodzaj, vector <Samochod> sortowane)
{
    Samochod temp = Samochod("a","a","a",0,0,0);
    switch(wyb)
    {
        case 4: //rocznik
            if(rodzaj == 1)
            {
                for(int i=0; i < sortowane.size(); i++)
                {
                    for(int j=sortowane.size()-1; j > 0; j--)
                    {
                        if(sortowane[j].pokaz_rocznik() > sortowane[j-1].pokaz_rocznik())
                        {
                            temp = sortowane[j];
                            sortowane[j] = sortowane[j-1];
                            sortowane[j-1] = temp;
                        }
                    }
                }
            }else
            {
                for(int i=0; i < sortowane.size(); i++)
                {
                    for(int j=0; j < sortowane.size()-1; j++)
                    {
                        if(sortowane[j].pokaz_rocznik() > sortowane[j+1].pokaz_rocznik())
                        {
                            temp = sortowane[j];
                            sortowane[j] = sortowane[j+1];
                            sortowane[j+1] = temp;
                        }
                    }
                }
            }
        break;
        case 5:
            if(rodzaj == 1)
            {
                for(int i=0; i < sortowane.size(); i++)
                {
                    for(int j=sortowane.size()-1; j > 0; j--)
                    {
                        if(sortowane[j].pokaz_poj() > sortowane[j-1].pokaz_poj())
                        {
                            temp = sortowane[j];
                            sortowane[j] = sortowane[j-1];
                            sortowane[j-1] = temp;
                        }
                    }
                }
            }else
            {
                for(int i=0; i < sortowane.size(); i++)
                {
                    for(int j=0; j < sortowane.size()-1; j++)
                    {
                        if(sortowane[j].pokaz_poj() > sortowane[j+1].pokaz_poj())
                        {
                            temp = sortowane[j];
                            sortowane[j] = sortowane[j+1];
                            sortowane[j+1] = temp;
                        }
                    }
                }
            }
        break;
        case 6:
            if(rodzaj == 1)
            {
                for(int i=0; i < sortowane.size(); i++)
                {
                    for(int j=sortowane.size()-1; j > 0; j--)
                    {
                        if(sortowane[j].pokaz_przebieg() > sortowane[j-1].pokaz_przebieg())
                        {
                            temp = sortowane[j];
                            sortowane[j] = sortowane[j-1];
                            sortowane[j-1] = temp;
                        }
                    }
                }
            }else
            {
                for(int i=0; i < sortowane.size(); i++)
                {
                    for(int j=0; j < sortowane.size()-1; j++)
                    {
                        if(sortowane[j].pokaz_przebieg() > sortowane[j+1].pokaz_przebieg())
                        {
                            temp = sortowane[j];
                            sortowane[j] = sortowane[j+1];
                            sortowane[j+1] = temp;
                        }
                    }
                }
            }
        break;
    }
    for(int i=0; i < sortowane.size(); i++)
    {
        cout<<i+1<<". ";
        sortowane[i].pokaz();
    }
    system("pause");
}

string idndeksDolny(string a)
{
    for(int i=0; i < a.length(); i++)
    {
        if(a[i] >=65 && a[i] <=90)
        {
            a[i]+=32;
        }
    }
    return a;
}

void sortowanieTxt(int wyb, int rodzaj, vector <Samochod> sortowane)
{
    Samochod temp = Samochod("a","a","a",0,0,0);
    switch(wyb)
    {
        case 1:
            if(rodzaj == 1)
            {
                for(int i=0; i < sortowane.size(); i++)
                {
                    for(int j=sortowane.size()-1; j > 0; j--)
                    {
                        if(idndeksDolny(sortowane[j].pokaz_marka()) > idndeksDolny(sortowane[j-1].pokaz_marka()))
                        {
                            temp = sortowane[j];
                            sortowane[j] = sortowane[j-1];
                            sortowane[j-1] = temp;
                        }
                    }
                }
            }else
            {
                for(int i=0; i < sortowane.size(); i++)
                {
                    for(int j=0; j < sortowane.size()-1; j++)
                    {
                        if(idndeksDolny(sortowane[j].pokaz_marka()) > idndeksDolny(sortowane[j+1].pokaz_marka()))
                        {
                            temp = sortowane[j];
                            sortowane[j] = sortowane[j+1];
                            sortowane[j+1] = temp;
                        }
                    }
                }
            }
        break;
        case 2:
            if(rodzaj == 1)
            {
                for(int i=0; i < sortowane.size(); i++)
                {
                    for(int j=sortowane.size()-1; j > 0; j--)
                    {
                        if(idndeksDolny(sortowane[j].pokaz_model()) > idndeksDolny(sortowane[j-1].pokaz_model()))
                        {
                            temp = sortowane[j];
                            sortowane[j] = sortowane[j-1];
                            sortowane[j-1] = temp;
                        }
                    }
                }
            }else
            {
                for(int i=0; i < sortowane.size(); i++)
                {
                    for(int j=0; j < sortowane.size()-1; j++)
                    {
                        if(idndeksDolny(sortowane[j].pokaz_model()) > idndeksDolny(sortowane[j+1].pokaz_model()))
                        {
                            temp = sortowane[j];
                            sortowane[j] = sortowane[j+1];
                            sortowane[j+1] = temp;
                        }
                    }
                }
            }
        break;
        case 3:
            if(rodzaj == 1)
            {
                for(int i=0; i < sortowane.size(); i++)
                {
                    for(int j=sortowane.size()-1; j > 0; j--)
                    {
                        if(idndeksDolny(sortowane[j].pokaz_skrzynia()) > idndeksDolny(sortowane[j-1].pokaz_skrzynia()))
                        {
                            temp = sortowane[j];
                            sortowane[j] = sortowane[j-1];
                            sortowane[j-1] = temp;
                        }
                    }
                }
            }else
            {
                for(int i=0; i < sortowane.size(); i++)
                {
                    for(int j=0; j < sortowane.size()-1; j++)
                    {
                        if(idndeksDolny(sortowane[j].pokaz_skrzynia()) > idndeksDolny(sortowane[j+1].pokaz_skrzynia()))
                        {
                            temp = sortowane[j];
                            sortowane[j] = sortowane[j+1];
                            sortowane[j+1] = temp;
                        }
                    }
                }
            }
        break;
    }
    for(int i=0; i < sortowane.size(); i++)
    {
        cout<<i+1<<". ";
        sortowane[i].pokaz();
    }
    system("pause");
}

int main()
{
    while (wybor != 9)
    {
        cout<<"PANEL GLOWNY"<<endl;
        cout<<"------------"<<endl;
        cout<<"1.Wprowadz nowy samochod"<<endl;
        cout<<"2.Wyswietl liste samochodow"<<endl;
        cout<<"3.Wyswietl liste samochodow (warunkowo)"<<endl;
        cout<<"4.Wyswietl konkretny samochod"<<endl;
        cout<<"5.Wyswietl liste samochodow (posotowana wg. pewnego parametru)"<<endl;
        cout<<"6.Usun konkretny samochod"<<endl;
        cout<<"7.Zapisz bierzacy katalog"<<endl;
        cout<<"8.Wczytaj katalog z pliku"<<endl;
        cout<<"9.Wyjdz"<<endl;
        cin >> wybor;
        system("cls");
        switch(wybor)
        {
            case 1:
                cout<<"Przy wpisywaniu spacje zastap podkreslnikiem np. 'Mercedes_Benz'"<<endl;
                cout<<"Podaj marke samochodu:"; cin>>mar;
                cout<<"Podaj model samochodu:"; cin>>mod;
                cout<<"Podaj typ skrzyni biegow samochodu (manualna czy automatyczna):"; cin>>skrz;
                cout<<"Podaj rocznik samochodu:"; cin>>rocz;
                cout<<"Podaj pojemosc silnika samochodu (w cm^3):"; cin>>poje;
                cout<<"Podaj przebieg samochodu (w KM):"; cin>>prz;

                samochody.push_back(Samochod(mar, mod, skrz, rocz, poje, prz));
                zapisane = false;
            break;
            case 2:
                for(int i=0; i < samochody.size(); i++)
                {
                    cout<<i+1<<". ";
                    samochody[i].pokaz();
                }
                system("pause");
            break;
            case 3:
            {
                int warunek, zaleznosc=0, wartosc;
                string parametr;
                cout<<"Podaj na podstawie jakiego parametru chcesz wyswietlac dane"<<endl;
                cout<<"1.Marka"<<endl;
                cout<<"2.Model"<<endl;
                cout<<"3.Typ skrzyni biegow"<<endl;
                cout<<"4.Rocznik"<<endl;
                cout<<"5.Pojemnosc"<<endl;
                cout<<"6.Przebieg"<<endl;
                cin >> warunek;
                system("cls");
                if(warunek >=1 && warunek <=3)
                {
                    cout<<"Podaj wartosc jaka ma miec dany parametr: ";
                    cin >> parametr;
                    system("cls");
                    wyswietlWarTxt(parametr, warunek);
                }else if(warunek >= 4 && warunek <= 6)
                {
                    cout<<"Podaj czy mamy wyswitlac samochody maja dana wartosc:"<<endl;
                    cout<<"1.Wieksza"<<endl;
                    cout<<"2.Taka sama"<<endl;
                    cout<<"3.Mniejsza"<<endl;
                    cin >> zaleznosc;
                    system("cls");
                    if(zaleznosc >=1 && zaleznosc <=3)
                    {
                        cout<<"Podaj wartosc: ";
                        cin >> wartosc;
                        system("cls");
                        wyswietlWarInt(wartosc, zaleznosc, warunek);
                    }else
                    {
                        cout<<"Nie ma takiego parametru do wyboru!"<<endl;
                        system("pause");
                    }
                }else
                {
                    cout<<"Nie ma takiego parametru do wyboru!"<<endl;
                    system("pause");
                }
            }
            break;
            case 4:
                int a;
                cout<<"Podaj indeks samochodu ktorego dane chcesz zoabczyc. ("<<samochody.size()<<" samochodow w katalogu):";
                cin>>a;
                system("cls");
                if(0<a && a<= samochody.size())
                {
                    samochody[a-1].pokaz();
                }else
                {
                    cout<<"Nie ma samochodu o takim indeksie w katalogu."<<endl;
                }
                system("pause");
            break;
            case 5:
                int do_sortowania, rm;
                cout<<"Podaj paramet na podstaiwe ktorego beda sortowane dane"<<endl;
                cout<<"1.Marka"<<endl;
                cout<<"2.Model"<<endl;
                cout<<"3.Typ skrzyni biegow"<<endl;
                cout<<"4.Rocznik"<<endl;
                cout<<"5.Pojemnosc"<<endl;
                cout<<"6.Przebieg"<<endl;
                cin >> do_sortowania;
                system("cls");
                if(do_sortowania >=1 && do_sortowania <=6)
                {
                    cout<<"Jak posortowac dane?"<<endl;
                    cout<<"1.Malejaco / od Z do A"<<endl;
                    cout<<"2.Rosnaco / od A do Z"<<endl;
                    cin >> rm;
                    system("cls");
                    if(rm ==1 || rm ==2)
                    {
                        if(do_sortowania <= 3)
                        {
                            sortowanieTxt(do_sortowania, rm, samochody);
                        }else
                        {
                            sortowanieInt(do_sortowania, rm, samochody);
                        }
                    }else
                    {
                        cout<<"Nie ma takiego parametru do wyboru!"<<endl;
                        system("pause");
                    }
                }else
                {
                    cout<<"Nie ma takiego parametru do wyboru!"<<endl;
                    system("pause");
                }

            break;
            case 6:
                for(int i=0; i < samochody.size(); i++)
                {
                    cout<<i+1<<". ";
                    samochody[i].pokaz();
                }
                cout<<"Wpisz nr samochodu ktorego chcesz usunac z katalogu:";
                cin >> usun;
                system("cls");
                if(0 < usun && usun <= samochody.size())
                {
                    samochody.erase(samochody.begin() + usun-1);
                    cout<<"Samochod o nr "<<usun<<" zostal usuniety. ";
                    zapisane = false;
                }else
                {
                    cout<<"Nie ma takiego nr. w rejestrze! ";
                }
                system("pause");
            break;
            case 7:
                cout<<"Podaj nazwe pliku do ktorego chcesz zapisac dany katalog (np. 'dane.txt'):";
                cin>> nazwa_pliku;
                dane.open(nazwa_pliku.c_str(), ios::out);
                for(int i=0; i < samochody.size(); i++)
                {
                    dane<<samochody[i].pokaz_marka()<<' '<<samochody[i].pokaz_model()<<' '<<samochody[i].pokaz_skrzynia()<<' '<<samochody[i].pokaz_rocznik()<<' '<<samochody[i].pokaz_poj()<<' '<<samochody[i].pokaz_przebieg()<<endl;
                }
                zapisane = true;
                dane.close();
            break;
            case 8:
                cout<<"Podaj nazwe pliku z ktorego chcesz wczytac katalog (np. 'dane.txt'):";
                cin>> nazwa_pliku;
                dane.open(nazwa_pliku.c_str(), ios::in);
                if(!dane.good())
                {
                    cout<<"Nie ma takiego pliku!"<<endl;
                    system("pause");
                }else
                {
                    samochody.clear();
                    while(!dane.eof())
                    {
                        string a, b, c;
                        int e, f, g;
                        dane>>a; dane>>b; dane>>c;
                        dane>>e; dane>>f; dane>>g;
                        if(a!="") //sprawdzam czy przypadkiem dane nie sa puste bo dotarly do konca pliku
                        {
                            samochody.push_back(Samochod(a, b, c, e, f, g));
                        }
                    }
                    cout<<"Plik zostal pomyslnie zaladowany"<<endl;
                    system("pause");
                }
                dane.close();
            break;
            case 9:
                if(!zapisane)
                {
                    int zapisac;
                    cout<<"Niektore dane nie zostaly zapisane, jestes pewien ze chcesz opuscic program?"<<endl;
                    cout<<"1.Nie"<<endl;
                    cout<<"2.Tak"<<endl;
                    cin>>zapisac;
                    switch(zapisac)
                    {
                        default: wybor=0; break;
                        case 2: break;
                    }
                }
            break;
            default: cout<<"Nie ma takiej opcji do wyboru!"<<endl; system("pause"); break;
        }
        system("cls");
    }
    return 0;
}
