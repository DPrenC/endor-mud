/*
DESCRIPCION  : Cementerio
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/narad/cement01.c
MODIFICACION : 15-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

private int fruto;

int inicio(){fruto=1; return 1;}

public int coger_cmd(string str)
{
object ob;

 if ((str=="fruto")||(str=="mandragora"))
 {
    if (fruto==1){
	   write("Arrancas un maloliente fruto de la mandragora.\n");
	   say(NOMBRE+" arranca un fruto de la mandragora.\n");
       ob=clone_object(QUEST+"curandera/mandragora");
       ob->move(TP);
	   call_out("inicio",180);
	   fruto=0;
	   return 1;
	   }
	else return 0;
 }
 return 0;
}

string VerMandragora(){
string s;
  s=  "Junto a una de las tumbas mas alejadas crece una pequenya y retorcida "
      "planta de mandragora. Estas plantas solo crecen en los cementerios junto "
      "a las tumbas, por lo que hay quien dice que necesitan alimentarse de los "
      "restos de los cadaveres para sobrevivir. Es una planta maloliente sin "
      "tallo y con hojas anchas y rugosas. A sus frutos se les atribuyen "
      "propiedades magicas.\n";
  s+=(fruto==1?"Ves un fruto entre las hojas de la mandragora.\n":"");
  return s;
}

create() {
  ::create();
 inicio();

  SetIntShort("el cementerio del pueblo de Narad");
  SetIntLong(
  "Estas en el extremo sur del cementerio rodeado por decenas de silenciosas "
    "tumbas. Esta parte del cementerio esta algo mas descuidada que el resto y "
    "en algunos sitios incluso crece algo de vegetacion. Junto a una de las "
    "tumbas mas alejadas crece una pequenya planta de mandragora.\n");

  AddDetail(({"mandragora","planta"}),SF(VerMandragora));

  AddDetail(({"tumbas","lapidas"}),
    "Las hay por todas partes. Esto es un cementerio.\n");

  AddDetail(({"cementerio","verja","muro"}),
  "El cementerio del pueblo esta rodeado por un muro de piedra y una vieja "
    "verja de metal es la puerta que permite acceder a el.\n");

  AddDetail(({"pueblo","villa","Narad"}),
  "Narad es el nombre de este pueblo. Es un pequenyo pueblo situado "
    "en el suroeste del valle de Azzor, en su parte alta. Sus habitantes "
    "se dedican basicamente a la agricultura y a la destilacion de bebida. "
    "La cerveza y el vino de esta zona son bien conocidos en la region.\n");

 SetIntNoise("Este es un lugar muy tranquilo.\n");
 SetIntSmell("No huele a nada en especial.\n");
 SetLocate("villa de Narad");
 SetIndoors(0);

 AddExit("norte",NARAD("cement00"));

 AddRoomCmd("coger","coger_cmd");
}

