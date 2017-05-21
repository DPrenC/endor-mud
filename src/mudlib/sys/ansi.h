/**
 * SIMAURIA '/sys/ansi.h'
 */
/*
[Nyh] Me doy la panzada para descubrir que hacen todos y cada uno de los
      codigos ansi que hay... y este es el resultado.

[0m -> reset; clears all colors and styles (to white on black)
[1m -> bold on (see below)
1	Bright
2	Dim
[3m -> italics on
[4m -> underline on
4	Underscore
5	Blink
[7m -> inverse on; reverses foreground & background colors
8	Hidden
[9m -> strikethrough on
[22m -> bold off (see below)
[23m -> italics off
[24m -> underline off
[27m -> inverse off
[29m -> strikethrough off
[30m -> set foreground color to black
[31m -> set foreground color to red
[32m -> set foreground color to green
[33m -> set foreground color to yellow
[34m -> set foreground color to blue
[35m -> set foreground color to magenta (purple)
[36m -> set foreground color to cyan
[37m -> set foreground color to white
[39m -> set foreground color to default (white)
[40m -> set background color to black
[41m -> set background color to red
[42m -> set background color to green
[43m -> set background color to yellow
[44m -> set background color to blue
[45m -> set background color to magenta (purple)
[46m -> set background color to cyan
[47m -> set background color to white
[49m -> set background color to default (black)
*/

#ifndef _ANSI_
#define _ANSI_

// ANSI especiales

#define ANSI_RESET          "[0m"  // Resetea todo
#define ANSI_NORMAL         ANSI_RESET
#define ANSI_BRIGHT         "[1m"  // Claro  / Brillante (Negrita on)
#define ANSI_DIM            "[2m"  // Oscuro / Apagado   (Negrita off)
#define ANSI_ITALIC         "[3m"  // Cursiva
#define ANSI_UNDERLINE      "[4m"  // Subrayado
#define ANSI_BLINK          "[5m"  // Parpadea
//#define ANSI_ITALIC         "[6m"  // Cursiva // ¿Repetido?
#define ANSI_INVERSE        "[7m"  // Inversa (Invierte fondo<->letra)
#define ANSI_HIDDEN         "[8m"  // Ni idea macho
#define ANSI_STRIKETHROUGH  "[9m"  // Tachada

#define ANSI_BOLD       ANSI_BRIGHT
#define ANSI_INVERS     ANSI_INVERSE
#define ANSI_UNDERL     ANSI_UNDERLINE
#define ANSI_STRIKE     ANSI_STRIKETHROUGH

#define ANSI_BOLD_OFF           "[22m" // Apagar negrita
#define ANSI_ITALIC_OFF         "[23m" // Apagar cursiva
#define ANSI_UNDERLINE_OFF      "[24m" // Apagar subrayado
#define ANSI_BLINK_OFF          "[25m" // Apagar parpadeo
#define ANSI_INVERSE_OFF        "[27m" // Apagar inversa
#define ANSI_HIDDEN_OFF         "[28m" // Apagar hidden? Ni idea macho
#define ANSI_STRIKETHROUGH_OFF  "[29m" // Apagar tachada

#define ANSI_INVERS_OFF     ANSI_INVERSE_OFF
#define ANSI_UNDERL_OFF     ANSI_UNDERLINE_OFF
#define ANSI_STRIKE_OFF     ANSI_STRIKETHROUGH_OFF

//COLORES
#define ANSI_BLACK      "[30m"
#define ANSI_RED        "[31m"
#define ANSI_GREEN      "[32m"
#define ANSI_YELLOW     "[33m"
#define ANSI_BLUE       "[34m"
#define ANSI_PURPLE     "[35m"
#define ANSI_CYAN       "[36m"
#define ANSI_WHITE      "[37m"
#define ANSI_DEFAULT    "[39m" // foreground color to default
#define ANSI_CNORMAL    ANSI_DEFAULT

//FONDOS
#define ANSI_BG_BLACK   "[40m"
#define ANSI_BG_RED     "[41m"
#define ANSI_BG_GREEN   "[42m"
#define ANSI_BG_YELLOW  "[43m"
#define ANSI_BG_BLUE    "[44m"
#define ANSI_BG_PURPLE  "[45m"
#define ANSI_BG_CYAN    "[46m"
#define ANSI_BG_WHITE   "[47m"
#define ANSI_BG_DEFAULT "[49m" // background color to default
#define ANSI_BG_CNORMAL ANSI_BG_DEFAULT

// NOMBRES
#define ANSI_NONE       ""

#define STR_ANSI_NONE	    "ninguno"
#define STR_ANSI_BOLD 	    "resaltado"
#define STR_ANSI_UNDERL     "subrayado"
#define STR_ANSI_BLINK 	    "parpadeante"
#define STR_ANSI_INVERS     "inverso"
#define STR_ANSI_STRIKE     "tachado"
#define STR_ANSI_NORMAL     "normal"

#define STR_ANSI_BLACK 	    "negro"
#define STR_ANSI_RED 	    "rojo"
#define STR_ANSI_GREEN	    "verde"
#define STR_ANSI_YELLOW	    "amarillo"
#define STR_ANSI_BLUE	    "azul"
#define STR_ANSI_PURPLE	    "púrpura"
#define STR_ANSI_PURPLE2    "purpura"
#define STR_ANSI_CYAN	    "cian"
#define STR_ANSI_WHITE	    "blanco"

#define ANSI_COLOR ([ \
	                STR_ANSI_NONE:    ANSI_NONE, \
	                STR_ANSI_BLACK:   ANSI_BLACK, \
	                STR_ANSI_RED:     ANSI_RED, \
	                STR_ANSI_GREEN:   ANSI_GREEN, \
	                STR_ANSI_YELLOW:  ANSI_YELLOW, \
	                STR_ANSI_BLUE:    ANSI_BLUE, \
	                STR_ANSI_PURPLE:  ANSI_PURPLE, \
	                STR_ANSI_PURPLE2: ANSI_PURPLE, \
	                STR_ANSI_CYAN:    ANSI_CYAN, \
	                STR_ANSI_WHITE:   ANSI_WHITE \
	               ])
#define ANSI_TYPE ([ \
	                STR_ANSI_NONE:   ANSI_NONE, \
	                STR_ANSI_BOLD:   ANSI_BOLD, \
	                STR_ANSI_UNDERL: ANSI_UNDERL, \
	                STR_ANSI_BLINK:  ANSI_BLINK, \
	                STR_ANSI_INVERS: ANSI_INVERS, \
	                STR_ANSI_STRIKE: ANSI_STRIKE  \
	              ])

#define ANSI_REP    ( ANSI_COLOR + ANSI_TYPE )

//#define COLORANSI ANSI_COLOR
#define ANSI_STR ([ \
    ANSI_NONE:      STR_ANSI_NONE,   \
    ANSI_BLACK:     STR_ANSI_BLACK,  \
    ANSI_RED:       STR_ANSI_RED,    \
    ANSI_GREEN:     STR_ANSI_GREEN,  \
    ANSI_YELLOW:    STR_ANSI_YELLOW, \
    ANSI_BLUE:      STR_ANSI_BLUE,   \
    ANSI_PURPLE:    STR_ANSI_PURPLE, \
    ANSI_CYAN:      STR_ANSI_CYAN,   \
    ANSI_WHITE:     STR_ANSI_WHITE,  \
    ])

#endif
