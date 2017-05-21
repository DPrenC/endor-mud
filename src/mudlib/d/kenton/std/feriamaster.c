/* /obj/questctrl/feriamaster.c
Objeto para el control de los puntos que ganan los jugadores en la feria
Forma parte del quest llamado 'DraegoQuest'

	[h] Nyh@Simauria

     06-04-03	[h] Creación

*/

#include "/d/kenton/sys/feria.h"
#define MAX_LISTA	10 //maximo d jugatas q salen en la lista
#define NDATOS		23 //22 pruebas + puntos gastados = 23
#define DATOS 		"/d/kenton/comun/save/feria/puntos" //donde se guardan los datos
#define PD		"/obj/player_dummy"
#define ART(x)		(x==2?"a":"o") //x es el querygender

//orden en el mapping:
#define PUNTOS_GASTADOS		0
//Las kender:
#define PUNTOS_PATOS	1	// "Los Pescapatos"
#define PUNTOS_ROBO	2	// "Robo al Muñeco"
#define PUNTOS_HONDA	3	// "Tiro con Honda"
#define PUNTOS_SACO	4	// "Salto con Saco"
//Las humanas:
#define PUNTOS_PETANCA	5	// "La Petanca"
#define PUNTOS_POTRO	6	// "El Potro Salvaje"
#define PUNTOS_DUENDE	7	// "La Barraca del Duende"
#define PUNTOS_FUERZA	8	// "Mide tu Fuerza"
#define PUNTOS_CERDO	9	// "Agarra el Cerdo"
#define PUNTOS_BINGO	10	// "El Bingo"
//Las elfas:
#define PUNTOS_ARCO	11	// "Tiro con Arco"
#define PUNTOS_CUCHILLOS 12	// "Esquivar Cuchillos"
#define PUNTOS_TRONCO	13	// "Trepar Tronco"
#define PUNTOS_DARDOS	14	// "Lanzar Dardos"
//Las orcas:
#define PUNTOS_CRANEOS	15	// "Revienta Cráneos"
#define PUNTOS_VISCERAS	16 	// "Lanzamiento de Vísceras"
#define PUNTOS_ELFO	17	// "Tiro al Elfo"
#define PUNTOS_GRUNYIO	18	// "Er Gruñio"
//Las enanas
#define PUNTOS_HACHAZO	19	// "El Hachazo"
#define PUNTOS_BIRRERIA	20	// "Birreria"
#define PUNTOS_QUIEN	21	// "Quien es Quien"
#define PUNTOS_TUMBAMUROS 22	// "Tumbamuros"
#define NUMERO_PRUEBAS	PUNTOS_TUMBAMUROS

#define ARRAY_POSICIONES ({PUNTOS_PATOS, PUNTOS_ROBO, PUNTOS_HONDA, \
			PUNTOS_SACO, PUNTOS_PETANCA, PUNTOS_POTRO, \
			PUNTOS_DUENDE, PUNTOS_FUERZA, PUNTOS_CERDO, \
			PUNTOS_BINGO, PUNTOS_ARCO, PUNTOS_CUCHILLOS, \
			PUNTOS_TRONCO, PUNTOS_DARDOS, PUNTOS_CRANEOS, \
			PUNTOS_VISCERAS, PUNTOS_ELFO, PUNTOS_GRUNYIO, \
			PUNTOS_HACHAZO, PUNTOS_BIRRERIA, PUNTOS_QUIEN, \
			PUNTOS_TUMBAMUROS })
//nota: ARRAY_POSICIONES tiene el mismo orden que CASETAS, sino peta!
#define CASETA_A_POSICION    mkmapping(CASETAS,ARRAY_POSICIONES)

#define PUNTOS_TOTALES	100
#define PUNTOS_RESTANTES 101

#define ERROR	-1
#define GASTA_INSUFICIENTES	0

#define LENGTH		30 //estos valores son de la lista
#define LENGTH_NOMBRE	15 //idem

public varargs void CargarPuntos();

public mapping puntos; // ([nombre:puntos_totales;puntos_restantes])

/* FUNCIONES */
/*
public int PropSexo(string pl) {
  mapping props;
  if (props=PD->QueryProperties(pl)) return props[P_GENDER];
  else return 1;
}
*/
// Carga el archivo de Puntos
public varargs void CargarPuntos() { if (!puntos && (restore_object(DATOS),!puntos)) puntos=m_allocate(0,NDATOS);}
// Graba el archivo de Puntos
public varargs void SalvarPuntos()
  { seteuid(getuid());
    save_object(DATOS);
}

//Devuelve los puntos tipo <flag> del jugador <pl>
public varargs int puntos(string pl, mixed flags) {
  int i;
  if (stringp(flags)) flags=CASETA_A_POSICION[flags];
  if (!puntos) CargarPuntos();
  switch (flags) {
    case PUNTOS_GASTADOS..NUMERO_PRUEBAS: flags=puntos[pl,flags]; break;
    case PUNTOS_TOTALES:   for (flags=0,i=NUMERO_PRUEBAS;i--;) flags+=puntos[pl,i]; break;
    case PUNTOS_RESTANTES: for (flags=-(puntos[pl,PUNTOS_GASTADOS]),i=NUMERO_PRUEBAS+1;--i;) flags+=puntos[pl,i]; break;
    default: flags=0;
  }
  return flags;
}
// Comprueba que un jugata esta en la Tabla
public int JugadorPresente(string pl)
  { return member(puntos?(CargarPuntos(),puntos||([])):puntos,pl); }

//nota: solo se pueden SUMAR puntos
//Añade al jugador <pl> los puntos por haber resultado <i> en la prueba <pr>
//devuelve -1 si error o el numero de puntos sumados (q puede ser 0)
public int AddPuntos(mixed pl, string pr, int i) {
  if (!pl || !pr || i<0) return ERROR;
  if (!stringp(pl)) {
    if (objectp(pl) && pl->QueryIsPlayer()) pl=pl->QueryName();
    else return ERROR;
  }
  if (!puntos) CargarPuntos();
  i = PUNTOS[pr,i]; //aqui cojo los puntos q debo sumarle
  puntos[pl,CASETA_A_POSICION[pr]]=puntos[pl,CASETA_A_POSICION[pr]]+i;
  SalvarPuntos();
  return i;
}

//esta funcion gasta <i> puntos de un jugador <pl>
//devuelve -1 si error, 0 si insuficientes y los gastados si sí que tiene
//NOTA: NO puedes gastar puntos de un jugador q no esta online
//	puede q en el futuro con el player_dummy lo permita, pero de momento no
public int GastaPuntos(mixed pl, int i) {
  if (!pl || (i<=0)) return ERROR;
  if (!stringp(pl)) {
    if (objectp(pl) && pl->QueryIsPlayer()) pl=pl->QueryName();
    else return ERROR;
  }
  if (!puntos) CargarPuntos();
  if (puntos(pl,PUNTOS_RESTANTES)<i) i = GASTA_INSUFICIENTES;
  else puntos[pl,PUNTOS_GASTADOS]=puntos[pl,PUNTOS_GASTADOS]+i;
  SalvarPuntos();
  return i;
}

private int comparar(int a, int b) { return a > b; } //esto ordena al derecho
//  array = sort_array(array, SF(<); )ordena el array al reves

//en flags le indicamos q ordena (PUNTOS_xxx)
protected int chk(string pl1, string pl2, mixed flags)
  { return comparar(puntos(pl1,flags),puntos(pl2,flags));}

//devuelve una lista de las MAX_LISTA superiores puntuaciones del tipo <flags>
//en flags se mete PUNTOS_loquesea, si no se mete nada por defecto
//lista los puntos gastados!
public varargs string Listar(mixed flags) {
  mixed ind;
  int num,i;
  string texto;

  if (stringp(flags)) flags=CASETA_A_POSICION[flags];

  texto  ="\n";
  texto +="."+STR->cadjust("-",                LENGTH,"-")+".\n";
  texto +="|"+STR->cadjust("Los más ludópatas",LENGTH," ")+"|\n";

  if (!puntos) CargarPuntos();
  if (!(num=sizeof(puntos))) {
    texto += "|"+STR->cadjust("",                 LENGTH," ")+"|\n";
    texto += "|"+STR->cadjust("",                 LENGTH," ")+"|\n";
    texto += "|"+STR->cadjust("No hay ludópatas", LENGTH," ")+"|\n";
    texto += "|"+STR->cadjust("",                 LENGTH," ")+"|\n";
    texto += "|"+STR->cadjust("",                 LENGTH," ")+"|\n";
    texto += "."+STR->cadjust("-",                LENGTH,"-")+".\n";
    texto += "\n";
    return texto;
  }
  num = (num>MAX_LISTA)?MAX_LISTA:num;
  ind = sort_array(m_indices(puntos), SF(chk),flags); // ordena ind al DERECHO
  SalvarPuntos();
//({})[<1]
  for(i=0;i<num;i++) {
    texto += "|"+STR->ladjust(" "+capitalize(ind[i])+" ",LENGTH_NOMBRE,".")
		+STR->radjust(" "+to_string(puntos(ind[i],flags))+" puntos",LENGTH-LENGTH_NOMBRE,".")+"|\n";
    texto += "."+STR->cadjust("-",LENGTH,"-")+".\n";
    texto += "\n";
  }
  return texto;
}
