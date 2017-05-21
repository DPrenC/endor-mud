/***********************************************************/
//	"mina_2-05"
//	Mina abandonada
//	14-12-01 : Creación -> Kodex
//	14-12-01 : Modificación -> Kodex
//
//
#include "./path.h"


inherit STD_AZMODAN("mina");

int encendido;
object abajo;
public int QueryEncendido() { return encendido; }
public int SetEncendido(int estado) { return encendido= estado; }
public void cerrar(){
    abajo = find_object(MINA_AZMODAN("mina_3-05"));
    tell_room(TO,"Las grietas del suelo vuelven a su posición cerrando el pasadizo y "
    "el candelabro se enciende de nuevo.\n");
    tell_room(abajo, "El techo se vuelve a cerrar.\n");
    abajo->RemoveExit("arriba");
    RemoveExit("abajo");
    encendido=1;
    abajo->SetOpen(0);
}

int apagar_cmd(string str){
    abajo = find_object(MINA_AZMODAN("mina_3-05"));
    if (!str)
        return notify_fail("¿" + CAP(query_verb()) + " qué?\n"),0;
    if (str == "candelabro" || str == "velas"){
	    if(!encendido || abajo->QueryOpen()==1)
	        return notify_fail("Las velas del candelabro no están encendidas.\n",
	        NOTIFY_NOT_VALID);
		encendido = 0;
		abajo->SetOpen(1);
		write("Apagas las velas y las grietas del suelo se mueven, dejando al "
		"descubierto unas escaleras hacia abajo.\n");
		say(CAP(TNAME) + " apaga las velas del candelabro.\n Las grietas del suelo "
		"se mueven dejando al descubierto unas escaleras que bajan.\n");
		tell_room(abajo, "El techo se abre dejando paso a una sala superior.\n");
		AddExit("abajo", MINA_AZMODAN("mina_3-05"));
		abajo->AddExit("arriba", MINA_AZMODAN("mina_2-05"));
		call_out("cerrar",9);
		return 1;
	}
	return notify_fail("¿" + CAP(query_verb()) + " qué?\n"),0;
}

public string f_candelabro(){
    if(encendido)
        return "Es un candelabro dorado con tres velas encendidas, el fuego que "
        "arde en ellas parece místico. Alguien debió dejarlo encendido por error.\n";
        return "Es un candelabro dorado con tres velas apagadas.\n";
}

public string f_suelo(){
    if(!encendido)
        return "El suelo está abierto mostrando una salida hacia abajo.\n";
        return "En el suelo se pueden apreciar unas grietas que quizá fueron producidas "
        "por algún desprendimiento.\n";
}

public string f_descripcion(){
    if(!encendido)
        return "Esto es una pequeña sala excavada en un recodo de la mina.\n"
        " Hay una mesa de madera adornada con un candelabro y dos jarras de metal,"
        " pero la mesa está ennegrecida por la suciedad que flota en el ambiente.\n "
        " En el suelo hay una apertura que comunica esta sala con otra inferior.\n";
        return "Esto es una pequeña sala excavada en un recodo de la mina.\n"
        " Hay una mesa de madera adornada con un candelabro y dos jarras de metal,"
        " pero la mesa está ennegrecida por la suciedad que flota en el ambiente.\n "
        " Se aprecian unas pequeñas grietas en el suelo.\n";
}

create() {
    ::create();
    encendido = 1;
    SetIntShort("la segunda planta de la mina");
    SetIntLong(SF(f_descripcion));
    AddDetail(({"grietas","suelo"}), SF(f_suelo));
    AddDetail(({"jarras","jarra","jarras de metal"}),
    "Son dos jarras de metal en muy mal estado y sucias... mejor dicho asquerosamente sucias.\n");
    AddDetail(({"candelabro", "velas"}), SF(f_candelabro));
    AddDetail(({"mesa", "mesa de madera"}), "Es una vieja mesa de madera muy estropeada "
    "por la humedad, y sobre todo muy sucia.\n");
    AddExit("norte",MINA_AZMODAN("mina_2-09"));
    AddExit("sudeste",MINA_AZMODAN("mina_2-02"));
if (random(100) < 50)
	{
		switch(random(3))
		{
		case 0 .. 1: AddItem(NPC_AZMODAN("uruk"),REFRESH_DESTRUCT,1); break;
		case 2: AddItem(NPC_AZMODAN("orco"),REFRESH_DESTRUCT,1); break;
		default: break;
		}
	}

}

init()
{
    ::init();
    add_action("apagar_cmd","apagar");
    add_action("apagar_cmd", "soplar");
    tell_room(MINA_AZMODAN("mina_3-05"), "Se escucha a lo lejos los sonidos naturales "
    "de las profundidades de la mina.\n");
}
