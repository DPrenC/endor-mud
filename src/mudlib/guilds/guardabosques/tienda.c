#include "path.h"
#include "/secure/wizlevels.h"
#include <rooms.h>
#include <guild.h>
#include <scheduler.h>
#include <properties.h>
#include <door.h>
#include <materials.h>
#include <sounds.h>

inherit "/std/shop";


//Todo está un 15% más barato...
public int ModifyPrice(object ob, int price, string verb)
{
  if (TP->QueryGuild()!=GC_GUARDABOSQUES) return ::ModifyPrice(ob, price, verb);
  return (::ModifyPrice(ob, price, verb)*85)/100;
}

create()
{
  ::create();
  SetIntLong(W("Estás en la tienda del Gremio de los Guardabosques. Aquí se venden "
  	"varios artículos, todos ellos bastante corrientes. Sin embargo, la "
  	"ventaja que tiene es que los artículos están rebajados si eres "
  	"un miembro del gremio.\nLa tienda regenta Khled, un humano bastante "
  	"mayor.\n"));
  SetIntShort("la tienda de Khled");
  SetLocate("el gremio de los Guardabosques");
  AddDetail(({"estantería", "estanteria", "estanterías", "estanterias",
  	"estante", "estantes"}), W("Un poco por todos sitios puedes ver el "
 	"desorden reinante en el lugar... Los objetos se amontonan por donde "
 	"pueden en unas resistentes estanterías de madera, las cuales carecen "
 	"totalmente de cualquier ornamento.\n"));
  ForbidShopkeeper();
  SetLastDest("./gremio");
  SetNotifyExits("norte");
  SetNotifyOpenMsg("Khled llega, abre la tienda y pasa a su interior.\n");
  SetNotifyCloseMsg("Khled cierra la tienda del gremio y se marcha.\n");




  AddDetail(({"tendero", "Khled"}), "Es un humano bastante mayor.\n");
    AddArticle("/obj/bcocina", REFRESH_REMOVE, 5);
    AddArticle(OBJETO("vialv"), REFRESH_REMOVE, 10);
    AddArticle(OBJETO("vialm"), REFRESH_REMOVE, 10);
    AddArticle(OBJETO("vial"), REFRESH_REMOVE, 5);
    AddArticle(OBJETO("mochila"), REFRESH_REMOVE, 4);
    AddArticle(OBJETO("mochilac"), REFRESH_REMOVE, 2);
    AddArticle(OBJETO("botas"), REFRESH_REMOVE, 2);
    AddArticle(OBJETO("capa"), REFRESH_REMOVE, 2);
    AddArticle(OBJETO("casco"), REFRESH_REMOVE, 2);
    AddArticle(OBJETO("coraza-cuero-claveteado"), REFRESH_REMOVE, 2);
    AddArticle(OBJETO("coraza-piel"), REFRESH_REMOVE, 3);
    AddArticle(OBJETO("escudo"), REFRESH_REMOVE, 2);
    AddArticle(OBJETO("espada-2manos-acero"), REFRESH_REMOVE, 1);
    AddArticle(OBJETO("espada-2manos"), REFRESH_REMOVE, 2);
    AddArticle(OBJETO("espada-acero"), REFRESH_REMOVE, 2);
    AddArticle(OBJETO("espada-corta-acero"), REFRESH_REMOVE, 1);
    AddArticle(OBJETO("espada-corta"), REFRESH_REMOVE, 2);
    AddArticle(OBJETO("espada-larga"), REFRESH_REMOVE, 2);
    AddArticle(OBJETO("guantes"), REFRESH_REMOVE, 2);
    AddArticle(OBJETO("guantes-piel"), REFRESH_REMOVE, 3);
    AddArticle(OBJETO("pantalones"), REFRESH_REMOVE, 2);
    AddArticle(OBJETO("pantalones-piel"), REFRESH_REMOVE, 2);
    AddArticle(OBJETO("tunica"), REFRESH_REMOVE, 3);
    AddArticle(OBJETO("vara"), REFRESH_REMOVE, 1);
    AddArticle(OBJETO("manzana"), REFRESH_REMOVE, 8);
    AddArticle(OBJETO("redoma"),REFRESH_REMOVE,3);
    AddArticle(OBJETO("mortero"),REFRESH_REMOVE,3);
    AddArticle(OBJETO("hierbas"),REFRESH_REMOVE,5);

  SetShopkeeper(PNJ("khled"));
  AddExit("norte", BASE+"gremio");
  AddDoor("norte", "la puerta de la tienda",
          "Es la puerta que comunica la tienda con la habitación principal del gremio de "
          "guardabosques. Es una puerta de madera sencilla, adornada con dibujos de hojas "
          "talladas en ella.\n",
          ({"puerta", "puerta de madera", "puerta del gremio", "puerta de la tienda"}),
          GENDER_FEMALE, ([P_MATERIAL:M_MADERA, P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT,
P_DOOR_OPEN_SOUND : SND_SUCESOS("abrir_puerta_campanillas"),
P_DOOR_CLOSE_SOUND : SND_SUCESOS("abrir_puerta_campanillas")]));

  RemoveExit("almacen");
}
