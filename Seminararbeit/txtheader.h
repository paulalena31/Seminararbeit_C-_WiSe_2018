enum findeID {erfolg, nichtErfolg};


class ClTxt{
private:
    int Id;
    char Kategorie[64];
    int SeitenAnz;
    ClTxt *next;
public:
    ClTxt();
    void verarbeite(ifstream& datei);
    void druckeelement();
    ClTxt *sucheID(int Identifier);
    char *getKat() {return Kategorie;}
    int getSeite() {return SeitenAnz;}
};




