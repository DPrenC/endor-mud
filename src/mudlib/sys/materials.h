/*
    SIMAURIA ["/sys/materiales.h"]
    ========

      [g] Guybrush
      [n] Nemesis

    12/12/97 [g] Traslado del archivo [/sys/puerta.h] y modificacion
             (anyade textos de material)
    18/09/98 [g] Anyade plastico. Ya ya. El plastico no estaba en aquella
             epoca, bla bla. Quien no quiera que no lo use.
        18-Feb-98 [n] Añadidos los materiales: Tela, Hueso, Cuero y Platino.
    15/03/99 [g] Añade piel y quita plástico. Aluminio fue añadido por
             [n] entre el 18/Feb/98 y hoy :-}
    16/03/99 [g] Añade el M_MAPPING. Ahora cualquier material nuevo
             que se introduzca en la lista, ha de ser también
             introducido en el M_MAPPING para que sea reconocido.
             Ventajas: No hace falta tocar ni el exits.c ni el
             thing.c ni nada que dependa de los materiales.
    23/04/99 [g] Se añadió el material PLOMO, pero no se metió en el
             M_MAPPING, ni se indicó en la cabecera. Hecho.

    NOTA: Por favor, las posibles modificaciones, notificadmelas e
        indicadlas con fecha brevemente en esta cabecera, y mas extensamente
        en la cabecera de la funcion modificada. Material que anyadais aqui,
        material que teneis que anyadir en el thing.c, funcion SetMaterial().
*/

#ifndef _MATERIALS_
#define _MATERIALS_

/* --- MATERIALES --- */

// TIPOS (ordenados por valor)
#define M_NINGUNO   0
#define M_TELA      1
#define M_CUERO     2
#define M_PIEL      3
#define M_MADERA    4
#define M_HUESO     5
#define M_PIEDRA    6
#define M_ALUMINIO  7
#define M_PLOMO     8
#define M_HIERRO    9
#define M_ACERO     10
#define M_COBRE     11
#define M_BRONCE    12
#define M_PLATA     13
#define M_CRISTAL   14
#define M_ORO       15
#define M_PLATINO   16
#define M_DIAMANTE  17
#define M_TITANIO   18
#define M_ADAMANTIO 19
#define M_MITHRIL   20
#define M_ESPECIAL  21

// TEXTOS (ordenados por valor)
#define M_NINGUNO_TXT   ""
#define M_TELA_TXT      "tela"
#define M_CUERO_TXT     "cuero"
#define M_PIEL_TXT      "piel"
#define M_MADERA_TXT    "madera"
#define M_HUESO_TXT     "hueso"
#define M_CRISTAL_TXT   "cristal"
#define M_PIEDRA_TXT    "piedra"
#define M_ALUMINIO_TXT  "aluminio"
#define M_PLOMO_TXT     "plomo"
#define M_HIERRO_TXT    "hierro"
#define M_ACERO_TXT     "acero"
#define M_COBRE_TXT     "cobre"
#define M_BRONCE_TXT    "bronce"
#define M_PLATA_TXT     "plata"
#define M_ORO_TXT       "oro"
#define M_PLATINO_TXT   "platino"
#define M_DIAMANTE_TXT  "diamante"
#define M_TITANIO_TXT   "titanio"
#define M_ADAMANTIO_TXT "adamantio"
#define M_MITHRIL_TXT   "mithril"
#define M_DESCONOCIDO_TXT   "material desconocido"
#define M_ESPECIAL_TXT      "material especial"

#define M_MAPPING    ([\
 M_NINGUNO: M_NINGUNO_TXT, M_TELA: M_TELA_TXT, M_CUERO: M_CUERO_TXT,\
 M_PIEL: M_PIEL_TXT, M_MADERA: M_MADERA_TXT, M_HUESO: M_HUESO_TXT,\
 M_CRISTAL: M_CRISTAL_TXT, M_PIEDRA: M_PIEDRA_TXT, M_ALUMINIO: M_ALUMINIO_TXT,\
 M_HIERRO: M_HIERRO_TXT, M_ACERO: M_ACERO_TXT, M_COBRE: M_COBRE_TXT,\
 M_BRONCE: M_BRONCE_TXT, M_PLATA: M_PLATA_TXT, M_ORO: M_ORO_TXT,\
 M_PLATINO: M_PLATINO_TXT, M_DIAMANTE: M_DIAMANTE_TXT, M_TITANIO: M_TITANIO_TXT,\
 M_ADAMANTIO: M_ADAMANTIO_TXT, M_MITHRIL: M_MITHRIL_TXT, M_PLOMO: M_PLOMO_TXT,\
 M_ESPECIAL:M_ESPECIAL_TXT])

#define M_NINGUNO_DUR   0
#define M_TELA_DUR      -9
#define M_CUERO_DUR     1
#define M_PIEL_DUR      1
#define M_MADERA_DUR    -1
#define M_HUESO_DUR     0
#define M_PIEDRA_DUR    0
#define M_ALUMINIO_DUR  0
#define M_PLOMO_DUR     0
#define M_HIERRO_DUR    4
#define M_ACERO_DUR     6
#define M_COBRE_DUR     1
#define M_BRONCE_DUR    2
#define M_PLATA_DUR     0
#define M_CRISTAL_DUR   -9
#define M_ORO_DUR       0
#define M_PLATINO_DUR   0
#define M_DIAMANTE_DUR  -9
#define M_TITANIO_DUR   7
#define M_ADAMANTIO_DUR 8
#define M_MITHRIL_DUR   10
#define M_ESPECIAL_DUR  15

#define M_DUREZA     ([    \
 M_NINGUNO: M_NINGUNO_DUR, M_TELA: M_TELA_DUR, M_CUERO: M_CUERO_DUR,\
 M_PIEL: M_PIEL_DUR, M_MADERA: M_MADERA_DUR, M_HUESO: M_HUESO_DUR,\
 M_CRISTAL: M_CRISTAL_DUR, M_PIEDRA: M_PIEDRA_DUR, M_ALUMINIO: M_ALUMINIO_DUR,\
 M_HIERRO: M_HIERRO_DUR, M_ACERO: M_ACERO_DUR, M_COBRE: M_COBRE_DUR,\
 M_BRONCE: M_BRONCE_DUR, M_PLATA: M_PLATA_DUR, M_ORO: M_ORO_DUR,\
 M_PLATINO: M_PLATINO_DUR, M_DIAMANTE: M_DIAMANTE_DUR, M_TITANIO: M_TITANIO_DUR,\
 M_ADAMANTIO: M_ADAMANTIO_DUR, M_MITHRIL: M_MITHRIL_DUR, M_PLOMO: M_PLOMO_DUR,\
 M_ESPECIAL:M_ESPECIAL_DUR\
               ])

// añado aquí de momento los defines para los asientos de endor
#define P_FIRMEZA_MUY_FRAGIL  30000 //madera podrida, asiento inestable
#define P_FIRMEZA_FRAGIL  60000 //madera buena, asiento inestable
#define P_FIRMEZA_NORMAL  100000  //madera buena, asiento en buen estado
#define P_FIRMEZA_RESISTENTE  150000  //hierro
#define P_FIRMEZA_MUY_RESISTENTE  200000  //piedra
#define P_FIRMEZA_IRROMPIBLE  1000000
#endif
