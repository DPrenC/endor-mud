/*
DESCRIPCION  : camino
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/camino1.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
                        [Nem] Revisado y Corregido
			[Mal] elimino retornos de carro, pongo el wrap a 76
	       15-01-02 [z]   Zomax a�ade una salida para que los players puedan
			      morir y de paso visitar Rhoemas.
			      29-09-07 Ratwor: Arreglo el archivo y lo uno con el nuevo camino de Berat.
--------------------------------------------------------------------------------
*/
#include "./path.h"
inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("un cruce de caminos");
    SetIntLong("Est�s en el camino que une el pueblo de Berat al sur, con la capital "
    "Ishtria, al norte. Es un camino ancho y parece muy transitado, est� rodeado de "
    "�rboles. Junto al cruce ves un poste clavado en el suelo.\n");
    SetIndoors(0);
    SetIntNoise("Escuchas el canto de los p�jaros.\n");
    SetIntSmell("Huele a hierba fresca.\n");
    AddDetail(({"pajaro","pajaros","p�jaro","p�jaros"}),"No consigues verlos entre "
    "la espesura de los �rboles.\n");
    AddDetail(({"camino", "suelo"}), "Es un camino de tierra con marcas de ruedas de"
    " carromato, y pisadas de caballos.\n");
    AddDetail(({"arboles","arbol","�rboles","�rbol"}), "Los �rboles adornan los "
    "laterales del camino.\n");
    AddReadMsg(({"letrero", "cartel", "indicaciones", "indicacion", "indicaci�n"}),
    " *Sur - Berat.\n *Norte - Ishtria | Betwa | Marhalt.\n *Este - Rhoemas.\n");
    AddDetail("poste", "Es un robusto poste clavado en el suelo, le cuelga un letrero "
    "con indicaciones.\n");
    AddDetail(({"letrero", "cartel", "indicaciones", "indicacion", "indicaci�n"}),
    "Ves un letrero con unas indicaciones escritas.\n");
    AddExit("norte", CAMINOS "/simauria-berat/cam30");
    AddExit("sur", "./puente1");
    AddExit("este", CAMINOS "/berat-rhoemas/camino_00");
}

