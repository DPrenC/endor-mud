/* SIMAURIA '/sys/magia.h'
   =======================
   [w] Woo@simauria

   04-04-99 [w] Creado este archivo.
   05-04-99 [w] Añadidas las detecciones de mproperties.h y las definiciones
                de teleport de magic.h
   06-04-99 [w] Incluyo combat.h aquí asi como la definición de MAGICD.
   07-04-99 [w] Añadido SPELL(x) que devuelve el fichero del conjuro
                con nombre 'x'.
   14-04-99 [w] Añadidas alguna que otra definicion ST_
   16-04-99 [w] Añadida la definición NO_PUEDE.
*/

#ifndef __MAGIA_H__
#define __MAGIA_H__

#include <combat.h>

#define STD_SPELL	"/std/magia/spellbase"

#ifndef MAGICD
#define MAGICD		"/secure/daemons/magicd"
#endif

#define SPELL(x)        MAGICD->QueryFileSpell(x) // (string) path fichero

// Detecciones
#define MP_DETECTINVIS		P_SEE_INVIS
#define MP_DETECTMAGIC		"mpDetectMagic"
#define MP_DETECTEVIL		"mpDetectEvil"
#define MP_DETECTGOOD		"mpDetectGood"
#define MP_DETECTHIDDEN		"mpDetectHidden"

// values for teleport forbid property
#define TPORT_NO   0		// No teleport allowed
#define TPORT_IN   1		// Only teleport in allowed
#define TPORT_OUT  2		// Only teleport out allowed
#define TPORT_BOTH (TPORT_IN | TPORT_OUT) // default

#define NO_PUEDE      0
#define ST_ALL        0			// All kind of spells

#define ST_DAMAGE     TD_MAGICO         // First attack spell
#define ST_FIRE       MT_FIRE           // fire spells of any kind
#define ST_COLD       MT_COLD        	// spells which produce coldness
#define ST_WATER      MT_WATER       	// water damage (hot water)
#define ST_GAS        MT_GAS         	// poison gas
#define ST_POISON     MT_POISON        	// poison ....
#define ST_ZAP        MT_ZAP         	// Destruct one/more LIVING(s)
#define ST_ELECTRO    MT_ELECTRO      	// Electrical damage
#define ST_ACID       MT_ACID      	// splash of acid damage
#define ST_PSYCHO     MT_PSYCHO      	// Mind damages

#define ST_OTHER      (32)              // All other non attack spelltypes
#define ST_KNOW       (ST_OTHER +  2)	// Increases knowledge
#define ST_PROTECT    (ST_OTHER +  3)	// protects you from something
#define ST_HEAL       (ST_OTHER + 4)	// healing spells
#define ST_CREATE     (ST_OTHER + 5)	// you can create something with them
#define ST_SUMMON     (ST_OTHER + 6)	// you can summon something
#define ST_TELEPORT   (ST_OTHER + 7)	// teleport spells
#define ST_INFLUENCE  (ST_OTHER + 8)	// mind influence spells
#define ST_CHARM      ST_INFLUENCE      // charm is influence
#define ST_LIGHT      (ST_OTHER + 9)	// cast light spells
#define ST_CHANGE     (ST_OTHER + 10)	// change items/objects/livings/props
#define ST_DARK       (ST_OTHER + 11)	// dark (evil) spells
#define ST_DESTRUCT   (ST_OTHER + 12)   // destruct a THING
#define ST_FUN        (ST_OTHER + 13)   // FUN Spells

#endif
