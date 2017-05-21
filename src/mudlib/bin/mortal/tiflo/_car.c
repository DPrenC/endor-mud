/****************************************************************************
Fichero: _con.c
Autor: kastwey@simauria
Descripción: Devuelve la constitución del player.
Creación: 19/11/2004
****************************************************************************/

#define MSG_SPEAK "all_speak:"

int car()
{
  write ((TP->QueryTiflo() ? MSG_SPEAK : "") + TP->QueryCha() + "\n");
  return 1;
}
