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
    char kategorie [64];
    int Seitenanzahl;
    ClXml *next;

public:
    ClXml();
    void ladedateien(ifstream &datei, ClTxt *daten);              // Konstruktor. Erstellt aus Eingabedatei eine Personenliste.
    void persAusgabe();                                     // Gibt die aktuelle Person aus.

