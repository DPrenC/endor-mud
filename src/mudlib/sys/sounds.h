/**
 * simauria /sys/sounds.h
*/

#ifndef __SOUNDS__
#define __SOUNDS_

#define SOUND_START_STR       "!!SOUND"
#define MUSIC_START_STR       "!!MUSIC"
#define SOUND_OFF             "off"
#define MUSIC_OFF             "off"
#define SOUND_ENV_VOLUME      20
#define IS_MUSIC              1
#define IS_SOUND              2
#define IS_OFF                3
#define SOUND_SUPPORT         ({"mp3", "wav", "ogg"})

// Defines para las rutas
#define SOUND_URL             "https://www.dropbox.com/sh/ilbcng799x4yt2k/AAASWATUNyoxFVc-sygpo5Zra?dl=0"
#define SND_ZONAS(x)          "zonas/" + x
#define SND_Z_AKALLAB(x)      SND_ZONAS("akallab/" + x)
#define SND_Z_KENTON(x)       SND_ZONAS("kenton/" + x)
#define SND_Z_KHA_ANNU(x)     SND_ZONAS("kha-annu/" + x)
#define SND_Z_LAD_LAURELIN(x) "SND_ZONAS("lad-laurelin/" + x)
#define SND_Z_SIMAURIA(x)     SND_ZONAS("simauria/" + x)
#define SND_Z_LIMBO(x)        SND_ZONAS("limbo/" + x)
#define SND_Z_GOLDHAI(x)      SND_ZONAS("goldhai/" + x)

//otros
#define SND_SUCESOS(x)        ("global/sucesos/" + x)
#define SND_HABILIDADES(x)    ("global/habilidades/" + x)

#define SND_CANALES(x)        "global/canales/" + x
#define SND_MAGIA(x)          "global/magia/" + x
#define SND_AMBIENTES(x)      "global/ambientes/" + x
#define SND_PNJS(x)           "global/pnjs/" + x

//defines para endor-mud
#define SOUND_OBJETOS(x)        ("general/objetos/" + x)
#define SOUND_EVENTOS(x)        ("general/eventos/" + x)
#define SOUND_AMBIENTES(x)        ("general/ambientes/" + x)
#define SOUND_PUERTAS(x)        ("general/puertas/" + x)
#define SOUND_CANALES(x)        ("general/canales/" + x)
#define SOUND_AINU(x)        ("ainu/" + x)


#endif
