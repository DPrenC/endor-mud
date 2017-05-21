/****************************************************************************
Fichero: sirvientes_castillo.c
Autor: Ratwor
Fecha: 02/10/2006
Descripción: los sirvientes del castillo de nandor.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <combat.h>
inherit NPC;

create()
{
    ::create();
    switch(d2())
    {
        case 1:
            SetStandard("una sirvienta", "humano", ([GC_TORPE:12]), GENDER_FEMALE);
            AddId(({"sirvienta", "criada", "humana", "mujer"}));
            SetShort("una sirvienta");
            switch(d3())
            {
                case 1:
                    SetLong("Es una de las sirvientas del castillo, ciertamente es muy "
                    "recatada y tiene pinta más de noble que de sirvienta.\n El orden "
                    "y la rapidez siempre es su prioridad.\n");
                    break;
                case 2:
                    SetLong("Se dice de esta sirvienta de todo y nada bueno, le gusta "
                    "tener un generoso escote y, curiosamente, su túnica de sirvienta "
                    "es más corta que las del resto.\n Más de una vez se le ha "
                    "sorprendido por los rincones del castillo, en situación "
                    "comprometedora, acompañada de distintos guardias.\n");
                    break;
                case 3:
                    SetLong("Cuando alguien en el castillo menciona a la tonta, es a esta "
                    "sirvienta a la que se menta, y ciertamente es poco agraciada en lo que a "
                    "inteligencia se refiere.\n Es costumbre entre los guardias reírse de ella "
                    "con bromas inocentes, y no parece enojarse por ello. Pero lo que tiene de "
                    "tonta también lo tiene de buen corazón.\n ");
                    break;
            }
            break;
        case 2:
            SetStandard("un sirviente", "humano", ([GC_TORPE:13]), GENDER_MALE);
            AddId(({"sirviente", "criado", "hombre"}));
            SetShort("un sirviente ");
            switch(d3())
            {
                case 1:
                    SetLong("Es uno de los sirvientes del castillo, éste no debe ser muy "
                    "límpio, pues su higiene personal deja mucho que desear.\n");
                    break;
                case 2:
                    SetLong("Es el sirviente del castillo más afeminado, tiende "
                    "a estar siempre en compañía de las sirvientas y, tanto sus "
                    "andares como sus gestos no son nada varoniles.\n");
                    break;
                case 3:
                    SetLong("Es un sirviente un tanto extraño, no suele hablar mucho "
                    "con nadie, hace sus labores en total silencio y rara vez se le "
                    "ha visto sonreir.\n");
                    break;
            }
            break;
    }

    SetCitizenship("nandor");
    InitAChats(5, ({QueryShort()+" grita pidiendo auxilio.\n",
        QueryShort()+" grita: ¡déjame en paz!.\n"}));
    InitChats(4, ({QueryShort()+" limpia un poco el polvo.\n",
        QueryShort()+" mira a su alrededor inspeccionándolo todo.\n",
        QueryShort()+" te mira interrogante.\n"}));
    SetShrugMsg(QueryShort()+" dice: aquí no se permite la entrada nada más que al "
        "personal del castillo.\n");
    SetGoChance(40);
AddWalkZones(({CASTILLO("planta1"), CASTILLO("planta2")}));

    AddItem("/std/armour",REFRESH_REMOVE,SF(wearme),
    ([P_SHORT: "una túnica de lana",
    P_LONG: "Es una sencilla túnica de lana basta de color marrón. Es la vestimenta "
      "habitual de campesinos y siervos por su funcionalidad y bajo coste.\n",
   P_ARMOUR_TYPE:AT_ARMOUR,
    P_IDS: ({"túnica de lana", "túnica"}),
    P_AC: 1, P_SIZE:P_SIZE_MEDIUM,
    P_WEIGHT: 750,
    P_VALUE: 100]) );

}

