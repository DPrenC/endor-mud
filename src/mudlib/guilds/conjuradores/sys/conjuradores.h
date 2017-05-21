/* SIMAURIA '/guilds/conjuradors/sys/conjuradores.h'
   =================================================
   [w] Woo@simauria

   11-10-99 [w] Empezamos...
*/

#ifndef __CONJURADORES_H__
#define __CONJURADORES_H__

/* ############## GREMIO DE CONJURADORES ############## */

#define GCONJURADORES       PPATH "conjuradores/"
#define OBJETO(x)           GCONJURADORES "obj/"+x
#define CONJ_SAVE(x)        GUILDLOGPATH "conjuradores/"+x
#define LOG(x,y)            write_file(GUILDLOGPATH "conjuradores/" + x, y)

/* ############## FUNCIONES MAS USADAS ############## */

#define OWNER         QueryObjectOwner()

/* ############## COLORES ############## */

#define CNEGRITA       "[1m"
#define CSUBR          "[4m"
#define CPARP          "[5m"
#define CINVERS        "[6m"
#define CNORMAL        "[0m"
#define CNEGRO         "[30m"
#define CROJO          "[31m"
#define CVERDE         "[32m"
#define CAMARILLO      "[33m"
#define CAZUL          "[34m"
#define CVIOLETA       "[35m"
#define CCIAN          "[36m"
#define CBLANCO        "[37m"
#define CCNORMAL       "[39m"

#endif
