#include "Arduino.h"
#include "SPI.h"
#include "SD.h"
#include "FS.h"
#include "Wire.h"
#include "ES8388.h"  // https://github.com/schreibfaul1/es8388
#include "Audio.h"   // https://github.com/schreibfaul1/ESP32-audioI2S
#include "SparkFun_TMF882X_Library.h" //http://librarymanager/All#SparkFun_Qwiic_TMPF882X

void printLine()
{
    Serial.println();
}

template <typename T, typename... Types>
void printLine(T first, Types... other)
{
  Serial.print(first);
  printLine(other...) ;
}

// microSD Card Reader connections
#define SD_CS         13
#define SPI_MOSI      15 
#define SPI_MISO       2
#define SPI_SCK       14

// I2S GPIOs
#define I2S_SDOUT     26
#define I2S_BCLK      27
#define I2S_LRCK      25
#define I2S_MCLK       0

// I2C GPIOs
#define IIC_CLK       32
#define IIC_DATA      33

// Amplifier enable
#define GPIO_PA_EN    21

//Delay in Millisekunden
#define SENSOR_UPDATE_TIME  10
#define BUTTON_UPDATE_TIME  100
#define FUENF 5000

//Buttons einlesen
#define BTN_LOUDER  29
#define BTN_QUIETER 30
#define BTN_MODI0   31
#define BTN_MODI1   32

//Cases for Modi State
#define MODI0 0
#define MODI1 1

int volume = 80;                            // 0...100

int Volume = 0;

int RandomNumber = 0;
int Reihenfolge = 0;

int BtnModi0Last = 0;
int BtnModi1Last = 0;
int BtnLouderLast = 0;
int BtnQuieterLast = 0;
// int Modi = 0;

int ModiState = MODI0;

unsigned long SensorDelay = 0;
unsigned long ButtonDelay = 0;

bool started = false;

SparkFun_TMF882X  myTMF882X;
ES8388 es;
Audio audio;
TwoWire I2CSensor = TwoWire(1);

typedef enum {
    FT_OTHER,
} filetype_t;

typedef struct {
    String name;
    unsigned int len;
    filetype_t type;
} filelist_t;

static struct tmf882x_mode_app_config tofConfig = { 0 };
static struct tmf882x_msg_meas_results myResults;

#define MAX_FILE_AMOUNT 50

uint32_t filesfound = 0;
uint32_t ackfiles = 0;
uint32_t failfiles = 0;
uint32_t failchances = 0;
uint32_t ackchances = 0;
filelist_t filelist[MAX_FILE_AMOUNT];

void createFileEntry(String name) {
  if(name.indexOf(".mp3")>= 0) {
    filelist[filesfound].name = name;
    filelist[filesfound].len = name.length();
    filelist[filesfound].type = FT_OTHER;
    filesfound++;
    // Serial.print("Add File: ");
    // Serial.println(name);
    printLine("Add File: ", name);
  }
}
//----------------------------------------------------------------------------------------------------------------------

void printDirectory(File dir, int numTabs) {
    while (true) {
        File entry =  dir.openNextFile();
        if (! entry) {
            // no more files
            break;
        }
        if (entry.isDirectory()) {
            printDirectory(entry, numTabs + 1);
        } else {
            createFileEntry(entry.name());
        }
        entry.close();
    }
}

void setup() {
  Serial.begin(115200);
//----------------------------------------------------------------------------------------------------------------------
//Button einlesen
  Serial.println("Starting reading Buttons");

  pinMode(BTN_LOUDER, INPUT_PULLUP);
  pinMode(BTN_QUIETER, INPUT_PULLUP);
  pinMode(BTN_MODI0, INPUT_PULLUP);
  pinMode(BTN_MODI1, INPUT_PULLUP);

  Serial.println("Finisched reading Buttons");
//----------------------------------------------------------------------------------------------------------------------
// ESP32  
  Serial.println("\r\nReset");

  SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);
  SPI.setFrequency(1000000);

  SD.begin(SD_CS);
  File root;
  root = SD.open("/");
  printDirectory(root, 0);

  printLine("\nFound ", filesfound, " Files total.\n");
  Serial.printf("Connect to ES8388 codec... ");
  while (!es.begin(IIC_DATA, IIC_CLK))
  {
      Serial.printf("Failed!\n");
      delay(1000);
  }
  Serial.printf("OK\n");

  es.volume(ES8388::ES_MAIN, volume);
  es.volume(ES8388::ES_OUT1, volume);
  es.volume(ES8388::ES_OUT2, volume);
  es.mute(ES8388::ES_OUT1, false);
  es.mute(ES8388::ES_OUT2, false);
  es.mute(ES8388::ES_MAIN, false);
  es.SetVolumeSpeaker(80);

  // Enable amplifier
  pinMode(GPIO_PA_EN, OUTPUT);
  digitalWrite(GPIO_PA_EN, HIGH);

  audio.setPinout(I2S_BCLK, I2S_LRCK, I2S_SDOUT, I2S_MCLK);
  audio.setVolume(Volume); // 0...21

//   printDirectory("/", 1);

  printLine("Play File");
  // audio.connecttoFS(SD, "info_computersagtnein.mp3");
  audio.connecttoFS(SD, "music_bennyhill.mp3");
  char filename[filelist[1].len+1];
  filelist[1].name.toCharArray(filename, sizeof(filename));
//   audio.connecttoFS(SD, filename);
  //music_bennyhill.mp3

//----------------------------------------------------------------------------------------------------------------------
// TMF8820
  Serial.println("TMF8820 Arduino Template");

  Serial.println("In setup");
  Serial.println("==============================");

  I2CSensor.begin(18, 23);
//   Wire.setPins(18, 23);

  if(!myTMF882X.begin(I2CSensor))
  {
     Serial.println("Error - The TMF882X failed to initialize - is the board connected?");
    while(1);
  }else {
    Serial.println("TMF882X started.");
  }
  bool bConfigSet = false;
  if (myTMF882X.getTMF882XConfig(tofConfig))
  {
    // Change the report period
    Serial.print("tofconfig.report_period_ms = ");
    Serial.println(tofConfig.report_period_ms);

    Serial.print("tofconfig.kilo_iterations = ");
    Serial.println(tofConfig.kilo_iterations);

    Serial.print("tofconfig.power_cfg = ");
    Serial.println(tofConfig.power_cfg);

    Serial.print("tofconfig.spad_map_id = ");
    Serial.println(tofConfig.spad_map_id);

    tofConfig.report_period_ms = 50;
    tofConfig.kilo_iterations = 50;

    bConfigSet = myTMF882X.setTMF882XConfig(tofConfig);
    Serial.print("Configresult: "); Serial.println(bConfigSet);
    myTMF882X.setSampleDelay(10);
  }

   Serial.println("End Setup\n");
//----------------------------------------------------------------------------------------------------------------------
//um eine Random Nummer zu generieren
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  audio.loop();

  switch (ModiState)
  {
    case MODI0:
      Serial.println("Modi 0");
      
      if((BTN_MODI1 != BtnModi1Last) && (BTN_MODI1 == LOW))
      {
        ModiState = MODI1;
      }

      if((BTN_LOUDER != BtnLouderLast) && (BTN_LOUDER == LOW))
      {
        Volume++;

        if (Volume >= 21)
        {
          Volume = 21;
        }
      }

      //Wenn man den Button Quieter drückt dann kann man manuel den Ton Leiser stellen und wenn die Laustärke
      //schon auf dem mindesten ist kann es nicht leiser gehen
      if((BTN_QUIETER != BtnQuieterLast) && (BTN_QUIETER == LOW))
      {
        Volume--;

        if(Volume <= 0)
        {
          Volume = 0;
        }
      }

      if(SensorDelay <= millis())
      {
        // Serial.println("Updated");
        SensorDelay = millis() + SENSOR_UPDATE_TIME;

        if(myTMF882X.startMeasuring(myResults, 50))
        {
          // Serial.print(".");

          for (int i = 0; i < myResults.num_results; ++i)
          {
            if(myResults.results[i].distance_mm < 1000)
            {
              // Serial.println("Found you");
              if(started == false)
              {
                started = true;
                
                //gibt eine random Nummer zwischen 1 und 12 aus
                RandomNumber = random(1, 13);
                char filename[filelist[RandomNumber].len+1];
                filelist[RandomNumber].name.toCharArray(filename, sizeof(filename));

                //Test file
                //audio.connecttoFS(SD, "info_computersagtnein.mp3");
              }
              break;
            }
          }
        }
      }
      
      BtnModi1Last = BTN_MODI1;
      BtnLouderLast = BTN_LOUDER;
      BtnQuieterLast = BTN_QUIETER;

      break;

    case MODI1:
      Serial.println("Modi 1");

      if((BTN_MODI0 != BtnModi0Last) && (BTN_MODI0 == LOW))
      {
        ModiState = MODI0;
      }

      if((BTN_LOUDER != BtnLouderLast) && (BTN_LOUDER == LOW))
      {
        Volume++;

        if(Volume >= 21)
        {
          Volume = 21;
        }
      }

      if((BTN_QUIETER != BtnQuieterLast) && (BTN_QUIETER == LOW))
      {
        Volume--;

        if(Volume <= 0)
        {
          Volume = 0;
        }
      }

      if(SensorDelay <= millis())
      {
        // Serial.println("Updated");
        SensorDelay = millis() + SENSOR_UPDATE_TIME;

        if(myTMF882X.startMeasuring(myResults, 50))
        {
          // Serial.print(".");

          for (int i = 0; i < myResults.num_results; ++i)
          {
            if(myResults.results[i].distance_mm < 1000)
            {
              // Serial.println("Found you");
              if(started == false)
              {
                started = true;
                
                Reihenfolge++;
                char filename[filelist[Reihenfolge].len+1];
                filelist[Reihenfolge].name.toCharArray(filename, sizeof(filename));

                if(Reihenfolge >= 12){
                  Reihenfolge = 1;
                }

                //Test file
                // audio.connecttoFS(SD, "music_bennyhill.mp3");
              }
              break;
            }
          }
        }
      }

      BtnModi0Last = MODI0;

      break;
  }
}

// optional
void audio_info(const char *info){
    Serial.print("info        "); 
    Serial.println(info);
}
void audio_id3data(const char *info){  //id3 metadata
    Serial.print("id3data     ");
    Serial.println(info);
}
void audio_eof_mp3(const char *info){  //end of file
    Serial.print("eof_mp3     ");
    Serial.println(info);
    started = false;
}
void audio_showstation(const char *info){
    Serial.print("station     ");
    Serial.println(info);
}
void audio_showstreaminfo(const char *info){
    Serial.print("streaminfo  ");
    Serial.println(info);
}
void audio_showstreamtitle(const char *info){
    Serial.print("streamtitle ");
    Serial.println(info);
}
void audio_bitrate(const char *info){
    Serial.print("bitrate     ");
    Serial.println(info);
}
void audio_commercial(const char *info){  //duration in sec
    Serial.print("commercial  ");
    Serial.println(info);
}
void audio_icyurl(const char *info){  //homepage
    Serial.print("icyurl      ");
    Serial.println(info);
}
void audio_lasthost(const char *info){  //stream URL played
    Serial.print("lasthost    ");
    Serial.println(info);
}
void audio_eof_speech(const char *info){
    Serial.print("eof_speech  ");
    Serial.println(info);
}