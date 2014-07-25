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
  timestamp: Oct 8, 2007; 9:20:6
  transform: DFT(16, 1)
  performance: 226 cycles, 3766 Mflop/s
*/

#include "omega64c.h"

void init_fft16() {
}

void fft16(_Complex double  *Y, _Complex double  *X) {
  _Complex double a289, a290, t243, t244, a291, a292, t245, 
    t246, t247, a293, t248, t249, a294, a295, t250, 
    t251, a296, a297, t252, t253, s31, a298, s32, 
    s33, a299, a300, t254, t255, a301, a302, t256, 
    t257, s34, a303, s35, s36, a304, a305, t258, 
    t259, a306, a307, t260, t261, s37, a308, s38, 
    s39, t262, t263, t264, a309, t265, t266, t267, 
    a310, t268, t269, t270, a311, t271, t272, t273, 
    a312;
  a289 = *(X);
  a290 = *((X + 8));
  t243 = (a289 + a290);
  t244 = (a289 - a290);
  a291 = *((X + 4));
  a292 = *((X + 12));
  t245 = (a291 + a292);
  t246 = (t243 + t245);
  t247 = (t243 - t245);
  a293 = (__I__*(a291 - a292));
  t248 = (t244 + a293);
  t249 = (t244 - a293);
  a294 = *((X + 1));
  a295 = *((X + 9));
  t250 = (a294 + a295);
  t251 = (a294 - a295);
  a296 = *((X + 5));
  a297 = *((X + 13));
  t252 = (a296 + a297);
  t253 = (t250 + t252);
  s31 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t250 - t252));
  a298 = (__I__*(a296 - a297));
  s32 = ((0.92387953251128674 + __I__ * 0.38268343236508978)*(t251 + a298));
  s33 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t251 - a298));
  a299 = *((X + 2));
  a300 = *((X + 10));
  t254 = (a299 + a300);
  t255 = (a299 - a300);
  a301 = *((X + 6));
  a302 = *((X + 14));
  t256 = (a301 + a302);
  t257 = (t254 + t256);
  s34 = (__I__*(t254 - t256));
  a303 = (__I__*(a301 - a302));
  s35 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t255 + a303));
  s36 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t255 - a303));
  a304 = *((X + 3));
  a305 = *((X + 11));
  t258 = (a304 + a305);
  t259 = (a304 - a305);
  a306 = *((X + 7));
  a307 = *((X + 15));
  t260 = (a306 + a307);
  t261 = (t258 + t260);
  s37 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t258 - t260));
  a308 = (__I__*(a306 - a307));
  s38 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t259 + a308));
  s39 = ((-0.92387953251128674 - __I__ * 0.38268343236508978)*(t259 - a308));
  t262 = (t246 + t257);
  t263 = (t246 - t257);
  t264 = (t253 + t261);
  *(Y) = (t262 + t264);
  *((Y + 8)) = (t262 - t264);
  a309 = (__I__*(t253 - t261));
  *((Y + 4)) = (t263 + a309);
  *((Y + 12)) = (t263 - a309);
  t265 = (t248 + s35);
  t266 = (t248 - s35);
  t267 = (s32 + s38);
  *((Y + 1)) = (t265 + t267);
  *((Y + 9)) = (t265 - t267);
  a310 = (__I__*(s32 - s38));
  *((Y + 5)) = (t266 + a310);
  *((Y + 13)) = (t266 - a310);
  t268 = (t247 + s34);
  t269 = (t247 - s34);
  t270 = (s31 + s37);
  *((Y + 2)) = (t268 + t270);
  *((Y + 10)) = (t268 - t270);
  a311 = (__I__*(s31 - s37));
  *((Y + 6)) = (t269 + a311);
  *((Y + 14)) = (t269 - a311);
  t271 = (t249 + s36);
  t272 = (t249 - s36);
  t273 = (s33 + s39);
  *((Y + 3)) = (t271 + t273);
  *((Y + 11)) = (t271 - t273);
  a312 = (__I__*(s33 - s39));
  *((Y + 7)) = (t272 + a312);
  *((Y + 15)) = (t272 - a312);
}