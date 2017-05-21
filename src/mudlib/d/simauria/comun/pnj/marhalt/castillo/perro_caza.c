#include <properties.h>
#include <combat.h>
inherit NPC;
create()
{
    ::create();
	SetStandard("un perro", "animal", 9, GENDER_MALE);
    SetShort("Un sabueso");
    SetLong("ES un perro de caza de los que el se�or de Nandor se sirve para rastrear y "
    "localizar los jabal�es, ciervos y dem�s piezas que moran en los grandes "
    "bosques de Marhalt. El se�or siente gran aprecio por sus sabuesos, dejandolos "
    "campar a sus anchas por su sal�n, y d�ndoles comida de su propia mesa.\n"
    "Es un perro de estructura ligera y pelaje color canela. Posee un cuerpo de "
    "estructura ligera, cola y orejas muy largas y un hocico ahusado con el que "
    "olisquea todo lo que le rodea.\n");
    AddId(({"un perro", "perro", "sabueso", "perro de caza", "caza", "animal"}));
    SetAlign(10);
    InitChats(4, ({"El sabueso levanta el hocico y husmea el aire atentamente.\n",
    	"El perro te mira mientras se relame largamente.\n",
    "El sabueso te olisquea con curiosidad.\n",
    "El sabueso se enrrosca en el suelo, rasc�ndose furiosamente una oreja con la pata trasera.\n",
    "El perro estornuda fuertemente salpicando el suelo de babas.\n"}));
    InitAChats(20, ({"El sabueso lanza un ga�ido de miedo.\n",
        "El sabueso gru�e ferozmente.\n"}));
    SetSmell("Huele a perro sucio.\n");
    SetWeight(42000);
    SetWhimpy(5);
    SetHands(({({"la dentadura", TD_CORTE,0})}));
    SetCitizenship("nandor");
}