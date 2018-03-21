
#include <iostream>

using namespace std;
#include <fstream>
#include <string.h>

#include "txtheader.h"

ClTxt::ClTxt(){
    Id=0;
    Kategorie[0]='\0';
    SeitenAnz=0;
    next=NULL;
}

void ClTxt::verarbeite(ifstream& datei)
{
    char zeichen;
    char puffer[64];
    int zaehler;

    for (datei.get(zeichen),zaehler=0;!datei.eof();datei.get(zeichen))
    {
        switch(zeichen)
        {
        case ')':
            puffer[zaehler] = '\0';
            Id= atoi(puffer);
            zaehler=0;
            break;
        case ':':
            puffer[zaehler] = '\0';
            strcpy(Kategorie,puffer);
            zaehler=0;
            break;
        case ';':
            puffer[zaehler] = '\0';
            SeitenAnz= atoi(puffer);
            zaehler=0;
            next = new ClTxt();
            next->verarbeite(datei);
            break;
        case ' ':
            break;
        default:
            puffer[zaehler] = zeichen;
            zaehler++;
            break;
        }
    }
}

void ClTxt::druckeelement()
{
    if(Id!=0)cout << Id << ") " << Kategorie << ": " << SeitenAnz<<";\n";
    if(next!=NULL)next->druckeelement();
}
