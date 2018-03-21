#include <iostream>

using namespace std;
#include <fstream>
#include <string.h>

#include "xmlheader.h"

int main()
{
ifstream eingabe;
char dateiname[80];
ClTxt *TxtClass;
ClXml *XmlClass;

eingabe.open("../Seminararbeit/Textdatei.txt");

if (!eingabe)
   {
   cout << "Die Datei konnte nicht geöffnet werden." << endl;
   return 1;
   }

TxtClass=new ClTxt();
TxtClass->verarbeite(eingabe);

eingabe.close();

TxtClass->druckeelement();

cout<< "\nHTML:" << endl;

eingabe.open("../Seminararbeit/XML2.xml");

if (!eingabe)
   {
   cout << "Die Datei konnte nicht geöffnet werden." << endl;
   return 1;
   }

XmlClass =new ClXml();
XmlClass->ladedateien(eingabe, TxtClass);
eingabe.close();
XmlClass->persAusgabe();

}
