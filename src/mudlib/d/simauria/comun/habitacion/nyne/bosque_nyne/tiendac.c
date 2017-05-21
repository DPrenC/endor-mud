#include "path.h"
#include <scheduler.h>
inherit SHOP;
create(){
    ::create();

    SetLocate("Bosque de Nyne");

    SetIndoors(0);
    SetIntBright(20);
    SetSunBright(MAX_SUNBRIGHT / 2);
    SetIntSmell("Huele a una rara combinación de especias..."
               " Debe ser lo que está fumando el tendero.\n");
    SetIntNoise("En esta zona el bullicio es ligeramente menor que fuera.\n");
    SetIntShort("la tienda de contrabandistas del bosque de Nine");

    RemoveDustbin();
    RemoveExit("almacen");
    SetCloseTime(({ND_NO_STATES}));
    SetMarket(0);
    SetSecurity(1);
    CanAppraise(1);
    CanBuy(1);
    CanIdentify(0);
    CanList(1);
    CanSell(1);
    CanShow(1);
    ForbidAllMagic();
    AddRoomCmd("matar","_matar");
}

int _matar(string str)
{
 if (!str) return 0;
 else {
 write("Hechas mano de tu arma para darle lo suyo a "+str+".\n");
 write("El sonido de un arco tensándose hace que te lo pienses dos veces.\n");
 write("Este no es buen lugar para empezar una pelea.\n");
 return 1;
 }
}

