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
Der **R78E3.3-1.0** ist ein kompakter, energieeffizienter Schaltregler, der sich ideal als Ersatz für lineare Spannungsregler eignet. Entwickelt dür moderne Elektroanwendungen, bietet er hohe Effizienz und einen breiten **Eingangsspannungsbereich**. Mit festen Ausgangsspannung von **3.3 V** und einem maximalen Strom von **1 A** ist er bestens für eine Vielzahl von Anwendungen geeignet, insbesondere dort, wo kompakte Bauformen und geringe Wärmeentwicklung gefragt ist.

### Wesentlichen Eigenschaften des R78E3.3-1.0
Der **R78E3.3-1.0** punktet mit mehreren Eigenschaften, die ihn zu einer leistungsstarken und zu verlässigen Lösung machen. Er bietet einen Wirkungsgrad von bis zu **96%**, wodurch die **Verlustleistung** und **Wärmeentwicklung** minimiert werden. Im Gegensatz zu linearen Reglern benötigt er keinen Kühlkörper, was Platz spart und das Design vereinfacht. Sein Eingangsspannungsbereich reicht von **7 V bid 28 V**, was ihn flexibel für verschiedene Stromquellen macht. Die **feste Ausgangsspannung von 3.3 V** gewährleistet eine stabile Stromversorgung für Mikrocontroller, Sensoren oder andere Elektronikbauteile. Zudem schützt der Schaltregler durch eingebaute Sicherheitsfunktionen wie **Kurzschluss- und Überstromschutz** eine Schaltung vor Schäden.

Seine **kompakte Bauform** ermöglicht die Integration in platzkritische Designs, während der geringe Eigenverbrauch die Effizienz in batteriebetriebenen Systemen maximiert. Dank seines geringen Rauschens und der hohen Zuverlässigkeit eignet sich der R78E3.3-1.0 auch für empfindliche Anwendungen.

### Typische Anwendungen
**Ersatz für lineare Regler**
Besonders geeignet für Designs, die dem **Stromverbrauch** und die **Wärmeentwicklung** minimieren wollen.

**Mikrocontroller-Stromversorgung**
Ideal für Mikrocontroller wie **ESP32, Raspberry Pi Pico oder Arduino**, die eine stabile **3.3-V-Versorgung** benötigt.

**Sensor- und oder IoT-Anwendungen**
Perfekt für batteriebetriebene Geräte, bei denen **Energieeffizienz** und **geringe Grösse** eintscheidend sind.

**Tragbare Elektronik**
In **Wearables** oder anderen **kompakten Systemen** sorgt der Schaltregler für eine **stabile Stromversorgung** bei **geringem Platzbedarf**.

### Technische Details
- **Eingangsspannung**: 7V bis 28V
- **Ausgangsspannung**: 3.3V (fix)
- **Maximaler Ausgangsstrom**: 1A
- **Wirkungsgrad**: Bis zu 96%
- **Betriebstemperatur**: -40°C bis +85°C
- **Bauform**: Kompakte SIP3-Gehäuseform
- **Schutztfunktionen**: Kurzschluss- und Überstromschutz

### Vorteile und Nachteile des R78E3.3-1.0
**Vorteile**
Sein **hoher Wirkungsgrad** reduziert die Wärmeentwicklung erheblich und spart Energie, wodurch odt auch zusätzliche Kühlmassnahmen verzichtet werden kann. Dank seiner **kompakten Bauform** benötigt er weniger Platz als herkömmliche lineare Regler, was ihn ideal für platzkritische Designs macht. Der **breite Eingangsspannungsbereich** von 7 bis 28 Volt verleiht ihm Flexibilität, da er mit unterschiedlichen Stromquellen kompatibel ist. Darüber hinaus sorgen **integrierte Schutzmechanismen**, wie Kurzschluss- und Überstromschutz, für eine zuverlässige und sichere Funktion.

**Nachteile**
Die **fixe Ausgangsspannung** von 3.3 Volt begrenzt seine Einsatzmöglichkeiten, insbesondere in Systemen, die eine variable Spannungsanpassung erfordern. Mit einem **maximalen Ausgangsstrom** von 1 Ampere ist er für Anwendungen mit höherem Leistungsbedarf ungeeignet. Zudem können, wie bei vielen Schaltreglern, **lektromagnetische Störungen (EMI)** auftreten, was in manchen Fällen den Einsatz zusätzlicher Filter notwendig macht. Schliesslich schränkt die **minimale Eingangsspannung von 7 Volt** die Nutzbarkeit in Niederspannungssystemen ein, wodurch nicht alle Projekte von seiner Effizienz profitieren können.

### Fazit
Der **R78E3.3-1.0** ist ein effizienter und vielseitiger Schaltregler, der sich durch hohe Effizienz und eine kompakte Bauform auszeichnet. Er ist ideal für den Ersatz von linearen Reglern und eignet sich besonders für batteriebetriebene und platzkritische Anwendungen. Einschränkungen wie die feste Ausgangsspannung und der begrenzte Stromausgang sollten jedoch bei der energieeffiziente Lösung für moderne Elektronikprojekte.

## TOF
Der **TMF8820** ist ein **Time-of-Flight (TOF)**-Sensor, der von AMS entwickelt wurde. Er misst Entfernungen präzise, indem er die Zeit berechnet, die Licht benötigt, um von einem Objekt reflektiert zu werden und zum Sensor zurückzukehren. Der TMF8820 eignet sich hervorragend für Anwendungen, bei denen eine genaue Distanzmessung oder Objekterkennung erforderlich ist. Hier sind die wichtigsten Informationen:  

### Wesentliche Eigenschaften des TMF8820
Der TMF8820 zeichnet sich durch eine Vielzahl wesentlicher Eigenschaften aus, die ihn zu einem vielseitigen und leistungsstarken Time-of-Flight (TOF)-Sensor machen· Sein Arbeitsprinzip basiert auf der TOF-Technologie, bei der Licht über eine integrierte Laserdiode (VCSEL - Vertical-Cavity Surface-Emitting Laser) ausgesendet wird· Der Sensor misst die Flugzeit des Lichts, das von einem Objekt reflektiert wird, und berechnet daraus präzise Entfernungen· 

Mit einem Messbereich von bis zu 4 Metern, abhängig von den Reflexionseigenschaften der Objekte und den Umgebungsbedingungen, ist der TMF8820 sowohl für Kurz- als auch Mittelstreckenmessungen hervorragend geeignet· Dabei gewährleistet er eine hohe Genauigkeit und ermöglicht millimetergenaue Messungen· Durch seine schnellen Messzyklen ist der Sensor ideal für Echtzeitanwendungen, die Präzision und Geschwindigkeit erfordern·

Eine herausragende Eigenschaft des TMF8820 ist seine Mehrzonen-Technologie· Der Sensor unterstützt Multi-Zonen-Messungen in einem 3x3-Muster, wodurch er nicht nur Entfernungen messen, sondern auch die Richtung von Objekten im Sichtfeld erkennen kann· Diese Fähigkeit ist besonders nützlich für Anwendungen, bei denen mehrere Zielobjekte gleichzeitig erfasst werden müssen, wie etwa bei der Gestenerkennung oder der Überwachung komplexer Szenarien·

Der TMF8820 überzeugt auch durch seine kompakte Bauform, die eine einfache Integration in verschiedenste Geräte ermöglicht· Dank der I²C-Schnittstelle ist die Kommunikation mit Mikrocontrollern wie dem ESP32 unkompliziert, was die Einbindung in Projekte erheblich erleichtert· Zudem wurde der Sensor für einen niedrigen Stromverbrauch optimiert, was ihn besonders attraktiv für batteriebetriebene Geräte macht· Verschiedene Stromsparmodi sorgen dafür, dass der Energieverbrauch minimiert wird, wenn der Sensor nicht aktiv genutzt wird· 

Mit diesen Eigenschaften bietet der TMF8820 eine ideale Kombination aus Präzision, Vielseitigkeit und Energieeffizienz, die ihn für eine Vielzahl moderner Anwendungen qualifiziert·

### Typische Anwendungen
**Gestensteuerung**
Des Weiteren lassen sie sich auch zur Erkennung von **Bewegungen** oder **Gesten** verwenden, indem sie die dynamischen Änderungen in der Entfernung zu einem Objekt messen.

**Objektortung und Distanzmessung**
Sie sind ideal für **Türsysteme**, bei denen erkannt wird, ob je,and hindurchgeht. Ausserdem werden sie zur **Hinderniserkennung** in **Robotern** oder **Drohnen** eingesetzt.

**Raumüberwachung**
In **Smart-Home-Anwendungen** werden sie genutzt, um **Personen** oder **Objekte** zu erfassen, welche sich in einem Raum befinden.

**Industrieautomation**
In der **Produktion** und **Logistik** ermöglichen sie das **Zählen von Objekten** oder das **Bestimmen ihrer Position**, was Effizienz und Präzision steigert.

### Technische Details
- **Lichtquelle**: **Integrierte Laserdiode** (VCSEL).
- **Schnittstelle**: **I²C**, für einfache Integration in Mikrocontroller-Projekte.
- **Spannungsversorgung**: Typischerweise **2,8 V** bis **3,3 V**.
- **Betriebstemperatur**: **-20 °C** bis **85 °C**.
- **Abmessungen**: **Sehr kompakt**, was ihn für portable Geräte geeignet macht.

### Vorteile und Nachteile von Gestenerkennungs- und Entfernungsmesstechnologie
**Vorteile**
Diese Technologien bieten **hohe Präzision** und **schnelle Messzeiten**, was sie für viele Anwendungen besonders attraktiv macht. Sie unterstützen **Multi-Zonen-Messungen**, wodurch mehrere Bereiche gleichzeitig überwacht werden können. Ausserdem sind sie **energieeffizient** und lassen sich leicht in **batteriebetriebene Systeme** integrieren. Ihre **robuste Leistung** bleibt selbst in Umgebungen mit **schwachem Licht** zuverlässig.

**Nachteile**
Die maximale Reichweite von **4 Metern** könnte für bestimmte Anwendungen als **einschränkend** empfunden werden. Zudedm können **reflektierende** oder optimale Ergebnisse ist oft eine **genaue Kalibrierung** erforderlich, was zusätzlichen Aufwand bedeuten kann.

### Fazit
Der **TMF8820** ist ein präziser** TOF-Sensor** mit bis zu **4 Metern Reichweite** und **Multi-Zonen-Messungen**, ideal für **Gesten- und Objekterkennung**. Dank **I²C** und geringem **Stromverbrauch** eignet er sich gut für **batteriebetriebene Geräte**. Einschränkungen sind die **maximale Reichweite** und die **Messgenauigkeit bei reflektierenden Oberflächen**. Insgesamt eine **effiziente Lösung** für präzise Messungen.

## ESP32
Das **ESP32-Audio-Kit** ist eine speziell für Audioanwendungen entwickelte Entwicklungsplattform, die auf dem leistungsstarken **ESP32-Mikrocontroller** basiert. Mit der Kombination aus **Wi-Fi**, **Bluetooth** und **Audioverarbeitung** bietet es eine vielseitige Lösung für Projekte wie **Audio-Streaming**, **Sprachsteuerung** und **interaktive Audiogeräte**. Hier sind die wichtigsten Merkmale und technischen Details des ESP32-Audio-Kits:  

### Wesentliche Eigenschaften des ESP32-Audio-Kits
Das **ESP32-Audio-Kit** ist eine **vielseitige** und **leistungsstarke Plattform** für Audioprojekte. Es zeichnet sich durch eine Reihe von **Merkmalen** aus, die es für verschiedenste Anwendungen attraktiv machen.

Im Kern steht der **ESP32-Mikrocontroller**, der mit einem **Xtensa LX6 Dual-Core-Prozessor** ausgestattet ist. Dieser taktet mit bis zu **240 MHz** und ermöglicht eine **schnelle Datenverarbeitung** sowie eine **effiziente Steuerung** von Audio- und Kommunikationsaufgaben. Dank der Unterstützung für **Wi-Fi** (802.11 b/g/n) und **Bluetooth** (Classic unf BLE) eignet sich der ESP32 hervorragend für **Drahtlose Audioanwendungen**. Seine **Flexibilität** wird duchr zahlreiche **Schnittstellen** wie **I2S, SPI, I2C, UART** und **PWM** ergänzt, die die **Integration externe Geräte** erleichtern. Zudem bieten mehrere **Stromsparmodi** eine hohe **Energieeffizienz**, was den Mikrocontroller auch für **batteriebetriebene Anwendungen** prädenstiniert.

Im Bereich der **Audio-Wiedergabe** überzeugt das Kit durch seine **I2S-Schnittstelle**, die eine **digitale Übertragung** von Audiodaten an **externe Digital-Analog-Wandler (DACs)** oder **Verstärken** ermöglicht. Es unterstützt gängige **Audioformate** wie **MP3, WAV** oder **OGG**, was es **vielseitig einsetzbar** macht. Ein integrierter **SD-Kartenstecksplatz** erlaubt darüber hinaus das **Abspielen von Audiodateien** direkt von einer **SD-Karte**.

Die **Software-Unterstützung** des ESP32-Audio-Kits ist ebesno bemerkenswert. es ist **kompatibel** mit der **Arduino IDE** und dem **ESP-IDF**, wodurch die **Entwicklung eigener Anwendungen** erleichtert wird. Spezialisierte **Frameworks** wie das **ESP32 Audio Framework** vereinfacht zusätzlich die Arbeit mit **Audioquellen** und **-ausgaben**. Mit diesen **Eigenschaften** bietet das ESP32-Audio-Kit eine ideale Lösung für **vielseitige Audioprojekte**.

### Typische Anwendungen:
**Audio-Streaming**
Ideal für die Erstellung von **Bluetooth-Lautsprechern** oder **Wi-Fi-Streaming-Geräten**, die in Smart-Home-Systemen oder Multiro0om-Audiosystemen eingesetzt werden können.

**Sprachsteuerung und -wiedergabe**
Perfekt für **sprachgesteuerte Geräte** und Text-to-Speech-Anwendungen in Smart-Home-Systemen.

**Interaktive Geräte**
In Kombination mit Sensoren wie einem Time-of-Flioght-Sensor kann das Kit verwendet werden, um auf Benutzereingaben zu reagieren, z.B. durch das Abspielen spezifischer Sounds.

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

### Vorteile und Nachteile des ESP32-Audio-Kits
**Vorteile**
Es ist **kostengünstig** und gleichzeitig **leistungsstark**, wodurch es sich für eine Vielzahl von Anwendungen eignet. Besonders hervorhebend ist die **Vielseitigkeit** des Kits, da es durch die Kombination von **Audio-Wiedergabe, Wi-Fi** und **Bluetooth** zahlreiche Einsatzmöglichkeitebn bietet. Darüber hinaus überzeugt es durch **flexible Erwiterbarkeit** und eine **einfache Programmierung** mit gängigen Entwicklungsumgebungen wie der **Arduine IDE** oder **ESP-IDF**.

**Nachteile**


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

```c
TwoWire I2CSensor = TwoWire(1);
void setup()
{
    I2CSensor.begin(18, 23);
    if(!myTMF882X.begin(I2CSensor))
    }
        Serial.println("Error - The TMF882X failed to initialize - is the board connected?");
        while(1);
    }else
    {  
        Serial.println("TMF882X started.");
    }
}
```
