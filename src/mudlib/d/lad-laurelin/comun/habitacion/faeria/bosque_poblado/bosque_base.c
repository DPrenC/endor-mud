/***
Fichero: bosque_base_siempreunidos.c
Autor: kastwey@simauria
Descripci�n: habitaci�n base para el bosque del Siempreunidos.
Creaci�n: 09/12/2004
16/12/2004
Retomo esta parte...
Me pongo a ponerle pijaditas dependiendo de la estaci�n,
del momento del d�a, de la raza que seas...
17/12/2004
y sigo........
***/

#include "path.h"
#include <nightday.h>


inherit STD_FAERIA("hab_siempreunidos");

string mirar_plantas();
string mirar_suelo();
string escuchar_bosque();

create()
{
    ::create();
    SetIntShort("el bosque de Siempreunidos");
    switch(random(4))
    {
        case 0:
            SetIntLong(W("Est�s en el bosque del norte  de Siempreunidos. Sientes la tranquilidad del lugar, tan caracter�stica de las zonas �lficas. Por doquier ves toda una gama de plantas, que a tus ojos, parecen encantadas.\n"
            "Ves gigantescos �rboles que siembran el lugar. Por su altura y grosor, dir�as que llevan ah� desde el principio de los tiempos.\n"));
            break;
        case 1:
            SetIntLong(W("Te encuentras en un bosque, al norte de Siempreunidos.\n"
            "La tranquilidad que se respira es increible. Los elementos de la naturaleza parecen convinarse aqu� en perfecta armon�a, otorgando a este lugar una calma casi sobrenatural.\n"));
            break;
        case 2:
            SetIntLong(W("Te encuentras caminando por el bosque del norte de Siempreunidos.\n"
            "Grandes �rboles, hermosas plantas, aire fresco... hacen que en este bosque sientas una calma y una paz absoluta.\n"));
            break;
        case 3:
            SetIntLong(W("Te encuentras en el peque�o bosque del norte de Siempreunidos.\n"
            "Por doquier puedes ver �rboles enormes, como si llevasen aqu� desde el principio de los tiempos. Multitud de plantas tapizan el suelo, haci�ndote a veces dif�cil incluso caminar.\n"));
            break;
    }
    switch(random(4))
    {
        case 0: // una ardilla
            AddItem(PNJ_BOSQUE_PUESTO("ardilla"),REFRESH_HOME,1);
            break;
        case 1: // una mofeta
            AddItem(PNJ_BOSQUE_PUESTO("mofeta"),REFRESH_HOME,1);
            break;
        case 2: // un tej�n
            AddItem(PNJ_BOSQUE_PUESTO("tejon"),REFRESH_HOME,1);
            break;
        case 3: // una comadreja
            AddItem(PNJ_BOSQUE_PUESTO("comadreja"),REFRESH_HOME,1);
            break;
        default: // nada
            break;
    }
    AddDetail(({"plantas","hierbas","flora","arboles","�rboles"}),SF(mirar_plantas));
    AddDetail("suelo",SF(mirar_suelo));
    SetIntSmell("Huele a aire puro y fresco.\n");
    SetIntNoise("Escuchas el susurro de las hojas de los �rboles movidas por la brisa.\n");
    SetLocate("Bosque de Siempreunidos");
    SetOutdoors(1);
}


string mirar_plantas()
{
    switch(NIGHTDAY->QueryState())
    {
        case ND_NIGHT..ND_PREDAWN:
        // es denoche o cercano al amanecer.
            return "A la luz de las estrellas, observas multitud de plantas que pueblan todo a tu alrededor, al igual que inmensos �rboles que se te antojan gigantones solitarios e inm�viles, como centinelas de este bosque milenario.\n";
            break;
        case ND_DAWN: // est� amaneciendo
            return "A la luz del amanecer, observas la diversidad de plantas que pueblan este hermoso bosque.\nLos �rboles, imponentes por su altura y grosor, parecen centinelas que te observasen const�ntemente.\n";
            break;
        case ND_SUNRISE..ND_FALL: // durante el d�a
            // dependiendo de la estaci�n que sea:
            switch (CHRONOS->QueryEstacion())
            {
                case 1: // invierno o algo parecido
                    return "A tu alrededor puedes ver gran cantidad de plantas diversas. Los �rboles, desnudos a causa de la estaci�n, parecen observarte como centinelas milenarios de este bosque.\n";
                    break;
                case 2: // primavera?
                    return W("A tu alrededor puedes ver multitud de plantas que no eres capaz de identificar. Los �rboles, recubiertos de un espeso follaje, parecen observarte mientras escuchas el susurro de sus hojas movidas por la brisa.\n"
                    "Casi parece como si estuviesen hablando entre s� en un secreto lenguaje.\n");
                    break;
                case 3: // estaci�n calurosa... verano? :)
                    return "A tu alrededor puedes ver gran diversidad de plantas, algunas algo marchitas por la falta de humedad de la estaci�n. Los grandes �rboles del bosque, parecen contemplarte como centinelas protejiendo su territorio.\n";
                    break;
                case 4: // oto�o, o suced�neo de oto�o.
                    return W("A tu alrededor ves gran variedad de plantas que no eres capaz de identificar.\n"
                    "Los �rboles, que comienzan a perder gran cantidad de hojas a causa de la llegada del fr�o, parecen vijilarte desde su absoluta inmovilidad.\n"
                    "El susurro de las hojas movidas por la brisa, te hace imaginar que los �rboles hablan entre s� en su secreto lenguaje.\n");
                    break;
            }
        case ND_PRENIGHT: // casi denoche
            return W("A la luz cada vez m�s menguante del d�a, observas la gran diversidad de plantas que pueblan el lugar.\n"
            "A tu alrededor, ves grandes �rboles, que en la luz cambiante de la puesta de sol, asemejan formas extra�as.\n");
            break;
    }
    return "";
}
string mirar_suelo()
{
    switch (CHRONOS->QueryEstacion())
    {
        case 1: // invierno
            return "El suelo aparece recubierto de una gruesa capa de nieve y de hojas secas. Mejor tener cuidado, no sea que te resbales al andar por aqu�.\n";
            break;
        case 2: // primavera
            return "El suelo est� recubierto de todo tipo de plantas que no eres capaz de identificar. Aqu� y all�, ves algunos charcos, productos del deshielo de las nieves de la estaci�n anterior.\n";
            break;
        case 3: // verano
            return "El suelo est� recubierto de hojas secas y plantas de todo tipo.\n";
            break;
        case 4: // oto�o
            return "El suelo est� cubierto de gran n�mero de hojas, adem�s de la gran cantidad de plantas que ves por doquier. Una fina capa de escarcha cubre gran parte de ellas, anunciando la llegada de tiempos a�n m�s fr�os.\n";
            break;
    }
    return "";
}


string escuchar_bosque()
{
    if (NIGHTDAY->QueryState() == ND_NIGHT || NIGHTDAY->QueryState() == ND_PRENIGHT)  return "Escuchas el canto de los grillos y el grito de alg�n que otro animal que no sabes identificar.";
    else  return "Escuchas el trino de los p�jaros.\n";
}
