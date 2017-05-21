/*
DESCRIPCION : macros utiles
MODIFICACION: 15-10-98 [Angor@Simauria] Creacion
              13-02-99 [Angor@Simauria] Ultima modificacion
--------------------------------------------------------------------------------
*/

#include <properties.h>

//funciones utiles
#define MAY(x)   (capitalize(x))
#define MIN(x,y) (x>y?y:x)
#define MAX(x,y) (x>y?x:y)
#define FORALL(x,y) for(x=first_inventory(y);x;x=next_inventory(x))

//gramatica
#define NOMBRE   (capitalize(this_player()->QueryName()))
#define AO       (this_player()->QueryGender()==GENDER_FEMALE?"a":"o")
#define AO2      (QueryGender()==GENDER_FEMALE?"a":"o")
#define AE       (this_player()->QueryGender()==GENDER_FEMALE?"a":"e")
#define AE2      (QueryGender()==GENDER_FEMALE?"a":"e")
#define A_       (this_player()->QueryGender()==GENDER_FEMALE?"a":"")
#define A_2      (QueryGender()==GENDER_FEMALE?"a":"")
#define UNA_     ("un"+A_)
#define UNA_2    ("un"+A_2)
#define ART      (this_player()->QueryGender()==GENDER_FEMALE?"la":"el")
#define ART2     (QueryArtDetString())
#define PRO      (this_player()->QueryGender()==GENDER_FEMALE?"ella":"el")
#define PRO2     (QueryGender()==GENDER_FEMALE?"ella":"el")
#define LAEL     (this_player()->QueryGender()==GENDER_FEMALE?"la":"el")
#define LAEL2    (QueryArtDetString())
#define DELA     (this_player()->QueryGender()==GENDER_FEMALE?"de la":"del"
#define DELA2    (QueryGender()==GENDER_FEMALE?"de la":"del")


