# This is the Marvin Documentation
## Inhaltsverzeichnich
1. Einleitung
2. Analyse
3. Berechnungen
4. Realisierung
5. Bauelemente
6. Testing
7. Arbeitsjournal
8. Anhang
9. Zeitplan und Anforderungen

## Einleitung
Im Rahmen meines Berufsübergreifenden Projekts (BüP) habe ich mich dazu entschieden, eine ikonische Szene aus Per Anhalter durch die Galaxis (englisch: The Hitchhiker's Guide to the Galaxy) nachzubilden: die stöhnende Tür. Diese Szene gehört zu den unverwechselbaren Momenten, die den Humor und die skurrile Welt von Douglas Adams so einzigartig machen. Mein Ziel ist es, die Mechanik und den charakteristischen Sound der stöhnenden Tür nachzuempfinden und damit einen kleinen, aber unvergesslichen Aspekt dieses Kultklassikers zum Leben zu erwecken.

Per Anhalter durch die Galaxis ist nicht nur ein Meilenstein der Science-Fiction-Literatur, sondern auch eine Satire auf Technik, Gesellschaft und die Absurditäten des Lebens. Die stöhnende Tür steht dabei sinnbildlich für die übertriebene Automatisierung und die Eigenheiten der Technologie in Adams' Universum: Eine Tür, die jede Bewegung mit einem seufzenden oder stöhnenden Laut kommentiert, eine Funktionalität, die im Alltag vollkommen unnötig wäre, aber in dieser Welt als selbstverständlich gilt. Genau diesen skurrilen Charme und die technische Absurdität möchte ich mit meinem Projekt einfangen und nachbilden.

Für die Umsetzung habe ich ein interaktives System geplant, das aus mehreren Komponenten besteht. Ein TOF-Sensor (Time-of-Flight) erkennt Bewegungen, sobald jemand durch die Tür geht, und löst das Abspielen einer Audiodatei aus. Das Herzstück des Systems ist das ESP32-Audio-Kit, ein Board, das sowohl den Mikrocontroller als auch den Audioplayer integriert. Es übernimmt die Auswertung der Sensordaten und die Wiedergabe der Audiodatei, die ich zuvor selbst aufgenommen habe. Dabei plane ich, nicht nur meine eigene Stimme einzusetzen, sondern auch Kollegen im Betrieb um Seufzer und andere passende Geräusche zu bitten, um die stöhnende Tür möglichst authentisch und vielfältig zu gestalten.

Die Energieversorgung des Systems erfolgt über eine 16-Volt-Batterie. Da das ESP32-Audio-Kit und der Sensor nur mit einer Spannung von 3,3 Volt arbeiten können, verwende ich einen Schaltregler, der die Spannung von 16 Volt auf das benötigte Niveau reduziert. Die Wahl des Schaltreglers fiel bewusst, da er effizienter arbeitet und weniger Energieverlust erzeugt als ein linearer Spannungsregler – ein entscheidender Vorteil bei einem batteriebetriebenen System.

Dieses Projekt verbindet verschiedene Aspekte aus Technik, Design und Unterhaltung, um eine humorvolle und zugleich funktionale Hommage an Douglas Adams' Meisterwerk zu schaffen. Gleichzeitig bietet es mir die Möglichkeit, meine Fähigkeiten in Bereichen wie Programmierung, Elektrotechnik und Mechanik weiterzuentwickeln. Darüber hinaus erlaubt es mir, meine Kreativität und Begeisterung für Popkultur auszudrücken, indem ich eine praktische und gleichzeitig humorvolle Lösung für die Nachbildung dieser Szene entwickle. Die Arbeit an diesem Projekt ist nicht nur eine technische Herausforderung, sondern auch eine Gelegenheit, den Geist von Per Anhalter durch die Galaxis auf originelle Weise zu interpretieren.

## Analyse
### Überlegungen  
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

### Theorie  
Das Ziel meines Projekts ist es, ein interaktives System zu entwickeln, bei dem eine Audiodatei abgespielt wird, sobald eine Person von einem TOF-Sensor erkannt wird, die durch die Tür geht. Um dies zu realisieren, verwende ich ein ESP32-Audio-Kit, ein Board, das sowohl den Mikrocontroller als auch den Audioplayer integriert. Später mehr dazu. Dieses Board wertet den Bewegungssensor aus und spielt dann die Audiodatei ab, die auf das Programm geladen wurde. Die Audioaufnahme werde ich mit einem Aufnahmegerät selbst erstellen und andere im Betrieb bitten, ein Seufzen beizutragen, um die ikonische *"Moaning Door"* aus Hitchhiker's Guide so authentisch wie möglich nachstellen zu können.  
  
Die Energieversorgung des gesamten Systems erfolgt über eine 16-Volt-Batterie. Da jedoch sowohl der Bewegungssensor als auch der Mikrocontroller nur mit einer Spannung von 3,3 Volt arbeiten können, setze ich einen Schaltregler ein, der die Spannung von 16 Volt auf das benötigte Niveau reduziert. Der Schaltregler wurde gewählt, da er effizienter arbeitet und weniger Energieverlust erzeugt als ein linearer Spannungsregler, was insbesondere bei batteriebetriebenen Anwendungen von Vorteil ist.

## Berechnungen

## Realisierung
### Funktionen
### Aufbau

## Bauelemente
### Schaltregler
### TOF
### ESP32
Das **ESP32-Audio-Kit** ist ein Entwicklungsboard, das speziell für Audioanwendungen entwickelt wurde und auf dem beliebten ESP32-Mikrocontroller basiert. Es bietet eine vielseitige Plattform für Projekte, die Audiowiedergabe, Sprachsteuerung oder andere Anwendungen im Bereich der Audiotechnologie erfordern. Hier sind einige der wichtigsten Merkmale:  
#### _Wichtige Eigenschaften_
1. ESP32 Microcontroler
    - Der ESP32 ist ein leistungsstarker Mikrocontroller mit Dual-Core-CPU, Wi-Fi und Bluetooth-Funktionalität.
    - Ideal für IoT-Anwendungen, bei denen drahtlose Konnektivität benötigt wird.

2. Audio-Codecs und DACs
    - Das Board enthält integrierte Audio-Digital-Analog-Wandler (DACs) und möglicherweise einen Audio-Codec (z. B. ES8388).
    - Diese Bauteile ermöglichen hochwertige Audiowiedergabe und -verarbeitung.

3. Audiowiedergabe und Aufnahme
    - Unterstützt verschiedene Audioformate wie MP3, WAV und AAC.
    - Bietet Anschlussmöglichkeiten für Mikrofone zur Audioaufnahme (bei manchen Versionen auch MEMS-Mikrofone integriert).

4. Anschlüsse und Schnittstellen
    - Lautsprecheranschlüsse (oft als Klinkenbuchse oder Pins ausgeführt).
    - Eingänge für Mikrofone.
    - I2S-Schnittstelle für Audioübertragung.
    - GPIOs für zusätzliche Funktionen wie Sensoren oder LEDs.

5. Programmierbarkeit
    - Programmierbar mit Arduino IDE, ESP-IDF oder PlatformIO.
    - Unterstützt Libraries wie ESP8266Audio oder andere für Audioprojekte.

6. Stromversorgung
    - In der Regel über USB oder eine externe Spannungsquelle versorgt.
    - Kann mit einer Spannungsregelung für externe Stromquellen kombiniert werden.

7. Zusätzliche Funktionen
    - Unterstützt drahtlose Audiostreams, wie z. B. Bluetooth-Audio oder Webradio.
    - Oft mit SD-Karten-Slots ausgestattet, um Audiodateien lokal zu speichern.


## Testing

## Arbeitsjournal
### KW 36
### KW 37
### KW 38
### KW 39
### KW 40
### KW 41
### KW 42
### KW 43
### KW 44
### KW 45
### KW 46
### KW 47
### KW 48
### KW 49
### KW 50
### KW 51
### KW 52
### KW 01
### KW 02

## Anhang

## Zeitplan und Anforderungen
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
