/***********************************************************/
//	"mina_scyla"
//	La habitación donde está la espada 'scyla'
//	Mina abandonada
//	18-12-01 : Creación -> Kodex
//	18-12-01 : Modificación -> Kodex
// 21-12-07 Ratwor: no tiene salidas porque esta room se abre al picar en mina_3-16
//
#include "./path.h"
#include <colours.h>
inherit STD_AZMODAN("mina");
int open;
public int QueryOpen() { return open; }
public int SetOpen(int estado) { return open= estado; }

public void mover(){
	TP->move(LABERINTO_AZMODAN(0));
	TP->LookAfterMove();
}

coger_cmd(string str){
	if (!str) return 0;
	write(TC_BOLD+TC_RED+"¡¡El suelo cede bajo tus pies!!\n"+TC_NORMAL);
	say("¡El suelo cede bajo los pies de "+capitalize(TP->QueryRealName())+"!\n");
	call_out("mover",1);
	return 0;
}

public string f_descripcion(){
    if(!open)
        return "Te encuentras en un pequeño agujero oculto en cualquier parte de "
        "estas minas. La estancia es incómoda y las escarpadas rocas que te rodean "
        "no ayudan. Todo a tu alrededor es roca y no tienes ninguna salida.\n";
        return "Te encuentras en un pequeño agujero oculto en cualquier parte de "
        "estas minas. La estancia es incómoda y las escarpadas rocas que te rodean "
        "no ayudan. Todo a tu alrededor es roca y sólo puedes salir por un pequeño "
        "agujero que hay sobre tu cabeza.\n";
}

create() {
object vaina;
    ::create();
        open=0;
    SetIntShort("un agujero oculto");
    SetIntLong(SF(f_descripcion));
    SetMaxIntWeight(400000); // Es un sitio muy pequeño.
    AddDetail(({"roca", "rocas", "pared", "paredes"}), "Todo a tu alrededor es pura roca.\n");
    vaina = clone_object(OBJETO_AZMODAN("vaina"));
    AddItem(vaina,REFRESH_REMOVE,1);
    vaina->AddItem(ARMA_AZMODAN("scyla"));
    AddExit("abajo", (:write("¿De verdad quieres seguir bajando?\n"); return 1;:));
    HideExit("abajo",1);
}

init()
{
    ::init();
    add_action("coger_cmd","coger");
}
