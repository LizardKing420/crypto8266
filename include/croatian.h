#include "header.h"

#define _dvije    11
#define _naest    12
#define _cetr     13
#define _hundert  16
#define _tausend  18
#define _milion   21
#define _miliarde 23
#define _minus    26
#define _plus     27
#define _komma    28
#define _punkt    29

String as_numHr[] = { "nula", "jedan", "dva", "tri", "cetri", "pet", "sest", "sedam", "osam", "devet", "deset", "dvije", "naest", "cetr",
                      "pedeset", "sezdeset", "sto", "dvjesto", "tisucu", "tisuce", "tisuca","milijun","milijuna","milijardi","milijarde",
                      "milijardi", "minus", "plus" "zarez", "tocka",
                    };

String digit2TextAndSoundHr(int i);
String spkHr(int i);
String playHr(int i)
{
  //  mp3.play(i); // die Kroatische Version der Methode play
  return as_numHr[i];
}
String speak1GHr(int i)
{
  int z = i/1000000000;
  if (z%10>4)
  {
    return spkHr(z) + " " + playHr(_miliarde+2) + " ";
  }
  if (z%10>1)
  {
    return spkHr(z) + " " + playHr(_miliarde+1) + " ";
  }
  return spkHr(z) + " " + playHr(_miliarde) + " "; 
}
String speak1MHr(int i)
{
  int z = i/1000000;
  if (z%10 > 1)
  {
    return spkHr(z) + " " + playHr(_milion+1) + " ";
  }
  return spkHr(z) + " " + playHr(_milion) + " ";
}

String speakKHr(int i)
{
    String ret ="";
    int z = i/1000;
    if (z%10 > 4 || (z%10==1 && z>1))
  {
    return  spkHr(z) + playHr(_tausend + 2) + " ";
  }
  
  else if (z%10 > 2) 
  {
    return  spkHr(z) + playHr(_tausend + 1) + " ";
  }
  else if (z%10 > 1) 
  {
    return spkHr(_dvije) + playHr(_tausend + 1) + " ";
  }
  else if (i > 999) {
    return playHr(_tausend) + " ";
    
  }
  return ret;  
}
String speak100Hr(int i)
{
  if(i>299) return playHr(i / 100) + playHr(_hundert) + " ";
  if(i>199) return playHr(_dvije) + playHr(_hundert) + " ";
  return playHr(_hundert) + " ";
}


String speak10Hr(int i)
{
  int zehner = i/10;
  if (zehner == 4)
  {
    return playHr(_cetr)  + playHr(10) + " ";
  }
  return playHr(zehner) + playHr(10) + " ";
}

String speakNaestHr(int i)
{
  int einzer = i-10;
  if (einzer==4)
  {
    return  playHr(_cetr) + playHr(_naest);
    
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
  if (i < 0) {
    s += playHr(_minus) + " ";
    i = -i;
  }
  s += digit2TextAndSoundHr(i);

  return s;
}
String spkHr(int i)
{
  String s = "";
  if (i>99)
  {
    s += speak100Hr(i);
    i = i%100;
  }

  if (i>19)
  {
    s += speak10Hr(i);
    i = i%10;
  }
  if (i>10)
  {
    s += speakNaestHr(i);
    return s;
  }
  if (i>0)    //  Jeli potrebno? Naravno da ne, ali izgleda ljepse!
  {
    s += speak1Hr(i);
  }
 return s;
}

String digit2TextAndSoundHr(int i)
{
  String s = "";
  if(i<0) i = i*-1;
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
  if (i >999)
  {
    s += speakKHr(i);
    i = i%1000;
  }
  s += spkHr(i);
  return s;
}