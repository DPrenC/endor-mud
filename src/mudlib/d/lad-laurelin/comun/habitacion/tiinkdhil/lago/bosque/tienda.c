
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit SHOP;
create(){
  ::create();
  SetIndoors(1);
  SetIntBright(42);
  SetLocate("bosqueDehim");
  SetIntSmell("Huele a viejo.\n");
  SetIntNoise("Oyes susurros en tu oreja.\n");
  SetIntShort("el refugio de Lioua-gan");
  SetIntLong("En este pequeño rincón se esconde Lioua-gan el nigromante. El recinto esta t"
    		"an viejo como la casa salvo que este está cubierto de estanterias llenas de "
    		"pergaminos y cachivaches que reposan llenos de polvo en una mesa. No hay ven"
    		"tanas, pero el antro está iluminado por la luz que desprenden varias lámpara"
    		"s de la pared. Hay esquinas de la habitacion en que ves pasearse raras sombr"
    		"as.\n");
  AddDetail(({"mesa"}),"Puedes listar los objetos que tiene.\n");

  CanBuy(1);
  CanList(1);
  CanSell(1);
  CanShow(1);
  CanAppraise(1);
  CanIdentify(1);
  SetMarket(0);
  SetDustbin();
  SetSecurity(1);
  SetShopkeeper(ALUPNJ("Lioua_gan"));

  AddArticle(ALUOBJ("arma/dagaPl"),REFRESH_DESTRUCT,3);
  AddArticle(ALUOBJ("arma/vara_pl"),REFRESH_DESTRUCT,3);
  AddArticle(ALUOBJ("arma/esp_platag"),REFRESH_DESTRUCT,2);
  AddArticle(ALUOBJ("arma/mangual_pl"),REFRESH_DESTRUCT,2);
  AddArticle(ALUOBJ("arma/luceroPlata"),REFRESH_DESTRUCT,3);
  AddArticle(ALUOBJ("magico/medal_luz"),REFRESH_DESTRUCT,2);
  AddArticle(ALUOBJ("magico/peto_defensa1"),REFRESH_DESTRUCT,1);
  //AddArticle("ALUOBJ("otro/bagua"),REFRESH_DESTRUCT,2);

  AddExit("sur",ALULAGO("bosque/casita"));

}