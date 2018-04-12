#include "xmlheader.h"

enum Zustaende {vorname, nachname, geschlecht, patronus, extra, kategorie, seitenanzahl};

class ClSuche {
private:
    ClXml *SuchErgeb;
    ClSuche *Naechster;

public:

    void sucheInXml(char eingabe[64] ,ClXml *daten, char zustand);
    void zeigeSuche();
};
