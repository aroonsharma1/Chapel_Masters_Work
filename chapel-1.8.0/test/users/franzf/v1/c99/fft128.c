/***************************************************************
This code was generated by  Spiral 5.0 beta, www.spiral.net --
Copyright (c) 2005, Carnegie Mellon University
All rights reserved.
The code is distributed under a BSD style license
(see http://www.opensource.org/licenses/bsd-license.php)

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

* Redistributions of source code must retain the above copyright
  notice, reference to Spiral, this list of conditions and the
  following disclaimer.
  * Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the following
  disclaimer in the documentation and/or other materials provided
  with the distribution.
  * Neither the name of Carnegie Mellon University nor the name of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*AS IS* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************/

/*	CPU: Intel Core2Duo at 2660 MHz, 2 cores, SSE3
  OS: Microsoft WindowsXP 32-bit
  SVN: 5262
  language: c.icl.opt
  timestamp: Oct 8, 2007; 9:20:19
  transform: DFT(128, 1)
  performance: 3692 cycles, 3227 Mflop/s
*/

#include "omega64c.h"
static _Complex double D3[56];
static _Complex double D4[56];

void init_fft128() {
  for(int i546 = 0; i546 <= 6; i546++) {
    for(int i561 = 0; i561 <= 3; i561++) {
      D3[((i546*8) + (i561*2))] = omega(128, ((i546 + 1)*i561));
      D3[((i546*8) + (i561*2) + 1)] = omega(128, ((i546 + 1)*(i561 + 4)));
    }
  }
  for(int i547 = 0; i547 <= 6; i547++) {
    for(int i571 = 0; i571 <= 3; i571++) {
      D4[((i547*8) + (i571*2))] = omega(128, ((9 + i547)*i571));
      D4[((i547*8) + (i571*2) + 1)] = omega(128, ((9 + i547)*(i571 + 4)));
    }
  }
}

void fft128(_Complex double  *Y, _Complex double  *X) {
  static _Complex double T162[128];
  _Complex double s268, t1110, s267, t1109, s266, t1108, a1047, 
    a1046, s265, t1107, a1045, a1044, t1106, t1105, a1043, 
    t1104, t1103, t1102, a1042, a1041, t1101, t1100, a1040, 
    a1039;
  a1039 = *(X);
  a1040 = *((X + 64));
  t1100 = (a1039 + a1040);
  t1101 = (a1039 - a1040);
  a1041 = *((X + 32));
  a1042 = *((X + 96));
  t1102 = (a1041 + a1042);
  t1103 = (t1100 + t1102);
  t1104 = (t1100 - t1102);
  a1043 = (__I__*(a1041 - a1042));
  t1105 = (t1101 + a1043);
  t1106 = (t1101 - a1043);
  a1044 = *((X + 16));
  a1045 = *((X + 80));
  t1107 = (a1044 + a1045);
  s265 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(a1044 - a1045));
  a1046 = *((X + 48));
  a1047 = *((X + 112));
  t1108 = (a1046 + a1047);
  s266 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(a1046 - a1047));
  t1109 = (t1107 + t1108);
  s267 = (__I__*(t1107 - t1108));
  t1110 = (s265 + s266);
  s268 = (__I__*(s265 - s266));
  *(T162) = (t1103 + t1109);
  *((T162 + 64)) = (t1103 - t1109);
  *((T162 + 16)) = (t1105 + t1110);
  *((T162 + 80)) = (t1105 - t1110);
  *((T162 + 32)) = (t1104 + s267);
  *((T162 + 96)) = (t1104 - s267);
  *((T162 + 48)) = (t1106 + s268);
  *((T162 + 112)) = (t1106 - s268);
  for(int i546 = 0; i546 <= 6; i546++) {
    _Complex double s320, t1169, s319, t1168, s318, t1167, s317, 
      s316, s315, t1166, s314, s313, t1165, t1164, a1125, 
      t1163, t1162, t1161, s312, s311, t1160, t1159, s310, 
      s309;
    _Complex double  *b87, *a1126, *b86;
    b86 = (X + i546);
    s309 = *((b86 + 1));
    s310 = *((b86 + 65));
    t1159 = (s309 + s310);
    t1160 = (s309 - s310);
    s311 = *((b86 + 33));
    s312 = *((b86 + 97));
    t1161 = (s311 + s312);
    t1162 = (t1159 + t1161);
    t1163 = (t1159 - t1161);
    a1125 = (__I__*(s311 - s312));
    t1164 = (t1160 + a1125);
    t1165 = (t1160 - a1125);
    s313 = *((b86 + 17));
    s314 = *((b86 + 81));
    t1166 = (s313 + s314);
    s315 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(s313 - s314));
    s316 = *((b86 + 49));
    s317 = *((b86 + 113));
    t1167 = (s316 + s317);
    s318 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(s316 - s317));
    t1168 = (t1166 + t1167);
    s319 = (__I__*(t1166 - t1167));
    t1169 = (s315 + s318);
    s320 = (__I__*(s315 - s318));
    a1126 = (D3 + (8*i546));
    b87 = (T162 + i546);
    *((b87 + 1)) = (*(a1126)*(t1162 + t1168));
    *((b87 + 65)) = (*((a1126 + 1))*(t1162 - t1168));
    *((b87 + 17)) = (*((a1126 + 2))*(t1164 + t1169));
    *((b87 + 81)) = (*((a1126 + 3))*(t1164 - t1169));
    *((b87 + 33)) = (*((a1126 + 4))*(t1163 + s319));
    *((b87 + 97)) = (*((a1126 + 5))*(t1163 - s319));
    *((b87 + 49)) = (*((a1126 + 6))*(t1165 + s320));
    *((b87 + 113)) = (*((a1126 + 7))*(t1165 - s320));
  }
  _Complex double s338, s337, a1224, s336, t1225, t1224, a1223, 
    a1222, t1223, t1222, a1221, a1220, s335, s334, a1219, 
    s333, t1221, t1220, a1218, a1217, t1219, t1218, a1216, 
    a1215;
  a1215 = *((X + 8));
  a1216 = *((X + 72));
  t1218 = (a1215 + a1216);
  t1219 = (a1215 - a1216);
  a1217 = *((X + 40));
  a1218 = *((X + 104));
  t1220 = (a1217 + a1218);
  t1221 = (t1218 + t1220);
  s333 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t1218 - t1220));
  a1219 = (__I__*(a1217 - a1218));
  s334 = ((0.92387953251128674 + __I__ * 0.38268343236508978)*(t1219 + a1219));
  s335 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t1219 - a1219));
  a1220 = *((X + 24));
  a1221 = *((X + 88));
  t1222 = (a1220 + a1221);
  t1223 = (a1220 - a1221);
  a1222 = *((X + 56));
  a1223 = *((X + 120));
  t1224 = (a1222 + a1223);
  t1225 = (t1222 + t1224);
  s336 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t1222 - t1224));
  a1224 = (__I__*(a1222 - a1223));
  s337 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t1223 + a1224));
  s338 = ((-0.92387953251128674 - __I__ * 0.38268343236508978)*(t1223 - a1224));
  *((T162 + 8)) = (t1221 + t1225);
  *((T162 + 72)) = ((__I__*t1221) + ((- __I__)*t1225));
  *((T162 + 24)) = (s334 + s337);
  *((T162 + 88)) = ((__I__*s334) + ((- __I__)*s337));
  *((T162 + 40)) = (s333 + s336);
  *((T162 + 104)) = ((__I__*s333) + ((- __I__)*s336));
  *((T162 + 56)) = (s335 + s338);
  *((T162 + 120)) = ((__I__*s335) + ((- __I__)*s338));
  for(int i547 = 0; i547 <= 6; i547++) {
    _Complex double s391, t1284, s390, t1283, s389, t1282, s388, 
      s387, s385, t1281, s384, s383, t1280, t1279, a1302, 
      t1278, t1277, t1276, s382, s381, t1275, t1274, s380, 
      s379;
    _Complex double  *b114, *a1303, *b113;
    b113 = (X + i547);
    s379 = *((b113 + 9));
    s380 = *((b113 + 73));
    t1274 = (s379 + s380);
    t1275 = (s379 - s380);
    s381 = *((b113 + 41));
    s382 = *((b113 + 105));
    t1276 = (s381 + s382);
    t1277 = (t1274 + t1276);
    t1278 = (t1274 - t1276);
    a1302 = (__I__*(s381 - s382));
    t1279 = (t1275 + a1302);
    t1280 = (t1275 - a1302);
    s383 = *((b113 + 25));
    s384 = *((b113 + 89));
    t1281 = (s383 + s384);
    s385 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(s383 - s384));
    s387 = *((b113 + 57));
    s388 = *((b113 + 121));
    t1282 = (s387 + s388);
    s389 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(s387 - s388));
    t1283 = (t1281 + t1282);
    s390 = (__I__*(t1281 - t1282));
    t1284 = (s385 + s389);
    s391 = (__I__*(s385 - s389));
    a1303 = (D4 + (8*i547));
    b114 = (T162 + i547);
    *((b114 + 9)) = (*(a1303)*(t1277 + t1283));
    *((b114 + 73)) = (*((a1303 + 1))*(t1277 - t1283));
    *((b114 + 25)) = (*((a1303 + 2))*(t1279 + t1284));
    *((b114 + 89)) = (*((a1303 + 3))*(t1279 - t1284));
    *((b114 + 41)) = (*((a1303 + 4))*(t1278 + s390));
    *((b114 + 105)) = (*((a1303 + 5))*(t1278 - s390));
    *((b114 + 57)) = (*((a1303 + 6))*(t1280 + s391));
    *((b114 + 121)) = (*((a1303 + 7))*(t1280 - s391));
  }
  for(int i548 = 0; i548 <= 7; i548++) {
    _Complex double a1426, t1443, t1442, t1441, a1425, t1440, t1439, 
      t1438, a1424, t1437, t1436, t1435, a1423, t1434, t1433, 
      t1432, s466, s465, a1421, s464, t1431, t1430, s463, 
      s462, t1429, t1428, s461, s460, s459, s458, a1420, 
      s457, t1427, t1426, s456, s455, t1425, t1424, s454, 
      s453, s452, s451, a1419, s450, t1423, t1422, s449, 
      s448, t1421, t1420, s447, s446, t1419, t1418, a1418, 
      t1417, t1416, t1415, s445, s444, t1414, t1413, s443, 
      s442;
    _Complex double  *a1422, *a1417;
    a1417 = (T162 + (16*i548));
    s442 = *(a1417);
    s443 = *((a1417 + 8));
    t1413 = (s442 + s443);
    t1414 = (s442 - s443);
    s444 = *((a1417 + 4));
    s445 = *((a1417 + 12));
    t1415 = (s444 + s445);
    t1416 = (t1413 + t1415);
    t1417 = (t1413 - t1415);
    a1418 = (__I__*(s444 - s445));
    t1418 = (t1414 + a1418);
    t1419 = (t1414 - a1418);
    s446 = *((a1417 + 1));
    s447 = *((a1417 + 9));
    t1420 = (s446 + s447);
    t1421 = (s446 - s447);
    s448 = *((a1417 + 5));
    s449 = *((a1417 + 13));
    t1422 = (s448 + s449);
    t1423 = (t1420 + t1422);
    s450 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t1420 - t1422));
    a1419 = (__I__*(s448 - s449));
    s451 = ((0.92387953251128674 + __I__ * 0.38268343236508978)*(t1421 + a1419));
    s452 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t1421 - a1419));
    s453 = *((a1417 + 2));
    s454 = *((a1417 + 10));
    t1424 = (s453 + s454);
    t1425 = (s453 - s454);
    s455 = *((a1417 + 6));
    s456 = *((a1417 + 14));
    t1426 = (s455 + s456);
    t1427 = (t1424 + t1426);
    s457 = (__I__*(t1424 - t1426));
    a1420 = (__I__*(s455 - s456));
    s458 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t1425 + a1420));
    s459 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t1425 - a1420));
    s460 = *((a1417 + 3));
    s461 = *((a1417 + 11));
    t1428 = (s460 + s461);
    t1429 = (s460 - s461);
    s462 = *((a1417 + 7));
    s463 = *((a1417 + 15));
    t1430 = (s462 + s463);
    t1431 = (t1428 + t1430);
    s464 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t1428 - t1430));
    a1421 = (__I__*(s462 - s463));
    s465 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t1429 + a1421));
    s466 = ((-0.92387953251128674 - __I__ * 0.38268343236508978)*(t1429 - a1421));
    t1432 = (t1416 + t1427);
    t1433 = (t1416 - t1427);
    t1434 = (t1423 + t1431);
    a1422 = (Y + i548);
    *(a1422) = (t1432 + t1434);
    *((a1422 + 64)) = (t1432 - t1434);
    a1423 = (__I__*(t1423 - t1431));
    *((a1422 + 32)) = (t1433 + a1423);
    *((a1422 + 96)) = (t1433 - a1423);
    t1435 = (t1418 + s458);
    t1436 = (t1418 - s458);
    t1437 = (s451 + s465);
    *((a1422 + 8)) = (t1435 + t1437);
    *((a1422 + 72)) = (t1435 - t1437);
    a1424 = (__I__*(s451 - s465));
    *((a1422 + 40)) = (t1436 + a1424);
    *((a1422 + 104)) = (t1436 - a1424);
    t1438 = (t1417 + s457);
    t1439 = (t1417 - s457);
    t1440 = (s450 + s464);
    *((a1422 + 16)) = (t1438 + t1440);
    *((a1422 + 80)) = (t1438 - t1440);
    a1425 = (__I__*(s450 - s464));
    *((a1422 + 48)) = (t1439 + a1425);
    *((a1422 + 112)) = (t1439 - a1425);
    t1441 = (t1419 + s459);
    t1442 = (t1419 - s459);
    t1443 = (s452 + s466);
    *((a1422 + 24)) = (t1441 + t1443);
    *((a1422 + 88)) = (t1441 - t1443);
    a1426 = (__I__*(s452 - s466));
    *((a1422 + 56)) = (t1442 + a1426);
    *((a1422 + 120)) = (t1442 - a1426);
  }
}