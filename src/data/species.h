#include "constants/species.h"
#include "constants/species_rs.h"
#include "types.h"

const struct PokemonSpecies gSpeciesInfo[NUM_SPECIES] = {
    [SPECIES_TREECKO] = {
        .speciesIdRS = 277,
        .nameJapanese = __("キモリ　　"),
        .name = "TREECKO   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GROVYLE
    },
    [SPECIES_GROVYLE] = {
        .speciesIdRS = 278,
        .nameJapanese = __("ジュプトル"),
        .name = "GROVYLE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SCEPTILE
    },
    [SPECIES_SCEPTILE] = {
        .speciesIdRS = 279,
        .nameJapanese = __("ジュカイン"),
        .name = "SCEPTILE  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TORCHIC] = {
        .speciesIdRS = 280,
        .nameJapanese = __("アチャモ　"),
        .name = "TORCHIC   ",
        .catchIndex = 1,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_COMBUSKEN
    },
    [SPECIES_COMBUSKEN] = {
        .speciesIdRS = 281,
        .nameJapanese = __("ワカシャモ"),
        .name = "COMBUSKEN ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BLAZIKEN
    },
    [SPECIES_BLAZIKEN] = {
        .speciesIdRS = 282,
        .nameJapanese = __("バシャーモ"),
        .name = "BLAZIKEN  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MUDKIP] = {
        .speciesIdRS = 283,
        .nameJapanese = __("ミズゴロウ"),
        .name = "MUDKIP    ",
        .catchIndex = 2,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MARSHTOMP
    },
    [SPECIES_MARSHTOMP] = {
        .speciesIdRS = 284,
        .nameJapanese = __("ヌマクロー"),
        .name = "MARSHTOMP ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SWAMPERT
    },
    [SPECIES_SWAMPERT] = {
        .speciesIdRS = 285,
        .nameJapanese = __("ラグラージ"),
        .name = "SWAMPERT  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_POOCHYENA] = {
        .speciesIdRS = 286,
        .nameJapanese = __("ポチエナ　"),
        .name = "POOCHYENA ",
        .catchIndex = 3,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MIGHTYENA
    },
    [SPECIES_MIGHTYENA] = {
        .speciesIdRS = 287,
        .nameJapanese = __("グラエナ　"),
        .name = "MIGHTYENA ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ZIGZAGOON] = {
        .speciesIdRS = 288,
        .nameJapanese = __("ジグザグマ"),
        .name = "ZIGZAGOON ",
        .catchIndex = 4,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LINOONE
    },
    [SPECIES_LINOONE] = {
        .speciesIdRS = 289,
        .nameJapanese = __("マッスグマ"),
        .name = "LINOONE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WURMPLE] = {
        .speciesIdRS = 290,
        .nameJapanese = __("ケムッソ　"),
        .name = "WURMPLE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 11,
        .evolutionTarget = SPECIES_SILCOON
    },
    [SPECIES_SILCOON] = {
        .speciesIdRS = 291,
        .nameJapanese = __("カラサリス"),
        .name = "SILCOON   ",
        .catchIndex = 5,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BEAUTIFLY
    },
    [SPECIES_BEAUTIFLY] = {
        .speciesIdRS = 292,
        .nameJapanese = __("アゲハント"),
        .name = "BEAUTIFLY ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CASCOON] = {
        .speciesIdRS = 293,
        .nameJapanese = __("マユルド　"),
        .name = "CASCOON   ",
        .catchIndex = 6,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DUSTOX
    },
    [SPECIES_DUSTOX] = {
        .speciesIdRS = 294,
        .nameJapanese = __("ドクケイル"),
        .name = "DUSTOX    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LOTAD] = {
        .speciesIdRS = 295,
        .nameJapanese = __("ハスボー　"),
        .name = "LOTAD     ",
        .catchIndex = 0,
        .eggIndex = 1,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LOMBRE
    },
    [SPECIES_LOMBRE] = {
        .speciesIdRS = 296,
        .nameJapanese = __("ハスブレロ"),
        .name = "LOMBRE    ",
        .catchIndex = 7,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 6,
        .evolutionTarget = SPECIES_LUDICOLO
    },
    [SPECIES_LUDICOLO] = {
        .speciesIdRS = 297,
        .nameJapanese = __("ルンパッパ"),
        .name = "LUDICOLO  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SEEDOT] = {
        .speciesIdRS = 298,
        .nameJapanese = __("タネボー　"),
        .name = "SEEDOT    ",
        .catchIndex = 0,
        .eggIndex = 2,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_NUZLEAF
    },
    [SPECIES_NUZLEAF] = {
        .speciesIdRS = 299,
        .nameJapanese = __("コノハナ　"),
        .name = "NUZLEAF   ",
        .catchIndex = 8,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 2,
        .evolutionTarget = SPECIES_SHIFTRY
    },
    [SPECIES_SHIFTRY] = {
        .speciesIdRS = 300,
        .nameJapanese = __("ダーテング"),
        .name = "SHIFTRY   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TAILLOW] = {
        .speciesIdRS = 304,
        .nameJapanese = __("スバメ　　"),
        .name = "TAILLOW   ",
        .catchIndex = 9,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SWELLOW
    },
    [SPECIES_SWELLOW] = {
        .speciesIdRS = 305,
        .nameJapanese = __("オオスバメ"),
        .name = "SWELLOW   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WINGULL] = {
        .speciesIdRS = 309,
        .nameJapanese = __("キャモメ　"),
        .name = "WINGULL   ",
        .catchIndex = 10,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_PELIPPER
    },
    [SPECIES_PELIPPER] = {
        .speciesIdRS = 310,
        .nameJapanese = __("ペリッパー"),
        .name = "PELIPPER  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RALTS] = {
        .speciesIdRS = 392,
        .nameJapanese = __("ラルトス　"),
        .name = "RALTS     ",
        .catchIndex = 0,
        .eggIndex = 3,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_KIRLIA
    },
    [SPECIES_KIRLIA] = {
        .speciesIdRS = 393,
        .nameJapanese = __("キルリア　"),
        .name = "KIRLIA    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GARDEVOIR
    },
    [SPECIES_GARDEVOIR] = {
        .speciesIdRS = 394,
        .nameJapanese = __("サーナイト"),
        .name = "GARDEVOIR ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SURSKIT] = {
        .speciesIdRS = 311,
        .nameJapanese = __("アメタマ　"),
        .name = "SURSKIT   ",
        .catchIndex = 0,
        .eggIndex = 4,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MASQUERAIN
    },
    [SPECIES_MASQUERAIN] = {
        .speciesIdRS = 312,
        .nameJapanese = __("アメモース"),
        .name = "MASQUERAIN",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHROOMISH] = {
        .speciesIdRS = 306,
        .nameJapanese = __("キノココ　"),
        .name = "SHROOMISH ",
        .catchIndex = 0,
        .eggIndex = 5,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BRELOOM
    },
    [SPECIES_BRELOOM] = {
        .speciesIdRS = 307,
        .nameJapanese = __("キノガッサ"),
        .name = "BRELOOM   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SLAKOTH] = {
        .speciesIdRS = 364,
        .nameJapanese = __("ナマケロ　"),
        .name = "SLAKOTH   ",
        .catchIndex = 11,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_VIGOROTH
    },
    [SPECIES_VIGOROTH] = {
        .speciesIdRS = 365,
        .nameJapanese = __("ヤルキモノ"),
        .name = "VIGOROTH  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SLAKING
    },
    [SPECIES_SLAKING] = {
        .speciesIdRS = 366,
        .nameJapanese = __("ケッキング"),
        .name = "SLAKING   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ABRA] = {
        .speciesIdRS = 63,
        .nameJapanese = __("ケーシィ　"),
        .name = "ABRA      ",
        .catchIndex = 12,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_KADABRA
    },
    [SPECIES_KADABRA] = {
        .speciesIdRS = 64,
        .nameJapanese = __("ユンゲラー"),
        .name = "KADABRA   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_ALAKAZAM
    },
    [SPECIES_ALAKAZAM] = {
        .speciesIdRS = 65,
        .nameJapanese = __("フーディン"),
        .name = "ALAKAZAM  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NINCADA] = {
        .speciesIdRS = 301,
        .nameJapanese = __("ツチニン　"),
        .name = "NINCADA   ",
        .catchIndex = 13,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_NINJASK
    },
    [SPECIES_NINJASK] = {
        .speciesIdRS = 302,
        .nameJapanese = __("テッカニン"),
        .name = "NINJASK   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHEDINJA] = {
        .speciesIdRS = 303,
        .nameJapanese = __("ヌケニン　"),
        .name = "SHEDINJA  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WHISMUR] = {
        .speciesIdRS = 370,
        .nameJapanese = __("ゴニョニョ"),
        .name = "WHISMUR   ",
        .catchIndex = 0,
        .eggIndex = 6,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LOUDRED
    },
    [SPECIES_LOUDRED] = {
        .speciesIdRS = 371,
        .nameJapanese = __("ドゴーム　"),
        .name = "LOUDRED   ",
        .catchIndex = 14,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_EXPLOUD
    },
    [SPECIES_EXPLOUD] = {
        .speciesIdRS = 372,
        .nameJapanese = __("バクオング"),
        .name = "EXPLOUD   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAKUHITA] = {
        .speciesIdRS = 335,
        .nameJapanese = __("マクノシタ"),
        .name = "MAKUHITA  ",
        .catchIndex = 15,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_HARIYAMA
    },
    [SPECIES_HARIYAMA] = {
        .speciesIdRS = 336,
        .nameJapanese = __("ハリテヤマ"),
        .name = "HARIYAMA  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GOLDEEN] = {
        .speciesIdRS = 118,
        .nameJapanese = __("トサキント"),
        .name = "GOLDEEN   ",
        .catchIndex = 16,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SEAKING
    },
    [SPECIES_SEAKING] = {
        .speciesIdRS = 119,
        .nameJapanese = __("アズマオウ"),
        .name = "SEAKING   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAGIKARP] = {
        .speciesIdRS = 129,
        .nameJapanese = __("コイキング"),
        .name = "MAGIKARP  ",
        .catchIndex = 17,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GYARADOS
    },
    [SPECIES_GYARADOS] = {
        .speciesIdRS = 130,
        .nameJapanese = __("ギャラドス"),
        .name = "GYARADOS  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_AZURILL] = {
        .speciesIdRS = 350,
        .nameJapanese = __("ルリリ　　"),
        .name = "AZURILL   ",
        .catchIndex = 0,
        .eggIndex = 7,
        .specialEggFlag = 1,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_MARILL
    },
    [SPECIES_MARILL] = {
        .speciesIdRS = 183,
        .nameJapanese = __("マリル　　"),
        .name = "MARILL    ",
        .catchIndex = 18,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_AZUMARILL
    },
    [SPECIES_AZUMARILL] = {
        .speciesIdRS = 184,
        .nameJapanese = __("マリルリ　"),
        .name = "AZUMARILL ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GEODUDE] = {
        .speciesIdRS = 74,
        .nameJapanese = __("イシツブテ"),
        .name = "GEODUDE   ",
        .catchIndex = 19,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GRAVELER
    },
    [SPECIES_GRAVELER] = {
        .speciesIdRS = 75,
        .nameJapanese = __("ゴローン　"),
        .name = "GRAVELER  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_GOLEM
    },
    [SPECIES_GOLEM] = {
        .speciesIdRS = 76,
        .nameJapanese = __("ゴローニャ"),
        .name = "GOLEM     ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NOSEPASS] = {
        .speciesIdRS = 320,
        .nameJapanese = __("ノズパス　"),
        .name = "NOSEPASS  ",
        .catchIndex = 20,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_PROBOPASS
    },
    [SPECIES_SKITTY] = {
        .speciesIdRS = 315,
        .nameJapanese = __("エネコ　　"),
        .name = "SKITTY    ",
        .catchIndex = 0,
        .eggIndex = 8,
        .specialEggFlag = 1,
        .evolutionMethod = 5,
        .evolutionTarget = SPECIES_DELCATTY
    },
    [SPECIES_DELCATTY] = {
        .speciesIdRS = 316,
        .nameJapanese = __("エネコロロ"),
        .name = "DELCATTY  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ZUBAT] = {
        .speciesIdRS = 41,
        .nameJapanese = __("ズバット　"),
        .name = "ZUBAT     ",
        .catchIndex = 190,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GOLBAT
    },
    [SPECIES_GOLBAT] = {
        .speciesIdRS = 42,
        .nameJapanese = __("ゴルバット"),
        .name = "GOLBAT    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_CROBAT
    },
    [SPECIES_CROBAT] = {
        .speciesIdRS = 169,
        .nameJapanese = __("クロバット"),
        .name = "CROBAT    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TENTACOOL] = {
        .speciesIdRS = 72,
        .nameJapanese = __("メノクラゲ"),
        .name = "TENTACOOL ",
        .catchIndex = 21,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_TENTACRUEL
    },
    [SPECIES_TENTACRUEL] = {
        .speciesIdRS = 73,
        .nameJapanese = __("ドククラゲ"),
        .name = "TENTACRUEL",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SABLEYE] = {
        .speciesIdRS = 322,
        .nameJapanese = __("ヤミラミ　"),
        .name = "SABLEYE   ",
        .catchIndex = 22,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAWILE] = {
        .speciesIdRS = 355,
        .nameJapanese = __("クチート　"),
        .name = "MAWILE    ",
        .catchIndex = 23,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ARON] = {
        .speciesIdRS = 382,
        .nameJapanese = __("ココドラ　"),
        .name = "ARON      ",
        .catchIndex = 0,
        .eggIndex = 10,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LAIRON
    },
    [SPECIES_LAIRON] = {
        .speciesIdRS = 383,
        .nameJapanese = __("コドラ　　"),
        .name = "LAIRON    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_AGGRON
    },
    [SPECIES_AGGRON] = {
        .speciesIdRS = 384,
        .nameJapanese = __("ボスゴドラ"),
        .name = "AGGRON    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MACHOP] = {
        .speciesIdRS = 66,
        .nameJapanese = __("ワンリキー"),
        .name = "MACHOP    ",
        .catchIndex = 24,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MACHOKE
    },
    [SPECIES_MACHOKE] = {
        .speciesIdRS = 67,
        .nameJapanese = __("ゴーリキー"),
        .name = "MACHOKE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_MACHAMP
    },
    [SPECIES_MACHAMP] = {
        .speciesIdRS = 68,
        .nameJapanese = __("カイリキー"),
        .name = "MACHAMP   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MEDITITE] = {
        .speciesIdRS = 356,
        .nameJapanese = __("アサナン　"),
        .name = "MEDITITE  ",
        .catchIndex = 25,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MEDICHAM
    },
    [SPECIES_MEDICHAM] = {
        .speciesIdRS = 357,
        .nameJapanese = __("チャーレム"),
        .name = "MEDICHAM  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ELECTRIKE] = {
        .speciesIdRS = 337,
        .nameJapanese = __("ラクライ　"),
        .name = "ELECTRIKE ",
        .catchIndex = 26,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MANECTRIC
    },
    [SPECIES_MANECTRIC] = {
        .speciesIdRS = 338,
        .nameJapanese = __("ライボルト"),
        .name = "MANECTRIC ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PLUSLE] = {
        .speciesIdRS = 353,
        .nameJapanese = __("プラスル　"),
        .name = "PLUSLE    ",
        .catchIndex = 0,
        .eggIndex = 11,
        .specialEggFlag = 1,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MINUN] = {
        .speciesIdRS = 354,
        .nameJapanese = __("マイナン　"),
        .name = "MINUN     ",
        .catchIndex = 0,
        .eggIndex = 12,
        .specialEggFlag = 1,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAGNEMITE] = {
        .speciesIdRS = 81,
        .nameJapanese = __("コイル　　"),
        .name = "MAGNEMITE ",
        .catchIndex = 27,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MAGNETON
    },
    [SPECIES_MAGNETON] = {
        .speciesIdRS = 82,
        .nameJapanese = __("レアコイル"),
        .name = "MAGNETON  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MAGNEZONE
    },
    [SPECIES_VOLTORB] = {
        .speciesIdRS = 100,
        .nameJapanese = __("ビリリダマ"),
        .name = "VOLTORB   ",
        .catchIndex = 28,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ELECTRODE
    },
    [SPECIES_ELECTRODE] = {
        .speciesIdRS = 101,
        .nameJapanese = __("マルマイン"),
        .name = "ELECTRODE ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_VOLBEAT] = {
        .speciesIdRS = 386,
        .nameJapanese = __("バルビート"),
        .name = "VOLBEAT   ",
        .catchIndex = 29,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ILLUMISE] = {
        .speciesIdRS = 387,
        .nameJapanese = __("イルミーゼ"),
        .name = "ILLUMISE  ",
        .catchIndex = 30,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ODDISH] = {
        .speciesIdRS = 43,
        .nameJapanese = __("ナゾノクサ"),
        .name = "ODDISH    ",
        .catchIndex = 191,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GLOOM
    },
    [SPECIES_GLOOM] = {
        .speciesIdRS = 44,
        .nameJapanese = __("クサイハナ"),
        .name = "GLOOM     ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 11,
        .evolutionTarget = SPECIES_VILEPLUME
    },
    [SPECIES_VILEPLUME] = {
        .speciesIdRS = 45,
        .nameJapanese = __("ラフレシア"),
        .name = "VILEPLUME ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BELLOSSOM] = {
        .speciesIdRS = 182,
        .nameJapanese = __("キレイハナ"),
        .name = "BELLOSSOM ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DODUO] = {
        .speciesIdRS = 84,
        .nameJapanese = __("ドードー　"),
        .name = "DODUO     ",
        .catchIndex = 31,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DODRIO
    },
    [SPECIES_DODRIO] = {
        .speciesIdRS = 85,
        .nameJapanese = __("ドードリオ"),
        .name = "DODRIO    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ROSELIA] = {
        .speciesIdRS = 363,
        .nameJapanese = __("ロゼリア　"),
        .name = "ROSELIA   ",
        .catchIndex = 32,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ROSERADE
    },
    [SPECIES_GULPIN] = {
        .speciesIdRS = 367,
        .nameJapanese = __("ゴクリン　"),
        .name = "GULPIN    ",
        .catchIndex = 0,
        .eggIndex = 14,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SWALOT
    },
    [SPECIES_SWALOT] = {
        .speciesIdRS = 368,
        .nameJapanese = __("マルノーム"),
        .name = "SWALOT    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CARVANHA] = {
        .speciesIdRS = 330,
        .nameJapanese = __("キバニア　"),
        .name = "CARVANHA  ",
        .catchIndex = 33,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SHARPEDO
    },
    [SPECIES_SHARPEDO] = {
        .speciesIdRS = 331,
        .nameJapanese = __("サメハダー"),
        .name = "SHARPEDO  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WAILMER] = {
        .speciesIdRS = 313,
        .nameJapanese = __("ホエルコ　"),
        .name = "WAILMER   ",
        .catchIndex = 34,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WAILORD
    },
    [SPECIES_WAILORD] = {
        .speciesIdRS = 314,
        .nameJapanese = __("ホエルオー"),
        .name = "WAILORD   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NUMEL] = {
        .speciesIdRS = 339,
        .nameJapanese = __("ドンメル　"),
        .name = "NUMEL     ",
        .catchIndex = 35,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CAMERUPT
    },
    [SPECIES_CAMERUPT] = {
        .speciesIdRS = 340,
        .nameJapanese = __("バクーダ　"),
        .name = "CAMERUPT  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SLUGMA] = {
        .speciesIdRS = 218,
        .nameJapanese = __("マグマッグ"),
        .name = "SLUGMA    ",
        .catchIndex = 36,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MAGCARGO
    },
    [SPECIES_MAGCARGO] = {
        .speciesIdRS = 219,
        .nameJapanese = __("マグカルゴ"),
        .name = "MAGCARGO  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TORKOAL] = {
        .speciesIdRS = 321,
        .nameJapanese = __("コータス　"),
        .name = "TORKOAL   ",
        .catchIndex = 37,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GRIMER] = {
        .speciesIdRS = 88,
        .nameJapanese = __("ベトベター"),
        .name = "GRIMER    ",
        .catchIndex = 38,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MUK
    },
    [SPECIES_MUK] = {
        .speciesIdRS = 89,
        .nameJapanese = __("ベトベトン"),
        .name = "MUK       ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_KOFFING] = {
        .speciesIdRS = 109,
        .nameJapanese = __("ドガース　"),
        .name = "KOFFING   ",
        .catchIndex = 39,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WEEZING
    },
    [SPECIES_WEEZING] = {
        .speciesIdRS = 110,
        .nameJapanese = __("マタドガス"),
        .name = "WEEZING   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SPOINK] = {
        .speciesIdRS = 351,
        .nameJapanese = __("バネブー　"),
        .name = "SPOINK    ",
        .catchIndex = 0,
        .eggIndex = 15,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GRUMPIG
    },
    [SPECIES_GRUMPIG] = {
        .speciesIdRS = 352,
        .nameJapanese = __("ブーピッグ"),
        .name = "GRUMPIG   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SANDSHREW] = {
        .speciesIdRS = 27,
        .nameJapanese = __("サンド　　"),
        .name = "SANDSHREW ",
        .catchIndex = 189,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SANDSLASH
    },
    [SPECIES_SANDSLASH] = {
        .speciesIdRS = 28,
        .nameJapanese = __("サンドパン"),
        .name = "SANDSLASH ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SPINDA] = {
        .speciesIdRS = 308,
        .nameJapanese = __("パッチール"),
        .name = "SPINDA    ",
        .catchIndex = 0,
        .eggIndex = 17,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SKARMORY] = {
        .speciesIdRS = 227,
        .nameJapanese = __("エアームド"),
        .name = "SKARMORY  ",
        .catchIndex = 40,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TRAPINCH] = {
        .speciesIdRS = 332,
        .nameJapanese = __("ナックラー"),
        .name = "TRAPINCH  ",
        .catchIndex = 0,
        .eggIndex = 18,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_VIBRAVA
    },
    [SPECIES_VIBRAVA] = {
        .speciesIdRS = 333,
        .nameJapanese = __("ビブラーバ"),
        .name = "VIBRAVA   ",
        .catchIndex = 41,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_FLYGON
    },
    [SPECIES_FLYGON] = {
        .speciesIdRS = 334,
        .nameJapanese = __("フライゴン"),
        .name = "FLYGON    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CACNEA] = {
        .speciesIdRS = 344,
        .nameJapanese = __("サボネア　"),
        .name = "CACNEA    ",
        .catchIndex = 42,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CACTURNE
    },
    [SPECIES_CACTURNE] = {
        .speciesIdRS = 345,
        .nameJapanese = __("ノクタス　"),
        .name = "CACTURNE  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SWABLU] = {
        .speciesIdRS = 358,
        .nameJapanese = __("チルット　"),
        .name = "SWABLU    ",
        .catchIndex = 43,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ALTARIA
    },
    [SPECIES_ALTARIA] = {
        .speciesIdRS = 359,
        .nameJapanese = __("チルタリス"),
        .name = "ALTARIA   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ZANGOOSE] = {
        .speciesIdRS = 380,
        .nameJapanese = __("ザングース"),
        .name = "ZANGOOSE  ",
        .catchIndex = 44,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SEVIPER] = {
        .speciesIdRS = 379,
        .nameJapanese = __("ハブネーク"),
        .name = "SEVIPER   ",
        .catchIndex = 45,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LUNATONE] = {
        .speciesIdRS = 348,
        .nameJapanese = __("ルナトーン"),
        .name = "LUNATONE  ",
        .catchIndex = 46,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SOLROCK] = {
        .speciesIdRS = 349,
        .nameJapanese = __("ソルロック"),
        .name = "SOLROCK   ",
        .catchIndex = 47,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BARBOACH] = {
        .speciesIdRS = 323,
        .nameJapanese = __("ドジョッチ"),
        .name = "BARBOACH  ",
        .catchIndex = 48,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WHISCASH
    },
    [SPECIES_WHISCASH] = {
        .speciesIdRS = 324,
        .nameJapanese = __("ナマズン　"),
        .name = "WHISCASH  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CORPHISH] = {
        .speciesIdRS = 326,
        .nameJapanese = __("ヘイガニ　"),
        .name = "CORPHISH  ",
        .catchIndex = 49,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CRAWDAUNT
    },
    [SPECIES_CRAWDAUNT] = {
        .speciesIdRS = 327,
        .nameJapanese = __("シザリガー"),
        .name = "CRAWDAUNT ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BALTOY] = {
        .speciesIdRS = 318,
        .nameJapanese = __("ヤジロン　"),
        .name = "BALTOY    ",
        .catchIndex = 50,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CLAYDOL
    },
    [SPECIES_CLAYDOL] = {
        .speciesIdRS = 319,
        .nameJapanese = __("ネンドール"),
        .name = "CLAYDOL   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LILEEP] = {
        .speciesIdRS = 388,
        .nameJapanese = __("リリーラ　"),
        .name = "LILEEP    ",
        .catchIndex = 51,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CRADILY
    },
    [SPECIES_CRADILY] = {
        .speciesIdRS = 389,
        .nameJapanese = __("ユレイドル"),
        .name = "CRADILY   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ANORITH] = {
        .speciesIdRS = 390,
        .nameJapanese = __("アノプス　"),
        .name = "ANORITH   ",
        .catchIndex = 52,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ARMALDO
    },
    [SPECIES_ARMALDO] = {
        .speciesIdRS = 391,
        .nameJapanese = __("アーマルド"),
        .name = "ARMALDO   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_IGGLYBUFF] = {
        .speciesIdRS = 174,
        .nameJapanese = __("ププリン　"),
        .name = "IGGLYBUFF ",
        .catchIndex = 0,
        .eggIndex = 19,
        .specialEggFlag = 1,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_JIGGLYPUFF
    },
    [SPECIES_JIGGLYPUFF] = {
        .speciesIdRS = 39,
        .nameJapanese = __("プリン　　"),
        .name = "JIGGLYPUFF",
        .catchIndex = 53,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 5,
        .evolutionTarget = SPECIES_WIGGLYTUFF
    },
    [SPECIES_WIGGLYTUFF] = {
        .speciesIdRS = 40,
        .nameJapanese = __("プクリン　"),
        .name = "WIGGLYTUFF",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_FEEBAS] = {
        .speciesIdRS = 328,
        .nameJapanese = __("ヒンバス　"),
        .name = "FEEBAS    ",
        .catchIndex = 54,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 10,
        .evolutionTarget = SPECIES_MILOTIC
    },
    [SPECIES_MILOTIC] = {
        .speciesIdRS = 329,
        .nameJapanese = __("ミロカロス"),
        .name = "MILOTIC   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CASTFORM] = {
        .speciesIdRS = 385,
        .nameJapanese = __("ポワルン　"),
        .name = "CASTFORM  ",
        .catchIndex = 55,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_STARYU] = {
        .speciesIdRS = 120,
        .nameJapanese = __("ヒトデマン"),
        .name = "STARYU    ",
        .catchIndex = 56,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 6,
        .evolutionTarget = SPECIES_STARMIE
    },
    [SPECIES_STARMIE] = {
        .speciesIdRS = 121,
        .nameJapanese = __("スターミー"),
        .name = "STARMIE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_KECLEON] = {
        .speciesIdRS = 317,
        .nameJapanese = __("カクレオン"),
        .name = "KECLEON   ",
        .catchIndex = 57,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHUPPET] = {
        .speciesIdRS = 377,
        .nameJapanese = __("カゲボウズ"),
        .name = "SHUPPET   ",
        .catchIndex = 0,
        .eggIndex = 20,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BANETTE
    },
    [SPECIES_BANETTE] = {
        .speciesIdRS = 378,
        .nameJapanese = __("ジュペッタ"),
        .name = "BANETTE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DUSKULL] = {
        .speciesIdRS = 361,
        .nameJapanese = __("ヨマワル　"),
        .name = "DUSKULL   ",
        .catchIndex = 58,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DUSCLOPS
    },
    [SPECIES_DUSCLOPS] = {
        .speciesIdRS = 362,
        .nameJapanese = __("サマヨール"),
        .name = "DUSCLOPS  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DUSKNOIR
    },
    [SPECIES_TROPIUS] = {
        .speciesIdRS = 369,
        .nameJapanese = __("トロピウス"),
        .name = "TROPIUS   ",
        .catchIndex = 59,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CHIMECHO] = {
        .speciesIdRS = 411,
        .nameJapanese = __("チリーン　"),
        .name = "CHIMECHO  ",
        .catchIndex = 0,
        .eggIndex = 21,
        .specialEggFlag = 1,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ABSOL] = {
        .speciesIdRS = 376,
        .nameJapanese = __("アブソル　"),
        .name = "ABSOL     ",
        .catchIndex = 60,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_VULPIX] = {
        .speciesIdRS = 37,
        .nameJapanese = __("ロコン　　"),
        .name = "VULPIX    ",
        .catchIndex = 61,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 3,
        .evolutionTarget = SPECIES_NINETALES
    },
    [SPECIES_NINETALES] = {
        .speciesIdRS = 38,
        .nameJapanese = __("キュウコン"),
        .name = "NINETALES ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PICHU] = {
        .speciesIdRS = 172,
        .nameJapanese = __("ピチュー　"),
        .name = "PICHU     ",
        .catchIndex = 0,
        .eggIndex = 22,
        .specialEggFlag = 1,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_PIKACHU
    },
    [SPECIES_PIKACHU] = {
        .speciesIdRS = 25,
        .nameJapanese = __("ピカチュウ"),
        .name = "PIKACHU   ",
        .catchIndex = 62,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 7,
        .evolutionTarget = SPECIES_RAICHU
    },
    [SPECIES_RAICHU] = {
        .speciesIdRS = 26,
        .nameJapanese = __("ライチュウ"),
        .name = "RAICHU    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PSYDUCK] = {
        .speciesIdRS = 54,
        .nameJapanese = __("コダック　"),
        .name = "PSYDUCK   ",
        .catchIndex = 63,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GOLDUCK
    },
    [SPECIES_GOLDUCK] = {
        .speciesIdRS = 55,
        .nameJapanese = __("ゴルダック"),
        .name = "GOLDUCK   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WYNAUT] = {
        .speciesIdRS = 360,
        .nameJapanese = __("ソーナノ　"),
        .name = "WYNAUT    ",
        .catchIndex = 0,
        .eggIndex = 23,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WOBBUFFET
    },
    [SPECIES_WOBBUFFET] = {
        .speciesIdRS = 202,
        .nameJapanese = __("ソーナンス"),
        .name = "WOBBUFFET ",
        .catchIndex = 64,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NATU] = {
        .speciesIdRS = 177,
        .nameJapanese = __("ネイティ　"),
        .name = "NATU      ",
        .catchIndex = 0,
        .eggIndex = 24,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_XATU
    },
    [SPECIES_XATU] = {
        .speciesIdRS = 178,
        .nameJapanese = __("ネイティオ"),
        .name = "XATU      ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GIRAFARIG] = {
        .speciesIdRS = 203,
        .nameJapanese = __("キリンリキ"),
        .name = "GIRAFARIG ",
        .catchIndex = 65,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PHANPY] = {
        .speciesIdRS = 231,
        .nameJapanese = __("ゴマゾウ　"),
        .name = "PHANPY    ",
        .catchIndex = 0,
        .eggIndex = 25,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DONPHAN
    },
    [SPECIES_DONPHAN] = {
        .speciesIdRS = 232,
        .nameJapanese = __("ドンファン"),
        .name = "DONPHAN   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PINSIR] = {
        .speciesIdRS = 127,
        .nameJapanese = __("カイロス　"),
        .name = "PINSIR    ",
        .catchIndex = 66,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_HERACROSS] = {
        .speciesIdRS = 214,
        .nameJapanese = __("ヘラクロス"),
        .name = "HERACROSS ",
        .catchIndex = 67,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RHYHORN] = {
        .speciesIdRS = 111,
        .nameJapanese = __("サイホーン"),
        .name = "RHYHORN   ",
        .catchIndex = 68,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_RHYDON
    },
    [SPECIES_RHYDON] = {
        .speciesIdRS = 112,
        .nameJapanese = __("サイドン　"),
        .name = "RHYDON    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_RHYPERIOR
    },
    [SPECIES_SNORUNT] = {
        .speciesIdRS = 346,
        .nameJapanese = __("ユキワラシ"),
        .name = "SNORUNT   ",
        .catchIndex = 0,
        .eggIndex = 26,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GLALIE
    },
    [SPECIES_GLALIE] = {
        .speciesIdRS = 347,
        .nameJapanese = __("オニゴーリ"),
        .name = "GLALIE    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SPHEAL] = {
        .speciesIdRS = 341,
        .nameJapanese = __("タマザラシ"),
        .name = "SPHEAL    ",
        .catchIndex = 0,
        .eggIndex = 27,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SEALEO
    },
    [SPECIES_SEALEO] = {
        .speciesIdRS = 342,
        .nameJapanese = __("トドグラー"),
        .name = "SEALEO    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WALREIN
    },
    [SPECIES_WALREIN] = {
        .speciesIdRS = 343,
        .nameJapanese = __("トドゼルガ"),
        .name = "WALREIN   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CLAMPERL] = {
        .speciesIdRS = 373,
        .nameJapanese = __("パールル　"),
        .name = "CLAMPERL  ",
        .catchIndex = 69,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 11,
        .evolutionTarget = SPECIES_HUNTAIL
    },
    [SPECIES_HUNTAIL] = {
        .speciesIdRS = 374,
        .nameJapanese = __("ハンテール"),
        .name = "HUNTAIL   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GOREBYSS] = {
        .speciesIdRS = 375,
        .nameJapanese = __("サクラビス"),
        .name = "GOREBYSS  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RELICANTH] = {
        .speciesIdRS = 381,
        .nameJapanese = __("ジーランス"),
        .name = "RELICANTH ",
        .catchIndex = 70,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CORSOLA] = {
        .speciesIdRS = 222,
        .nameJapanese = __("サニーゴ　"),
        .name = "CORSOLA   ",
        .catchIndex = 0,
        .eggIndex = 28,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CHINCHOU] = {
        .speciesIdRS = 170,
        .nameJapanese = __("チョンチー"),
        .name = "CHINCHOU  ",
        .catchIndex = 0,
        .eggIndex = 29,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LANTURN
    },
    [SPECIES_LANTURN] = {
        .speciesIdRS = 171,
        .nameJapanese = __("ランターン"),
        .name = "LANTURN   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LUVDISC] = {
        .speciesIdRS = 325,
        .nameJapanese = __("ラブカス　"),
        .name = "LUVDISC   ",
        .catchIndex = 71,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_HORSEA] = {
        .speciesIdRS = 116,
        .nameJapanese = __("タッツー　"),
        .name = "HORSEA    ",
        .catchIndex = 192,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SEADRA
    },
    [SPECIES_SEADRA] = {
        .speciesIdRS = 117,
        .nameJapanese = __("シードラ　"),
        .name = "SEADRA    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_KINGDRA
    },
    [SPECIES_KINGDRA] = {
        .speciesIdRS = 230,
        .nameJapanese = __("キングドラ"),
        .name = "KINGDRA   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BAGON] = {
        .speciesIdRS = 395,
        .nameJapanese = __("タツベイ　"),
        .name = "BAGON     ",
        .catchIndex = 0,
        .eggIndex = 31,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SHELGON
    },
    [SPECIES_SHELGON] = {
        .speciesIdRS = 396,
        .nameJapanese = __("コモルー　"),
        .name = "SHELGON   ",
        .catchIndex = 72,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SALAMENCE
    },
    [SPECIES_SALAMENCE] = {
        .speciesIdRS = 397,
        .nameJapanese = __("ボーマンダ"),
        .name = "SALAMENCE ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BELDUM] = {
        .speciesIdRS = 398,
        .nameJapanese = __("ダンバル　"),
        .name = "BELDUM    ",
        .catchIndex = 73,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_METANG
    },
    [SPECIES_METANG] = {
        .speciesIdRS = 399,
        .nameJapanese = __("メタング　"),
        .name = "METANG    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_METAGROSS
    },
    [SPECIES_METAGROSS] = {
        .speciesIdRS = 400,
        .nameJapanese = __("メタグロス"),
        .name = "METAGROSS ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_REGIROCK] = {
        .speciesIdRS = 401,
        .nameJapanese = __("レジロック"),
        .name = "REGIROCK  ",
        .catchIndex = 74,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_REGICE] = {
        .speciesIdRS = 402,
        .nameJapanese = __("レジアイス"),
        .name = "REGICE    ",
        .catchIndex = 75,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_REGISTEEL] = {
        .speciesIdRS = 403,
        .nameJapanese = __("レジスチル"),
        .name = "REGISTEEL ",
        .catchIndex = 76,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LATIAS] = {
        .speciesIdRS = 407,
        .nameJapanese = __("ラティアス"),
        .name = "LATIAS    ",
        .catchIndex = 77,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LATIOS] = {
        .speciesIdRS = 408,
        .nameJapanese = __("ラティオス"),
        .name = "LATIOS    ",
        .catchIndex = 78,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_KYOGRE] = {
        .speciesIdRS = 404,
        .nameJapanese = __("カイオーガ"),
        .name = "KYOGRE    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GROUDON] = {
        .speciesIdRS = 405,
        .nameJapanese = __("グラードン"),
        .name = "GROUDON   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RAYQUAZA] = {
        .speciesIdRS = 406,
        .nameJapanese = __("レックウザ"),
        .name = "RAYQUAZA  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_JIRACHI] = {
        .speciesIdRS = 409,
        .nameJapanese = __("ジラーチ　"),
        .name = "JIRACHI   ",
        .catchIndex = 79,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CHIKORITA] = {
        .speciesIdRS = 152,
        .nameJapanese = __("チコリータ"),
        .name = "CHIKORITA ",
        .catchIndex = 80,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BAYLEEF
    },
    [SPECIES_CYNDAQUIL] = {
        .speciesIdRS = 155,
        .nameJapanese = __("ヒノアラシ"),
        .name = "CYNDAQUIL ",
        .catchIndex = 81,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_QUILAVA
    },
    [SPECIES_TOTODILE] = {
        .speciesIdRS = 158,
        .nameJapanese = __("ワニノコ　"),
        .name = "TOTODILE  ",
        .catchIndex = 82,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CROCONAW
    },
    [SPECIES_AERODACTYL] = {
        .speciesIdRS = 142,
        .nameJapanese = __("プテラ　　"),
        .name = "AERODACTYL",
        .catchIndex = 83,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DEOXYS] = {
        .speciesIdRS = 410,
        .nameJapanese = {0},
        .name = "DEOXYS    ",
        .catchIndex = 176,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BLITZLE] = {
        .speciesIdRS = SPECIES_RS_BLITZLE,
        .nameJapanese = {0},
        .name = "BLITZLE   ",
        .catchIndex = 84,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ZEBSTRIKA
    },
    [SPECIES_BULBASAUR] = {
        .speciesIdRS = 1,
        .nameJapanese = {0},
        .name = "BULBASAUR ",
        .catchIndex = 85,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_IVYSAUR
    },
    [SPECIES_IVYSAUR] = {
        .speciesIdRS = 2,
        .nameJapanese = {0},
        .name = "IVYSAUR   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_VENUSAUR
    },
    [SPECIES_VENUSAUR] = {
        .speciesIdRS = 3,
        .nameJapanese = {0},
        .name = "VENUSAUR  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CHARMANDER] = {
        .speciesIdRS = 4,
        .nameJapanese = {0},
        .name = "CHARMANDER",
        .catchIndex = 86,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CHARMELEON
    },
    [SPECIES_CHARMELEON] = {
        .speciesIdRS = 5,
        .nameJapanese = {0},
        .name = "CHARMELEON",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CHARIZARD
    },
    [SPECIES_CHARIZARD] = {
        .speciesIdRS = 6,
        .nameJapanese = {0},
        .name = "CHARIZARD ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SQUIRTLE] = {
        .speciesIdRS = 7,
        .nameJapanese = {0},
        .name = "SQUIRTLE  ",
        .catchIndex = 87,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WARTORTLE
    },
    [SPECIES_WARTORTLE] = {
        .speciesIdRS = 8,
        .nameJapanese = {0},
        .name = "WARTORTLE ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BLASTOISE
    },
    [SPECIES_BLASTOISE] = {
        .speciesIdRS = 9,
        .nameJapanese = {0},
        .name = "BLASTOISE ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CATERPIE] = {
        .speciesIdRS = 10,
        .nameJapanese = {0},
        .name = "CATERPIE  ",
        .catchIndex = 88,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_METAPOD
    },
    [SPECIES_METAPOD] = {
        .speciesIdRS = 11,
        .nameJapanese = {0},
        .name = "METAPOD   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BUTTERFREE
    },
    [SPECIES_BUTTERFREE] = {
        .speciesIdRS = 12,
        .nameJapanese = {0},
        .name = "BUTTERFREE",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WEEDLE] = {
        .speciesIdRS = 13,
        .nameJapanese = {0},
        .name = "WEEDLE    ",
        .catchIndex = 89,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_KAKUNA
    },
    [SPECIES_KAKUNA] = {
        .speciesIdRS = 14,
        .nameJapanese = {0},
        .name = "KAKUNA    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BEEDRILL
    },
    [SPECIES_BEEDRILL] = {
        .speciesIdRS = 15,
        .nameJapanese = {0},
        .name = "BEEDRILL  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PIDGEY] = {
        .speciesIdRS = 16,
        .nameJapanese = {0},
        .name = "PIDGEY    ",
        .catchIndex = 90,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_PIDGEOTTO
    },
    [SPECIES_PIDGEOTTO] = {
        .speciesIdRS = 17,
        .nameJapanese = {0},
        .name = "PIDGEOTTO ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_PIDGEOT
    },
    [SPECIES_PIDGEOT] = {
        .speciesIdRS = 18,
        .nameJapanese = {0},
        .name = "PIDGEOT   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RATTATA] = {
        .speciesIdRS = 19,
        .nameJapanese = {0},
        .name = "RATTATA   ",
        .catchIndex = 91,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_RATICATE
    },
    [SPECIES_RATICATE] = {
        .speciesIdRS = 20,
        .nameJapanese = {0},
        .name = "RATICATE  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SPEAROW] = {
        .speciesIdRS = 21,
        .nameJapanese = {0},
        .name = "SPEAROW   ",
        .catchIndex = 92,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_FEAROW
    },
    [SPECIES_FEAROW] = {
        .speciesIdRS = 22,
        .nameJapanese = {0},
        .name = "FEAROW    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_EKANS] = {
        .speciesIdRS = 23,
        .nameJapanese = {0},
        .name = "EKANS     ",
        .catchIndex = 93,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ARBOK
    },
    [SPECIES_ARBOK] = {
        .speciesIdRS = 24,
        .nameJapanese = {0},
        .name = "ARBOK     ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NIDORAN_F] = {
        .speciesIdRS = 29,
        .nameJapanese = {0},
        .name = "NIDORAN F ",
        .catchIndex = 94,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_NIDORINA
    },
    [SPECIES_NIDORINA] = {
        .speciesIdRS = 30,
        .nameJapanese = {0},
        .name = "NIDORINA  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 5,
        .evolutionTarget = SPECIES_NIDOQUEEN
    },
    [SPECIES_NIDOQUEEN] = {
        .speciesIdRS = 31,
        .nameJapanese = {0},
        .name = "NIDOQUEEN ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_NIDORAN_M] = {
        .speciesIdRS = 32,
        .nameJapanese = {0},
        .name = "NIDORAN M ",
        .catchIndex = 95,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_NIDORINO
    },
    [SPECIES_NIDORINO] = {
        .speciesIdRS = 33,
        .nameJapanese = {0},
        .name = "NIDORINO  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 5,
        .evolutionTarget = SPECIES_NIDOKING
    },
    [SPECIES_NIDOKING] = {
        .speciesIdRS = 34,
        .nameJapanese = {0},
        .name = "NIDOKING  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CLEFAIRY] = {
        .speciesIdRS = 35,
        .nameJapanese = {0},
        .name = "CLEFAIRY  ",
        .catchIndex = 96,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 5,
        .evolutionTarget = SPECIES_CLEFABLE
    },
    [SPECIES_CLEFABLE] = {
        .speciesIdRS = 36,
        .nameJapanese = {0},
        .name = "CLEFABLE  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PARAS] = {
        .speciesIdRS = 46,
        .nameJapanese = {0},
        .name = "PARAS     ",
        .catchIndex = 97,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_PARASECT
    },
    [SPECIES_PARASECT] = {
        .speciesIdRS = 47,
        .nameJapanese = {0},
        .name = "PARASECT  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_VENONAT] = {
        .speciesIdRS = 48,
        .nameJapanese = {0},
        .name = "VENONAT   ",
        .catchIndex = 98,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_VENOMOTH
    },
    [SPECIES_VENOMOTH] = {
        .speciesIdRS = 49,
        .nameJapanese = {0},
        .name = "VENOMOTH  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DIGLETT] = {
        .speciesIdRS = 50,
        .nameJapanese = {0},
        .name = "DIGLETT   ",
        .catchIndex = 99,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DUGTRIO
    },
    [SPECIES_DUGTRIO] = {
        .speciesIdRS = 51,
        .nameJapanese = {0},
        .name = "DUGTRIO   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MEOWTH] = {
        .speciesIdRS = 52,
        .nameJapanese = {0},
        .name = "MEOWTH    ",
        .catchIndex = 100,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_PERSIAN
    },
    [SPECIES_PERSIAN] = {
        .speciesIdRS = 53,
        .nameJapanese = {0},
        .name = "PERSIAN   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MANKEY] = {
        .speciesIdRS = 56,
        .nameJapanese = {0},
        .name = "MANKEY    ",
        .catchIndex = 101,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_PRIMEAPE
    },
    [SPECIES_PRIMEAPE] = {
        .speciesIdRS = 57,
        .nameJapanese = {0},
        .name = "PRIMEAPE  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GROWLITHE] = {
        .speciesIdRS = 58,
        .nameJapanese = {0},
        .name = "GROWLITHE ",
        .catchIndex = 102,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 3,
        .evolutionTarget = SPECIES_ARCANINE
    },
    [SPECIES_ARCANINE] = {
        .speciesIdRS = 59,
        .nameJapanese = {0},
        .name = "ARCANINE  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_POLIWAG] = {
        .speciesIdRS = 60,
        .nameJapanese = {0},
        .name = "POLIWAG   ",
        .catchIndex = 103,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_POLIWHIRL
    },
    [SPECIES_POLIWHIRL] = {
        .speciesIdRS = 61,
        .nameJapanese = {0},
        .name = "POLIWHIRL ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 6,
        .evolutionTarget = SPECIES_POLIWRATH
    },
    [SPECIES_POLIWRATH] = {
        .speciesIdRS = 62,
        .nameJapanese = {0},
        .name = "POLIWRATH ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BELLSPROUT] = {
        .speciesIdRS = 69,
        .nameJapanese = {0},
        .name = "BELLSPROUT",
        .catchIndex = 104,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WEEPINBELL
    },
    [SPECIES_WEEPINBELL] = {
        .speciesIdRS = 70,
        .nameJapanese = {0},
        .name = "WEEPINBELL",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 2,
        .evolutionTarget = SPECIES_VICTREEBEL
    },
    [SPECIES_VICTREEBEL] = {
        .speciesIdRS = 71,
        .nameJapanese = {0},
        .name = "VICTREEBEL",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PONYTA] = {
        .speciesIdRS = 77,
        .nameJapanese = {0},
        .name = "PONYTA    ",
        .catchIndex = 105,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_RAPIDASH
    },
    [SPECIES_RAPIDASH] = {
        .speciesIdRS = 78,
        .nameJapanese = {0},
        .name = "RAPIDASH  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SLOWPOKE] = {
        .speciesIdRS = 79,
        .nameJapanese = {0},
        .name = "SLOWPOKE  ",
        .catchIndex = 106,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SLOWBRO
    },
    [SPECIES_SLOWBRO] = {
        .speciesIdRS = 80,
        .nameJapanese = {0},
        .name = "SLOWBRO   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_FARFETCHD] = {
        .speciesIdRS = 83,
        .nameJapanese = {0},
        .name = "FARFETCHD ",
        .catchIndex = 107,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SEEL] = {
        .speciesIdRS = 86,
        .nameJapanese = {0},
        .name = "SEEL      ",
        .catchIndex = 108,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DEWGONG
    },
    [SPECIES_DEWGONG] = {
        .speciesIdRS = 87,
        .nameJapanese = {0},
        .name = "DEWGONG   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHELLDER] = {
        .speciesIdRS = 90,
        .nameJapanese = {0},
        .name = "SHELLDER  ",
        .catchIndex = 109,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 6,
        .evolutionTarget = SPECIES_CLOYSTER
    },
    [SPECIES_CLOYSTER] = {
        .speciesIdRS = 91,
        .nameJapanese = {0},
        .name = "CLOYSTER  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GASTLY] = {
        .speciesIdRS = 92,
        .nameJapanese = {0},
        .name = "GASTLY    ",
        .catchIndex = 110,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_HAUNTER
    },
    [SPECIES_HAUNTER] = {
        .speciesIdRS = 93,
        .nameJapanese = {0},
        .name = "HAUNTER   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_GENGAR
    },
    [SPECIES_GENGAR] = {
        .speciesIdRS = 94,
        .nameJapanese = {0},
        .name = "GENGAR    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ONIX] = {
        .speciesIdRS = 95,
        .nameJapanese = {0},
        .name = "ONIX      ",
        .catchIndex = 111,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_STEELIX
    },
    [SPECIES_DROWZEE] = {
        .speciesIdRS = 96,
        .nameJapanese = {0},
        .name = "DROWZEE   ",
        .catchIndex = 112,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_HYPNO
    },
    [SPECIES_HYPNO] = {
        .speciesIdRS = 97,
        .nameJapanese = {0},
        .name = "HYPNO     ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_KRABBY] = {
        .speciesIdRS = 98,
        .nameJapanese = {0},
        .name = "KRABBY    ",
        .catchIndex = 113,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_KINGLER
    },
    [SPECIES_KINGLER] = {
        .speciesIdRS = 99,
        .nameJapanese = {0},
        .name = "KINGLER   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_EXEGGCUTE] = {
        .speciesIdRS = 102,
        .nameJapanese = {0},
        .name = "EXEGGCUTE ",
        .catchIndex = 114,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 2,
        .evolutionTarget = SPECIES_EXEGGUTOR
    },
    [SPECIES_EXEGGUTOR] = {
        .speciesIdRS = 103,
        .nameJapanese = {0},
        .name = "EXEGGUTOR ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CUBONE] = {
        .speciesIdRS = 104,
        .nameJapanese = {0},
        .name = "CUBONE    ",
        .catchIndex = 115,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MAROWAK
    },
    [SPECIES_MAROWAK] = {
        .speciesIdRS = 105,
        .nameJapanese = {0},
        .name = "MAROWAK   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_HITMONLEE] = {
        .speciesIdRS = 106,
        .nameJapanese = {0},
        .name = "HITMONLEE ",
        .catchIndex = 116,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_HITMONCHAN] = {
        .speciesIdRS = 107,
        .nameJapanese = {0},
        .name = "HITMONCHAN",
        .catchIndex = 117,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LICKITUNG] = {
        .speciesIdRS = 108,
        .nameJapanese = {0},
        .name = "LICKITUNG ",
        .catchIndex = 118,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LICKILICKY
    },
    [SPECIES_CHANSEY] = {
        .speciesIdRS = 113,
        .nameJapanese = {0},
        .name = "CHANSEY   ",
        .catchIndex = 119,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_BLISSEY
    },
    [SPECIES_TANGELA] = {
        .speciesIdRS = 114,
        .nameJapanese = {0},
        .name = "TANGELA   ",
        .catchIndex = 120,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_TANGROWTH
    },
    [SPECIES_KANGASKHAN] = {
        .speciesIdRS = 115,
        .nameJapanese = {0},
        .name = "KANGASKHAN",
        .catchIndex = 121,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MR_MIME] = {
        .speciesIdRS = 122,
        .nameJapanese = {0},
        .name = "MR MIME   ",
        .catchIndex = 122,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SCYTHER] = {
        .speciesIdRS = 123,
        .nameJapanese = {0},
        .name = "SCYTHER   ",
        .catchIndex = 123,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_SCIZOR
    },
    [SPECIES_JYNX] = {
        .speciesIdRS = 124,
        .nameJapanese = {0},
        .name = "JYNX      ",
        .catchIndex = 124,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ELECTABUZZ] = {
        .speciesIdRS = 125,
        .nameJapanese = {0},
        .name = "ELECTABUZZ",
        .catchIndex = 125,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ELECTIVIRE
    },
    [SPECIES_MAGMAR] = {
        .speciesIdRS = 126,
        .nameJapanese = {0},
        .name = "MAGMAR    ",
        .catchIndex = 126,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MAGMORTAR
    },
    [SPECIES_TAUROS] = {
        .speciesIdRS = 128,
        .nameJapanese = {0},
        .name = "TAUROS    ",
        .catchIndex = 127,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LAPRAS] = {
        .speciesIdRS = 131,
        .nameJapanese = {0},
        .name = "LAPRAS    ",
        .catchIndex = 128,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DITTO] = {
        .speciesIdRS = 132,
        .nameJapanese = {0},
        .name = "DITTO     ",
        .catchIndex = 129,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_EEVEE] = {
        .speciesIdRS = 133,
        .nameJapanese = {0},
        .name = "EEVEE     ",
        .catchIndex = 130,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 6,
        .evolutionTarget = SPECIES_VAPOREON
    },
    [SPECIES_VAPOREON] = {
        .speciesIdRS = 134,
        .nameJapanese = {0},
        .name = "VAPOREON  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_JOLTEON] = {
        .speciesIdRS = 135,
        .nameJapanese = {0},
        .name = "JOLTEON   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_FLAREON] = {
        .speciesIdRS = 136,
        .nameJapanese = {0},
        .name = "FLAREON   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PORYGON] = {
        .speciesIdRS = 137,
        .nameJapanese = {0},
        .name = "PORYGON   ",
        .catchIndex = 131,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 4,
        .evolutionTarget = SPECIES_PORYGON2
    },
    [SPECIES_OMANYTE] = {
        .speciesIdRS = 138,
        .nameJapanese = {0},
        .name = "OMANYTE   ",
        .catchIndex = 132,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_OMASTAR
    },
    [SPECIES_OMASTAR] = {
        .speciesIdRS = 139,
        .nameJapanese = {0},
        .name = "OMASTAR   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_KABUTO] = {
        .speciesIdRS = 140,
        .nameJapanese = {0},
        .name = "KABUTO    ",
        .catchIndex = 133,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_KABUTOPS
    },
    [SPECIES_KABUTOPS] = {
        .speciesIdRS = 141,
        .nameJapanese = {0},
        .name = "KABUTOPS  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SNORLAX] = {
        .speciesIdRS = 143,
        .nameJapanese = {0},
        .name = "SNORLAX   ",
        .catchIndex = 134,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ARTICUNO] = {
        .speciesIdRS = 144,
        .nameJapanese = {0},
        .name = "ARTICUNO  ",
        .catchIndex = 135,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ZAPDOS] = {
        .speciesIdRS = 145,
        .nameJapanese = {0},
        .name = "ZAPDOS    ",
        .catchIndex = 136,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MOLTRES] = {
        .speciesIdRS = 146,
        .nameJapanese = {0},
        .name = "MOLTRES   ",
        .catchIndex = 137,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DRATINI] = {
        .speciesIdRS = 147,
        .nameJapanese = {0},
        .name = "DRATINI   ",
        .catchIndex = 138,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DRAGONAIR
    },
    [SPECIES_DRAGONAIR] = {
        .speciesIdRS = 148,
        .nameJapanese = {0},
        .name = "DRAGONAIR ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DRAGONITE
    },
    [SPECIES_DRAGONITE] = {
        .speciesIdRS = 149,
        .nameJapanese = {0},
        .name = "DRAGONITE ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MEWTWO] = {
        .speciesIdRS = 150,
        .nameJapanese = {0},
        .name = "MEWTWO    ",
        .catchIndex = 139,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MEW] = {
        .speciesIdRS = 151,
        .nameJapanese = {0},
        .name = "MEW       ",
        .catchIndex = 140,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BAYLEEF] = {
        .speciesIdRS = 153,
        .nameJapanese = {0},
        .name = "BAYLEEF   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MEGANIUM
    },
    [SPECIES_MEGANIUM] = {
        .speciesIdRS = 154,
        .nameJapanese = {0},
        .name = "MEGANIUM  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_QUILAVA] = {
        .speciesIdRS = 156,
        .nameJapanese = {0},
        .name = "QUILAVA   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_TYPHLOSION
    },
    [SPECIES_TYPHLOSION] = {
        .speciesIdRS = 157,
        .nameJapanese = {0},
        .name = "TYPHLOSION",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CROCONAW] = {
        .speciesIdRS = 159,
        .nameJapanese = {0},
        .name = "CROCONAW  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_FERALIGATR
    },
    [SPECIES_FERALIGATR] = {
        .speciesIdRS = 160,
        .nameJapanese = {0},
        .name = "FERALIGATR",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SENTRET] = {
        .speciesIdRS = 161,
        .nameJapanese = {0},
        .name = "SENTRET   ",
        .catchIndex = 141,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_FURRET
    },
    [SPECIES_FURRET] = {
        .speciesIdRS = 162,
        .nameJapanese = {0},
        .name = "FURRET    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_HOOTHOOT] = {
        .speciesIdRS = 163,
        .nameJapanese = {0},
        .name = "HOOTHOOT  ",
        .catchIndex = 142,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_NOCTOWL
    },
    [SPECIES_NOCTOWL] = {
        .speciesIdRS = 164,
        .nameJapanese = {0},
        .name = "NOCTOWL   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LEDYBA] = {
        .speciesIdRS = 165,
        .nameJapanese = {0},
        .name = "LEDYBA    ",
        .catchIndex = 143,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LEDIAN
    },
    [SPECIES_LEDIAN] = {
        .speciesIdRS = 166,
        .nameJapanese = {0},
        .name = "LEDIAN    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SPINARAK] = {
        .speciesIdRS = 167,
        .nameJapanese = {0},
        .name = "SPINARAK  ",
        .catchIndex = 144,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ARIADOS
    },
    [SPECIES_ARIADOS] = {
        .speciesIdRS = 168,
        .nameJapanese = {0},
        .name = "ARIADOS   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CLEFFA] = {
        .speciesIdRS = 173,
        .nameJapanese = {0},
        .name = "CLEFFA    ",
        .catchIndex = 0,
        .eggIndex = 33,
        .specialEggFlag = 1,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_CLEFAIRY
    },
    [SPECIES_TOGEPI] = {
        .speciesIdRS = 175,
        .nameJapanese = {0},
        .name = "TOGEPI    ",
        .catchIndex = 0,
        .eggIndex = 38,
        .specialEggFlag = 1,
        .evolutionMethod = 9,
        .evolutionTarget = SPECIES_TOGETIC
    },
    [SPECIES_TOGETIC] = {
        .speciesIdRS = 176,
        .nameJapanese = {0},
        .name = "TOGETIC   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_TOGEKISS
    },
    [SPECIES_MAREEP] = {
        .speciesIdRS = 179,
        .nameJapanese = {0},
        .name = "MAREEP    ",
        .catchIndex = 145,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_FLAAFFY
    },
    [SPECIES_FLAAFFY] = {
        .speciesIdRS = 180,
        .nameJapanese = {0},
        .name = "FLAAFFY   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_AMPHAROS
    },
    [SPECIES_AMPHAROS] = {
        .speciesIdRS = 181,
        .nameJapanese = {0},
        .name = "AMPHAROS  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SUDOWOODO] = {
        .speciesIdRS = 185,
        .nameJapanese = {0},
        .name = "SUDOWOODO ",
        .catchIndex = 146,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_POLITOED] = {
        .speciesIdRS = 186,
        .nameJapanese = {0},
        .name = "POLITOED  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_HOPPIP] = {
        .speciesIdRS = 187,
        .nameJapanese = {0},
        .name = "HOPPIP    ",
        .catchIndex = 147,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SKIPLOOM
    },
    [SPECIES_SKIPLOOM] = {
        .speciesIdRS = 188,
        .nameJapanese = {0},
        .name = "SKIPLOOM  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_JUMPLUFF
    },
    [SPECIES_JUMPLUFF] = {
        .speciesIdRS = 189,
        .nameJapanese = {0},
        .name = "JUMPLUFF  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_AIPOM] = {
        .speciesIdRS = 190,
        .nameJapanese = {0},
        .name = "AIPOM     ",
        .catchIndex = 148,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_AMBIPOM
    },
    [SPECIES_SUNKERN] = {
        .speciesIdRS = 191,
        .nameJapanese = {0},
        .name = "SUNKERN   ",
        .catchIndex = 149,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 8,
        .evolutionTarget = SPECIES_SUNFLORA
    },
    [SPECIES_SUNFLORA] = {
        .speciesIdRS = 192,
        .nameJapanese = {0},
        .name = "SUNFLORA  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_YANMA] = {
        .speciesIdRS = 193,
        .nameJapanese = {0},
        .name = "YANMA     ",
        .catchIndex = 150,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_YANMEGA
    },
    [SPECIES_WOOPER] = {
        .speciesIdRS = 194,
        .nameJapanese = {0},
        .name = "WOOPER    ",
        .catchIndex = 151,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_QUAGSIRE
    },
    [SPECIES_QUAGSIRE] = {
        .speciesIdRS = 195,
        .nameJapanese = {0},
        .name = "QUAGSIRE  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ESPEON] = {
        .speciesIdRS = 196,
        .nameJapanese = {0},
        .name = "ESPEON    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_UMBREON] = {
        .speciesIdRS = 197,
        .nameJapanese = {0},
        .name = "UMBREON   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MURKROW] = {
        .speciesIdRS = 198,
        .nameJapanese = {0},
        .name = "MURKROW   ",
        .catchIndex = 152,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_HONCHKROW
    },
    [SPECIES_SLOWKING] = {
        .speciesIdRS = 199,
        .nameJapanese = {0},
        .name = "SLOWKING  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MISDREAVUS] = {
        .speciesIdRS = 200,
        .nameJapanese = {0},
        .name = "MISDREAVUS",
        .catchIndex = 153,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MISMAGIUS
    },
    [SPECIES_UNOWN] = {
        .speciesIdRS = 201,
        .nameJapanese = {0},
        .name = "UNOWN     ",
        .catchIndex = 154,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PINECO] = {
        .speciesIdRS = 204,
        .nameJapanese = {0},
        .name = "PINECO    ",
        .catchIndex = 155,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_FORRETRESS
    },
    [SPECIES_FORRETRESS] = {
        .speciesIdRS = 205,
        .nameJapanese = {0},
        .name = "FORRETRESS",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DUNSPARCE] = {
        .speciesIdRS = 206,
        .nameJapanese = {0},
        .name = "DUNSPARCE ",
        .catchIndex = 156,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GLIGAR] = {
        .speciesIdRS = 207,
        .nameJapanese = {0},
        .name = "GLIGAR    ",
        .catchIndex = 157,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GLISCOR
    },
    [SPECIES_STEELIX] = {
        .speciesIdRS = 208,
        .nameJapanese = {0},
        .name = "STEELIX   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SNUBBULL] = {
        .speciesIdRS = 209,
        .nameJapanese = {0},
        .name = "SNUBBULL  ",
        .catchIndex = 158,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GRANBULL
    },
    [SPECIES_GRANBULL] = {
        .speciesIdRS = 210,
        .nameJapanese = {0},
        .name = "GRANBULL  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_QWILFISH] = {
        .speciesIdRS = 211,
        .nameJapanese = {0},
        .name = "QWILFISH  ",
        .catchIndex = 159,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SCIZOR] = {
        .speciesIdRS = 212,
        .nameJapanese = {0},
        .name = "SCIZOR    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHUCKLE] = {
        .speciesIdRS = 213,
        .nameJapanese = {0},
        .name = "SHUCKLE   ",
        .catchIndex = 160,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SNEASEL] = {
        .speciesIdRS = 215,
        .nameJapanese = {0},
        .name = "SNEASEL   ",
        .catchIndex = 161,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WEAVILE
    },
    [SPECIES_TEDDIURSA] = {
        .speciesIdRS = 216,
        .nameJapanese = {0},
        .name = "TEDDIURSA ",
        .catchIndex = 162,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_URSARING
    },
    [SPECIES_URSARING] = {
        .speciesIdRS = 217,
        .nameJapanese = {0},
        .name = "URSARING  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SWINUB] = {
        .speciesIdRS = 220,
        .nameJapanese = {0},
        .name = "SWINUB    ",
        .catchIndex = 0,
        .eggIndex = 37,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_PILOSWINE
    },
    [SPECIES_PILOSWINE] = {
        .speciesIdRS = 221,
        .nameJapanese = {0},
        .name = "PILOSWINE ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MAMOSWINE
    },
    [SPECIES_REMORAID] = {
        .speciesIdRS = 223,
        .nameJapanese = {0},
        .name = "REMORAID  ",
        .catchIndex = 163,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_OCTILLERY
    },
    [SPECIES_OCTILLERY] = {
        .speciesIdRS = 224,
        .nameJapanese = {0},
        .name = "OCTILLERY ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DELIBIRD] = {
        .speciesIdRS = 225,
        .nameJapanese = {0},
        .name = "DELIBIRD  ",
        .catchIndex = 164,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MANTINE] = {
        .speciesIdRS = 226,
        .nameJapanese = {0},
        .name = "MANTINE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_HOUNDOUR] = {
        .speciesIdRS = 228,
        .nameJapanese = {0},
        .name = "HOUNDOUR  ",
        .catchIndex = 165,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_HOUNDOOM
    },
    [SPECIES_HOUNDOOM] = {
        .speciesIdRS = 229,
        .nameJapanese = {0},
        .name = "HOUNDOOM  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PORYGON2] = {
        .speciesIdRS = 233,
        .nameJapanese = {0},
        .name = "PORYGON2  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_PORYGON_Z
    },
    [SPECIES_STANTLER] = {
        .speciesIdRS = 234,
        .nameJapanese = {0},
        .name = "STANTLER  ",
        .catchIndex = 166,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SMEARGLE] = {
        .speciesIdRS = 235,
        .nameJapanese = {0},
        .name = "SMEARGLE  ",
        .catchIndex = 167,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TYROGUE] = {
        .speciesIdRS = 236,
        .nameJapanese = {0},
        .name = "TYROGUE   ",
        .catchIndex = 0,
        .eggIndex = 39,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_HITMONTOP
    },
    [SPECIES_HITMONTOP] = {
        .speciesIdRS = 237,
        .nameJapanese = {0},
        .name = "HITMONTOP ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SMOOCHUM] = {
        .speciesIdRS = 238,
        .nameJapanese = {0},
        .name = "SMOOCHUM  ",
        .catchIndex = 0,
        .eggIndex = 36,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_JYNX
    },
    [SPECIES_ELEKID] = {
        .speciesIdRS = 239,
        .nameJapanese = {0},
        .name = "ELEKID    ",
        .catchIndex = 0,
        .eggIndex = 34,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ELECTABUZZ
    },
    [SPECIES_MAGBY] = {
        .speciesIdRS = 240,
        .nameJapanese = {0},
        .name = "MAGBY     ",
        .catchIndex = 0,
        .eggIndex = 35,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MAGMAR
    },
    [SPECIES_MILTANK] = {
        .speciesIdRS = 241,
        .nameJapanese = {0},
        .name = "MILTANK   ",
        .catchIndex = 168,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BLISSEY] = {
        .speciesIdRS = 242,
        .nameJapanese = {0},
        .name = "BLISSEY   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RAIKOU] = {
        .speciesIdRS = 243,
        .nameJapanese = {0},
        .name = "RAIKOU    ",
        .catchIndex = 169,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ENTEI] = {
        .speciesIdRS = 244,
        .nameJapanese = {0},
        .name = "ENTEI     ",
        .catchIndex = 170,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SUICUNE] = {
        .speciesIdRS = 245,
        .nameJapanese = {0},
        .name = "SUICUNE   ",
        .catchIndex = 171,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LARVITAR] = {
        .speciesIdRS = 246,
        .nameJapanese = {0},
        .name = "LARVITAR  ",
        .catchIndex = 172,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_PUPITAR
    },
    [SPECIES_PUPITAR] = {
        .speciesIdRS = 247,
        .nameJapanese = {0},
        .name = "PUPITAR   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_TYRANITAR
    },
    [SPECIES_TYRANITAR] = {
        .speciesIdRS = 248,
        .nameJapanese = {0},
        .name = "TYRANITAR ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LUGIA] = {
        .speciesIdRS = 249,
        .nameJapanese = {0},
        .name = "LUGIA     ",
        .catchIndex = 173,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_HO_OH] = {
        .speciesIdRS = 250,
        .nameJapanese = {0},
        .name = "HO-OH     ",
        .catchIndex = 174,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CELEBI] = {
        .speciesIdRS = 251,
        .nameJapanese = {0},
        .name = "CELEBI    ",
        .catchIndex = 175,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ZEBSTRIKA] = {
        .speciesIdRS = SPECIES_RS_ZEBSTRIKA,
        .nameJapanese = {0},
        .name = "ZEBSTRIKA ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TURTWIG] = {
        .speciesIdRS = SPECIES_RS_TURTWIG,
        .nameJapanese = {0},
        .name = "TURTWIG   ",
        .catchIndex = 177,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GROTLE
    },
    [SPECIES_GROTLE] = {
        .speciesIdRS = SPECIES_RS_GROTLE,
        .nameJapanese = {0},
        .name = "GROTLE    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_TORTERRA
    },
    [SPECIES_TORTERRA] = {
        .speciesIdRS = SPECIES_RS_TORTERRA,
        .nameJapanese = {0},
        .name = "TORTERRA  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CHIMCHAR] = {
        .speciesIdRS = SPECIES_RS_CHIMCHAR,
        .nameJapanese = {0},
        .name = "CHIMCHAR  ",
        .catchIndex = 178,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MONFERNO
    },
    [SPECIES_MONFERNO] = {
        .speciesIdRS = SPECIES_RS_MONFERNO,
        .nameJapanese = {0},
        .name = "MONFERNO  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_INFERNAPE
    },
    [SPECIES_INFERNAPE] = {
        .speciesIdRS = SPECIES_RS_INFERNAPE,
        .nameJapanese = {0},
        .name = "INFERNAPE ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PIPLUP] = {
        .speciesIdRS = SPECIES_RS_PIPLUP,
        .nameJapanese = {0},
        .name = "PIPLUP    ",
        .catchIndex = 179,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_PRINPLUP
    },
    [SPECIES_PRINPLUP] = {
        .speciesIdRS = SPECIES_RS_PRINPLUP,
        .nameJapanese = {0},
        .name = "PRINPLUP  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_EMPOLEON
    },
    [SPECIES_EMPOLEON] = {
        .speciesIdRS = SPECIES_RS_EMPOLEON,
        .nameJapanese = {0},
        .name = "EMPOLEON  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_STARLY] = {
        .speciesIdRS = SPECIES_RS_STARLY,
        .nameJapanese = {0},
        .name = "STARLY    ",
        .catchIndex = 180,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_STARAVIA
    },
    [SPECIES_STARAVIA] = {
        .speciesIdRS = SPECIES_RS_STARAVIA,
        .nameJapanese = {0},
        .name = "STARAVIA  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_STARAPTOR
    },
    [SPECIES_STARAPTOR] = {
        .speciesIdRS = SPECIES_RS_STARAPTOR,
        .nameJapanese = {0},
        .name = "STARAPTOR ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BIDOOF] = {
        .speciesIdRS = SPECIES_RS_BIDOOF,
        .nameJapanese = {0},
        .name = "BIDOOF    ",
        .catchIndex = 181,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BIBAREL
    },
    [SPECIES_BIBAREL] = {
        .speciesIdRS = SPECIES_RS_BIBAREL,
        .nameJapanese = {0},
        .name = "BIBAREL   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_KRICKETOT] = {
        .speciesIdRS = SPECIES_RS_KRICKETOT,
        .nameJapanese = {0},
        .name = "KRICKETOT ",
        .catchIndex = 182,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_KRICKETUNE
    },
    [SPECIES_KRICKETUNE] = {
        .speciesIdRS = SPECIES_RS_KRICKETUNE,
        .nameJapanese = {0},
        .name = "KRICKETUNE",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHINX] = {
        .speciesIdRS = SPECIES_RS_SHINX,
        .nameJapanese = {0},
        .name = "SHINX     ",
        .catchIndex = 183,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LUXIO
    },
    [SPECIES_LUXIO] = {
        .speciesIdRS = SPECIES_RS_LUXIO,
        .nameJapanese = {0},
        .name = "LUXIO     ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LUXRAY
    },
    [SPECIES_LUXRAY] = {
        .speciesIdRS = SPECIES_RS_LUXRAY,
        .nameJapanese = {0},
        .name = "LUXRAY    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BUDEW] = {
        .speciesIdRS = SPECIES_RS_BUDEW,
        .nameJapanese = {0},
        .name = "BUDEW     ",
        .catchIndex = 0,
        .eggIndex = 41,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ROSELIA
    },
    [SPECIES_ROSERADE] = {
        .speciesIdRS = SPECIES_RS_ROSERADE,
        .nameJapanese = {0},
        .name = "ROSERADE  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CRANIDOS] = {
        .speciesIdRS = SPECIES_RS_CRANIDOS,
        .nameJapanese = {0},
        .name = "CRANIDOS  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_RAMPARDOS
    },
    [SPECIES_RAMPARDOS] = {
        .speciesIdRS = SPECIES_RS_RAMPARDOS,
        .nameJapanese = {0},
        .name = "RAMPARDOS ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHIELDON] = {
        .speciesIdRS = SPECIES_RS_SHIELDON,
        .nameJapanese = {0},
        .name = "SHIELDON  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BASTIODON
    },
    [SPECIES_BASTIODON] = {
        .speciesIdRS = SPECIES_RS_BASTIODON,
        .nameJapanese = {0},
        .name = "BASTIODON ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BURMY] = {
        .speciesIdRS = SPECIES_RS_BURMY,
        .nameJapanese = {0},
        .name = "BURMY     ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_WORMADAM
    },
    [SPECIES_WORMADAM] = {
        .speciesIdRS = SPECIES_RS_WORMADAM,
        .nameJapanese = {0},
        .name = "WORMADAM  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MOTHIM] = {
        .speciesIdRS = SPECIES_RS_MOTHIM,
        .nameJapanese = {0},
        .name = "MOTHIM    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_COMBEE] = {
        .speciesIdRS = SPECIES_RS_COMBEE,
        .nameJapanese = {0},
        .name = "COMBEE    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_VESPIQUEN
    },
    [SPECIES_VESPIQUEN] = {
        .speciesIdRS = SPECIES_RS_VESPIQUEN,
        .nameJapanese = {0},
        .name = "VESPIQUEN ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PACHIRISU] = {
        .speciesIdRS = SPECIES_RS_PACHIRISU,
        .nameJapanese = {0},
        .name = "PACHIRISU ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BUIZEL] = {
        .speciesIdRS = SPECIES_RS_BUIZEL,
        .nameJapanese = {0},
        .name = "BUIZEL    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_FLOATZEL
    },
    [SPECIES_FLOATZEL] = {
        .speciesIdRS = SPECIES_RS_FLOATZEL,
        .nameJapanese = {0},
        .name = "FLOATZEL  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CHERUBI] = {
        .speciesIdRS = SPECIES_RS_CHERUBI,
        .nameJapanese = {0},
        .name = "CHERUBI   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CHERRIM
    },
    [SPECIES_CHERRIM] = {
        .speciesIdRS = SPECIES_RS_CHERRIM,
        .nameJapanese = {0},
        .name = "CHERRIM   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHELLOS] = {
        .speciesIdRS = SPECIES_RS_SHELLOS,
        .nameJapanese = {0},
        .name = "SHELLOS   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GASTRODON
    },
    [SPECIES_GASTRODON] = {
        .speciesIdRS = SPECIES_RS_GASTRODON,
        .nameJapanese = {0},
        .name = "GASTRODON ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_AMBIPOM] = {
        .speciesIdRS = SPECIES_RS_AMBIPOM,
        .nameJapanese = {0},
        .name = "AMBIPOM   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DRIFLOON] = {
        .speciesIdRS = SPECIES_RS_DRIFLOON,
        .nameJapanese = {0},
        .name = "DRIFLOON  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DRIFBLIM
    },
    [SPECIES_DRIFBLIM] = {
        .speciesIdRS = SPECIES_RS_DRIFBLIM,
        .nameJapanese = {0},
        .name = "DRIFBLIM  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BUNEARY] = {
        .speciesIdRS = SPECIES_RS_BUNEARY,
        .nameJapanese = {0},
        .name = "BUNEARY   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LOPUNNY
    },
    [SPECIES_LOPUNNY] = {
        .speciesIdRS = SPECIES_RS_LOPUNNY,
        .nameJapanese = {0},
        .name = "LOPUNNY   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MISMAGIUS] = {
        .speciesIdRS = SPECIES_RS_MISMAGIUS,
        .nameJapanese = {0},
        .name = "MISMAGIUS ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_HONCHKROW] = {
        .speciesIdRS = SPECIES_RS_HONCHKROW,
        .nameJapanese = {0},
        .name = "HONCHKROW ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GLAMEOW] = {
        .speciesIdRS = SPECIES_RS_GLAMEOW,
        .nameJapanese = {0},
        .name = "GLAMEOW   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_PURUGLY
    },
    [SPECIES_PURUGLY] = {
        .speciesIdRS = SPECIES_RS_PURUGLY,
        .nameJapanese = {0},
        .name = "PURUGLY   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CHINGLING] = {
        .speciesIdRS = SPECIES_RS_CHINGLING,
        .nameJapanese = {0},
        .name = "CHINGLING ",
        .catchIndex = 0,
        .eggIndex = 42,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CHIMECHO
    },
    [SPECIES_STUNKY] = {
        .speciesIdRS = SPECIES_RS_STUNKY,
        .nameJapanese = {0},
        .name = "STUNKY    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SKUNTANK
    },
    [SPECIES_SKUNTANK] = {
        .speciesIdRS = SPECIES_RS_SKUNTANK,
        .nameJapanese = {0},
        .name = "SKUNTANK  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BRONZOR] = {
        .speciesIdRS = SPECIES_RS_BRONZOR,
        .nameJapanese = {0},
        .name = "BRONZOR   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_BRONZONG
    },
    [SPECIES_BRONZONG] = {
        .speciesIdRS = SPECIES_RS_BRONZONG,
        .nameJapanese = {0},
        .name = "BRONZONG  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_BONSLY] = {
        .speciesIdRS = SPECIES_RS_BONSLY,
        .nameJapanese = {0},
        .name = "BONSLY    ",
        .catchIndex = 0,
        .eggIndex = 40,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SUDOWOODO
    },
    [SPECIES_MIME_JR] = {
        .speciesIdRS = SPECIES_RS_MIME_JR,
        .nameJapanese = {0},
        .name = "MIME JR.  ",
        .catchIndex = 0,
        .eggIndex = 46,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MR_MIME
    },
    [SPECIES_HAPPINY] = {
        .speciesIdRS = SPECIES_RS_HAPPINY,
        .nameJapanese = {0},
        .name = "HAPPINY   ",
        .catchIndex = 0,
        .eggIndex = 43,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_CHANSEY
    },
    [SPECIES_CHATOT] = {
        .speciesIdRS = SPECIES_RS_CHATOT,
        .nameJapanese = {0},
        .name = "CHATOT    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SPIRITOMB] = {
        .speciesIdRS = SPECIES_RS_SPIRITOMB,
        .nameJapanese = {0},
        .name = "SPIRITOMB ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GIBLE] = {
        .speciesIdRS = SPECIES_RS_GIBLE,
        .nameJapanese = {0},
        .name = "GIBLE     ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GABITE
    },
    [SPECIES_GABITE] = {
        .speciesIdRS = SPECIES_RS_GABITE,
        .nameJapanese = {0},
        .name = "GABITE    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_GARCHOMP
    },
    [SPECIES_GARCHOMP] = {
        .speciesIdRS = SPECIES_RS_GARCHOMP,
        .nameJapanese = {0},
        .name = "GARCHOMP  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MUNCHLAX] = {
        .speciesIdRS = SPECIES_RS_MUNCHLAX,
        .nameJapanese = {0},
        .name = "MUNCHLAX  ",
        .catchIndex = 0,
        .eggIndex = 47,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_SNORLAX
    },
    [SPECIES_RIOLU] = {
        .speciesIdRS = SPECIES_RS_RIOLU,
        .nameJapanese = {0},
        .name = "RIOLU     ",
        .catchIndex = 0,
        .eggIndex = 48,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LUCARIO
    },
    [SPECIES_LUCARIO] = {
        .speciesIdRS = SPECIES_RS_LUCARIO,
        .nameJapanese = {0},
        .name = "LUCARIO   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_HIPPOPOTAS] = {
        .speciesIdRS = SPECIES_RS_HIPPOPOTAS,
        .nameJapanese = {0},
        .name = "HIPPOPOTAS",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_HIPPOWDON
    },
    [SPECIES_HIPPOWDON] = {
        .speciesIdRS = SPECIES_RS_HIPPOWDON,
        .nameJapanese = {0},
        .name = "HIPPOWDON ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SKORUPI] = {
        .speciesIdRS = SPECIES_RS_SKORUPI,
        .nameJapanese = {0},
        .name = "SKORUPI   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_DRAPION
    },
    [SPECIES_DRAPION] = {
        .speciesIdRS = SPECIES_RS_DRAPION,
        .nameJapanese = {0},
        .name = "DRAPION   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CROAGUNK] = {
        .speciesIdRS = SPECIES_RS_CROAGUNK,
        .nameJapanese = {0},
        .name = "CROAGUNK  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_TOXICROAK
    },
    [SPECIES_TOXICROAK] = {
        .speciesIdRS = SPECIES_RS_TOXICROAK,
        .nameJapanese = {0},
        .name = "TOXICROAK ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CARNIVINE] = {
        .speciesIdRS = SPECIES_RS_CARNIVINE,
        .nameJapanese = {0},
        .name = "CARNIVINE ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_FINNEON] = {
        .speciesIdRS = SPECIES_RS_FINNEON,
        .nameJapanese = {0},
        .name = "FINNEON   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_LUMINEON
    },
    [SPECIES_LUMINEON] = {
        .speciesIdRS = SPECIES_RS_LUMINEON,
        .nameJapanese = {0},
        .name = "LUMINEON  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MANTYKE] = {
        .speciesIdRS = SPECIES_RS_MANTYKE,
        .nameJapanese = {0},
        .name = "MANTYKE   ",
        .catchIndex = 0,
        .eggIndex = 45,
        .specialEggFlag = 1,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_MANTINE
    },
    [SPECIES_SNOVER] = {
        .speciesIdRS = SPECIES_RS_SNOVER,
        .nameJapanese = {0},
        .name = "SNOVER    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 1,
        .evolutionTarget = SPECIES_ABOMASNOW
    },
    [SPECIES_ABOMASNOW] = {
        .speciesIdRS = SPECIES_RS_ABOMASNOW,
        .nameJapanese = {0},
        .name = "ABOMASNOW ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_WEAVILE] = {
        .speciesIdRS = SPECIES_RS_WEAVILE,
        .nameJapanese = {0},
        .name = "WEAVILE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAGNEZONE] = {
        .speciesIdRS = SPECIES_RS_MAGNEZONE,
        .nameJapanese = {0},
        .name = "MAGNEZONE ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LICKILICKY] = {
        .speciesIdRS = SPECIES_RS_LICKILICKY,
        .nameJapanese = {0},
        .name = "LICKILICKY",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_RHYPERIOR] = {
        .speciesIdRS = SPECIES_RS_RHYPERIOR,
        .nameJapanese = {0},
        .name = "RHYPERIOR ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TANGROWTH] = {
        .speciesIdRS = SPECIES_RS_TANGROWTH,
        .nameJapanese = {0},
        .name = "TANGROWTH ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ELECTIVIRE] = {
        .speciesIdRS = SPECIES_RS_ELECTIVIRE,
        .nameJapanese = {0},
        .name = "ELECTIVIRE",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAGMORTAR] = {
        .speciesIdRS = SPECIES_RS_MAGMORTAR,
        .nameJapanese = {0},
        .name = "MAGMORTAR ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_TOGEKISS] = {
        .speciesIdRS = SPECIES_RS_TOGEKISS,
        .nameJapanese = {0},
        .name = "TOGEKISS  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_YANMEGA] = {
        .speciesIdRS = SPECIES_RS_YANMEGA,
        .nameJapanese = {0},
        .name = "YANMEGA   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_LEAFEON] = {
        .speciesIdRS = SPECIES_RS_LEAFEON,
        .nameJapanese = {0},
        .name = "LEAFEON   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GLACEON] = {
        .speciesIdRS = SPECIES_RS_GLACEON,
        .nameJapanese = {0},
        .name = "GLACEON   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GLISCOR] = {
        .speciesIdRS = SPECIES_RS_GLISCOR,
        .nameJapanese = {0},
        .name = "GLISCOR   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MAMOSWINE] = {
        .speciesIdRS = SPECIES_RS_MAMOSWINE,
        .nameJapanese = {0},
        .name = "MAMOSWINE ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PORYGON_Z] = {
        .speciesIdRS = SPECIES_RS_PORYGON_Z,
        .nameJapanese = {0},
        .name = "PORYGON-Z ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GALLADE] = {
        .speciesIdRS = SPECIES_RS_GALLADE,
        .nameJapanese = {0},
        .name = "GALLADE   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PROBOPASS] = {
        .speciesIdRS = SPECIES_RS_PROBOPASS,
        .nameJapanese = {0},
        .name = "PROBOPASS ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DUSKNOIR] = {
        .speciesIdRS = SPECIES_RS_DUSKNOIR,
        .nameJapanese = {0},
        .name = "DUSKNOIR  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_FROSLASS] = {
        .speciesIdRS = SPECIES_RS_FROSLASS,
        .nameJapanese = {0},
        .name = "FROSLASS  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ROTOM] = {
        .speciesIdRS = SPECIES_RS_ROTOM,
        .nameJapanese = {0},
        .name = "ROTOM     ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_UXIE] = {
        .speciesIdRS = SPECIES_RS_UXIE,
        .nameJapanese = {0},
        .name = "UXIE      ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MESPRIT] = {
        .speciesIdRS = SPECIES_RS_MESPRIT,
        .nameJapanese = {0},
        .name = "MESPRIT   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_AZELF] = {
        .speciesIdRS = SPECIES_RS_AZELF,
        .nameJapanese = {0},
        .name = "AZELF     ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DIALGA] = {
        .speciesIdRS = SPECIES_RS_DIALGA,
        .nameJapanese = {0},
        .name = "DIALGA    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PALKIA] = {
        .speciesIdRS = SPECIES_RS_PALKIA,
        .nameJapanese = {0},
        .name = "PALKIA    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_HEATRAN] = {
        .speciesIdRS = SPECIES_RS_HEATRAN,
        .nameJapanese = {0},
        .name = "HEATRAN   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_REGIGIGAS] = {
        .speciesIdRS = SPECIES_RS_REGIGIGAS,
        .nameJapanese = {0},
        .name = "REGIGIGAS ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_GIRATINA] = {
        .speciesIdRS = SPECIES_RS_GIRATINA,
        .nameJapanese = {0},
        .name = "GIRATINA  ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_CRESSELIA] = {
        .speciesIdRS = SPECIES_RS_CRESSELIA,
        .nameJapanese = {0},
        .name = "CRESSELIA ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_PHIONE] = {
        .speciesIdRS = SPECIES_RS_PHIONE,
        .nameJapanese = {0},
        .name = "PHIONE    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_MANAPHY] = {
        .speciesIdRS = SPECIES_RS_MANAPHY,
        .nameJapanese = {0},
        .name = "MANAPHY   ",
        .catchIndex = 0,
        .eggIndex = 44,
        .specialEggFlag = 1,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_DARKRAI] = {
        .speciesIdRS = SPECIES_RS_DARKRAI,
        .nameJapanese = {0},
        .name = "DARKRAI   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_SHAYMIN] = {
        .speciesIdRS = SPECIES_RS_SHAYMIN,
        .nameJapanese = {0},
        .name = "SHAYMIN   ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ARCEUS] = {
        .speciesIdRS = SPECIES_RS_ARCEUS,
        .nameJapanese = {0},
        .name = "ARCEUS    ",
        .catchIndex = 0,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_AXEW] = {
        .speciesIdRS = SPECIES_RS_AXEW,
        .nameJapanese = {0},
        .name = "AXEW      ",
        .catchIndex = 184,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_AMAURA] = {
        .speciesIdRS = SPECIES_RS_AMAURA,
        .nameJapanese = {0},
        .name = "AMAURA    ",
        .catchIndex = 185,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_ROWLET] = {
        .speciesIdRS = SPECIES_RS_ROWLET,
        .nameJapanese = {0},
        .name = "ROWLET    ",
        .catchIndex = 186,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_APPLIN] = {
        .speciesIdRS = SPECIES_RS_APPLIN,
        .nameJapanese = {0},
        .name = "APPLIN    ",
        .catchIndex = 187,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
    [SPECIES_FUECOCO] = {
        .speciesIdRS = SPECIES_RS_FUECOCO,
        .nameJapanese = {0},
        .name = "FUECOCO   ",
        .catchIndex = 188,
        .eggIndex = 0,
        .specialEggFlag = 0,
        .evolutionMethod = 0,
        .evolutionTarget = SPECIES_NONE
    },
};
