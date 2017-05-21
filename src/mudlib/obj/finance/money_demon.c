/**
 * SIMAURIA '/obj/money_demon.c'
 *
 */

/*  This object keeps track of how much each type of coin is worth
 *  So be nice to it ;-)
 */

#include <money.h>

#define DEF_WEIGHT  8

/*
#define MONEY_VALUE    0
#define MONEY_SHORT    1
#define MONEY_LONG     2
*/
// cointypes: ([ nombre: valor; short; long ])
private mapping cointypes = ([
    "mithril": 5000; "mt"; "Admiras la belleza de la moneda y el perfecto acabado de las lineas...\nSiempre cambiantes, forman dos dibujos: un caballo alado y una isla por una\nparte y las letras 'SIMAURIA' y una torre en la otra.\n",
    "platino": 1000; "pt"; "Tienes entre tus manos lo que es una de las monedas mas bellas jamas creadas.\nEn una cara ves el contorno del mapa de Simauria y al girarla ves una estatua\nde una extranya criatura... No se parece a nada de lo que hayas conocido...\n",
    "oro":      100; "or"; "Aunque es una moneda un tanto tosca adviertes la belleza del material con\nla que esta confeccionada. En una cara ves El Limbo y al girarla ves un\ncaballo alado.\n",
    "plata":     10; "pl"; "Es una simple moneda de plata bastante gastada...\nEn una de las caras ves una torre y en la otra una 'S' ensartada en\nuna espada.\n",
    "cobre":      1; "co"; "Es una vulgar y simple moneda de cobre. En una cara ves una torre\ny en la otra ves una 'S'.\n",
                            ]);

/* To be able to 'update' the money_demon */
remove() { destruct(TO); return 1; }

/* Just to export the current settings */
public mapping QueryCoinTypes() { return (mapping) copy(cointypes); }
public string* QueryStandard()  { return m_indices(cointypes); }

/* Tells us, how much the special type of coins is worth */
public int QueryCoinValue(string type) {
    return cointypes[type];
}

/* This function removes every empty entry from the mapping */
public mapping CleanMoney(mapping money) {
    return filter(money || ([]), (: $2 :));
}

/* Tells us the weight of a coin of the specified type */
public int QueryCoinWeight(string type) {
  return DEF_WEIGHT;
}

/* Gives us the value of the money mapping
 * If pointerp(types) we use only that type of coins
 */
public varargs int QueryMoneyValue(mapping money, string *types) {
    int val = 0;

    if (!sizeof(money)) return 0;
    if (!pointerp(types)) types = QueryStandard();
    foreach(string coin, int num: money)
        if (member(types, coin) > -1)
            val += QueryCoinValue(coin) * num;
    return val;
}

/* Gives us the weight of the money */
public int QueryMoneyWeight(mapping money) {
    int val = 0;

    if (!sizeof(money)) return 0;
    foreach(string coin, int num: money) val += QueryCoinWeight(coin) * num;
    return val;
}

/* Returns the number of the coins in the given mapping */
public int QueryCoinNumber(mapping money) {
    if (!sizeof(money)) return 0;
    return sum(m_values(money));
}

/* It compares the values of the different coin types */
public int compare_value(string typ1, string typ2) {
  return QueryCoinValue(typ1) < QueryCoinValue(typ2);
}

private int compare_value_backward(string typ1, string typ2) {
  return compare_value(typ2, typ1);
}

/* This function converts the money mapping into a nice string */
// Al parecer flag es hasta cuanto sabemos contar... q fuerte :p
// Ej: 20 monedas de oro y 11 de plata
public varargs string QueryMoneyString(mapping money, int flag) {
  string *types, *sh = ({});
  int    i, j;
  mixed tmp, tmp1;

  if (!sizeof(money)) return "0 monedas de cobre";

  money = CleanMoney(money);
  if (!sizeof(types = sort_array(m_indices(money),SF(compare_value))))
    return "0 monedas de cobre";
  /* Checking for trivial values */

  for(i = 0, j = sizeof(types); i<j; ++i) {
    sh += ({"" +
        // Primero el numero de moneda(s), depende de hasta cuanto sepa contar
            ( (flag && flag <= money[types[i]])?
              (2*flag <= money[types[i]]?"montones de":"algunas"):
              money[types[i]]
            )
        // Si es la primera (i!=0) añado la palabra moneda(s)
            + ( i ? " " : " moneda"+ ( (money[types[i]] == 1) ? " ":"s ") )
        // Añado el tipo de moneda
            + "de " + types[i]
          });
  }

  if (sizeof(sh) == 1) return implode(sh,"");
  return implode(sh[0..<2],", ") + " y " + sh[<1];
}

/* Tries to find a short description for the money */
private string short_string(string type, mapping money) {
  return money[type] + (QueryCoinTypes()[type, MONEY_SHORT]||type[0..1]);
}

/* This function tries to create a smaller version of the money
 * string (specially for price announcements and such) */
public string QueryMoneyShort(mapping money) {
  if (   !money
      || !mappingp(money)
      || !sizeof(money = CleanMoney(money))
     ) return "0co";
  return implode(map(sort_array(m_indices(money),SF(compare_value)),
                           SF(short_string), money), " ");
}

varargs string QueryMoneyLong(mapping money, int flag) {
  string type;

  if(sizeof(money) != 1)
    return "Ves " + QueryMoneyString(money, flag) + ".\n";
  if(QueryCoinTypes()[type = m_indices(money)[0], MONEY_LONG])
    return QueryCoinTypes()[type, MONEY_LONG];
  return "Ves " + QueryMoneyString(money, flag) + ".\n";
}

/* This is only a small function to support the next one */
private int add_next_count(string type, mixed other) {
  int tmp;

  if(!pointerp(other)) return 0;
  if(!QueryCoinValue(type)) return 0;
  other[1][type] = (tmp = other[0]/QueryCoinValue(type));
  other[0] %= QueryCoinValue(type);
  return 0;
}

/* This function creates a money mapping which has the worth of
 * the given value and contains only the given money types or
 * (if not given) the standard money types */
public varargs mapping CreateMoney(int value, string *types) {
  int i,amnt;
  mixed tmp;

  if (!value) return ([]);
  if (!sizeof(types)) types = QueryStandard();
  else if (member(types, "cobre")<0) types += ({"cobre"});
  types = sort_array(types, SF(compare_value));

  tmp = ({value,([])});
  filter(types, SF(add_next_count), &tmp);
  return CleanMoney(tmp[1]);
}

/* Creates a string for the given value */
varargs string QueryValueString(int value, string *types) {
  return QueryMoneyString(CreateMoney(value, types));
}

/* Creates a very short string for the given value */
varargs string QueryValueShort(int value, string *types) {
  return QueryMoneyShort(CreateMoney(value, types));
}

/* This function calculates, which money array the player has to
 * give to pay the given value and which money array he would get
 * back */
// Devuelve un array con el dinero que queda despues de pagar, el dinero que
// se ha pagado y la vuelta recibida (por si no tenias justo). Hay que tener en
// cuenta que la vuelta recibida ya esta sumada al dinero que te queda despues.
varargs mixed PayValue(int value, mapping money, string *types) {
  mixed retval, change;
  int i, j, num;

  if (!sizeof(types)) types = QueryStandard();
  else if (member(types, "cobre")<0) types += ({"cobre"});
  types = sort_array(types, SF(compare_value));

  retval = ([]);

  if (!mappingp(money)) return 0;
  money = (mapping) copy(money);

  if (QueryMoneyValue(money & types) < value) return 0;
  /* We now know, the money contains enough coins of the given types to pay
   * the given value */

  // Primero voy rellenando con las monedas mas pequeñas que value
  for (i=sizeof(types); i--;) {
    if (!QueryCoinValue(types[i])) continue;
    if (value < QueryCoinValue(types[i])) break;
    num = min(value/QueryCoinValue(types[i]), money[types[i]]);
    value -= num * QueryCoinValue(types[i]);
    money[types[i]] -= num;
    retval[types[i]] = num;
    if (!value) return ({ CleanMoney(money), CleanMoney(retval), 0 });

  }

  /* Now we have some amount left, we are searching for the next type of
   * coins which is still aviable in money and is more worth than the
   * leftover */
 // Usea, meto la primera moneda que pille mas grande que el value restante
  for(i=sizeof(types); i--; ) {
    if(money[types[i]] && (QueryCoinValue(types[i]) >= value)) {
      ++retval[types[i]];
      --money[types[i]];
      value -= QueryCoinValue(types[i]);
      break;
    }
  }

  /* Now we maybe can return some smaller coins */
  // Simplifico extrayendo monedas pequeñas
  for(j = sizeof(types), ++i; i < j; ++i) {
    if(!QueryCoinValue(types[i])) continue;
    num = min((-value)/QueryCoinValue(types[i]), retval[types[i]]);
    value += num * QueryCoinValue(types[i]);
    retval[types[i]] -= num;
    money[types[i]] += num;
    if (!value) return ({ CleanMoney(money), CleanMoney(retval), 0 });
    /* Normally value can't be zero now! */
  }
  /* So, now we have a money mapping which contains the littlest possible
   * value which is realizable with the 'money' variable, and which has a
   * greater value than 'value'
   *
   * We add the change to the money map and return */

  change = CreateMoney(-value,types);
  walk_mapping(change, (: $3[$1] += $2 :), &money); // money[type] += amount;
  return ({ CleanMoney(money), CleanMoney(retval), change });
}

/* This function just decreases the amount of a specified type of coins */
private void pay_single_type(string type, int amount, mixed special) {
  if(!pointerp(special)) return;
  if((special[0][type] -= amount) < 0) special[1] = 1;
}

/* This function remains for compatibility. I don't think we need it. */
// Llamada en /std/bancos/banco.c->? llama a /lib/money.c->PayMoney llama aqui
public mapping PayMoney(mapping money, mapping to_pay) {
  mixed tmp;

  if( !mappingp(money) || !mappingp(to_pay)) return 0;
  tmp = ({(mapping) copy(money), 0});
  walk_mapping(to_pay,SF(pay_single_type),&tmp);
  return tmp[1]?0:tmp[0];
}

/* This function checks, if we have money of the given type in the given
 * money map and returns the associated name */
private void add_vario(string type, mixed  contents, mixed  filtro) {

    switch (type) {
        case "cobre":
            m_add(filtro, "co"                , "cobre"  );
            m_add(filtro, "cos"               , "cobre"  );
            m_add(filtro, "cobre"             , "cobre"  );
            m_add(filtro, "cobres"            , "cobre"  );
            m_add(filtro, "moneda de cobre"   , "cobre"  );
            m_add(filtro, "monedas de cobre"  , "cobre"  );
        break;
        case "plata":
            m_add(filtro, "pl"                , "plata"  );
            m_add(filtro, "pls"               , "plata"  );
            m_add(filtro, "plata"             , "plata"  );
            m_add(filtro, "platas"            , "plata"  );
            m_add(filtro, "moneda de plata"   , "plata"  );
            m_add(filtro, "monedas de plata"  , "plata"  );
        break;
        case "oro":
            m_add(filtro, "or"                , "oro"    );
            m_add(filtro, "ors"               , "oro"    );
            m_add(filtro, "oro"               , "oro"    );
            m_add(filtro, "oros"              , "oro"    );
            m_add(filtro, "moneda de oro"     , "oro"    );
            m_add(filtro, "monedas de oro"    , "oro"    );
        break;
        case "platino":
            m_add(filtro, "pt"                , "platino");
            m_add(filtro, "pts"               , "platino");
            m_add(filtro, "platino"           , "platino");
            m_add(filtro, "platinos"          , "platino");
            m_add(filtro, "moneda de platino" , "platino");
            m_add(filtro, "monedas de platino", "platino");
        break;
        case "mithril":
            m_add(filtro, "mt"                , "mithril");
            m_add(filtro, "mts"               , "mithril");
            m_add(filtro, "mithril"           , "mithril");
            m_add(filtro, "mithrils"          , "mithril");
            m_add(filtro, "mithriles"         , "mithril");
            m_add(filtro, "moneda de mithril" , "mithril");
            m_add(filtro, "monedas de mithril", "mithril");
        break;
    }
}

/* Devuelve el tipo de moneda de money que encaja con el string type */
public string PresentMoney(string type, mixed money) {
  mixed filtro = ([]);

  if (!money || !mappingp(money)) return 0;
  walk_mapping(money, SF(add_vario), &filtro);
  return filtro[type];
}
