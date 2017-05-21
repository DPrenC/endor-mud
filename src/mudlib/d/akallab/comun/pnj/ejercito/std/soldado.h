/* 
DESCRIPCION  : macros del pnj base del ejercito orco
FICHERO      : soldado.h
MODIFICACION : 02-03-00 [Angor@Simauria] Creacion
*/

//cosas relacionadas con la experiencia
#define SO_EXP_NOVATO 0
#define SO_EXP_NORMAL 1
#define SO_EXP_EXPERTO 2
#define SO_EXP_AS 3
#define SO_EXP_PROB ({0,20,60,90,100}) //20%,40%,30%,10%
#define SO_EXP_BONUS ({-2,0,2,6})
#define SO_EXP_MAS ({"novato","","experto","muy experto"})
#define SO_EXP_FEM ({"novata","","experta","muy experta"})

//cosas relacionadas con la edad
#define SO_EDAD_JOVEN 0
#define SO_EDAD_NORMAL 1
#define SO_EDAD_VIEJO 2
#define SO_EDAD_PROB ({0,40,80,100}) //40%,40%,20%
#define SO_EDAD_BONUS ({0,1,-1})
#define SO_EDAD_MAS ({"joven","","viejo"})
#define SO_EDAD_FEM ({"joven","","vieja"})

//cosas relacionadas con el grado los soldados
#define SO_GRADO_SOLDADO 1
#define SO_GRADO_CABO 2
#define SO_GRADO_SARGENTO 3
#define SO_GRADO_TENIENTE 4
#define SO_GRADO_CAPITAN 5
#define SO_GRADO_COMANDANTE 6
#define SO_GRADO_CORONEL 7
#define SO_GRADO_GENERAL 8
#define SO_GRADO_MAS ({"soldado","cabo","sargento","teniente","capitan","comandante","coronel","general"})
#define SO_GRADO_FEM ({"soldada","cabo","sargenta","teniente","capitana","comandante","coronela","generala"})
#define SO_GRADO_NIVEL_BASE ({15,20,25,30,35,39,43,47})

//cosas relacionadas con la clase de los soldados
#define SO_CLASE_GUERRERO 0
#define SO_CLASE_ARQUERO 1
#define SO_CLASE_GUARDIA 2
#define SO_CLASE_LANZAHACHAS 3
#define SO_CLASE_EXPLORADOR 4
#define SO_CLASE_MAS ({"guerrero","arquero","guardia","lannzador de hachas","explorador"})
#define SO_CLASE_FEM ({"guerrera","arquera","guardia","lanzadora de hachas","exploradora"})

#define SO_SEXO_PROB  50 //50% M, 50% H
#define SO_SEXO_BONUS ({2,0})

#define SO_RAZA_MAS ({"orco","troll","gigante"})
#define SO_RAZA_FEM ({"orca","troll","giganta"})

#define SO_HABLAR_PROB 30 //30% hablan
