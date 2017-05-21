
/* SIMAURIA '/sys/gremios.h'
   =======================
   [t] Theuzifan

   27-11-99 [t] Creación
   28-02-00 [w] Metidos los clerigos.
   11-02-03 [t] Añado GUILD_PATH
*/

#ifndef _GREMIOS_H
#define _GREMIOS_H

#define GC_GUARDABOSQUES "guardabosque"
#define GC_AVENTUREROS  "aventurero"
#define GC_KISALAS      "kisala"
#define GC_GUERREROS    "guerrero"
#define GC_CONJURADORES "conjurador"
#define GC_HECHICEROS   "hechicero"
#define GC_ASESINOS     "asesino"
#define GC_CLERIGOS     "clerigo"
#define GC_EXPLORADORES     "explorador"

#define GC_GUARDABOSQUE	GC_GUARDABOSQUES
#define GC_AVENTURERO	GC_AVENTUREROS
#define GC_KISALA	GC_KISALAS
#define GC_GUERRERO	GC_GUERREROS
#define GC_CONJURADOR	GC_CONJURADORES
#define GC_HECHICERO	GC_HECHICEROS
#define GC_ASESINO	GC_ASESINOS
#define GC_CLERIGO	GC_CLERIGOS
#define GC_EXPLORADOR	GC_EXPLORADORES

//guilds para pnj			combate/magia
#define GC_EXPERTO	"experto"  //	bueno	bueno
#define GC_LUCHADOR	"luchador" //	bueno	malo
#define GC_NINGUNO	"ninguno"  //	regular	regular
#define GC_MAGO		"mago"     //	malo	bueno
#define GC_TORPE	"torpe"    //	malo	malo
//guilds genericos para pnj, estos no incluyen habilidades.
#define GC_CB_MB	"CB/MB"	   //	bueno	bueno
#define GC_CB_MR	"CB/MR"	   //	bueno	regular
#define GC_CB_MM	"CM/MM"	   //	bueno	malo
#define GC_CR_MB	"CR/MB"	   //	regular	bueno
#define GC_CR_MR	"CR/MR"	   //	regular	regular
#define GC_CR_MM	"CR/MM"	   //	regular	malo
#define GC_CM_MB	"CM/MB"	   //	malo	bueno
#define GC_CM_MR	"CM/MR"	   //	malo	regular
#define GC_CM_MM	"CM/MM"	   //	malo	malo
//----

#define GUILD_PATH ([\
	GC_GUARDABOSQUES:	"/guilds/guardabosques/",\
	GC_AVENTUREROS:		"/guilds/aventurero/",\
	GC_KISALAS: 		"/guilds/kisalas/",\
	GC_GUERREROS: 		"/guilds/guerreros/",\
	GC_CONJURADORES: 	"/guilds/conjuradores/",\
	GC_HECHICEROS: 		"/guilds/hechiceros/",\
	GC_ASESINOS: 		"/guilds/asesinos/",\
	    GC_EXPLORADORES: 		"/guilds/exploradores/",\
	GC_CLERIGOS: 		"/guilds/clerigos/"])
// Gremios permitidos en Simauria
#define GC_LEGALES ({GC_KISALAS,GC_GUERREROS,GC_CONJURADORES,GC_AVENTUREROS,\
                     GC_HECHICEROS,GC_GUARDABOSQUES,GC_CLERIGOS,GC_ASESINOS,GC_EXPLORADORES,\
                     GC_EXPERTO, GC_LUCHADOR, GC_NINGUNO, GC_MAGO, GC_TORPE,\
                     GC_CB_MB, GC_CB_MR, GC_CB_MM, GC_CR_MB, GC_CR_MR, \
                     GC_CR_MM, GC_CM_MB, GC_CM_MR, GC_CM_MM })

#define VALID_GUILDCLASS(gc) (member(GC_LEGALES, gc) > -1)

// Gremios que pueden memorizar conjuros/hechizos (solo para pj)
#define GC_MAGIA ({GC_KISALAS,GC_CONJURADORES,GC_HECHICEROS })
// Gremios que NO pueden memorizar conjuros/hechizos (solo para pj)
#define GC_LUCHA ({GC_GUERREROS, GC_LUCHADOR, GC_ASESINOS })

#define GC_CANALIZACION ({GC_GUARDABOSQUES,GC_CLERIGOS})
#define GC_MENTALISMO ({GC_KISALAS})
#define GC_ESENCIA ({GC_CONJURADORES,GC_HECHICEROS})

//--- para puntos de vida y magia, tipo sale de GUILD_COMBAT o GUILD_MAGIC
#define BASE_POINTS	25
#define BASE_LEVEL	2
#define TIPO_MULT	2
#define MAX_POINTS(tipo,stat)	(BASE_POINTS+stat*(BASE_LEVEL+tipo*TIPO_MULT))
#define NPC_POINTS(x)	(x*4)/3 //los npc tienen mas puntos...
//---
//gremios respecto a la habilidad de combate, puntuacion sobre 4 (D&D3ª)
#define COMBATE_MAX	4 //sobre cuanto se puntua el combate
#define COMBATE_BUENO	4
#define COMBATE_REGULAR	3
#define COMBATE_MALO	2

#define GUILD_COMBAT ([\
	GC_EXPERTO:	  COMBATE_BUENO,\
	GC_LUCHADOR:	  COMBATE_BUENO,\
	GC_GUARDABOSQUES: COMBATE_BUENO,\
	GC_AVENTUREROS:   COMBATE_BUENO,\
	    GC_EXPLORADORES:   COMBATE_BUENO,\
	GC_KISALAS:	  COMBATE_BUENO,\
	GC_GUERREROS:	  COMBATE_BUENO,\
	GC_ASESINOS:	  COMBATE_REGULAR,\
	GC_CLERIGOS:	  COMBATE_REGULAR,\
	GC_NINGUNO:	  COMBATE_REGULAR,\
	GC_CONJURADORES:  COMBATE_MALO,\
	GC_HECHICEROS:	  COMBATE_MALO,\
	GC_MAGO:	  COMBATE_MALO,\
	GC_TORPE:	  COMBATE_MALO,\
	GC_CB_MB:	  COMBATE_BUENO,\
	GC_CB_MR:	  COMBATE_BUENO,\
	GC_CB_MM:	  COMBATE_BUENO,\
	GC_CR_MB:	  COMBATE_REGULAR,\
	GC_CR_MR:	  COMBATE_REGULAR,\
	GC_CR_MM:	  COMBATE_REGULAR,\
	GC_CM_MB:	  COMBATE_MALO,\
	GC_CM_MR:	  COMBATE_MALO,\
	GC_CM_MM:	  COMBATE_MALO,\
	     	     ])

#define MAX_HP(gremio,stat) MAX_POINTS(GUILD_COMBAT[gremio||GC_NINGUNO],stat)

//gremios respecto a la habilidad de magia, puntuacion sobre 4 (D&D3ª)
#define MAGIA_MAX	4 //sobre cuanto se puntua el magia
#define MAGIA_BUENO	4
#define MAGIA_REGULAR	3
#define MAGIA_MALO	2
#define SP_MAGIA	3 //por que multiplicas el magia para hallar SP

#define GUILD_MAGIC ([\
	GC_GUARDABOSQUES: MAGIA_REGULAR,\
	GC_AVENTUREROS:   MAGIA_REGULAR,\
	    GC_EXPLORADORES:   MAGIA_REGULAR,\
	GC_KISALAS:	  MAGIA_REGULAR,\
	GC_NINGUNO:	  MAGIA_REGULAR,\
	GC_TORPE:	  MAGIA_MALO,\
	GC_GUERREROS:	  MAGIA_MALO,\
	GC_ASESINOS:	  MAGIA_MALO,\
	GC_LUCHADOR:	  MAGIA_MALO,\
	GC_EXPERTO:	  MAGIA_BUENO,\
	GC_CLERIGOS:	  MAGIA_BUENO,\
	GC_CONJURADORES:  MAGIA_BUENO,\
	GC_HECHICEROS:	  MAGIA_BUENO,\
	GC_MAGO:	  MAGIA_BUENO,\
	GC_CB_MB:	  MAGIA_BUENO,\
	GC_CB_MR:	  MAGIA_REGULAR,\
	GC_CB_MM:	  MAGIA_MALO,\
	GC_CR_MB:	  MAGIA_BUENO,\
	GC_CR_MR:	  MAGIA_REGULAR,\
	GC_CR_MM:	  MAGIA_MALO,\
	GC_CM_MB:	  MAGIA_BUENO,\
	GC_CM_MR:	  MAGIA_REGULAR,\
	GC_CM_MM:	  MAGIA_MALO,\
	     	     ])
#define MAX_SP(gremio,stat) MAX_POINTS(GUILD_MAGIC[gremio||GC_NINGUNO],stat)

//se le introduce un string y si es un gremio valido lo devuelve y si no 0
#define VALIDA_GREMIO(x)	((member(GC_LEGALES,x)>-1)?x:0)

#endif
