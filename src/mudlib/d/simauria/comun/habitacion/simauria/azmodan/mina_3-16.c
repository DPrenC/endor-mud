/***********************************************************/
//	"mina_3-16"
//	Mina abandonada, escondite de scyla
//	15-12-01 : Creación -> Kodex
//	18-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
inherit STD_AZMODAN("mina");

object scyla;
int open;
public int QueryOpen() { return open; }
public int picar_cmd(string str){
	object pico;
	scyla = find_object(MINA_AZMODAN("mina_scyla"));
    if (str == "veta" || str == "en veta" || !str)	{
	    if (open)
	        return notify_fail("No necesitas picar, el agujero ya está abierto.\n");
	pico = present("pico",TP);
	if (!pico) return notify_fail("Necesitas empuñar un pico para picar.\n");
	if (pico->QueryEquipped() == TP)
		{
		switch(random(2))
			{
			case 0:	write("Empiezas a picar sobre la veta de mineral pero no consigues nada relevante.... deberías seguir intentándolo.\n");
				say(capitalize(TP->QueryRealName()) + " empieza a picar en la veta de mineral pero sin resultados.\n");
				return 1;
				break;
			case 1:
			    write("Empiezas a picar sobre la veta de mineral y consigues descubrir "
			    "una entrada hacia abajo.\n");
				say(capitalize(TP->QueryRealName()) + " empieza a picar en la veta "
				"de mineral y descubre una entrada hacia abajo.\n");
				tell_room(scyla, "Escuchas golpes de pico sobre tu cabeza y al poco "
				"tiempo ves que se abre una pequeña salida por arriba.\n");
				AddExit("abajo", MINA_AZMODAN("mina_scyla"));
				scyla->AddExit("arriba", MINA_AZMODAN("mina_3-16"));
				open = 1;
				scyla->SetOpen(1);
				return 1;
				break;
			default:break;
			}
		}
	else
	return notify_fail("Necesitas empuñar un pico para picar.\n");
	}
else return notify_fail("No encuentras " + str + " para picar.\n");
}

public string f_veta(){
    if(!open)
        return "Es una parte de la pared rocosa que brilla, es notablemente distinto al "
        "resto de la pared.\n";
        return "La veta está casi totalmente picada, ya no queda mucho de ella, pero "
        "en su lugar hay un abujero que da entrada a una pequeña estancia oculta hacia abajo.\n";
}

public string f_descripcion(){
    if(!open)
        return "Estás en un cruce de corredores, donde la mayoría de la "
        "iluminación de la sala apunta a un gran estandarte clavado en el "
        "suelo que se presenta señorial ante tus ojos. La estructura de "
        "clanes orca parece tener mucho poder sobre su comportamiento.\n  En una de las "
        "paredes se puede apreciar una veta de mineral sin trabajar, la deben haber pasado por alto.\n";
        return "Estás en un cruce de corredores, donde la mayoría de la "
        "iluminación de la sala apunta a un gran estandarte clavado en el "
        "suelo que se presenta señorial ante tus ojos. La estructura de "
        "clanes orca parece tener mucho poder sobre su comportamiento.\n  En una de las "
        "paredes hay un agujero que da entrada a una estancia oculta hacia abajo.\n";
}

        create() {
    ::create();
        open=0;
    SetIntShort("la tercera planta de la mina");
    SetIntLong(SF(f_descripcion));

    AddDetail("estandarte",
    "Es el estandarte del clan Tanglor, tiene dos cimitarras cruzadas dibujadas.\n");
    AddDetail(({"veta", "veta de mineral"}), SF(f_veta));
    AddExit("este",MINA_AZMODAN("mina_3-17"));
    AddExit("oeste",MINA_AZMODAN("mina_3-15"));
    AddExit("sur",MINA_AZMODAN("mina_3-11"));
if (random(100) < 50)
	{
		switch(random(2))
		{
		case 0: AddItem(NPC_AZMODAN("shaman"),REFRESH_DESTRUCT,d2()); break;
		case 1: AddItem(NPC_AZMODAN("uruk"),REFRESH_DESTRUCT,d2()); break;
		default: break;
		}
	}

}

aviso()
{
tell_object(TP,"Gracias a las habilidades de tu raza, descubres una veta de mineral "
"sin tratar,en una de las paredes.\n");
}

init()
{
    ::init();
    tell_room(MINA_AZMODAN("mina_scyla"), "Escuchas los sonidos de las entrañas de la mina.\n");
    if (TP->QueryRace() == "enano")
    	call_out("aviso",1);
    add_action("picar_cmd","picar");
}
