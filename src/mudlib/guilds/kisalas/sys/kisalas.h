/*=======================================================================*
 |                   <<   Gremio de las Kisalas   >>                     |
 *=======================================================================*
 | [w] Woo@simauria                                                      |
 | [a] Avengelyne@simauria                                               |
 |                                                                       |
 | 09-10-98 [w] Creación de este archivo.                                |
 | 13-03-99 [w] Eliminadas las definiciones que ahora están en guild.h   |
 | 23-03-99 [w] Las amazonas pasan a llamarse kisalas.                   |
 *=======================================================================*/

#ifndef __KISALAS_H__
#define __KISALAS_H__


/* ############## GREMIO DE AMAZONAS ############## */

#define AMAZONHOME          PPATH "kisalas/"         // Direc. Amazonas
#define LAGO(x)             "/d/goldhai/comun/habitacion/lago/" + x
#define AM_PNJ(x)           AMAZONHOME "pnj/" + x
#define AM_OBJETO(x)        AMAZONHOME "obj/"+x          // Objetos
#define ARMA_GOLDHAI(x)     "/d/goldhai/comun/objeto/arma/"+x
#define PROT_GOLDHAI(x)     "/d/goldhai/comun/objeto/proteccion/"+x
#define AMAZONA_SAVE(x)     GUILDLOGPATH "kisalas/"+x

// habitaciones varias
#define AM_ROOM(x)          AMAZONHOME "habitacion/"+x
#define AM_VARIOS(x)        AM_ROOM("varios/" + x)
#define AM_ARENA(x)         AM_ROOM("arena/" + x)
#define AM_VESTIBULO(x)     AM_ROOM("vestibulo/" + x)
#define AM_PASILLO(x)       AM_ROOM("pasillo/" + x)
#define SUELO_ARENA         AM_ARENA("suelo_base")



/* ############## pnjs de la arena ################ */

#define AM_PNJ_ARENA(x)     AM_PNJ("arena/" + x)
#define ANIMAL_BASE         AM_PNJ_ARENA("animal_base")
#define DEPREDADOR          AM_PNJ_ARENA("depredador")



#define MASCOTA             AMAZONHOME "pnj/mascota"    // Arch. mascotas
#define GUILD_STD           AMAZONHOME "std/"
#define INTERIOR_BASE       GUILD_STD "interior_base"
#define LOG(x,y)            write_file(GUILDLOGPATH "kisalas/" + x, y)


/* ############## OTRAS DEFINICIONES ############## */

#define BUENO               295
#define MALO                -200
#define MUY_MALO            -600

/* ############## FUNCIONES MAS USADAS ############## */

#define OWNER               QueryObjectOwner()
#define TGENDER             TP->QueryGender()


#endif
