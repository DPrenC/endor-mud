/* /std/room/basicexits.c
   ======================
   [t] Theuzifan
   [h] Nyh@Simauria

   20-01-01 [t] Creación.
   XX-XX-04 [h] Retoques mínimos.
                Pongo el control de luz como en la habitacion normal.
*/

#include <moving.h>
#include <nightday.h>
#include <messages.h>
#include <magia.h>
#include <config.h>
#include "/secure/wizlevels.h"
#include <messages.h>
#include <properties.h>

#define DIR_EXIT ({ "norte", "noroeste", "oeste", "suroeste", "sur", "sureste", "este", "noreste" })
#define UPNDOWN_EXIT ({ "arriba", "abajo" })

private static int pSafe, pTport;
private static int pIndoors;
private static string server;
private static mapping pMagicProp;
private static int maxinv, weight, maxweight;
/* [Nyh] Cambio esto:
//private static int light;  //La luz que hay dentro del objeto
// private static int useSunlight;
Por lo siguiente:
*/
private static int pSunBright, pIntLight, pIntBright;


public string QueryServer() {
	return server;
}

public string SetServer(mixed to) {
	if (objectp(to)) {
    	to = object_name(to);
    }
	return server = to;
}

public int QueryIndoors() {
	return pIndoors;
}

public int SetIndoors(int i) {
	return pIndoors = i;
}

public mixed QueryOutdoors() {
  return QueryIndoors() ? 0 : QueryServer();
}

public mixed SetOutdoors(mixed i) {
  if (i && intp(i)) i = NIGHTDAY;
  SetIndoors(!i);
  return SetServer(i);
}

public string QueryDayDesc() {
	return server->QueryStateDesc();
}

public string QueryDayState() {
	return server->QueryDayState();
}

/* [Nyh] Quito esto y lo pongo com la room normal...

public int QuerySunLight() {
	return server->QuerySunLight();
}

public int QueryIntLight() {
	if (useSunlight) {
    	return light + QuerySunLight();
    }
	return light;
}

public varargs int SetIntLight(int to, int sun) {
	useSunlight = sun;
	return light = to;
}
*/
//-----------------------------------------------------------------------------
public int QuerySunBright() { return pSunBright; }
public int SetSunBright(int s) { return pSunBright = s; }

public int QuerySunLight() {
  mixed in;
  return (in = QueryOutdoors())
           ? (QuerySunBright() * in->QuerySunLight()) / MAX_SUNBRIGHT
           : 0;
}

public void light_from_inside(int l) {
    filter_objects(all_inventory() - ({ PO }), "light_from_outside", l);
    pIntLight += l;
}

public void emit_intlight(int l) {
    filter_objects(all_inventory(), "light_from_outside", l);
    pIntLight += l;
}

public varargs int QueryIntLight(int nosun) {
  return nosun ? pIntLight : pIntLight + QuerySunLight();
}
public varargs int SetIntLight(int l, int nosun) {
  emit_intlight(l -= nosun ? pIntLight : pIntLight + QuerySunLight() );
  pIntBright += l;
  return pIntLight;
}
public int AddIntLight(int l) {
  light_from_inside(l);
  return pIntLight;
}

/* Nasty hack to circumvent inheritance problems */
protected static void _add_int_light (int l) {
  pIntLight += l;
}

public int QueryBright()    { return pIntBright; }
public int SetBright(int l) {
  emit_intlight(l - pIntBright);
  return pIntBright = l;
}
//-----------------------------------------------------------------------------

public mapping QueryMagicProtection() {
	return pMagicProp;
}

public mapping SetMagicProtection(mapping map) {
	if (mappingp(map)) {
    	pMagicProp = copy(map);
    }
	return pMagicProp;
}

public string AddMagicProtection(int type, string message) {
	pMagicProp[type] = message;
	return pMagicProp[type];
}

public varargs mapping ForbidAllMagic(string str) {
	if (!str) {
    	str = "Aquí no puedes usar magia...\n";
    }
	SetMagicProtection(([ST_ALL:str]));
	return QueryMagicProtection();
}

public string QueryIsMagicForbidden(int type) {
	return pMagicProp && (pMagicProp[type] || pMagicProp[ST_ALL]);
}

public int QueryTPort() {
	return (IS_LEARNER(TP) && !TP->Query(P_NOWIZ)) ? TPORT_BOTH : pTport;
}

public int SetTPort(int t) {
	return pTport = t;
}

public int SetSafe(int i) {
	return pSafe=i;
}

public int QuerySafe() {
	return pSafe;
}

/* gestión de peso y de número de objetos */

public int QueryMaxInv() {
	return maxinv;
}

public int SetMaxInv(int to) {
	return maxinv = to;
}

public int QueryWeightContent() {
	return weight;
}

public int QueryMaxWeight() {
	return maxweight;
}

public int SetMaxWeight(int to) {
	if (to < weight) {
    	return maxweight = weight;
    }
	return maxweight = to;
}

public int AddIntWeight(int w) {
	return weight += w;
}

public int AddIntWeight(int w) {
	AddIntWeight(w);
	return TO->QueryWeight();
}

public int MayAddIntWeight(int w) {
	return ((weight + w) <= maxweight);
}

public int MayAddItem() {
	return ((sizeof(all_inventory()) + 1) <= QueryMaxInv());
}

/* control de entrada de objetos */

public int allow_enter(int method, mixed extra) {
	if(method == M_TELEPORT && !(QueryTPort() & TPORT_IN)) {
    	return ME_NO_ENTER;
    }

	if (!MayAddItem() || !MayAddIntWeight((int)PO->QueryWeight())) {
    	return ME_TOO_HEAVY;
    }

	return ME_OK;
}

public void notify_leave(mixed to, int method, mixed extra) {
	string str;

/* [Nyh] Cambio esto:
	light -= PO->QueryLight();
//Por lo siguiente:
*/
    emit_intlight(-to_int(PO->QueryLight()));
    PO->light_from_outside(-QueryIntLight());

	if ((!living(PO) && !PO->QueryIsNPC()) || PO->QueryInvis()) {
    	return;
    }

	str = capitalize(PO->QueryShort() || PO->QueryName() || "alguien");
	if (method == M_GO) {
    	if (stringp(extra)) {
        	if (member(DIR_EXIT, extra) != -1) {
            	str += " se va en dirección " + extra;
            }
        	else if (member(UPNDOWN_EXIT, extra) != -1) {
            	str += " va hacia " + extra;
            }
        	else {
            	str += " se va";
            }
        }
    	else {
        	str += " se va";
        }
    }
	else {
    	str += " desaparece";
    }
	tell_room(TO, ({ MSG_SEE, str + ".\n" }), ({ PO }));
}

public void notify_enter(mixed from, int method, mixed extra) {
	string str;

/* [Nyh] Cambio esto:
	light += PO->QueryLight();
//por lo siguiente:
*/
    PO->light_from_outside(QueryIntLight()-to_int(PO->QueryLight()));
    emit_intlight(to_int(PO->QueryLight()));

	if ((!living(PO) && !PO->QueryIsNPC()) || PO->QueryInvis()) {
    	return;
    }

	str = capitalize(PO->QueryShort() || PO->QueryName() || "alguien");
	if (method == M_GO) {
    	if (stringp(extra)) {
        	if (member(DIR_EXIT, extra) != -1) {
            	str += " viene por el " + extra;
            }
        	else if (member(UPNDOWN_EXIT, extra) != -1) {
            	str += "llega desde " + extra;
            }
        	else {
            	str += " llega";
            }
        }
    	else {
        	str += " llega";
        }
    }
	else {
    	str += " aparece";
    }
	tell_room(TO, ({ MSG_SEE, str + ".\n" }), ({ PO }));
}


public varargs mixed Locate(mixed what, int mode, object * also) {
	return locate(TO, what, mode, also);
}

static int _display_filter(object rec, mixed msg) {
	if (!rec) {
    	return 0;
    }
	if (!living(rec) && !rec->CanSee()) {
    	return 0;
    }

	return 0;
}

public varargs object *display(mixed *msg, mixed excl) {
	object *excl2;
	if (!excl) {
    	excl = ({});
    }
  	else if (!pointerp(excl)) {
      	excl = ({ excl });
      }

  	if (stringp(msg)) {
      	msg = ({ msg, 0 });
      }
  	excl2 = filter(all_inventory(TO)-excl, SF(_display_filter), msg);
  	msg = ({ MSG_SEE }) + msg;
  	tell_room(TO, msg, excl + excl2);
  	return excl + excl2;
}

public void create() {
	server = NIGHTDAY;
	pIndoors = 1;
	pMagicProp = ([]);
	pSafe = 0;
	pTport = TPORT_BOTH;
	weight = 0;
	maxweight = 1<<30;
	maxinv = 100;
/* [Nyh] Cambio esto:
	light = 0;
	useSunlight = 1;
//Por lo siguiente:
*/
    pSunBright = MAX_SUNBRIGHT;
    pIntLight = 0;
    pIntBright = 0;
}
