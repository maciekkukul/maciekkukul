#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <sstream>

using namespace std;
class Auta{
    public:

    string marka;
    string model;
    int rocznik;
    string skrzynia;
    float poj;
    int przebieg;


public:
    void zapis(){
        system( "cls" );
        fstream dane;
        dane.open("samochody.txt",ios::ate | ios::in);

        cout << " Wprowadz marke: ";
        cin >> marka;
        dane  << marka << endl;

        cout << " Wprowadz model: ";
        cin >> model;
        dane  << model << endl;

        cout << " Wprowadz pojemnosc:";
        cin >> poj;
        dane  << poj << endl ;

        cout << " Wprowadz przebieg:";
        cin >> przebieg;
        dane  << przebieg << endl;


        cout<<" Wprowadz rocznik:";
        cin>>rocznik;
        dane<<rocznik<<endl;

        cout << " Wprowadz rodzaj skrzyni biegow:";
        cin >> skrzynia;
        dane  << skrzynia << endl;

    dane.close();
    }

	bool operator< (Auta & other){
		return poj < other.poj;
	}

	bool operator> (Auta & other){
		return poj > other.poj;
	}

	bool operator<= (Auta & other){
		return przebieg < other.przebieg;
	}

	bool operator>= (Auta & other){
		return przebieg > other.przebieg;
	}

	string toString(){
		std::ostringstream s;
		s << poj;
		std::string pojnap(s.str());

		std::ostringstream s2;
		s2 << przebieg;
		std::string przebiegnap(s2.str());

		std::ostringstream s3;
		s3 << rocznik;
		std::string roczniknap(s3.str());

		string napis = marka + " " + model + " " + pojnap + " " + przebiegnap + " " + roczniknap + " " + skrzynia + " " ;
		return napis;
	}
};
int n=1;
fstream dane;
Auta samochod;
vector<Auta> samochody;

void plik(){
    fstream dane;
    dane.open("samochody.txt",ios::in);
    while(!dane.eof())
    {
        dane >> samochod.marka ;
        dane >> samochod.model ;
        dane >> samochod.poj  ;
        dane >> samochod.przebieg ;
        dane >> samochod.rocznik;
        dane >> samochod.skrzynia;
        samochody.push_back(samochod);

    }
        samochody.erase(samochody.end());
    dane.close();
    }

void odczyt(){
        system( "cls" );
        dane.open("samochody.txt", ios::out);
        cout<<"Marka   Model   Pojemnosc Przebieg  rocznik   skrzynia biegow \n";
        for(int i=0;i<samochody.size();i++)
        {
                    cout << endl;
                    cout << samochody[i].toString();
        }
        dane.close();
        getch();
        system( "cls" );
        return;
        }

void odczytw(){
        int x;
        float z;
        system( "cls" );
        cout << "Wyswietl wedlug\n1.Pojemnosci\n2.Przebiegu\n";
        cin >>x;
        switch(x){
            case 1:
                cout << "Wyswietl \n1.Wieksze od danej pojemnosci \n2.Mniejsze od danej pojemnosci\n";
                cin >>x;
                 if(x==1)
                 {
                 cout << "Podaj pojemnosc ";
                 cin >> z;
                 for(int i=0;i<samochody.size();i++)
                 {
                    if(samochody[i].poj > z)
                    {
                    cout << endl;
                    cout << samochody[i].marka << " ";
                    cout << samochody[i].model << " ";
                    cout << samochody[i].poj << " ";
                    cout << samochody[i].przebieg << " ";
                    cout << samochody[i].rocznik << " ";
                    cout << samochody[i].skrzynia << " ";
                    }
                 }
                 }

                 else
                 {

                 cout << "Podaj pojemnosc ";
                 cin >> z;
                 for(int i=0;i<samochody.size();i++)
                 {
                    if(samochody[i].poj < z)
                    {
                    cout << endl;
                    cout << samochody[i].marka << " ";
                    cout << samochody[i].model << " ";
                    cout << samochody[i].poj << " ";
                    cout << samochody[i].przebieg << " ";
                    cout << samochody[i].rocznik << " ";
                    cout << samochody[i].skrzynia << " ";
                    }
                 }
                 }
                break;
            case 2:
                cout << "Wyswietl \n1.Wieksze od danego przebiegu \n2.Mniejsze od danego przebiegu\n";
                cin >>x;
                 if(x==1)
                 {
                 cout << "Podaj przebieg ";
                 cin >> x;
                 for(int i=0;i<samochody.size();i++)
                 {
                    if(samochody[i].przebieg > x)
                    {
                    cout << endl;
                    cout << samochody[i].marka << " ";
                    cout << samochody[i].model << " ";
                    cout << samochody[i].poj << " ";
                    cout << samochody[i].przebieg << " ";
                    cout << samochody[i].rocznik << " ";
                    cout << samochody[i].skrzynia << " ";

                    }
                 }
                 }

                 else
                 {
                 cout << "Podaj przebieg ";
                 cin >> x;
                 for(int i=0;i<samochody.size();i++)
                 {
                    if(samochody[i].przebieg < x)
                    {
                    cout << samochody[i].marka << " ";
                    cout << samochody[i].model << endl;
                    cout << samochody[i].poj << endl;
                    cout << samochody[i].przebieg << endl;
                    cout << samochody[i].rocznik << " ";
                    cout << samochody[i].skrzynia << " ";
                    }
                 }
                 }

                break;
        }

        dane.close();
        getch();
        system( "cls" );
        return;
        }

void odczytk(){
    int x;
    cout << "Ktory samochod pokazac?";
    cin >> x;
    x--;
    cout << endl;
    cout << samochody[x].marka << " ";
    cout << samochody[x].model << " ";
    cout << samochody[x].poj << " ";
    cout << samochody[x].przebieg << " ";
    cout << samochody[x].rocznik << " ";
    cout << samochody[x].skrzynia << " ";
    return;
}

void zapis(){

        fstream dane;
        dane.open("samochody.txt",ios::out);
        dane.clear();
        dane.close();
        dane.open("samochody.txt",ios::out);
        for(int i=0;i<samochody.size();i++)
        {
		dane << samochody[i].toString();
        dane << endl;
        }
    dane.close();
    }


void sortowanie(){
    int opcja;
        system( "cls" );
        cout << "sortuj wedlug: \n1.Pojemnosci\n2.Przebiegu\n";
        cin >>opcja;
        switch(opcja){
            case 1:{
                cout << "Sortowanie wedlug pojemnosci ";

    			for( int i = 0; i < samochody.size()-1; i++ )
    			{
					int indmin = i;
        			for( int j = i+1; j < samochody.size(); j++ )
        			{
            			if( samochody[indmin] > samochody[j])
                 			indmin = j;
        			}
        			swap(samochody[i], samochody[indmin]);
    			}
                  break;
            }


            case 2:{
                cout << "Sortowanie wedlug przebiegu";

    			for( int i = 0; i < samochody.size()-1; i++ )
    			{
					int indmin = i;
        			for( int j = i+1; j < samochody.size(); j++ )
        			{
            			if( samochody[indmin] >= samochody[j])
                 			indmin = j;
        			}
        			swap(samochody[i], samochody[indmin]);
    			}
            }
            break;
        }
}
int main()
{
    int z;
   cout << "Czy otworzyc istniejaca baze samochodow\n1.Tak\n2.Nie \n";
    cin >> z;
    if(z==1)
    plik();
    system("cls");
    while (n!=0)
    {
    cout << "MENU spisu samochodow\n1.Dodaj samochod\n2.Pokaz liste samochodow\n"
    "3.Wyswietl wedlug\n4.Wyswietl samochod z bazy\n6.Usun samochod z bazy\n7.Sortuj Samochody \n0.Zakoncz\n";
    cin >> n;
    switch(n){
        case 1:
            samochod.zapis();
            samochody.push_back(samochod);
            system( "cls" );
            break;
        case 2:

            odczyt();

            break;
        case 3:
            odczytw();
            system( "cls" );
            break;
        case 4:
            odczytk();
            getch();
            system("cls");
            break;
        case 6:
            system("cls");
            int x;
            cout << "Ktore auto usunac";
            cin >> x;
            samochody.erase(samochody.begin()+x);
            zapis();
            break;
        case 7:
            sortowanie();
            break;

            }

    }

    zapis();

    return 0;
}
