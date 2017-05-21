 /*
DESCRIPCION : pescador en la barca
FICHERO     : /d/akallab/comun/pnj/akallab/azzor/pescador_barca.c
MODIFICACION: 16-09-07 [Angor] Creacion
*/

#include "path.h"
#include <properties.h>
#include <guild.h>

inherit NPC;

public create()
{
    ::create();
    seteuid(getuid());

    string *nombres = ({"Haknur","Nekku","Tokker","Grokk","Nestak","Rualk","Kasllak"});
    string nombre = nombres[ random(sizeof(nombres)) ];
    string *apodos = ({""," el tuerto"," el de Gaddaro"," el pescador"," el pescador", " bocatorcida", " bocanegra"});
    string apodo = apodos[ random(sizeof(apodos)) ];
    
    SetStandard(nombre,"orco",([GC_NINGUNO:10+random(20)]),GENDER_MALE);
    SetShort(nombre + apodo);
    SetLong(nombre + " es un pescador local, ajado por el salitre y curtido por el mar.\n");

    SetIds(({nombre}));
    SetIds(({"pescador", apodo, "marino","marinero","orco"}));

    InitChats(2,({ nombre + " tararea una cancioncilla.\n",
    "El pescador repasa las redes.\n",
    nombre + " repara un agujero en una red.\n",
    "Una gaviota sobrevuela la barca en busca de comida.\n",
    "Una gaviota se posa sobre el mastil y te mira curiosa.\n",
    nombre + " tira unos restos de pescado al mar.\n",
    nombre + " lanza unos restos de pescado a una gaviota y esta los atrapa al vuelo.\n",
    "El pescador ajusta los cabos de las velas.\n",
    }));

    AddItem("/obj/armas/cuchillo",REFRESH_REMOVE,([
            P_SHORT: "un cuchillo corto",
            P_LONG:  "Un cuchillo corto con mango de hueso. Gastado aunque aun bien afilado.\n",
            P_IDS: ({"cuchillo"}),
            P_NUMBER_HANDS: 1,
            P_MATERIAL: M_HIERRO]),
            SF(wieldme));
}
