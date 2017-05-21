/***
Fichero: bosque_base_siempreunidos.c
Autor: kastwey@simauria
Descripción: habitación base para el bosque del Siempreunidos.
Creación: 09/12/2004
16/12/2004
Retomo esta parte...
Me pongo a ponerle pijaditas dependiendo de la estación,
del momento del día, de la raza que seas...
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
            SetIntLong(W("Estás en el bosque del norte  de Siempreunidos. Sientes la tranquilidad del lugar, tan característica de las zonas élficas. Por doquier ves toda una gama de plantas, que a tus ojos, parecen encantadas.\n"
            "Ves gigantescos árboles que siembran el lugar. Por su altura y grosor, dirías que llevan ahí desde el principio de los tiempos.\n"));
            break;
        case 1:
            SetIntLong(W("Te encuentras en un bosque, al norte de Siempreunidos.\n"
            "La tranquilidad que se respira es increible. Los elementos de la naturaleza parecen convinarse aquí en perfecta armonía, otorgando a este lugar una calma casi sobrenatural.\n"));
            break;
        case 2:
            SetIntLong(W("Te encuentras caminando por el bosque del norte de Siempreunidos.\n"
            "Grandes árboles, hermosas plantas, aire fresco... hacen que en este bosque sientas una calma y una paz absoluta.\n"));
            break;
        case 3:
            SetIntLong(W("Te encuentras en el pequeño bosque del norte de Siempreunidos.\n"
            "Por doquier puedes ver árboles enormes, como si llevasen aquí desde el principio de los tiempos. Multitud de plantas tapizan el suelo, haciéndote a veces difícil incluso caminar.\n"));
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
        case 2: // un tejón
            AddItem(PNJ_BOSQUE_PUESTO("tejon"),REFRESH_HOME,1);
            break;
        case 3: // una comadreja
            AddItem(PNJ_BOSQUE_PUESTO("comadreja"),REFRESH_HOME,1);
            break;
        default: // nada
            break;
    }
    AddDetail(({"plantas","hierbas","flora","arboles","árboles"}),SF(mirar_plantas));
    AddDetail("suelo",SF(mirar_suelo));
    SetIntSmell("Huele a aire puro y fresco.\n");
    SetIntNoise("Escuchas el susurro de las hojas de los árboles movidas por la brisa.\n");
    SetLocate("Bosque de Siempreunidos");
    SetOutdoors(1);
}


string mirar_plantas()
{
    switch(NIGHTDAY->QueryState())
    {
        case ND_NIGHT..ND_PREDAWN:
        // es denoche o cercano al amanecer.
            return "A la luz de las estrellas, observas multitud de plantas que pueblan todo a tu alrededor, al igual que inmensos árboles que se te antojan gigantones solitarios e inmóviles, como centinelas de este bosque milenario.\n";
            break;
        case ND_DAWN: // está amaneciendo
            return "A la luz del amanecer, observas la diversidad de plantas que pueblan este hermoso bosque.\nLos árboles, imponentes por su altura y grosor, parecen centinelas que te observasen constántemente.\n";
            break;
        case ND_SUNRISE..ND_FALL: // durante el día
            // dependiendo de la estación que sea:
            switch (CHRONOS->QueryEstacion())
            {
                case 1: // invierno o algo parecido
                    return "A tu alrededor puedes ver gran cantidad de plantas diversas. Los árboles, desnudos a causa de la estación, parecen observarte como centinelas milenarios de este bosque.\n";
                    break;
                case 2: // primavera?
                    return W("A tu alrededor puedes ver multitud de plantas que no eres capaz de identificar. Los árboles, recubiertos de un espeso follaje, parecen observarte mientras escuchas el susurro de sus hojas movidas por la brisa.\n"
                    "Casi parece como si estuviesen hablando entre sí en un secreto lenguaje.\n");
                    break;
                case 3: // estación calurosa... verano? :)
                    return "A tu alrededor puedes ver gran diversidad de plantas, algunas algo marchitas por la falta de humedad de la estación. Los grandes árboles del bosque, parecen contemplarte como centinelas protejiendo su territorio.\n";
                    break;
                case 4: // otoño, o sucedáneo de otoño.
                    return W("A tu alrededor ves gran variedad de plantas que no eres capaz de identificar.\n"
                    "Los árboles, que comienzan a perder gran cantidad de hojas a causa de la llegada del frío, parecen vijilarte desde su absoluta inmovilidad.\n"
                    "El susurro de las hojas movidas por la brisa, te hace imaginar que los árboles hablan entre sí en su secreto lenguaje.\n");
                    break;
            }
        case ND_PRENIGHT: // casi denoche
            return W("A la luz cada vez más menguante del día, observas la gran diversidad de plantas que pueblan el lugar.\n"
            "A tu alrededor, ves grandes árboles, que en la luz cambiante de la puesta de sol, asemejan formas extrañas.\n");
            break;
    }
    return "";
}
string mirar_suelo()
{
    switch (CHRONOS->QueryEstacion())
    {
        case 1: // invierno
            return "El suelo aparece recubierto de una gruesa capa de nieve y de hojas secas. Mejor tener cuidado, no sea que te resbales al andar por aquí.\n";
            break;
        case 2: // primavera
            return "El suelo está recubierto de todo tipo de plantas que no eres capaz de identificar. Aquí y allá, ves algunos charcos, productos del deshielo de las nieves de la estación anterior.\n";
            break;
        case 3: // verano
            return "El suelo está recubierto de hojas secas y plantas de todo tipo.\n";
            break;
        case 4: // otoño
            return "El suelo está cubierto de gran número de hojas, además de la gran cantidad de plantas que ves por doquier. Una fina capa de escarcha cubre gran parte de ellas, anunciando la llegada de tiempos aún más fríos.\n";
            break;
    }
    return "";
}


string escuchar_bosque()
{
    if (NIGHTDAY->QueryState() == ND_NIGHT || NIGHTDAY->QueryState() == ND_PRENIGHT)  return "Escuchas el canto de los grillos y el grito de algún que otro animal que no sabes identificar.";
    else  return "Escuchas el trino de los pájaros.\n";
}
