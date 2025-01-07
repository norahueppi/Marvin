# **This is the Marvin Documentation**
# Inhaltsverzeichnich
1. Einleitung
2. Analyse
3. Berechnungen
4. Realisierung
5. Bauelemente
6. Testing
7. Schwierigkeiten im Code
8. Arbeitsjournal
9. Anhang
10. Zeitplan und Anforderungen

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
## Betriebsdauer der Batterie in mit verschienden Laufzeiten
### Batterie läuft 24h
**Formel**
- Betriebsdauer (in Stunden) = Kapazität (in Ah) / Stromverbrauch (in A)
- Anzahl der Tage = Gesamtlaufzeit (in Stunden)​ / Betriebsdauer pro Tag (in Stunden)

**Gegebene Werte:**
- Kapazität der Batterie: 1.8 Ah
- Stromverbrauch: 17.20 mA = 0,0172 A

**Berechnung:**  
Betriebsdauer = Kapazität / Stromverbrauch 
= 1.8 Ah / 17.20 mA = *104.65 h*

Anzahl der Tage = Gesamtlaufzeit / Betriebsdauer pro Tag 
= 104.65 h / 24 h = 4.36 Tage ==> ***4 Tage & 9 h***

### Batterie läuft 10h
**Formel**
- Betriebsdauer (in Stunden) = Kapazität (in Ah) / Stromverbrauch (in A)
- Anzahl der Tage = Gesamtlaufzeit (in Stunden)​ / Betriebsdauer pro Tag (in Stunden)

**Gegebene Werte:**
- Kapazität der Batterie: 1.8 Ah
- Stromverbrauch: 17.20 mA = 0,0172 A

**Berechnung:**  
Betriebsdauer = Kapazität / Stromverbrauch 
= 1.8 Ah / 17.20 mA = *104.65 h*

Anzahl der Tage = Gesamtlaufzeit / Betriebsdauer pro Tag 
= 104.65 h / 10 h = 10.47 Tage ==> ***10 Tage & 11 h***

## Energieverbrauch pro Tag
**Formel**
- Verbrauchte Energie/Tag (Wh/Tag) = Strom (A) × Spannung (V) × Betriebszeit (h)

**Gegebene Werte:**
- Stromverbrauch: 17.20 mA = 0,0172 A
- Spannung: 16 V
- Betriebsdauer: 10 h

**Berechnung:**  
Verbrauchte Energie/Tag = Strom × Spannung × Betriebszeit
= 17.20 mA * 16 V * 10 h = ***2.75 Wh/Tag***

## Laufzeit unter Brücksichtigung vonLadeverlusten
**Formel**
- Effektive Kapazität (Ah) = Kapazität (Ah) × Effizienz
- Betriebsdauer (in Stunden) = Kapazität (in Ah) / Stromverbrauch (in A)

**Gegebene Werte:**
- Kapazität: 1.8 Ah
- Effizienz: 85 %

**Berechnung:**  
Effektive Kapazität = Kapazität × Effizienz
= 1.8 Ah * 85 % = *1.53 Ah*

Betriebsdauer = Kapazität / Stromverbrauch 
= 1.53 Ah / 17.20 mA = ***88.95 h***

## Abschätzung der Ladezeit
**Formel**
- Ladezeit (h) = Kapazität (Ah) / Ladestrom (A)

**Gegebene Werte:**
- Kapazität: 1.8 Ah
- Ladestrom: 0.5 A

**Berechnung:**  
Ladezeit = Kapazität / Ladestrom
= 1.8 Ah / 0.5 A = ***3.6 h***

# Realisierung
## Funktionen
### SPI
**SPI (Serial Peripheral Interface)** ist ein weit verbreitentes Kommunikationsprotokoll, das für die schnelle, synchrone Datenübertragung zwischen einem Master-Gerät und einem oder mehreren Slave-Geräten verwndet wird. Es wurde entwickelt, um eine einfache und effektive Verbindung für Peripheriegeräte wie Sensoren, Displays, Speicher und Mikrocontroller bereitzustellen.

**Hauptmerkmale**
Die Haupmerkmkale von SPI (Serial Peripheral Interface) machen es zu einem effizienten und vielseitigen Kommunikationsprotokoll. SPI ist ein **synchrones Protokoll**, das eine gemeinsame Taktleitung zu steuern. Es unterstützt **Vollduplex-Kommunikation**, bei der Daten gleichzeitig in beide Richtungen - vom Master zum Slave und umgekehrt -  übertragen werden können. SPI ist für **hohe GEschwindigkeiten** ausgelegt und häufig schneller als andere Protokolle wie I2C. Zudem bietet als **Flexibilität**, da keine festen Datenrahmen vorgegeben sind; die Datenbreite kann Anforderungen angepasst werden. Durch sein **einfaches Protokoll**, das ohne Adressierungsschema oder Datenflusskontrolle auskommt, ist SPI unkomploiziert und effizzient in der Anwendung.

**SPI-Signale**
SPI verwndet in der Regel vier Hauptleitungen:
1. **MOSI (Master OUT, Slave IN):** Datenleitungen vom Master zu den Slaves.
2. **MISO (Master IN, Slave OUT):** Datenleitungen von den Slaves zum Master.
3. **SLCK (Serial Clock):** Taktleitung, bereitgestellt vom Master.
4. **SS/CS (Slave Select/ Chip Select):** Leitung(en) zu Auswahlh eines Bestimten Slaves.

**Wie Funktioniert SPI?**
Die Funktionsweise von SPI basiert auf einer klaren Master-Slave-Struktur. Der **Master generiert den Takt** (SLCK) und steuert damit die gesamte Datenübertragung. Über die **MOSI-Leitungen** (Master In, Slave) Daten zurück an den Master übermittelt. Damit nur das gewünschte Gerät aktiv ist, wird der **Slave über die SS/CS-Leitung** (Slave Select/Chip Select) ausgewählt. Dieser Mechanismus stellt sicher, dass die Kommunikation gezielt und effizient abläuft.

**Vorteile und Nachteile von SPI**
***Vorteile***
Dank seiner **hohen Geschwindigkeit** eignet es sich hervorragend für schnelle Datenübertragungen. Die **Vollduplex-Fähigkeit** erlaubt das gleichzeitige Senden und Empfangen von Daten, was die Effizienz steigert. Darüber hinaus zeichnet sich SPI durch **EInfachheit** aus, da keine komplexen Protokolle erforderlich sind. Die **Flexibilität** des Protokolls ermöglicht die Anbindung mehrerer Slaves sowie die Nutzung unterschiedlicher Datenbreiten, was es vielseitig einsetzbar macht.

***Nachteile***
SPI benötigt **mehr Leistungen**, da für jede zusätzlichen Slave eine eigene SS-Leitung erforderlich ist. Zudem ist die **Reichweite begrenzt**, da SPI aufgrund des fehlenden Fehlerkorrekturmechanismus und des synchrinen Takts nur für kurze Distanzen geeignet ist. Ein weiterer Nachteil ist die fehlende **Adressierung**, wodurch der Master jeden Slave explizit über SS/CS auswählen muss.

**Typische Anwendungen von SPI**
- **Sensoren:** Beschleunigungsmesser, Gyroskope, Temperatursensoren.
- **Displays:** LCDs, OLEDs und Touchscreens.
- **Speicher:** SD-Karten, Flahs-Speicher, EEPROM.
- **Audio:** DACs, ADCs und Audio-Codec-Chips.
SPI ist besonders in Anwendungen belibet, bei denen Geschwindigkeit und einfache Schnittstellen priorisiert werden.

### I2S
**I2S (Inter-IC Sound)** ist ein standaerdisiertes digitales Kommunikationsprotokoll, das speziell für die Übertragung von Audiodaten zwischen digitalen Audiogeräten entwickelt wurde. Es wird häufig verwendet, um Daten zwischen Mikrocontrollwen, digitalen Signalprozessoren (DSPs), Digital-Analog-Wandlern (DACs), Analog-Digital-Wandlern (ADCs) und Audio-Codec-Chips auzutauschen.

**Hauptmerkmale**
**I2S** zeichnet sich durch eine Reihe von Hauptmerkmalen aus, die es zu einer idealen Wahl für Audioprojekte machen. Es handelt sich um ein **audiospezifisches Protokoll**, das speziell für die Übertragung von Audiodaten entwickelt wurde, im Gegensatz zu universellen Protokollen wie **SPI** oder **I2C**. Die **serielle Datenübertragung** reduziert den Bedarf an zusätzlichen Leitungen, wodurch es einfacher zu implementieren ist. I2S verwendet **separate Leitungen für den Bit-Clock (BCLK)** und den **Word-Select (WS)**, was eine präzise Synchronisierung der Audiodaten gewährleistet. Das **Datenformat** unterstützt Standardbreiten von **16, 24 oder 32 Bit** pro Kanal (Stereo), wobei der linke und rechte Kanal in einem festen Zeitrahmen übertragen werden. Zudem bietet I2S eine hohe **Flexibilität**, da es verschiedene **Audioauflösungen** und -formate unterstützt, was es vielseitig einsetzbar macht.

**I2S-Signale**
I2S verwendet in der Regel drei Hauptleitungen:
1. **BCLK (Bit Clock):** Synchronisiert die Übertragung einzelner Bits auf der Datenleitung.
2. **WS (Word Select):** Gibt an, ob die aktuellen Daten zum linken oder rechten Audiokanal gehören.
3. **SD (Serial Data):** Überträgt die Audiodaten bitweise zwischen Master und Slave.
Optional wird manchmal eine vierte Leitung verwendet:
4. **MCLK(Master Clock):** Dient als Haupttacktquelle für hochpräzise Audioanwendungen.

**Wie funktioniert I2S?**
In einer **I2S-Verbindung** gibt es drei Hauptleitungen, die die Funktionalität des Protokolls sicherstellen. Der **BCLK (Bit-Clock)** synchronisiert die Übertragung einzelner Bits, während der **WS (Word-Select)** die Daten für den **linken** und **rechten Audiokanal** trennt. Die **SD (Serielle Datenleitung)** ist für die Übertragung der eigentluchen **Audiodaten** verantwortlich. Die **Master** generiert die Takte (**BCLK** und **WS**) und stellt sicher, dass der **Slave** die Daten synchron empfängt oder sendet. Die Audiodaten werden typischerweise im **MSB-First-Format (Most Significant Bit zuerst)** übertragen, was eine hohe Präzision und Genauigkeit bei der Datenübertragung gewährleistet.

**Vorteile und Nachteile von I2S**
***Vorteile***
Es ist **optimiert für Audio**, da es eine präzise **Synchronisation** und hohe **Qualität** bei der **Audiowiedergabe** und -aufnahme ermöglicht. Die **einfache Integration** wird durch die breite Unterstützung durch viele Mikrocontroller und Audiogeräte erleichtert. Zudem unterstützt I2S **Stereo-Übertragungen**, wodurch es möglich ist, Daten für den linken und rechten Audiokanal gleichzeitig zu übertragen.

***Nachteile***
Die **begrenzte Reichweite** der seriellen Übertragung macht es ungeeignet für lange Distanzen. Es ist ein **spezialisierter Ensatz**, der ausschliesslich für Audioanwendungen konzipiert wurde und sich nicht für allgemeine Datenübertragung eignet. Ausserdem erfordert es einen **hohen Taktbedarf**, da die Synchronisation von **Bit-Takt** und **Wort-Takt** in hochfrequenten Anwendungen anspruchsvoll sein kann.

**Typische Anwendungen von I2S**
- **DACs und ADCs:** Überträgt digitale Audiodaten an DACs für die Ausgabe oder empfängt analoge Signale von ADCs.
- **Audio-Codecs:** Verbindet Mikrocontroller mit Chips, die Audioverarbeitung wie Sampling, Encoding oder Decoding durchführen.
- **Digitale Lautsprecher:** Überträgt Audiodaten an digitale Verstärker oder autsprecher mit integriertem I2S.
- **Mikrofone:** Kommuniziert mit MEMS-Mikrofonen, die digitale Audiodaten bereitstellen.

### I2C
**I²C (Inter-Integrated Circuit)** ist ein synchrones serielles Kommunikationsprotokoll, das für die einfache Verbindung mehrerer integrierter Schaltungen (ICs) auf einer Leiterplatte entwickelt wurde. Es wird häufig in Embedded-Systemen verwendet und ist ideal für Anwendungen, bei denen Geräte mit geringem Datenvolumen kommunizieren müssen, wie Sensoren, Displays oder Speicherbausteine.

**Hauptmerkmale**
**I²C** zeichnet sich durch mehrere Hauptmerkmale aus, die es zu einem beliebten Kommunikationsprotokoll machen. Es basiert auf einer **Master-Slave-Architektur**, bei der der Master die Kommunikation initiiert und steuert, während die Slaves darauf reagieren. Das Protokoll verwendet ein **Zwei-Leitungs-System** mit den Leitungen **SDA (Serial Data)**, die die Daten bidirektional überträgt, und **SCL (Serial Clock)**, die die Synchronisation der Datenübertragung zwischen Master und Slave übernimmt. Jedes Gerät auf dem Bus hat eine eindeutige **Adresse**, die der Master verwendet, um gezielt mit einem spezifischen Slave zu kommunizieren.

Darüber hinaus unterstützt I²C **Multi-Master-Systeme**, bei denen mehrere Master auf demselben Bus existieren können, wobei Mechanismen zur Vermeidung von Konflikten implementiert sind. Die **Taktgeschwindigkeit** ist flexibel und reicht von Standardmodi mit bis zu 100 kHz über den Fast-Modus (bis 400 kHz) und Fast Mode Plus (bis 1 MHz) bis hin zum High-Speed-Modus (bis 3,4 MHz). Ein weiteres wichtiges Merkmal ist der **ACK/NACK-Mechanismus**, bei dem der Empfänger nach jedem empfangenen Byte bestätigt (ACK) oder ablehnt (NACK), wodurch eine zuverlässige Datenübertragung gewährleistet wird.

**I2C Signale**
I²C verwendet ein **Zwei-Leitungs-System**, um die Kommunikation zwischen Master und Slave-Geräten zu ermöglichen:
1. **SDA (Serial Data Line):** Diese Leitung dient zur bidirektionalen Übertragung von Daten zwischen Master und Slave. Die Daten werden bitweise seriell gesendet.
2. **SCL (Serial Clock Line):** Diese Leitung liefert den Takt, der die Übertragung von Daten synchronisiert. Der Master generiert das Taktsignal, um die Kommunikation zu steuern.

Beide Leitungen sind **Open-Drain**, was bedeutet, dass Geräte sie nur auf niedrig ziehen können. Der logische High-Zustand wird durch externe **Pull-Up-Widerstände** erreicht, die SDA und SCL mit der Versorgungsspannung verbinden.

**Wie funktioniert I2C?**
I²C funktioniert, indem der Master die Kommunikation mit einem **Start-Bit** initiiert, wobei die **SDA-Leitung** auf niedrig gezogen wird, während **SCL** hoch ist. Anschließend sendet der Master die **Adresse des Ziel-Slaves**, woraufhin der angesprochene Slave mit einem **ACK-Bit** antwortet.

Die **Datenübertragung** erfolgt synchron mit den Taktsignalen auf der SCL-Leitung, wobei der Empfänger nach jedem Byte ein **ACK-Bit** sendet. Fehler oder das Ende der Übertragung werden mit einem **NACK-Bit** signalisiert. Der Master beendet die Kommunikation durch ein **Stop-Bit**, bei dem die SDA-Leitung von niedrig nach hoch wechselt, während SCL hoch bleibt.

**Vorteile und Nachteile von I2C**
***Vorteile***
Eine der wichtigsten Eigenschaften ist die **einfache Verkabelung**, da unabhängig von der Anzahl der Slaves nur zwei Leitungen erforderlich sind. Dies trägt zu einer **kompakten Architektur** bei, die besonders für platzsparende Designs mit mehreren Geräten geeignet ist. Zudem ist I²C **flexibel** und ermöglicht sowohl Lese- als auch Schreiboperationen, was es vielseitig einsetzbar macht.

***Nachteile***
Es ist **langsamer als SPI**, da die serielle Übertragung und das Adressierungsschema die Geschwindigkeit begrenzen. Die **begrenzte Kabellänge** stellt ein weiteres Problem dar, da die Signalintegrität bei längeren Kabeln abnimmt. Darüber hinaus sind **Pull-Up-Widerstände** für die SDA- und SCL-Leitungen erforderlich, damit das Protokoll korrekt funktioniert, was den Aufbau etwas komplizierter machen kann.


**Typische Anwendungen von I2C**
- **Sensore:** Temperatursensoren, Feuchtigkeitssensoren, Beschleunigungsmesser.
- **Displays:** LCDs und OLEDs.
- **Eingabegeräte:** Tastenfelder und Touchscreens.
- **Mikrocontroller-Kommunikation:** Verbindung zwischen Mikrocontrollern oder Peripheriegeräten.

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
Die integrierten **Digital-Analog-Wandler(DACs)** und **Verstärker** bieten keine **High-End-Audioqualität**, was für anspruchsvolle Audioprojekte einschränkend sein kann. Zudem sind der **Flash-Speicher** und der **Arbeitsspeicher** begrenzt, was die Umsetzung komplexer Anwendungen erschwert. Bei intensiver Nutzung kann es ausserdem zu einer merklichen **Wärmeentwicklung** kommen, was in **kompakten Gehäusen** ohne ausreichende **Kühlung** problematisch sein könnte.

### Fazit
Das **ESP32-Audio-Kit** ist eine leistungsstarke, kostengünstige und vielseitige Plattform für Audioanwendungen. Es eignet sich besonders für Projekte, die **Audio-Streaming**, **Sprachsteuerung** und **interaktive Audiogeräte** umfassen, und bietet durch die Flexibilität des ESP32 Mikrocontrollers zahlreiche Anwendungsmöglichkeiten. Trotz einiger Einschränkungen in der **Audioqualität** und **Speichergröße** ist es eine ausgezeichnete Wahl für viele DIY-Projekte und IoT-Anwendungen.


# Testing
## Funktionale Anforderungen
|Anforderungen              |Funktioniert |Funktioniert nicht |  
|Am Input des ESP32 3.3V    | X |   |  
|Wenn Sensor an eine LED an | X |   |  
|Sensor soll Audioanlage aktivieren| X|   |  
|Audiofiles selbst aufgenommen| X|   |  
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||

# Schwierigkeiten im Code
## Zwei I2C Schnittstellen
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
## 


# Arbeitsjournal
## KW 34
Diese Woche wurde uns das neue Fach **BüP (Berufsübergreifende Projekte)** vorgestellt, das uns die Grundlagen der **Projektsmanagements** näherbringen soll. Dazu haben wir zwei **PowerPoint-Präsentationen** angesehen: **EN22a_BuP_PM_Einführung_240731** und **EN22a_BuP_Projektideen_240801**. In diesen Präsentationen ging es um die **Grundlagen des Projektmanagements**, die Anforderungen an uns Schüler und erste **Projektideen**.

Ein **Projekt** hat ein klares Ziel, ist zeitlich begrenzt und wird duch die Parameter **Qualität**, **Zeit**, **Kosten** und **Risiken** bestimmt. Diese Parameter sind entscheidend, um ein Projekt erfolgreich zu planen und umzusetzen. Besonders wichtig ist es, die **Zusammenhänge zwischen diesen Faktoren** zu verstehen, da Änderungen an einem Parameter oft Auswirkungen auf die anderen Sachen haben.

## KW 35
Der Schwerpunkt des heutigen Tages lag darauf, zu lernen, wie man **effektive Anforderungen** nach der **SMART-Methode** formuliert: **S**pezifisch, **M**essbar, **A**kzeptiert, **R**ealistisch und **T**ermingebunden. Diese Methode hilft sicherzustellen, das Anforderungen präzise und klar definiert sind, was ein entscheidender Faktor für ein erfolgreiches **Projektmanagement** ist.

Wir haben uns dabei mit zwei Arten von Anforderungen beschäftigt:
- **Funktionale Anforderungen:** Diese beschreiben, was das Produkt leisten soll, also konkrete Funktionen und Aufgaben.
- **Nicht-funktionale Anforderungen:** Diese definieren Parameter wie **Qualität, Benutzerfreundlichkeit** oder **Leistung**, die sicherstellen, dass das Produkt den gewünschten Standards entspricht.

Ein zentraler  Aspekt, den wir vertieft haben, war der **Qualitätsparameter**. Dieser legt die Standards fest, die das Produkt erfüllen muss, um die Erwartungen der Nutzer zu erfüllen und den vorgesehenen Zweck zu erreichen. Besonders wichtig ist es, Anforderungen mit einem klaren Fokus auf Qualität zu schreiben, da dies sicherstellt, dass das Endergebnis nicht nur funktional, sondern auch effizient und zuverlässig ist.

Zudem haben wir besprochen, wie die SMART-Methode in der Praxis angewendet werden kann. um Projekte zielgerichtet und struckturiert zu planen. Dies ist eine wichtige Grundlage, um die Zusammenarbeit im Team zu verbessern und Projekte erfolgreich umzusetzen.


In dieser Woche habe ich mich mit meinem Lehrmeister zusammen gesetzt und wir haben uns gemeinsam eine Idee fürs BüP überlegt. Dann kam ihm die Idee das ich eine Szene aus einem Film nachstellen könnte. Da wir vor den Sommerferien noch eben über dies gesprochen hatten, fanden wir dies die perfekte Gelegenheit um diese Idee umzusetzen.

Die Idee war das ich mit einem Sensor eine Audioanlage ansteuere und düber ein "AEWWW" kommt von verschienden Mitarbeiter in meinem Geschäft.

Diese Szene ist aus dem Film *the Hitchhickers Guide to the galaxy* und dort hat es ein Raumschiff dessen Tür immer stöhnt wenn sie geöffnet wird.

## KW 36
In der dritten Woche haben wir uns mit dem Thema **Zeitplan** und **Zeitmanagement** beschäftigt. Dabei lag der Fokus auf der Planung und Festlegung von Terminen, die für den reibungslosen Ablauf des Projekts von grosser Bedeutung sind. Zu den festgelegten Terminen gehören unter anderem:
- Wann werden die Anforderungen unterschrieben und das Projekt offiziell freigegeben?
- Wann findet die Abnahme statt?
- Wann sind die ersten Versuchen geplant?

Zusätzlich zur Terminplanung haben wir und auch mit der Bewertung des Zeitplans befasst:
- Es liegt ein Zeitplan f¨r die gesamte Projektdauer vor.
- Die Auflösung des Zeitplans beträgt 1 Stunde.
- Der Zeitplan soll einen **SOLL-/IST-Vergleich** enthalten, um Abweichungen festzustellen und nachzuverfolgen.


Nach der Einführung von Herrn Jäger zum **Zeitplan** habe ich begonnen, die Anforderungen für mein  Projekt auszuarbeiten. Dazu habe ich zunächst eine **Excel-Tabelle** erstellt, um die wichtigsten Eckdaten festzuhalten. In dieser Tabelle dokumentierte ich das Projekt, den **Projektleiter** (also mich selbst) sowie den **Start** und das **Ende** des Projekts.

Als ersten Schritt habe ich die **funktionalen Anforderungen** formuliert, die die grundlegenden Funktionen des Projekts definieren. Diese beinhalten:
- Das **ESP32-Audio-Kit** darf nicht mehr als **3.3V DC** aufnehmen, um eine Beschädigung durch Überspannung zu vermeiden.
-  Eien **LED** soll anzeigen, wenn der **Bewegungssensor** eine Bewegung detektiert.
- Es sollen **selbst aufgenommene Audiodateien** abgespielt werden können.
- Jede Aktivierung des Bewegungssensor soll eine **Audiodatei** abspielen.
- Das System soll über **verschiedene Modi** verfügen, die flexibel an die Anforderungen angepasst werden können.

Im nächsten Schritt habe ich die **nicht-funktionale Anforderungen** definiert, die sich auf die Eigenschaften und das Design des Projekts beziehen. Diese umfassen:
- Das Projekt soll so gestaltet sein, dass es **über einer Tür montierbar** ist.
- Das **Gehäuse** soll möglichst **kompakt** sein, um Platz zu sparen und die Installation zu erleichtern.
-  das Gehäuse soll mit einem **individuellen Motiv** versehen werden, um eine optisch ansprechende Gestaltugn zu erreichen.

Mit diesen Anforderungen als Grundlage ist ein klarer Rahmen für die weitere Umsetzung des Projekts geschaffen. Die strukturierte Dokumentation hilft dabei, die Zeile stets im Blick zu behalten und das Projekt effizient zu planen und umzusetzen.

## KW 37
Heute lag unser Fokus auf dem Verständnis der **Projektkosten**, die in zwei Hauptkategoriern unterteilt werden:
1. **Arbeitskosten:**
    - **Interne Kosten:** Diese umfassen die Zeit und den Aufwand, den Teammitglieder oder Ressourcen innerhalb der Organisation in das Projekt einbringen.
    - **Externe Kosten:** Diese beziehen sich auf Dienstleistungen oder Arbeitskräfte, die ausserhalb der Organisation bezogen werden, wie z.B. die Beauftragung externer Unterstützung.
2. **Materialkosten:**
    - **Aktivierbare Kosten:** Diese können als Vermögenswerte verbucht werden, da sie direkt zur Erstellung des Endprodukts beitragen und den Wert des Prijekts steigern.
    - **Nicht-aktivierbare Kosten:** Diesse Kosten können nicht als Vermögenswerte erfasst werden. Sie gelten als unmittelbare Ausgaben, die notwendig sind, um das Projekt zu unterstützen.

Dieses Konzept hilft dabei, die verschiedenen Arten vonKosten im Projekt zu unterscheiden und besser nachzuvollziehen, wie sie sich auf das Budget und die Ressourcenplanung auswirken. Er betont auch die Wichtigkeit einer klaren Trennung zwischen investierenden und laufenden Kosten, um eine realistische Kostenkontrolle zu gewährleisten.


Nach der Einführung von Herr Jäger habe ich mit der Erstellung des **Zeitplans** begonnen. Zunächst habe ich mir notiert, welche Punkte der Zeitplan enthalten muss, um alle wichtigen Aspekte des Projekts abzudecken. Dazu gehören unter anderem:
- **Dokumentation**
- **Blockschaltbilder**
- **Schema**
- **Gehäuse Designen**
- **etc.**

Im nächsten Schritt habe ich die **Kalenderwochen** aufgelistet und diese zusätzlich un die einzelnen Wochentage (**Mo, Di, Mi, Do, Fr, Sa, So**) unterteilt. So konnte ich die Aufgaben detailliert und übersichtlich planen. Ausserdem habe ich alle Kategorien im Zeitplan in die Bereiche **Soll** und **Ist** unterteilt, um sowohl di egeplante als auch die tatsächliche Arbeitszeit zu dokumentieren.

Bis **Kalenderwoche 37** habe ich alle Einträge rückwirkend so eingetragen, wie sie tatsächlich abgelaufen sind, um eine realistischen Überblick über den bisherigen Fortschritt zu erhalten. Ab diesem Punkt habe ich den Zeitplan so realistisch wie möglich für die kommenden Wochen erstellt, basierend auf den bisherigen Erfahrungen und dem verbleibenden Arbeitsaufwand.

Zum Schluss habe ich eine zusätzliche Spalte hinzugefügt, in der ich meine **Urlaubszeiten** eingetragen habe, die ich mir im Geschöft genommen habe. Dies soll sicherstellen, dass ich diese Zeit möglichst freihalten kann.

## KW 38
Heute haben wir uns mit dem Konzept der **Projektrisiken** beschäftigt, die einen wesentlichen Einfluss auf den Erfolg oder Misserfolg eines Projekts haben können. Risiken sind potenzielle Ereignisse oder Bedingungen, die sich negativ auf dne **Projektverlauf**, die **Ergebnisse** oder die Ressourcen auswirken können. Sie können aus verschiedenen Bereichen stammen, wie beispielsweise **unsicheren Anforderungen, begrenzten Ressourcen, technischen Herausforderungen** oder **externer Abhängigkeiten.**

Ein zentraler Aspekt bei der Auseindersetzung mit Risiken ist die frühzeitige **Identifikation** und **Bewertung** diese potenziellen Gefahren. Dabei wird zwischen **vermeidbaren Risiken**, die durch sorgfältige Planun, klare Kommunikation und geeigneten Massnahmen minimiert werden können, und **unvorhersehbare Risiken** unterscheiden, die oft durch externe Faktoren wie Marktveränderungen oder Lieferketten prbleme verursacht werden.

Wir haben uns auch mit Strategien zur **Risikobewältigung** beschäftigt, wie der Entwicklung eines **Risikomanagementplans**, der präventive Massnahmen und Notfallpläne enthält. Der Umgang mit Risiken ist ein integraler Bestandteil eines effektiven **Projektmanagements** und trägt wesentlich dazu bei, die **Projektziele** trotz unerwarteter Herausforderungen zu erreichen.


In der **Kalenderwoche 38** habe ich mich intensiv mit der Erstellung von **Blockschaltbildern** beschäftigt, um die verscheidenen Aspekte des Projekts zu visualisieren und zu planen.

Zunächst habe ich ein **Blockschaltbild** für die **Leistungsaufnahme** erstellt, das die Energieversorgung des Systems und die entsprechenden Verbindungen klar darstellt. Ziel war es, sicherzustellen, dass alle Komponenten effizient mit Strim versorgt werden und mögliche Energieverluste minimiert werden können.

Anschliessend habe ich ein weiteres **Blockschaltbild** erstellt, das die Einbindung des **Sensors** in das System darstellt. Damit konnte ich sicherstellen, dass der Sensor korrekt angeschlossen ist und zuverlässig arbeitet.

Zum Abschluss habe ich mir Gedanken darüber gemacht, welche **Bauteile** ich für das gesamte Projekt benötigen werde. Um einen besseren Überblick über die benötigten Komponenten und deren Zusammenhänge zu bekommen, habe ich auch hierfür ein umfassendes **Blockschaltbild** erstellt. Dieses dient als Grundlage für die Materialbeschaffung und die spätere Umsetzung des Projekts.

Durch die Erstellung dieser **Blockschaltbilder** konnte ich eine klare Struktur für die nächsten Schritte im Projekt festlegen und die Planung weiter präzisieren.

Bevor ich mit dem **Blockschema** begonnen habe, habe ich mich zunächst der **Dokumentation** gewidmet. Mein erster Schritt war, das **Arbeitsjournal** zu aktualisieren, indem ich die Einträge der letzten Wochen nachgetragen habe.
Dadurch konnte ich sicherstellen, dass alle bisherigen Fortschritte und Erkenntnisse vollständig dokumentiert sind. Anschliessend habe ich mit dem **Titel** und dem **Inhaltsverzeichnis** des Projektdokuments begonnen, um eine klare und strukturierte Grundlage für die weiteren Inhalte zu schaffen.

Nachdem diese grundlegenden Teile abgeschlossen waren, habe ich den **Zeitplan** erneut überprüft und aktualisiert. Dabei fiel mir auf, dass die **Leistungsaufnahme** meines Projekts bislang nicht berücksichtigt wurde. Um diesen wichtigen Aspekt mit einzubeziehen, habe ich entsprechende Änderungen vorgenommen und den Zeitplan angepasst. Dadurch konnte ich sicherstellen, dass alle relevanten Punkte im Projektablauf korrekt erfasst und berücksichtigt sind.

## KW39
Im heutigen Input ahben wir und damit beschäftigt, wie ein **Projektdokument** systematisch und sinnvoll aufgebaut wird. Dabei haben wir gelernt welche **Kriterien** bei der Bewertung eine Rolle spielen und wie der **Inhalt** effektiv gegliedert werden kann.

Der Lehrer hat uns wichtige **Fragenstellungen** mit auf den Weg gegeben, wie z.B.: **Welche Inhalte sind unbedingt notwendig?** und **Wie strukturiert man das Dokument, damit es logisch und klar verständlich ist?**

Besonders hervorgehoben wurde die Bedeutung einer klaren Struktur und eines nachvollziehbaren Aufbaus, um sicherzustellen, dass das Dokument übersichtlich bleibt und den Anforderungen entspricht.  Mit dieser Herangehensweise können wir ein hochwertiges und gut durchdachtes Projektdokument erstellen.


In dieser Woche habe ich intensiv an meinem **Projektdokument** weitergearbeitet. Neben den Haupttiteln habe ich nun auch die passenden **Untertitel** ergänzt, um die Struktur des Dokuments noch klarer und übersichtlicher zu gestalten. Zusätzlich habe ich mein **Arbeitsjournal** aktualisiert und alle bisherigen Fortschritte sowie offene Punkte festgehalten.

Ein weiterer Schwerpunkt dieser Woche war der **Test des Sensors.** Für mein Projekt benötige ich einen **ToF-Sensor (Time of Flight-Sensor)**, um Bewegungen zuverlässig zu erkennen. Der ursprünglich ausgewählte Sensor schien zunächst geeignet, stellte sich jedoch bei praktischen Tests als unpassend heraus. Da ich mein Gehäuse oberhalb der Tür und nicht seitlich montieren möchte, erwies sich die **Messreichweite** des Sensors als zu gering. Das Problem war, dass der Sensor zwar andere Personen erkennen konnte, mich jedoch nicht, da ich schlichtweg zu klein für den Erfassungsbereich des Sensors bin.

Um eine Lösung zu finden, habe ich mich mit meinem **Lehrmeister** zusammengesetzt, und wir haben gemeinsam nach Alternativen gesucht. Nach intensiver Recherche bei **Sparkfun** sind wir auf zwei **ToF-Sensoren** gestossen, die eine **Reichweite von bis zu 4 Meter** haben. Nach eingehender Abwägung haben wir uns für die kleinere Variante entschieden. Der Grund dafür ist, dass eine einfache Montage und eine ästhetische Integration über der Tür zu gewährleisten.

Diese Entscheidung bringt mein Projekt einen wichtigen Schritt voran, da der neue Sensor alle Anforderungen erfüllt und optimal in das Gesamtkonzept passt. Die nächste Aufgabe besteht nun darin, den neuen Sensor zu bestellen und nach Erhalt ausführlich zu testen, um sicherzustellen, dass er wie geplant funktioniert.

## KW 40
In dieser Woche habe ich mich intensiv mit der **Leistungsaufnahme** meines Projekts beschäftigt, da dies ein eintscheidender Aspekt für die Planung und den Betrieb des Systems ist. Es war für mich besonders wichtig zu wissen, wie viel **Leistung** mein Projekt im Durchschnitt verbraucht und wie lange mein **16V, 1.8Ah Akku** ausreichen wird, um das System zu betreiben.

Ich habe die **Stromaufnahme** des Projekts gemessen und festgestellt, dass im Durchschnitt etwa **17.20mA** benötigt werden. Um eine realistische Einschätzung zu bekommen, habe ich berechnet, wie lange der Akku unter verschiedenen Bediegnungen ausreichen würde. Wenn die **Schaltung ständig aktiv** ist und das Projekt 24 Stunden am Tag läuft, würde eine vollständige **Akkuladung** für etwa **4 tage und 9 Stunden** ausreichen. Wenn das Projekt jedoch nur **10 Stunden am Tag** läuft, würde die Akkuladung **10 Tage und 11 Stunden"" halten, was einen deutlichen Unterschied macht.

Aufgrund dieser Ergebnisse habe ich mich dazu entschlossen, einen **Schalter** in das Projekt einzubauen, der es mir ermöglicht, das System manuell auszuschalten, wenn es nicht benötigt wird. Dies bietet den Vorteil, dass die **Energieeffizienz** verbessert wird, da der Akku nicht unnötig entladen wird, wenn das Projekt nicht aktiv genutzt wird. Ausserdem kann ich so die Lebenssdauer des Zeiträume hinweg zuverlässig betrieben werden kann, ohne ständig aufgeladen werden zu müssen.

Dieser Schritt ist besonders wichtig für die **Nachhaltigkeit** des Projekts und hilft mir, eine Lösung zu finden, die sowohl den **Energieverbrauch** optimiert als auch den Betrieb des Systems flexibel gestaltet.

## KW 41
War in den Ferien, habe nicht daran gearbeitet.

## KW 42
In dieser Woche habe ich mich intensiv mit dem **Schema** meines Projekts beschäftigt. Dazu habe ich mir die **Datenblätter** der einzelnen Komponenten genau angesehen, um sicherzustellen, dass alle notwendigen Anforderungen erfüllt sind und keine wichtigen Details übersehen wurden. Mein Ziel war es, die Funktionalität der Schaltung im Detail zu prüfen und herauszufinden, ob eine der drei Hauptkomponenten zusätzliche Bauteile benötigt, um ordnungsgemäss zu arbeiten.

Während miener Analyse stellte sich heraus, dass der **Schaltregler** sowohl am **Eingang** als auch am **Ausgang** jeweils einen **Kondensator** benötigt, um die Stabilität und Effizienz der Spannungsregulierung zu gewährleisten. Diese Kondensatoren sind wichtig, um **Spannungsschwankungen** auszugleichen und eine reibungslose Funktion der Schaltung sicherzustellen.

Nach dieser Erkenntnis habe ich das Schema entsprechend ergänzt und die Platzierung der Kondensatoren im Schaltplan festgelegt. Zusätzlich habe ich mich mit den **technischen Spezifikationen** dieser Kondensatoren auseinandergesetzt, um die richtigen Werte auszuwählen, die den Anforderungen der Schaltung entsprechen. Diese Anpassungen sind essenziell, um sicherzustellen, dass die gesamte Schaltung wie geplant funktioniert und keine Probleme beim späteren Testen auftreten.

In der **Dokumentation** habe ich nun die **Berechnungen** ergänzt, darunter die Werte zur **Leistungsaufnahme.** Diese sind essenziell, um sicherzustellen, dass das Projekt den geplanten Anforderungen entspricht. Die Berechenungen wurden klar und nachvollziehbar dargestellt.

## KW 43
In dieser woche habe ich die **BoM (Bill of Materials)** erstellt. Zunächst war ich unsicher, wie ich die Liste strukturieren sollte, da ich nur den **ToF-Sensor** bestellen musste. Schließlich habe ich die Liste in zwei Hauptkategorien unterteilt:
1. **Bereits vorhandene Bauteile**
2. **Bauteile, die bestellt werden müssen**

Die Bauteile, die ich bestellen musste, habe ich weiter in folgende Unterkategorien gegliedert:
- **Hersteller:** Die Quelle des Bauteils
- **Preis:** Die Kosten des Bauteils
- **Datenblatt:** Die technischen Informationen des Bauteils
- **Name des Bauteils:** Zur eindeutigen Identifikation

Die Bauteile, die ich bereits hatte, habe ich lediglich mit den Unterkategorien **Name des Bauteils** und **Datenblatt** versehen, um die Informationen übersichtlich zu halten.

Diese Struktur sorgt für eine klare und gut nachvollziehbare Übersicht der Bauteile, die im Projekt verwendet werden, und erleichtert den späteren Zugriff auf alle relevanten Details.

Anschliessend habe ich in dieser Woche mein **Vero-Board** gelötet. Dabei stiess ich auf einige Schwierigkeiten, da ich die Verbindungen vollständig selbst mit **Litzen** herstellen musste. Einige der Verbindungsstellen waren entweder direkt nebeneinander oder hatten nur einen sehr kleinen Abstand zueinander, was die Arbeit zusätzlich erschwerte. Um Probleme wie das **Verbrühen** oder Fehler beim Löten zu vermeiden, entschied ich mich, **Lötbrücken** zu setzen, anstatt jedes einzelne Kabel zu verlöten. Diese Methode ermöglichte es mir, die Verbindungen schneller und sicherer herzustellen, ohne dass es zu Fehlern oder Beschädigungen kam. Es war eine effiziente Lösung, die mir Zeit sparte und gleichzeitig sicherstellte, dass die Verbindungen zuverlässig waren.

In der **Dokumentation** habe ich begonnen, die Funktionen wie **SPI (Serial Peripheral Interface)** und **I2S (Inter-IC Sound)** zu beschreiben. Dabei habe ich detailliert erklärt, wie diese **Kommunikationsprotokolle** in meinem Projekt verwendet werden und welche Rolle sie in der **Datenübertragung** und **Signalverarbeitung** spielen. **SPI** wird verwendet, um eine schnelle und zuverlässige **Datenübertragung** zwischen den verschiedenen Komponenten zu ermöglichen, während **I2S** für die **Audio-Datenübertragung** zuständig ist. Diese Details sind entscheidend, um die **technischen Grundlagen** meines Projekts verständlich zu machen und eine klare Nachvollziehbarkeit der verwendeten Technologien zu gewährleisten. Zudem habe ich die Bedeutung dieser Protokolle für die Funktionalität und Effizienz des Systems erläutert, um zu verdeutlichen, wie sie zum Gesamterfolg des Projekts beitragen.

## KW 44
In der **Woche 44** habe ich mich daran gemacht, das **Gehäuse** zu designen. Ehrlich gesagt hatte ich mir den Prozess einfacher vorgestellt, als er letztlich war. Ich habe das Gehäuse mit **OnShape** gezeichnet. Da ich zu Beginn nicht genau wusste, wie die Plattform funktioniert hat mein **Oberstift Eros Porcella** mir geholfen, mein Projekt in OnShape einzurichten und mich beim Zeichnen zu unterstützen. Er hat mir bei den ersten Schritten zur Seite gestanden und viele meiner Fragen beantwortet.

Nachdem ich alle einzelnen Bauteile des Gehäuses gezeichnet hatte, musste ich sie noch im **Assembly** zusammenfügen, um sicherzustellen, dass alles wie geplant zusammenpasst. Dabei stellte sich jedoch heraus, dass ich die einzelnen Elemente nicht auf der gleichen Ebene gezeichnet hatte. Um dieses Problem zu lösen, habe ich mir **YouTube-Videos** angeschaut, die mir zeigten, wie ich das gesamte Design auf eine andere **Grundebene** verschieben kann. Bei der Gestaltung des **UART-Ports** gab es ebenfalls Schwierigkeiten, weshalb ich das Design an dieser Stelle nochmals überarbeiten musste.

Am **Freitag** habe ich das Gehäuse dann drucken lassen, und am **Samstagmittag** war es schliesslich fertig gedruckt.

In der **Dokumentation** habe ich ausserdem mit dem Abschnitt zu I2C weitergeschrieben.

## KW 45
Als ich am Mittwoch ins **Geschäft** kam, lag das **Gehäuse** bereits auf meinem Arbeitsplatz, und ich habe es sofort zusammengebaut. Grundsätzlich war das Gehäuse gut, jedoch noch nicht ganz perfekt. Das Loch für den **Schalter** war nicht ganz mittig, und der **SD-Karten-Schlitz** war etwas zu schmal. Es war nicht möglich, die SD-Karte mit den Fingern einzusetzen oder zu entnehmen, man hätte stattdessen ein kleines Werkzeug verwenden müssen. Diese Probleme habe ich in der **zweiten Version** korrigiert. Auch diese habe ich anschliessend erneut **drucken** lassen, und die überarbeitete Version hat perfekt gepasst.

Am gleichen Tag nahm ich das Gehäuse mit nach Hause und habe es zuerst in einer **Grundfarbe** bemalt. Nachdem die Farbe getrocknet war, habe ich das **Motiv** zunächst mit **Bleistift** vorgezeichnet. Anschliessend habe ich das Motiv mit **Farbe** gestaltet und dabei **Schatteneffekte** hinzugefügt, um das Design abzurunden.

Zu Beginn der Woche habe ich das **Arbeitsjournal** der vergangenen Woche aktualisiert, da ich etwas hinterher war. Danach habe ich mich mit einigen **Details** zum **Schaltregler** beschäftigt, den ich in meinem Projekt verwende.

## KW 46
In dieser Woche habe ich mich mit der **Aufnahme der Audio-Dateien** für mein Projekt beschäftigt. Dafür stellte mir mein **Lehrmeister** sein **Aufnahmegerät** zur Verfügung. Ich ging im **Geschäft** umher und fragte etwa 5-6 verschiedene Personen, ob sie bereit wären, mich zu unterstützen und eine Aufnahme beizutragen. Glücklicherweise waren alle, die ich angesprochen hatte, **bereitwillig** und sogar erfreut, mir helfen zu können. Jede Person lieferte **zwei individuelle** Aufnahmen, die ich später in mein Projekt einfügen wollte.

Nachdem ich alle **Aufnahmen** gesammelt hatte, zeigte mir mein Lehrmeister die Software **Audacity**, ein Tool zur Bearbeitung von Audio-Dateien. Er erklärte mir die grundlegenden Funktionen der Software, und ich begann, die Aufnahmen zu bearbeiten. Dabei schnitt ich die Dateien zurecht, passte die Lautstärke an und fügte, wo nötig, Filter hinzu, um die Qualität der Aufnahmen zu verbessern. Dieser Prozess war sehr lehrreich, da ich dabei einiges über **Audio-Bearbeitung** und den Umgang mit professioneller Software gelernt habe.

Im letzten Schritt habe ich die final bearbeiteten Audio-Dateien auf meine **SD-Karte** geladen, damit sie später im Projekt verwendet werden können. Dieser Meilenstein war besonders wichtig, da die Audio-Dateien eine zentrale Rolle in meinem Projekt spielen.

In der **Dokumentation** habe ich parallel begonnen, detailliert über den **ToF-Sensor** zu schreiben. Dabei ging ich auf seine Funktionsweise, die Reichweite und die Integration in mein Projekt ein. Außerdem fing ich an, den Teil über das **ESP32-Audio-Kit** zu verfassen. Hier beschrieb ich die grundlegenden Eigenschaften des Kits und wie es in meinem Projekt eingebunden wird.

## KW 47
In dieser Woche habe ich von meinem **Lehrmeister** zwei verschiedene **Code-Beispiele** erhalten: einen für den **ToF-Sensor** und einen weiteren für das **ESP32-Audio-Kit.** Meine Aufgabe bestand darin, diese beiden Code-Segmente so zusammenzufügen, dass sie reibungslos zusammenarbeiten. Da ich bisher noch keine Erfahrung mit der **I2S-Schnittstelle** gesammelt hatte, stellte dies eine besondere Herausforderung dar, bot mir aber gleichzeitig eine großartige Gelegenheit, Neues zu lernen.

Zuerst analysierte ich die beiden Code-Teile, um zu verstehen, wie sie jeweils aufgebaut waren und welche Teile in das **Setup** und den **Loop** meines Programms integriert werden konnten. Es war entscheidend, sicherzustellen, dass die beiden Funktionen nicht miteinander in Konflikt geraten, insbesondere da das ESP32-Audio-Kit sehr empfindlich auf Timing und Signalverarbeitung reagiert. Nachdem ich die notwendigen Abschnitte in den **Setup-Bereich** eingefügt hatte, überprüfte ich die bestehenden Schleifenstrukturen im **Loop.**

Ein Problem, das ich lösen musste, war die mögliche **Blockade durch Schleifen** (z. B. **for-Loops**), die verhindern könnten, dass das Programm rechtzeitig die Audio-Funktion ausführt. Da die Audio-Wiedergabe konstant und ohne Unterbrechungen laufen muss, durfte das Programm nicht in einer Schleife „hängen bleiben“. Um dieses Problem zu lösen, beschäftigte ich mich intensiv mit der **millis**()-Funktion, einer Methode, um zeitgesteuerte Aktionen ohne blockierende Schleifen auszuführen. Nach einigen Experimenten gelang es mir, die Logik anzupassen und die **millis**()-Funktion so einzusetzen, dass sowohl der ToF-Sensor als auch das Audio-Kit zuverlässig arbeiten konnten.

In der **Dokumentation** habe ich diese Woche die **Berechnungen** hinzugefügt. Dazu zählten unter anderem die **Leistungsaufnahme**, die **Laufzeitberechnungen** für den Akku und die Details zu den Schaltungsanpassungen. Diese Berechnungen sind entscheidend, um die technische Umsetzbarkeit meines Projekts zu dokumentieren und sicherzustellen, dass alle relevanten Aspekte berücksichtigt wurden.

## KW 48
In der **Woche 48** habe ich mich intensiv mit der Programmierung eines **Switch-Case-Systems** beschäftigt, das notwendig war, um die beiden verschiedenen **Modi** meines Projekts umzusetzen. Die Idee hinter dieser Struktur war es, eine klare und effiziente Möglichkeit zu schaffen, zwischen den Modi hin- und herzuschalten. Hierfür benötigte ich eine **Flankenerkennung**, um zu registrieren, wann ein Button gedrückt wurde. Diese Buttons, die über den **ESP32** eingelesen werden, ermöglichen es mir, den Modus je nach Bedarf zu wechseln.

Um dies umzusetzen, musste ich mich zunächst mit der Logik der **Flankenerkennung** vertraut machen. Dabei ging es darum, zu erkennen, ob ein Signal von "nicht gedrückt" auf "gedrückt" wechselt, sodass der Modus nur bei einem echten Tastendruck umgeschaltet wird. Nach einigen Experimenten gelang es mir, die gewünschte Funktionalität zu implementieren.

Zusätzlich habe ich zwei **If-Abfragen** programmiert, mit denen die **Lautstärke** des Audios manuell angepasst werden kann. Der erste Button reduziert die Lautstärke, während der zweite Button sie erhöht. Diese Funktion war für mich besonders wichtig, da sie den Nutzer ermöglicht, die Wiedergabe flexibel an ihre Bedürfnisse anzupassen.

Ein weiteres Feature, das ich umsetzen wollte, war die Möglichkeit, die **Audio-Dateien in zufälliger Reihenfolge** abzuspielen. Im entsprechenden Modus sollten die Dateien nicht chronologisch, sondern in einer **Random-Reihenfolge** abgespielt werden. Dafür musste ich mich eingehend mit der **random()**-Funktion beschäftigen. Nach einigen Tests konnte ich sicherstellen, dass die zufällige Wiedergabe wie gewünscht funktioniert und keine Datei doppelt abgespielt wird, bevor alle anderen einmal abgespielt wurden.

Parallel dazu habe ich in der Dokumentation weitergearbeitet und mich dabei auf das **Arbeitsjournal** konzentriert. Ich aktualisierte die Einträge der vergangenen Wochen und fügte weitere Details hinzu, um die Fortschritte und Herausforderungen meiner Arbeit vollständig zu dokumentieren.

## KW 49
In dieser Woche habe ich mich darum gekümmert, dass die **Audio-Dateie**n nicht mehr manuell in den **Code** eingebunden werden müssen. Stattdessen sollte der Prozess automatisiert ablaufen, sodass neue **Sound-Dateien**, die auf die **SD-Karte** geladen werden, automatisch erkannt und ins **Programm** integriert werden.

Hierfür habe ich den **Code** angepasst, um alle auf der SD-Karte gespeicherten **Audio-Dateien** dynamisch einzulesen und in einer Liste zu speichern. Diese Liste wird dann vom Programm verwendet, um die Dateien abzuspielen, ohne dass eine erneute manuelle Anpassung notwendig ist. Der Vorteil dieses Ansatzes ist, dass das System künftig flexibel bleibt und mit neuen **Audio-Inhalten** erweitert werden kann, ohne zusätzlichen Aufwand.

Die Umsetzung erforderte, dass ich mich intensiver mit den **Dateisystem-Funktionen** der SD-Bibliothek auseinandergesetzt habe, um sicherzustellen, dass alle Dateien korrekt gelesen und eingebunden werden. Zudem testete ich die Funktion ausgiebig, um sicherzugehen, dass auch unterschiedliche Dateiformate und Dateinamen problemlos erkannt werden.

Mit dieser Anpassung ist das Projekt deutlich anwenderfreundlicher und effizienter geworden.

## KW 50
In dieser Woche habe ich mich darauf konzentriert, meinen **Loop** im Code sorgfältig zu **kommentieren**. Das Ziel war es, den Ablauf des Programms klarer und verständlicher zu machen, sowohl für mich als auch für andere Personen, die den Code möglicherweise lesen oder weiterentwickeln möchten.

## KW 51
In dieser Woche habe ich mein **Projekt** ausführlich anhand der festgelegten **Anforderungen** getestet. Dabei überprüfte ich, ob alle **funktionalen** und **nicht-funktionalen Anforderungen** erfüllt wurden. Besonders achtete ich darauf, dass der **ToF-Sensor** zuverlässig funktioniert, die **Audio-Wiedergab**e korrekt abläuft und die **Modi-Steuerung** wie geplant umschaltet. Zusätzlich testete ich die **Lautstärkeregelung** und die **Zufallswiedergabe** der Audiodateien. Wo kleinere Abweichungen auftraten, habe ich Notizen gemacht, um diese später anzupassen.

## KW 52
In den **Ferien** habe ich die **Zeit** genutzt, um meine **Rechtschreibfehler** in der **3** zu korrigieren. Dabei habe ich jeden Abschnitt sorgfältig durchgelesen und verbessert, um sicherzustellen, dass der Text klar und fehlerfrei ist. Zusätzlich habe ich kleinere **Formatierungsanpassungen** vorgenommen, um die Lesbarkeit weiter zu optimieren.

## KW 01
In dieser Woche habe ich die **Bilder** in die **Dokumentation** eingefügt, passend beschriftet und kurz erklärt, um den Inhalt **anschaulicher** zu gestalten.

## KW 02
Auch in der letzten Woche habe ich das **Dokument** nochmals **überflogen** und **überarbeitet**. Geplant ist, dass ich mich für die kommenden Woche der **Vorbereitung** der **Präsentation** widme.

# Anhang
[ESP32 Datenblatt](esp32-audio-kit_v2.2_sch.pdf)  
[TOF Datenblatt](TMF882X_DataSheet.pdf)  
[TOF mini Schematic](SparkFun_dToF-TMF8820_Mini_Schematic.pdf)  
[Schaltregler Datenblatt](R_78E_1_0-1711201.pdf)  

# Zeitplan und Anforderungen
[Zeitplan und Anforderungen](Marvin_AudioAnlage_Anforderungen_NoraHueppi_20240917.xlsx)  
