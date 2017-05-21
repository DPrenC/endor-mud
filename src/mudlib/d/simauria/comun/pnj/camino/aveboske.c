/****************************************************************************
Fichero: /d/simauria/comun/pnj/camino/aveboske.c
Autor: Yalin
Fecha: 22/12/2008 14:53
Descripción: Pajarillos aleatorios para los caminos.
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
            SetLong("Es un lindo canario amarillo que revolotea distraídamente entre los árboles.\n");
            AddId(({"canario"}));
        break;
        case 2:
            SetName("el martín pescador");
            SetShort("un martín pescador");
            SetLong("Es un pájaro de largo pico adaptado a coger peces de las aguas. Está posado en una rama, "
                "probablemente descansando entre comida y comida antes de volver al agua a buscar otro pez.\n");
            AddId(({"martin","martín","martin pescador","martín pescador","pescador"}));
        break;
        case 3:
            SetName("el ruiseñor");
            SetShort("un ruiseñor");
            SetLong("Un típico ruiseñor de los bosques, que merodea sin propósito por el arbolado.\n");
            AddId(({"ruiseñor","ruisenyor"}));
        break;
        case 4:
            SetName("el jilguero");
            SetShort("un jilguero");
            SetLong("Se trata de un pequeño jilguero que deambula ociosamente de árbol en árbol.\n");
            AddId(({"jilguero"}));
        break;
        case 5:
            SetName("el periquito");
            SetShort("un periquito");
            SetLong("Es un ave prensora, más o menos como un loro muy pequeño. Se agarra fuertemente a una rama con sus "
                "fuertes uñas.\n");
            AddId(({"periquito"}));
        break;
        case 6:
            SetName("el gorrión");
            SetShort("un gorrión");
            SetLong("Un gorrión común, de los que se encuentran en cualquier ciudad. Es raro verle por estos lugares, pero "
                "aquí está.\n");
            AddId(({"gorrion","gorrión"}));
        break;
        case 7:
            SetName("el pájaro carpintero");
            SetShort("un pájaro carpintero");
            SetLong("Es un pájaro de pico afilado, que excava agujeros en la madera. Debe andar por aquí buscando un árbol "
                "para hacer su nido.\n");
            AddId(({"carpintero"}));
        break;
        case 8:
            SetName("el tordo");
            SetShort("un tordo");
            SetLong("Un tordo que debe tener su nido en estos                                     árboles. Probablemente "
                "se alimente en los campos de cultivo de alguna aldea.\n");
            AddId(({"tordo"}));
        break;
        case 9:
            SetName("el colibrí");
            SetShort("un colibrí");
            SetLong("Es un pájaro algo mayor que un escarabajo. Anda por aquí, chupando la savia de los árboles, o el "
                "néctar de alguna flor.\n");
            AddId(({"colibri","colibrí"}));
        break;
        case 10:
            SetName("el pájaro");
            SetShort("un pájaro");
            SetLong("Es un pájaro del bosque, cuya especie no sabes identificar.\n");
        break;
    }
    return;
}

string otro()
{
    string chat;
    if (QueryName()=="el pájaro carpintero") chat=" picotea rápidamente la madera.\n";
    else if (QueryName()=="el martín pescador") chat=" se limpia el pico en la corteza del árbol.\n";
    else chat=" lanza unos trinos al aire.\n";
    return CAP(QueryName())+chat;
}
                        
create()
{
    ::create();
    SetStandard("un pájaro","ave",d2(),GENERO_MASCULINO);
    SetIds(({"pajaro","pájaro"}));
    SetDesc();
    SetHands(({({"pico",1,1+QueryLevel()})}));
    InitChats(5,({
        CAP(QueryName())+" vuela a una rama más alta.\n",
        CAP(QueryName())+" te mira indiferente.\n",
        CAP(QueryName())+" hace unas acrobacias en el aire.\n",
        CAP(QueryName())+" revolotea entre las ramas.\n",
        SF(otro)}));
    InitAChats(5,({CAP(QueryName())+" intenta picarte los ojos.\n",
        CAP(QueryName())+" te araña la cara.\n"}));
}
    