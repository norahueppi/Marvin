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
Für mein BüP Projekt habe ich mich dazu entschieden, eine ikonische Szene aus *The hitchhicker's guide to the galaxy* nach zu bilden: die stöhnende Tür. Dieses Projekt kombiniert Punkte aus Technik, Design und Unterhaltung, um Douglas Adams Klassikerauf kreativeund funktionale weise nach zu stellen.  
  
Die stöhnende Tür symbolisiert den skurrilen Charme und die technische Absurdität, die das Universum der Hichhicker's Guide prägen. Mein Ziel ist es, die Mechanik und den charakteristischen Sound dieser Tür nachzuempfinden und damit einen kleinen, aber unvergesslichen Aspekt der Geschichte zum Leben zu erwecken.  
  
Im Verlauf des Projekts werde ich mir überlgungen zur genauen umsetzung machen, damit ich eine möglichst authentische Nachbildung erreichen kann. Dabei Liegt der Schwerpunkt sowohl auf der technischen Umsetzung als auch der humorvollen Präsentation.   
  
Dieses Projekt bietet mir die Möglichkeit meine Fähigkeit in der Elektronik und der Programmierung zu erweitern.  
  
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
