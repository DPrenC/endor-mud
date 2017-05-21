/*
DESCRIPCION  : monton de calaveras
FICHERO      : /d/akallab/comun/objeto/otro/monton_calaveras.c
MODIFICACION : 23-02-99 [Angor@Simauria] Creacion
*/

inherit THING;
#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <config.h> //[a] anayadido por NOTIFY_NOT_CMD
#include <moving.h>

create() {
 ::create();
 seteuid(getuid(TO));
 SetShort("un monton de calaveras");
 SetLong("Es un monton de blancas calaveras apiladas. Te parece reconocer "
           "al menos una de elfo y varias humanas, pero la mayoria parecen "
		   "ser de orcos y troll.\n");
 AddId(({"calaveras","craneos","monton"}));
 AddAdjective("blancas");
 SetWeight(10000);
 Set(P_NOGET,1);
 SetValue(0);
}

init() {
  ::init();
  add_action("coger_cmd","coger");
}

int coger_cmd(string str){
    string raza,que,donde;
	int i;
    object objeto;

	if (!str) return notify_fail("Que es lo que quieres coger?\n",NOTIFY_NOT_VALID)&&0;
    if (sscanf(str,"%s de %s",que,donde)<2) return 0;
    if (((que=="craneo")||(que=="calavera"))&&((donde=="monton")||(donde=="pila"))){

       objeto=clone_object(HUESO_DIR("craneo"));
       //La raza del craneo es aleatoria (10% elfo, 20% humano, 40% orco, 30% troll)
	   i=random(100);
	   raza="troll";
	   if (i<10) raza="elfo";
	   if ((i>=10)&&(i<30)) raza="humano";
	   if ((i>=30)&&(i<70)) raza="orco";
  	   objeto->SetRazaHueso(raza);
	   objeto->move(TP,M_SILENT);
	   write("Coges una de las calaveras de la pila. Por la forma, parece "
	           "ser un craneo de "+raza+".\n");
       return 1;
       }
    return 0;
}


