
# Dokumentation
Das entwickelte Programm ist ein System für einen Verlag. Damit lassen sich Daten aus einer XML-Datei mit weiteren Daten aus einer TXT-Datei zusammenführe, welche wichtige Informationen enthält, die für den Druck eines Buches wichtig sind. Diese neuerzeugte Datei aus den beiden Ursprungsdateien wird nach der Konvertierung als XML-Datei ausgeben.
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
# TXT einlesen
• zunächst wird das Objekt "ClTxt" zum Pointer "TxtClass" erstellt
in der main Funktion wird die Textdatei geöffnet

