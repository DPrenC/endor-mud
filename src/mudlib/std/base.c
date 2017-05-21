/** SIMAURIA '/std/base.c'
 *  ======================
 */

#include "/secure/config.h"
#include <functionlist.h>
#include <properties.h>
#include <moving.h>

//--- global variables ------------------------------------------------------

private nosave string pCreator, pCreatorI;
private nosave int pInherited, pCloned, pCreationTime, pIsVirtual;
private nosave mapping pProps;

//--- property querying and setting -----------------------------------------

/** @brief Obtiene el valor de una propiedad del objeto

Esta función devuelve el valor de la propiedad solicitada del objeto.

@param pn Nombre de la propiedad que se solicita
@return El valor de la propiedad solicitada o 0 en caso de que no exista. Tener
en cuenta que puede existir y valer 0, y no hay forma de diferenciarlo.
*/
public mixed Query(string pn) {
  mixed ret;

  if (call_resolved(&ret, TO, "Query" + pn)) return ret;
  return pProps ? pProps[pn] : 0;
}

/** @brief Modifica una propiedad del objeto

Esta función modifica la propiedad especificada del objeto, asignándole el valor
que se le indique.

@param pn Nombre de la propiedad a la que se quiere modificar
@return El nuevo valor de la propiedad modificada.
*/
public mixed Set(string pn, mixed arg) {
  mixed ret;

  if (!pProps) pProps = ([P_CLEAN_UP: 1]);
  if (call_resolved(&ret, TO, "Set" + pn, arg)) return ret;
  if (arg) pProps[pn] = arg;
  else pProps = m_delete(pProps, pn);
  return arg;
}

/** @brief Mira si existe la propiedad especificada.

Esta función devuelve 1 si la propiedad especificada existe y cero si no.

@param pn Nombre de la propiedad que se comprueba
@return 1 si la propiedad especificada existe y cero en caso contrario.
*/
public varargs int Exists(string pn)
{
  return function_exists("Query" + pn, TO) ? 1 : member(pProps, pn);
}

//--- grant access to ALL properties of an object ---------------------------

// NOTE: we do not know, if the actual object has turned some softcoded
//       properties into hardcoded properties. So we HAVE to use
//       the Query- and Set() function to get/set the correct
//       values. So these functions have an VERY high evaluation cost.

private void filter_hardcoded(string func, mapping m) {
  if (func[0..4] == "Query")
  {
    mixed tmp;
    switch (func)
    {
      case "Query":
      case "QueryAttr":
      case "QueryProperties":
        break;
      default:
        if (!m_contains(&tmp, m, func[5..])) m[func[5..]]=call_other(TO, func);
    }
  }
}

/** @brief Obtiene TODAS las propiedades de un objeto. NO USAR SIN PERMISO.

Esta función devuelve un mapping con TODAS las propiedades del objeto. Consume
MUCHOS recursos, así que  hace falta un MUY BUEN MOTIVO para utilizarla.

@return Mapping con TODAS las propiedades del objeto.
*/
public mapping QueryProperties() {
  mapping m;

  m = ([]) + pProps;
  filter(functionlist(TO), SF(filter_hardcoded), m);
  return m;
}

/** @brief Modifica varias propiedades a la vez.

Esta función modifica todas las propiedades contenidas en el mapping que se
pasa como argumento a la función.

@param props Mapping con las propiedades y los valores que queremos modificar.
@return Mapping con las propeidades modificadas y sus valores finales.
*/
public mapping SetProperties(mapping props) {
  foreach (string prop, mixed value: props) props[prop] = Set(prop, value);
  return props;
}

//--- object destruction ----------------------------------------------------

/** @brief Función que se encarga de solicitar a este objeto que se destruya

Esta función es la que debe ser llamada cuando queremos destruir este objeto.

@return 1
*/
public int remove() {
  if (TO)
  {
    if(environment() && !(int)environment()->prevent_leave(TO, M_DESTRUCT, 0))
    {
      environment()->notify_leave(0, M_DESTRUCT, 0);
    }
    destruct(TO);
  }
  return 1;
}

//---------------------------------------------------------------------------

/** @brief Función llamada automágicamente por el driver para limpiarme.

Esta función es automágicamente llamada por el driver cuando considera que este
objeto hace mucho que no se usa y está ocupando memoria de forma innecesaria.
Se supone que debemos comprobar si seguimos o no siendo necesarios y en caso de
que no lo seamos, borrarnos limpiamente (esto es, llamando a mi remove).

@param ref No recuerdo muy bien que significaba.
@return A pesar de ser 'int' según el código se devuelve a si mismo si NO se
quiere borrar, y 1 en caso de que si se haya borrado
*/
public int clean_up(int ref) {
  if (Query(P_CLEAN_UP)) remove();
  return TO && 1;
}

//--- Better memory usage ---------------------------------------------------

/** @brief Realiza un replace_program si cree que debe hacerlo.

Esta función comprueba si este objeto puede hacer un replace_program para
ahorrar memoria, y en caso de que pueda, lo realiza.

@return Devuelve cero si decide NO hacer el replace_program, y el nombre del
programa con el que se ha reemplazado en caso de haberlo hecho.
*/
public string replace_pgm() {
  mixed *arr;
  object ob;
  int s;

  if (pInherited || pCloned || clonep()) return 0;

  // Check all non-"create" functions if they are inherited.
  arr = functionlist(TO, 3);
  s = sizeof(arr) - 1;
  do {
    if (!(arr[s] & NAME_INHERITED) && arr[s - 1] != "create")
      return 0;
    s -= 2;
  } while (s > 0);

  // Check if we have just one direct papa.
  arr = inherit_list();
  s = sizeof(arr) - 1;
  if (s && (ob = find_object(arr[1])) && s == sizeof(inherit_list(ob)))
  {
    replace_program(object_name(ob));
    return object_name(ob);
  }
  return 0;
}

//--- creator tracking ------------------------------------------------------

public /* nomask */ string QueryCreator()      { return pCreator; }
public /* nomask */ int    QueryCreationTime() { return pCreationTime; }
public /* nomask */ string QueryICreator()     { return pCreatorI; }
public /* nomask */ int    QueryInherited()    { return pInherited; }
public /* nomask */ int    QueryCloned()       { return pCloned; }
public /* nomask */ int    SetCloned(int i) {
  object o;
  o = PO;
  if (o && TO && o != TO
        && object_name(TO) == blueprint(TO)
        && object_name(TO) == blueprint(o)
     )
  {
    pCloned = -1;
  }
  return pCloned;
}

public /* nomask */ int QueryIsVirtual()    { return pIsVirtual; }
public /* nomask */ int SetIsVirtual(int i) {
  object o;
  o = PO;
  if (o && getuid(o) == ROOTID)
  {
    pIsVirtual = 1;
  }
  return pIsVirtual;
}

//---------------------------------------------------------------------------

private nomask void _create() {
  pCreator = to_string(PO || "<desconocido>");
  pCreatorI = to_string(TI || "<desconocido>");
  pProps = ([P_CLEAN_UP: 1]);  // No use to have extra code for pProps = 0
  pCreationTime = time();
  pIsVirtual = 0;
}

public void create() {

}

// called for cloned objects
public void create_clone() {
  _create();
  pInherited = 0;
  pCloned = 1;
  blueprint()->SetCloned(-1);
  create();
}

public void create_blueprint() {
  pCloned = 0;
  _create();
  create();
}

// called for blueprints implicitely loaded by inheritance
public void create_super() {
  pInherited = 1;
  create_blueprint();
}

// called for explicitely loaded blueprints/objects
public void create_ob() {
  /* pInherited = 0; */
  /* Sometimes an object is first loaded, then inherited.
   * It even makes sense sometimes.
   */
  create_blueprint();
}

//---------------------------------------------------------------------------
