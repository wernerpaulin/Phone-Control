 
U N I C O M         (Deutsche Anleitung: Bitte nach unten blÑttern!)
===========

Terminal program for DOS

The archive contains the following programs:

UC.EXE      Terminal program for DOS, COM1 to COM4,
            with protocol analysis function for two ports
UCX.EXE     Terminal program with Bull emulation
UCN.EXE     Terminal program with INT 14 interface
UCPF.EXE    Terminal program for Atari's Portfolio hand-held PC

The menu language of Unicom is either English or German,
depending on the COUNTRY parameter in CONFIG.SYS. German
is selected for country=49. We recommend to use code page
437 (not 850) in order to display all graphic symbols
correctly.

Online help and mouse
---------------------
You will get a context-sensitive help by pressing ALT-F1
in any menu or in the main screen, or by clicking on the upper
right corner of the screen with the right mouse key.

The left mouse button or Enter accepts a selection, the right
mouse button or ESC aborts a menu or entry.

Configuration
-------------
First select a proper COM port and its settings in the
"configuration" menu. For COM3 or COM4 make sure to select
the correct address and interrupt. Do not use the same
interrupt for more than one COM port.

To start UC.EXE for a specific COM port, COM2 for instance,
enter UC /2 at the DOS command prompt.

Protocol analysis
-----------------
To watch the communication of two other sets, e.g. a computer
and a modem, you will need to make a special cable with four
connectors so that Unicom may watch the TXD data stream thru
RXD of its first port, and the RXD data thru RXD of its second
port. The data of each direction will be displayed in different
colors.

Upload and download
-------------------
Unicom supports Xmodem and Xmodem-1K for binary file transfers.
Select a block length of 128 for standard Xmodem or Xmodem-CRC,
and 1024 for Xmodem-1K.

Script files
------------
When sending a script file, some characters are interpreted:

 <  (less than)         Hangup (DTR+RTS low for 2 seconds)
 >  (greater than)      Wait for connect, i.e. until DCD=1
 '  (apostrophe)        Wait until nothing received for 1 s
 _  (underline)         Pause one second
 #  (pound symbol)      Do not interpret the next character,
                        e.g. "#>" to send ">"

Example for a script file:
ATD 123456              Dials a number
>'''''HELP              Waits for connect, pauses 5 s and
                        then enters HELP

Macros
------
You may configure macros (sequences of key strokes) which can
be executed automatically by pressing F1 to F10.

Macros may be concatenated. If you program ALT-1 (1 is the
key above the Q key, not on the numeric keypad), the program
will execute the F1 macro next.

INT 14 version
--------------
UCN.EXE is basically the same as UC.EXE, but does not address
the COM ports physically. Instead, the INT 14 software interface
is used, which is often supported by external drivers.

In order to use the online help (ALT-F1), copy UC.H? to UCN.H?
so that the required help files exist.

Atari Portfolio
---------------
UCPF.EXE is a special version for the Atari Portfolio hand-held
computer:

- No memory extension required
- Only on COM port (serial interface) supported
- Dual-speed 1200/75 bps not supported
- No DOS shell available in the file menu
- No colors (the Portfolio LCD is black/white).
- The command line option /M sets the screen format to 40 x 8
- With Unicom running, the Portfolio does not switch off automatically
- We recommend to use a mains adapter instead of batteries
- The screen mode should be static or dynamic to ensure that
  all menu items (even the ones below the bottom screen line)
  are selectable

UCX for Bull emulation
----------------------
UCX emulates a Bull VIP-73XX terminal. The following special
character sequences are interpreted:

1. ESC ` (1B 60 hex) clears the screen.
2. ESC f x y sets the cursor to column x, line y.
3. ESC s B = Blinking on.
4. ESC s R = Blinking off.
5. ESC s I is ignored.
6. ESC s L is ignored.
7. The 1st, 3rd, 5th etc LF character is ignored.
8. ESC k # is ignored (#=any character).

Please copy UC.H? to UCX.H? so that the online help is available.

Copyright
---------
(c) Shamrock Software GmbH, http://www.shamrock.de

-------------------------------------------------------------------------

U N I C O M
===========
Terminalprogramm fÅr DOS-PCs

Folgende Programme sind im Archiv enthalten:

UC.EXE      Terminalprogramm fÅr DOS-PCs, COM1 bis COM4,
            mit Protokollanalyse-Funktion fÅr zwei COM-Ports
UCX.EXE     Terminalprogramm mit Bull-Emulation
UCN.EXE     Int-14-Terminalprogramm z.B. fÅr ISDN- und LAN-Treiber
            (benutzbar mit CAPI14.COM aus den Shamrock-ISDN-Tools)
UCPF.EXE    Terminalprogramm fÅr den Atari-Portfolio

Die MenÅsprache von Unicom ist deutsch oder englisch; deutsch
wird gewÑhlt, wenn in CONFIG.SYS als Land (Country) 49 einge-
stellt ist. - Wir empfehlen Ihnen, in CONFIG.SYS bzw. AUTOEXEC.BAT
nicht die Codepage 850, sondern 437 zu wÑhlen, damit die Fenster-
rahmen korrekt dargestellt werden kînnen.

Online-Hilfe und Maus
---------------------
Sie erhalten zu jedem MenÅpunkt eine kontextsensitive Hilfe,
indem Sie entweder ALT-F1 drÅcken oder mit der Maus ins rechte
obere Bildschirm-Eck klicken.

Die linke Maustaste oder Enter bestÑtigt eine MenÅauswahl oder
Eingabe, die rechte Maustaste oder ESC dient zum Abbruch einer
MenÅfunktion oder Eingabe.

Einstellungen
-------------
Die gewÅnschte Schnittstelle kînnen Sie im MenÅ Konfig/V.24/Port
auswÑhlen. Bei COM3+COM4 sollten Sie als erstes die gewÅnschte
Adresse und den Interrupt konfigurieren (COM1/COM3 bzw. COM2/COM4
sollten NIE denselben Interrupt benutzen!).

Sie kînnen UC auch gleich beim Start zwingen, z.B. COM2 zu benutzen,
indem Sie  UC /2  eingeben.

Der Baudraten-MenÅpunkt "75/1200" erlaubt das Senden mit 75 Baud
bei gleichzeitigem Empfang mit 1200 Baud. Die umgekehrte Kombi-
nation ist aus Hardware-GrÅnden nicht realisierbar.

Protokollanalyse
----------------
Sie kînnen UC.EXE verwenden, um den Datenverkehr zweier anderer
GerÑte (z.B. eines anderen PCs und eines Modems) "mitzulesen".
Dazu verbinden Sie die RXD-Leitung von COM1 mit der TXD-Leitung
des anderen PCs und RXD von COM2 mit dessen RXD. Im Konfigurations-
menÅ von UC stellen Sie dann als ersten Port COM1 und als 2. Port
COM2 ein. Die Sende- und Empfangsdaten des anderen PC erscheinen
dann in unterschiedlichen Farben auf dem Bildschirm.

Up- und Download
----------------
Unicom erlaubt Up- und Downloads, d.h. binÑre Dateitransfers,
in den Protokollvarianten Xmodem und Xmodem-1K. FÅr Xmodem mu·
in Konfiguration/V.24/Xmodem-Block die BlocklÑnge auf 128 Byte
gestellt sein, fÅr Xmodem-1K auf 1024 Byte.

Steuerdateien
-------------
Mit dem MenÅpunkt V.24/Steuerdatei kînnen Sie z.B. den Verbindungs-
aufbau zu einer Mailbox automatisieren. Steuerdateien werden mit
einem normalen Texteditor, z.B. EDIT, erstellt. Bestimmte ASCII-
Zeichen sind fÅr Steueraufgaben reserviert:

 <  (Kleiner-Zeichen)   2 Sek. auflegen (RTS+DTR=0, dann 1)
 >  (Grî·er-Zeichen)    Auf TrÑger warten (bis DSR,CTS,CD=1)
 '  (Apostroph)         Warten, bis 1 s nichts empfangen wird
 _  (Unterstrich)       Eine Sekunde Pause
 #  (Nummernsymbol)     Folgezeichen ist kein Steuersymbol,
                        z.B. "#>" zur Ausgabe von ">"

Beispiel fÅr eine Steuerdatei:
ATD 123456              (wÑhlt die angegebene Nummer)
>'''''HELP              (Wartet auf Verbindung, macht 5 Sekunden
                        Pause und gibt "HELP" ein)

Makros
------
Makros sind Tastenfolgen (auch ALT- und STRG-Tastenkombinationen),
die automatisch ausgefÅhrt werden sollen. Sie sind mit den
Funktionstasten F1 bis F10 abrufbar und werden mit Konfiguration/
Makros eingegeben.

Das Aufrufen von Tasten-Makros ist Åber das Info-MenÅ auch mit
der Maus mîglich. Bei der Makro-Eingabe (Konfig-MenÅ) werden Sie
nach einem Kommentar gefragt, der dann in diesem Info-UntermenÅ
als Auswahltext erscheint.

Sie kînnen beim Programmieren von Makros ALT-1 bis ALT-0 (Ziffern
Åber der Buchstabentastatur) eingeben, um einen Makro mit einem
anderen Makro (F1 bis F10) fortzusetzen. ABER: Sie sind selbst
verantwortlich dafÅr, da· hierbei keine Schleifen entstehen. Es
ist nicht zulÑssig, z.B. im F1-Makro ALT-1 zu programmieren.

Folgende reservierte Tastenkombinationen gibt es bei Makros:
'           (Apostroph) Wartet eine Sekunde.
CTRL-R      Liest einen Dateinamen aus einer beim Start mit
            UC @FILES angegebenen Dateiliste und gibt ihn aus.
            (Auch jeder Xmodem-Transfer im V.24-MenÅ liest
            einen Namen aus @FILES.)
CTRL-Home   FÅhrt den aktuellen Makro von vorn aus, solange
            die Dateiliste (UC @FILES) nicht abgearbeitet ist.

Die Mîglichkeiten vollautomatischer Dateitransfers mit Unicom
werden in der Textdatei MAKROS.DOC ausfÅhrlicher beschrieben.

UCN fÅr Int-14h-Treiber
-----------------------
UCN.EXE ist eine UniCom-Version, die die Schnittstelle nicht
direkt Åber I/O-Ports, sondern Åber die von IBM definierte
Int-14h-API anspricht. Sie kînnen damit z.B. den ISDN-Treiber
CAPI14.COM der Shamrock-ISDN-Tools benutzen. Um eine Mailbox
mit dem X.75-Protokoll anzurufen, ist zuerst CAPI14 /p1,4/d/e1
(/e1 fÅr EAZ=1, siehe ISDN-Tools-Handbuch) einzugeben und dann
UCN zu starten.

Wenn Sie die Online-Hilfe in UCN mit ALT-F1 benutzen mîchten,
mÅssen Sie UC.H? nach UCN.H? kopieren.

Portfolio-Version
-----------------
Die Datei UCPF.EXE ist eine an den Atari-Portfolio angepa·te
Programm-Version. Sie ist auf normalen PCs NICHT lauffÑhig.
(Der Portfolio ist ein DOS-basierender Palmtop-Computer.)
Folgende Eigenschaften besitzt die Portfolio-Version:

- Es wird keine Speichererweiterung fÅr den Portfolio benîtigt.
- Es wird nur ein COM-Port unterstÅtzt (serielles Interface).
- Die Baudratenkombination 1200/75 wird nicht unterstÅtzt.
- Der MenÅpunkt "DOS-Shell" existiert nicht (wegen Portfolio-DOS).
- Der Portfolio kann keine Farbattribute (z.B. invers) darstellen.
- Beim Start mit der Option /M ist das Bildschirmformat 40 x 8.
- Der Rechner schaltet sich unter UniCom NICHT automatisch aus.
- Es wird empfohlen, den Portfolio mit einem Netzteil zu betreiben.
- Der Bildschirm-Modus sollte "Dynamisch" oder "Statisch" sein,
  da sich im Modus "Normal" MenÅzeilen unterhalb der sichtbaren
  acht Zeilen nicht mit dem Cursor anwÑhlen lassen.

Um UCPF.EXE von einem PC auf den Portfolio zu kopieren, kînnen Sie
das Parallel-Interface mit der von Atari dazu gelieferten Software
verwenden. Auf der RAM-Disk des Portfolio sollten vorher mindestens
25000 Byte frei sein.

UCX.EXE fÅr Bull-Emulation
--------------------------
UCX enthÑlt eine Spezial-Emulation fÅr Bull-VIP-73XX-Terminals:

1. ESC ` (1B 60 hex) lîscht den Bildschirm.
2. ESC f x y setzt den Cursor auf Spalte x, Zeile y.
3. ESC s B = Blinken ein.
4. ESC s R = Blinken aus.
5. ESC s I wird ignoriert.
6. ESC s L wird ignoriert.
7. Das 1., 3., 5. usw. LF-Steuerzeichen wird ignoriert.
8. ESC k # wird ignoriert (#=beliebiger Code).

Kopieren Sie bitte UC.H? nach UCX.H? zur Benutzung der
Online-Hilfe (ALT-F1) in UCX.

Copyright
---------
(c) Shamrock Software GmbH, http://www.shamrock.de
