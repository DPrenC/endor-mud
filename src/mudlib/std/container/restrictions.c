/**
 * SIMAURIA '/std/container/restrictions.c'
 */

#include <config.h>
#include <search.h>
#include <moving.h>
#include <messages.h>
#include <magia.h>
#include <wizlevels.h>
#include <properties.h>

inherit "/std/thing/restrictions";

//---------------------------------------------------------------------------

private nosave int pIntWeight = 0; // Peso de lo que tengo dentro
private int pMaxIntWeight = 1<<30; // Peso maximo que puedo llevar
private int pMaxInv = 0; // Numero maximo de objetos
private int pMaxIntSize = 100; // Tamaño maximo conjunto de los obj

private int pTport = TPORT_BOTH;

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

public varargs object* Locate(mixed what, int mode)
{
  if (   !(mode & SEARCH_IGNLIGHT)
      && member(deep_inventory(TO), TP) == -1
     )
  {
    return (mode & SM_OBJECT) ? 0 : ({});
  }
  return locate(TO, what, mode);
}


//---------------------------------------------------------------------------
//--- weight handling -------------------------------------------------------

public int QueryIntWeight()      { return pIntWeight; }
public int QueryWeightContent()  { return QueryIntWeight(); }

public int QueryMaxIntWeight()    { return pMaxIntWeight; }
public int SetMaxIntWeight(int w) {
    return w >= pMaxIntWeight
           ? pMaxIntWeight = w
           : ( w <= pIntWeight ? pMaxIntWeight = pIntWeight
                               : pMaxIntWeight = w
             );
}

public int MayAddIntWeight(int w) {
    return w<1 || (   ( QueryMaxIntWeight() >= w + pIntWeight )
                   && ( !environment() || environment()->MayAddIntWeight(w) )
                  );
}

public void AddIntWeight(int w) {
    pIntWeight += w;
    if (environment()) environment()->AddIntWeight(w);
}
/**
 * Si flag == 1 devuelve el peso solo de este objeto
 *  (de momento vale con distinto de cero, pero lo oficial es igual a 1)
 * Si flag == 0 devuelve el peso de este objeto y de su contenido
 */
public varargs int QueryWeight(int flag) {
    if (flag) return ::QueryWeight(1);
    return ::QueryWeight(1) + QueryIntWeight();
}

/**
 * Devuelve lo máximo que puede llegar a pesar un objeto
 */
public int QueryMaxWeight() {
    return ::QueryWeight(1) + QueryMaxIntWeight();
}

//---------------------------------------------------------------------------

public int QueryMaxInv()    { return pMaxInv; }
public int SetMaxInv(int i) { return pMaxInv = (i >= 0) ? i : 0; }

public int MayAddItem() {
    int i;
    i = QueryMaxInv();
    return i < 1 || sizeof(all_inventory(TO)) < i;
}

//---------------------------------------------------------------------------

public int QueryIntSize() {
    return sum(call_other(all_inventory(),"QuerySize"));
}
public int QueryMaxIntSize() { return pMaxIntSize; }
public int SetMaxIntSize(int to) { return pMaxIntSize = to; }

public int MayAddSize(int i) {
	return QueryMaxIntSize()<1 || (QueryIntSize() + i <= QueryMaxIntSize());
}

//----------------------------------------------------------------------------

//--- find something or more in the container --------------------------------

// Cuidado con borrar esto, que se usa en el sefun_search.ic
public object *filterWornWielded (object * objs) {
  objs -= filter_objects(objs, "Query", P_EQUIPPED);
  return objs;
}

//--- moving restrictions and notifications ---------------------------------

public int QueryTPort() {
    return (IS_LEARNER(TP) && !TP->Query(P_NOWIZ)) ? TPORT_BOTH : pTport;
}
public int SetTPort(int t) { return pTport = t; }

public int prevent_leave(mixed dest, int method, mixed extra) {
  if(method == M_TELEPORT && !(QueryTPort() & TPORT_OUT)) return ME_NO_LEAVE;
  return ME_NO_PREVENT;
}

public int allow_enter(int method, mixed extra) {
    if(method == M_TELEPORT && !(QueryTPort() & TPORT_IN)) return ME_NO_ENTER;

    if (!MayAddItem()) return ME_TOO_MANY;
	if (!MayAddSize((int)PO->QuerySize())) return ME_TOO_BIG;
    if (!MayAddIntWeight((int)PO->QueryWeight())) return ME_TOO_HEAVY;

    return ME_OK;
}

//----------------------------------------------------------------------------
private void  _send_leave_message(mixed to, int method, mixed extra )
{
    string seemsg = "", hearmsg = "", seeextra = "", hearextra = "";
    mixed msgout;
    object obj;

    obj = PO;

    if (!obj->Query(P_INVIS) && (!obj->Short() || obj->Short() == "")) return;

    seemsg = capitalize(((string)obj->QueryName()||(string)obj->Short())) + " ";
    hearmsg = living(obj) ? "Alguien " : "Algo ";

    if (stringp(extra)) seeextra = extra;
    else if (pointerp(extra) && sizeof(extra))
    {
        if (stringp(extra[0])) seeextra = extra[0];
        else
        {
            seeextra  = extra[0][0];
            hearextra = extra[0][1];
        }
    }

    switch(method)
    {
    case M_GO:
        msgout = obj->QueryMsgOut() || "se va";
        seemsg += stringp(msgout) ? msgout : msgout[0];
        hearmsg = stringp(msgout) ? hearmsg + "desaparece" : msgout[1];
        if(stringp(extra))
        {
            switch(extra)
            {
            case "norte":      seemsg += " hacia el norte";       break;
            case "noreste":   seemsg += " hacia el noreste";    break;
            case "este":       seemsg += " hacia el este";        break;
            case "sureste":    seemsg += " hacia el sureste";     break;
            case "sur":        seemsg += " hacia el sur";         break;
            case "suroeste":   seemsg += " hacia el suroeste";    break;
            case "oeste":      seemsg += " hacia el oeste";       break;
            case "noroeste":   seemsg += " hacia el noroeste";    break;
            case "arriba":     seemsg += " hacia arriba";         break;
            case "abajo":      seemsg += " hacia abajo";          break;
            }
        }
        else
        {
            seemsg  += " " + seeextra;
            hearmsg += " " + hearextra;
        }
        break;
    case M_TELEPORT:
        msgout = obj->QueryMMsgOut() || "se va";
        if (seeextra  != "") seemsg  += seeextra;
        else seemsg += stringp(msgout) ? msgout : msgout[0];
        if (hearextra != "") hearmsg += hearextra;
        else hearmsg = stringp(msgout) ? hearmsg + "desaparece" : msgout[1];
        break;
    case M_SPECIAL:
        seemsg  += seeextra;
        hearmsg += hearextra;
        break;
    default:
        return;
    }

    if(member(".!?", seemsg[<1] ) == -1) seemsg  += ".";
    if(member(".!?", hearmsg[<1]) == -1) hearmsg += ".";

    tell_room( TO, ({ MSG_SEE, seemsg, ({ MSG_HEAR, hearmsg }) }), ({ obj }) );

}

public void notify_leave(mixed to, int method, mixed extra)
{
// Quitarte como fuente de luz
    TO->RemoveLightSource(PO);

// Quitar el peso añadido al environment
    AddIntWeight(-(int)PO->QueryWeight());

// Envio el mensaje de salida
    _send_leave_message( to, method, extra );
//    say( ({ MSG_MOVE, THIS, to, method, extra }) /*, ({ PO })*/ );

}

private void _send_enter_message(mixed from, int method, mixed extra)
{
  mixed msgin;
  string seemsg = "", hearmsg = "", seeextra = "", hearextra = "";
  object *rej, obj;

  obj = PO;

  if (stringp(extra)) seeextra = extra;
  else if (pointerp(extra) && sizeof(extra) > 1)
  {
    if (stringp(extra[1])) seeextra = extra[1];
    else
    {
      seeextra  = extra[1][0];
      hearextra = extra[1][1];
    }
  }

  if (!obj->Query(P_INVIS) && (!obj->Short() || obj->Short() == "")) return;

  seemsg = capitalize(((string)obj->QueryName()||(string)obj->Short())) + " ";
  hearmsg = living(obj) ? "Alguien " : "Algo ";

  switch(method)
  {
    case M_GO:
      msgin = obj->QueryMsgIn() || "llega";
      seemsg += stringp(msgin) ?  msgin  : msgin[0];
      hearmsg = stringp(msgin) ? hearmsg + "llega" : msgin[1];
      if(stringp(extra))
      {
        switch(extra)
        {
          case "norte":    seemsg += " del sur";      break;
          case "noreste": seemsg += " del suroeste"; break;
          case "este":     seemsg += " del oeste";    break;
          case "sureste":  seemsg += " del noroeste"; break;
          case "sur":      seemsg += " del norte";    break;
          case "suroeste": seemsg += " del noreste"; break;
          case "oeste":    seemsg += " del este";     break;
          case "noroeste": seemsg += " del sureste";  break;
          case "arriba":   seemsg += " de abajo";     break;
          case "abajo":    seemsg += " de arriba";    break;
        }
      }
      else
      {
        seemsg  += " " + seeextra;
        hearmsg += " " + hearextra;
      }
      break;
    case M_TELEPORT:
      msgin = obj->QueryMMsgIn() || "aparece";
      if (seeextra  != "") seemsg  += seeextra;
      else seemsg += stringp(msgin) ?  msgin : msgin[0];
      if (hearextra != "") hearmsg += hearextra;
      else hearmsg = stringp(msgin) ? hearmsg + "aparece" : msgin[1];
      break;
    case M_SPECIAL:
      seemsg  += seeextra;
      hearmsg += hearextra;
      break;
    default:
      return;
  }

  if (member(".!?", seemsg[<1] ) == -1) seemsg  += ".";
  if (member(".!?", hearmsg[<1]) == -1) hearmsg += ".";

  tell_room( TO, ({ MSG_SEE, seemsg, ({ MSG_HEAR, hearmsg }) }), ({ obj }) );

}

public void notify_enter(mixed from, int method, mixed extra)
{
// Ponerte como fuente de luz
    TO->AddLightSource(PO);

// Añadir tu peso
    AddIntWeight((int)PO->QueryWeight());

// Envio el mensaje de entrada
    _send_enter_message( from, method, extra );
//    say( ({ MSG_MOVE, from, THIS, method, extra }) /*, ({ PO })*/ );

}
