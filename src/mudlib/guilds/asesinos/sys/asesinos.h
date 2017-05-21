#ifndef __ASESINOS_H
#define __ASESINOS_H
/*############ DEFINES DEL GREMIO ################*/
#include <properties.h>
#include <gremios.h>
#include <skills.h>
#include <config.h>

#define GN_ASESINOS     "Gremio de Las Rosas Negras"

#define GASESINOS       PPATH "asesinos/"
#define OBJETO(x)       GASESINOS "obj/"+x
#define ASESINO_SAVE(x) GUILDLOGPATH "asesinos/"+x
#define HOME(x)         GASESINOS "habitacion/"+x
#define LOG(x,y)        write_file(GUILDLOGPATH "asesinos/" + x, y)

/* ############## OTRAS DEFINICIONES ############## */

#define MUY_BUENO       600
#define BUENO           295
#define MALO            -200
#define MUY_MALO        -600

#define COMANDOS_PERMITIDOS_ESCONDIDO ({ "=gremio","ayuda","charset","cls",\
	"color","compararse","conjuros","coraje","email","equipo",\
	"esconderse","estado","gquien","habilidades","hora","i","inv",\
	"inventario","m","mirar","parar","quien","sigilo","tel","telepatia",\
        "pv", \
	"telepatía","tell" })

#define HUMANOID_RACES ({\
"demonio",\
"diablo",\
"draconiano",\
"duende",\
"elfo-oscuro",\
"elfo oscuro",\
"elfo",\
"enano",\
"gigante",\
"gnomo",\
"humano",\
"kainoak",\
"kender",\
"kobold",\
"logath",\
"medio-elfo",\
"medio elfo",\
"orco",\
"troll",\
})

#define IS_HUMANOID(x) (member(HUMANOID_RACES, x->QueryRace())!=-1)

/* ############## ARMADURAS PERMITIDAS ############## */
#define MATERIALES_ILEGALES   ({M_ALUMINIO_TXT,M_PLOMO_TXT,M_ACERO_TXT,M_HIERRO_TXT,M_COBRE_TXT,M_BRONCE_TXT,\
                                M_PLATA_TXT,M_ORO_TXT,M_PLATINO_TXT,M_TITANIO_TXT,M_ADAMANTIO_TXT})

#define MATERIALES_LEGALES  ({M_TELA_TXT,M_CUERO_TXT,M_PIEL_TXT,M_MITHRIL_TXT,M_ESPECIAL_TXT})

#define OTROS_MATERIALES  ({M_MADERA_TXT,M_HUESO_TXT,M_PIEDRA_TXT,M_CRISTAL_TXT})


/* ############## FUNCIONES MAS USADAS ############## */

#define OWNER		QueryObjectOwner()
#define TGENDER		this_player()->QueryGender()

/* ############## COSTE DE LAS HABILIDADES ############## */
#define TP_SIGILO	1

#define TIMER_INMOVILIZAR	10
#define TIMER_ACUCHILLAR	3
#define TIMER_CORTAR_GARGANTAS	3
#define TIMER_CEGAR		2

#define TIME_LURE 60
#define TIME_HOME 50

#define TIMER_ENVIAR TIME_LURE
#define TIMER_ATRAER TIME_HOME

#define MANA_ESCONDERSE 5
#define MANA_SIGILO	0
#define MANA_ACUCHILLAR	10
#define MANA_ENGANYAR	0
#define MANA_DO_VENENO	0
#define MANA_ENVENENAR	5
#define MANA_CUTTHROAT	15
#define MANA_STUN	25
#define MANA_CEGAR	5
#define MANA_FINTAR	5

/* ############## OTROS ############## */
#define NO_MANA(x) (x->QuerySP()<MANA_COST)


/* ############## COLORES ############## */
#define CNEGRITA       "[1m"
#define CSUBR          "[4m"
#define CPARP          "[5m"
#define CINVERS        "[6m"
#define CNORMAL        "[0m"
#define CNEGRO         "[30m"
#define CROJO          "[31m"
#define CVERDE         "[32m"
#define CAMARILLO      "[33m"
#define CAZUL          "[34m"
#define CVIOLETA       "[35m"
#define CCIAN          "[36m"
#define CBLANCO        "[37m"
#define CCNORMAL       "[39m"
#endif
