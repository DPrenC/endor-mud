/***********************************************************/
//	"mina_3-05"
//	Mina abandonada
//	15-12-01 : Creación -> Kodex
//	15-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
inherit STD_AZMODAN("mina");

int open;
object arriba;
public int QueryOpen() { return open; }
public int SetOpen(int estado) { return open= estado; }

public void cerrar(){
    arriba = find_object(MINA_AZMODAN("mina_2-05"));
    tell_room(arriba,"Las grietas del suelo vuelven a su posición cerrando el pasadizo y "
    "las velas del candelabro se encienden.\n");
    tell_room(TO, "El techo se vuelve a cerrar.\n");
    arriba->RemoveExit("abajo");
    RemoveExit("arriba");
    open=0;
    arriba->SetEncendido(1);
}

int cmd_mover(string str){
    arriba = find_object(MINA_AZMODAN("mina_2-05"));
    if (!str)
        return notify_fail("¿" + CAP(query_verb()) + " qué?\n"),0;
    if (str == "antorcha"){
	    if (open || !arriba->QueryEncendido())
	        return notify_fail("No parece que ocurra nada.\n",
	        NOTIFY_NOT_VALID);
		open=1;
		arriba->SetEncendido(0);
		write("Forcejeas con la antorcha para moverla y ves como se abre una apertura "
		"en el techo al final de las escaleras.\n");
		say(CAP(TNAME) + " forcejea con la antorcha de la pared y ves como se abre "
		"una apertura en el techo al final de las escaleras.\n");
		tell_room(arriba, "El suelo se abre dejando paso a una sala inferior, las velas "
		"del candelabro se apagan.\n");
		arriba->AddExit("abajo", MINA_AZMODAN("mina_3-05"));
		AddExit("arriba", MINA_AZMODAN("mina_2-05"));
		call_out("cerrar",5+d4());
		return 1;
	}
	return notify_fail("¿" + CAP(query_verb()) + " qué?\n"),0;
}

public string f_escaleras(){
    if(open)
        return "Son unas viejas escaleras que dan a una sala superior por una "
        "apertura en el techo.\n Junto a las escaleras hay una antorcha apagada.\n";
        return "Son unas viejas escaleras sin mucho sentido, pues acaban en el techo "
        "cerrado y no parecen tener ningún objetivo, quizá algún día existía alguna "
        "apertura ahí arriba para acceder a otra sala superior.\n Junto a las escaleras "
        "hay una antorcha apagada.\n";
}

public string f_techo(){
    if(open)
        return "Ahí arriba, tras el final de las escaleras en el techo, hay una "
        "estrecha apertura que da a una sala superior.\n";
        return "El techo debió tener alguna apertura algún día, pues sino no se "
        "explicaría estas escaleras que terminan en el duro techo sin ninguna salida.\n";
}

public string f_descripcion(){
    if(open)
        return "Te encuentras junto a unas viejas escaleras de piedra que ascienden "
        "hasta el techo de esta estancia, y las cuales van a dar hasta una sala "
        "superior por una estrecha apertura al final de las escaleras.\n";
        return "Te encuentras junto a unas escaleras que suben hacia el techo, "
        "encontrándose con la dura roca, pues las cuales no llevan a ninguna parte, ya "
        "que si alguna vez hubo una apertura ahí arriba ya no existe.\n";
}

create() {
    ::create();
    open = 0;
    SetIntShort("la tercera planta de la mina, junto a unas escaleras");
    SetIntLong(SF(f_descripcion));
    AddDetail(({"techo", "arriba"}), SF(f_techo));
    AddDetail(({"escalera", "escaleras"}), SF(f_escaleras));
    AddDetail("antorcha", "Es una antorcha apagada que está clavada en la dura pared.\n");
    AddRoomCmd(({"mover", "girar", "empujar"}), "cmd_mover");
    AddExit("norte",MINA_AZMODAN("mina_3-09"));
    AddExit("sudeste",MINA_AZMODAN("mina_3-02"));
if (random(100) < 50)
	{
		switch(random(2))
		{
		case 0: AddItem(NPC_AZMODAN("shaman"),REFRESH_DESTRUCT,1); break;
		case 1: AddItem(NPC_AZMODAN("uruk"),REFRESH_DESTRUCT,1); break;
		default: break;
		}
	}

}

init(){
    ::init();
    tell_room(MINA_AZMODAN("mina_2-05"), "Se escucha a lo lejos los sonidos naturales "
    "de las profundidades de la mina.\n");
}
