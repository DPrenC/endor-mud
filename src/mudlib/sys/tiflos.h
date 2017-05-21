/***
fichero: tiflos.h
autor: kastwey@simauria
Descripción: Defines y otras cosillas para el manejo de los nuevos bins.
***/


#define AO (TP->QueryGender() == 2?"a":"o")
#define MSG_SPEAK "all_speak:"

int responder(string str)
// hace un write con wrapeado y comprobando si el player es o no un tiflo :)
{
  if (TP->QueryTiflo())
    write(W(MSG_SPEAK + str));
  else
    write (W(str));
  return 1;
}
