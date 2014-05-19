/*
 * Linux/PA-RISC Project (http://www.parisc-linux.org/)
 *
 * Floating-point emulation code
 *  Copyright (C) 2001 Hewlett-Packard (Paul Bame) <bame@debian.org>
 *
 *    This program is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2, or (at your option)
 *    any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


#include "float.h"
#include "sgl_float.h"
#include "dbl_float.h"
#include "cnv_float.h"


int
sgl_to_sgl_fcnvfu(
			sgl_floating_point *srcptr,
			unsigned int *nullptr,
			unsigned int *dstptr,
			unsigned int *status)
{
	register unsigned int src, result;
	register int src_exponent;
	register boolean inexact = FALSE;

	src = *srcptr;
	src_exponent = Sgl_exponent(src) - SGL_BIAS;

	if (src_exponent > SGL_FX_MAX_EXP + 1) {
		if (Sgl_isone_sign(src)) {
			result = 0;
		} else {
			result = 0xffffffff;
		}
		if (Is_invalidtrap_enabled()) {
			return(INVALIDEXCEPTION);
		}
		Set_invalidflag();
		*dstptr = result;
		return(NOEXCEPTION);
	}
	if (src_exponent >= 0) {
		if (Sgl_isone_sign(src)) {
			result = 0;
			if (Is_invalidtrap_enabled()) {
				return(INVALIDEXCEPTION);
			}
			Set_invalidflag();
			*dstptr = result;
			return(NOEXCEPTION);
		}
		Sgl_clear_signexponent_set_hidden(src);
		Suint_from_sgl_mantissa(src,src_exponent,result);

		
		if (Sgl_isinexact_to_unsigned(src,src_exponent)) {
			inexact = TRUE;
			
			switch (Rounding_mode()) {
			case ROUNDPLUS:
				result++;
				break;
			case ROUNDMINUS: 
				break;
			case ROUNDNEAREST:
				if (Sgl_isone_roundbit(src,src_exponent) &&
				    (Sgl_isone_stickybit(src,src_exponent) ||
				     (result & 1))) {
			     		result++;
				}
				break;
			}
		}
	} else {
		result = 0;

		
		if (Sgl_isnotzero_exponentmantissa(src)) {
			inexact = TRUE;
			
			switch (Rounding_mode()) {
			case ROUNDPLUS:
				if (Sgl_iszero_sign(src)) {
					result++;
				}
				break;
			case ROUNDMINUS:
				if (Sgl_isone_sign(src)) {
					result = 0;
					if (Is_invalidtrap_enabled()) {
						return(INVALIDEXCEPTION);
					}
					Set_invalidflag();
					inexact = FALSE;
				}
				break;
			case ROUNDNEAREST:
				if (src_exponent == -1 &&
				    Sgl_isnotzero_mantissa(src)) {
					if (Sgl_isone_sign(src)) {
						result = 0;
						if (Is_invalidtrap_enabled()) {
							return(INVALIDEXCEPTION);
						}
						Set_invalidflag();
						inexact = FALSE;
					}
			      		else result++;
				}
				break;
			}
		}
	}
	*dstptr = result;
	if (inexact) {
		if (Is_inexacttrap_enabled()) return(INEXACTEXCEPTION);
		else Set_inexactflag();
	}
	return(NOEXCEPTION);
}

int
sgl_to_dbl_fcnvfu(
		    sgl_floating_point *srcptr,
		    unsigned int *nullptr,
		    dbl_unsigned *dstptr,
		    unsigned int *status)
{
	register int src_exponent;
	register unsigned int src, resultp1, resultp2;
	register boolean inexact = FALSE;

	src = *srcptr;
	src_exponent = Sgl_exponent(src) - SGL_BIAS;

	if (src_exponent > DBL_FX_MAX_EXP + 1) {
		if (Sgl_isone_sign(src)) {
			resultp1 = resultp2 = 0;
		} else {
			resultp1 = resultp2 = 0xffffffff;
		}
		if (Is_invalidtrap_enabled()) {
			return(INVALIDEXCEPTION);
		}
		Set_invalidflag();
    		Duint_copytoptr(resultp1,resultp2,dstptr);
		return(NOEXCEPTION);
	}
	if (src_exponent >= 0) {
		if (Sgl_isone_sign(src)) {
			resultp1 = resultp2 = 0;
			if (Is_invalidtrap_enabled()) {
				return(INVALIDEXCEPTION);
			}
			Set_invalidflag();
    			Duint_copytoptr(resultp1,resultp2,dstptr);
			return(NOEXCEPTION);
		}
		Sgl_clear_signexponent_set_hidden(src);
		Duint_from_sgl_mantissa(src,src_exponent,resultp1,resultp2);

		
		if (Sgl_isinexact_to_unsigned(src,src_exponent)) {
			inexact = TRUE;
			
			switch (Rounding_mode()) {
			case ROUNDPLUS:
				Duint_increment(resultp1,resultp2);
				break;
			case ROUNDMINUS: 
				break;
			case ROUNDNEAREST:
				if (Sgl_isone_roundbit(src,src_exponent) &&
				    (Sgl_isone_stickybit(src,src_exponent) || 
				     Duint_isone_lowp2(resultp2))) {
					Duint_increment(resultp1,resultp2);
				}
				break;
			}
		}
	} else {
		Duint_setzero(resultp1,resultp2);

		
		if (Sgl_isnotzero_exponentmantissa(src)) {
			inexact = TRUE;
			
			switch (Rounding_mode()) {
			case ROUNDPLUS:
				if (Sgl_iszero_sign(src)) {
					Duint_increment(resultp1,resultp2);
				}
				break;
			case ROUNDMINUS:
				if (Sgl_isone_sign(src)) {
					resultp1 = resultp2 = 0;
					if (Is_invalidtrap_enabled()) {
						return(INVALIDEXCEPTION);
					}
					Set_invalidflag();
					inexact = FALSE;
				}
				break;
			case ROUNDNEAREST:
				if (src_exponent == -1 &&
				    Sgl_isnotzero_mantissa(src)) {
					if (Sgl_isone_sign(src)) {
						resultp1 = 0;
						resultp2 = 0;
						if (Is_invalidtrap_enabled()) {
							return(INVALIDEXCEPTION);
						}
						Set_invalidflag();
						inexact = FALSE;
					}
					else Duint_increment(resultp1,resultp2);
				}
			}
		}
	}
	Duint_copytoptr(resultp1,resultp2,dstptr);
	if (inexact) {
		if (Is_inexacttrap_enabled()) return(INEXACTEXCEPTION);
		else Set_inexactflag();
	}
	return(NOEXCEPTION);
}

int
dbl_to_sgl_fcnvfu (dbl_floating_point * srcptr, unsigned int *nullptr,
		   unsigned int *dstptr, unsigned int *status)
{
	register unsigned int srcp1, srcp2, result;
	register int src_exponent;
	register boolean inexact = FALSE;

	Dbl_copyfromptr(srcptr,srcp1,srcp2);
	src_exponent = Dbl_exponent(srcp1) - DBL_BIAS;

	if (src_exponent > SGL_FX_MAX_EXP + 1) {
		if (Dbl_isone_sign(srcp1)) {
			result = 0;
		} else {
			result = 0xffffffff;
		}
		if (Is_invalidtrap_enabled()) {
			return(INVALIDEXCEPTION);
		}
		Set_invalidflag();
		*dstptr = result;
		return(NOEXCEPTION);
	}
	if (src_exponent >= 0) {
		if (Dbl_isone_sign(srcp1)) {
			result = 0;
			if (Is_invalidtrap_enabled()) {
				return(INVALIDEXCEPTION);
			}
			Set_invalidflag();
			*dstptr = result;
			return(NOEXCEPTION);
		}
		Dbl_clear_signexponent_set_hidden(srcp1);
		Suint_from_dbl_mantissa(srcp1,srcp2,src_exponent,result);

		
		if (Dbl_isinexact_to_unsigned(srcp1,srcp2,src_exponent)) {
			inexact = TRUE;
			
			switch (Rounding_mode()) {
			case ROUNDPLUS:
			     result++;
			     break;
			case ROUNDMINUS: 
			     break;
			case ROUNDNEAREST:
			     if(Dbl_isone_roundbit(srcp1,srcp2,src_exponent) &&
				(Dbl_isone_stickybit(srcp1,srcp2,src_exponent)||
				 result&1))
				   result++;
			     break;
			}
			
			if (result == 0) {
				result = 0xffffffff;
				if (Is_invalidtrap_enabled()) {
					return(INVALIDEXCEPTION);
				}
				Set_invalidflag();
				*dstptr = result;
				return(NOEXCEPTION);
			}
		}
	} else {
		result = 0;

		
		if (Dbl_isnotzero_exponentmantissa(srcp1,srcp2)) {
			inexact = TRUE;
			
			switch (Rounding_mode()) {
			case ROUNDPLUS:
				if (Dbl_iszero_sign(srcp1)) result++;
				break;
			case ROUNDMINUS:
				if (Dbl_isone_sign(srcp1)) {
					result = 0;
					if (Is_invalidtrap_enabled()) {
						return(INVALIDEXCEPTION);
					}
					Set_invalidflag();
					inexact = FALSE;
				}
				break;
			case ROUNDNEAREST:
				if (src_exponent == -1 &&
				    Dbl_isnotzero_mantissa(srcp1,srcp2))
					if (Dbl_isone_sign(srcp1)) {
						result = 0;
						if (Is_invalidtrap_enabled()) {
							return(INVALIDEXCEPTION);
						}
						Set_invalidflag();
						inexact = FALSE;
					}
					else result++;
			}
		}
	}
	*dstptr = result;
	if (inexact) {
		if (Is_inexacttrap_enabled()) return(INEXACTEXCEPTION);
		else Set_inexactflag();
	}
	return(NOEXCEPTION);
}

int
dbl_to_dbl_fcnvfu (dbl_floating_point * srcptr, unsigned int *nullptr,
		   dbl_unsigned * dstptr, unsigned int *status)
{
	register int src_exponent;
	register unsigned int srcp1, srcp2, resultp1, resultp2;
	register boolean inexact = FALSE;

	Dbl_copyfromptr(srcptr,srcp1,srcp2);
	src_exponent = Dbl_exponent(srcp1) - DBL_BIAS;

	if (src_exponent > DBL_FX_MAX_EXP + 1) {
		if (Dbl_isone_sign(srcp1)) {
			resultp1 = resultp2 = 0;
		} else {
			resultp1 = resultp2 = 0xffffffff;
		}
		if (Is_invalidtrap_enabled()) {
			return(INVALIDEXCEPTION);
		}
		Set_invalidflag();
    		Duint_copytoptr(resultp1,resultp2,dstptr);
		return(NOEXCEPTION);
	}
 
	if (src_exponent >= 0) {
		if (Dbl_isone_sign(srcp1)) {
			resultp1 = resultp2 = 0;
			if (Is_invalidtrap_enabled()) {
				return(INVALIDEXCEPTION);
			}
			Set_invalidflag();
    			Duint_copytoptr(resultp1,resultp2,dstptr);
			return(NOEXCEPTION);
		}
		Dbl_clear_signexponent_set_hidden(srcp1);
		Duint_from_dbl_mantissa(srcp1,srcp2,src_exponent,resultp1,
		  resultp2);

		
		if (Dbl_isinexact_to_unsigned(srcp1,srcp2,src_exponent)) {
			inexact = TRUE;
			
			switch (Rounding_mode()) {
			case ROUNDPLUS:
				Duint_increment(resultp1,resultp2);
				break;
			case ROUNDMINUS: 
				break;
			case ROUNDNEAREST:
				if(Dbl_isone_roundbit(srcp1,srcp2,src_exponent))
				  if(Dbl_isone_stickybit(srcp1,srcp2,src_exponent) || 
				     Duint_isone_lowp2(resultp2))
					Duint_increment(resultp1,resultp2);
			} 
		}
	} else {
		Duint_setzero(resultp1,resultp2);

		
		if (Dbl_isnotzero_exponentmantissa(srcp1,srcp2)) {
			inexact = TRUE;
			
			switch (Rounding_mode()) {
			case ROUNDPLUS:
				if (Dbl_iszero_sign(srcp1)) {
					Duint_increment(resultp1,resultp2);
				}
				break;
			case ROUNDMINUS:
				if (Dbl_isone_sign(srcp1)) {
					resultp1 = resultp2 = 0;
					if (Is_invalidtrap_enabled()) {
						return(INVALIDEXCEPTION);
					}
					Set_invalidflag();
					inexact = FALSE;
				}
				break;
			case ROUNDNEAREST:
				if (src_exponent == -1 &&
				    Dbl_isnotzero_mantissa(srcp1,srcp2))
					if (Dbl_iszero_sign(srcp1)) {
						Duint_increment(resultp1,resultp2);
					} else {
						resultp1 = 0;
						resultp2 = 0;
						if (Is_invalidtrap_enabled()) {
							return(INVALIDEXCEPTION);
						}
						Set_invalidflag();
						inexact = FALSE;
					}
			}
		}
	}
	Duint_copytoptr(resultp1,resultp2,dstptr);
	if (inexact) {
		if (Is_inexacttrap_enabled()) return(INEXACTEXCEPTION);
		else Set_inexactflag();
	}
	return(NOEXCEPTION);
}

