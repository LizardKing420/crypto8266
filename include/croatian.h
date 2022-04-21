#include "header.h"

#define _jedna 11
#define _dvije 12
#define _naest 13
#define _cetr 14
#define _hundert 17
#define _tausend 19
#define _milion 22
#define _miliarde 24
#define _minus 27
#define _plus 28
#define _komma 29
#define _punkt 30

String as_numHr[] = {
    "nula",
    "jedan",
    "dva",
    "tri",
    "cetri",
    "pet",
    "sest",
    "sedam",
    "osam",
    "devet",
    "deset",
    "jedna",
    "dvije",
    "naest",
    "cetr",
    "pedeset",
    "sezdeset",
    "sto",
    "dvjesto",
    "tisucu",
    "tisuce",
    "tisuca",
    "milijun",
    "milijuna",
    "milijardi",
    "milijarde",
    "milijardi",
    "minus",
    "plus"
    "zarez",
    "tocka",
};

String digit2TextAndSoundHr(int i);
String spkHr(int i);
String playHr(int i) // vraca i-ti element araya as_numHr[] te poslje ce takoder pokretati playback i-te audiotrake na MP3-Playeru
{
  //  mp3.play(i); // die Kroatische Version der Methode play
  return as_numHr[i];
}
String speak1GHr(int i)
{
  int z = i / 1000000000;
  if (z % 10 > 4)
  {
    return spkHr(z) + " " + playHr(_miliarde + 2) + " ";
  }
  else if (z % 10 > 1)
  {
    return spkHr(z) + " " + playHr(_miliarde + 1) + " ";
  }
  return spkHr(z) + " " + playHr(_miliarde) + " ";
}
String speak1MHr(int i)
{
  int z = i / 1000000;
  if (z % 10 > 1)
  {
    return spkHr(z) + " " + playHr(_milion + 1) + " ";
  }
  return spkHr(z) + " " + playHr(_milion) + " ";
}
String speakKHr(int i)
{
  String ret = "";
  int z = i / 1000; // ovo je izolirani "K" dio inputa
  if ((z % 10 > 4) || (z % 10 == 0) || (z%100>10 && z%
  100<20))
  {
    return spkHr(z) + " " + playHr(_tausend + 2) + " "; // ako je zadnja cifra K-djela veca od 4 onda "tisuca"
  }

  else if (z % 10 > 2)
  {
    return spkHr(z) + playHr(_tausend + 1) + " "; // ako je zadnja cifra K-djela 3 ili 4 onda "tisuce"
  }
  else if (z % 10 > 1)
  {
    return spkHr(z - z % 10) + playHr(_dvije) +" " + playHr(_tausend + 1) + " "; // ako je zadnja cifra K-djela 2 pobrini se da kaze "dvije" umjesto "dva"
  }
  else if (z == 1)                              // onda samo vrati tisucu
  {
    return playHr(_tausend) + " ";
  }
  else if (z % 10 == 1)                         // ako je zadnja znamenka 1
    {
      return spkHr(z - z % 10) + playHr(_jedna) + " " + playHr(_tausend + 2) + " "; // ako je zadnja cifra K-djela 2 pobrini se da kaze "dvije" umjesto "dva"
    }

  return ret;
}
String speak100Hr(int i)
{
  if (i > 299)
    return playHr(i / 100) + playHr(_hundert) + " ";
  if (i > 199)
    return playHr(_dvije) + playHr(_hundert) + " ";
  return playHr(_hundert) + " ";
}

String speak10Hr(int i)
{
  int zehner = i / 10;
  if (zehner == 4)
  {
    return playHr(_cetr) + playHr(10) + " ";
  }
  return playHr(zehner) + playHr(10) + " ";
}

String speakNaestHr(int i)
{
  int einzer = i - 10;
  if (einzer == 4)
  {
    return playHr(_cetr) + playHr(_naest);
  }
  return playHr(einzer) + playHr(_naest);
}
String speak1Hr(int i)
{
  return playHr(i);
}

String speakHr(int i)
{
  String s = String(i) + " == ";
  if (i < 0)
  {
    s += playHr(_minus) + " ";
    i = -i;
  }
  s += digit2TextAndSoundHr(i);

  return s;
}
String spkHr(int i)
{
  String s = "";
  if (i > 99)
  {
    s += speak100Hr(i);
    i = i % 100;
  }

  if (i > 19)
  {
    s += speak10Hr(i);
    i = i % 10;
  }
  if (i > 10)
  {
    s += speakNaestHr(i);
    return s;
  }
  if (i > 0) //  Jeli potrebno? Naravno da ne, ali izgleda ljepse!
  {
    s += speak1Hr(i);
  }
  return s;
}

String digit2TextAndSoundHr(int i)
{
  String s = "";
  if (i < 0)
    i = i * -1;
  if (i > 999999999)
  {
    s += speak1GHr(i);
    i = i % 1000000000;
  }
  if (i > 999999)
  {
    s += speak1MHr(i);
    i = i % 1000000;
  }
  if (i > 999)
  {
    s += speakKHr(i);
    i = i % 1000;
  }
  s += spkHr(i);
  return s;
}