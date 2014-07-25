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
	SVN: 5591 (modified)
	language: c.icl.opt
	timestamp: Dec 6, 2007; 13:43:52
	transform: DFT(64, 1)
	source file: "fft_64.c(.c)"
	performance: 1772 cycles, 2882 Mflop/s

algorithm: DFT_GT_CT( DFT(64, 1),
  GT_NthLoop( GT(DFT(16, 1), XChain([ 0, 1 ]), XChain([ 0, 1 ]), [ 4 ]),
    GT_Base( GT(DFT(16, 1), XChain([ 0 ]), XChain([ 0 ]), [  ]),
      DFT_CT( "T", DFT(16, 1),
        DFT_GT_CT( DFT(4, 1),
          GT_NthLoop( GT(DFT(2, 1), XChain([ 0, 1 ]), XChain([ 0, 1 ]), [ 2 ]),
            GT_Base( GT(DFT(2, 1), XChain([ 0 ]), XChain([ 0 ]), [  ]),
              DFT_Base( DFT(2, 1) ) ),
            Info_Base( InfoNt(1) ) ),
          GT_NthLoop( GT(DFT(2, 1), XChain([ 0, 1 ]), XChain([ 1, 0 ]), [ 2 ]),
            GT_Base( GT(DFT(2, 1), XChain([ 0 ]), XChain([ 0 ]), [  ]),
              DFT_Base( DFT(2, 1) ) ),
            Info_Base( InfoNt(1) ) ) ),
        DFT_GT_CT( DFT(4, 1),
          GT_NthLoop( GT(DFT(2, 1), XChain([ 0, 1 ]), XChain([ 0, 1 ]), [ 2 ]),
            GT_Base( GT(DFT(2, 1), XChain([ 0 ]), XChain([ 0 ]), [  ]),
              DFT_Base( DFT(2, 1) ) ),
            Info_Base( InfoNt(1) ) ),
          GT_NthLoop( GT(DFT(2, 1), XChain([ 0, 1 ]), XChain([ 1, 0 ]), [ 2 ]),
            GT_Base( GT(DFT(2, 1), XChain([ 0 ]), XChain([ 0 ]), [  ]),
              DFT_Base( DFT(2, 1) ) ),
            Info_Base( InfoNt(1) ) ) ) ) ),
    Info_Base( InfoNt(1) ) ),
  GT_NthLoop( GT(DFT(4, 1), XChain([ 0, 1 ]), XChain([ 1, 0 ]), [ 16 ]),
    GT_Base( GT(DFT(4, 1), XChain([ 0 ]), XChain([ 0 ]), [  ]),
      DFT_GT_CT( DFT(4, 1),
        GT_NthLoop( GT(DFT(2, 1), XChain([ 0, 1 ]), XChain([ 0, 1 ]), [ 2 ]),
          GT_Base( GT(DFT(2, 1), XChain([ 0 ]), XChain([ 0 ]), [  ]),
            DFT_Base( DFT(2, 1) ) ),
          Info_Base( InfoNt(1) ) ),
        GT_NthLoop( GT(DFT(2, 1), XChain([ 0, 1 ]), XChain([ 1, 0 ]), [ 2 ]),
          GT_Base( GT(DFT(2, 1), XChain([ 0 ]), XChain([ 0 ]), [  ]),
            DFT_Base( DFT(2, 1) ) ),
          Info_Base( InfoNt(1) ) ) ) ),
    Info_Base( InfoNt(1) ) ) )
*/

#include <include/omega64c.h>
static _Complex double D1[64];

void init_fft64() {
    for(int i192 = 0; i192 <= 3; i192++) {
        for(int i197 = 0; i197 <= 3; i197++) {
            for(int i203 = 0; i203 <= 1; i203++) {
                D1[((i192*16) + (i197*4) + (i203*2))] = omega(64, ((i197 + (i203*4))*i192));
                D1[((i192*16) + (i197*4) + (i203*2) + 1)] = omega(64, ((i197 + (i203*4) + 8)*i192));
            }
        }
    }
}

void fft64(_Complex double  *Y, _Complex double  *X) {
    static _Complex double T49[64];
    for(int i193 = 0; i193 <= 15; i193++) {
        _Complex double s227, s228, s229, s230, s231, t700, t701, 
            t702;
        int a142;
        s227 = X[i193];
        s228 = X[(i193 + 32)];
        t700 = (s227 + s228);
        t701 = (s227 - s228);
        s229 = X[(i193 + 16)];
        s230 = X[(48 + i193)];
        t702 = (s229 + s230);
        a142 = (4*i193);
        T49[a142] = (t700 + t702);
        T49[(a142 + 2)] = (t700 - t702);
        s231 = (__I__*(s229 - s230));
        T49[(a142 + 1)] = (t701 + s231);
        T49[(3 + a142)] = (t701 - s231);
    }
    for(int i192 = 0; i192 <= 3; i192++) {
        _Complex double s330, s331, s332, s333, s334, s335, s336, 
            s337, s338, s339, s340, s341, s342, s343, s344, 
            s345, s346, s347, s348, s349, s350, s351, s352, 
            s353, s354, s355, s356, s357, s358, s359, s360, 
            s361, s362, t831, t832, t833, t834, t835, t836, 
            t837, t838, t839, t840, t841, t842, t843, t844, 
            t845, t846, t847, t848, t849, t850, t851, t852, 
            t853, t854, t855, t856, t857, t858, t859, t860, 
            t861;
        int a267, a268, a269, a270, a271, a272, a273, 
            a274, a275, a276, a277, a278, a279, a280, a281, 
            a282;
        a267 = (i192 + 32);
        a268 = (16*i192);
        s330 = (D1[a268]*T49[i192]);
        s331 = (D1[(1 + a268)]*T49[a267]);
        t831 = (s330 + s331);
        t832 = (s330 - s331);
        a269 = (i192 + 16);
        a270 = (48 + i192);
        s332 = (D1[(2 + a268)]*T49[a269]);
        s333 = (D1[(3 + a268)]*T49[a270]);
        t833 = (s332 + s333);
        t834 = (t831 + t833);
        t835 = (t831 - t833);
        s334 = (__I__*(s332 - s333));
        t836 = (t832 + s334);
        t837 = (t832 - s334);
        a271 = (i192 + 4);
        a272 = (36 + i192);
        s335 = (D1[(4 + a268)]*T49[a271]);
        s336 = (D1[(5 + a268)]*T49[a272]);
        t838 = (s335 + s336);
        t839 = (s335 - s336);
        a273 = (i192 + 20);
        a274 = (52 + i192);
        s337 = (D1[(6 + a268)]*T49[a273]);
        s338 = (D1[(7 + a268)]*T49[a274]);
        t840 = (s337 + s338);
        t841 = (t838 + t840);
        s339 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t838 - t840));
        s340 = (__I__*(s337 - s338));
        s341 = ((0.92387953251128674 + __I__ * 0.38268343236508978)*(t839 + s340));
        s342 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t839 - s340));
        a275 = (i192 + 8);
        a276 = (40 + i192);
        s343 = (D1[(8 + a268)]*T49[a275]);
        s344 = (D1[(9 + a268)]*T49[a276]);
        t842 = (s343 + s344);
        t843 = (s343 - s344);
        a277 = (i192 + 24);
        a278 = (56 + i192);
        s345 = (D1[(10 + a268)]*T49[a277]);
        s346 = (D1[(11 + a268)]*T49[a278]);
        t844 = (s345 + s346);
        t845 = (t842 + t844);
        s347 = (__I__*(t842 - t844));
        s348 = (__I__*(s345 - s346));
        s349 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t843 + s348));
        s350 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t843 - s348));
        a279 = (i192 + 12);
        a280 = (44 + i192);
        s351 = (D1[(12 + a268)]*T49[a279]);
        s352 = (D1[(13 + a268)]*T49[a280]);
        t846 = (s351 + s352);
        t847 = (s351 - s352);
        a281 = (i192 + 28);
        a282 = (60 + i192);
        s353 = (D1[(14 + a268)]*T49[a281]);
        s354 = (D1[(15 + a268)]*T49[a282]);
        t848 = (s353 + s354);
        t849 = (t846 + t848);
        s355 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t846 - t848));
        s356 = (__I__*(s353 - s354));
        s357 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t847 + s356));
        s358 = ((-0.92387953251128674 - __I__ * 0.38268343236508978)*(t847 - s356));
        t850 = (t834 + t845);
        t851 = (t834 - t845);
        t852 = (t841 + t849);
        Y[i192] = (t850 + t852);
        Y[a267] = (t850 - t852);
        s359 = (__I__*(t841 - t849));
        Y[a269] = (t851 + s359);
        Y[a270] = (t851 - s359);
        t853 = (t836 + s349);
        t854 = (t836 - s349);
        t855 = (s341 + s357);
        Y[a271] = (t853 + t855);
        Y[a272] = (t853 - t855);
        s360 = (__I__*(s341 - s357));
        Y[a273] = (t854 + s360);
        Y[a274] = (t854 - s360);
        t856 = (t835 + s347);
        t857 = (t835 - s347);
        t858 = (s339 + s355);
        Y[a275] = (t856 + t858);
        Y[a276] = (t856 - t858);
        s361 = (__I__*(s339 - s355));
        Y[a277] = (t857 + s361);
        Y[a278] = (t857 - s361);
        t859 = (t837 + s350);
        t860 = (t837 - s350);
        t861 = (s342 + s358);
        Y[a279] = (t859 + t861);
        Y[a280] = (t859 - t861);
        s362 = (__I__*(s342 - s358));
        Y[a281] = (t860 + s362);
        Y[a282] = (t860 - s362);
    }
}