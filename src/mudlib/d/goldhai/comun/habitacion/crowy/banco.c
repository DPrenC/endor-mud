/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 15-02-97                |
 |               Ultima Modificacion.. 15-02-97                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit BANK;

create(){
    ::create();
    SetIntShort("el banco de Crowy");
    SetIntLong("Estás en el lujoso banco de la ciudad de Crowy, toda la sala está "
    "construida con mármol gris, limpio y brillante.\n La decoración es lujosa "
    "dando buena impresión de poder y seguridad.\n Esta oficina tiene un horario "
    "continuo de 24 horas para satisfacer las necesidades comerciales de la ciudad."
    " Debido a sus horarios especiales, esta oficina tiene las comisiones notablemente "
    "más altas que en otros lugares.\n");
    SetBankName("crowy");
    SetIntBright(40);
    SetIntSmell("Hmm.. no huele a nada especial.\n");
    AddDetail("mostrador",
    "Es un enorme mostrador de mármol gris con adornos de plata.\n");
     AddDetail("banco",
  "Parece grande, pero es producto de una buena decoración. El techo está bastante "
  "alto y todo construido con mármol.\n");
    SetFee(15);
    SetKeeper(PNJ("crowy/alsein"));
    //AddExit("sur",CROWY("taquillas"));
    AddExit("oeste",CROWY("calle2"));
    SetLastDest(CROWY("calle2"));
    SetNotifyExits("fuera");
    SetCloseTime(({}));
    SetLocate("Crowy");
}
