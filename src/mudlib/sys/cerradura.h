/*
	SIMAURIA [/sys/puerta.h]
	========
	
	  [g] Guybrush
	  
	08/11/98 [g] Creacion de todo.
	23/11/98 [g] Anyade nuevas propiedades.
	07/11/98 [g] Anyadido el valor CERRADURA_ANTI_GANZUA.
	
	NOTA: Por favor, las posibles modificaciones, notificadmelas e
        indicadlas con fecha brevemente en esta cabecera, y mas extensamente
        en la cabecera de la funcion modificada. 
*/

#ifndef _CERRADURA_
#define _CERRADURA_

/* --- PROPIEDADES --- */

#define P_CERRADURA		"Lock"
#define P_CERRADURA_ESTADO	"LockState"
#define P_CERRADURA_IDS		"LockIds"
#define P_CERRADURA_SEGURIDAD	"LockSecurity"
#define P_CERRADURA_RESISTENCIA	"LockResistance"
#define P_CERRADURA_CONECTADA	"LockConnected"

#define P_LLAVE_IDS		"KeyIds"

#define P_GANZUA_PODER		"PickPower"
#define P_GANZUA_ESTADO		"PickState"

/* --- VALORES --- */

// ESTADO
#define CERRADURA_CERRADA	0
#define CERRADURA_ABIERTA	1

// OTROS
#define CERRADURA_INACTIVO	0
#define CERRADURA_ACTIVO	1
#define CERRADURA_ANTI_GANZUA	-1

/* --- ESTANDARES --- */

#define STD_LLAVE		"/std/puerta/llave"
#define STD_GANZUA		"/std/puerta/ganzua"

#endif