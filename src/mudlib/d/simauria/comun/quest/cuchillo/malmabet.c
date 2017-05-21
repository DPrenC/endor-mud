/*
DESCRIPCION : tendera Malmabeth
FICHERO     : /d/simauria/comun/pnj/simauria/berat/malmabet.c
MODIFICACION:
              [i] Icaro
              [m] Maler
	      [n] Nemesis
              04-11-99 [Icaro] Creaci�n
              02-06-00 [Maler] correccion ortografica, eliminados
			      retornos de carro;
			      sustituido el path de la coraza;
	               [m] modifico a saco pa hacer la quest
	      11-07-00 [n] Ligeros retoques a los textos y a la
	                   indentaci�n
	      19-09-01 [n] A  partir de ahora se guardar� un log de qui�n
	                   resuelve el quest y cu�ndo

--------------------------------------------------------------------------------
*/
#include "path.h"
#include <properties.h>
#include <living.h>
#include <combat.h>
#include <rooms.h>
#include <messages.h>
inherit NPC;

init()
{
    ::init();
    add_action("dar_cmd","dar");
}

int dar_cmd(string str)
{
    object from, ob, ob2, lista;
    int num;
    string a, b, Quests;
    from = TP;
    if ((sscanf(str,"%s a malmabeth",a) == 1)||
        (sscanf(str,"%s a Malmabeth",a) == 1)||
        (sscanf(str,"%s a tendera",a) == 1))
    {
        if (!from || !str) return 0;
        Quests=from->QueryQuests();
        if (!Quests) Quests="hallo";
        ob  =  present(a,TP);
        if (!ob) return notify_fail("Tu no tienes "+a+".\n",NOTIFY_NOT_VALID)&&0;
        if (member(ob->QueryIds(), "quest_cuchillo_berat")!=-1)
        {
            ob->remove();
            write("Malmabeth te mira de arriba a abajo, y una expresi�n de intensa alegr�a "
                "inunda su cara. Te abraza efusivamente, y te dice: muchas gracias por traerme "
                "mi apreciado cuchillo, no se qu� habr�a hecho sin ti. Ojal� hubiese m�s gente "
                "que se preocupase por los dem�s.\n");
            if (sscanf(Quests,"%serat_quest_cuchill%s",a,b)!=2)
            {
                write("Malmabeth te dice: Ahora supongo que querr�s cobrar tu recompensa.\nY "
                    "diciendo esto abre uno de sus cajones y te da dos gemas.\nNo es mucho "
                    "-contin�a-, pero es todo lo que me queda, la obra se est� llevando casi "
                    "todos mis ingresos.\n");
                tell_room(environment(TP),({MSG_SEE,"Malmabeth le da dos gemas a "+
                    TP->QueryName()+" como recompensa por su ayuda.\n"}),({TP}));
                ob2=clone_object(OTRO("zafiro"));
                ob2->move(TP);
                ob2=clone_object(OTRO("zafiro"));
                ob2->move(TP);
                write("\nAcabas de resolver el quest del cuchillo perdido de Malmabeth.\n\n");
                QUESTMASTER->InformSolution("Malmabeth ha recuperado su cuchillo perdido "
                    "gracias a "+TP->QueryName()+".\n");
                QUESTMASTER->SetPlayerQuest("berat_quest_cuchillo",TP);
  	            write_file(LOGS"CUCHILLOQUEST",ctime(time())+" "+TP->QueryRealName()+" ["+
                    TP->QueryLevel()+"]   Ha recuperado el cuchillo de Malmabeth\n");
            }
        }
        else
        {
            write("La tendera te mira, y dice: Vaya, gracias! nunca me hab�an regalado nada. "
                "Realmente, sabes como conquistar a una mujer.\n ");
            return 0;
        }
        return 1; // return del if(ello es dar x a Malmabeth)
    }
    return 0;  // Si resulta que ello es: 'dar x a otro que no es MMB'
}


create()
{
    ::create();
   SetStandard("Malmabeth","humano",10,GENDER_FEMALE);
    SetShort("Malmabeth la tendera");
    SetLong("Malmabeth es una humana hermosa, probablemente la joven m�s deseada de este "
        "pueblo.\nParece alterada, como si buscase algo.\n");
    SetIds(({"Malmabeth","malmabeth","tendera", "mujer", "humana"}));
    Set(P_CANT_LURE,1);
    SetCitizenship("berat");
    AddQuestion(({"busqueda","que buscas","alteracion","preocupacion","b�squeda","qu� buscas","alteraci�n","preocupaci�n"}),
        "Malmabeth te dice: No encuentro mi cuchillo para curtir, �podr�as ayudarme a buscarlo? "
        "No andar� muy lejos, si me ayudas te recompensar�.\n");
    AddQuestion(({"cuchillo","cuchillo para curtir"}),"Malmabeth te dice: No s� donde lo he "
        "dejado, a lo mejor lo perd� mientras ayudaba en la construcci�n de mi casa.... por "
        "favor, encu�ntralo y te recompensar�.\n");
    AddQuestion(({"casa","casa en construcci�n" "casa en construccion"}),"Malmabeth te dice: "
        "Me estoy haciendo una casa en la calle Koldar, al este de aqu�.\n");
    InitChats(3,({"Malmabeth dice: Oooooh, cielos, �d�nde lo habr� puesto?\n",
        "Malmabeth te dice: �Has visto mi cuchillo?\n",
        "Malmabeth te dice: Todos los hombres del pueblo son iguales, mucho hablar, pero nunca "
            "te ayudan.\n"}));
}



