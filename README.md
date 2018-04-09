
# Dokumentation
Das entwickelte Programm ist ein System für einen Verlag. Damit lassen sich Daten aus einer XML-Datei mit weiteren Daten aus einer TXT-Datei zusammenführen, welche wichtige Informationen enthalten, die für den Druck des Buches elementar sind. Diese neu erzeugte Datei aus den beiden Ursprungsdateien wird nach der Konvertierung als XML-Datei abgespeichert.
## Menü
### (k)onvertieren
•	Der erste Menüpunkt ermöglicht die Zusammenführung der beiden Datenquellen: der XML-Datei und der TXT-Datei. Der User wird nach einem beliebigen Dateinamen gefragt und die neue XML-Instanz wird abgespeichert.
### (t)xt anzeigen
• Die TXT-Datei (Textdatei.txt), welche im Ordner "Seminararbeit" liegt, wird eingelesen und ausgeben.
### (x)ml anzeigen
• Die XML-Datei (XML2.xml) wird eingelesen und ausgeben, welche im Ordner "Seminararbeit" liegt, wird eingelesen und ausgeben.
### (h)ilfe
•	Dieser Menüpunkt gibt dem User Hilfe, falls er nicht versteht was er eingeben soll:
b: beendet das Programm 
t: öffnet die Textdatei
x: öffnet die XML-Datei 
k: konvertiert beide Dateien
### (b)eenden
•	Beendet das Programm 
## Funktionsweise
### TXT einlesen und ausgeben
•In der main source wird zunächst der Pointer "TxtClass" zum Objekt "ClTxt" erstellt. (Zeile 14)
•Die Textdatei wird geöffnet (Zeile 30)
die "verarbeite" Funktion übergibt die eben geöffnete Textdatei
sie wird in der txtlib.cpp ausgeführt
Dabei wird im Switch Case Zeichen für Zeichen durchgegangen und bei bestimmten Zeichen gespeichert
danach wird über next die nächste Zeile durchgegangen

### XML einlesen und ausgeben
•XML Datei wird mittels einer DTD validiert
In der main source wird zunächst der Pointer "XmlClass" zum Objekt "ClXml" erstellt. (Zeile 15)
die Xml Datei wird geöffnet
Der Pointer zeigt auf die ladeDateien Funktion 
in der Xmllib dann aufgerufen
sie läd die txt datei
im switch case wird die XML-Datei nach Zeichen überprüft und ein jeweiliger Zustand bestimmt
diese Zustände werden in Zeile 109-116 bestimmt
über next wird beim letzten zustand wieder zur nächsten ID übergegangen
" zeigen das Schließen danach wird ID gelesen und gespeichert
zeile 92 wird nach ID in liste gesucht
pointer zur txt wird in "richtigeID" zwischen gespeichert
wenn richtigeID ungleich 0 dann wird die Datei gelesen bis endoffile (for schleife, die nur bei end of file endet) Zeile 37

### Konvertierung






