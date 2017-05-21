/*

Nombre      : AmuletoContenedorVital
Zona        : Poblado de Enalel
Autor       : Tyflos
Fecha       : 14/01/2005
Descripci�n : Amuleto que almacena y devuelve puntos de vida.
Almacenar� vida de todos los personajes.
Devolver� vida a todos los personajes.
Podr� almacenar un m�ximo de 500 PV.
S�lo funcionar� con su due�o.

*/
#include "path.h"
#include <properties.h>
#include <combat.h>

inherit ARMOUR;

// Gesti�n de propiedades m�gicas
string Propietario; // Nombre del jugador
string Temperatura; // Para el Long
int HP; // Vida almacenada
string SetNewLong();
string QueryPropietario ();
int SetPropietario (string nombre);
int QueryHP();
int SetHP (int PHP);
int CmdCargar(string str);
int CmdDescargar(string str);

init ()
{
    add_action("CmdCargar","cargar");
    add_action("CmdDescargar","descargar");
} // Init

create()
{
    ::create();
    SetStandard(AT_AMULETO, 0, P_SIZE_GENERIC, M_NINGUNO);
    SetShort("un amuleto de vida");
    SetAds(({"un","magico","m�gico","de vida"}));
    AddId(({"armadura","amuleto","amuleto de vida"}));
    // Iniciamos los valores
    Temperatura = "frio";
    HP = 0;
    Propietario = "";
    SetLong(
        "Es un curioso amuleto con forma de manzana. "
        "Tiene un extra�o nombre grabado en el centro. "
        "Al tocarlo, parece estar congelado.\n"
        );
    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetWeight(300);
} // Create

string SetNewLong()
{
    if (QueryHP()<=10) Temperatura = "muy frio";
    else if (QueryHP()<=100) Temperatura = "frio";
    else if (QueryHP()<=200) Temperatura = "templado";
    else if (QueryHP()<=300) Temperatura = "caliente";
    else if (QueryHP()<=400) Temperatura = "muy caliente";
    else if (QueryHP()>400) Temperatura = "palpitando por el calor";
    SetLong(
        "Es un curioso amuleto con forma de manzana. "
        "Tiene el nombre de " + CAP(Propietario) + " grabado en el centro. "
        "Al tocarlo, parece estar " + Temperatura + ".\n"
        );
    return QueryLong();

} // SetNewLong

string QueryPropietario ()
{
    return Propietario;
} // QueryPropietario

int SetPropietario (string nombre)
{
    Propietario = nombre;
    SetNewLong();
    return 1;
} // SetPropietario

int QueryHP()
{
    return HP;
} // QueryHP

int SetHP (int PHP)
{
    if (PHP >500)
    {
        HP = 500;
        SetNewLong();
        return (PHP - 500);
    }
    HP = PHP;
    SetNewLong();
    return 0;
} // SetHP

int CmdCargar(string str)
{
    if (!str)
    {
        return notify_fail("�Qu� quieres cargar?\n", NOTIFY_NOT_VALID);
    }
    if (str=="amuleto" || str == "amuleto magico" || str == "amuleto m�gico" || str == "amuleto de vida")
    {
        write("Colocas tus manos en el amuleto y te concentras.\n");
        say(capitalize(TP->QueryRealName()) +" coloca sus manos sobre un amuleto y se concentra.\n",TP);
        // Comprobamos que sea el due�o del amuleto
        if (TP->QueryRealName() == QueryPropietario() )
        {
            // Comprobamos que le queda vida suficiente para cargarlo
            if (TP->QueryHP() > 10)
            {
                int AAlmacenar = TP->QueryHP() - 10;
                AAlmacenar = AAlmacenar > 500 ? 500 : AAlmacenar;
                if (QueryHP() == 500)
                {
                    return notify_fail("El amuleto comienza a vibrar y a desprender chispas azules. Parece que ya est� al l�mite de su capacidad.\n", NOTIFY_NOT_VALID);
                }
                write("Sientes como tus fuerzas te avandonan para pasar al amuleto.\n");
                TP->DoDamage(AAlmacenar + QueryHP() > 500 ? 500 - QueryHP() : AAlmacenar);
                if (AAlmacenar + QueryHP() > 500)
                {
                    write("El amuleto comienza a desprender chispas azules.\nParece que no puede almacenar m�s energ�a.\n");
                    say("El amuleto sostenido por " + capitalize(TP->QueryRealName() ) + " comienza a desprender chispas azules.\n",TP);
                }
                SetHP(QueryHP() + AAlmacenar);

            }
            else
            {
                write("No te quedan fuerzas para seguir cargando el amuleto.\n");
                say(capitalize(TP->QueryRealName() ) + " parece muy cansado.\n",TP);
            }
        }
        else
        {
            write("No sucede nada. Piensas que este amuleto s�lo puede ser usado por su leg�timo due�o.\n");
        }
        return 1;
    }
    else
    {
        return 0;
    }
} // CmdCargar

int CmdDescargar(string str)
{
    int HPD; // Variable para calcular los puntos de da�o o recuperaci�n
    if (!str)
    {
        return notify_fail("�Qu� quieres descargar?\n", NOTIFY_NOT_VALID);
    }
    if (str=="amuleto" || str=="amuleto magico" || str=="amuleto m�gico" || str=="amuleto de vida")
    {
        write("Te colocas el amuleto cerca de tu pecho.\n");
        say(capitalize(TP->QueryRealName() ) +" se coloca un amuleto cerca de su pecho.\n",TP);
        // Comprueba que sea el propietario
        if (TP->QueryRealName() == QueryPropietario() )
        {
            if (TP->QueryHP() >= TP->QueryMaxHP()) return notify_fail("No necesitas descargar el amuleto. Est�s en perfecto estado.\n", NOTIFY_NOT_VALID);
            HPD = (TP->QueryMaxHP() - TP->QueryHP() ); // Calculamos cuantos puntos puede almacenar el player
            if (QueryHP() < HPD) // Y si no tenemos suficiente, cambiamos los puntos a recuperar
                HPD = QueryHP(); // Si no, le damos lo que tengamos
            SetHP(QueryHP() - HPD); // Sacamos la energ�a del amuleto
            write("Sientes como aumentan tus fuerzas.\n");
            TP->SetHP( TP->QueryHP() + HPD);
        }
        else
        {
            write("Del amuleto salen rayos rojizos que te abrasan.\n");
            say("Del amuleto salen rayos rojizos y queman a " + capitalize(TP->QueryRealName() ) + ".\n",TP);
            HPD = random(QueryHP()); // Calculamos los puntos de da�o seg�n la energ�a almacenada
            SetHP(QueryHP() - HPD); // Quitamos los puntos del da�o
            TP->DoDamage(HPD+ 5); // Y da�amos al jugador
        }
        return 1;
    }
    else
        return 0;
} // CmdDescargar
