
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
};




