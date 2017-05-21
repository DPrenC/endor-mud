/**************************************************************************/
/*                                                                        */
/**************************************************************************/

#include "./path.h"
#include <moving.h>

#define LOCATE "Algun lugar del norte de Marhalt"
inherit SIM_ROOM;
int encontrado;
object obsequio;
void say (string str)
{
  tell_room(MARH("nandor/tiendas/iglesia"),
    "Oyes voces bajo tus pies.\nConcretamente, alguien dice: "+str+"\n");
}

haz_arriba()
{
  write("Sigilosamente sales a la luz...\n.... �Y apareces en medio de un templo!\n");
  tell_room(MARH("nandor/tiendas/iglesia"),
    "De pronto, una losa se alza y aparece "+TP->QueryName()+
    " con cara de asombro.\n");
  TP->move(MARH("nandor/tiendas/iglesia"),M_GO,"arriba");
  tell_room(MARH("nandor/castillo/tunel/sal2"),
    TP->QueryName()+" sube hacia el exterior saliendo de la tumba.\n");
  return 1;
}

public string f_encontrar(){
    write("Es un h�bito ro�do por el paso del tiempo.\n");
    if (!encontrado){
        encontrado=1;
        obsequio = clone_object(QUEST "ghoul/lingote");
        obsequio->move(environment(TP));
        TP->SetExplored();
        say(CAP(TNAME)+" rebusca entre los restos del esqueleto y saca un lingote de plata.\n");
        return "Entre los restos del h�bito, encuentras un lingote de plata que "
        "alguien ha debido esconder no hace mucho, teniendo en cuenta su brillo.\n";
    }
    return "";
}

create()
{
    ::create();
    SetLocate(LOCATE);
    SetIntShort("la salida de un t�nel");
    SetIntLong(
    "Est�s en un estrecho cub�culo. Hay un esqueleto tirado por aqu�. Oyes "
    "un rumor extra�o proveniente de arriba...\n");
    SetIntBright(5);
    SetIntNoise("Oyes el eco de pasos y voces provenientes de arriba.\n");
    AddDetail(({"arriba", "techo"}),
    "Parece que el techo es m�vil...\n");
    AddDetail(({"huesos","esqueleto"}),
    "Parece que est�s en la tumba de un cl�rigo, a juzgar por el h�bito "
    "ra�do que cubre sus pelados huesos.\n");
    AddDetail(({"h�bito", "habito", "h�bito raido", "habito raido", "h�bito ra�do",
    "habito ra�do"}), SF(f_encontrar));

    AddRoomCmd(({"decir","'"}),SF(say));
    AddExit("arriba",SF(haz_arriba));
    AddExit("oeste","./pasadizo67");
}
