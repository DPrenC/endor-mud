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
    SetIntLong("Est�s en el lujoso banco de la ciudad de Crowy, toda la sala est� "
    "construida con m�rmol gris, limpio y brillante.\n La decoraci�n es lujosa "
    "dando buena impresi�n de poder y seguridad.\n Esta oficina tiene un horario "
    "continuo de 24 horas para satisfacer las necesidades comerciales de la ciudad."
    " Debido a sus horarios especiales, esta oficina tiene las comisiones notablemente "
    "m�s altas que en otros lugares.\n");
    SetBankName("crowy");
    SetIntBright(40);
    SetIntSmell("Hmm.. no huele a nada especial.\n");
    AddDetail("mostrador",
    "Es un enorme mostrador de m�rmol gris con adornos de plata.\n");
     AddDetail("banco",
  "Parece grande, pero es producto de una buena decoraci�n. El techo est� bastante "
  "alto y todo construido con m�rmol.\n");
    SetFee(15);
    SetKeeper(PNJ("crowy/alsein"));
    //AddExit("sur",CROWY("taquillas"));
    AddExit("oeste",CROWY("calle2"));
    SetLastDest(CROWY("calle2"));
    SetNotifyExits("fuera");
    SetCloseTime(({}));
    SetLocate("Crowy");
}
