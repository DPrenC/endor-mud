/***********************************************************/
//	"mina_2-01"
//	Mina abandonada
//	14-12-01 : Creaci�n -> Kodex
//	14-12-01 : Modificaci�n -> Kodex
// 14-12-07 Ratwor: Esta room se queda sin salida por orden de mina_2-03, la pared se
// cierra automaticamente. As� que no es un error.
//

#include "./path.h"
inherit STD_AZMODAN("mina");
int open;
public int QueryOpen() { return open; }
public int SetOpen(int estado) { return open= estado; }

public string f_paredes(){
    if(!open)
        return "Son de pura roca con salientes, como el resto de estas minas, aunque estas est�n "
    "manchadas de rojo.\n La pared por la que has entrado se encuentra bien cerrada y "
    "es posible que s�lo se abra desde fuera.\n";
        return "Son de pura roca con salientes, como el resto de estas minas, aunque estas est�n "
        "manchadas de rojo. En la pared del norte se ha abierto una salida en la roca.\n";
}

public string f_descripcion(){
    if(!open)
        return "Te encuentras en una habitaci�n secreta, donde  hay unas "
        "estanter�as vac�as con vasijas rotas.\n  Unas pinturas de color rojo adornan las "
        "paredes, parecen escritas con sangre.\n Hay objetos extra�os por el suelo.\n"
        " El mecanismo para abrir esta habitaci�n secreta se encuentra fuera, con lo "
        "que necesitar�s a alguien que lo vuelva a activar para que puedas salir de aqu�.\n";
        return "Te encuentras en una habitaci�n secreta, donde  hay unas "
        "estanter�as vac�as con vasijas rotas.\n  Unas pinturas de color rojo adornan las "
        "paredes, parecen escritas con sangre.\n Hay objetos extra�os por el suelo.\n"
        " la pared del norte tiene una apertura en la roca para salir de esta "
        "estancia, lo cual deber�as de hacer cuanto antes.\n ";
}

create() {
    ::create();
        open=0;
    SetIntShort("una habitaci�n secreta");
    SetIntLong(SF(f_descripcion));

    AddDetail(({"pared", "paredes"}), SF(f_paredes));
    AddDetail(({"objetos","objetos extra�os"}),
    "Unos utensilios poco comunes, es posible que los usen los shamanes"
    ", est�n muy deteriorados y no valen para nada.\n");
    AddItem(OBJETO_AZMODAN("aguja"),REFRESH_REMOVE,d4());
    AddExit("abajo", (:write("�De verdad quieres seguir bajando?\n"); return 1;:));
    HideExit("abajo",1);
    SetExplorable(1);
}
