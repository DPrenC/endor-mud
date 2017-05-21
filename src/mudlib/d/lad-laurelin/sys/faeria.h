/***
Fichero: faeria.h
Autor: kastwey@simauria
Descripción:
Fichero con defines para faeria
Creación: 17/12/2004
22/12/2004 Añadida la raza  gigante como enemiga, que no estaba.
***/

#ifndef FAERIA

#define FAERIA

#define STD_FAERIA(x)        (DOM_STD "faeria/"+ x)
#define HAB_PUESTO(x)        (HABITACION "faeria/siempreunidos/"+x)
#define HAB_BOSQUE_PUESTO(x) (HABITACION "faeria/bosque_poblado/"+x)
#define HAB_BOSQUE_FAERIA(x) (HABITACION "faeria/bosque_faeria/"+x)
#define PNJ_PUESTO(x)        PNJ("faeria/siempreunidos/"+x)
#define PNJ_BOSQUE_PUESTO(x) PNJ("faeria/bosque_poblado/"+x)
#define PNJ_BOSQUE_FAERIA(x) PNJ("faeria/bosque_faeria/"+x)
#define OBJ_OTRO_FAERIA(x)   OBJETO "otro/faeria/" + x
#define OBJ_ARMA_FAERIA(x)   OBJETO "arma/faeria/" + x
#define OBJ_MAGICO_FAERIA(x) OBJETO "magico/faeria/" + x

// tablón de enemigos
#define TABLON_ENEMIGOS      (STD_FAERIA("enemigos_faeria"))
// razas enemigas de los elfos de faeria
#define RAZASENEMIGAS        ({"elfo-oscuro", "demonio", "orco", "troll","gigante"})
// AO para el sexo de los players
#define AO              (TP->QueryGender() == 2 ? "a" : "o")
#endif
