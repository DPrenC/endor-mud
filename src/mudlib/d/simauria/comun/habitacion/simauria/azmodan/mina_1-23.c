/***********************************************************/
//	"mina_1-23"
//	Mina abandonada
//	11-12-01 : Creaci�n -> Kodex
//	11-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
inherit STD_AZMODAN("mina");
object pasaje;
int open;
public int QueryOpen() { return open; }
public int SetOpen(int estado) { return open= estado; }

public void cerrar(){
    pasaje = find_object(MINA_AZMODAN("mina_1-25"));
    tell_room(TO,"La pared vuelve a colocarse en su sitio tapando la entrada secreta.\n");
    tell_room(pasaje, "La pared se vuelve a mover ocultando la salida hacia el sur.\n");
    pasaje->RemoveExit("sur");
    RemoveExit("norte");
    open = 0;
    pasaje->SetOpen(0);
}

int coger_cmd(string str){
    pasaje = find_object(MINA_AZMODAN("mina_1-25"));
    if(!str)
        return notify_fail("�" + CAP(query_verb()) + " qu�?\n");

    if (str == "libro" || str == "libro rojo"){
	    if (open)
	        return notify_fail("El libro est� sujeto a alg�n mecanismo y no parece "
	        "que ocurra nada.\n");
		write("Intentas coger el libro, pero al moverlo, una pared de la estancia "
		    "se desliza mostrando una salida hacia el norte.\n");
		say(capitalize(TP->QueryRealName()) + " mueve un libro de una estanter�a y "
		"una de las paredes se desliza mostrando una salida hacia el norte.\n");
		tell_room(MINA_AZMODAN("mina_1-25"), "La pared del sur se mueve dejando al descubierto una "
		"salida hacia all�.\n");
		AddExit("norte", MINA_AZMODAN("mina_1-25"));
		pasaje->AddExit("sur", MINA_AZMODAN("mina_1-23"));
		open = 1;
		pasaje->SetOpen(1);
		call_out("cerrar",5+d4());
		return 1;
	}
	return notify_fail("�" + CAP(query_verb()) + " qu�?\n"),0;
}

create() {
::create();
    open = 0;
    SetIntShort("una vieja armer�a");
    SetIntLong("Est�s en algo que parece una armer�a. En esta sala"
    " la decoraci�n cambia ligeramente, se siguen viendo las mismas rocas que hay por "
    "el resto de la mina, pero muchas han sido pulidas para que esta zona sea m�s "
    "habitable.\n Hay algunas armas rotas colocadas en estanter�as de madera y "
    "algunos objetos sin importancia.\n");
    AddDetail(({"estanter�as","estanterias","estanter�a","estanteria"}),
    "Ves unos cuantos trozos de acero destruido, antiguamente ser�an armas pero "
    "parece que ya no quedan cosas de valor, exceptuando un curioso libro rojo.\n");
    AddDetail(({"libro","libro rojo", "curioso libro", "curioso libro rojo"}),
    "Parece que est� sujeto a la estanter�a con alg�n tipo de mecanismo.\n");
    AddExit("oeste",MINA_AZMODAN("mina_1-22"));
    AddExit("sur",MINA_AZMODAN("mina_1-18"));
    AddItem(ARMA_AZMODAN("cimit"),REFRESH_REMOVE,d2());
    if (random(100) < 50)
	{
		switch(random(3))
		{
		    case 0:
		        AddItem(NPC_AZMODAN("orco"),REFRESH_DESTRUCT,1);break;
		case 2:
		    AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,2);
		    break;
		default: break;
		}
	}

}

init()
{
    ::init();
    add_action("coger_cmd","coger");
    add_action("coger_cmd","mover");
    tell_room(MINA_AZMODAN("mina_1-25"), "Escuchas movimiento desde las profundidades de la mina.\n");
}
