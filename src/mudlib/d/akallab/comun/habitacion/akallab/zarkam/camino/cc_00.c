/*
DESCRIPCION  : Cruce del Sendero de los Cráneos y camino a Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/cc_00.c
MODIFICACION : 20-05-97 [Angor@Simauria] Creacion.
               05-10-98 [Angor@Simauria] Varias modificaciones
               29-10-98 [Chaos] Modificado para el portal
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>


inherit ROOM;

private static object objeto;

public int leer_cmd(string str)
{
 if (!str) return notify_fail("Que es lo que quieres leer?\n",NOTIFY_NOT_VALID);

 if ((str=="textos")||(str=="tablones")||("letreros"))
 {
    write(" Al norte, Ciudad de Zarkam.\n Al este, tierras de cultivo y paso "
          "de Akkbar.\n Al sur, Garganta de Sharg.\n");
    return 1;
 }
}


public int coger_cmd(string str)
{
 string raza;
 int i;
 object objeto;

 if (!str) return notify_fail("Que es lo que quieres coger?\n",NOTIFY_NOT_VALID)&&0;
 if ((str=="calavera")||(str=="craneo"))
 {
 objeto=clone_object(HUESO_DIR("craneo"));

 //La raza del craneo es aleatoria (20% elfo, 30% orco, 50% humano)
 i=random(10);
 raza="humano";
 if (i<=1) raza="elfo";
 if (i>=7) raza="orco";

 objeto->SetRazaHueso(raza);
 objeto->move(TP,M_SILENT);

 write("Tras forcejear un rato con las calaveras clavadas en el poste, consigues "
       "arrancar una de ellas. Por la forma, parece ser un craneo de "+raza+".\n");
 return 1;
 }
}


create() {
  object portal;
  ::create();
  SetIntShort("un cruce en el Sendero de los Cráneos al sur de Zarkam.");
  SetIntLong(
     "Has llegado a un cruce en el Sendero de los Cráneos. En este punto del Sendero "
     "se separa de el un camino que conduce hacia el este, probablemente hacia los "
     "campos de cultivo que se observan en el fondo del valle. El Sendero asciende "
     "suavemente desde aqui hasta la ciudad de Zarkam al norte. Junto al cruce hay "
     "un poste con varias calaveras clavadas en el, ademas de varios viejos letreros. "
     "El paisaje es austero, y el viento sopla con fuerza desde el sureste.\n");

  AddDetail(({"poste","letrero","poste con un letrero","poste con calaveras"}),
     "Junto al cruce hay clavado en el suelo, un poste indicador. En el se encuentran "
     "varios viejos tablones en los que hay tallados textos que indican hacia que "
     "lugar conduce cada camino. Deberias leerlo. Clavados en el extremo del poste se "
     "encuentran varios cráneos, posiblemente de enemigos muertos.\n");

  AddDetail(({"calaveras","cráneos"}),
     "Sobre el poste indicador se encuentran clavadas varias calaveras. Te parece "
     "reconocer al menos una de elfo y varias humanas. Pero no todo son cráneos de "
     "enemigos muertos, ya que parece que tambien hay varios cráneos orcos entre "
     "ellos. Esta gente no se anda con bromas incluso con los de su misma raza. La "
     "vision del conjunto es bastante inquietante.\n");

  AddDetail(({"Sendero","sendero","Sendero de los Cráneos","sendero de los cráneos"}),
     "El Sendero de los Cráneos es la mas importante via de comunicacion en la "
     "peninsula orca que recorre de norte a sur serpenteando a traves de altas "
     "cordilleras y profundos acantilados. Los esclavos capturados por los orcos en la "
     "guerra han sido obligados a construirlo para mayor gloria del Emperador orco. "
     "Los huesos de aquellos que han dejado su vida en esta construccion se mezclan "
     "con el pavimento y sus cráneos estan clavados en altos postes junto al camino "
     "como advertencia a cualquiera que pretenda enfrentarse al imperio orco...\n");

  AddDetail(({"ciudad","ciudad fortificada","Zarkam","zarkam"}),
     "En medio del valle y sobre una loma se alza la ciudad fortificada de Zarkam. Es "
     "una poblacion de mediano tamanyo que se halla totalmente rodeado por una alta "
     "muralla de piedra. Desde el exterior, lo unico que se puedes ver de la ciudad es "
     "una alta torre que se alza sobre la muralla y en la que siempre hay vigias por "
     "si aparecen enemigos. Seguro que vigilan tus movimientos desde que entraste en "
     "este valle... No hay duda que esta gente esta acostumbrada a la guerra.\n");

  SetIntNoise("Oyes el aullido del fuerte viento a traves de los desfiladeros.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
  AddExit("suroeste",Z_CAMINO("cc_05"));
  AddExit("norte",Z_CAMINO("cc_01"));
  AddExit("este",Z_CAMINO("ce_00"));
  AddRoomCmd("leer","leer_cmd");
  AddRoomCmd("coger","coger_cmd");

  portal=clone_object("obj/monolito");
  portal->SetRaza("kainoak");
  portal->move(TO);
}
