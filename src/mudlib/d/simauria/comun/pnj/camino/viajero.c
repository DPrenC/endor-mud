/****************************************************************************
Fichero: viajero.c
Autor: Ratwor
Fecha: 16/09/2007
Descripci�n: Un viajero que se mueve por Simauria.
****************************************************************************/
#include "./path.h"
#include <properties.h>
inherit NPC;
create()
{
    ::create();
    SetStandard("un viajero", "humano", 11+d4(), GENDER_MALE);
    SetShort("un viajero");
    switch(d3()){
        case 1:
            SetLong("Se trata de un anciano humano de aspecto cansado vestido "
            "con ropas desgastadas por el tiempo y la dureza de una vida de vagabundeos."
            " Su aspecto desali�ado, la barba gris y mal recortada, el macilento rostro "
            "surcado de arrugas y la mirada cansina hacen pensar que sus d�as de "
            "errar por las tierras de Simauria est�n tocando a su fin.\n");
        AddId(({"viejo", "anciano"}));
            break;
        case 2:
            SetLong("Es un humano de mediana edad.  Por sus ropas de un lujo modesto "
            "podr�a tratarse de un mercader o comerciante que viaja en pos de alg�n "
            "negocio que le d� provecho, o un ciudadano que quiz�s se propone visitar "
            "a alg�n pariente.\n");
            break;
        case 3:
            SetLong("Es un j�ven humano vestido con ropas modestas.\n Forma parte de las "
            "gentes que recorren los caminos, huyendo de conflictos lejanos en busca "
            "de un lugar donde establecerse o que simplemente viajan sin rumbo fijo.\n");
            AddId("joven");
            break;
    }
    AddId(({"viajero", "viajante", "hombre", "humano"}));
    SetWhimpy(10);
    InitChats(5, ({"El viajero otea el horizonte.\n",
        "El viajero se ajusta la capa.\n",
        "El viajero se reacomoda el petate.\n",
        "El viajero dice: me duelen los pies, creo que me detendr� un rato a descansar.\n"}));
    InitAChats(10, ({"El viajero grita: �Ayuda! �Socorrooo!\n",
        "El viajero se cubre la cabeza con los brazos tratando de protegerse.\n",
        "El viajero grita: �Ayuda, me quieren asesinar!\n"}));
    AddItem("/obj/armas/baston", REFRESH_DESTRUCT,SF(wieldme),
    ([P_NUMBER_HANDS:1]));
    AddItem(PROT("capucha"), REFRESH_REMOVE, SF(wearme));
    SetGoChance(80);
    AddWalkZones(({CAMINOS, MARH("nandor/c")}));

    if (d4()==1)
        AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["oro":random(7),"plata":d6()])]));
    if(d4()==1)
        AddItem(GOBJETO("comida/queso"), REFRESH_REMOVE);
    if(d4()==1)
        AddItem(GOBJETO("comida/mendrugo"), REFRESH_REMOVE);
}
