/****************************************************************************
Fichero: carta_tramposo.c
Autor: Kastwey
Fecha: 02/04/2006
Descripción: Una carta para los que consigan la carta de Gardil de forma ilícita
****************************************************************************/


inherit THING;

private static string pOwner;

public string SetOwner(string own) { return pOwner = own; }
public string QueryOwner() { return pOwner; }

private string contenido()
{
    object pl;
    if (!(pl = TP)) return 0;
    if (QueryOwner() != NREAL(pl)) return "La carta está en blanco.\n";
    return "Estimado Kionix. Soy " + CAP(TNAME) + ", la persona que le acaba de "
           "entregar esta carta. Sólo era para decirle, que me han comentado que "
           "como shamán es un fraude total, y que como hechicero ni hablemos, "
           "así que venía a comprobar esto, y también a observar si realmente es "
           "tan feo como la gente dice por ahí. Le entrego esta carta, con "
           "la esperanza de que no sea usted un cobarde sin orguyo como me han comentado, "
           "y me vaya a dejar salir de su mísero local como si nada.\n\n"
           "Atentamente, " + pl->QueryPresay() + pl->QueryName() +
           " " + pl->QueryTitle() + "\n\n";
}


create()
{
    ::create();
    SetShort("una carta");
    SetLong("Es un papel doblado por la mitad. Quizás podrías leerlo.\n");
    SetReadMsg(SF(contenido));
    SetIds(({"carta", "papel"}));
    SetValue(0);
    SetWeight(30);
}