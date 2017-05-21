/**
 * /sys/herbs.h
 */

#ifndef _HERBS_H_
#define _HERBS_H_

#define HERB_ID         "_herb_id"

#define HERB_CLASS_NORMAL     "normal"
#define HERB_CLASS_HEALING    "curativo"    // healing
#define HERB_CLASS_MAGIC      "magico"      // magic
#define HERB_CLASS_POISONOUS  "venenoso"    // poisonous
#define HERB_CLASS_NARCOTIC   "narcotico"   // narcotic
#define HERB_CLASS_FOOD       "saciante"    // quench sed // hambre: satisfy
#define HERB_CLASS_TOXIC      "intoxicante" // toxic
#define HERB_CLASS_UNKNOWN    "desconocido"

#define HERB_ALL ({ HERB_CLASS_NORMAL   , \
                    HERB_CLASS_HEALING  , \
                    HERB_CLASS_MAGIC    , \
                    HERB_CLASS_POISONOUS, \
                    HERB_CLASS_NARCOTIC , \
                    HERB_CLASS_FOOD     , \
                    HERB_CLASS_TOXIC    , \
                    HERB_CLASS_UNKNOWN  , \
                  })

#define HERB_TYPE_HERB      "hierba"
#define HERB_TYPE_ROOT      "raiz"
#define HERB_TYPE_FUNGUS    "hongo"
#define HERB_TYPE_MUSHROOM  "seta"

#define HERB_TYPE_ALL ({ HERB_TYPE_HERB    , \
                         HERB_TYPE_ROOT    , \
                         HERB_TYPE_FUNGUS  , \
                         HERB_TYPE_MUSHROOM, \
                      })

#endif
