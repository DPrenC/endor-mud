/**
 * /guilds/hechiceros/sys/hechiceros.h
 */

#ifndef __HECHICEROS_H__
#define __HECHICEROS_H__

/* --- GREMIO DE HECHICEROS --- */

#define H_HOME          "/guilds/hechiceros/"
#define H_AYUDA(x)	H_HOME "ayuda/" + x
#define H_DOCS(x)	H_HOME "docs/" +x
#define H_OBJETO(x)	H_HOME "obj/" + x
#define H_SAVE(x)	GUILDLOGPATH "hechiceros/" + x
#define H_LOGDIR	GUILDLOGPATH "hechiceros/"
#define H_LOG(x,y)	write_file( H_LOGDIR + x, y )

/* --- ESTANDARES --- */


/* --- ALGUNAS DEFINICIONES FUNCIONES --- */

#define OWNER		QueryObjectOwner()

#define CAPIT(x)	capitalize(x)

#define GENDER(x)	x->QueryGender()

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

/* --- OTRAS --- */

#endif
