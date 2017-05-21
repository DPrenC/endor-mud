/*   Impreso temporal del quest de los papeles
     Creado por : Cheto
     Fecha : 10-Oct-2001
*/

#include "path.h"
#include <properties.h>

#define DATOS (LOGS "impresot/")
//#define DATOS "/log/register/ppe/PAPELES"

#define NDATOS 3 //i=0, destino=1, lista=2

inherit THING;

//definicion de variables
static int i=0; //contador de paseo por los despachos
static int d1a=0; //para que cuando salgas tengas que ir al d1a.
int piso; //random
int numero; //random
static int *lista;
static string destino;
static int tablacargada=0;
static int tablacreada=0;
public mapping papeles;


//funcion de objeto
create() {
::create();
SetShort("Solicitud para el JK23-H");
SetLong("Solicitud para el impreso JK23-H, necesario para conseguirlo.\n");
AddId(({"impresot","JK232-H","impreso"}));
Set(P_NOGIVE, 1);
Set(P_NODROP, 1);
Set(P_NOSELL,1);
SetWeight(0);
SetValue(50);
Set(P_NOSELL,1);
//seteuid(getuid(TP));
}

//funciones varias para la gestion de la actividad del papelillo
void CrearTabla(){
if(papeles) return;
papeles = m_allocate(0,NDATOS);
tablacreada=1;
}


varargs void CargarTabla(){
/*  Carga la tabla*/
string jug;
jug = TP->QueryRealName();
if(papeles) return;
restore_object(DATOS + jug);
tablacargada=1;
}

varargs void SalvarTabla() {
string jug;
jug = TP->QueryRealName();
/* salva la tabla */
save_object(DATOS+jug);
}



void aumentar_contador()
{
string jug;
jug=TP->QueryRealName();
if (!tablacargada) CargarTabla();
i=papeles[jug,0];
i++;
papeles[jug,0]=i;
//dtell(jug,"incrementa i\n");
SalvarTabla();
}

int calcula_indice(int fila,int columna)
{// devuelve el indice que hay que pasarle al array
if (columna==0) return fila;
if (columna!=0) return (fila*26)+(columna);
}
int consultar_contador()
{
//cargar tabla!!
string jug;
jug=TP->QueryRealName();
if (!tablacargada) CargarTabla();
i=papeles[jug,0];
return i;
}
//para saber donde tiene que ir

string destino()
{
//cargar tabla
string jug;
if (d1a==0) {return "d1a";}
else{
jug=TP->QueryRealName();
if (!tablacargada) CargarTabla();
destino=papeles[jug,1];
return destino;
}
}
//calcula el string a devolver

string anyade_destino(int piso, int numero)
{
string dest;
string jug;
if (piso==0 &&numero==0){ return "d3z";}
else{
jug=TP->QueryRealName();
if (!tablacargada) CargarTabla();
numero++;
if (piso==0){
	if (numero==1) dest="d1a";
	if (numero==2) dest="d1b";
	if (numero==3) dest="d1c";
	if (numero==4) dest="d1d";
	if (numero==5) dest="d1e";
	if (numero==6) dest="d1f";
	if (numero==7) dest="d1g";
	if (numero==8) dest="d1h";
	if (numero==9) dest="d1i";
	if (numero==10) dest="d1j";
	if (numero==11) dest="d1k";
	if (numero==12) dest="d1l";
	if (numero==13) dest="d1m";
	if (numero==14) dest="d1n";
	if (numero==15) dest="d1o";
	if (numero==16) dest="d1p";
	if (numero==17) dest="d1q";
	if (numero==18) dest="d1r";
	if (numero==19) dest="d1s";
	if (numero==20) dest="d1t";
	if (numero==21) dest="d1u";
	if (numero==22) dest="d1v";
	if (numero==23) dest="d1w";
	if (numero==24) dest="d1x";
	if (numero==25) dest="d1y";
	if (numero==26) dest="d1z";
	}//piso=1
if (piso==1){
	if (numero==1) dest="d2a";
        if (numero==2) dest="d2b";
        if (numero==3) dest="d2c";
        if (numero==4) dest="d2d";
        if (numero==5) dest="d2e";
        if (numero==6) dest="d2f";
        if (numero==7) dest="d2g";
        if (numero==8) dest="d2h";
        if (numero==9) dest="d2i";
        if (numero==10) dest="d2j";
        if (numero==11) dest="d2k";
        if (numero==12) dest="d2l";
        if (numero==13) dest="d2m";
        if (numero==14) dest="d2n";
        if (numero==15) dest="d2o";
        if (numero==16) dest="d2p";
        if (numero==17) dest="d2q";
        if (numero==18) dest="d2r";
        if (numero==19) dest="d2s";
        if (numero==20) dest="d2t";
        if (numero==21) dest="d2u";
        if (numero==22) dest="d2v";
	if (numero==23) dest="d2w";
        if (numero==24) dest="d2x";
        if (numero==25) dest="d2y";
        if (numero==26) dest="d2z";
	}//piso=2
if (piso==2){
	if (numero==1) dest="d3a";
        if (numero==2) dest="d3b";
        if (numero==3) dest="d3c";
        if (numero==4) dest="d3d";
        if (numero==5) dest="d3e";
        if (numero==6) dest="d3f";
        if (numero==7) dest="d3g";
        if (numero==8) dest="d3h";
        if (numero==9) dest="d3i";
        if (numero==10) dest="d3j";
        if (numero==11) dest="d3k";
        if (numero==12) dest="d3l";
        if (numero==13) dest="d3m";
        if (numero==14) dest="d3n";
        if (numero==15) dest="d3o";
        if (numero==16) dest="d3p";
        if (numero==17) dest="d3q";
        if (numero==18) dest="d3r";
        if (numero==19) dest="d3s";
        if (numero==20) dest="d3t";
        if (numero==21) dest="d3u";
        if (numero==22) dest="d3v";
        if (numero==23) dest="d3w";
        if (numero==24) dest="d3x";
	if (numero==25) dest="d3y";
        if (numero==26) dest="d3z";
}//piso=3

papeles[jug,1]=dest;
//dtell(jug,"destino");
SalvarTabla();
return dest;
}
}
//funcion mega-tocha que hace todo
//genera un indice, si ese indice es valido, calcula el destino
//si no es valido genera otro hasta que el destino sea valida
void siguiente_destino()
{
int max;
int piso;
int numero;
int indice; //posicion del vector;
int condicion=0; //booleano para el while;
string jug;
if (d1a!=0){
jug=TP->QueryRealName();
if (!tablacargada) CargarTabla();
aumentar_contador();
//comprobacion del mapping
lista=papeles[jug,2];
while (condicion==0)
	{piso=random(3);
	numero=random(26);
	indice=calcula_indice(piso,numero);
	if (lista[indice]==0)
		{
		lista[indice]=1;
		condicion=1;
		destino=anyade_destino(piso,numero);
		}//if
	}//while
papeles[jug,2]=lista;
//dtell(jug,"lista");
SalvarTabla();
max=consultar_contador();
if (max>60) papeles = m_delete(papeles,jug);
}
else {
d1a=3;
}
}

//funcion de inicio del vector;
void inicializa()
{int i=0;
string jug;
lista=({});
jug=TP->QueryRealName();
if (!tablacreada) CrearTabla();
if (!tablacargada) CargarTabla();
lista=lista+({1});
for (i=1;i<=78;i++)
	{
	lista=lista+({0});}
papeles[jug,2]=lista;
//dtell(jug,"lista2");
SalvarTabla();
d1a=35;
}
