#include "path.h"
#include <nightday.h>

inherit DOM_STD+"tienda";

int cmd_dar(string str)
{
  object pluma1, pluma2, pluma3, *inv, cascara;
  string name;
  int i, num,npl;

  if (!present("ralin")) return 0;

  if (str!="pluma a ralin" && str!="pluma a elfo" && str!="pluma a Ralin" &&
  	str!="plumas a ralin" && str!="plumas a Ralin")
    return 0;

  if (QUESTMASTER->QueryQuestSolved("plumas_de_wyvelt", TI))
  {
    write("Ralin te dice: Pero si ya me las distes, ¿no lo recuerdas?\n");
    return 1;
  }

  inv=all_inventory(TI);
  npl=0;
  for (i=0; i<sizeof(inv); i++)
  {
    if (object_name(efun::blueprint(inv[i]))=="/d/lad-laurelin/comun/quest/pluma")
    {
      name=inv[i]->Query("from");
      if (name=="lad laurelin") pluma1=inv[i];
      else if (name=="goldhai") pluma2=inv[i];
      else if (name=="akallab") pluma3=inv[i];
    }
    if (object_name(efun::blueprint(inv[i]))=="/d/lad-laurelin/comun/quest/cascara")
      cascara=inv[i];
  }
  if (!pluma1 && !pluma2 && !pluma3)
    return 0;

  num=objectp(pluma1)+objectp(pluma2)+objectp(pluma3);

  if (num==1)
  {
    write(W("Ralin te dice: Vaya, veo que tienes una de las plumas de Wyvelt en tu poder... "
    	"Vuelve cuando tengas las tres que necesito.\n"));
    return 1;
  }
  if (num==2)
  {
    write(W("Ralin te dice: ¡Enhorabuena! Tan sólo te falta una pluma para completar el trío "
    	"y poder regalárselas a mi esposa."));
    return 1;
  }

  write(W("¡Gracias por encontrar las plumas! Ahora podré hacerle el regalo "
  	"a mi esposa que siempre quise hacerle!\n"));
  say(W(capitalize(TI->QueryName())+" le tres plumas a "
    	"Ralin.\n"));

  QUESTMASTER->SetPlayerQuest("plumas_de_wyvelt",TI);
  QUESTMASTER->InformSolution(""+capitalize(TI->QueryName())+" ha encontrado las plumas de Wyvelt para Ralin.\n");

  pluma1->remove();
  pluma2->remove();
  pluma3->remove();

  if (cascara)
  {
    write(W("Anda, además has encontrado un trozo de la cáscara del huevo de "
      "un Wyvelt... Si quieres hacerte una buena armadura llévaselo a mi "
      "esposa. Está en la habitación de al lado. ¡Y no le digas nada de las "
      "plumas, será una sorpresa!\n"));
  }

  return 1;
}


create()
{
  ::create();
  SetIntLong(W("Estás en una tienda de armaduras. La tienda está dividida en "
  	"dos mitades. En esta zona se venden armaduras de todo tipo, y en "
  	"la habitación contígua pueden repararlas e incluso ensancharlas a tu "
  	"medida. Esta parte de la tienda la regenta Ralin, el esposo de "
  	"Aleet.\n"));

  SetIntShort("la tienda de venta de armaduras");
  SetIntNoise("El murmullo de la ciudad es aquí un poco más tenue.\n");

  AddDetail(({"estantería", "estanteria", "estanterías", "estanterias",
  	"estante", "estantes"}), W("En los estantes es donde está toda "
  	"la mercancía en venta.\n"));

  SetShopkeeper(PNJ("atbalnin/ciudad/ralin"));

  AddArticle(PROT("botas-metal"), REFRESH_REMOVE, 3);
  AddArticle(PROT("casco"), REFRESH_REMOVE, 3);
  AddArticle(PROT("coraza-cuero-claveteado"), REFRESH_REMOVE, 3);
  AddArticle(PROT("coraza-malla"), REFRESH_REMOVE, 2);
  AddArticle(PROT("guantes"), REFRESH_REMOVE, 2);
  AddArticle(PROT("escudo"), REFRESH_REMOVE, 4);
  AddArticle(PROT("guantes-metal"), REFRESH_REMOVE, 2);
  AddArticle(PROT("tunica"), REFRESH_REMOVE, 2);
  AddArticle("/obj/mochila", REFRESH_REMOVE, 2);
  AddArticle("/obj/vial", REFRESH_REMOVE, 3);
  AddArticle("/obj/vialv", REFRESH_REMOVE, 5);
  AddArticle("/obj/vialm", REFRESH_REMOVE, 5);

  AddRoomCmd("dar", SF(cmd_dar));

  AddExit("salir", ATB_CI("ciudad23"));
  AddExit("herreria", ATB_TI("herreria02"));
  //HideExit("herreria",1);
  //AddExit("herrería", ATB_TI("herreria02"));
}


