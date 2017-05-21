/***********************************************************/
//	"mina_2-03"
//	Mina abandonada
//	14-12-01 : Creación -> Kodex
//	14-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
#include <properties.h>
inherit STD_AZMODAN("mina");

public int secreta;
public int QuerySecreta() { return secreta; }
object room_secreta;
public void cerrar()
{
    room_secreta = find_object(MINA_AZMODAN("mina_2-01"));
    tell_room(TO,"El pasadizo se cierra con fuerza.\n");
    tell_room(room_secreta, "La apertura de la pared del norte se cierra con fuerza "
    "dejando la estancia sin salidas.\n");
    secreta = 0;
    room_secreta->SetOpen(0);
    RemoveExit("sur");
    room_secreta->RemoveExit("norte");
}

int empujar_cmd(string str)
{
    room_secreta = find_object(MINA_AZMODAN("mina_2-01"));
if (!str) return notify_fail("¿Empujar qué?\n"),0;
if (secreta) return notify_fail("La roca ya fue empujada antes.\n"),0;
if (str == "roca")
	{
		write("Empujas la roca y se abre un pasadizo en la pared del sur.\n");
		say(capitalize(TP->QueryRealName()) + " empuja una roca de la pared y, ante tus "
		"ojos, se abre un pasadizo que lleva al sur.\n");
		tell_room(MINA_AZMODAN("mina_2-01"), "Escuchas moverse la roca en la pared del "
		"norte y una apertura se abre en la dura piedra.\n");
		secreta = 1;
		room_secreta->SetOpen(1);
		AddExit("sur",MINA_AZMODAN("mina_2-01"));
		room_secreta->AddExit("norte",MINA_AZMODAN("mina_2-03"));
		call_out("cerrar",100);
		return 1;
	}
	else
	return notify_fail("No encuentras " + str + " para empujar.\n"),0;
}

public string f_descripcion(){
    if(!secreta)
        return "Estás en un pasillo corto que une dos bifurcaciones, la "
        "luz es muy tenue, las antorchas que hay en la mina no iluminan demasiado "
        "y las rocas que hay en las paredes son a veces peligrosas como aquí.\n";
        return "Estás en un pasillo corto que une dos bifurcaciones, la "
        "luz es muy tenue, las antorchas que hay en la mina no iluminan demasiado "
        "y las rocas que hay en las paredes son a veces peligrosas como aquí.\n En la "
        "pared del sur parece haberse abierto la roca para dejar paso a una estancia "
        "notablemente pequeña.\n";
}

public string f_paredes(){
    if(!secreta)
        return "Las paredes están llenas de rocas que sobresalen.\n";
        return "Las paredes están llenas de rocas que sobresalen. La del sur se ha "
        "abierto dejando una pequeña entrada a una pequeña estancia.\n";
}

create() {

    ::create();
    SetIntShort("la segunda planta de la mina");
    SetIntLong(SF(f_descripcion));
    AddDetail(({"pared","paredes"}), SF(f_paredes));
    AddDetail(({"rocas que sobresalen", "rocas"}),
    "Hay un montón de rocas que sobresalen de la pared pero una de ellas es distinta a las demás.\n");
    AddDetail(({"roca distinta", "roca"}),
    "Es una roca que sobresale demasiado y parece que se puede empujar.\n");
    secreta = 0;
    AddExit("este",MINA_AZMODAN("mina_2-04"));
    AddExit("oeste",MINA_AZMODAN("mina_2-02"));
    if (random(100) < 50)
	{
		switch(random(3))
		{
		case 0: AddItem(NPC_AZMODAN("uruk"),REFRESH_DESTRUCT,1); break;
		case 2: AddItem(NPC_AZMODAN("orco"),REFRESH_DESTRUCT,1); break;
		default: break;
		}
	}

}

public void aviso()
{
    if(present(TP, TO))
        tell_object(TP,"Con tu intuición de tu raza, te fijas que en una de las paredes hay "
        "una roca que sobresale demasiado, es muy sospechosa.\n");
}

init()
{
    ::init();
    tell_room(MINA_AZMODAN("mina_2-01"), "Escuchas los sonidos de las entrañas de la mina.\n");
    if (TP->QueryRace() == "enano")
    	call_out("aviso",d3());
    add_action("empujar_cmd","empujar");

}
