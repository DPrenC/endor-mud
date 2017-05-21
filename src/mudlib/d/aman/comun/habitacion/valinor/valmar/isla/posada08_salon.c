/*****************************************************************************************
 ARCHIVO:       posada08_salon.c
 AUTOR:         Ztico
 FECHA:         13-04-2005
 DESCRIPCIÓN:   Posada del Unicornio Azul. Salón de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include "/d/aman/comun/quest/runas/runas_quest.h"
#include <colours.h>
#include <moving.h>
#include <wizlevels.h>

inherit BASE_ISLA;

public int cmd_mirar(string str);
public int cmd_leer(string str);
public string mirar_tapices();
public int transportar(object pl);

create()
{
    if(::create()) return 1;

    SetIntShort("el salón de los Druidas");
    SetIntLong("Te encuentras en el salón privado que los druidas usan para sus "
        "menesteres. Es una espaciosa estancia en uno de cuyos lados, colocados en el "
        "suelo, se alinean filas de almohadones que se sitúan frente a una tarima. Del "
        "techo penden enormes lámparas de cristal tallado que oscilan tintineando al "
        "menor soplo de brisa. Las paredes están adornadas con tapices y el suelo de "
        "mármol oscuro espejea de tan pulido y reluciente. Ves unas escaleras que "
        "descienden caracoleando hasta perderse de vista.\n");
    AddDetail(({"almohadon", "almohadón", "almohadones"}), "Están organizados en filas "
        "y alrededor de pequeñas mesas de madera.\n");
    AddDetail("tarima", "");
    AddDetail("techo", "");
    AddDetail("paredes", "");
    AddDetail(({"lampara", "lámpara", "lamparas", "lámparas"}), "Algunas están "
        "fabricadas con cristales monocromáticos y otras con pequeños vidrios de "
        "colores.\n");
    AddDetail("escaleras", ".\n");
    AddDetail("tapices", SF(mirar_tapices));
    AddDetail("suelo", "Puedes ver tu reflejo.\n");

    SetIndoors(1);
    SetIntBright(30);

    AddRoomCmd("leer", "cmd_leer");
    AddRoomCmd(({"mirar", "examinar"}), "cmd_mirar");

    AddExit("sureste", HAB_BOSQUE_ISLA("posada06_comedor.c"));
    AddExit("arriba", HAB_BOSQUE_ISLA("posada10_azotea.c"));
    AddExit("abajo", HAB_BOSQUE_ISLA("posada11_taller.c"));
}

public string mirar_tapices()
{
    if(QUESTMASTER->QueryQuestSolved(QUEST_KEY, TP) || TP->QueryAttribute(ATTE_RUNAS))
        return "Están tejidos en lana pura, y reflejan viñetas de naturaleza y de caza.\n"
               "Uno de ellos destaca entre los demás.\n";
    else return "Están tejidos en lana pura, y reflejan viñetas de naturaleza y de caza.\n";
}

public int cmd_mirar(string str)
{
    if(!str) return 0;
    if(QUESTMASTER->QueryQuestSolved(QUEST_KEY, TP) || TP->QueryAttribute(ATTE_RUNAS))
    {
        switch(str)
        {
            case "tapiz":
                tell_object(TP, "Te fijas bien y alrededor de uno de ellos hay unas "
                    "extrañas marcas rojas.\n");
                break;

            case "marcas":
            case "marcas rojas":
                tell_object(TP, "Se trata de una serie de runas enlazadas.\n");
	              break;

            case "runas":
            case "runas enlazadas":
        	      tell_object(TP, "Quizás puedas leerlas.\n");
        	      break;
        	  default: return 0;
        }
        return 1;
    }
    return 0;
}

public int cmd_leer(string str)
{
    if (!str || str != "runas") return 0;

    if(IS_LEARNER(TP))
    {
        TP->move(HAB_BOSQUE_ISLA("posada09_secreta.c"), M_SPECIAL);
        return 1;
    }

    if(QUESTMASTER->QueryQuestSolved(QUEST_KEY, TP) || TP->QueryAttribute(ATTE_RUNAS))
    {
        write("\nPronuncias en voz alta:" TC_BOLD TC_CYAN " Sdrôn arhumad annon ehlö.\n"
            TC_NORMAL "y ves como las runas se iluminan de repente.\n");
        say(CAP(TNAME) + " pronuncia en voz alta: Sdrôn arhumad ehlö annon.\n");
        call_out("transportar", 1, TP);
        return 1;
    }
    else
    {
    	  write("No estás preparad" + AO + " para leer las runas.\n");
        return 0;
    }
}

public int transportar(object pl)
{
    if(pl && present(pl, TO))
    {
        pl->move(HAB_BOSQUE_ISLA("posada09_secreta.c"), M_SPECIAL, ({
  		                     "dice algo que no puedes entender y de repente aparece una luz "
  		                     "que te ciega",
			                     "llega",
			                     "Una fuerza mágica te transporta a un lugar diferente"
		                    }));
        return 1;
    }
    return 0;
}
