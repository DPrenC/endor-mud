/*
DESCRIPCION  : valores por defecto para un ciudadano generico
FICHERO      : /d/akallab/sys/ciudadano.h
MODIFICACION : 15-10-98 [Angor@Simauria]Creacion
--------------------------------------------------------------------------------
*/

//Tipos de edades
#define ES_BEBE   0  // 0-2   anyos
#define ES_NINYO  1  // 3-10  anyos
#define ES_ADOL   2  // 11-20 anyos
#define ES_JOVEN  3  // 21-30 anyos
#define ES_ADULTO 4  // 31-60 anyos
#define ES_VIEJO  5  // >60   anyos

//textos de las edades
#define EDAD ({"bebe","bebe","ninyo","ninya","adolescente","adolescente","joven","joven","adulto","adulta","viejo","vieja"})

//niveles de decision entre cada tipo (5%, 10%, 10%, 20%, 40%, 15%)
#define UMBRAL ({0,5,15,25,45,85,100})

//probabilidades
// * si se es macho, la probabilidad de borrachera aumenta un 5%
// * solo se puede estar borracho si la edad es >=ES_ADOL
#define PROB_GUERRERO 30  // de ser guerrero (25%)
#define PROB_BORRACHO 10  // de estar borracho (10%)

//niveles del PNJ para cada una de las posibles edades
// * las hembras tienen un nivel menos
// * los guerreros tienen 3 niveles mas
#define NIVEL_MIN ({1,1,2,3,4,3})
#define NIVEL_MAX ({3,4,6,8,10,5})

//nombres masculinos
#define N_MAS ({"Gulkas","Sukko","Morlak","Akkefe","Norun","Tagalo","Sankadan","Neko","Garr"})
//nombres femeninos
#define N_FEM ({"Gara","Yakada","Shaalee","Mikkada","Larinna","Netee","Magenne","Shinn","Tana"})

//dinero [formato: (columnas=oro,plata,cobre),(filas=edad)]
#define DINERO ({0,0,0,\
0,0,random(10)+5,\
0,random(4)+1,random(20)+10,\
0,random(10)+2,random(25)+15,\
random(10)+2,random(20)+5,random(25)+20,\
random(3)+1,random(10)+3,random(25)+15\
})
