/****************************************************************************
Fichero: _conj.c
Autor: kastwey@simauria
Descripción: Comando que pasándole un conjuro como parámetro, devuelve
el nivel de aprendizaje de dicho conjuro, y si lo puede usar o no en el
gremio actual.
Creación: 22/01/2006
****************************************************************************/

#include <magia.h>

#define MSG_SPEAK "all_speak:"
#define TIFLO(x, i)  (x->QueryTiflo() ? MSG_SPEAK : "") + i


public int main(string conjuro)
{
    object pl = TP;
    string fichero;
    mapping spells;

    if (!conjuro)
    {
        return notify_fail(TIFLO(pl, "Sintaxis: conj <conjuro>, donde <conjuro> "
                                     "es el nombre de uno de los conjuros que "
                                     "tengas memorizados.\n"));
    }
    if (!member(spells = pl->QuerySpells(),conjuro))
    {
        return notify_fail(TIFLO(pl, "No conoces ningún conjuro con ese "
                                     "nombre.\n"));
    }

    fichero = SPELL(conjuro);
    if (!fichero)
    {
        return notify_fail(TIFLO(pl, "Aunque tienes este conjuro memorizado, "
                                     "parece que ahora mismo no puedes realizarlo.\n"));
    }
    seteuid(getuid());
    if (fichero->QueryCastLevel(pl->QueryGuild()) == NO_PUEDE)
    {
        write(TIFLO(pl, conjuro + ": " + spells[conjuro] + " / " +
                        spells[conjuro, 1] + ". Sin embargo, Actualmente no "
                        "puedes hacer este tipo de magia.\n"));
        return 1;
    }
    write(TIFLO(pl, conjuro + ": " + spells[conjuro] + " / " +
                    spells[conjuro, 1] + "\n"));
    return 1;
}