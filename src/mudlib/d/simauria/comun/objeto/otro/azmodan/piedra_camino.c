/****************************************************************************
Fichero: piedra_camino.c
Autor: Kastwey
Fecha: 13/03/2006
Descripción: Una piedra para el camino de Azmodan.
****************************************************************************/


inherit THING;

private string mirar_piedra()
{
    object env;
    if (!(env = environment())) return "";
    if (env->QueryCaminoAzmodan())
    {
        return "Es una piedra enorme situada a un lado del camino. Además de "
               "parecer realmente pesada, no ves nada destacable en ella.\n";
    }
    return "Es una piedra enorme, sin nada de particular.\n";
}

    create()
{
    SetShort("una gran piedra");
    SetLong(SF(mirar_piedra));
    SetIds(({"piedra", "gran piedra", "piedra enorme", "piedra grande"}));
    SetWeight(25000);
    SetValue(0);
}



