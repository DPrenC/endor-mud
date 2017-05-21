/***********************************************************
*                QUIERO USAR HABS!!!                       *
*  Fichero: usahab.h					   *
*  creacion(fusilamiento): 17-5-00			   *
*  version: 1.0						   *
************************************************************
*/

#ifndef _USAHAB_
#define _USAHAB_ "17-5-00"

/* --- ALGUNAS DEFINICIONES FUNCIONES --- */

#define OWNER		QueryObjectOwner()

#define CAPIT(x)	capitalize(x)

#define GENDER(x)	x->QueryGender()
#define ISPLAYER(x)	x->QueryIsPlayer()

/* --- COLORES --- */

#define H_NEGRITA	"[1m"
#define H_SUBR		"[4m"
#define H_PARPADEO	"[5m"
#define H_INVERSO	"[6m"
#define H_NORMAL	"[0m"
#define H_NEGRO		"[30m"
#define H_ROJO		"[31m"
#define H_VERDE		"[32m"
#define H_AMARILLO	"[33m"
#define H_AZUL		"[34m"
#define H_VIOLETA	"[35m"
#define H_CIAN		"[36m"
#define H_BLANCO	"[37m"
#define H_GRIS		"[39m"

#endif
