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
  timestamp: Oct 8, 2007; 9:20:23
  transform: DFT(256, 1)
  performance: 9548 cycles, 2852 Mflop/s
*/

#include "omega64c.h"
static _Complex double D5[124];
static _Complex double D6[124];
static _Complex double D7[28];
static _Complex double D8[28];

void init_fft256() {
  for(int i839 = 0; i839 <= 30; i839++) {
    for(int i849 = 0; i849 <= 1; i849++) {
      D5[((i839*4) + (i849*2))] = omega(256, ((i839 + 1)*i849));
      D5[((i839*4) + (i849*2) + 1)] = omega(256, ((i839 + 1)*(i849 + 2)));
    }
  }
  for(int i840 = 0; i840 <= 30; i840++) {
    for(int i857 = 0; i857 <= 1; i857++) {
      D6[((i840*4) + (i857*2))] = omega(256, ((33 + i840)*i857));
      D6[((i840*4) + (i857*2) + 1)] = omega(256, ((33 + i840)*(i857 + 2)));
    }
  }
  for(int i859 = 0; i859 <= 6; i859++) {
    for(int i869 = 0; i869 <= 1; i869++) {
      D7[((i859*4) + (i869*2))] = omega(64, ((i859 + 1)*i869));
      D7[((i859*4) + (i869*2) + 1)] = omega(64, ((i859 + 1)*(i869 + 2)));
    }
  }
  for(int i860 = 0; i860 <= 6; i860++) {
    for(int i877 = 0; i877 <= 1; i877++) {
      D8[((i860*4) + (i877*2))] = omega(64, ((9 + i860)*i877));
      D8[((i860*4) + (i877*2) + 1)] = omega(64, ((9 + i860)*(i877 + 2)));
    }
  }
}

void fft256(_Complex double  *Y, _Complex double  *X) {
  static _Complex double T245[256];
  for(int i841 = 0; i841 <= 3; i841++) {
    static _Complex double T246[64];
    for(int i861 = 0; i861 <= 3; i861++) {
      _Complex double a1566, t1658, t1657, t1656, a1565, t1655, t1654, 
        t1653, a1564, t1652, t1651, t1650, a1563, t1649, t1648, 
        t1647, s541, s540, a1561, s539, t1646, t1645, s538, 
        s537, t1644, t1643, s536, s535, s534, s533, a1560, 
        s532, t1642, t1641, s531, s530, t1640, t1639, s529, 
        s528, s527, s526, a1559, s525, t1638, t1637, s524, 
        s523, t1636, t1635, s522, s521, t1634, t1633, a1558, 
        t1632, t1631, t1630, s520, s519, t1629, t1628, s518, 
        s517;
      _Complex double  *a1562, *a1557;
      a1557 = (X + i841 + (4*i861));
      s517 = *(a1557);
      s518 = *((a1557 + 128));
      t1628 = (s517 + s518);
      t1629 = (s517 - s518);
      s519 = *((a1557 + 64));
      s520 = *((a1557 + 192));
      t1630 = (s519 + s520);
      t1631 = (t1628 + t1630);
      t1632 = (t1628 - t1630);
      a1558 = (__I__*(s519 - s520));
      t1633 = (t1629 + a1558);
      t1634 = (t1629 - a1558);
      s521 = *((a1557 + 16));
      s522 = *((a1557 + 144));
      t1635 = (s521 + s522);
      t1636 = (s521 - s522);
      s523 = *((a1557 + 80));
      s524 = *((a1557 + 208));
      t1637 = (s523 + s524);
      t1638 = (t1635 + t1637);
      s525 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t1635 - t1637));
      a1559 = (__I__*(s523 - s524));
      s526 = ((0.92387953251128674 + __I__ * 0.38268343236508978)*(t1636 + a1559));
      s527 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t1636 - a1559));
      s528 = *((a1557 + 32));
      s529 = *((a1557 + 160));
      t1639 = (s528 + s529);
      t1640 = (s528 - s529);
      s530 = *((a1557 + 96));
      s531 = *((a1557 + 224));
      t1641 = (s530 + s531);
      t1642 = (t1639 + t1641);
      s532 = (__I__*(t1639 - t1641));
      a1560 = (__I__*(s530 - s531));
      s533 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t1640 + a1560));
      s534 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t1640 - a1560));
      s535 = *((a1557 + 48));
      s536 = *((a1557 + 176));
      t1643 = (s535 + s536);
      t1644 = (s535 - s536);
      s537 = *((a1557 + 112));
      s538 = *((a1557 + 240));
      t1645 = (s537 + s538);
      t1646 = (t1643 + t1645);
      s539 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t1643 - t1645));
      a1561 = (__I__*(s537 - s538));
      s540 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t1644 + a1561));
      s541 = ((-0.92387953251128674 - __I__ * 0.38268343236508978)*(t1644 - a1561));
      t1647 = (t1631 + t1642);
      t1648 = (t1631 - t1642);
      t1649 = (t1638 + t1646);
      a1562 = (T246 + (16*i861));
      *(a1562) = (t1647 + t1649);
      *((a1562 + 8)) = (t1647 - t1649);
      a1563 = (__I__*(t1638 - t1646));
      *((a1562 + 4)) = (t1648 + a1563);
      *((a1562 + 12)) = (t1648 - a1563);
      t1650 = (t1633 + s533);
      t1651 = (t1633 - s533);
      t1652 = (s526 + s540);
      *((a1562 + 1)) = (t1650 + t1652);
      *((a1562 + 9)) = (t1650 - t1652);
      a1564 = (__I__*(s526 - s540));
      *((a1562 + 5)) = (t1651 + a1564);
      *((a1562 + 13)) = (t1651 - a1564);
      t1653 = (t1632 + s532);
      t1654 = (t1632 - s532);
      t1655 = (s525 + s539);
      *((a1562 + 2)) = (t1653 + t1655);
      *((a1562 + 10)) = (t1653 - t1655);
      a1565 = (__I__*(s525 - s539));
      *((a1562 + 6)) = (t1654 + a1565);
      *((a1562 + 14)) = (t1654 - a1565);
      t1656 = (t1634 + s534);
      t1657 = (t1634 - s534);
      t1658 = (s527 + s541);
      *((a1562 + 3)) = (t1656 + t1658);
      *((a1562 + 11)) = (t1656 - t1658);
      a1566 = (__I__*(s527 - s541));
      *((a1562 + 7)) = (t1657 + a1566);
      *((a1562 + 15)) = (t1657 - a1566);
    }
    _Complex double a1612, t1677, a1610, a1609, t1676, t1675, a1608, 
      a1607;
    _Complex double  *a1611;
    a1607 = *(T246);
    a1608 = *((T246 + 32));
    t1675 = (a1607 + a1608);
    t1676 = (a1607 - a1608);
    a1609 = *((T246 + 16));
    a1610 = *((T246 + 48));
    t1677 = (a1609 + a1610);
    a1611 = (T245 + (64*i841));
    *(a1611) = (t1675 + t1677);
    *((a1611 + 32)) = (t1675 - t1677);
    a1612 = (__I__*(a1609 - a1610));
    *((a1611 + 16)) = (t1676 + a1612);
    *((a1611 + 48)) = (t1676 - a1612);
    for(int i859 = 0; i859 <= 6; i859++) {
      _Complex double a1660, t1696, s561, s560, t1695, t1694, s559, 
        s558;
      _Complex double  *b214, *a1659, *b213;
      b213 = (T246 + i859);
      a1659 = (D7 + (4*i859));
      s558 = (*(a1659)**((b213 + 1)));
      s559 = (*((a1659 + 1))**((b213 + 33)));
      t1694 = (s558 + s559);
      t1695 = (s558 - s559);
      s560 = (*((a1659 + 2))**((b213 + 17)));
      s561 = (*((a1659 + 3))**((b213 + 49)));
      t1696 = (s560 + s561);
      b214 = (T245 + (64*i841) + i859);
      *((b214 + 1)) = (t1694 + t1696);
      *((b214 + 33)) = (t1694 - t1696);
      a1660 = (__I__*(s560 - s561));
      *((b214 + 17)) = (t1695 + a1660);
      *((b214 + 49)) = (t1695 - a1660);
    }
    _Complex double s567, s566, a1709, a1708, t1714, t1713, a1707, 
      a1706;
    _Complex double  *b220;
    a1706 = *((T246 + 8));
    a1707 = (__I__**((T246 + 40)));
    t1713 = (a1706 + a1707);
    t1714 = (a1706 - a1707);
    a1708 = *((T246 + 24));
    a1709 = (__I__**((T246 + 56)));
    s566 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(a1708 + a1709));
    s567 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(a1708 - a1709));
    b220 = (T245 + (64*i841));
    *((b220 + 8)) = (t1713 + s566);
    *((b220 + 40)) = (t1713 - s566);
    *((b220 + 24)) = (t1714 + s567);
    *((b220 + 56)) = (t1714 - s567);
    for(int i860 = 0; i860 <= 6; i860++) {
      _Complex double a1757, t1733, s587, s586, t1732, t1731, s585, 
        s584;
      _Complex double  *b240, *a1756, *b239;
      b239 = (T246 + i860);
      a1756 = (D8 + (4*i860));
      s584 = (*(a1756)**((b239 + 9)));
      s585 = (*((a1756 + 1))**((b239 + 41)));
      t1731 = (s584 + s585);
      t1732 = (s584 - s585);
      s586 = (*((a1756 + 2))**((b239 + 25)));
      s587 = (*((a1756 + 3))**((b239 + 57)));
      t1733 = (s586 + s587);
      b240 = (T245 + (64*i841) + i860);
      *((b240 + 9)) = (t1731 + t1733);
      *((b240 + 41)) = (t1731 - t1733);
      a1757 = (__I__*(s586 - s587));
      *((b240 + 25)) = (t1732 + a1757);
      *((b240 + 57)) = (t1732 - a1757);
    }
  }
  _Complex double a1796, t1752, a1795, a1794, t1751, t1750, a1793, 
    a1792;
  a1792 = *(T245);
  a1793 = *((T245 + 128));
  t1750 = (a1792 + a1793);
  t1751 = (a1792 - a1793);
  a1794 = *((T245 + 64));
  a1795 = *((T245 + 192));
  t1752 = (a1794 + a1795);
  *(Y) = (t1750 + t1752);
  *((Y + 128)) = (t1750 - t1752);
  a1796 = (__I__*(a1794 - a1795));
  *((Y + 64)) = (t1751 + a1796);
  *((Y + 192)) = (t1751 - a1796);
  for(int i839 = 0; i839 <= 30; i839++) {
    _Complex double a1839, t1771, s607, s606, t1770, t1769, s605, 
      s604;
    _Complex double  *b255, *a1838, *b254;
    b254 = (T245 + i839);
    a1838 = (D5 + (4*i839));
    s604 = (*(a1838)**((b254 + 1)));
    s605 = (*((a1838 + 1))**((b254 + 129)));
    t1769 = (s604 + s605);
    t1770 = (s604 - s605);
    s606 = (*((a1838 + 2))**((b254 + 65)));
    s607 = (*((a1838 + 3))**((b254 + 193)));
    t1771 = (s606 + s607);
    b255 = (Y + i839);
    *((b255 + 1)) = (t1769 + t1771);
    *((b255 + 129)) = (t1769 - t1771);
    a1839 = (__I__*(s606 - s607));
    *((b255 + 65)) = (t1770 + a1839);
    *((b255 + 193)) = (t1770 - a1839);
  }
  _Complex double s613, s612, a1883, a1882, t1789, t1788, a1881, 
    a1880;
  a1880 = *((T245 + 32));
  a1881 = (__I__**((T245 + 160)));
  t1788 = (a1880 + a1881);
  t1789 = (a1880 - a1881);
  a1882 = *((T245 + 96));
  a1883 = (__I__**((T245 + 224)));
  s612 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(a1882 + a1883));
  s613 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(a1882 - a1883));
  *((Y + 32)) = (t1788 + s612);
  *((Y + 160)) = (t1788 - s612);
  *((Y + 96)) = (t1789 + s613);
  *((Y + 224)) = (t1789 - s613);
  for(int i840 = 0; i840 <= 30; i840++) {
    _Complex double a1926, t1808, s633, s632, t1807, t1806, s631, 
      s630;
    _Complex double  *b270, *a1925, *b269;
    b269 = (T245 + i840);
    a1925 = (D6 + (4*i840));
    s630 = (*(a1925)**((b269 + 33)));
    s631 = (*((a1925 + 1))**((b269 + 161)));
    t1806 = (s630 + s631);
    t1807 = (s630 - s631);
    s632 = (*((a1925 + 2))**((b269 + 97)));
    s633 = (*((a1925 + 3))**((b269 + 225)));
    t1808 = (s632 + s633);
    b270 = (Y + i840);
    *((b270 + 33)) = (t1806 + t1808);
    *((b270 + 161)) = (t1806 - t1808);
    a1926 = (__I__*(s632 - s633));
    *((b270 + 97)) = (t1807 + a1926);
    *((b270 + 225)) = (t1807 - a1926);
  }
}