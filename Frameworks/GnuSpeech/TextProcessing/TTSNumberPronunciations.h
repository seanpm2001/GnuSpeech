////////////////////////////////////////////////////////////////////////////////
//
//  Copyright 1991-2009 David R. Hill, Leonard Manzara, Craig Schock
//  
//  Contributors: Steve Nygard
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
////////////////////////////////////////////////////////////////////////////////
//
//  TTSNumberPronunciations.h
//  GnuSpeech
//
//  Created by Steve Nygard in 2004.
//
//  Version: 0.8
//
////////////////////////////////////////////////////////////////////////////////

/*  number_pronunciations.h CONTAINS PRONUNCIATIONS FOR
    number_parser() AND degenerate_string()  */

/*  CARDINAL NUMBER NAMES  */
#define PR_OH                     @"'uh_uu "
#define PR_ZERO                   @"'z_i_r.uh_uu "
#define PR_ONE                    @"'w_a_n "
#define PR_TWO                    @"'t_uu "
#define PR_THREE                  @"'th_r_ee "
#define PR_FOUR                   @"'f_aw_r "
#define PR_FIVE                   @"'f_ah_i_v "
#define PR_SIX                    @"'s_i_k_s "
#define PR_SEVEN                  @"'s_e.v_uh_n "
#define PR_EIGHT                  @"'e_i_t "
#define PR_NINE                   @"'n_ah_i_n "
#define PR_TEN                    @"'t_e_n "
#define PR_ELEVEN                 @"i.'l_e.v_uh_n "
#define PR_TWELVE                 @"'t_w_e_l_v "
#define PR_THIRTEEN               @"'th_uh_r.t_ee_n "
#define PR_FOURTEEN               @"'f_aw_r.t_ee_n "
#define PR_FIFTEEN                @"'f_i_f.t_ee_n "
#define PR_SIXTEEN                @"'s_i_k_s.t_ee_n "
#define PR_SEVENTEEN              @"'s_e.v_uh_n.t_ee_n "
#define PR_EIGHTEEN               @"'e_i.t_ee_n "
#define PR_NINETEEN               @"'n_ah_i_n.t_ee_n "
#define PR_TWENTY                 @"'t_w_e_n.t_ee "
#define PR_THIRTY                 @"'th_uh_r.t_ee "
#define PR_FORTY                  @"'f_aw_r.t_ee "
#define PR_FIFTY                  @"'f_i_f.t_ee "
#define PR_SIXTY                  @"'s_i_k_s.t_ee "
#define PR_SEVENTY                @"'s_e.v_uh_n.t_ee "
#define PR_EIGHTY                 @"'e_i.t_ee "
#define PR_NINETY                 @"'n_ah_i.t_ee "

#define PR_TRIADS_MAX             22
/*  THERE MUST BE THIS MANY TRIAD NAMES BELOW  */
#define PR_HUNDRED                @"'h_a_n.d_r_uh_d "
#define PR_THOUSAND               @"'th_ah_uu.z_uh_n_d "
#define PR_MILLION                @"'m_i_l.i_uh_n "
#define PR_BILLION                @"'b_i_l.i_uh_n "
#define PR_TRILLION               @"'t_r_i_l.i_uh_n "
#define PR_QUADRILLION            @"k_w_uh.'d_r_i_l.i_uh_n "
#define PR_QUINTILLION            @"k_w_i_n.'t_i_l.i_uh_n "
#define PR_SEXTILLION             @"s_e_k_s.'t_i_l.i_uh_n "
#define PR_SEPTILLION             @"s_e_p.'t_i_l.i_uh_n "
#define PR_OCTILLION              @"ar_k.'t_i_l.i_uh_n "
#define PR_NONILLION              @"n_o.'n_i_l.i_uh_n "
#define PR_DECILLION              @"d_e.'s_i_l.i_uh_n "
#define PR_UNDECILLION            @"\"a_n.d_e.'s_i_l.i_uh_n "
#define PR_DUODECILLION           @"\"d_uu.uh_uu.d_e.'s_i_l.i_uh_n "
#define PR_TREDECILLION           @"\"t_r_e_i.d_e.'s_i_l.i_uh_n "
#define PR_QUATTUORDECILLION      @"k_w_uh.\"t_aw_r.d_e.'s_i_l.i_uh_n "
#define PR_QUINDECILLION          @"\"k_w_i_n.d_e.'s_i_l.i_uh_n "
#define PR_SEXDECILLION           @"\"s_e_k_s.d_e.'s_i_l.i_uh_n "
#define PR_SEPTENDECILLION        @"\"s_e_p.t_e_n.d_e.'s_i_l.i_uh_n "
#define PR_OCTODECILLION          @"\"ar_k.t_uh_uu.d_e.'s_i_l.i_uh_n "
#define PR_NOVEMDECILLION         @"\"n_uh_uu.v_e_m.d_e.'s_i_l.i_uh_n "
#define PR_VIGINTILLION           @"\"v_i.j_i_n.'t_i_l.i_uh_n "


/*  ORDINAL NUMBER NAMES  */
#define PR_ZEROETH                @"'z_i_r.uh_uu.e_th "
#define PR_FIRST                  @"'f_uh_r_s_t "
#define PR_SECOND                 @"'s_e.k_uh_n_d "
#define PR_THIRD                  @"'th_uh_r_d "
#define PR_FOURTH                 @"'f_aw_r_th "
#define PR_FIFTH                  @"'f_i_f_th "
#define PR_SIXTH                  @"'s_i_k_s_th "
#define PR_SEVENTH                @"'s_e.v_uh_n_th "
#define PR_EIGHTH                 @"'e_i_t_th "
#define PR_NINTH                  @"'n_ah_i_n_th "
#define PR_TENTH                  @"'t_e_n_th "
#define PR_ELEVENTH               @"i.'l_e.v_uh_n_th "
#define PR_TWELFTH                @"'t_w_e_l_f_th "
#define PR_THIRTEENTH             @"'th_uh_r.t_ee_n_th "
#define PR_FOURTEENTH             @"'f_aw_r.t_ee_n_th "
#define PR_FIFTEENTH              @"'f_i_f.t_ee_n_th "
#define PR_SIXTEENTH              @"'s_i_k_s.t_ee_n_th "
#define PR_SEVENTEENTH            @"'s_e.v_uh_n.t_ee_n_th "
#define PR_EIGHTEENTH             @"'e_i.t_ee_n_th "
#define PR_NINETEENTH             @"'n_ah_i_n.t_ee_n_th "
#define PR_TWENTIETH              @"'t_w_e_n.t_ee.uh_th "
#define PR_THIRTIETH              @"'th_uh_r.t_ee.uh_th "
#define PR_FORTIETH               @"'f_aw_r.t_ee.uh_th "
#define PR_FIFTIETH               @"'f_i_f.t_ee.uh_th "
#define PR_SIXTIETH               @"'s_i_k_s.t_ee.uh_th "
#define PR_SEVENTIETH             @"'s_e.v_uh_n.t_ee.uh_th "
#define PR_EIGHTIETH              @"'e_i.t_ee.uh_th "
#define PR_NINETIETH              @"'n_ah_i.t_ee.uh_th "

/* THESE MUST MATCH THE TRIAD NAMES ABOVE */
#define PR_HUNDREDTH              @"'h_a_n.d_r_uh_d_th "
#define PR_THOUSANDTH             @"'th_ah_uu.z_uh_n_th "
#define PR_MILLIONTH              @"'m_i_l.i_uh_n_th "
#define PR_BILLIONTH              @"'b_i_l.i_uh_n_th "
#define PR_TRILLIONTH             @"'t_r_i_l.i_uh_n_th "
#define PR_QUADRILLIONTH          @"k_w_uh.'d_r_i_l.i_uh_n_th "
#define PR_QUINTILLIONTH          @"k_w_i_n.'t_i_l.i_uh_n_th "
#define PR_SEXTILLIONTH           @"s_e_k_s.'t_i_l.i_uh_n_th "
#define PR_SEPTILLIONTH           @"s_e_p.'t_i_l.i_uh_n_th "
#define PR_OCTILLIONTH            @"ar_k.'t_i_l.i_uh_n_th "
#define PR_NONILLIONTH            @"n_o.'n_i_l.i_uh_n_th "
#define PR_DECILLIONTH            @"d_e.'s_i_l.i_uh_n_th "
#define PR_UNDECILLIONTH          @"\"a_n.d_e.'s_i_l.i_uh_n_th "
#define PR_DUODECILLIONTH         @"\"d_uu.uh_uu.d_e.'s_i_l.i_uh_n_th "
#define PR_TREDECILLIONTH         @"\"t_r_e_i.d_e.'s_i_l.i_uh_n_th "
#define PR_QUATTUORDECILLIONTH    @"k_w_uh.\"t_aw_r.d_e.'s_i_l.i_uh_n_th "
#define PR_QUINDECILLIONTH        @"\"k_w_i_n.d_e.'s_i_l.i_uh_n_th "
#define PR_SEXDECILLIONTH         @"\"s_e_k_s.d_e.'s_i_l.i_uh_n_th "
#define PR_SEPTENDECILLIONTH      @"\"s_e_p.t_e_n.d_e.'s_i_l.i_uh_n_th "
#define PR_OCTODECILLIONTH        @"\"ar_k.t_uh_uu.d_e.'s_i_l.i_uh_n_th "
#define PR_NOVEMDECILLIONTH       @"\"n_uh_uu.v_e_m.d_e.'s_i_l.i_uh_n_th "
#define PR_VIGINTILLIONTH         @"\"v_i.j_i_n.'t_i_l.i_uh_n_th "

/*  PLURAL ORDINAL NUMBER NAMES FOR FRACTIONS  */
#define PR_HALF                   @"'h_aa_f "
#define PR_HALVES                 @"'h_aa_v_z "
#define PR_SECONDTH               @"'s_e.k_uh_n_th "
#define PR_SECONDTHS              @"'s_e.k_uh_n_th_s "
#define PR_THIRDS                 @"'th_uh_r_d_z "
#define PR_QUARTER                @"'k_w_aw_r.t_uh_r "
#define PR_QUARTERS               @"'k_w_aw_r.t_uh_r_z "
#define PR_FOURTHS                @"'f_aw_r_th_s "
#define PR_FIFTHS                 @"'f_i_f_s "
#define PR_SIXTHS                 @"'s_i_k_s_th_s "
#define PR_SEVENTHS               @"'s_e.v_uh_n_th_s "
#define PR_EIGHTHS                @"'e_i_t_th_s "
#define PR_NINTHS                 @"'n_ah_i_n_th_s "
#define PR_TENTHS                 @"'t_e_n_th_s "
#define PR_ELEVENTHS              @"i.'l_e.v_e_n_th_s "
#define PR_TWELFTHS               @"'t_w_e_l_f_s "
#define PR_THIRTEENTHS            @"'th_uh_r.t_ee_n_th_s "
#define PR_FOURTEENTHS            @"'f_aw_r.t_ee_n_th_s "
#define PR_FIFTEENTHS             @"'f_i_f.t_ee_n_th_s "
#define PR_SIXTEENTHS             @"'s_i_k_s.t_ee_n_th_s "
#define PR_SEVENTEENTHS           @"'s_e.v_uh_n.t_ee_n_th_s "
#define PR_EIGHTEENTHS            @"'e_i.t_ee_n_th_s "
#define PR_NINETEENTHS            @"'n_ah_i_n.t_ee_n_th_s "
#define PR_TWENTIETHS             @"'t_w_e_n.t_ee.uh_th_s "
#define PR_THIRTIETHS             @"'th_uh_r.t_ee.uh_th_s "
#define PR_FORTIETHS              @"'f_aw_r.t_ee.uh_th_s "
#define PR_FIFTIETHS              @"'f_i_f.t_ee.uh_th_s "
#define PR_SIXTIETHS              @"'s_i_k_s.t_ee.uh_th_s "
#define PR_SEVENTIETHS            @"'s_e.v_uh_n.t_ee.uh_th_s "
#define PR_EIGHTIETHS             @"'e_i.t_ee.uh_th_s "
#define PR_NINETIETHS             @"'n_ah_i.t_ee.uh_th_s "

/* THESE MUST MATCH THE TRIAD NAMES ABOVE */
#define PR_HUNDREDTHS             @"'h_a_n.d_r_uh_d_th_s "
#define PR_THOUSANDTHS            @"'th_ah_uu.z_uh_n_th_s "
#define PR_MILLIONTHS             @"'m_i_l.i_uh_n_th_s "
#define PR_BILLIONTHS             @"'b_i_l.i_uh_n_th_s "
#define PR_TRILLIONTHS            @"'t_r_i_l.i_uh_n_th_s "
#define PR_QUADRILLIONTHS         @"k_w_uh.'d_r_i_l.i_uh_n_th_s "
#define PR_QUINTILLIONTHS         @"k_w_i_n.'t_i_l.i_uh_n_th_s "
#define PR_SEXTILLIONTHS          @"s_e_k_s.'t_i_l.i_uh_n_th_s "
#define PR_SEPTILLIONTHS          @"s_e_p.'t_i_l.i_uh_n_th_s "
#define PR_OCTILLIONTHS           @"ar_k.'t_i_l.i_uh_n_th_s "
#define PR_NONILLIONTHS           @"n_o.'n_i_l.i_uh_n_th_s "
#define PR_DECILLIONTHS           @"d_e.'s_i_l.i_uh_n_th_s "
#define PR_UNDECILLIONTHS         @"\"a_n.d_e.'s_i_l.i_uh_n_th_s "
#define PR_DUODECILLIONTHS        @"\"d_uu.uh_uu.d_e.'s_i_l.i_uh_n_th_s "
#define PR_TREDECILLIONTHS        @"\"t_r_e_i.d_e.'s_i_l.i_uh_n_th_s "
#define PR_QUATTUORDECILLIONTHS   @"k_w_uh.\"t_aw_r.d_e.'s_i_l.i_uh_n_th_s "
#define PR_QUINDECILLIONTHS       @"\"k_w_i_n.d_e.'s_i_l.i_uh_n_th_s "
#define PR_SEXDECILLIONTHS        @"\"s_e_k_s.d_e.'s_i_l.i_uh_n_th_s "
#define PR_SEPTENDECILLIONTHS     @"\"s_e_p.t_e_n.d_e.'s_i_l.i_uh_n_th_s "
#define PR_OCTODECILLIONTHS       @"\"ar_k.t_uh_uu.d_e.'s_i_l.i_uh_n_th_s "
#define PR_NOVEMDECILLIONTHS      @"\"n_uh_uu.v_e_m.d_e.'s_i_l.i_uh_n_th_s "
#define PR_VIGINTILLIONTHS        @"\"v_i.j_i_n.'t_i_l.i_uh_n_th_s "


/*  MISCELLANEOUS SYMBOL NAMES  */
#define PR_AND                    @"aa_n_d "
#define PR_DOLLAR                 @"'d_ar.l_uh_r "
#define PR_DOLLARS                @"'d_ar.l_uh_r_z "
#define PR_NEGATIVE               @"'n_e.g_uh.t_i_v "
#define PR_POSITIVE               @"'p_o.z_i.t_i_v "
#define PR_POINT                  @"'p_o_i_n_t "
#define PR_CENT                   @"'s_e_n_t "
#define PR_CENTS                  @"'s_e_n_t_s "
#define PR_PERCENT                @"p_r.'s_e_n_t "
#define PR_OVER                   @"'uh_uu.v_uh_r "
#define PR_AREA                   @"'e_r.ee.uh "
#define PR_CODE                   @"'k_uh_uu_d "
#define PR_PAUSE                  @"^ "
#define PR_SECONDS                @"'s_e.k_uh_n_d_z "
#define PR_OCLOCK                 @"uh_uu.'k_l_ar_k "
#define PR_NULL_STRING            @""

#define PR_BLANK                  @"'b_l_aa_n_k "
#define PR_EXCLAMATION_POINT      @"\"e_k_s.k_l_uh.'m_e_i.sh_uh_n 'p_o_i_n_t "
#define PR_DOUBLE_QUOTE           @"'d_a.b_uh_l 'k_w_uh_uu_t "
#define PR_NUMBER_SIGN            @"'n_a_m.b_r \"s_ah_i_n "
#define PR_DOLLAR_SIGN            @"'d_ar.l_uh_r \"s_ah_i_n "
#define PR_PERCENT_SIGN           @"p_r.'s_e_n_t 's_ah_i_n "
#define PR_AMPERSAND              @"'aa_m.p_r.s_aa_n_d "
#define PR_SINGLE_QUOTE           @"'s_i_ng.g_uh_l 'k_w_uh_uu_t "
#define PR_OPEN_PARENTHESIS       @"'uh_uu.p_uh_n p_uh.'r_e_n.th_uh.s_i_s "
#define PR_CLOSE_PARENTHESIS      @"'k_l_uh_uu_z p_uh.'r_e_n.th_uh.s_i_s "
#define PR_ASTERISK               @"'aa_s.t_uh_r.i_s_k "
#define PR_PLUS_SIGN              @"'p_l_a_s 's_ah_i_n "
#define PR_COMMA                  @"'k_ar.m_uh "
#define PR_HYPHEN                 @"'h_ah_i.f_uh_n "
#define PR_PERIOD                 @"'p_i_r.ee.uh_d "
#define PR_SLASH                  @"'s_l_aa_sh "
#define PR_COLON                  @"'k_uh_uu.l_uh_n "
#define PR_SEMICOLON              @"'s_e.m_ee.\"k_uh_uu.l_uh_n "
#define PR_OPEN_ANGLE_BRACKET     @"'uh_uu.p_uh_n 'aa_ng.g_uh_l 'b_r_aa.k_uh_t "
#define PR_EQUAL_SIGN             @"'ee.k_w_uh_l 's_ah_i_n "
#define PR_CLOSE_ANGLE_BRACKET    @"'k_l_uh_uu_z 'aa_ng.g_uh_l 'b_r_aa.k_uh_t "
#define PR_QUESTION_MARK          @"'k_w_e_s.ch_uh_n 'm_ar_r_k "
#define PR_AT_SIGN                @"'aa_t 's_ah_i_n "
#define PR_A                      @"'e_i "
#define PR_B                      @"'b_ee "
#define PR_C                      @"'s_ee "
#define PR_D                      @"'d_ee "
#define PR_E                      @"'ee "
#define PR_F                      @"'e_f "
#define PR_G                      @"'j_ee "
#define PR_H                      @"'e_i_ch "
#define PR_I                      @"'ah_i "
#define PR_J                      @"'j_e_i "
#define PR_K                      @"'k_e_i "
#define PR_L                      @"'e_l "
#define PR_M                      @"'e_m "
#define PR_N                      @"'e_n "
#define PR_O                      @"'uh_uu "
#define PR_P                      @"'p_ee "
#define PR_Q                      @"'k_y_uu "
#define PR_R                      @"'ar_r "
#define PR_S                      @"'e_s "
#define PR_T                      @"'t_ee "
#define PR_U                      @"'y_uu "
#define PR_V                      @"'v_ee "
#define PR_W                      @"'d_a.b_uh_l.y_uu "
#define PR_X                      @"'e_k_s "
#define PR_Y                      @"'w_ah_i "
#define PR_Z                      @"'z_ee "
#define PR_OPEN_SQUARE_BRACKET    @"'uh_uu.p_uh_n 's_k_w_e_r 'b_r_aa.k_uh_t "
#define PR_BACKSLASH              @"'b_aa_k.s_l_aa_sh "
#define PR_CLOSE_SQUARE_BRACKET   @"'k_l_uh_uu_z 's_k_w_e_r 'b_r_aa.k_uh_t "
#define PR_CARET                  @"'k_e.r_uh_t "
#define PR_UNDERSCORE             @"'a_n.d_r.\"s_k_aw_r "
#define PR_GRAVE_ACCENT           @"'g_r_e_i_v 'aa_k.s_e_n_t "
#define PR_OPEN_BRACE             @"'uh_uu.p_uh_n 'b_r_e_i_s "
#define PR_VERTICAL_BAR           @"'v_uh_r.t_i.k_uh_l 'b_a_r "
#define PR_CLOSE_BRACE            @"'k_l_uh_uu_z 'b_r_e_i_s "
#define PR_TILDE                  @"'t_i_l.d_uh "
#define PR_UNKNOWN                @"uh_n.'n_uh_uu_n "
