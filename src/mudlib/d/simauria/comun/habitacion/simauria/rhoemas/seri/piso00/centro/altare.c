/***************************************************************************************
 ARCHIVO:	altare.c
 AUTOR:		[z] Zomax
 FECHA:		10-01-2002
 COMENTARIOS:	Uno de los altares del templo
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, planta baja");
  SetIntShort("un altar");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntLong(W("Est�s en una peque�a habitaci�n muy adornada llena de tapices y alfombras "
  	"que destacan por la austeridad del resto de este piso del templo. Parece que es "
  	"uno de los lugares de culto a la diosa Xaenetia, en quien est� erigido el templo. "
  	"Hay una gran losa de m�rmol blanco con un peque�o hueco en el centro donde se "
  	"depositan las ofrendas quemando incienso.\n"));
  
  AddDetail(({"altar"}),W("Es un maravilloso altar muy bien adornado con alfombras a "
  	"su alrededor y una gran losa blanca en medio donde se realizan las ofrendas.\n"));
  AddDetail(({"tapiz","tapices"}),W("No consigues fijarte en uno solo, hay demasiados, a "
  	"cada cual m�s complicado y a la vez precioso.\n"));
  AddDetail(({"alfombra","alfombras"}),W("Al igual que los tapices puedes ver varias "
  	"alfombras individuales en el suelo para que los preregrinos recen sobre ellas.\n"));
  AddDetail(({"losa","marmol","m�rmol","hueco"}),W("Una enorme y pesada losa de m�rmol "
  	"blanco en el centro de la habitaci�n. Justo en el mismo centro de la losa "
  	"hay un peque�o hueco donde se quema incienso.\n"));
  AddDetail(({"pared","paredes"}),W("Las paredes est�n hechas de piedra y tienen unos "
  	"bonitos tapices que las adornan con gran acierto. No parece el mismo templo, en "
  	"comparaci�n con los pasillos de este piso.\n"));
  AddDetail(({"suelo","techo"}),W("Est� hecho de piedras formando dibujos muy extra�os en el "
  	"centro.\n"));
  AddDetail(({"dibujos extranyos","dibujos extra�os","dibujos","dibujo","dibujo extra�o","dibujo extranyo"}),W(
  	"El suelo forma extra�os dibujos en el centro de la sala. Parece que s�lo decorativos.\n"));
  AddRoomCmd("quemar","fquemar");
  AddRoomCmd("rezar","frezar");
  AddItem(RHOEPNJ("seri/peregrino"),1,2+random(6));
  AddExit("oeste",RHOEHAB("seri/piso00/centro/pasillo_03")); 
}

int fquemar(string str)
{
	   if (!str) return notify_fail("�Quemar qu�?\n",NOTIFY_NOT_VALID);
	   if (str=="incienso")
	   {
	       if (present("incienso",TP))
	       {
    		      write("Quemas un poco de incienso en el altar para purificar tu alma. Te sientes "
  		            "mejor contigo mism"+AO+"\n");
      		    say(CATP+" quema un poco de incienso en el altar.\n",TP);
  		        present("incienso",TP)->fmenos();
     		     if (TP->QuerySP()<(TP->QueryMaxSP())-5) TP->AddSP(5);
  		        else TP->SetSP(TP->QueryMaxSP());
      		    return 1;
    	   }
    	   return notify_fail("No tienes incienso para quemar.\n",NOTIFY_NOT_VALID);
	   }
    return notify_fail("�No se te ocurre nada mejor?\n",NOTIFY_NOT_VALID);
}

int frezar(string str)
{
	write("Rezas una corta oraci�n a la diosa Xaenetia.\n");
	say(W(CATP+" reza una corta oraci�n a la diosa Xaenetia.\n"),TP);
	return 1;
}
