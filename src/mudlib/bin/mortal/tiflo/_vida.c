/****************************************************************************
Fichero: _vida.c
Autor: orome@endor-mud
Descripción: Devuelve los puntos de vida del jugador (HP antiguo comando pv.)
****************************************************************************/

//#define MSG_SPEAK "all_speak:"

public int main()
{
      write("\n\t"+(!TP->QueryTiflo() ? "Puntos de Vida: " : "Vida: ") + TP->QueryHP() + " de " + TP->QueryMaxHP() + "\n");
    return 1;
}
