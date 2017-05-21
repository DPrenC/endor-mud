/****************************************************************************
Fichero: carta_tramposo.c
Autor: Kastwey
Fecha: 02/04/2006
Descripci�n: Una carta para los que consigan la carta de Gardil de forma il�cita
****************************************************************************/


inherit THING;

private static string pOwner;

public string SetOwner(string own) { return pOwner = own; }
public string QueryOwner() { return pOwner; }

private string contenido()
{
    object pl;
    if (!(pl = TP)) return 0;
    if (QueryOwner() != NREAL(pl)) return "La carta est� en blanco.\n";
    return "Estimado Kionix. Soy " + CAP(TNAME) + ", la persona que le acaba de "
           "entregar esta carta. S�lo era para decirle, que me han comentado que "
           "como sham�n es un fraude total, y que como hechicero ni hablemos, "
           "as� que ven�a a comprobar esto, y tambi�n a observar si realmente es "
           "tan feo como la gente dice por ah�. Le entrego esta carta, con "
           "la esperanza de que no sea usted un cobarde sin orguyo como me han comentado, "
           "y me vaya a dejar salir de su m�sero local como si nada.\n\n"
           "Atentamente, " + pl->QueryPresay() + pl->QueryName() +
           " " + pl->QueryTitle() + "\n\n";
}


create()
{
    ::create();
    SetShort("una carta");
    SetLong("Es un papel doblado por la mitad. Quiz�s podr�as leerlo.\n");
    SetReadMsg(SF(contenido));
    SetIds(({"carta", "papel"}));
    SetValue(0);
    SetWeight(30);
}