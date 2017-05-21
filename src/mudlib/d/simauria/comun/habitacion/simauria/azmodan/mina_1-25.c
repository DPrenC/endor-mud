/***********************************************************/
//	"mina_1-25"
//	Mina abandonada
//	11-12-01 : Creaci�n -> Kodex
//	11-12-01 : Modificaci�n -> Kodex
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
    tell_room(TO,"La pared del sur vuelve a moverse tapando la salida hacia all�.\n");
    tell_room(armeria, "La pared se vuelve a mover ocultando la salida hacia el norte.\n");
    armeria->RemoveExit("norte");
    RemoveExit("sur");
    open = 0;
    armeria->SetOpen(0);
}

int cmd_pisar(string str){
    armeria = find_object(MINA_AZMODAN("mina_1-23"));
    if(!str)
        return notify_fail("�Qu� quieres pisar?\n", NOTIFY_NOT_VALID);
    if(str=="piedra" || str=="peque�a piedra" || str=="peque�a piedra redondeada"
    || str=="piedra redondeada"){
	    if(open)
	        return notify_fail("Pisas la piedra del suelo, pero no parece que ocurra nada.\n"),0;
		    write("Pisas con fuerza la piedra redondeada del pelda�o y la pared "
		    "del sur se mueve dejando al descubierto una salida hacia all�.\n");
		say(CAP(TNAME)+" pisa con fuerza una piedra redondeada que hay en uno de "
		"los pelda�os de la escalera y la pared del sur se mueve mostrando una salida "
		"hacia all�.\n");
		tell_room(armeria, "La pared del norte se mueve dejando al descubierto una "
		"salida hacia all�.\n");
		armeria->AddExit("norte", MINA_AZMODAN("mina_1-25"));
		AddExit("sur", MINA_AZMODAN("mina_1-23"));
		open = 1;
		armeria->SetOpen(1);
		call_out("cerrar",5+d4());
		return 1;
	}
	return notify_fail("�Qu� quieres pisar?\n", NOTIFY_NOT_VALID);
}

public string f_descripcion(){
    if(!open)
        return "Te encuentras en un estrecho rellano en lo alto de una escalera que "
        "baja hacia el segundo nivel de la mina.\n Las paredes bloquean todas las "
        "salidas excepto para abajo por las escaleras.\n";
        return "Te encuentras en un estrecho rellano en lo alto de una escalera que "
        "baja hacia el segundo nivel de la mina.\n Las paredes bloquean todas las "
        "salidas excepto para abajo por las escaleras, aunque en la pared del sur "
        "hay una extra�a apertura que da paso a otra estancia.\n";
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
    "Ves sangre reseca, ser� de alg�n combate que haya tenido lugar en estas "
    "escaleras hace relativamente poco tiempo.\n");
    AddDetail(({"grietas"}),
    "La escalera tiene algunas grietas producidas por el paso del tiempo.\n");
    AddDetail(({"escalera", "escaleras"}), "Las escaleras est�n escabadas en la "
    "propia roca de la mina, son estrechas y empinadas. En el �ltimo pelda�o se "
    "puede apreciar una peque�a piedra redondeada que sobresale ligeramente del suelo.\n");
    AddDetail(({"piedra", "peque�a piedra", "peque�a piedra redondeada", "piedra redondeada",
        "pelda�o", "�ltimo pelda�o", "ultimo pelda�o"}),
    "Sobre el �ltimo pelda�o de las escaleras se puede ver, que sobresale del suelo, "
    "una peque�a piedra redondeada, con el s�mbolo de una flecha grabada, que indica "
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
    if(str=="piedra" || str=="peque�a piedra" || str=="peque�a piedra redondeada"
    || str=="piedra redondeada")
        return notify_fail("Est� bien sujeta al suelo.\n", NOTIFY_NOT_VALID);
}

