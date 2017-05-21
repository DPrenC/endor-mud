/***
Fichero: valinor.h

***/

#ifndef VALINOR

#define VALINOR

#define STD_VALINOR(x)        (DOM_STD "valinor/"+ x)


#define HAB_VALMAR(x) (HABITACION "valinor/valmar/"+x)

#define HAB_BOSQUE_CENTRAL(x)     HAB_VALMAR("bosque_central/" + x)
#define HAB_BOSQUE_HADAS(x)       HAB_VALMAR("bosque_hadas/" + x)
#define HAB_BOSQUE_DRIADAS(x)     HAB_VALMAR("bosque_driadas/" + x)
#define HAB_BOSQUE_SENDERO(x)     HAB_VALMAR("senderos/" + x)
#define HAB_BOSQUE_ISLA(x)        HAB_VALMAR("isla/" + x)

#define BASE_CENTRAL              HAB_BOSQUE_CENTRAL("bosque_central_base.c")
#define BASE_HADAS                HAB_BOSQUE_HADAS("bosq_hadas_base.c")
#define BASE_DRIADAS              HAB_BOSQUE_DRIADAS("bosq_driadas_base.c")
#define BASE_ISLA                 HAB_BOSQUE_ISLA("isla_base.c")
#define BASE_SENDERO_OESTE        HAB_BOSQUE_SENDERO("sendero_oeste_base.c")
#define BASE_SENDERO_ESTE         HAB_BOSQUE_SENDERO("sendero_este_base.c")



#define PNJ_VALMAR(x) PNJ("valinor/valmar/"+x)
#define OBJ_OTRO_VALINOR(x)   OBJETO "otro/valinor/" + x
#define OBJ_ARMA_VALINOR(x)   OBJETO "arma/valinor/" + x
#define OBJ_MAGICO_VALINOR(x) OBJETO "magico/valinor/" + x
#define OBJ_PROT(x) OBJETO "proteccion/" + x
//para todos los comestibles de valinor
#define OBJ_COMIDA_VALINOR(x)      COMIDA("valinor/" + x)

//alias de los quest
#define QUEST_RUNAS(x)     "/d/aman/comun/quest/runas/"


// razas enemigas
#define RAZASENEMIGAS        ({"elfo-oscuro", "demonio", "orco", "troll","gigante"})
// AO para el sexo de los players
#define AO              (TP->QueryGender() == 2 ? "a" : "o")
#endif
