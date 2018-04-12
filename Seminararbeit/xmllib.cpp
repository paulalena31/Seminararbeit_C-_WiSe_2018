#include <string.h>
using namespace std;
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "xmlheader.h"

void ClXml::druckePerson()
{   if(id!=0){
        cout << id <<  ": Vorname: " << vorname <<
                "\nName: " << nachname << endl
             << "Patronus: " << patronus << ";\nGeschlecht: " <<geschlecht << "\nExtra: " << extra<< endl;
        cout << "Seitenanzahl: " << Seitenanzahl << " / Kategorie: " <<kategorie << endl;
        if (next==NULL) return;
        next->druckePerson();}
}

ClXml::ClXml(){
    id=0;
    vorname[0]= '\0';
    nachname[0]= '\0';
    patronus[0]= '\0';
    geschlecht[0]= '\0';
    extra[0]= '\0';
    next=NULL;
}

void ClXml::ladedateien(ifstream &datei, ClTxt *daten)
{

    char zeichen;
    char puffer[64];
    int zaehler=0;
    enum XMLZustand zustand = noise;
    next=NULL;

    for(;;)
    {
        datei.get(zeichen);
        if(datei.eof()) break;

        switch(zeichen)
        {
        case '<':
            puffer[zaehler]='\0';
            zaehler=0;
            switch(zustand)
            {
            case noise:
                zustand=noise;
                break;
            case vornameE:
                strcpy(vorname,puffer);
                zustand=noise;
                break;
            case nachnameE:
                strcpy(nachname,puffer);
                zustand=noise;
                break;
            case patronusE:
                strcpy(patronus,puffer);
                zustand=noise;
                break;
            case geschlechtE:
                strcpy(geschlecht,puffer);
                zustand=noise;
                break;
            case extraE:
                strcpy(extra,puffer);
                next = new ClXml();
                next->ladedateien(datei, daten);
                return;
            default:
                cout << "Fehler! "<<zustand;
                break;
            }
            break;

        case '"':
            switch(zustand)
            {
            case noise:
                zaehler=0;
                zustand=verarbeiteId;
                break;
            case verarbeiteId:
                puffer[zaehler]='\0';
                zaehler=0;
                zustand=noise;
                id= atoi(puffer);

                ClTxt *RichtigeID = daten->sucheID(id);

                if (RichtigeID){
                    kategorie = RichtigeID->getKat();
                    Seitenanzahl = RichtigeID->getSeite();
                }
                else{
                    cout << "Diese ID ist unbekannt!" << endl<< "'" << puffer<<"'" << endl;
                    return;
                }
                break;
            }
            break;
        case '>':
            puffer[zaehler]='\0';
            zaehler=0;

        {
            if(0==strcmp(puffer,"vorname")) zustand=vornameE;
            else if (0==strcmp(puffer,"name")) zustand=nachnameE;
            else if (0==strcmp(puffer,"patronus")) zustand=patronusE;
            else if (0==strcmp(puffer,"geschlecht")) zustand=geschlechtE;
            else if (0==strcmp(puffer,"extra")) zustand=extraE;
            else zustand=noise;
        }
            break;
        case '\n':
            break;
        case ' ':
            break;
        default:
            puffer[zaehler]=zeichen;
            zaehler++;
            break;
        }
    }
}

int ClXml::konvertAlles(ofstream &datei)
{
    if (id!=0){
        datei<<"<figur id=\""<< id << "\">"<<endl
            <<"<vorname>" << vorname << "</vorname>" <<endl
           <<"<name>"<< nachname << "</name>" <<endl
          <<"<geschlecht>"<< geschlecht << "</geschlecht>" <<endl
         <<"<extra>"<< extra << "</extra>" <<endl
        <<"<kategorie>"<< kategorie << "</kategorie>" <<endl
        <<"<seitenanzahl>"<< Seitenanzahl << "</seitenanzahl>" <<endl
        <<"</figur>"<<endl;
    }
    if (next==NULL) return 0;
    return next->konvertAlles(datei);
}
