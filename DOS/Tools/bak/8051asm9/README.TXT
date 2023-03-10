                            8051/32 Assembler V1.9:
                            ~~~~~~~~~~~~~~~~~~~~~~~
Beim Programm 8051ASM handelt es sich um eine graphische Oberfl?che f?r
die Intel-Programme OH, RL51, MAP2SYM, ASM51, MT und AVSIM, sowie f?r zwei
selbstdefinierbare Programme.
Die Oberfl?che ist so aufgebaut, da? man nur den Pfeilen zu folgen braucht,
um zum gew?nschten Ergebnis zu kommen.

Am wichtigsten sind wohl die Einstellungen im Setup:

* Serieller Port / Baudrate f?r die Daten?bertragung:
  Geben Sie hier die Nummer des COM-Ports und die gew?nschte Baudrate f?r die
  Daten?bertragung zur 8051/32-Platine an.
* Druckerport:
  Hier k?nnen Sie den Port angeben, an den Sie die im Men? Drucken gew?hlten
  Dateien, schicken m?chten.
* Linkparameter:
  Durch Anklicken der wei?en Eingabefelder k?nnen Sie Dateinamen von Modul-
  dateien (ohne Erweiterung) angeben, die dem aktuellen Programm beim
  Linken/Relocaten beigef?gt werden sollen. 
  Im ?brigen sollte erw?hnt werden, da? sich der 8051ASM die Namen aller
  Segmente aus dem Source-Code Ihres Programmes holt und diese als Parameter
  an den RL51 weitergibt. Aus diesem Grund m?ssen die Sourcefiles aller Module
  vorliegen. Sind bestimmte Segmente im Source-Code mittels Strichpunkt
  auskommentiert worden, so mu? dieser am Anfang der Zeile stehen, da ihn sonst
  der 8051ASM nicht erkennt.
* Relocator-/Linker Zieldatei:
  Falls die Objektdatei, die vom Relocator/Linker generiert wird nicht dem
  aktuellen Projektnamen entsprechen soll, so k?nnen Sie hier den gew?nschten
  Dateiname angeben.
* Startadresse f?r Code-, Data-, IData-, XData- & Bit-Sement:
  Geben Sie hier die Startadressen an, die dem Programm RL51 beim Relocaten
  der Monitorversion f?r das entsprechende Segment ?bergeben wird.
* 3D-Effekte:
  F?r die 3D-Buttondarstellung, mu? die Maus versteckt werden, um St?rungen
  beim Umschalten von der einen in die andere Ansicht zu vermeiden. Dieses
  Verstecken funktioniert ?ber Ihren Maustreiber und falls Sie einen
  Maustreiber besitzen, bei dem dieser Umschaltevorgang zu lange dauert, f?hrt
  dies zu einem Rucken im Programm. Falls dieser Fall eintritt, k?nnen Sie
  durch Umschalten der 3D-Effekte auf OFF dieses Ruckeln vermeiden.
* Ramsize(256):
  Nachfolgetypen des 8051 (80535,8052,..) haben einen gr??eren internen Daten-
  speicher. Um dies dem Relocator/Linker mitzuteilen, mu? diese Option
  ausgew?hlt werden.
* Projektbezogen:
  Es kommt oft vor, da? man f?r verschiedene Projekte unterschiedliche
  Setup-Einstellungen braucht, insbesondere f?r die Segmentbereiche. F?r
  diesen Fall hat der 8051 Assembler diese Option, um jedem Projektnamen ein
  eigenes Setup-File zuzuweisen.
* Hilfefenster:
  Ist diese Option aktiviert, so wird vor dem Aufruf von AVSIM und MT eine
  kurze Anleitung und vor dem Linken die ermittelten Parameter angezeigt.
* Sourcecode-Erweiterung:
  Hier k?nnen Sie angeben, welche Dateierweiterung die von Ihnen erstellen
  Sourcecode-Files haben sollen (meist .ASM oder .SRC).
* Titel des 1./2. Zusatzprogrammes:
  Vor der genaueren Beschreibung dieser Funktion, sollte gesagt werden, was
  es mit der Zusatzprogrammfunktion auf sich hat. Wollen Sie z.B. zu den
  bereits im Men? vorhandenen Punkten ein oder zwei Programme hinzuf?gen,
  k?nnen Sie dies ?ber diese Funktion erledigen. Dies findet zum Beispiel
  Anwendung, wenn Sie die Software eines Eprom-Programmers oder eines
  Simulationsprogrammes zus?tzlich in die Oberfl?che einbinden wollen.
  Unter dem Men?punkt Titel des 1./2. Zusatzprogrammes k?nnen Sie dann den
  Titel des zus?tzlichen Programmes eingeben, der im Men? erscheinen soll.
* Dateiname des 1./2. Zusatzprogrammes:
  Hier k?nnen Sie dann den Dateinamen des Zusatzprogrammes (mit Erweiterung)
  im ersten Kasten, sowie die zu ben?tzenden Parameter im zweiten Kasten
  angeben. Das aufzurufende Programm mu?! sich dabei entweder im selben Ver-
  zeichnis wie der 8051ASM, im aktuellen Arbeitsverzeichnis oder in einem der
  in der AUTOEXEC.BAT mit dem Befehl PATH festgelegten Verzeichnisse befinden.
  Wenn Sie diesem selbst definierten Programm den Projektnamen als Parameter
  ?bergeben wollen, so brauchen Sie nur an die Stelle der Parameter #P
  schreiben, wo beim Aufruf der Projektname eingef?gt werden soll. Auf die
  gleiche Weise k?nnen Sie auch den im Setup eingestellten Comport (#C) und
  die Sourcecode-Erweiterung (#S) angeben. Wenn Sie also den Sourcecode und
  den Comport an das Programm ?bergeben wollen so schreiben Sie #P#S #C .
  Bsp. f?r SIMULA5X: -i #p -s #p -8052    (f?r 8052, sonst 8051 oder 80535).

Ein weiterer wichtiger Punkt ist der Editor, der vom Hauptmen? aus durch
Anklicken von Editieren aufgerufen wird. Im Editor selbst stehen die Dateien
mit den Erweiterungen .(SRC) .M51 .LST und .TXT zur Verf?gung. Zwischen diesen
kann durch gleichzeitiges Dr?cken von ALT und einer Ziffer von 1-4
umgeschaltet werden. Weiters kann man auch im Men?punkt FENSTER den
Bildschirm teilen, um zwei Dateien gleichzeitig zu betrachten.

Der Projektname kann sowohl beim Aufruf des 8051ASM als erster Parameter
?bergeben werden, als auch im Hauptmen? im Punkt Projekt angegeben werden.
Der Projektname wird gespeichert und wenn beim n?chsten Aufruf des 8051ASM
kein anderer angegeben wird, so bleibt der alte weiterhin in Verwendung.
Die Erweiterung f?r die Sourcecode-Bezeichnung, die dem Projektnamen
angeh?ngt werden soll, kann entweder im Setup angegeben werden, als auch
beim Kommandozeilenaufruf dem Projektnamen gleich angeh?ngt werden.

Zuletzt sollte noch der Linker erw?hnt werden. Dieser wird durch den Knopf
mit der Aufschrift Linken aufgerufen. F?r die Monitorversion werden die
Linkparameter aus den Angaben im Setup gewonnen. Sind die Parameter l?nger
als 128 Zeichen, kann sie DOS nicht mehr verarbeiten. Aus diesem Grund gibt
der 8051ASM eine entsprechende Fehlermeldung aus. Die beste L?sung ist dann,
den 8051ASM mit dem Befehl DOS zu beenden, wobei an DOS das Laufwerk (au?er
wenn es Laufwerk C ist), in dem sich COMMAND.COM befindet, angeh?ngt werden
mu?, und die Parameter mittels Eingabeumleitung an den Linker weiter zu geben.
Dieser Vorgang ist kein Problem, da der 8051ASM eine entprechende Datei
automatisch generiert. Diese Datei hat die Bezeichnung <Projektname>.TXT und
kann so an den Linker weitergegeben werden:    RL51 &< <Projektname>.TXT
Dieser Vorgang mu? auch angewendet werden, wenn man nicht die automatisch
generierten Linkparameter verwenden will.

Spezial Info:
Falls der 8051ASM z.B. in einem Netzwerk betrieben werden soll und so die vom
Setup generierten Files mit Ihren Einstellungen nicht im selben Verzeichnis
wie sich der 8051ASM befindet, abgespeichert werden k?nnen, so kann dem
8051ASM beim Aufruf als Parameter der gew?nschte Pfad und der Name des
Setup-Files angegeben werden.
Bsp.: 8051ASM [<Projektname>][.Extension] i:\BSP.SET
Um diesen Vorgang zu vereinfachen, k?nnte z.B. ein Batch-File geschrieben
werden, welches diesen Parameter automatisch anh?ngt.
Zu beachten ist, da? die Setup-Datei immer die Erweiterung .SET haben mu?, da
sie sonst der 8051ASM nicht von einem Projektnamen unterscheiden kann.

Fehlerbehebung:
Gleich nach dem Start des 8051ASM kann es in einigen F?llen zu der Fehler-
meldung "Fehler beim ?ffnen/Erstellen der SETUP-Datei" kommen. Fehlerursache
k?nnte z.B. eine defekte SETUP-Datei oder die Ben?tzung eines schreib-
gesch?tzen (Netz-)Laufwerkes sein. Im ersten Fall ist die 8051ASM.SET-Datei
zu l?schen, im zweiten hingegen ist wie im Punkt "Spezial Info" beschrieben
vorzugehen.

Module:
Im Verzeichnis MODULE befinden sich einige Module zur Ansteuerung eines
Displays und eines Echtzeituhrenbausteines.

Intel-Monitor:
Im Verzeichnis RISM befinden sich mehrere Versionen des Monitor-Sourcecodes,
die sich zur Verwendung mit dem beiliegenden Programm IECM51.EXE eigenen.
Bevor man einen davon aber auf ein EPROM laden kann, mu? er erst assembliert 
und gelinkt werden.

Keil-Monitor:
Im Verzeichnis KEIL befinden sich mehrere Versionen des Monitor-Sourcecodes,
die sich zur Verwendung mit dem beiliegenden Programm MT.EXE eigenen.

                                         Christian Knei?l
V1.9.2,28.5.6
