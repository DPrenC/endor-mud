/**
 * /std/container/description
 */

#include <config.h>
#include <rooms.h>
#include <properties.h>
#include <colours.h>
#include <messages.h>
#include <bandos.h>
inherit "/std/thing/description";

//----------------------------------------------------------------------------

private int pIntLight = 0;  // La luz que hay dentro
private int pIntBright = 0; // Lo q yo brillo padentro
private nosave mapping pLightSources = ([]); // Las luces q hay dentro

private string pPreIntShort = "en"; // Preposición del IntShort
private mixed  pIntShort = ""; // Mi descripción corta interna
private mixed  pIntLong;  // Mi descripción larga interna
private mixed  pExaIntLong; // Mi descripción examinar larga int
private mixed  pIntNoise; // Mi ruido interno
private mixed  pIntSmell; // Mi olor interno
private string pPreCont;  // Cadena mostrada antes del contenido
private int aIntBando;
string color_short="";
public int QueryIntBando()          { return aIntBando; }
public int SetIntBando(int i)       { return aIntBando = i; }
//----------------------------------------------------------------------------

public string * filterExtra (string prop); // std/thing/description

public int QueryIntLight();     // forward
public int QueryIntBright();    // forward

//----------------------------------------------------------------------------
// Manejo de la luz
//----------------------------------------------------------------------------

/** public void emit_intlight()
Emitir luz hacia dentro de mi.
Tengo que notificar a los objetos de dentro del cambio de luz.
*/
public void emit_intlight() {
    //dtell("nyh",sprintf("%O llamó a %O->emit_intlight()\n", PO, TO));
    filter_objects(all_inventory(), "light_outside", QueryIntLight());
}

/** Debera ser protected o incluso private, es public para debug
 Esta función revisa el mapping de fuentes de luz limpiandolo y calculando
 la nueva intlight.
 Os preguntareis por que uso tanto el QueryIntLight en esta funcion, esto
 es debido a q sa funcion luego se sobrecarga por ejemplo en la room para
 tener en cuenta el SunLight y tal...
*/
static int _recalculate_intlight() {
    int i = QueryIntLight();
    // Primero limpio por si hay mierda en el mapping
    pLightSources = filter(pLightSources, (: objectp($1) && present($1) :));

    // Ahora calculo la luz. Sera el mayor valor y punto (no se apilan ;p)
    // El que no se apilasen daba problemas con los ocnjuros de oscuridad,
    // asi que de momento lo cambio para que sume todos los valores.
    if (sizeof(pLightSources)) {
        //pIntLight = max(  max(m_values(pLightSources)), QueryIntBright() );
        pIntLight = sum(m_values(pLightSources)) + QueryIntBright();
    }
    else {
        pIntLight = QueryIntBright();
    }

    if (i != QueryIntLight()) { // ha cambiado la luz, notificarlo
        emit_intlight();
    }

    return QueryIntLight();
}

/** public varargs void AddLightSource(object obj)
 * Añado al objeto obj como fuente de luz dentro de este contenedor
 */
public varargs void AddLightSource(object obj) {
    int light;

    if (!objectp(obj)) obj = PO;
    //if (!objectp(obj)) return 0; // Seguridad, de momento no lo pongo
    if (!present(obj)) return 0;
    //dtell("nyh",sprintf("%O llamó a %O->AddLightSource(%O)\n", PO, TO, obj));
    if (light = (int)obj->QueryBright()) m_add(pLightSources, obj, light);
    else m_delete(pLightSources, obj); // Necesario para cuando apagas algo.
    _recalculate_intlight();
}

/**

*/
public varargs void RemoveLightSource(object obj) {
    if (!objectp(obj)) obj = PO;
    //if (!objectp(obj)) return 0; // Seguridad, de momento no lo pongo
    if (!member(pLightSources, obj)) return 0;
    //dtell("nyh",sprintf("%O llamó a %O->RemoveLightSource(%O)\n", PO, TO, obj));
    m_delete(pLightSources, obj);
    _recalculate_intlight();
}

public mapping QueryLightSources() { return pLightSources; }

/** public void light_outside(int l)
Me llega luz de fuera.
Como ya no hay transparencia, aqui se queda, la dejo para sobrecargar.
*/
public void light_outside(int l) {
    //dtell("nyh",sprintf("%O llamó a %O->light_outside(%O)\n", PO, TO, l));
}

public varargs int QueryIntLight()  { return pIntLight; }
public int SetIntLight(int l)       { return QueryIntLight(); }

public int QueryIntBright()    { return pIntBright; }
public int SetIntBright(int l) {
    pIntBright = l;
    _recalculate_intlight();
    return QueryIntBright();
}

//----------------------------------------------------------------------------
// Fin del manejo de la luz
//----------------------------------------------------------------------------

public string SetIntLong(mixed s)       { return (string)funcall(pIntLong = s); }
public string QueryIntLong()            { return (string)funcall(pIntLong); }

public string SetExaIntLong(mixed s)    { return (string)funcall(pExaIntLong = s); }
public string QueryExaIntLong()         { return (string)funcall(pExaIntLong); }

public string SetIntShort(mixed s)      { return (string)funcall(pIntShort = s); }
public varargs string QueryIntShort(int i) {
    if (closurep(pIntShort)) return (string)funcall(pIntShort);
    if (i || !sizeof(pIntShort)) return pIntShort;
    /*
    // corregimos los posibles IntShort del tipo: a el sur, dentro de el barco...
    if (   (pPreIntShort == "a" || pPreIntShort[<2..] == " a" ||pPreIntShort[<3..] == " de")
        && pIntShort[..2] == "el " )
    {
        return pPreIntShort + pIntShort[1..];
            }
*/
switch(QueryIntBando()){
        case P_BANDO_NEUTRO: color_short = P_BANDO_COLOR_NEUTRO; break;
        case P_BANDO_LUZ: color_short = P_BANDO_COLOR_LUZ; break;
        case P_BANDO_OSCURIDAD: color_short = P_BANDO_COLOR_OSCURIDAD; break;
        default: color_short = P_BANDO_COLOR_NEUTRO; break;
        }
    //return TC_BOLD+TC_CYAN+pPreIntShort + " " + pIntShort+TC_NORMAL;
    return TC_BOLD+color_short+ CAP(pIntShort);
}

public string SetPreIntShort(string s)  { return pPreIntShort = stringp(s)?s:"en"; }
public string QueryPreIntShort()        { return sizeof(pIntShort)?pPreIntShort:""; }

public string SetIntNoise(mixed s)      { return (string)funcall(pIntNoise = s); }
public string QueryIntNoise()           { return (string)funcall(pIntNoise); }

public string SetIntSmell(mixed s)      { return (string)funcall(pIntSmell = s); }
public string QueryIntSmell()           { return (string)funcall(pIntSmell); }

public string SetPreContent(string s)   { return pPreCont = stringp(s)?s:""; }
public string QueryPreContent()         { return pPreCont; }


//--- Actual appearance -----------------------------------------------------

public varargs string IntLong(string what)  {
  return QueryIntLong() + implode(filterExtra(P_INT_LONG), "");
}
public varargs string ExaIntLong(string what)  {
  string rc;
  return ((rc=QueryExaIntLong())?rc:("No adviertes nada fuera de lo común.\n"+QueryIntLong()))
         +implode(filterExtra(P_INT_LONG), "");
}
public varargs string IntShort(string what) {
  string sh;
  if (!(sh = QueryIntShort()) || sh == "") return sh;
  return sh+implode(filterExtra(P_INT_SHORT), "");
}
public varargs string IntNoise(string what) {
  string str;
  if (what) return TO->GetNoise(what);
  str = (QueryIntNoise()||"")+implode(filterExtra(P_INT_NOISE), "");
  return str != "" ? str : 0;
}
public varargs string IntSmell(string what) {
  string str;
  if (what) return TO->GetSmell(what);
  str = (QueryIntSmell()||"")+implode(filterExtra(P_INT_SMELL), "");
  return str != "" ? str : 0;
}

public varargs string Content(string what, mixed excl, object pl) {
  string *strs,str_objects;
  mapping objects;
  mixed ind;
  int i;
  object *inv;

  if (closurep(excl)) excl = filter(all_inventory(TO), excl);
  if (objectp(excl)) excl = ({ pl||TP, excl });
  else if (pointerp(excl)) excl += ({ pl||TP });
  else excl = ({ pl||TP });

  strs = map_objects(all_inventory(TO) - excl, "InvShort") - ({ "" });

  if (sizeof(strs))
  {
    objects = m_allocate(0,1);
    for (i = sizeof(strs); i--; )
    {
      if (!member(objects,strs[i])) objects[strs[i],0] = 1;
      else objects[strs[i],0]++; //=objects[strs[i],0]+1;
    }
    str_objects="";
    ind = m_indices(objects);
    for(i = 0;i<sizeof(objects);i++)
    {
      if (objects[ind[i],0]==1) str_objects += ind[i]+".\n";
      else str_objects += ind[i]+"["+objects[ind[i],0]+"].\n";
    }
    return (QueryPreContent() || "") + str_objects;
  }
  return "";
}

public varargs string GetIntDesc(int brief, mixed excl, object pl) {
  string desc = "";
  if (!pl) pl = TP;
switch(QueryIntBando()){
        case P_BANDO_NEUTRO: color_short = P_BANDO_COLOR_NEUTRO; break;
        case P_BANDO_LUZ: color_short = P_BANDO_COLOR_LUZ; break;
        case P_BANDO_OSCURIDAD: color_short = P_BANDO_COLOR_OSCURIDAD; break;
        default: color_short = P_BANDO_COLOR_NEUTRO; break;
        }
  if (!brief) {
    desc += TC_BOLD+color_short+" -< "+CAP(IntShort())+" >-"TC_NORMAL"\n"+IntLong()+
    (!TO->QueryIndoors() ? TO->QueryDayDesc() : "");
  }

  if (pl->QueryObvious()) {
	if (brief) desc += TC_BLUE+"("+TC_NORMAL;
	desc += TO->Exits(brief, pl);
	if (brief) desc += TC_BLUE+")\n"+TC_NORMAL;
	desc += TO->Doors(0) || "";
  }
  return desc + Content(0, excl, pl);
}

public varargs string GetExaIntDesc(mixed excl, object pl) {
  string desc;

  if (!pl) pl = TP;
  desc = ExaIntLong();

  if (pl->QueryObvious()) {
	if (pl->QueryBrief()) desc += TC_BLUE+"("+TC_NORMAL;
	desc += TO->Exits(1, pl);
	if (pl->QueryBrief()) desc += TC_BLUE+")\n"+TC_NORMAL;
	desc += TO->Doors(0) || "";
  }
  return desc + Content(0, excl, pl);
}


//----------------------------------------------------------------------------
