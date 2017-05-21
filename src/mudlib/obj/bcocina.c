inherit "/std/thing";
#include <properties.h>
#define P_CARGAS P_AUX1

public string QueryLong()
{
  string r;
  r="Es una bolsa de cocina normal. Con ella podrás cocinar todos los "
  	"alimentos, ya que tiene todos los utensilios necesarios.\n";

  if (Query(P_CARGAS)==1)
    r+="Sólo puedes cocinar con esta bolsa una vez más.\n";

  else if (Query(P_CARGAS)>1)
    r+="Con esta bolsa puedes cocinar "+itoa(Query(P_CARGAS))+" veces más.\n";
  else
  {
    r+="No puedes cocinar nada más con esta bolsa.\n";
    Set(P_CARGAS, 0);
  }
  return W(r);
}

public string QueryShort()
{
  return "una bolsa de cocina ("+Query(P_CARGAS)+")";
}

create()
{
  ::create();
  SetShort("bolsa de cocina");
  Set(P_CARGAS, 15);
  SetIds(({"bolsa de cocina", "bolsa de cocinero", "bolsa", "cocin-a-matic"}));
  SetWeight(4000);
  SetValue(100+50*Query(P_CARGAS));
  Set(P_SIZE, P_SIZE_MEDIUM);
}

  