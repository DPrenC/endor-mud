/****************************************************************************
Fichero: hab.c
Autor: Kastwey@simauria
Descripción: Devuelve el nivel de una determinada habilidad.
Creación: 23/01/2006
****************************************************************************/

#define MSG_SPEAK "all_speak:"
#define TIFLO(x) (TP->QueryTiflo() ? MSG_SPEAK : "") + x

public int main(string str)
{
    mapping habs;
    if (!str)
    {
        return notify_fail(TIFLO("Sintaxis: hab <habilidad>, donde "
                                 "<hab> es una de las habilidades que tienes memorizadas.\n"));
    }
    habs = TP->QuerySkills();
    if (!member(habs,str))
    {
        return notify_fail(TIFLO("No conoces la habilidad " + str + ".\n"));
    }
    write(TIFLO(CAP(str) + ": " + habs[str] + " / " + habs[str, 1] + "\n"));
    return 1;
}


