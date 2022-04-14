#include <header.h>

#define EINS      13
#define MINUS     14
#define UND       18
#define IP        20
#define HUNDERT   30
#define MILION    32
#define MILIARDE    33



static String as_numDe[] =  {"null" , "ein", "zwei",   "drei",    "vier",   "fuenf",   "sechs",  "sieben", "acht",   "neun",
                      "zehn" , "elf", "zwoelf", "eins",    "minus ", " komma ", "16",     "17",     " und ",  " dot ",
                      "ipadr", "zehn", "zwanzig", "dreissig", "vierzig", "fuenfzig", "sechzig", "siebzig", "achtzig", "neunzig",
                      " hundert ", " tausend ", "milion" , "miliarde"
                            };

String playDe(int i)
{
  //  mp3.play(i); // Spiele ein MP3-File mit dem gesprochenen Text des obigen Array ab
  return as_numDe[i];
}   

static String speakGDe(int i)
{
    String s ="";
    int millie = i / 1000000000;
    s += spkDe(millie) + playDe(HUNDERT + 3) + " ";
    return s;

}
static String speakMDe(int i)
{
    String s ="";
    int millie = i / 1000000;
    s += spkDe(millie) + playDe(HUNDERT + 2) + " ";
    return s;

}
static String speakKDe(int i)
{
    String s ="";
    int tausend = i / 1000;
    s += spkDe(tausend) + playDe(HUNDERT + 1) + " ";
    return s;

}
static String speak100De(int i)
{
  String s = "";
  int hundert = i / 100;
  s += playDe(hundert) + playDe(HUNDERT);

  return s;
}
static String spkDe(int i) //Code by: Richard Hoerman
{
  String s ="";
  if (i > 100)
  {
    s += speak100De(i);
    i = i % 100;
  }
  if (i == 1) {
    return s += playDe(EINS);
  }
  if (i <= 12) {
    return s += playDe(i);
  }
  int einer = i % 10; int zehner = i / 10;
  if (einer != 0) {
    s += playDe(einer);
    if (i > 20) {
      s += playDe(UND);
    }
  }
  return s + playDe(zehner + 20);
  }
  
static String digit2TextAndSoundDe(int i)
{
  String s = "";
  if (i<0)i*=-1;
  if (i > 999999999)//    The G part
  {
    s+=speakGDe(i);
    i%=1000000000;
    
  }
  if (i > 999999)//       The M part
  {
    s+=speakMDe(i);
    i%=1000000;
  }
  if (i > 999)//          The K part
  {
    s+=speakKDe(i);
    i%=1000000000;
  }
  return s+spkDe(i);//    The "spk" part
}
static String SpeakDe(int i)
{
  String s = String(i) + " == ";
  if (i < 0) {
    s += playDe(MINUS);
    i = -i;
    return s + digit2TextAndSoundDe(i);
}

}
