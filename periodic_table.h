#pragma once
// Usage: in one implementation file add this directive before including this header file
// #define PERIODIC_TABLE_IMPLEMENTATION

#ifdef __cplusplus
extern "C" {
#endif

static const double cKelvinToCelcius = 273.15;
static const double cCelciusToKelvin = -273.15;
inline double kelvin_to_celcius(const double K) { return K + cKelvinToCelcius; }
inline double celcius_to_kelvin(const double C) { return C + cCelciusToKelvin; }

static const double cUnknownTemperature = -1000.0; // TODO: fix a better solution than this

// TODO:
//    add block
//    add electrons per shell
//    add atomic radius
//    add covalent radius
//    densities can vary in different forms, and some densities are unknown but have predicted values
//    ionization energy have several different values (up to 30) revisit the values...
//    add isotopes to separate table?
//    remove special? I don't know what it is
typedef struct PeriodicElement
{
    int         number;
    int         group;
    int         period;
    double      atomic_weight;          // amu (g / mol)
    double      density;                // g / cm3
    double      melting_point;          // Celcius
    double      boiling_point;          // Celcius
    double      ionization_energy;      // eV
    double      earth_abundance;        // %
    const char* block;                  // s-, f-, d- or p-block
    const char* name;
    const char* symbol;
    const char* electron_configuration;
    const char* special;
} PeriodicElement;

#ifndef PERIODIC_TABLE_IMPLEMENTATION
extern PeriodicElement periodic_table[];
#else
PeriodicElement periodic_table[] =
{
    //num, group, period,   weigth, density,       melting point,   boiling point,        ion,  abund, block,            name,symbol, electron config,           special
    {   1,     1,      1,    1.008,    0.09,                -259,                -253,  13.60,   0.14,   "s", "Hydrogen"     ,  "H" ,  "1s1"                   ,  ""  },
    {   2,    18,      1,    4.003,    0.18,                -272,                -269,  24.59,      0,   "s", "Helium"       ,  "He",  "1s2"                   ,  ""  },
    {   3,     1,      2,    6.941,    0.53,                 180,                1347,   5.39,      0,   "s", "Lithium"      ,  "Li",  "[He] 2s1"              ,  ""  },
    {   4,     2,      2,    9.012,    1.85,                1278,                2970,   9.32,      0,   "s", "Beryllium"    ,  "Be",  "[He] 2s2"              ,  ""  },
    {   5,    13,      2,   10.811,    2.34,                2300,                2550,   8.30,      0,   "p", "Boron"        ,  "B" ,  "[He] 2s2 2p1"          ,  ""  },
    {   6,    14,      2,   12.011,    2.26,                3500,                4827,  11.26,   0.09,   "p", "Carbon"       ,  "C" ,  "[He] 2s2 2p2"          ,  ""  },
    {   7,    15,      2,   14.007,    1.25,                -210,                -196,  14.53,      0,   "p", "Nitrogen"     ,  "N" ,  "[He] 2s2 2p3"          ,  ""  },
    {   8,    16,      2,   15.999,    1.43,                -218,                -183,  13.62,  46.71,   "p", "Oxygen"       ,  "O" ,  "[He] 2s2 2p4"          ,  ""  },
    {   9,    17,      2,   18.998,    1.70,                -220,                -188,  17.42,   0.03,   "p", "Fluorine"     ,  "F" ,  "[He] 2s2 2p5"          ,  ""  },
    {  10,    18,      2,   20.180,    0.90,                -249,                -246,  21.56,      0,   "p", "Neon"         ,  "Ne",  "[He] 2s2 2p6"          ,  ""  },
    {  11,     1,      3,   22.990,    0.97,                  98,                 883,   5.14,   2.75,   "s", "Sodium"       ,  "Na",  "[Ne] 3s1"              ,  ""  },
    {  12,     2,      3,   24.305,    1.74,                 639,                1090,   7.65,   2.08,   "s", "Magnesium"    ,  "Mg",  "[Ne] 3s2"              ,  ""  },
    {  13,    13,      3,   26.982,    2.70,                 660,                2467,   5.99,   8.07,   "p", "Aluminum"     ,  "Al",  "[Ne] 3s2 3p1"          ,  ""  },
    {  14,    14,      3,   28.086,    2.33,                1410,                2355,   8.15,  27.69,   "p", "Silicon"      ,  "Si",  "[Ne] 3s2 3p2"          ,  ""  },
    {  15,    15,      3,   30.974,    1.82,                  44,                 280,  10.49,   0.13,   "p", "Phosphorus"   ,  "P" ,  "[Ne] 3s2 3p3"          ,  ""  },
    {  16,    16,      3,   32.065,    2.07,                 113,                 445,  10.36,   0.05,   "p", "Sulfur"       ,  "S" ,  "[Ne] 3s2 3p4"          ,  ""  },
    {  17,    17,      3,   35.453,    3.21,                -101,                 -35,  12.97,   0.05,   "p", "Chlorine"     ,  "Cl",  "[Ne] 3s2 3p5"          ,  ""  },
    {  18,    18,      3,   39.948,    1.78,                -189,                -186,  15.76,      0,   "p", "Argon"        ,  "Ar",  "[Ne] 3s2 3p6"          ,  ""  },
    {  19,     1,      4,   39.098,    0.86,                  64,                 774,   4.34,   2.58,   "s", "Potassium"    ,  "K" ,  "[Ar] 4s1"              ,  ""  },
    {  20,     2,      4,   40.078,    1.55,                 839,                1484,   6.11,   3.65,   "s", "Calcium"      ,  "Ca",  "[Ar] 4s2"              ,  ""  },
    {  21,     3,      4,   44.956,    2.99,                1539,                2832,   6.56,      0,   "d", "Scandium"     ,  "Sc",  "[Ar] 3d1 4s2"          ,  ""  },
    {  22,     4,      4,   47.867,    4.54,                1660,                3287,   6.83,   0.62,   "d", "Titanium"     ,  "Ti",  "[Ar] 3d2 4s2"          ,  ""  },
    {  23,     5,      4,   50.942,    6.11,                1890,                3380,   6.75,      0,   "d", "Vanadium"     ,  "V" ,  "[Ar] 3d3 4s2"          ,  ""  },
    {  24,     6,      4,   51.996,    7.19,                1857,                2672,   6.77,   0.04,   "d", "Chromium"     ,  "Cr",  "[Ar] 3d5 4s1"          ,  ""  },
    {  25,     7,      4,   54.938,    7.43,                1245,                1962,   7.43,   0.09,   "d", "Manganese"    ,  "Mn",  "[Ar] 3d5 4s2"          ,  ""  },
    {  26,     8,      4,   55.845,    7.87,                1535,                2750,   7.90,   5.05,   "d", "Iron"         ,  "Fe",  "[Ar] 3d6 4s2"          ,  ""  },
    {  27,     9,      4,   58.933,    8.90,                1495,                2870,   7.88,      0,   "d", "Cobalt"       ,  "Co",  "[Ar] 3d7 4s2"          ,  ""  },
    {  28,    10,      4,   58.693,    8.90,                1453,                2732,   7.64,   0.02,   "d", "Nickel"       ,  "Ni",  "[Ar] 3d8 4s2"          ,  ""  },
    {  29,    11,      4,   63.546,    8.96,                1083,                2567,   7.73,      0,   "d", "Copper"       ,  "Cu",  "[Ar] 3d10 4s1"         ,  ""  },
    {  30,    12,      4,   65.390,    7.13,                 420,                 907,   9.39,      0,   "d", "Zinc"         ,  "Zn",  "[Ar] 3d10 4s2"         ,  ""  },
    {  31,    13,      4,   69.723,    5.91,                  30,                2403,   6.00,      0,   "p", "Gallium"      ,  "Ga",  "[Ar] 3d10 4s2 4p1"     ,  ""  },
    {  32,    14,      4,   72.640,    5.32,                 937,                2830,   7.90,      0,   "p", "Germanium"    ,  "Ge",  "[Ar] 3d10 4s2 4p2"     ,  ""  },
    {  33,    15,      4,   74.922,    5.72,                  81,                 613,   9.79,      0,   "p", "Arsenic"      ,  "As",  "[Ar] 3d10 4s2 4p3"     ,  ""  },
    {  34,    16,      4,   78.960,    4.79,                 217,                 685,   9.75,      0,   "p", "Selenium"     ,  "Se",  "[Ar] 3d10 4s2 4p4"     ,  ""  },
    {  35,    17,      4,   79.904,    3.12,                  -7,                  59,  11.81,      0,   "p", "Bromine"      ,  "Br",  "[Ar] 3d10 4s2 4p5"     ,  ""  },
    {  36,    18,      4,   83.800,    3.75,                -157,                -153,  14.00,      0,   "p", "Krypton"      ,  "Kr",  "[Ar] 3d10 4s2 4p6"     ,  ""  },
    {  37,     1,      5,   85.468,    1.63,                  39,                 688,   4.18,      0,   "s", "Rubidium"     ,  "Rb",  "[Kr] 5s1"              ,  ""  },
    {  38,     2,      5,   87.620,    2.54,                 769,                1384,   5.69,      0,   "s", "Strontium"    ,  "Sr",  "[Kr] 5s2"              ,  ""  },
    {  39,     3,      5,   88.906,    4.47,                1523,                3337,   6.22,      0,   "d", "Yttrium"      ,  "Y" ,  "[Kr] 4d1 5s2"          ,  ""  },
    //num, group, period,   weigth, density,       melting point,   boiling point,        ion,  abund, block,            name,symbol, electron config,           special
    {  40,     4,      5,   91.224,    6.51,                1852,                4377,   6.63,   0.03,   "d", "Zirconium"    ,  "Zr",  "[Kr] 4d2 5s2"          ,  ""  },
    {  41,     5,      5,   92.906,    8.57,                2468,                4927,   6.76,      0,   "d", "Niobium"      ,  "Nb",  "[Kr] 4d4 5s1"          ,  ""  },
    {  42,     6,      5,   95.940,   10.22,                2617,                4612,   7.09,      0,   "d", "Molybdenum"   ,  "Mo",  "[Kr] 4d5 5s1"          ,  ""  },
    {  43,     7,      5,   98.000,   11.50,                2200,                4877,   7.28,      0,   "d", "Technetium"   ,  "Tc",  "[Kr] 4d5 5s2"          ,  "*" },
    {  44,     8,      5,  101.070,   12.37,                2250,                3900,   7.36,      0,   "d", "Ruthenium"    ,  "Ru",  "[Kr] 4d7 5s1"          ,  ""  },
    {  45,     9,      5,  102.906,   12.41,                1966,                3727,   7.46,      0,   "d", "Rhodium"      ,  "Rh",  "[Kr] 4d8 5s1"          ,  ""  },
    {  46,    10,      5,  106.420,   12.02,                1552,                2927,   8.34,      0,   "d", "Palladium"    ,  "Pd",  "[Kr] 4d10"             ,  ""  },
    {  47,    11,      5,  107.868,   10.50,                 962,                2212,   7.58,      0,   "d", "Silver"       ,  "Ag",  "[Kr] 4d10 5s1"         ,  ""  },
    {  48,    12,      5,  112.411,    8.65,                 321,                 765,   8.99,      0,   "d", "Cadmium"      ,  "Cd",  "[Kr] 4d10 5s2"         ,  ""  },
    {  49,    13,      5,  114.818,    7.31,                 157,                2000,   5.79,      0,   "p", "Indium"       ,  "In",  "[Kr] 4d10 5s2 5p1"     ,  ""  },
    {  50,    14,      5,  118.710,    7.31,                 232,                2270,   7.34,      0,   "p", "Tin"          ,  "Sn",  "[Kr] 4d10 5s2 5p2"     ,  ""  },
    {  51,    15,      5,  121.760,    6.68,                 630,                1750,   8.61,      0,   "p", "Antimony"     ,  "Sb",  "[Kr] 4d10 5s2 5p3"     ,  ""  },
    {  52,    16,      5,  127.600,    6.24,                 449,                 990,   9.01,      0,   "p", "Tellurium"    ,  "Te",  "[Kr] 4d10 5s2 5p4"     ,  ""  },
    {  53,    17,      5,  126.905,    4.93,                 114,                 184,  10.45,      0,   "p", "Iodine"       ,  "I" ,  "[Kr] 4d10 5s2 5p5"     ,  ""  },
    {  54,    18,      5,  131.293,    5.90,                -112,                -108,  12.13,      0,   "p", "Xenon"        ,  "Xe",  "[Kr] 4d10 5s2 5p6"     ,  ""  },
    {  55,     1,      6,  132.906,    1.87,                  29,                 678,   3.89,      0,   "s", "Cesium"       ,  "Cs",  "[Xe] 6s1"              ,  ""  },
    {  56,     2,      6,  137.327,    3.59,                 725,                1140,   5.21,   0.05,   "s", "Barium"       ,  "Ba",  "[Xe] 6s2"              ,  ""  },
    {  57,   101,      6,  138.906,    6.15,                 920,                3469,   5.58,      0,   "f", "Lanthanum"    ,  "La",  "[Xe] 5d1 6s2"          ,  ""  },
    {  58,   101,      6,  140.116,    6.77,                 795,                3257,   5.54,      0,   "f", "Cerium"       ,  "Ce",  "[Xe] 4f1 5d1 6s2"      ,  ""  },
    {  59,   101,      6,  140.908,    6.77,                 935,                3127,   5.47,      0,   "f", "Praseodymium" ,  "Pr",  "[Xe] 4f3 6s2"          ,  ""  },
    {  60,   101,      6,  144.240,    7.01,                1010,                3127,   5.53,      0,   "f", "Neodymium"    ,  "Nd",  "[Xe] 4f4 6s2"          ,  ""  },
    {  61,   101,      6,  145.000,    7.30,                1100,                3000,   5.58,      0,   "f", "Promethium"   ,  "Pm",  "[Xe] 4f5 6s2"          ,  "*" },
    {  62,   101,      6,  150.360,    7.52,                1072,                1900,   5.64,      0,   "f", "Samarium"     ,  "Sm",  "[Xe] 4f6 6s2"          ,  ""  },
    {  63,   101,      6,  151.964,    5.24,                 822,                1597,   5.67,      0,   "f", "Europium"     ,  "Eu",  "[Xe] 4f7 6s2"          ,  ""  },
    {  64,   101,      6,  157.250,    7.90,                1311,                3233,   6.15,      0,   "f", "Gadolinium"   ,  "Gd",  "[Xe] 4f7 5d1 6s2"      ,  ""  },
    {  65,   101,      6,  158.925,    8.23,                1360,                3041,   5.86,      0,   "f", "Terbium"      ,  "Tb",  "[Xe] 4f9 6s2"          ,  ""  },
    {  66,   101,      6,  162.500,    8.55,                1412,                2562,   5.94,      0,   "f", "Dysprosium"   ,  "Dy",  "[Xe] 4f10 6s2"         ,  ""  },
    {  67,   101,      6,  164.930,    8.80,                1470,                2720,   6.02,      0,   "f", "Holmium"      ,  "Ho",  "[Xe] 4f11 6s2"         ,  ""  },
    {  68,   101,      6,  167.259,    9.07,                1522,                2510,   6.11,      0,   "f", "Erbium"       ,  "Er",  "[Xe] 4f12 6s2"         ,  ""  },
    {  69,   101,      6,  168.934,    9.32,                1545,                1727,   6.18,      0,   "f", "Thulium"      ,  "Tm",  "[Xe] 4f13 6s2"         ,  ""  },
    {  70,   101,      6,  173.040,    6.90,                 824,                1466,   6.25,      0,   "f", "Ytterbium"    ,  "Yb",  "[Xe] 4f14 6s2"         ,  ""  },
    {  71,     3,      6,  174.967,    9.84,                1656,                3315,   5.43,      0,   "d", "Lutetium"     ,  "Lu",  "[Xe] 4f14 5d1 6s2"     ,  ""  },
    {  72,     4,      6,  178.490,   13.31,                2150,                5400,   6.83,      0,   "d", "Hafnium"      ,  "Hf",  "[Xe] 4f14 5d2 6s2"     ,  ""  },
    {  73,     5,      6,  180.948,   16.65,                2996,                5425,   7.55,      0,   "d", "Tantalum"     ,  "Ta",  "[Xe] 4f14 5d3 6s2"     ,  ""  },
    {  74,     6,      6,  183.840,   19.35,                3410,                5660,   7.86,      0,   "d", "Tungsten"     ,  "W" ,  "[Xe] 4f14 5d4 6s2"     ,  ""  },
    {  75,     7,      6,  186.207,   21.04,                3180,                5627,   7.83,      0,   "d", "Rhenium"      ,  "Re",  "[Xe] 4f14 5d5 6s2"     ,  ""  },
    {  76,     8,      6,  190.230,   22.60,                3045,                5027,   8.44,      0,   "d", "Osmium"       ,  "Os",  "[Xe] 4f14 5d6 6s2"     ,  ""  },
    {  77,     9,      6,  192.217,   22.40,                2410,                4527,   8.97,      0,   "d", "Iridium"      ,  "Ir",  "[Xe] 4f14 5d7 6s2"     ,  ""  },
    {  78,    10,      6,  195.078,   21.45,                1772,                3827,   8.96,      0,   "d", "Platinum"     ,  "Pt",  "[Xe] 4f14 5d9 6s1"     ,  ""  },
    {  79,    11,      6,  196.967,   19.32,                1064,                2807,   9.23,      0,   "d", "Gold"         ,  "Au",  "[Xe] 4f14 5d10 6s1"    ,  ""  },
    //num, group, period,   weigth, density,       melting point,   boiling point,        ion,  abund, block,            name,symbol, electron config,           special
    {  80,    12,      6,  200.590,   13.55,                 -39,                 357,  10.44,      0,   "d", "Mercury"      ,  "Hg",  "[Xe] 4f14 5d10 6s2"    ,  ""  },
    {  81,    13,      6,  204.383,   11.85,                 303,                1457,   6.11,      0,   "p", "Thallium"     ,  "Tl",  "[Xe] 4f14 5d10 6s2 6p1",  ""  },
    {  82,    14,      6,  207.200,   11.35,                 327,                1740,   7.42,      0,   "p", "Lead"         ,  "Pb",  "[Xe] 4f14 5d10 6s2 6p2",  ""  },
    {  83,    15,      6,  208.980,    9.75,                 271,                1560,   7.29,      0,   "p", "Bismuth"      ,  "Bi",  "[Xe] 4f14 5d10 6s2 6p3",  ""  },
    {  84,    16,      6,  209.000,    9.30,                 254,                 962,   8.42,      0,   "p", "Polonium"     ,  "Po",  "[Xe] 4f14 5d10 6s2 6p4",  "*" },
    {  85,    17,      6,  210.000,    0.00,                 302,                 337,   9.30,      0,   "p", "Astatine"     ,  "At",  "[Xe] 4f14 5d10 6s2 6p5",  "*" },
    {  86,    18,      6,  222.000,    9.73,                 -71,                 -62,  10.75,      0,   "p", "Radon"        ,  "Rn",  "[Xe] 4f14 5d10 6s2 6p6",  "*" },
    {  87,     1,      7,  223.000,    0.00,                  27,                 677,   4.07,      0,   "s", "Francium"     ,  "Fr",  "[Rn] 7s1"              ,  "*" },
    {  88,     2,      7,  226.000,    5.50,                 700,                1737,   5.28,      0,   "s", "Radium"       ,  "Ra",  "[Rn] 7s2"              ,  "*" },
    {  89,   102,      7,  227.000,   10.07,                1050,                3200,   5.17,      0,   "f", "Actinium"     ,  "Ac",  "[Rn] 6d1 7s2"          ,  "*" },
    {  90,   102,      7,  232.038,   11.72,                1750,                4790,   6.31,      0,   "f", "Thorium"      ,  "Th",  "[Rn] 6d2 7s2"          ,  ""  },
    {  91,   102,      7,  231.036,   15.40,                1568,                4027,   5.89,      0,   "f", "Protactinium" ,  "Pa",  "[Rn] 5f2 6d1 7s2"      ,  ""  },
    {  92,   102,      7,  238.029,   18.95,                1132,                3818,   6.19,      0,   "f", "Uranium"      ,  "U" ,  "[Rn] 5f3 6d1 7s2"      ,  ""  },
    {  93,   102,      7,  237.000,   20.20,                 640,                3902,   6.27,      0,   "f", "Neptunium"    ,  "Np",  "[Rn] 5f4 6d1 7s2"      ,  "*" },
    {  94,   102,      7,  244.000,   19.84,                 640,                3235,   6.03,      0,   "f", "Plutonium"    ,  "Pu",  "[Rn] 5f6 7s2"          ,  "*" },
    {  95,   102,      7,  243.000,   13.67,                 994,                2607,   5.97,      0,   "f", "Americium"    ,  "Am",  "[Rn] 5f7 7s2"          ,  "*" },
    {  96,   102,      7,  247.000,   13.50,                1340,                3110,   5.99,      0,   "f", "Curium"       ,  "Cm",  ""                      ,  "*" },
    {  97,   102,      7,  247.000,   14.78,                 986,                2627,   6.20,      0,   "f", "Berkelium"    ,  "Bk",  ""                      ,  "*" },
    {  98,   102,      7,  251.000,   15.10,                 900,                1470,   6.28,      0,   "f", "Californium"  ,  "Cf",  ""                      ,  "*" },
    {  99,   102,      7,  252.000,    0.00,                 860,                 996,   6.42,      0,   "f", "Einsteinium"  ,  "Es",  ""                      ,  "*" },
    { 100,   102,      7,  257.000,    0.00,                1527, cUnknownTemperature,   6.50,      0,   "f", "Fermium"      ,  "Fm",  ""                      ,  "*" },
    { 101,   102,      7,  258.000,    0.00,              826.85, cUnknownTemperature,   6.58,      0,   "f", "Mendelevium"  ,  "Md",  ""                      ,  "*" },
    { 102,   102,      7,  259.000,    0.00,                 827, cUnknownTemperature,   6.65,      0,   "f", "Nobelium"     ,  "No",  ""                      ,  "*" },
    { 103,     3,      7,  262.000,    0.00,                1627, cUnknownTemperature,   4.90,      0,   "d", "Lawrencium"   ,  "Lr",  ""                      ,  "*" },
    { 104,     4,      7,  261.000,   17.00,                2100,                5500,   0.00,      0,   "d", "Rutherfordium",  "Rf",  ""                      ,  "*" },
    { 105,     5,      7,  262.000,   21.60, cUnknownTemperature, cUnknownTemperature,   0.00,      0,   "d", "Dubnium"      ,  "Db",  ""                      ,  "*" },
    { 106,     6,      7,  266.000,   23.50, cUnknownTemperature, cUnknownTemperature,   0.00,      0,   "d", "Seaborgium"   ,  "Sg",  ""                      ,  "*" },
    { 107,     7,      7,  264.000,   26.50, cUnknownTemperature, cUnknownTemperature,   0.00,      0,   "d", "Bohrium"      ,  "Bh",  ""                      ,  "*" },
    { 108,     8,      7,  277.000,   28.00, cUnknownTemperature, cUnknownTemperature,   0.00,      0,   "d", "Hassium"      ,  "Hs",  ""                      ,  "*" },
    { 109,     9,      7,  268.000,   27.50, cUnknownTemperature, cUnknownTemperature,   0.00,      0,   "d", "Meitnerium"   ,  "Mt",  ""                      ,  "*" },
    //num, group, period,   weigth, density,       melting point,   boiling point,        ion,  abund, block,            name,symbol, electron config,           special
    { 110,    10,      7,  281.000,   26.50, cUnknownTemperature, cUnknownTemperature,   0.00,      0,   "d", "Darnstadtium" ,  "Ds",  "[Rn] 5f14 6d8 7s2"     ,  ""  },
    { 111,    11,      7,  282.000,   23.00, cUnknownTemperature, cUnknownTemperature,   0.00,      0,   "d", "Roentgenium"  ,  "Rg",  "[Rn] 5f14 6d9 7s2"     ,  ""  },
    { 112,    12,      7,  285.000,   14.00,                9.85,               66.85,   0.00,      0,   "d", "Copernicium"  ,  "Cn",  "[Rn] 5f14 6d10 7s2"    ,  ""  },
    { 113,    13,      7,  286.000,   16.00,              426.85,             1156.85,   0.00,      0,   "p", "Nihonium"     ,  "Nh",  "[Rn] 5f14 6d10 7s2 7p1",  ""  },
    { 114,    14,      7,  289.000,   9.928,              -73.15,              106.85,   0.00,      0,   "p", "Flerovium"    ,  "Fl",  "[Rn] 5f14 6d10 7s2 7p2",  ""  },
    { 115,    15,      7,  290.000,    13.5,              396.85,             1126.85,   0.00,      0,   "p", "Moscovium"    ,  "Mc",  "[Rn] 5f14 6d10 7s2 7p3",  ""  },
    { 116,    16,      7,  293.000,    12.9,              435.35,              811.85,   0.00,      0,   "p", "Livermorium"  ,  "Lv",  "[Rn] 5f14 6d10 7s2 7p4",  ""  },
    { 117,    17,      7,  294.000,     7.2,              449.85,              568.85,   0.00,      0,   "p", "Tennessine"   ,  "Ts",  "[Rn] 5f14 6d10 7s2 7p5",  ""  },
    { 118,    18,      7,  294.000,     7.0,               51.85,              176.85,   0.00,      0,   "p", "Organesson"   ,  "Og",  "[Rn] 5f14 6d10 7s2 7p6",  ""  }
};
#endif

#ifdef __cplusplus
} // extern "C"
#endif
