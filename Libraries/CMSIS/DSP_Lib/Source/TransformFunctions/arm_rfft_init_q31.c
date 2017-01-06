/* ----------------------------------------------------------------------   
* Copyright (C) 2010 ARM Limited. All rights reserved.   
*   
* $Date:        15. July 2011  
* $Revision: 	V1.0.10  
*   
* Project: 	    CMSIS DSP Library   
* Title:	    arm_rfft_init_q31.c   
*   
* Description:	RFFT & RIFFT Q31 initialisation function   
*   
* Target Processor: Cortex-M4/Cortex-M3/Cortex-M0
*  
* Version 1.0.10 2011/7/15 
*    Big Endian support added and Merged M0 and M3/M4 Source code.  
*   
* Version 1.0.3 2010/11/29  
*    Re-organized the CMSIS folders and updated documentation.   
*    
* Version 1.0.2 2010/11/11   
*    Documentation updated.    
*   
* Version 1.0.1 2010/10/05    
*    Production release and review comments incorporated.   
*   
* Version 1.0.0 2010/09/20    
*    Production release and review comments incorporated   
*   
* Version 0.0.7  2010/06/10    
*    Misra-C changes done   
* -------------------------------------------------------------------- */

#include "arm_math.h"

/**   
 * @ingroup groupTransforms   
 */

/**   
 * @addtogroup RFFT_RIFFT   
 * @{   
 */

/**   
* \par   
* Generation floating point realCoefAQ31 array:   
* \par   
* n = 1024   
* <pre>for (i = 0; i < n; i++)   
* {   
*    pATable[2 * i] = 0.5 * (1.0 - sin (2 * PI / (double) (2 * n) * (double) i));   
*    pATable[2 * i + 1] = 0.5 * (-1.0 * cos (2 * PI / (double) (2 * n) * (double) i));   
* }</pre>   
* \par   
* Convert to fixed point Q31 format   
*     round(pATable[i] * pow(2, 31))   
*/


const q31_t realCoefAQ31[1024] = {
  0x40000000, 0xc0000000, 0x3f9b783c, 0xc0004ef5,
  0x3f36f170, 0xc0013bd3, 0x3ed26c94, 0xc002c697,
  0x3e6deaa1, 0xc004ef3f, 0x3e096c8d, 0xc007b5c4,
  0x3da4f351, 0xc00b1a20, 0x3d407fe6, 0xc00f1c4a,
  0x3cdc1342, 0xc013bc39, 0x3c77ae5e, 0xc018f9e1,
  0x3c135231, 0xc01ed535, 0x3baeffb3, 0xc0254e27,
  0x3b4ab7db, 0xc02c64a6, 0x3ae67ba2, 0xc03418a2,
  0x3a824bfd, 0xc03c6a07, 0x3a1e29e5, 0xc04558c0,
  0x39ba1651, 0xc04ee4b8, 0x39561237, 0xc0590dd8,
  0x38f21e8e, 0xc063d405, 0x388e3c4d, 0xc06f3726,
  0x382a6c6a, 0xc07b371e, 0x37c6afdc, 0xc087d3d0,
  0x37630799, 0xc0950d1d, 0x36ff7496, 0xc0a2e2e3,
  0x369bf7c9, 0xc0b15502, 0x36389228, 0xc0c06355,
  0x35d544a7, 0xc0d00db6, 0x3572103d, 0xc0e05401,
  0x350ef5de, 0xc0f1360b, 0x34abf67e, 0xc102b3ac,
  0x34491311, 0xc114ccb9, 0x33e64c8c, 0xc1278104,
  0x3383a3e2, 0xc13ad060, 0x33211a07, 0xc14eba9d,
  0x32beafed, 0xc1633f8a, 0x325c6688, 0xc1785ef4,
  0x31fa3ecb, 0xc18e18a7, 0x319839a6, 0xc1a46c6e,
  0x3136580d, 0xc1bb5a11, 0x30d49af1, 0xc1d2e158,
  0x30730342, 0xc1eb0209, 0x301191f3, 0xc203bbe8,
  0x2fb047f2, 0xc21d0eb8, 0x2f4f2630, 0xc236fa3b,
  0x2eee2d9d, 0xc2517e31, 0x2e8d5f29, 0xc26c9a58,
  0x2e2cbbc1, 0xc2884e6e, 0x2dcc4454, 0xc2a49a2e,
  0x2d6bf9d1, 0xc2c17d52, 0x2d0bdd25, 0xc2def794,
  0x2cabef3d, 0xc2fd08a9, 0x2c4c3106, 0xc31bb049,
  0x2beca36c, 0xc33aee27, 0x2b8d475b, 0xc35ac1f7,
  0x2b2e1dbe, 0xc37b2b6a, 0x2acf277f, 0xc39c2a2f,
  0x2a70658a, 0xc3bdbdf6, 0x2a11d8c8, 0xc3dfe66c,
  0x29b38223, 0xc402a33c, 0x29556282, 0xc425f410,
  0x28f77acf, 0xc449d892, 0x2899cbf1, 0xc46e5069,
  0x283c56cf, 0xc4935b3c, 0x27df1c50, 0xc4b8f8ad,
  0x27821d59, 0xc4df2862, 0x27255ad1, 0xc505e9fb,
  0x26c8d59c, 0xc52d3d18, 0x266c8e9f, 0xc555215a,
  0x261086bc, 0xc57d965d, 0x25b4bed8, 0xc5a69bbe,
  0x255937d5, 0xc5d03118, 0x24fdf294, 0xc5fa5603,
  0x24a2eff6, 0xc6250a18, 0x244830dd, 0xc6504ced,
  0x23edb628, 0xc67c1e18, 0x239380b6, 0xc6a87d2d,
  0x23399167, 0xc6d569be, 0x22dfe917, 0xc702e35c,
  0x228688a4, 0xc730e997, 0x222d70eb, 0xc75f7bfe,
  0x21d4a2c8, 0xc78e9a1d, 0x217c1f15, 0xc7be4381,
  0x2123e6ad, 0xc7ee77b3, 0x20cbfa6a, 0xc81f363d,
  0x20745b24, 0xc8507ea7, 0x201d09b4, 0xc8825077,
  0x1fc606f1, 0xc8b4ab32, 0x1f6f53b3, 0xc8e78e5b,
  0x1f18f0ce, 0xc91af976, 0x1ec2df18, 0xc94eec03,
  0x1e6d1f65, 0xc9836582, 0x1e17b28a, 0xc9b86572,
  0x1dc29958, 0xc9edeb50, 0x1d6dd4a2, 0xca23f698,
  0x1d196538, 0xca5a86c4, 0x1cc54bec, 0xca919b4e,
  0x1c71898d, 0xcac933ae, 0x1c1e1ee9, 0xcb014f5b,
  0x1bcb0cce, 0xcb39edca, 0x1b785409, 0xcb730e70,
  0x1b25f566, 0xcbacb0bf, 0x1ad3f1b1, 0xcbe6d42b,
  0x1a8249b4, 0xcc217822, 0x1a30fe38, 0xcc5c9c14,
  0x19e01006, 0xcc983f70, 0x198f7fe6, 0xccd461a2,
  0x193f4e9e, 0xcd110216, 0x18ef7cf4, 0xcd4e2037,
  0x18a00bae, 0xcd8bbb6d, 0x1850fb8e, 0xcdc9d320,
  0x18024d59, 0xce0866b8, 0x17b401d1, 0xce47759a,
  0x176619b6, 0xce86ff2a, 0x171895c9, 0xcec702cb,
  0x16cb76c9, 0xcf077fe1, 0x167ebd74, 0xcf4875ca,
  0x16326a88, 0xcf89e3e8, 0x15e67ec1, 0xcfcbc999,
  0x159afadb, 0xd00e2639, 0x154fdf8f, 0xd050f926,
  0x15052d97, 0xd09441bb, 0x14bae5ab, 0xd0d7ff51,
  0x14710883, 0xd11c3142, 0x142796d5, 0xd160d6e5,
  0x13de9156, 0xd1a5ef90, 0x1395f8ba, 0xd1eb7a9a,
  0x134dcdb4, 0xd2317756, 0x130610f7, 0xd277e518,
  0x12bec333, 0xd2bec333, 0x1277e518, 0xd30610f7,
  0x12317756, 0xd34dcdb4, 0x11eb7a9a, 0xd395f8ba,
  0x11a5ef90, 0xd3de9156, 0x1160d6e5, 0xd42796d5,
  0x111c3142, 0xd4710883, 0x10d7ff51, 0xd4bae5ab,
  0x109441bb, 0xd5052d97, 0x1050f926, 0xd54fdf8f,
  0x100e2639, 0xd59afadb, 0xfcbc999, 0xd5e67ec1,
  0xf89e3e8, 0xd6326a88, 0xf4875ca, 0xd67ebd74,
  0xf077fe1, 0xd6cb76c9, 0xec702cb, 0xd71895c9,
  0xe86ff2a, 0xd76619b6, 0xe47759a, 0xd7b401d1,
  0xe0866b8, 0xd8024d59, 0xdc9d320, 0xd850fb8e,
  0xd8bbb6d, 0xd8a00bae, 0xd4e2037, 0xd8ef7cf4,
  0xd110216, 0xd93f4e9e, 0xcd461a2, 0xd98f7fe6,
  0xc983f70, 0xd9e01006, 0xc5c9c14, 0xda30fe38,
  0xc217822, 0xda8249b4, 0xbe6d42b, 0xdad3f1b1,
  0xbacb0bf, 0xdb25f566, 0xb730e70, 0xdb785409,
  0xb39edca, 0xdbcb0cce, 0xb014f5b, 0xdc1e1ee9,
  0xac933ae, 0xdc71898d, 0xa919b4e, 0xdcc54bec,
  0xa5a86c4, 0xdd196538, 0xa23f698, 0xdd6dd4a2,
  0x9edeb50, 0xddc29958, 0x9b86572, 0xde17b28a,
  0x9836582, 0xde6d1f65, 0x94eec03, 0xdec2df18,
  0x91af976, 0xdf18f0ce, 0x8e78e5b, 0xdf6f53b3,
  0x8b4ab32, 0xdfc606f1, 0x8825077, 0xe01d09b4,
  0x8507ea7, 0xe0745b24, 0x81f363d, 0xe0cbfa6a,
  0x7ee77b3, 0xe123e6ad, 0x7be4381, 0xe17c1f15,
  0x78e9a1d, 0xe1d4a2c8, 0x75f7bfe, 0xe22d70eb,
  0x730e997, 0xe28688a4, 0x702e35c, 0xe2dfe917,
  0x6d569be, 0xe3399167, 0x6a87d2d, 0xe39380b6,
  0x67c1e18, 0xe3edb628, 0x6504ced, 0xe44830dd,
  0x6250a18, 0xe4a2eff6, 0x5fa5603, 0xe4fdf294,
  0x5d03118, 0xe55937d5, 0x5a69bbe, 0xe5b4bed8,
  0x57d965d, 0xe61086bc, 0x555215a, 0xe66c8e9f,
  0x52d3d18, 0xe6c8d59c, 0x505e9fb, 0xe7255ad1,
  0x4df2862, 0xe7821d59, 0x4b8f8ad, 0xe7df1c50,
  0x4935b3c, 0xe83c56cf, 0x46e5069, 0xe899cbf1,
  0x449d892, 0xe8f77acf, 0x425f410, 0xe9556282,
  0x402a33c, 0xe9b38223, 0x3dfe66c, 0xea11d8c8,
  0x3bdbdf6, 0xea70658a, 0x39c2a2f, 0xeacf277f,
  0x37b2b6a, 0xeb2e1dbe, 0x35ac1f7, 0xeb8d475b,
  0x33aee27, 0xebeca36c, 0x31bb049, 0xec4c3106,
  0x2fd08a9, 0xecabef3d, 0x2def794, 0xed0bdd25,
  0x2c17d52, 0xed6bf9d1, 0x2a49a2e, 0xedcc4454,
  0x2884e6e, 0xee2cbbc1, 0x26c9a58, 0xee8d5f29,
  0x2517e31, 0xeeee2d9d, 0x236fa3b, 0xef4f2630,
  0x21d0eb8, 0xefb047f2, 0x203bbe8, 0xf01191f3,
  0x1eb0209, 0xf0730342, 0x1d2e158, 0xf0d49af1,
  0x1bb5a11, 0xf136580d, 0x1a46c6e, 0xf19839a6,
  0x18e18a7, 0xf1fa3ecb, 0x1785ef4, 0xf25c6688,
  0x1633f8a, 0xf2beafed, 0x14eba9d, 0xf3211a07,
  0x13ad060, 0xf383a3e2, 0x1278104, 0xf3e64c8c,
  0x114ccb9, 0xf4491311, 0x102b3ac, 0xf4abf67e,
  0xf1360b, 0xf50ef5de, 0xe05401, 0xf572103d,
  0xd00db6, 0xf5d544a7, 0xc06355, 0xf6389228,
  0xb15502, 0xf69bf7c9, 0xa2e2e3, 0xf6ff7496,
  0x950d1d, 0xf7630799, 0x87d3d0, 0xf7c6afdc,
  0x7b371e, 0xf82a6c6a, 0x6f3726, 0xf88e3c4d,
  0x63d405, 0xf8f21e8e, 0x590dd8, 0xf9561237,
  0x4ee4b8, 0xf9ba1651, 0x4558c0, 0xfa1e29e5,
  0x3c6a07, 0xfa824bfd, 0x3418a2, 0xfae67ba2,
  0x2c64a6, 0xfb4ab7db, 0x254e27, 0xfbaeffb3,
  0x1ed535, 0xfc135231, 0x18f9e1, 0xfc77ae5e,
  0x13bc39, 0xfcdc1342, 0xf1c4a, 0xfd407fe6,
  0xb1a20, 0xfda4f351, 0x7b5c4, 0xfe096c8d,
  0x4ef3f, 0xfe6deaa1, 0x2c697, 0xfed26c94,
  0x13bd3, 0xff36f170, 0x4ef5, 0xff9b783c,
  0x0, 0x0, 0x4ef5, 0x6487c4,
  0x13bd3, 0xc90e90, 0x2c697, 0x12d936c,
  0x4ef3f, 0x192155f, 0x7b5c4, 0x1f69373,
  0xb1a20, 0x25b0caf, 0xf1c4a, 0x2bf801a,
  0x13bc39, 0x323ecbe, 0x18f9e1, 0x38851a2,
  0x1ed535, 0x3ecadcf, 0x254e27, 0x451004d,
  0x2c64a6, 0x4b54825, 0x3418a2, 0x519845e,
  0x3c6a07, 0x57db403, 0x4558c0, 0x5e1d61b,
  0x4ee4b8, 0x645e9af, 0x590dd8, 0x6a9edc9,
  0x63d405, 0x70de172, 0x6f3726, 0x771c3b3,
  0x7b371e, 0x7d59396, 0x87d3d0, 0x8395024,
  0x950d1d, 0x89cf867, 0xa2e2e3, 0x9008b6a,
  0xb15502, 0x9640837, 0xc06355, 0x9c76dd8,
  0xd00db6, 0xa2abb59, 0xe05401, 0xa8defc3,
  0xf1360b, 0xaf10a22, 0x102b3ac, 0xb540982,
  0x114ccb9, 0xbb6ecef, 0x1278104, 0xc19b374,
  0x13ad060, 0xc7c5c1e, 0x14eba9d, 0xcdee5f9,
  0x1633f8a, 0xd415013, 0x1785ef4, 0xda39978,
  0x18e18a7, 0xe05c135, 0x1a46c6e, 0xe67c65a,
  0x1bb5a11, 0xec9a7f3, 0x1d2e158, 0xf2b650f,
  0x1eb0209, 0xf8cfcbe, 0x203bbe8, 0xfee6e0d,
  0x21d0eb8, 0x104fb80e, 0x236fa3b, 0x10b0d9d0,
  0x2517e31, 0x1111d263, 0x26c9a58, 0x1172a0d7,
  0x2884e6e, 0x11d3443f, 0x2a49a2e, 0x1233bbac,
  0x2c17d52, 0x1294062f, 0x2def794, 0x12f422db,
  0x2fd08a9, 0x135410c3, 0x31bb049, 0x13b3cefa,
  0x33aee27, 0x14135c94, 0x35ac1f7, 0x1472b8a5,
  0x37b2b6a, 0x14d1e242, 0x39c2a2f, 0x1530d881,
  0x3bdbdf6, 0x158f9a76, 0x3dfe66c, 0x15ee2738,
  0x402a33c, 0x164c7ddd, 0x425f410, 0x16aa9d7e,
  0x449d892, 0x17088531, 0x46e5069, 0x1766340f,
  0x4935b3c, 0x17c3a931, 0x4b8f8ad, 0x1820e3b0,
  0x4df2862, 0x187de2a7, 0x505e9fb, 0x18daa52f,
  0x52d3d18, 0x19372a64, 0x555215a, 0x19937161,
  0x57d965d, 0x19ef7944, 0x5a69bbe, 0x1a4b4128,
  0x5d03118, 0x1aa6c82b, 0x5fa5603, 0x1b020d6c,
  0x6250a18, 0x1b5d100a, 0x6504ced, 0x1bb7cf23,
  0x67c1e18, 0x1c1249d8, 0x6a87d2d, 0x1c6c7f4a,
  0x6d569be, 0x1cc66e99, 0x702e35c, 0x1d2016e9,
  0x730e997, 0x1d79775c, 0x75f7bfe, 0x1dd28f15,
  0x78e9a1d, 0x1e2b5d38, 0x7be4381, 0x1e83e0eb,
  0x7ee77b3, 0x1edc1953, 0x81f363d, 0x1f340596,
  0x8507ea7, 0x1f8ba4dc, 0x8825077, 0x1fe2f64c,
  0x8b4ab32, 0x2039f90f, 0x8e78e5b, 0x2090ac4d,
  0x91af976, 0x20e70f32, 0x94eec03, 0x213d20e8,
  0x9836582, 0x2192e09b, 0x9b86572, 0x21e84d76,
  0x9edeb50, 0x223d66a8, 0xa23f698, 0x22922b5e,
  0xa5a86c4, 0x22e69ac8, 0xa919b4e, 0x233ab414,
  0xac933ae, 0x238e7673, 0xb014f5b, 0x23e1e117,
  0xb39edca, 0x2434f332, 0xb730e70, 0x2487abf7,
  0xbacb0bf, 0x24da0a9a, 0xbe6d42b, 0x252c0e4f,
  0xc217822, 0x257db64c, 0xc5c9c14, 0x25cf01c8,
  0xc983f70, 0x261feffa, 0xcd461a2, 0x2670801a,
  0xd110216, 0x26c0b162, 0xd4e2037, 0x2710830c,
  0xd8bbb6d, 0x275ff452, 0xdc9d320, 0x27af0472,
  0xe0866b8, 0x27fdb2a7, 0xe47759a, 0x284bfe2f,
  0xe86ff2a, 0x2899e64a, 0xec702cb, 0x28e76a37,
  0xf077fe1, 0x29348937, 0xf4875ca, 0x2981428c,
  0xf89e3e8, 0x29cd9578, 0xfcbc999, 0x2a19813f,
  0x100e2639, 0x2a650525, 0x1050f926, 0x2ab02071,
  0x109441bb, 0x2afad269, 0x10d7ff51, 0x2b451a55,
  0x111c3142, 0x2b8ef77d, 0x1160d6e5, 0x2bd8692b,
  0x11a5ef90, 0x2c216eaa, 0x11eb7a9a, 0x2c6a0746,
  0x12317756, 0x2cb2324c, 0x1277e518, 0x2cf9ef09,
  0x12bec333, 0x2d413ccd, 0x130610f7, 0x2d881ae8,
  0x134dcdb4, 0x2dce88aa, 0x1395f8ba, 0x2e148566,
  0x13de9156, 0x2e5a1070, 0x142796d5, 0x2e9f291b,
  0x14710883, 0x2ee3cebe, 0x14bae5ab, 0x2f2800af,
  0x15052d97, 0x2f6bbe45, 0x154fdf8f, 0x2faf06da,
  0x159afadb, 0x2ff1d9c7, 0x15e67ec1, 0x30343667,
  0x16326a88, 0x30761c18, 0x167ebd74, 0x30b78a36,
  0x16cb76c9, 0x30f8801f, 0x171895c9, 0x3138fd35,
  0x176619b6, 0x317900d6, 0x17b401d1, 0x31b88a66,
  0x18024d59, 0x31f79948, 0x1850fb8e, 0x32362ce0,
  0x18a00bae, 0x32744493, 0x18ef7cf4, 0x32b1dfc9,
  0x193f4e9e, 0x32eefdea, 0x198f7fe6, 0x332b9e5e,
  0x19e01006, 0x3367c090, 0x1a30fe38, 0x33a363ec,
  0x1a8249b4, 0x33de87de, 0x1ad3f1b1, 0x34192bd5,
  0x1b25f566, 0x34534f41, 0x1b785409, 0x348cf190,
  0x1bcb0cce, 0x34c61236, 0x1c1e1ee9, 0x34feb0a5,
  0x1c71898d, 0x3536cc52, 0x1cc54bec, 0x356e64b2,
  0x1d196538, 0x35a5793c, 0x1d6dd4a2, 0x35dc0968,
  0x1dc29958, 0x361214b0, 0x1e17b28a, 0x36479a8e,
  0x1e6d1f65, 0x367c9a7e, 0x1ec2df18, 0x36b113fd,
  0x1f18f0ce, 0x36e5068a, 0x1f6f53b3, 0x371871a5,
  0x1fc606f1, 0x374b54ce, 0x201d09b4, 0x377daf89,
  0x20745b24, 0x37af8159, 0x20cbfa6a, 0x37e0c9c3,
  0x2123e6ad, 0x3811884d, 0x217c1f15, 0x3841bc7f,
  0x21d4a2c8, 0x387165e3, 0x222d70eb, 0x38a08402,
  0x228688a4, 0x38cf1669, 0x22dfe917, 0x38fd1ca4,
  0x23399167, 0x392a9642, 0x239380b6, 0x395782d3,
  0x23edb628, 0x3983e1e8, 0x244830dd, 0x39afb313,
  0x24a2eff6, 0x39daf5e8, 0x24fdf294, 0x3a05a9fd,
  0x255937d5, 0x3a2fcee8, 0x25b4bed8, 0x3a596442,
  0x261086bc, 0x3a8269a3, 0x266c8e9f, 0x3aaadea6,
  0x26c8d59c, 0x3ad2c2e8, 0x27255ad1, 0x3afa1605,
  0x27821d59, 0x3b20d79e, 0x27df1c50, 0x3b470753,
  0x283c56cf, 0x3b6ca4c4, 0x2899cbf1, 0x3b91af97,
  0x28f77acf, 0x3bb6276e, 0x29556282, 0x3bda0bf0,
  0x29b38223, 0x3bfd5cc4, 0x2a11d8c8, 0x3c201994,
  0x2a70658a, 0x3c42420a, 0x2acf277f, 0x3c63d5d1,
  0x2b2e1dbe, 0x3c84d496, 0x2b8d475b, 0x3ca53e09,
  0x2beca36c, 0x3cc511d9, 0x2c4c3106, 0x3ce44fb7,
  0x2cabef3d, 0x3d02f757, 0x2d0bdd25, 0x3d21086c,
  0x2d6bf9d1, 0x3d3e82ae, 0x2dcc4454, 0x3d5b65d2,
  0x2e2cbbc1, 0x3d77b192, 0x2e8d5f29, 0x3d9365a8,
  0x2eee2d9d, 0x3dae81cf, 0x2f4f2630, 0x3dc905c5,
  0x2fb047f2, 0x3de2f148, 0x301191f3, 0x3dfc4418,
  0x30730342, 0x3e14fdf7, 0x30d49af1, 0x3e2d1ea8,
  0x3136580d, 0x3e44a5ef, 0x319839a6, 0x3e5b9392,
  0x31fa3ecb, 0x3e71e759, 0x325c6688, 0x3e87a10c,
  0x32beafed, 0x3e9cc076, 0x33211a07, 0x3eb14563,
  0x3383a3e2, 0x3ec52fa0, 0x33e64c8c, 0x3ed87efc,
  0x34491311, 0x3eeb3347, 0x34abf67e, 0x3efd4c54,
  0x350ef5de, 0x3f0ec9f5, 0x3572103d, 0x3f1fabff,
  0x35d544a7, 0x3f2ff24a, 0x36389228, 0x3f3f9cab,
  0x369bf7c9, 0x3f4eaafe, 0x36ff7496, 0x3f5d1d1d,
  0x37630799, 0x3f6af2e3, 0x37c6afdc, 0x3f782c30,
  0x382a6c6a, 0x3f84c8e2, 0x388e3c4d, 0x3f90c8da,
  0x38f21e8e, 0x3f9c2bfb, 0x39561237, 0x3fa6f228,
  0x39ba1651, 0x3fb11b48, 0x3a1e29e5, 0x3fbaa740,
  0x3a824bfd, 0x3fc395f9, 0x3ae67ba2, 0x3fcbe75e,
  0x3b4ab7db, 0x3fd39b5a, 0x3baeffb3, 0x3fdab1d9,
  0x3c135231, 0x3fe12acb, 0x3c77ae5e, 0x3fe7061f,
  0x3cdc1342, 0x3fec43c7, 0x3d407fe6, 0x3ff0e3b6,
  0x3da4f351, 0x3ff4e5e0, 0x3e096c8d, 0x3ff84a3c,
  0x3e6deaa1, 0x3ffb10c1, 0x3ed26c94, 0x3ffd3969,
  0x3f36f170, 0x3ffec42d, 0x3f9b783c, 0x3fffb10b
};


/**   
* \par  
* Generation of realCoefBQ31 array:   
* \par   
*  n = 512   
* <pre>for (i = 0; i < n; i++)   
* {   
*    pBTable[2 * i] = 0.5 * (1.0 + sin (2 * PI / (double) (2 * n) * (double) i));   
*    pBTable[2 * i + 1] = 0.5 * (1.0 * cos (2 * PI / (double) (2 * n) * (double) i));   
* } </pre>   
* \par   
* Convert to fixed point Q31 format   
*     round(pBTable[i] * pow(2, 31))   
*   
*/

const q31_t realCoefBQ31[1024] = {
  0x40000000, 0x40000000, 0x406487c4, 0x3fffb10b,
  0x40c90e90, 0x3ffec42d, 0x412d936c, 0x3ffd3969,
  0x4192155f, 0x3ffb10c1, 0x41f69373, 0x3ff84a3c,
  0x425b0caf, 0x3ff4e5e0, 0x42bf801a, 0x3ff0e3b6,
  0x4323ecbe, 0x3fec43c7, 0x438851a2, 0x3fe7061f,
  0x43ecadcf, 0x3fe12acb, 0x4451004d, 0x3fdab1d9,
  0x44b54825, 0x3fd39b5a, 0x4519845e, 0x3fcbe75e,
  0x457db403, 0x3fc395f9, 0x45e1d61b, 0x3fbaa740,
  0x4645e9af, 0x3fb11b48, 0x46a9edc9, 0x3fa6f228,
  0x470de172, 0x3f9c2bfb, 0x4771c3b3, 0x3f90c8da,
  0x47d59396, 0x3f84c8e2, 0x48395024, 0x3f782c30,
  0x489cf867, 0x3f6af2e3, 0x49008b6a, 0x3f5d1d1d,
  0x49640837, 0x3f4eaafe, 0x49c76dd8, 0x3f3f9cab,
  0x4a2abb59, 0x3f2ff24a, 0x4a8defc3, 0x3f1fabff,
  0x4af10a22, 0x3f0ec9f5, 0x4b540982, 0x3efd4c54,
  0x4bb6ecef, 0x3eeb3347, 0x4c19b374, 0x3ed87efc,
  0x4c7c5c1e, 0x3ec52fa0, 0x4cdee5f9, 0x3eb14563,
  0x4d415013, 0x3e9cc076, 0x4da39978, 0x3e87a10c,
  0x4e05c135, 0x3e71e759, 0x4e67c65a, 0x3e5b9392,
  0x4ec9a7f3, 0x3e44a5ef, 0x4f2b650f, 0x3e2d1ea8,
  0x4f8cfcbe, 0x3e14fdf7, 0x4fee6e0d, 0x3dfc4418,
  0x504fb80e, 0x3de2f148, 0x50b0d9d0, 0x3dc905c5,
  0x5111d263, 0x3dae81cf, 0x5172a0d7, 0x3d9365a8,
  0x51d3443f, 0x3d77b192, 0x5233bbac, 0x3d5b65d2,
  0x5294062f, 0x3d3e82ae, 0x52f422db, 0x3d21086c,
  0x535410c3, 0x3d02f757, 0x53b3cefa, 0x3ce44fb7,
  0x54135c94, 0x3cc511d9, 0x5472b8a5, 0x3ca53e09,
  0x54d1e242, 0x3c84d496, 0x5530d881, 0x3c63d5d1,
  0x558f9a76, 0x3c42420a, 0x55ee2738, 0x3c201994,
  0x564c7ddd, 0x3bfd5cc4, 0x56aa9d7e, 0x3bda0bf0,
  0x57088531, 0x3bb6276e, 0x5766340f, 0x3b91af97,
  0x57c3a931, 0x3b6ca4c4, 0x5820e3b0, 0x3b470753,
  0x587de2a7, 0x3b20d79e, 0x58daa52f, 0x3afa1605,
  0x59372a64, 0x3ad2c2e8, 0x59937161, 0x3aaadea6,
  0x59ef7944, 0x3a8269a3, 0x5a4b4128, 0x3a596442,
  0x5aa6c82b, 0x3a2fcee8, 0x5b020d6c, 0x3a05a9fd,
  0x5b5d100a, 0x39daf5e8, 0x5bb7cf23, 0x39afb313,
  0x5c1249d8, 0x3983e1e8, 0x5c6c7f4a, 0x395782d3,
  0x5cc66e99, 0x392a9642, 0x5d2016e9, 0x38fd1ca4,
  0x5d79775c, 0x38cf1669, 0x5dd28f15, 0x38a08402,
  0x5e2b5d38, 0x387165e3, 0x5e83e0eb, 0x3841bc7f,
  0x5edc1953, 0x3811884d, 0x5f340596, 0x37e0c9c3,
  0x5f8ba4dc, 0x37af8159, 0x5fe2f64c, 0x377daf89,
  0x6039f90f, 0x374b54ce, 0x6090ac4d, 0x371871a5,
  0x60e70f32, 0x36e5068a, 0x613d20e8, 0x36b113fd,
  0x6192e09b, 0x367c9a7e, 0x61e84d76, 0x36479a8e,
  0x623d66a8, 0x361214b0, 0x62922b5e, 0x35dc0968,
  0x62e69ac8, 0x35a5793c, 0x633ab414, 0x356e64b2,
  0x638e7673, 0x3536cc52, 0x63e1e117, 0x34feb0a5,
  0x6434f332, 0x34c61236, 0x6487abf7, 0x348cf190,
  0x64da0a9a, 0x34534f41, 0x652c0e4f, 0x34192bd5,
  0x657db64c, 0x33de87de, 0x65cf01c8, 0x33a363ec,
  0x661feffa, 0x3367c090, 0x6670801a, 0x332b9e5e,
  0x66c0b162, 0x32eefdea, 0x6710830c, 0x32b1dfc9,
  0x675ff452, 0x32744493, 0x67af0472, 0x32362ce0,
  0x67fdb2a7, 0x31f79948, 0x684bfe2f, 0x31b88a66,
  0x6899e64a, 0x317900d6, 0x68e76a37, 0x3138fd35,
  0x69348937, 0x30f8801f, 0x6981428c, 0x30b78a36,
  0x69cd9578, 0x30761c18, 0x6a19813f, 0x30343667,
  0x6a650525, 0x2ff1d9c7, 0x6ab02071, 0x2faf06da,
  0x6afad269, 0x2f6bbe45, 0x6b451a55, 0x2f2800af,
  0x6b8ef77d, 0x2ee3cebe, 0x6bd8692b, 0x2e9f291b,
  0x6c216eaa, 0x2e5a1070, 0x6c6a0746, 0x2e148566,
  0x6cb2324c, 0x2dce88aa, 0x6cf9ef09, 0x2d881ae8,
  0x6d413ccd, 0x2d413ccd, 0x6d881ae8, 0x2cf9ef09,
  0x6dce88aa, 0x2cb2324c, 0x6e148566, 0x2c6a0746,
  0x6e5a1070, 0x2c216eaa, 0x6e9f291b, 0x2bd8692b,
  0x6ee3cebe, 0x2b8ef77d, 0x6f2800af, 0x2b451a55,
  0x6f6bbe45, 0x2afad269, 0x6faf06da, 0x2ab02071,
  0x6ff1d9c7, 0x2a650525, 0x70343667, 0x2a19813f,
  0x70761c18, 0x29cd9578, 0x70b78a36, 0x2981428c,
  0x70f8801f, 0x29348937, 0x7138fd35, 0x28e76a37,
  0x717900d6, 0x2899e64a, 0x71b88a66, 0x284bfe2f,
  0x71f79948, 0x27fdb2a7, 0x72362ce0, 0x27af0472,
  0x72744493, 0x275ff452, 0x72b1dfc9, 0x2710830c,
  0x72eefdea, 0x26c0b162, 0x732b9e5e, 0x2670801a,
  0x7367c090, 0x261feffa, 0x73a363ec, 0x25cf01c8,
  0x73de87de, 0x257db64c, 0x74192bd5, 0x252c0e4f,
  0x74534f41, 0x24da0a9a, 0x748cf190, 0x2487abf7,
  0x74c61236, 0x2434f332, 0x74feb0a5, 0x23e1e117,
  0x7536cc52, 0x238e7673, 0x756e64b2, 0x233ab414,
  0x75a5793c, 0x22e69ac8, 0x75dc0968, 0x22922b5e,
  0x761214b0, 0x223d66a8, 0x76479a8e, 0x21e84d76,
  0x767c9a7e, 0x2192e09b, 0x76b113fd, 0x213d20e8,
  0x76e5068a, 0x20e70f32, 0x771871a5, 0x2090ac4d,
  0x774b54ce, 0x2039f90f, 0x777daf89, 0x1fe2f64c,
  0x77af8159, 0x1f8ba4dc, 0x77e0c9c3, 0x1f340596,
  0x7811884d, 0x1edc1953, 0x7841bc7f, 0x1e83e0eb,
  0x787165e3, 0x1e2b5d38, 0x78a08402, 0x1dd28f15,
  0x78cf1669, 0x1d79775c, 0x78fd1ca4, 0x1d2016e9,
  0x792a9642, 0x1cc66e99, 0x795782d3, 0x1c6c7f4a,
  0x7983e1e8, 0x1c1249d8, 0x79afb313, 0x1bb7cf23,
  0x79daf5e8, 0x1b5d100a, 0x7a05a9fd, 0x1b020d6c,
  0x7a2fcee8, 0x1aa6c82b, 0x7a596442, 0x1a4b4128,
  0x7a8269a3, 0x19ef7944, 0x7aaadea6, 0x19937161,
  0x7ad2c2e8, 0x19372a64, 0x7afa1605, 0x18daa52f,
  0x7b20d79e, 0x187de2a7, 0x7b470753, 0x1820e3b0,
  0x7b6ca4c4, 0x17c3a931, 0x7b91af97, 0x1766340f,
  0x7bb6276e, 0x17088531, 0x7bda0bf0, 0x16aa9d7e,
  0x7bfd5cc4, 0x164c7ddd, 0x7c201994, 0x15ee2738,
  0x7c42420a, 0x158f9a76, 0x7c63d5d1, 0x1530d881,
  0x7c84d496, 0x14d1e242, 0x7ca53e09, 0x1472b8a5,
  0x7cc511d9, 0x14135c94, 0x7ce44fb7, 0x13b3cefa,
  0x7d02f757, 0x135410c3, 0x7d21086c, 0x12f422db,
  0x7d3e82ae, 0x1294062f, 0x7d5b65d2, 0x1233bbac,
  0x7d77b192, 0x11d3443f, 0x7d9365a8, 0x1172a0d7,
  0x7dae81cf, 0x1111d263, 0x7dc905c5, 0x10b0d9d0,
  0x7de2f148, 0x104fb80e, 0x7dfc4418, 0xfee6e0d,
  0x7e14fdf7, 0xf8cfcbe, 0x7e2d1ea8, 0xf2b650f,
  0x7e44a5ef, 0xec9a7f3, 0x7e5b9392, 0xe67c65a,
  0x7e71e759, 0xe05c135, 0x7e87a10c, 0xda39978,
  0x7e9cc076, 0xd415013, 0x7eb14563, 0xcdee5f9,
  0x7ec52fa0, 0xc7c5c1e, 0x7ed87efc, 0xc19b374,
  0x7eeb3347, 0xbb6ecef, 0x7efd4c54, 0xb540982,
  0x7f0ec9f5, 0xaf10a22, 0x7f1fabff, 0xa8defc3,
  0x7f2ff24a, 0xa2abb59, 0x7f3f9cab, 0x9c76dd8,
  0x7f4eaafe, 0x9640837, 0x7f5d1d1d, 0x9008b6a,
  0x7f6af2e3, 0x89cf867, 0x7f782c30, 0x8395024,
  0x7f84c8e2, 0x7d59396, 0x7f90c8da, 0x771c3b3,
  0x7f9c2bfb, 0x70de172, 0x7fa6f228, 0x6a9edc9,
  0x7fb11b48, 0x645e9af, 0x7fbaa740, 0x5e1d61b,
  0x7fc395f9, 0x57db403, 0x7fcbe75e, 0x519845e,
  0x7fd39b5a, 0x4b54825, 0x7fdab1d9, 0x451004d,
  0x7fe12acb, 0x3ecadcf, 0x7fe7061f, 0x38851a2,
  0x7fec43c7, 0x323ecbe, 0x7ff0e3b6, 0x2bf801a,
  0x7ff4e5e0, 0x25b0caf, 0x7ff84a3c, 0x1f69373,
  0x7ffb10c1, 0x192155f, 0x7ffd3969, 0x12d936c,
  0x7ffec42d, 0xc90e90, 0x7fffb10b, 0x6487c4,
  0x7fffffff, 0x0, 0x7fffb10b, 0xff9b783c,
  0x7ffec42d, 0xff36f170, 0x7ffd3969, 0xfed26c94,
  0x7ffb10c1, 0xfe6deaa1, 0x7ff84a3c, 0xfe096c8d,
  0x7ff4e5e0, 0xfda4f351, 0x7ff0e3b6, 0xfd407fe6,
  0x7fec43c7, 0xfcdc1342, 0x7fe7061f, 0xfc77ae5e,
  0x7fe12acb, 0xfc135231, 0x7fdab1d9, 0xfbaeffb3,
  0x7fd39b5a, 0xfb4ab7db, 0x7fcbe75e, 0xfae67ba2,
  0x7fc395f9, 0xfa824bfd, 0x7fbaa740, 0xfa1e29e5,
  0x7fb11b48, 0xf9ba1651, 0x7fa6f228, 0xf9561237,
  0x7f9c2bfb, 0xf8f21e8e, 0x7f90c8da, 0xf88e3c4d,
  0x7f84c8e2, 0xf82a6c6a, 0x7f782c30, 0xf7c6afdc,
  0x7f6af2e3, 0xf7630799, 0x7f5d1d1d, 0xf6ff7496,
  0x7f4eaafe, 0xf69bf7c9, 0x7f3f9cab, 0xf6389228,
  0x7f2ff24a, 0xf5d544a7, 0x7f1fabff, 0xf572103d,
  0x7f0ec9f5, 0xf50ef5de, 0x7efd4c54, 0xf4abf67e,
  0x7eeb3347, 0xf4491311, 0x7ed87efc, 0xf3e64c8c,
  0x7ec52fa0, 0xf383a3e2, 0x7eb14563, 0xf3211a07,
  0x7e9cc076, 0xf2beafed, 0x7e87a10c, 0xf25c6688,
  0x7e71e759, 0xf1fa3ecb, 0x7e5b9392, 0xf19839a6,
  0x7e44a5ef, 0xf136580d, 0x7e2d1ea8, 0xf0d49af1,
  0x7e14fdf7, 0xf0730342, 0x7dfc4418, 0xf01191f3,
  0x7de2f148, 0xefb047f2, 0x7dc905c5, 0xef4f2630,
  0x7dae81cf, 0xeeee2d9d, 0x7d9365a8, 0xee8d5f29,
  0x7d77b192, 0xee2cbbc1, 0x7d5b65d2, 0xedcc4454,
  0x7d3e82ae, 0xed6bf9d1, 0x7d21086c, 0xed0bdd25,
  0x7d02f757, 0xecabef3d, 0x7ce44fb7, 0xec4c3106,
  0x7cc511d9, 0xebeca36c, 0x7ca53e09, 0xeb8d475b,
  0x7c84d496, 0xeb2e1dbe, 0x7c63d5d1, 0xeacf277f,
  0x7c42420a, 0xea70658a, 0x7c201994, 0xea11d8c8,
  0x7bfd5cc4, 0xe9b38223, 0x7bda0bf0, 0xe9556282,
  0x7bb6276e, 0xe8f77acf, 0x7b91af97, 0xe899cbf1,
  0x7b6ca4c4, 0xe83c56cf, 0x7b470753, 0xe7df1c50,
  0x7b20d79e, 0xe7821d59, 0x7afa1605, 0xe7255ad1,
  0x7ad2c2e8, 0xe6c8d59c, 0x7aaadea6, 0xe66c8e9f,
  0x7a8269a3, 0xe61086bc, 0x7a596442, 0xe5b4bed8,
  0x7a2fcee8, 0xe55937d5, 0x7a05a9fd, 0xe4fdf294,
  0x79daf5e8, 0xe4a2eff6, 0x79afb313, 0xe44830dd,
  0x7983e1e8, 0xe3edb628, 0x795782d3, 0xe39380b6,
  0x792a9642, 0xe3399167, 0x78fd1ca4, 0xe2dfe917,
  0x78cf1669, 0xe28688a4, 0x78a08402, 0xe22d70eb,
  0x787165e3, 0xe1d4a2c8, 0x7841bc7f, 0xe17c1f15,
  0x7811884d, 0xe123e6ad, 0x77e0c9c3, 0xe0cbfa6a,
  0x77af8159, 0xe0745b24, 0x777daf89, 0xe01d09b4,
  0x774b54ce, 0xdfc606f1, 0x771871a5, 0xdf6f53b3,
  0x76e5068a, 0xdf18f0ce, 0x76b113fd, 0xdec2df18,
  0x767c9a7e, 0xde6d1f65, 0x76479a8e, 0xde17b28a,
  0x761214b0, 0xddc29958, 0x75dc0968, 0xdd6dd4a2,
  0x75a5793c, 0xdd196538, 0x756e64b2, 0xdcc54bec,
  0x7536cc52, 0xdc71898d, 0x74feb0a5, 0xdc1e1ee9,
  0x74c61236, 0xdbcb0cce, 0x748cf190, 0xdb785409,
  0x74534f41, 0xdb25f566, 0x74192bd5, 0xdad3f1b1,
  0x73de87de, 0xda8249b4, 0x73a363ec, 0xda30fe38,
  0x7367c090, 0xd9e01006, 0x732b9e5e, 0xd98f7fe6,
  0x72eefdea, 0xd93f4e9e, 0x72b1dfc9, 0xd8ef7cf4,
  0x72744493, 0xd8a00bae, 0x72362ce0, 0xd850fb8e,
  0x71f79948, 0xd8024d59, 0x71b88a66, 0xd7b401d1,
  0x717900d6, 0xd76619b6, 0x7138fd35, 0xd71895c9,
  0x70f8801f, 0xd6cb76c9, 0x70b78a36, 0xd67ebd74,
  0x70761c18, 0xd6326a88, 0x70343667, 0xd5e67ec1,
  0x6ff1d9c7, 0xd59afadb, 0x6faf06da, 0xd54fdf8f,
  0x6f6bbe45, 0xd5052d97, 0x6f2800af, 0xd4bae5ab,
  0x6ee3cebe, 0xd4710883, 0x6e9f291b, 0xd42796d5,
  0x6e5a1070, 0xd3de9156, 0x6e148566, 0xd395f8ba,
  0x6dce88aa, 0xd34dcdb4, 0x6d881ae8, 0xd30610f7,
  0x6d413ccd, 0xd2bec333, 0x6cf9ef09, 0xd277e518,
  0x6cb2324c, 0xd2317756, 0x6c6a0746, 0xd1eb7a9a,
  0x6c216eaa, 0xd1a5ef90, 0x6bd8692b, 0xd160d6e5,
  0x6b8ef77d, 0xd11c3142, 0x6b451a55, 0xd0d7ff51,
  0x6afad269, 0xd09441bb, 0x6ab02071, 0xd050f926,
  0x6a650525, 0xd00e2639, 0x6a19813f, 0xcfcbc999,
  0x69cd9578, 0xcf89e3e8, 0x6981428c, 0xcf4875ca,
  0x69348937, 0xcf077fe1, 0x68e76a37, 0xcec702cb,
  0x6899e64a, 0xce86ff2a, 0x684bfe2f, 0xce47759a,
  0x67fdb2a7, 0xce0866b8, 0x67af0472, 0xcdc9d320,
  0x675ff452, 0xcd8bbb6d, 0x6710830c, 0xcd4e2037,
  0x66c0b162, 0xcd110216, 0x6670801a, 0xccd461a2,
  0x661feffa, 0xcc983f70, 0x65cf01c8, 0xcc5c9c14,
  0x657db64c, 0xcc217822, 0x652c0e4f, 0xcbe6d42b,
  0x64da0a9a, 0xcbacb0bf, 0x6487abf7, 0xcb730e70,
  0x6434f332, 0xcb39edca, 0x63e1e117, 0xcb014f5b,
  0x638e7673, 0xcac933ae, 0x633ab414, 0xca919b4e,
  0x62e69ac8, 0xca5a86c4, 0x62922b5e, 0xca23f698,
  0x623d66a8, 0xc9edeb50, 0x61e84d76, 0xc9b86572,
  0x6192e09b, 0xc9836582, 0x613d20e8, 0xc94eec03,
  0x60e70f32, 0xc91af976, 0x6090ac4d, 0xc8e78e5b,
  0x6039f90f, 0xc8b4ab32, 0x5fe2f64c, 0xc8825077,
  0x5f8ba4dc, 0xc8507ea7, 0x5f340596, 0xc81f363d,
  0x5edc1953, 0xc7ee77b3, 0x5e83e0eb, 0xc7be4381,
  0x5e2b5d38, 0xc78e9a1d, 0x5dd28f15, 0xc75f7bfe,
  0x5d79775c, 0xc730e997, 0x5d2016e9, 0xc702e35c,
  0x5cc66e99, 0xc6d569be, 0x5c6c7f4a, 0xc6a87d2d,
  0x5c1249d8, 0xc67c1e18, 0x5bb7cf23, 0xc6504ced,
  0x5b5d100a, 0xc6250a18, 0x5b020d6c, 0xc5fa5603,
  0x5aa6c82b, 0xc5d03118, 0x5a4b4128, 0xc5a69bbe,
  0x59ef7944, 0xc57d965d, 0x59937161, 0xc555215a,
  0x59372a64, 0xc52d3d18, 0x58daa52f, 0xc505e9fb,
  0x587de2a7, 0xc4df2862, 0x5820e3b0, 0xc4b8f8ad,
  0x57c3a931, 0xc4935b3c, 0x5766340f, 0xc46e5069,
  0x57088531, 0xc449d892, 0x56aa9d7e, 0xc425f410,
  0x564c7ddd, 0xc402a33c, 0x55ee2738, 0xc3dfe66c,
  0x558f9a76, 0xc3bdbdf6, 0x5530d881, 0xc39c2a2f,
  0x54d1e242, 0xc37b2b6a, 0x5472b8a5, 0xc35ac1f7,
  0x54135c94, 0xc33aee27, 0x53b3cefa, 0xc31bb049,
  0x535410c3, 0xc2fd08a9, 0x52f422db, 0xc2def794,
  0x5294062f, 0xc2c17d52, 0x5233bbac, 0xc2a49a2e,
  0x51d3443f, 0xc2884e6e, 0x5172a0d7, 0xc26c9a58,
  0x5111d263, 0xc2517e31, 0x50b0d9d0, 0xc236fa3b,
  0x504fb80e, 0xc21d0eb8, 0x4fee6e0d, 0xc203bbe8,
  0x4f8cfcbe, 0xc1eb0209, 0x4f2b650f, 0xc1d2e158,
  0x4ec9a7f3, 0xc1bb5a11, 0x4e67c65a, 0xc1a46c6e,
  0x4e05c135, 0xc18e18a7, 0x4da39978, 0xc1785ef4,
  0x4d415013, 0xc1633f8a, 0x4cdee5f9, 0xc14eba9d,
  0x4c7c5c1e, 0xc13ad060, 0x4c19b374, 0xc1278104,
  0x4bb6ecef, 0xc114ccb9, 0x4b540982, 0xc102b3ac,
  0x4af10a22, 0xc0f1360b, 0x4a8defc3, 0xc0e05401,
  0x4a2abb59, 0xc0d00db6, 0x49c76dd8, 0xc0c06355,
  0x49640837, 0xc0b15502, 0x49008b6a, 0xc0a2e2e3,
  0x489cf867, 0xc0950d1d, 0x48395024, 0xc087d3d0,
  0x47d59396, 0xc07b371e, 0x4771c3b3, 0xc06f3726,
  0x470de172, 0xc063d405, 0x46a9edc9, 0xc0590dd8,
  0x4645e9af, 0xc04ee4b8, 0x45e1d61b, 0xc04558c0,
  0x457db403, 0xc03c6a07, 0x4519845e, 0xc03418a2,
  0x44b54825, 0xc02c64a6, 0x4451004d, 0xc0254e27,
  0x43ecadcf, 0xc01ed535, 0x438851a2, 0xc018f9e1,
  0x4323ecbe, 0xc013bc39, 0x42bf801a, 0xc00f1c4a,
  0x425b0caf, 0xc00b1a20, 0x41f69373, 0xc007b5c4,
  0x4192155f, 0xc004ef3f, 0x412d936c, 0xc002c697,
  0x40c90e90, 0xc0013bd3, 0x406487c4, 0xc0004ef5
};

/**   
* @brief  Initialization function for the Q31 RFFT/RIFFT.  
* @param[in, out] *S             points to an instance of the Q31 RFFT/RIFFT structure.  
* @param[in, out] *S_CFFT        points to an instance of the Q31 CFFT/CIFFT structure.  
* @param[in]      fftLenReal     length of the FFT.  
* @param[in]      ifftFlagR      flag that selects forward (ifftFlagR=0) or inverse (ifftFlagR=1) transform.  
* @param[in]      bitReverseFlag flag that enables (bitReverseFlag=1) or disables (bitReverseFlag=0) bit reversal of output.  
* @return		The function returns ARM_MATH_SUCCESS if initialization is successful or ARM_MATH_ARGUMENT_ERROR if <code>fftLenReal</code> is not a supported value.  
*   
* \par Description:  
* \par  
* The parameter <code>fftLenReal</code>	Specifies length of RFFT/RIFFT Process. Supported FFT Lengths are 128, 512, 2048.   
* \par   
* The parameter <code>ifftFlagR</code> controls whether a forward or inverse transform is computed.   
* Set(=1) ifftFlagR to calculate RIFFT, otherwise RFFT is calculated.   
* \par   
* The parameter <code>bitReverseFlag</code> controls whether output is in normal order or bit reversed order.   
* Set(=1) bitReverseFlag for output to be in normal order otherwise output is in bit reversed order.  
* \par   
* This function also initializes Twiddle factor table.   
*/

arm_status arm_rfft_init_q31(
  arm_rfft_instance_q31 * S,
  arm_cfft_radix4_instance_q31 * S_CFFT,
  uint32_t fftLenReal,
  uint32_t ifftFlagR,
  uint32_t bitReverseFlag)
{
  /*  Initialise the default arm status */
  arm_status status = ARM_MATH_SUCCESS;

  /*  Initialize the Real FFT length */
  S->fftLenReal = (uint16_t) fftLenReal;

  /*  Initialize the Complex FFT length */
  S->fftLenBy2 = (uint16_t) fftLenReal / 2u;

  /*  Initialize the Twiddle coefficientA pointer */
  S->pTwiddleAReal = (q31_t *) realCoefAQ31;

  /*  Initialize the Twiddle coefficientB pointer */
  S->pTwiddleBReal = (q31_t *) realCoefBQ31;

  /*  Initialize the Flag for selection of RFFT or RIFFT */
  S->ifftFlagR = (uint8_t) ifftFlagR;

  /*  Initialize the Flag for calculation Bit reversal or not */
  S->bitReverseFlagR = (uint8_t) bitReverseFlag;

  /*  Initialization of coef modifier depending on the FFT length */
  switch (S->fftLenReal)
  {
  case 512u:
    S->twidCoefRModifier = 2u;
    break;
  case 128u:
    S->twidCoefRModifier = 8u;
    break;
  default:
    /*  Reporting argument error if rfftSize is not valid value */
    status = ARM_MATH_ARGUMENT_ERROR;
    break;
  }

  /* Init Complex FFT Instance */
  S->pCfft = S_CFFT;

  if(S->ifftFlagR)
  {
    /* Initializes the CIFFT Module for fftLenreal/2 length */
    arm_cfft_radix4_init_q31(S->pCfft, (uint16_t) S->fftLenBy2, 1u, 1u);
  }
  else
  {
    /* Initializes the CFFT Module for fftLenreal/2 length */
    arm_cfft_radix4_init_q31(S->pCfft, (uint16_t) S->fftLenBy2, 0u, 1u);
  }

  /* return the status of RFFT Init function */
  return (status);

}

  /**   
   * @} end of RFFT_RIFFT group   
   */
