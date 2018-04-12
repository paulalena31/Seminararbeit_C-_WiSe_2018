#include <iostream>

using namespace std;
#include <fstream>
#include <string.h>

#include "suchheader.h"

void menuFuehrung(ClXml *XmlClass, ClTxt *TxtClass);

int main()
{
    ifstream eingabe;
    ClTxt *TxtClass; //Pointer für txt
    ClXml *XmlClass; //Pointer für xml

    eingabe.open("Textdatei.txt"); //öffnet die Textdatei

    if (!eingabe)
    {
        cout << "Die Datei konnte nicht geöffnet werden." << endl;
        return 1;
    } else {
        cout <<"Die Textdatei.txt wurde erfolgreich eingelesen." << endl;
    }

    TxtClass=new ClTxt();
    TxtClass->verarbeite(eingabe);

    eingabe.close();

    eingabe.open("XML2.xml"); //öffnet die XML-Datei

    if (!eingabe)
    {
        cout << "Die Datei konnte nicht geöffnet werden." << endl;
        return 1;
    } else {
        cout << "Die XML.xml wurde erfolgreich eingelesen.\n" << endl;
    }

    XmlClass =new ClXml();
    XmlClass->ladedateien(eingabe, TxtClass);
    eingabe.close();

    menuFuehrung(XmlClass, TxtClass);
}


void menuFuehrung(ClXml *XmlClass, ClTxt *TxtClass){

    char zeichen;

    for(int i=0;i==0;){ //macht das Menü
        cout << "Menu:"<<endl
             <<"   (k)onvertieren"<<endl
            <<"   (t)xt anzeigen"<<endl
           <<"   (x)xml anzeigen"<<endl
          <<"   (h)ilfe"<<endl
         <<"   (b)eenden"<<endl<<endl
        <<"Eingabe: ";

        cin>>zeichen;

        ofstream ausgabe;
        string Dateiname = "";
        char sucheEingabe[64], suchKat;
        suchKat ='v';

        switch(zeichen){

        case 't':
            cout<< "Txt:\n";
            TxtClass->druckeelement();
            cout << endl;
            break;

        case 'x':
            cout<< "XMl:\n";
            XmlClass->druckePerson();
            cout << endl;
            break;

        case 'b':
            cout<<"Beendet";
            i=1;
            break;

        case 'h':
            cout<< "Hilfe:\n "
               <<"b: beendet das Programm \n "
               <<"t: oeffnet die Textdatei \n "
              <<"x: oeffnet die Daten der XML2-Datei und Textdatei\n "
             << "k: konvertiert beide Dateien"<<endl<<endl;

            break;

        case 'k':
            cout<<"\nWie soll die Datei heissen?\n";
            cin>>Dateiname;

            ausgabe.open(Dateiname);
            if (XmlClass->konvertAlles(ausgabe)==0) cout << "Die Datei: '" << Dateiname <<"' wurde erstellt.\n";
            else cout<<"FEHLER! Die Datei konnte nicht konvertiert werden.";
            ausgabe.close();
            break;

        default:
            cout<<"Das Zeichen \""<< zeichen << "\" kenne ich nicht."<<endl;
            break;
        }
    }
}
