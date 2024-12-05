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
Der **TMF8820** ist ein **Time-of-Flight (TOF)**-Sensor, der von AMS entwickelt wurde. Er misst Entfernungen präzise, indem er die Zeit berechnet, die Licht benötigt, um von einem Objekt reflektiert zu werden und zum Sensor zurückzukehren. Der TMF8820 eignet sich hervorragend für Anwendungen, bei denen eine genaue Distanzmessung oder Objekterkennung erforderlich ist. Hier sind die wichtigsten Informationen:  

### Wesentliche Eigenschaften des TMF8820
1. **Arbeitsprinzip: Time-of-Flight (TOF)**
    - Der Sensor emittiert Licht über eine integrierte **Laserdiode** (VCSEL - Vertical-Cavity Surface-Emitting Laser).
    - Er misst die Flugzeit des Lichts, das von einem Objekt reflektiert wird, um präzise Entfernungen zu berechnen.

Messbereich
    Der TMF8820 bietet eine maximale Reichweite von bis zu 4 Metern, abhängig von der Umgebung und den Reflexionseigenschaften des Objekts.
    Hohe Genauigkeit bei Kurz- und Mittelstrecken.

Auflösung und Präzision
    Millimetergenauigkeit, ideal für Anwendungen, die eine hohe Präzision erfordern.
    Sehr schnelle Messzyklen, was ihn für Echtzeitanwendungen geeignet macht.

Mehrzonen-Technologie
    Unterstützt 3x3 Multi-Zonen-Messungen, wodurch der Sensor nicht nur die Entfernung misst, sondern auch die Richtung von Objekten erkennen kann.
    Dies ist nützlich für Anwendungen mit mehreren Zielobjekten im Sichtfeld.

Größe und Integration
    Sehr kompakt und leicht in Geräte integrierbar.
    I²C-Schnittstelle zur einfachen Kommunikation mit Mikrocontrollern wie dem ESP32.

Stromverbrauch
    Optimiert für batteriebetriebene Geräte mit geringem Stromverbrauch.
    Stromsparmodi verfügbar, wenn der Sensor nicht aktiv ist.

Typische Anwendungen

    Gestenerkennung
        Kann verwendet werden, um Bewegungen oder Gesten zu erkennen, indem die Entfernung zu einem Objekt dynamisch gemessen wird.

    Entfernungs- und Objekterkennung
        Ideal für Türsysteme, bei denen erkannt wird, ob jemand hindurchgeht, wie in deinem Projekt.
        Kann zur Hinderniserkennung in Robotern oder Drohnen eingesetzt werden.

    Raumüberwachung
        Nützlich in Smart-Home-Anwendungen zur Erkennung von Personen oder Objekten in einem Raum.

    Industrielle Automatisierung
        In Produktionslinien oder Logistiksystemen, um Objekte zu zählen oder deren Position zu bestimmen.

Technische Details

    Lichtquelle: Integrierte Laserdiode (VCSEL).
    Schnittstelle: I²C, für einfache Integration in Mikrocontroller-Projekte.
    Spannungsversorgung: Typischerweise 2,8 V bis 3,3 V.
    Betriebstemperatur: -20 °C bis 85 °C.
    Abmessungen: Sehr kompakt, was ihn für portable Geräte geeignet macht.

Vor- und Nachteile
Vorteile

    Hohe Präzision und schnelle Messzeiten.
    Unterstützt Multi-Zonen-Messungen.
    Energieeffizient und einfach in batteriebetriebene Systeme zu integrieren.
    Robuste Leistung auch in Umgebungen mit schwachem Licht.

Nachteile

    Die maximale Reichweite von 4 Metern könnte für manche Anwendungen begrenzend sein.
    Reflektierende oder transparente Oberflächen können die Messgenauigkeit beeinträchtigen.
    Erfordert möglicherweise genaue Kalibrierung für optimale Ergebnisse.  

## ESP32
Das **ESP32-Audio-Kit** ist eine speziell für Audioanwendungen entwickelte Entwicklungsplattform, die auf dem leistungsstarken **ESP32-Mikrocontroller** basiert. Mit der Kombination aus **Wi-Fi**, **Bluetooth** und **Audioverarbeitung** bietet es eine vielseitige Lösung für Projekte wie **Audio-Streaming**, **Sprachsteuerung** und **interaktive Audiogeräte**. Hier sind die wichtigsten Merkmale und technischen Details des ESP32-Audio-Kits:  

### Hauptmerkmale:
1. **ESP32 Mikrocontroller:**
    - **Dual-Core-Prozessor**: Der ESP32 verfügt über einen **Xtensa LX6 Dual-Core-Prozessor** mit bis zu **240 MHz** Taktfrequenz, was eine schnelle Datenverarbeitung und effiziente Steuerung von Audio- und Kommunikationsaufgaben ermöglicht.
    - **Wi-Fi und Bluetooth**: Der Mikrocontroller unterstützt sowohl **Wi-Fi** (802.11 b/g/n) als auch **Bluetoot** (Classic und BLE), was ihn ideal für drahtlose Audioanwendungen macht.
    - **Vielseitige Kommunikationsprotokolle**: Der ESP32 unterstützt **I2S** (für digitale Audioübertragung), **SPI**, **I2C**, **UART** und **PWM**, um eine einfache Integration von externen Geräten zu ermöglichen.
    - **Energieeffizienz**: Der Mikrocontroller bietet mehrere **Stromsparmodi** und ist daher auch für batteriebetriebene Anwendungen geeignet.

2. **Audio-Wiedergabe:**
    - **I²S-Schnittstelle**: Das Board nutzt die **I2S (Inter-IC Sound)**-Schnittstelle, um digitale Audiodaten an externe **DACs** (Digital-Analog-Wandler) oder **Verstärker** zu übertragen.
    - **Unterstützung für gängige Audioformate**: Es unterstützt Audioformate wie **MP3**, **WAV**, **OGG** und andere.
    - **SD-Kartenleser**: Der integrierte **SD-Kartensteckplatz** ermöglicht das Abspielen von Audiodateien direkt von einer SD-Karte.

3. **Eingebaute Lautsprecher- und Audioausgangsoptionen:**
    - Das Board ist mit einem **eingebauten Audioverstärker** ausgestattet, der die direkte Ausgabe von Audio an angeschlossene Lautsprecher ermöglicht.
    - **Bluetooth Audio**: Es unterstützt **Bluetooth-Audio-Streaming** (A2DP-Profil), sodass Audio auch drahtlos an Bluetooth-fähige Lautsprecher oder Kopfhörer gestreamt werden kann.

4. **Energieeffizienz:**
    - Das ESP32-Audio-Kit ist für den Einsatz in **batteriebetriebenen Anwendungen** optimiert. Dank **Deep Sleep**- und **Light Sleep**-Modi kann der Stromverbrauch bei Nichtnutzung stark reduziert werden.

5. **Anschlussmöglichkeiten:**
    - **I²C**, **SPI**, **UART**, **I2S**-Schnittstellen ermöglichen die einfache Integration von Sensoren und anderen Peripheriegeräten.
    - **SD-Kartenleser**: Für das Abspielen von Audiodateien von externen Speichern, ideal für Projekte, die größere Mengen an Audiodaten benötigen.

6. **Flexibilität durch Software:**
    - Das Kit wird in der Regel mit der **Arduino IDE** oder **ESP-IDF** (Espressif IoT Development Framework) unterstützt, sodass Entwickler ihre eigenen Programme einfach erstellen können.
    - **ESP32 Audio Framework** und andere Bibliotheken erleichtern die Arbeit mit Audioquellen und -ausgaben.

### Typische Anwendungen:
1. **Audio-Streaming:**
    - **Bluetooth-Lautsprecher**: Das ESP32-Audio-Kit eignet sich für die Erstellung von **Bluetooth-Lautsprechern**, die Audio von Smartphones, Tablets oder Computern streamen.
    - **Wi-Fi-Streaming**: Es kann auch für **Wi-Fi-Audio-Streaming** verwendet werden, z. B. für Musik oder Podcasts, was es ideal für Smart-Home-Systeme oder Multiroom-Audiosysteme macht.

2. **Sprachsteuerung und -wiedergabe:**
    - **Sprachgesteuerte Geräte**: Das Kit eignet sich für **Smart Home**-Geräte, die Sprachbefehle empfangen und Audio-Warnmeldungen oder Rückmeldungen ausgeben.
    - **TTS (Text-to-Speech)**: Das Board kann mit Text-to-Speech-Engines kombiniert werden, um benutzerdefinierte Sprachausgaben zu erzeugen.

3. **Kombination mit Sensoren (z. B. TOF-Sensor):**
    - In Projekten mit **Bewegungserkennung** (wie bei einem **TOF-Sensor**) kann das ESP32-Audio-Kit so programmiert werden, dass es bestimmte Audioereignisse abspielt, z. B. das Geräusch einer sich öffnenden Tür.

4. **Interaktive Geräte:**
    - **Ausstellungen und Installationen**: In interaktiven Systemen, bei denen Audio auf Benutzereingaben (z. B. Bewegungen oder Berührungen) reagiert, kann das Kit verwendet werden, um Audioausgaben zu erzeugen.

### Technische Details:
-   **Prozessor**: **Dual-Core Xtensa LX6** @ 240 MHz
-   **RAM**: **520 KB** SRAM (Standard), erweiterbar mit externem RAM
-   **Speicher**: Unterstützung für **Flash-Speicher** (meist 4MB bis 16MB) und **SD-Karten** (bis zu 32 GB)
-   **Audioformate**: **MP3**, **WAV**, **OGG**, **FLAC**
-   **I²S**-Schnittstelle für **digitale Audioübertragung**
-   **Audioverstärker** (oft integriert, je nach Modell)
-   **Wi-Fi**: **802.11 b/g/n** (2,4 GHz)
-   **Bluetooth**: **Classic** und **BLE**
-   **Energieverbrauch**: Optimierte **Stromsparmodi** für batteriebetriebene Anwendungen
-   **Verfügbare Schnittstellen**: **I2C**, **SPI**, **UART**, **I2S**
-   **SD-Kartenleser**: Für die Speicherung und das Abspielen von Audiodateien

### Vorteile:
- **Kostengünstig**: Das ESP32-Audio-Kit bietet eine erschwingliche Lösung für Audioprojekte, die dennoch leistungsstark genug für viele Anwendungen ist.
- **Vielfältige Einsatzmöglichkeiten**: Durch die Kombination von Audio-Wiedergabe, Wi-Fi und Bluetooth bietet es zahlreiche Anwendungsmöglichkeiten in verschiedenen Bereichen.
- **Erweiterbarkeit**: Das Board lässt sich problemlos in größere Systeme integrieren, da es verschiedene Kommunikationsprotokolle und eine breite Unterstützung von Peripheriegeräten bietet.
- **Einfache Programmierung**: Mit Unterstützung für beliebte Entwicklungsumgebungen wie Arduino und ESP-IDF können Entwickler schnell Prototypen und Anwendungen erstellen.

### Nachteile:
- **Begrenzte Audioqualität**: Der **Audioverstärker** und die einfachen **DACs** bieten keine High-End-Audioqualität.
- **Eingeschränkter Speicher**: Der **Flash-Speicher** und **RAM** sind begrenzt, was bei großen oder komplexen Anwendungen problematisch sein kann.
- **Wärmeentwicklung**: Bei intensiver Nutzung kann der **ESP32 Wärme entwickeln**, was in engen Gehäusen ohne ausreichende Kühlung problematisch sein könnte.

### Fazit:
Das **ESP32-Audio-Kit** ist eine leistungsstarke, kostengünstige und vielseitige Plattform für Audioanwendungen. Es eignet sich besonders für Projekte, die **Audio-Streaming**, **Sprachsteuerung** und **interaktive Audiogeräte** umfassen, und bietet durch die Flexibilität des ESP32 Mikrocontrollers zahlreiche Anwendungsmöglichkeiten. Trotz einiger Einschränkungen in der **Audioqualität** und **Speichergröße** ist es eine ausgezeichnete Wahl für viele DIY-Projekte und IoT-Anwendungen.


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
