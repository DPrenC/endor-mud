/****************************************************************************
Fichero: /d/simauria/comun/pnj/camino/aveboske.c
Autor: Yalin
Fecha: 22/12/2008 14:53
Descripci�n: Pajarillos aleatorios para los caminos.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
inherit NPC;

void SetDesc()
{
    switch (d10())
    {
        case 1:
            SetName("el canario");
            SetShort("un canario");
            SetLong("Es un lindo canario amarillo que revolotea distra�damente entre los �rboles.\n");
            AddId(({"canario"}));
        break;
        case 2:
            SetName("el mart�n pescador");
            SetShort("un mart�n pescador");
            SetLong("Es un p�jaro de largo pico adaptado a coger peces de las aguas. Est� posado en una rama, "
                "probablemente descansando entre comida y comida antes de volver al agua a buscar otro pez.\n");
            AddId(({"martin","mart�n","martin pescador","mart�n pescador","pescador"}));
        break;
        case 3:
            SetName("el ruise�or");
            SetShort("un ruise�or");
            SetLong("Un t�pico ruise�or de los bosques, que merodea sin prop�sito por el arbolado.\n");
            AddId(({"ruise�or","ruisenyor"}));
        break;
        case 4:
            SetName("el jilguero");
            SetShort("un jilguero");
            SetLong("Se trata de un peque�o jilguero que deambula ociosamente de �rbol en �rbol.\n");
            AddId(({"jilguero"}));
        break;
        case 5:
            SetName("el periquito");
            SetShort("un periquito");
            SetLong("Es un ave prensora, m�s o menos como un loro muy peque�o. Se agarra fuertemente a una rama con sus "
                "fuertes u�as.\n");
            AddId(({"periquito"}));
        break;
        case 6:
            SetName("el gorri�n");
            SetShort("un gorri�n");
            SetLong("Un gorri�n com�n, de los que se encuentran en cualquier ciudad. Es raro verle por estos lugares, pero "
                "aqu� est�.\n");
            AddId(({"gorrion","gorri�n"}));
        break;
        case 7:
            SetName("el p�jaro carpintero");
            SetShort("un p�jaro carpintero");
            SetLong("Es un p�jaro de pico afilado, que excava agujeros en la madera. Debe andar por aqu� buscando un �rbol "
                "para hacer su nido.\n");
            AddId(({"carpintero"}));
        break;
        case 8:
            SetName("el tordo");
            SetShort("un tordo");
            SetLong("Un tordo que debe tener su nido en estos                                     �rboles. Probablemente "
                "se alimente en los campos de cultivo de alguna aldea.\n");
            AddId(({"tordo"}));
        break;
        case 9:
            SetName("el colibr�");
            SetShort("un colibr�");
            SetLong("Es un p�jaro algo mayor que un escarabajo. Anda por aqu�, chupando la savia de los �rboles, o el "
                "n�ctar de alguna flor.\n");
            AddId(({"colibri","colibr�"}));
        break;
        case 10:
            SetName("el p�jaro");
            SetShort("un p�jaro");
            SetLong("Es un p�jaro del bosque, cuya especie no sabes identificar.\n");
        break;
    }
    return;
}

string otro()
{
    string chat;
    if (QueryName()=="el p�jaro carpintero") chat=" picotea r�pidamente la madera.\n";
    else if (QueryName()=="el mart�n pescador") chat=" se limpia el pico en la corteza del �rbol.\n";
    else chat=" lanza unos trinos al aire.\n";
    return CAP(QueryName())+chat;
}
                        
create()
{
    ::create();
    SetStandard("un p�jaro","ave",d2(),GENERO_MASCULINO);
    SetIds(({"pajaro","p�jaro"}));
    SetDesc();
    SetHands(({({"pico",1,1+QueryLevel()})}));
    InitChats(5,({
        CAP(QueryName())+" vuela a una rama m�s alta.\n",
        CAP(QueryName())+" te mira indiferente.\n",
        CAP(QueryName())+" hace unas acrobacias en el aire.\n",
        CAP(QueryName())+" revolotea entre las ramas.\n",
        SF(otro)}));
    InitAChats(5,({CAP(QueryName())+" intenta picarte los ojos.\n",
        CAP(QueryName())+" te ara�a la cara.\n"}));
}
    