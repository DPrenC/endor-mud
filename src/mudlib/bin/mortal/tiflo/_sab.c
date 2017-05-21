/****************************************************************************
Fichero: _sab.c
Autor: Kastwey@simauria
Descripción: Devuelve la sabiduría del jugador
Creación: 23/01/2006
****************************************************************************/

#define MSG_SPEAK "all_speak:"

public int main()
{
    write((TP->QueryTiflo() ? MSG_SPEAK : "") + TP->QueryWis() + "\n");
    return 1;
}
