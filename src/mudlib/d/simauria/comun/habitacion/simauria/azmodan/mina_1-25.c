/***********************************************************/
//	"mina_1-25"
//	Mina abandonada
//	11-12-01 : Creación -> Kodex
//	11-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
inherit STD_AZMODAN("mina");
object armeria;
int open;
public int QueryOpen() { return open; }
public int SetOpen(int estado) { return open= estado; }

public void cerrar(){
    armeria= find_object(MINA_AZMODAN("mina_1-23"));
    tell_room(TO,"La pared del sur vuelve a moverse tapando la salida hacia allí.\n");
    tell_room(armeria, "La pared se vuelve a mover ocultando la salida hacia el norte.\n");
    armeria->RemoveExit("norte");
    RemoveExit("sur");
    open = 0;
    armeria->SetOpen(0);
}

int cmd_pisar(string str){
    armeria = find_object(MINA_AZMODAN("mina_1-23"));
    if(!str)
        return notify_fail("¿Qué quieres pisar?\n", NOTIFY_NOT_VALID);
    if(str=="piedra" || str=="pequeña piedra" || str=="pequeña piedra redondeada"
    || str=="piedra redondeada"){
	    if(open)
	        return notify_fail("Pisas la piedra del suelo, pero no parece que ocurra nada.\n"),0;
		    write("Pisas con fuerza la piedra redondeada del peldaño y la pared "
		    "del sur se mueve dejando al descubierto una salida hacia allí.\n");
		say(CAP(TNAME)+" pisa con fuerza una piedra redondeada que hay en uno de "
		"los peldaños de la escalera y la pared del sur se mueve mostrando una salida "
		"hacia allí.\n");
		tell_room(armeria, "La pared del norte se mueve dejando al descubierto una "
		"salida hacia allí.\n");
		armeria->AddExit("norte", MINA_AZMODAN("mina_1-25"));
		AddExit("sur", MINA_AZMODAN("mina_1-23"));
		open = 1;
		armeria->SetOpen(1);
		call_out("cerrar",5+d4());
		return 1;
	}
	return notify_fail("¿Qué quieres pisar?\n", NOTIFY_NOT_VALID);
}

public string f_descripcion(){
    if(!open)
        return "Te encuentras en un estrecho rellano en lo alto de una escalera que "
        "baja hacia el segundo nivel de la mina.\n Las paredes bloquean todas las "
        "salidas excepto para abajo por las escaleras.\n";
        return "Te encuentras en un estrecho rellano en lo alto de una escalera que "
        "baja hacia el segundo nivel de la mina.\n Las paredes bloquean todas las "
        "salidas excepto para abajo por las escaleras, aunque en la pared del sur "
        "hay una extraña apertura que da paso a otra estancia.\n";
}

public string f_pared_sur(){
    if(!open)
        return "Las paredes de toda la mina presentan el mismo aspecto de roca basta y pura.\n";
    return "Esta pared presenta un gran orificio que da paso a otra estancia hacia el sur.\n";
}

create() {
    ::create();
    open = 0;
    SetIntShort("un rellano sin salida");
    SetIntLong(SF(f_descripcion));

    AddDetail(({"manchas","sangre","manchas de sangre"}),
    "Ves sangre reseca, será de algún combate que haya tenido lugar en estas "
    "escaleras hace relativamente poco tiempo.\n");
    AddDetail(({"grietas"}),
    "La escalera tiene algunas grietas producidas por el paso del tiempo.\n");
    AddDetail(({"escalera", "escaleras"}), "Las escaleras están escabadas en la "
    "propia roca de la mina, son estrechas y empinadas. En el último peldaño se "
    "puede apreciar una pequeña piedra redondeada que sobresale ligeramente del suelo.\n");
    AddDetail(({"piedra", "pequeña piedra", "pequeña piedra redondeada", "piedra redondeada",
        "peldaño", "último peldaño", "ultimo peldaño"}),
    "Sobre el último peldaño de las escaleras se puede ver, que sobresale del suelo, "
    "una pequeña piedra redondeada, con el símbolo de una flecha grabada, que indica "
    "hacia la pared del sur.\n");
    AddDetail("paredes",
    "Las paredes de toda la mina presentan el mismo aspecto de roca basta y pura.\n");
    AddDetail(({"pared sur", "pared del sur"}), SF(f_pared_sur));
    AddRoomCmd(({"pisar", "aplastar", "chafar", "pisotear"}), "cmd_pisar");
    AddRoomCmd("coger", "cmd_coger");
    AddExit("abajo",MINA_AZMODAN("mina_2-25"));
}

init(){
    ::init();
    tell_room(MINA_AZMODAN("mina_1-23"), "Escuchas movimiento desde las profundidades de la mina.\n");
}

public int cmd_coger(string str){
    if(!str) return 0;
    if(str=="piedra" || str=="pequeña piedra" || str=="pequeña piedra redondeada"
    || str=="piedra redondeada")
        return notify_fail("Está bien sujeta al suelo.\n", NOTIFY_NOT_VALID);
}

