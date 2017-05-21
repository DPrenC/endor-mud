/*
DESCRIPCION : tienda del gremio de conjuratas
FICHERO     : /guilds/conjuradores/seguroqaquivaalgo/tienda.c
MODIFICACION: 31-10-00 [Maler] Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <rooms.h>
#include <door.h>
#include <properties.h>
#include <materials.h>
#include <scheduler.h>
#include <sounds.h>
inherit SHOP;

#define NOMBRE          (TP->QueryName())
#define NOMBRE_M        (capitalize NOMBRE)
#define SUF             (TP->QueryGenderEndString())
#define SUF2            (TP->QueryGender()==2?"a":"e")

create()
 {
  ::create();
 SetIntShort("la tienda del gremio de conjuradores");
  SetIntLong(W(
 "Est�s en la tienda del gremio de conjuradores. Aqu� puedes encontrar "
 "las armas favoritas de este tipo de magos. Las paredes son totalmente blancas, "
 "el color identificativo del gremio. Puedes ver algunos libros y pergaminos en "
 "las estanterias, perfectamente ordenados. Al entrar, Firoldil, el tendero, te saluda.\n"));

 AddDetail(({"tienda","local"}),QueryIntLong());

 AddDetail(({"daga","dagas"}),"Hay una incre�ble variedad de dagas.\n");
 AddDetail(({"cuchillo","cuchillos"}),W(
 "Una incre�ble variedad de cuchillos, los hay de todos los tama�os y formas, cada uno "
 "espec�ficamente dise�ado para una situaci�n determinada.\n"));

 AddDetail(({"pergaminos","libros"}),W(
 "Ves bastantes pergaminos, todos ellos en blanco, asi como libros de hechizos, listos para ser "
 "rellenados por alg�n estudiante nuevo del gremio.\n"));
SetIntNoise(W("No se oye absoultamente nada, como si el ruido cobrase por estar en esta habitaci�n.\n"));
SetIntSmell("Ni siquiera el olor de la muerte se atreve a entrar aqu�.\n");
SetIndoors(1);
SetIntBright(50);

SetNotifyExits("este");
SetLastDest("../gremio");
SetNotifyOpenMsg("Firoldil llega, saluda a Valdemar, abre la tienda y pasa a su interior.\n");
SetNotifyCloseMsg("Firoldil sale de la tienda y cierra tras de s�.\n'Buenas noches maestro', "
                  "-dice saludando a Valdemar.\nRapidamente, sale del gremio y se marcha.\n");
AddExit("este",GCONJURADORES+"gremio");
AddDoor("este", "la puerta de la tienda",
        "Se trata de una puerta de madera sencilla, que comnica la tienda con la habitaci�n "
        "principal del gremio.\n",
        ({"puerta", "puerta de madera", "puerta de la tienda"}), GENDER_FEMALE,
        ([P_MATERIAL : M_MADERA, P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT,
P_DOOR_OPEN_SOUND : SND_SUCESOS("abrir_puerta_campanillas"),
P_DOOR_CLOSE_SOUND : SND_SUCESOS("abrir_puerta_campanillas")]));


CanAppraise(0); //No se valoran objetos
CanIdentify(0); //No se identifican objetos

SetShopkeeper(GCONJURADORES+"/pnj/firoldil");

//articulos a la venta
AddArticle(OBJETO("vara_metal"),REFRESH_REMOVE,2);
AddArticle(OBJETO("daga"), REFRESH_REMOVE,1);
AddArticle(OBJETO("cuchillo"), REFRESH_REMOVE,1);
AddArticle(OBJETO("vara_adamantio"), REFRESH_REMOVE,1);
}

void init()
{
  (::init());

  if (present("Firoldil",TO))
   {
  write("Firoldil te mira al entrar en la tienda: 'Hola, bienvenid"+SUF+" a mi tienda.\n");

  say(  "Firoldil saluda a "+NOMBRE_M+" cuando est"+SUF2+" entra en la tienda.\n",TP);

  }
}

