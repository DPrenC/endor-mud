/***********************************************************/
//	"mina_2-01"
//	Mina abandonada
//	14-12-01 : Creación -> Kodex
//	14-12-01 : Modificación -> Kodex
// 14-12-07 Ratwor: Esta room se queda sin salida por orden de mina_2-03, la pared se
// cierra automaticamente. Así que no es un error.
//

#include "./path.h"
inherit STD_AZMODAN("mina");
int open;
public int QueryOpen() { return open; }
public int SetOpen(int estado) { return open= estado; }

public string f_paredes(){
    if(!open)
        return "Son de pura roca con salientes, como el resto de estas minas, aunque estas están "
    "manchadas de rojo.\n La pared por la que has entrado se encuentra bien cerrada y "
    "es posible que sólo se abra desde fuera.\n";
        return "Son de pura roca con salientes, como el resto de estas minas, aunque estas están "
        "manchadas de rojo. En la pared del norte se ha abierto una salida en la roca.\n";
}

public string f_descripcion(){
    if(!open)
        return "Te encuentras en una habitación secreta, donde  hay unas "
        "estanterías vacías con vasijas rotas.\n  Unas pinturas de color rojo adornan las "
        "paredes, parecen escritas con sangre.\n Hay objetos extraños por el suelo.\n"
        " El mecanismo para abrir esta habitación secreta se encuentra fuera, con lo "
        "que necesitarás a alguien que lo vuelva a activar para que puedas salir de aquí.\n";
        return "Te encuentras en una habitación secreta, donde  hay unas "
        "estanterías vacías con vasijas rotas.\n  Unas pinturas de color rojo adornan las "
        "paredes, parecen escritas con sangre.\n Hay objetos extraños por el suelo.\n"
        " la pared del norte tiene una apertura en la roca para salir de esta "
        "estancia, lo cual deberías de hacer cuanto antes.\n ";
}

create() {
    ::create();
        open=0;
    SetIntShort("una habitación secreta");
    SetIntLong(SF(f_descripcion));

    AddDetail(({"pared", "paredes"}), SF(f_paredes));
    AddDetail(({"objetos","objetos extraños"}),
    "Unos utensilios poco comunes, es posible que los usen los shamanes"
    ", están muy deteriorados y no valen para nada.\n");
    AddItem(OBJETO_AZMODAN("aguja"),REFRESH_REMOVE,d4());
    AddExit("abajo", (:write("¿De verdad quieres seguir bajando?\n"); return 1;:));
    HideExit("abajo",1);
    SetExplorable(1);
}
