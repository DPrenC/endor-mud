/****************************************************************************
Fichero: _con.c
Autor: kastwey@simauria
Descripci�n: Devuelve la constituci�n del player.
Creaci�n: 19/11/2004
****************************************************************************/

#define MSG_SPEAK "all_speak:"

int car()
{
  write ((TP->QueryTiflo() ? MSG_SPEAK : "") + TP->QueryCha() + "\n");
  return 1;
}
