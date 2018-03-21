#include <string.h>
using namespace std;
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "xmlheader.h"

void ClXml::persAusgabe()
{   if(id!=0){
    cout << id <<  ": Vorname " << vorname <<
            "\nNachname: " << nachname << endl
         << "Patronus " << patronus << "; Geschlecht " <<geschlecht << " extra: " << extra<< endl;
    if (next==NULL) return;
    next->persAusgabe();}
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
               /* if (daten->sucheGeburtstag(puffer)==erfolg)
                {
                    datum=daten->pAktuell();
                }
                else
                {
                    cout << "Diese ID ist unbekannt!" << endl<< "' " << puffer<<" '" << endl;
                    datum=NULL;
                    return;
                }*/
                break;
            default:
                cout << "Fehler! "<<zustand;
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
