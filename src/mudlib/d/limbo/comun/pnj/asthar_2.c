/*
DESCRIPCION  : Asthar, el siervo encargado de transformar a los players
FICHERO      : /d/limbo/comun/pnj/asthar.c
*/

#include <colours.h>
#include "path.h"
#include <properties.h>
#include <messages.h>
inherit NPC;
#define AO      (TP->QueryGenderEndString())
#define NOMBRE  (capitalize(TP->QueryName()))

int nolucho()
{
    object agresor=TP || PO;
    tell_room(environment(),agresor->QueryName()+" intenta matar a Asthar. Éste le mira fíjamente mientras "
        "parece decirle algo.\n",({agresor}));
    return notify_fail("Asthar te mira profundamente a los ojos mientras te dice: Estoy aquí "
        "para ayudar a los mortales, no para hacerles daño. No hay razón para que me ataques, "
        "a los dioses no les gustaría.\nHa dicho las últimas palabras con una mirada "
        "suplicante, y al fijarte en sus ojos, tienes la sensación de que no es por su vida "
        "por la que teme, sino por la tuya. Sientes un escalofrío de terror, y desistes de tu "
        "intención.\n",NOTIFY_NOT_VALID);
}

int esquivo()
{
    tell_room(environment(),"Asthar hace un movimiento rápido. Parece que "+NOMBRE+" intentaba "
        "lanzarle algo.\n",({TP}));
    write("Asthar hace un rápido quiebro, esquivando tu lanzamiento.\n");
    return 1;
}

create()
{
    ::create();
    SetStandard("Asthar","humano",90,GENERO_MASCULINO);
    SetChkFightFunction(SF(nolucho));
    SetChkMagicFunction(SF(nolucho));
    SetShort("Asthar, el siervo de los dioses");
    SetLong("Asthar es un hombre mayor, vestido con la túnica característica de los siervos de "
        "los dioses, una gruesa túnica blanca recorrida verticalmente por una ancha franja de "
        "color rojo. Pese al sencillo atuendo, algo te dice que Asthar no es un individuo "
        "corriente...\n");
    SetIds(({"humano","siervo","asthar","Asthar","hombre"}));
    SetAds(({"un","siervo","humano"}));
    SetNoGet("Asthar te dice: Mantén las manos quietas si quieres conservarlas.\n");
    Set(P_CANT_STEAL,1);
    Set(P_CANT_LURE,1);
    /*InitChats(6,({"Asthar dice: Si estás muerto, con 'resucitar' puedo devolverte tu cuerpo "
        "físico.\n"}));*/
    //Preguntas
  AddQuestion(({"dios","dioses","Dioses","wizards","Wizards","los dioses","los Dioses"}),
"Un puñado de Dioses crearon este mundo en un tiempo inmemorial y luego "
"encargaron a los Wizards su mantenimiento. Si alguna vez te cruzas con "
"alguno de ellos, muéstrales el respeto debido o te arriesgaras a caiga "
"sobre ti su furia desatada. Esta isla Limbo es un lugar muy especial en "
"Simauria pues es aquí donde las nuevas almas como la tuya aparecen. Mi "
"misión, así como la del resto de los siervos de los Dioses, es ayudar a "
"esas nuevas almas a dar los primeros pasos en este mundo.\n");
    SetShrugMsg("Asthar dice: Hummm!... No conozco la respuesta en este momento. Me ayudarías "
        "a mí y a otros mortales si se lo preguntas directamente a los dioses.\n"
        "[Usa 'idea asthar no puede responder a <lo que preguntaste>']\n");
}

init()
{
    ::init();
    add_action("esquivo","lanzar");
}
   