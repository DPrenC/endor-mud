/*
DESCRIPCION  : Calendario v.1.0
FICHERO      : /obj/calendario/calendario.c
MODIFICACION : 18-02-98 [Angor@Simauria] Creacion de la version 1.0
-------------------------------------------------------------------------------
Por favor, las posibles modificaciones, notificadmelas e indicadlas con fecha
brevemente en esta cabecera, y mas extensamente en la cabecera de la funcion
modificada. [Angor]

-------------------------------------------------------------------------------
NOTAS:
- El calendario supone definidas todas las constantes de este fichero para
  poder trabajar.
- Todos los meses duran lo mismo, y este valor se autocalcula en funcion del
- La duracion del mes en dias-Simauria se autocalcula en funcion del numero de
  meses que tenga el calendario.

-------------------------------------------------------------------------------
 10-12-98 [woo] He modificado un idx que daba error, resulta que buscaba un
          indice del mes 12,cuando solo habian 0..11, asi que he anyadido
          un -1.. espero no pete ahora.
 08-11-99 [Angor] Anyadida la funcion leer para que un PJ pueda saber la fecha

*/

inherit "/std/thing";
#include <properties.h>
#include <calendario.h>

//Declaracion de las funciones publicas
public void    SetTipoCalendario(string str);
public string  QueryTipoCalendario();
public void    SetNumMesesPorAnyo(int num);
public int     QueryMesesPorAnyo();
public void    SetNomMeses(mapping nom);
public mapping QueryNomMeses();
public void    SetNumDiasPorSemana(int i);
public int     QueryNumDiasPorSemana();
public void    SetNomDias(mapping nom);
public mapping QueryNomDias();
public void    SetAnyoBase(int anyo);
public int     QueryAnyoBase();
public string  QueryMesNombre();
public int     QueryMesNum();
public string  QueryDiaNombre();
public int     QueryDiaNum();
public string  QueryAnyo();

//declaracion de las funciones privadas
private        void updateDesc();
public int     numMeses();
private int    NumMesReal(string str);
private string DiaReal();
private string MesReal();
private string HoraReal();
private string MinutoReal();
private string SegundoReal();
private string AnyoReal();
public int     diasEntreMeses(int mesFin, int mesIni);
public int     diasTotales();

// Variables globales
private string tipoCalendario;
private int    numMesesAnyo;
private static mapping nomMeses;
private int    numDiasSemana;
private static mapping nomDias;
private int    anyoBase;
private static mapping idxMeses;
private string* idxMeses2;
private mapping durMeses;


//Definicion de las funciones
public void    SetTipoCalendario(string str){if (str) {tipoCalendario=str; updateDesc();}}
public string  QueryTipoCalendario(){return tipoCalendario;}
public void    SetNumMesesPorAnyo(int num){numMesesAnyo=num;}
public int     QueryMesesPorAnyo(){return numMesesAnyo;}
public void    SetNomMeses(mapping nom){nomMeses=nom;}
public mapping QueryNomMeses(){return nomMeses;}
public void    SetNumDiasPorSemana(int i){numDiasSemana=i;}
public int     QueryNumDiasPorSemana(){return numDiasSemana;}
public void    SetNomDias(mapping nom){nomDias=nom;}
public mapping QueryNomDias(){return nomDias;}
public void    SetAnyoBase(int anyo){anyoBase=anyo;}
public int     QueryAnyoBase(){return anyoBase;}
public string  QueryMesNombre(){return nomMeses[QueryMesNum()];}
public int     QueryMesNum(){return (numMeses()-((numMeses()-1)/numMesesAnyo)*numMesesAnyo);}
private int    NumMesReal(string mes){return idxMeses[mes];}


public string QueryFecha(){
return "Es el "+QueryDiaNombre()+" "+(string)(QueryDiaNum())+" de "
       +capitalize(QueryMesNombre())+" del anyo "+QueryAnyo()
       +" del calendario "+capitalize(tipoCalendario);
}


// Que anyo es en este calendario
public string QueryAnyo(){
  int anyo;
  anyo=anyoBase+(numMeses()/numMesesAnyo);
  return (string)anyo;
}


// Duracion del mes en dias-simauria del calendario
public int QueryDiasPorMes(){
return ((C_DIAS_SIM_POR_DIA_REAL*365)/(C_NUM_ESTACIONES*C_DURACION_ESTACION*numMesesAnyo));
}


// Que dia del mes es en este calendario
public string QueryDiaNombre(){
  int num,dia;
  string nombre;
  num=QueryDiaNum();
  dia=num-numDiasSemana*(num/numDiasSemana);
  //write(""+num+","+numDiasSemana+","+dia+"\n");
  nombre=nomDias[dia];
  return nombre;
}


// Que dia del mes es en este calendario
public int QueryDiaNum(){
  int num,anyosSim,resto,mesesSim,diasSim,offset;
  num=diasTotales();
  anyosSim=num*C_NUM_ESTACIONES*C_DURACION_ESTACION/365;
  resto=num-(365*anyosSim)/(C_NUM_ESTACIONES*C_DURACION_ESTACION);
  mesesSim=resto*C_DIAS_SIM_POR_DIA_REAL/QueryDiasPorMes();
  diasSim=resto*C_DIAS_SIM_POR_DIA_REAL-mesesSim*QueryDiasPorMes();
  offset=(int)HoraReal()*C_DIAS_SIM_POR_DIA_REAL/24;
  diasSim+=offset;
  if (resto==0) diasSim=QueryDiasPorMes(); //fin de anyo-Sim
  return diasSim;
}


// Numero total de meses-calendario desde el comienzo del MUD
public int numMeses(){
  int num,anyosSim,mesesSim,resto;
  num=diasTotales();
  anyosSim=num*C_NUM_ESTACIONES*C_DURACION_ESTACION/365;
  resto=num-(365*anyosSim)/(C_NUM_ESTACIONES*C_DURACION_ESTACION);
  mesesSim=anyosSim*numMesesAnyo+resto*numMesesAnyo/(365/C_NUM_ESTACIONES*C_DURACION_ESTACION);
  return mesesSim;
}


// Numero de dias reales totales desde el comienzo del MUD
public int diasTotales(){
  int dia1,dia2,mes1,mes2,anyo1,anyo2,numDias;
  dia1=(int)C_DIA_INICIO_MUD;
  dia2=(int)DiaReal();
  mes1=NumMesReal(C_MES_INICIO_MUD);
  mes2=NumMesReal(MesReal());
  anyo1=(int)C_ANYO_INICIO_MUD;
  anyo2=(int)AnyoReal();
// write("dia1["+dia1+"]dia2["+dia2+"]mes1["+mes1+"]mes2["+mes2+"]anyo1["+anyo1+"]anyo2["+anyo2+"]\n");
if (mes2>=mes1) {
  numDias=(anyo2-anyo1)*365;
  numDias=numDias+diasEntreMeses(mes2,mes1);
// [w] He puesto un idxMeses2[mes2'-1']
  numDias=numDias-dia1-(durMeses[idxMeses2[mes2-1]]-dia2);
  }
else{
  numDias=(anyo2-anyo1)*365;
  numDias=numDias-diasEntreMeses(mes1,mes2);
// [w] He puesto un idxMeses2[mes2'-1']
  numDias=numDias+dia2+(durMeses[idxMeses2[mes1-1]]-dia1);
  }
return numDias;
}


// Dias entre dos meses reales dados
public int diasEntreMeses(int mesFin, int mesIni){
  int numDias,i;
  if (mesFin==mesIni) return 0;
  numDias=0;
  for (i=mesIni;i<=mesFin;i++){numDias+=durMeses[idxMeses2[i-1]];}
  return numDias;
}


// Funciones para la obtencion de parte de la fecha real
// Nota: ctime() obtiene fecha formato con "Fri Jul 17 19:13:33 1992"
private string NomDiaReal(){return (ctime()[0..2]);}
private string MesReal(){return (ctime()[4..6]);}
private string DiaReal(){return (ctime()[8..9]);}
private string HoraReal(){return (ctime()[11..12]);}
private string MinutoReal(){return (ctime()[14..15]);}
private string SegundoReal(){return (ctime()[17..18]);}
private string AnyoReal(){return (ctime()[20..23]);}


// Actualiza la descripcion del calendario
private void updateDesc(){
  SetShort("Un calendario del tipo "+capitalize(tipoCalendario));
  SetLong(capitalize(QueryShort())+".\n");
}

int leer_cmd(string que){
   if (member(TO->QueryIds(),que)!=-1)
      {
	  write(W(QueryFecha()+".\n"));
	  return 1;
	  }

   /*string str;
   str="Segun el calendario de tipo "+capitalize(QueryTipoCalendario())+
       " hoy es "+capitalize(QueryDiaNombre())+" "+QueryDiaNum()+
	   " del mes de "+capitalize(QueryMesNombre())+".\n";
   write(W(str));*/

return 0;
}

init(){
  ::init();
  add_action("leer_cmd","leer");
  return;
}

// Funcion principal
create(){
  ::create();
  SetShort("un calendario");
  SetTipoCalendario();
  AddId("calendario");
  AddId("almanaque");
  SetLong(capitalize(QueryShort())+".\n");
  SetWeight(200);

  idxMeses=C_IDX_MESES;
  idxMeses2=C_IDX_MESES_2;
  durMeses=C_DURACION_MESES;

  SetValue(150);
}
