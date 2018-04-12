# Dokumentation
Ein Verlag (fiktiv) will ein neues Buch über die Charaktere der Film- und Buchreihe Harry Potter herausbringen. Dafür müssen die Figuren mit den bereits vorhandenen Fakten noch nach der Zugehörigkeit in die Kategorien „Schüler“, „Lehrer“, „Bösewicht“ und „Kreatur“ sortiert werden. Außerdem muss auch noch jeder Figur die Seitenanzahl zugeschrieben werden, die in dem Buch der jeweiligen Figur zur Verfügung steht.

Das entwickelte Programm ist ein System für diesen Verlag. Damit lassen sich Daten aus einer XML-Datei mit weiteren Daten aus einer TXT-Datei zusammenführen, welche wichtige Informationen enthalten, die für den Druck des Buches elementar sind. Diese neu erzeugte Datei aus den beiden Ursprungsdateien wird nach der Konvertierung als XML-Datei abgespeichert.
## Menü
### (k)onvertieren
•	Der erste Menüpunkt ermöglicht die Zusammenführung der beiden Datenquellen: der XML-Datei und der TXT-Datei. Der User wird nach einem beliebigen Dateinamen gefragt und die neue XML-Instanz wird im "build..."-Verzeichnis abgespeichert.
### (t)xt anzeigen
• Die TXT-Datei "Textdatei.txt", welche im Ordner "Daten" liegt, wird eingelesen und ausgeben.
### (x)ml anzeigen
• Die XML-Datei "XML2.xml", welche im Ordner "Daten" liegt, wird eingelesen, mit der Textdatei zusammengeführt und ausgeben.
### (h)ilfe
Dieser Menüpunkt gibt dem User Hilfe, falls er nicht versteht was er eingeben soll:

 - k: konvertiert beide Dateien und ermöglicht die Abspeicherung unter beliebigem Namen
 - t: öffnet die Textdatei
 - x: öffnet die XML-Datei mit den Daten der Textdatei
 - b: beendet das Programm 



### (b)eenden
•	Beendet das Programm 
## Funktionsweise
### TXT einlesen und ausgeben
*Die Datei "Textdatei.txt" muss für die Funktion des Programms im build-Verzeichnis liegen*

 - In der Main-Funktion werden die Objekte vom Typ ClTxt und ClXml     erstellt
 - Die Textdatei wird über den ifstream eingelesen 
 - Im txtheader.h sind die Variablen Id, Kategorie und Seitenanz deklariert
 - Die "verarbeite" - Funktion übergibt die eben gelesene Textdatei und sie wird in der txtlib.cpp ausgeführt
 - Die "verarbeite" - Funktion parst die Textdatei und wandelt sie in die ClTxt-Struktur um, um eine linked List zu erzeugen
 - Jedes Zeichen wird durchlaufen und nach Steuerzeichen überprüft
 - Die jeweiligen Daten in den Klassenvariablen der ClTxt werden gespeichert
 -   So wird jedes Objekt durchgegangen und ruft das nächste auf bis keines mehr folgt
 - Gibt der User im Menü "t" ein, wird die Funktion "druckeElement" aufgerufen
 - Diese wird in der txtlib.cpp ausgeführt und gibt die Variablen der Objekte des Typs ClTxt in lesbarer Schrift aus, in der die ID, Kategorie und Seitenanzahl enthalten sind

### XML einlesen, mit der Textdatei zusammenführen und ausgeben
*Für die Ausführung des Programms müssen die DTD und die XML-Datei namens "XML.xml"  im build-Verzeichnis liegen*

 - Die XML-Datei wird über den ifstream eingelesen
 - Im xmlheader.h sind die Variablen und Zustände gespeichert 
 - Die "ladeDateien" Funktion übergibt die eingelesene XML-Datei und auch die TxtClass und sie wird in der xmllib.cpp ausgeführt
 - Wie auch bei der Textdatei werden die Daten der XML geparst und nach Steuerzeichen überprüft
 - Nach den jeweiligen Zuständen werden aus dem Puffer die Daten aus der Datei in das Objekt gespeichert
 - Sobald das Zeichen ' " ' erkannt wird, wird die ID aus der XML gelesen und es wird in der ClTxt nach der ID gesucht
 - Ist "RichtigeID" ungleich 0, wird bis eof. eingelesen
 - Kategorie und Seitenanzahl werden aus der ClTxt gelesen und in der ClXml gespeichert
 - Gibt der User "x" ein, wird die Funktion "druckePerson" aufgerufen, welche die zuvor geparste Datei mit den zusammengeführten Daten aus der Textdatei ausgibt
 

### Konvertierung
*Die konvertierte XML-Datei wird sich unter dem abgespeicherten Namen im build-Verzeichnis befinden*

 - Gibt der User "k" ein, wird er erstmal nach einem Dateinnamen gefragt
 - Über den ofstream wird eine Ausgabedatei mit dem Parameter des Dateinamens geöffnet
 - Die Funktion: "konvertAlles" wird aufgerufen und schreibt die Daten des aktuellen Objekts in die neue XML-Datei
 - Es wird kontrolliert, ob es ein folgendes Objekt gibt (next) oder nicht
 - Falls ja, wird das nächste ausgeführt und die nächste Person in der Liste wird in die XML-Datei eingetragen (Rekursion)
 - Falls nicht, endet der Vorgang 
