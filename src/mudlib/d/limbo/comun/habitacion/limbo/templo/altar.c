/*
DESCRIPCION  : Altar del Templo de Asthar.
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/altar.c
BASADO       : froffice.c (NightFall)
MODIFICACION :

13-12-96 [Angor@Simauria] Creacion.
07-02-98 [Angor@Simauria] Version operativa
30-09-98 [Angor@Simauria] Algunos arreglos
26-10-98 [Angor@Simauria] Ahora Asthar resucita a los muertos
11-11-98 [Angor@Simauria] Eliminado el bug que hacia que si se llevaban armas
         empunyadas al transformarse se mantuviesen asi pese a que los brazos
         se destruian y se sustituian por los de la nueva raza (vacios y por
         tanto donde se podian empunyar mas armas). Ahora se desempunya todo
         antes de la transformacion.
24-03-99 [Angor@Simauria] wrapeadoks
10-10-99 [Woo] Toqueteado... Ahora ademas, no se puede hacer magia aqui.
14-06-01 [Nyh] Hago que tampoco eliga las razas que terminan en quest

--------------------------------------------------------------------------------
*/

#include "/d/limbo/sys/limbo.h"
#include <colours.h>
#include <moving.h>

inherit ROOM;

#include <wizlevels.h>
#include <living.h>

#define AO      (TP->QueryGenderEndString())
#define NOMBRE  (capitalize(TP->QueryName()))

public string *QueryRacenames()
{
  string *rn;

  rn =  (string *) RACEMASTER->AllPlayerRaceNames();
  rn -= regexp(rn,"vampire$|^visitor$|^slave$|quest$");
  // these races should not occur in any list and the player should not
  // be able to morph into them
  // Don't change the "vampire$"-regexp! It's written as it is meant. All
  // races which end on "vampire" should not occur in the list
  return rn;
}

//--------------------------------------------------------------------------------
public int resucitar_cmd(){
  if (!(TP->QueryGhost()))
  return notify_fail(
      "Asthar te dice: Como voy a resucitarte si ya estas viv"+AO+"!\n",NOTIFY_NOT_VALID)&&0;
  write("Asthar cierra los ojos y se concentra. Murmura un extranyo sortilegio y un halo "
        "fantasmal comienza a rodearle. De repente notas como una poderosa fuerza absorbe "
        "tu espíritu y al instante reapareces en forma sólida.\n");
  TP->SetGhost(0);
  say("Un halo fantasmal rodea Asthar mientras hace resucitar a "+TP->QueryName()+".\n");
  return 1;
}


//--------------------------------------------------------------------------------
public create()
{
  ::create();
  SetIntShort("el templo de Asthar");

 AddDetail(({"plataforma"}),
  W("Te hallas sobre una plataforma elevada sobre el nivel del suelo del "
    "templo. En su centro se halla en altar del templo. La plataforma esta "
    "construida con bloques de marmol negro pulidos como si fuesen un "
    "espejos.\n"));

AddDetail(({"altar","mesa"}),
 W("El altar es una especie de mesa formada por una gruesa lamina de metal "
   "montada sobre un robusto soporte de piedra. Es el lugar donde Asthar "
   "realiza las transformacciones que permiten cambiar las forma de un cuerpo "
   "o permitir que un espiritu pueda encarnarse.\n"));

AddDetail(({"soporte","robusto soporte"}),
 "Forma parte del altar y su funcion es la de soportar la plancha de metal.\n");

AddDetail(({"plancha","plancha de metal"}),
 "Forma parte del altar y sobre ella se colocan los cuerpos a transformar.\n");

AddDetail(({"templo","habitacion"}),QueryIntLong());

SetIntNoise("Oyes el ruido de las olas chocando contra los acantilados.\n");
SetIntSmell("Hmm.. el aire es fresco y limpio.\n");
SetLocate("isla Limbo");
SetIndoors(1);
SetIntBright(50);
AddExit("norte",TEMPLO("templo04"));
AddExit("este",TEMPLO("templo07"));
AddExit("oeste",TEMPLO("templo06"));
AddRoomCmd("resucitar","resucitar_cmd");

AddItem(PNJ("asthar"));
ForbidAllMagic();

}

QueryIntLong()
{
return
  W("Te encuentras sobre una plataforma elevada sobre el suelo del templo en "
    "cuyo centro se halla el altar y tras él, Asthar. A este fiel siervo de "
    "los dioses le fueron revelados los antiguos conocimientos que permiten "
    "resucitar a los que han muerto en este mundo.\n");
 }
