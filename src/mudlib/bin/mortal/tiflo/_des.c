/****************************************************************************
Fichero: _des.c
Autor: Kastwey@simauria
Descripci�n: Devuelve la destreza dle player.
Creaci�n: 19/11/2004
****************************************************************************/

#define MSG_SPEAK "all_speak:"

public int main()
{
    write((TP->QueryTiflo() ? MSG_SPEAK : "") + TP->QueryDex(1) + "\n");;
  return 1;
}
