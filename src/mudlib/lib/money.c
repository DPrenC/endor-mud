/**
 * SIMAURIA '/lib/money.c'
 */

/*  this object provides some money library functions.  */

#include <money.h>
#include <moving.h>

create() {
  seteuid(getuid());
}

/*---------------------------------------------------------------------------*/
remove() { destruct(TO); return 1; }
/*---------------------------------------------------------------------------*/

/* Te devuelve el objeto de dinero de who, o who si este es un objeto de dinero
 * en caso de que who no sea dinero y no contenga dinero creo un nuevo objeto
 * de dinero y lo intento mover dentro de who, en caso de que salga bien lo
 * devuelvo y si no devuelvo 0
 * El devolver who = money o who = inv[0] es por si se pasa por referencia.
 */
public object QueryMoneyObject(object who) {
    object *inv;

    if (!who) return 0;
    if (who->QueryMoneyObject()) return who;

    if (!sizeof(inv = filter(all_inventory(who), (:$1->QueryMoneyObject():)))) {
        object money;
        seteuid(getuid());
        money = clone_object(MONEY);
        if (money->move(who) == ME_OK) {
            return who = money;
        }
        return 0;
    }
    return who = inv[0];
}

/*
 * SetValuta()
 * Sets the money types we trade with.
 * This wouldn't have any effects, if the /lib/money is used via call_other()
 */
public string *QueryValuta() {
  return MONEY_DEMON->QueryStandard();
}

/*---------------------------------------------------------------------------*/
public varargs int AdjustMoney(object ob, mixed i, string type) {
    if (!QueryMoneyObject(&ob)) return 0;
  return ob->AdjustMoney(i, type);
}

/*---------------------------------------------------------------------------*/
public mapping QueryMoney(object ob) {
  if (!QueryMoneyObject(&ob)) return 0;
  return (mapping) ob->QueryMoney();
}

/*---------------------------------------------------------------------------*/
public varargs int SetMoney(object ob, mixed arg, string *types) {
  if (!QueryMoneyObject(&ob)) return 0;
  if (intp(arg)) return ob->SetMoney(MONEY_DEMON->CreateMoney(arg, types));
  else return ob->SetMoney(arg);
}

/*---------------------------------------------------------------------------*/
public int QuerySomeonesValue(object ob, string *types) {
  if (!QueryMoneyObject(&ob)) return 0;
  return MONEY_DEMON->QueryMoneyValue(ob->QueryMoney(), types);
}

/*---------------------------------------------------------------------------*/
/* El objeto who paga m_map de dinero.
 * Utilizada cuando es necesario especificar exactamente que monedas usa,
 *  como por ejemplo al ingresar dinero en un banco.
 */
public int PayMoney(object ob, mapping *m_map) {
  mixed m_a;

  if (!QueryMoneyObject(&ob)) return 0;

  if ((int)ob->QueryValue()<(int)MONEY_DEMON->QueryMoneyValue(m_map))
    return 0;
  m_a = MONEY_DEMON->PayMoney(ob->QueryMoney(), m_map);
  if (!m_a) return 0;
  ob->SetMoney(m_a);
  return 1;
}

/*---------------------------------------------------------------------------*/
public varargs int PayValue(object who, int value, string *types)
{
    object money;
    mixed *m_a;

    if (!who) return 0;
    if (value <= 0) return !value;
    if (!(money = QueryMoneyObject(who))) return 0;
    if (money->QueryValue() < value) return 0;

    m_a = MONEY_DEMON->PayValue(value, money->QueryMoney(), types);

    if (!m_a) return 0;
    if (!pointerp(m_a)) return 0;
    money->SetMoney(m_a[0]);
    return 1;
}

/*---------------------------------------------------------------------------*/
varargs mixed PayValue2(object who, int value, string *types) {
    object money;
    mixed *m_a, *eyo;
    string *ret;

    if (value<0) return MONEY_NEGATIVE;
    if (!value) return ({"nada",0});
    if ( !(money = QueryMoneyObject(who)) ) return MONEY_NO_MONEY;
    if (money->QueryValue() < value) return MONEY_NOT_ENOUGH;
    m_a = MONEY_DEMON->PayValue(value,money->QueryMoney(),types);
    if (!m_a) return MONEY_CANT_PAY;
    if (!pointerp(m_a)) return MONEY_WRONG_RESULT;
    money->SetMoney(m_a[0]);
    if (!MONEY_DEMON->QueryMoneyValue(m_a[1])) ret = ({0});
    else ret = ({ (string)MONEY_DEMON->QueryMoneyString(m_a[1]) });
    if (!MONEY_DEMON->QueryMoneyValue(m_a[2])) ret+=({0});
    else ret += ({ (string)MONEY_DEMON->QueryMoneyString(m_a[2]) });
    return ret;
}

/*---------------------------------------------------------------------------*/
private object *get_previous_objects() {
  int     i;
  object *ob;

  ob = ({});
  while(previous_object(i)) ob += ({previous_object(i++)});
  return ob;
}

/*---------------------------------------------------------------------------*/
varargs string PayValueString(object who, int value, string *types,
			      string extramsg, int width)
{
  mixed result;

  if(pointerp(result = PayValue2(who, value, types))) {
    if(!result[0] && !result[1]) return "No pasa nada.\n";
    return sprintf("%*=-s",width||79,
		   //"You " +
		   (result[0]?"Pagas " + result[0] +
		    (extramsg?" " + extramsg:"") +
		    (result[1]?" y ":""):"") +
		   (result[1]?"recibes " + result[1] + " a cambio":"") +
		   (result[0] || !extramsg?"":" " + extramsg)
		   + ".\n");
  }
  switch(result) {
  case MONEY_NEGATIVE:
    notify_fail("No puedes pagar una cantidad de dinero negativa.\n");
    return 0;
  case MONEY_NO_MONEY:
    notify_fail("No tienes ni una triste moneda de cobre.\n");
    return 0;
  case MONEY_NOT_ENOUGH:
    notify_fail("No cuentas con el dinero suficiente para pagar eso.\n");
    return 0;
  case MONEY_CANT_PAY:
    notify_fail("No tienes suficientes monedas del tipo que aquí aceptan.\n");
    return 0;
  default:
  } /* end switch() */
  notify_fail("Ha ocurrido un error interno. Avisa a algún Vala.\n");
  log_file(MONEY_ERRORLOG,
          sprintf("\n--\n%s: PayValue2() returned MONEY_WRONG_RESULT\n"
                  "Previous objects:\n%s\n",
			    ctime(time()),
			    implode( map(get_previous_objects(),
                           SF(file_name)),"\n")));
  return 0;
}

/*---------------------------------------------------------------------------*/
// Igual q la anterior pero tb devuelve un mensaje para la habitacion
varargs string *PayValueString2(object who, int value, string *types,
			      string extramsg, int width)
{
  mixed result;

  if(pointerp(result = PayValue2(who, value, types)))
  {
    return ({ sprintf("%*=-s", width||79,
                       (result[0] ? "Pagas " + result[0] +
		                            (extramsg?" " + extramsg:"") +
		                            (result[1]?" y ":"")
		                          : "")
		             + (result[1] ? "recibes " + result[1] + " a cambio":"")
                     + (result[0] || !extramsg?"":" " + extramsg) + ".\n")
            ,sprintf("%*=-s", 79,
                       (result[0] ? capitalize(who->QueryName())
                                    + " paga " + result[0]
                                    + (extramsg?" " + extramsg:"") +
		                            (result[1]?" y ":"")
		                          : "")
                     + (result[1] ? " y recibe " + result[1] + " a cambio":"")
                     + (result[0] || !extramsg?"":" " + extramsg) + ".\n")
           });
  }
  switch(result) {
  case MONEY_NEGATIVE:
    notify_fail("No puedes pagar una cantidad de dinero negativa.\n");
    return 0;
  case MONEY_NO_MONEY:
    notify_fail("No tienes dinero.\n");
    return 0;
  case MONEY_NOT_ENOUGH:
    notify_fail("No tienes ni una triste moneda de cobre.\n");
    return 0;
  case MONEY_CANT_PAY:
    notify_fail("No tienes suficientes monedas del tipo que utilizan aquí.\n");
    return 0;
  default:
  } /* end switch() */
  notify_fail("Ha ocurrido un error interno. Avisa a algún God.\n");
  log_file(MONEY_ERRORLOG,
          sprintf("\n--\n%s: PayValue2() returned MONEY_WRONG_RESULT\n"
                  "Previous objects:\n%s\n",
		    ctime(time()),
		    implode( map(get_previous_objects(),
                           SF(file_name)),"\n")));
  return 0;
}

/**
 convierte un valor dado en cobre, en un string con el cambio en el menor
 número de monedas posibles.
*/
public varargs string Value2String(int valor, int abr) {
    string *monedas, *mensaje = ({});
    int unvalor, i;
    mapping types;

    if (!valor) return abr ? " 0 co" : "0 monedas de cobre";
    types = MONEY_DEMON->QueryCoinTypes();
    monedas = sort_array(m_indices(types), (:$3[$1] < $3[$2]:), types);
    if (!valor) return abr ? "0 co" : "0 monedas de cobre";

    foreach (string moneda:monedas)
    {
        if (i = valor / (unvalor = types[moneda])) {
            if (abr) mensaje += ({to_string(i) + " " + types[moneda, MONEY_SHORT]});
            else mensaje += ({to_string(i) + (sizeof(mensaje)?" de " + moneda : " moneda"+ (i>1?"s" : "")+ " de " + moneda)});
            valor = valor % unvalor;
        }
    }
    return implode(mensaje[0..<2],", ")+(sizeof(mensaje[0..<2])?" y ":"")+mensaje[<1];
}

/**
 convierte un valor dado en cobre, en un mapping con el cambio en el menor
 número de monedas posibles.
*/
public mapping Value2Mapping(int valor) {
    mapping types, res = ([]);
    string *monedas;
    int unvalor, i;

    if (!valor) return res;
    types = MONEY_DEMON->QueryCoinTypes();
    monedas = sort_array(m_indices(types), (:$3[$1] < $3[$2]:), types);
    foreach(string moneda:monedas)
    {
        if (i = valor / (unvalor = types[moneda])) {
            res += ([moneda:i]);
            valor = valor % unvalor;
        }
    }
    return res;
}


/**
 Dado un mapping en el formato que acepta SetMoney, devuelve el valor convertido a string. Si abr
 está a 1, el mensaje aparecerá en formato abreviado.
**/
public string Mapping2String(mapping m, int abr)
{
    string *monedas, *mensaje;
    mapping types;

    if (!m ||!sizeof(m)) return abr ? "0 co" : "0 monedas de cobre";
    mensaje = ({});
    types = MONEY_DEMON->QueryCoinTypes();
    monedas = sort_array(m_indices(m), symbol_function("compare_value", MONEY_DEMON));
    foreach(string moneda:monedas)
    {
        if (!member(m, moneda) || !m[moneda]) continue;
        if (abr) mensaje += ({to_string(m[moneda]) + " " + types[moneda, MONEY_SHORT]});
        else mensaje += ({to_string(m[moneda]) + (sizeof(mensaje)?" de " + moneda : " moneda"+ (m[moneda] > 1?"s" : "")+ " de " + moneda)});
    }
    return implode_list(mensaje);
}

/**
 Dado un mapping en el formato que acepta SetMoney, devuelve el valor total, en monedas de cobre
**/
public int Mapping2Value(mapping mon)
{
    mapping types;
    string *monedas;
    int res;
    if (!mon || !sizeof(mon)) return 0;

    types = MONEY_DEMON->QueryCoinTypes();
    monedas = m_indices(types);
    foreach (string unamoneda:monedas)
    {
        res += mon[unamoneda] * types[unamoneda];
    }
    return res;
}





/*---------------------------------------------------------------------------*/
