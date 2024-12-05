# **This is the Marvin Documentation**
# Inhaltsverzeichnich
1. Einleitung
2. Analyse
3. Berechnungen
4. Realisierung
5. Bauelemente
6. Testing
7. Arbeitsjournal
8. Anhang
9. Zeitplan und Anforderungen

# Einleitung
Im Rahmen meines Berufsübergreifenden Projekts (BüP) habe ich mich dazu entschieden, eine ikonische Szene aus Per Anhalter durch die Galaxis (englisch: The Hitchhiker's Guide to the Galaxy) nachzubilden: die stöhnende Tür. Diese Szene gehört zu den unverwechselbaren Momenten, die den Humor und die skurrile Welt von Douglas Adams so einzigartig machen. Mein Ziel ist es, die Mechanik und den charakteristischen Sound der stöhnenden Tür nachzuempfinden und damit einen kleinen, aber unvergesslichen Aspekt dieses Kultklassikers zum Leben zu erwecken.

Per Anhalter durch die Galaxis ist nicht nur ein Meilenstein der Science-Fiction-Literatur, sondern auch eine Satire auf Technik, Gesellschaft und die Absurditäten des Lebens. Die stöhnende Tür steht dabei sinnbildlich für die übertriebene Automatisierung und die Eigenheiten der Technologie in Adams' Universum: Eine Tür, die jede Bewegung mit einem seufzenden oder stöhnenden Laut kommentiert, eine Funktionalität, die im Alltag vollkommen unnötig wäre, aber in dieser Welt als selbstverständlich gilt. Genau diesen skurrilen Charme und die technische Absurdität möchte ich mit meinem Projekt einfangen und nachbilden.

Für die Umsetzung habe ich ein interaktives System geplant, das aus mehreren Komponenten besteht. Ein TOF-Sensor (Time-of-Flight) erkennt Bewegungen, sobald jemand durch die Tür geht, und löst das Abspielen einer Audiodatei aus. Das Herzstück des Systems ist das ESP32-Audio-Kit, ein Board, das sowohl den Mikrocontroller als auch den Audioplayer integriert. Es übernimmt die Auswertung der Sensordaten und die Wiedergabe der Audiodatei, die ich zuvor selbst aufgenommen habe. Dabei plane ich, nicht nur meine eigene Stimme einzusetzen, sondern auch Kollegen im Betrieb um Seufzer und andere passende Geräusche zu bitten, um die stöhnende Tür möglichst authentisch und vielfältig zu gestalten.

Die Energieversorgung des Systems erfolgt über eine 16-Volt-Batterie. Da das ESP32-Audio-Kit und der Sensor nur mit einer Spannung von 3,3 Volt arbeiten können, verwende ich einen Schaltregler, der die Spannung von 16 Volt auf das benötigte Niveau reduziert. Die Wahl des Schaltreglers fiel bewusst, da er effizienter arbeitet und weniger Energieverlust erzeugt als ein linearer Spannungsregler – ein entscheidender Vorteil bei einem batteriebetriebenen System.

Dieses Projekt verbindet verschiedene Aspekte aus Technik, Design und Unterhaltung, um eine humorvolle und zugleich funktionale Hommage an Douglas Adams' Meisterwerk zu schaffen. Gleichzeitig bietet es mir die Möglichkeit, meine Fähigkeiten in Bereichen wie Programmierung, Elektrotechnik und Mechanik weiterzuentwickeln. Darüber hinaus erlaubt es mir, meine Kreativität und Begeisterung für Popkultur auszudrücken, indem ich eine praktische und gleichzeitig humorvolle Lösung für die Nachbildung dieser Szene entwickle. Die Arbeit an diesem Projekt ist nicht nur eine technische Herausforderung, sondern auch eine Gelegenheit, den Geist von Per Anhalter durch die Galaxis auf originelle Weise zu interpretieren.

# Analyse
## Überlegungen  
Für die Realsierung des Projekts musste ich mir ein paar überlegen machen:
- **Wie will ich das mit dem Sensor genau angehen? Wir lassen die Tür im Betrieb immer geöffnet, ist es Sinvoll mit dem Sensor das öffnen der Tür zu Messen?**
    - *Der Sensor wird oberhalb der Tür montiert. Da wir die Tür durchgehend geöffnet haben ist es nicht Sinvoll das öffnen der Tür zu messen, stattdessen misst der Sensor die einzelnen Personen die durch die Tür duch gehen.*
  
- **Was für ein Sensor verwnde ich?**
    - *Ich werde einen TOF (Time-Of-Flight) Sensor verwenden. Genauer einen TMF8820.*
  
- **Welcher Microcontroller verwende ich?**
    - *Ich verwende ein ESP32-Audio-Kit verwenden mit einem ESP32-A1S Microcontroller.*
  
- **Wie soll das Projekt betrieben werden?**
    - *Das Projekt wird mit einem Akku Betrieben.*
  
- **Was für einen Akku soll ich verwnden?**
    - *Ich verwende einen 16V, 1.8Ah Akku*
  
- **Der ESP32-A1S wird mit 3.3V betrieben. Wie mache ich die 16V in 3.3V?**
    - *Ich baue eine kleine Externe schaltung mit eienme Schaltregler*

## Theorie  
Das Ziel meines Projekts ist es, ein interaktives System zu entwickeln, bei dem eine Audiodatei abgespielt wird, sobald eine Person von einem TOF-Sensor erkannt wird, die durch die Tür geht. Um dies zu realisieren, verwende ich ein ESP32-Audio-Kit, ein Board, das sowohl den Mikrocontroller als auch den Audioplayer integriert. Später mehr dazu. Dieses Board wertet den Bewegungssensor aus und spielt dann die Audiodatei ab, die auf das Programm geladen wurde. Die Audioaufnahme werde ich mit einem Aufnahmegerät selbst erstellen und andere im Betrieb bitten, ein Seufzen beizutragen, um die ikonische *"Moaning Door"* aus Hitchhiker's Guide so authentisch wie möglich nachstellen zu können.  
  
Die Energieversorgung des gesamten Systems erfolgt über eine 16-Volt-Batterie. Da jedoch sowohl der Bewegungssensor als auch der Mikrocontroller nur mit einer Spannung von 3,3 Volt arbeiten können, setze ich einen Schaltregler ein, der die Spannung von 16 Volt auf das benötigte Niveau reduziert. Der Schaltregler wurde gewählt, da er effizienter arbeitet und weniger Energieverlust erzeugt als ein linearer Spannungsregler, was insbesondere bei batteriebetriebenen Anwendungen von Vorteil ist.

# Berechnungen

# Realisierung
## Funktionen
## Aufbau

# Bauelemente
## Schaltregler
## TOF
## ESP32
Das **ESP32-Audio-Kit** ist eine Hardware-Plattform, die speziell für Audioanwendungen entwickelt wurde und auf dem beliebten **ESP32**-Mikrocontroller basiert. Es kombiniert leistungsstarke Funktionen wie Wi-Fi, Bluetooth und Audioverarbeitung, was es zu einer vielseitigen Lösung für Audio-Streaming und -Verarbeitung in verschiedenen Projekten macht. Hier sind die wichtigsten Merkmale des **ESP32-Audio-Kit**:  

### Hauptmerkmale:
1. **ESP32 Mikrocontroller:**
    - Der ESP32 ist ein leistungsfähiger Mikrocontroller mit **Dual-Core-Prozessor**, der für schnelle Datenverarbeitung und Aufgaben wie Wi-Fi, Bluetooth und Audio-Streaming geeignet ist.
    - Er bietet eine breite Unterstützung für verschiedene Kommunikationsprotokolle (wie Wi-Fi, Bluetooth, I²S) und ist aufgrund seiner Flexibilität und seiner kostengünstigen Preise in vielen IoT- und Audioprojekten beliebt.

2. **Audio-Wiedergabe:**
    - Das **ESP32-Audio-Kit** ist darauf ausgelegt, Audioinhalte wie MP3- oder WAV-Dateien abzuspielen. Es bietet eine **I²S-Audio-Schnittstelle**, die eine Verbindung zu externen DACs (Digital-Analog-Wandlern) oder Verstärkern ermöglicht.
    - Der Mikrocontroller kann direkt mit Audioquellen wie SD-Karten oder Streams über Wi-Fi kommunizieren.

3. **Eingebaute Lautsprecher- und Audioausgangsoptionen:**  
    - Das Board unterstützt den Anschluss eines Lautsprechers und ist mit einem eingebauten Audioverstärker ausgestattet, sodass es für die Ausgabe von Audio ohne zusätzliche Hardware verwendet werden kann.
    - Es kann auch verwendet werden, um Audio über Bluetooth an drahtlose Lautsprecher oder Kopfhörer zu streamen.

4. **Energieeffizienz:**
    - Der ESP32-Audio-Kit wurde so konzipiert, dass er in batteriebetriebenen Anwendungen gut funktioniert. Das Board unterstützt verschiedene Stromsparmodi des ESP32-Mikrocontrollers, was es zu einer guten Wahl für mobile oder kabellose Projekte macht.

5. **Anschlussmöglichkeiten:**
    - Das Board bietet verschiedene Anschlussmöglichkeiten wie **I²C**, **SPI**, **UART**, und **I²S**, was eine einfache Integration in andere Systeme und Peripheriegeräte ermöglicht.
    - Auch SD-Kartensteckplätze für das Abspielen von Audiodateien von externen Speichern sind oft verfügbar.

6. **Flexibilität durch Software:**
    - Das ESP32-Audio-Kit wird in der Regel mit der beliebten Entwicklungsumgebung **Arduino IDE** oder der **ESP-IDF-Plattform** unterstützt, sodass Benutzer leicht ihre eigenen Programme schreiben können, um das Verhalten des Boards zu steuern.
    - Es gibt auch viele Bibliotheken und Frameworks, die speziell für Audioanwendungen entwickelt wurden, wie etwa das **ESP32 Audio** Framework, das eine einfache Handhabung von Audioquellen und -ausgaben ermöglicht.

### Einsatzmöglichkeiten
- Intelligente Lautsprecher: Entwicklung von sprachgesteuerten Geräten.
- Musikspieler: Erstellung von MP3-Playern oder Webradios.
- Benachrichtigungssysteme: Wiedergabe von Benachrichtigungstönen in IoT-Systemen.
- Künstlerische Projekte: Einsatz in Installationen oder kreativen Projekten wie deinem „stöhnende Tür“-Projekt.

# Testing

# Arbeitsjournal
## KW 36
## KW 37
## KW 38
## KW 39
## KW 40
## KW 41
## KW 42
## KW 43
## KW 44
## KW 45
## KW 46
## KW 47
## KW 48
## KW 49
## KW 50
## KW 51
## KW 52
## KW 01
## KW 02

# Anhang
[ESP32 Datenblatt](esp32-audio-kit_v2.2_sch.pdf)  
[TOF Datenblatt](TMF882X_DataSheet.pdf)  
[TOF mini Schematic](SparkFun_dToF-TMF8820_Mini_Schematic.pdf)  
[Schaltregler Dtaenblatt](R_78E_1_0-1711201.pdf)  

# Zeitplan und Anforderungen
[Zeitplan und Anforderungen](Marvin_AudioAnlage_Anforderungen_NoraHueppi_20240917.xlsx)  

## Schwierigkeiten im Code
Der ESp32 hat 2 I2C anschlüsse und ich musste für dies eine lösung im Programm finden.
Das Problem war das ich den gleichen I2C treiber 2 mal inizialisieruen wollte, ich musste den zweiten I2C treiber noch initialisieren.
Ich schaute im Internet nach lösungen und dies war meine Lösung für mein Problem:

`TwoWire I2CSensor = TwoWire(1);`  
`void setup()`
`{`  
    `I2CSensor.begin(18, 23);`  
    `if(!myTMF882X.begin(I2CSensor))`  
    `}`  
        `Serial.println("Error - The TMF882X failed to initialize - is the board connected?");`  
        `while(1);`  
    `}else` 
    `{`  
        `Serial.println("TMF882X started.");`  
    `}`  
`}`  
