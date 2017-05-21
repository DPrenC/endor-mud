/***********************************************************/
//	"mina_3-25"
//	Mina abandonada
//	15-12-01 : Creación -> Kodex
//	15-12-01 : Modificación -> Kodex
//22-12-07 Ratwor: Esta room se abre o se cierra desde mina_3-23, así que no es un bug que no tenga salidas.
//
#include "./path.h"
inherit STD_AZMODAN("mina");
int open;
public int QueryOpen() { return open; }
public int SetOpen(int estado) { return open= estado; }

public string f_descripcion(){
    if(open)
        return "Te encuentras en una siniestra habitación secreta en la tercera planta "
        "de la mina.\n Multitud de objetos extraños y deteriorados se encuentran "
        "esparcidos por todo el suelo.\n Las paredes se encuentran algo más "
        "ennegrecidas que en el resto de la mina.\n La única salida de este lugar está "
        "al sur abierta en la roca.\n";
        return "Te encuentras en una siniestra habitación secreta en la tercera planta "
        "de la mina.\n Multitud de objetos extraños y deteriorados se encuentran "
        "esparcidos por todo el suelo.\n Las paredes se encuentran algo más "
        "ennegrecidas que en el resto de la mina.\n";
}

public string f_paredes(){
    if(!open)
        return "Son de pura roca con salientes, como el resto de estas minas, aunque estas están "
    "algo negras.\n";
        return "Son de pura roca con salientes, como el resto de estas minas, aunque estas están "
        "algo negras. En la pared del sur se ha abierto una salida en la roca.\n";
}

create() {
    ::create();
        open=0;
    SetIntShort("una habitación secreta");
    SetIntLong(SF(f_descripcion));
    AddDetail(({"pared", "muro", "paredes", "muros"}), SF(f_paredes));
    AddDetail(({"objetos","objetos extraños"}),
    "Unos utensilios poco comunes, es posible que los usen los shamanes, "
    "están muy deteriorados y no valen para nada.\n");
    AddItem(OBJETO_AZMODAN("voodoo"),REFRESH_REMOVE,1);
    AddExit("abajo", (:write("¿De verdad quieres seguir bajando?\n"); return 1;:));
    HideExit("abajo",1);
}
