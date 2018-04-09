#include <fstream>
#include "txtheader.h"

enum XMLZustand {noise, verarbeiteId, vornameE, nachnameE, patronusE, geschlechtE, extraE};

class ClXml {
private:
    int id;
    char vorname[64];
    char nachname[64];
    char patronus[64];
    char geschlecht [64];
    char extra [256];
    char *kategorie;
    int Seitenanzahl;
    ClXml *next;

public:
    ClXml();
    void ladedateien(ifstream &datei, ClTxt *daten);              // Konstruktor. Erstellt aus Eingabedatei eine Personenliste.
    void persAusgabe();                                     // Gibt die aktuelle Person aus.

    int konvertAlles(ofstream &datei);                      // Konvertiert komplette Personenliste in Ausgabedatei.
    ClXml *durchsuche(char eingabe[64] , char zustand);

    char *getVorname(){return vorname;}
    ClXml *getNaechster(){return next;}
};
