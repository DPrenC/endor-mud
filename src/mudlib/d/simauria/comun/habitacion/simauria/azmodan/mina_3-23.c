/***********************************************************/
//	"mina_3-23"
//	Mina abandonada
//	15-12-01 : Creación -> Kodex
//	15-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
inherit STD_AZMODAN("mina");

int open;
public int QueryOpen() { return open; }

public int mover_cmd(string str){
    object secreta = find_object(MINA_AZMODAN("mina_3-25"));
    if(!str)
        return notify_fail("¿" + CAP(query_verb()) + " qué?\n");
    if (str=="antorcha"){
     	if (open){
		    write("Maniobras con la antorcha y la pared del norte se cierra ocultando "
		    "la estancia secreta.\n");
		    say(CAP(TNAME)+" hace algo con la antorcha de la pared y el muro del norte "
		    "se cierra ocultando la estancia secreta.\n");
		    tell_room(secreta, "La salida del sur se cierra dejando este lugar sin salidas.\n");
		    open= 0;
		    secreta->SetOpen(0);
		    RemoveExit("norte");
		    secreta->RemoveExit("sur");
		    return 1;
	    }else{
		    write("Forcejeas con la antorcha y la pared del norte se mueve mostrando "
		    "una entrada secreta.\n");
		    say(CAP(TNAME)+" forcejea con la antorcha de la pared y se abre una "
		    "entrada secreta en el muro del norte.\n");
		    tell_room(secreta, "La pared del sur se abre mostrando una salida hacia allí.\n");
		    open=1;
		    secreta->SetOpen(1);
		    AddExit("norte", MINA_AZMODAN("mina_3-25"));
		    secreta->AddExit("sur", MINA_AZMODAN("mina_3-23"));
		    return 1;
	    }
    }
    return notify_fail("¿" + CAP(query_verb()) + " qué?\n"),0;
}

public string f_descripcion(){
    if(open)
        return "A tu alrededor ves paredes rocosas de la mina, en esta zona los orcos no "
        "han trabajado absolutamente nada, las paredes parecen intactas. Seguramente "
        "lleven así desde hace cientos de años.\n Una antorcha apagada es el único "
        "adorno de este rincón de la mina.\n En la pared del norte se ha abierto una "
        "entrada en la roca hacia una estancia reducida.\n";
        return "A tu alrededor ves paredes rocosas de la mina, en esta zona los orcos no "
        "han trabajado absolutamente nada, las paredes parecen intactas. Seguramente "
        "lleven así desde hace cientos de años.\n Una antorcha apagada es el único "
        "adorno de este rincón de la mina.\n ";
}

create() {
    ::create();
    open=0;
    SetIntShort("la tercera planta de la mina");
    SetIntLong(SF(f_descripcion));

    SetIntBright(30);
    AddDetail("antorcha", "Parece distinta a las demás antorchas que se ven por el resto "
    "de la mina.\n");
    AddExit("oeste",MINA_AZMODAN("mina_3-22"));
    AddExit("sur",MINA_AZMODAN("mina_3-18"));
if (random(100) < 50)
	{
		switch(random(2))
		{
		case 0: AddItem(NPC_AZMODAN("shaman"),REFRESH_DESTRUCT,1);break;
		case 1: AddItem(NPC_AZMODAN("uruk"),REFRESH_DESTRUCT,1);break;
		default: break;
		}
	}

}

init()
{
    ::init();

    add_action("mover_cmd","mover");
    add_action("mover_cmd","girar");
    add_action("mover_cmd","empujar");
    tell_room(MINA_AZMODAN("mina_3-25"), "Escuchas sonidos provenientes de las "
    "profundidades de la mina.\n");
}
