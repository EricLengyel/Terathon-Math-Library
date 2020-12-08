//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2021, Terathon Software LLC
//
// This software is licensed under the GNU General Public License version 3.
// Separate proprietary licenses are available from Terathon Software.
//
// THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
// EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. 
//


#ifndef TSMath_h
#define TSMath_h


//# \component	Math Library
//# \prefix		Math/


#ifndef TERATHON_NO_SIMD

	#include "TSSimd.h"

#else

	#include "TSPlatform.h"

#endif


#define TERATHON_MATH 1


namespace Terathon
{
	inline float Fabs(const float& x)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecAndc(VecLoadScalar(&x), VecFloatGetMinusZero()), &result);
			return (result);

		#else

			return ((x < 0.0F) ? -x : x);

		#endif
	}

	inline float Fnabs(const float& x)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecOr(VecLoadScalar(&x), VecFloatGetMinusZero()), &result);
			return (result);

		#else

			return ((x > 0.0F) ? -x : x);

		#endif
	}

	inline float Fsgn(const float& x)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecFsgn(VecLoadScalar(&x)), &result);
			return (result);

		#else

			return ((x < 0.0F) ? -1.0F : ((x > 0.0F) ? 1.0F : 0.0F));

		#endif
	}

	inline float Fnsgn(const float& x)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecFnsgn(VecLoadScalar(&x)), &result);
			return (result);

		#else

			return ((x < 0.0F) ? 1.0F : ((x > 0.0F) ? -1.0F : 0.0F));

		#endif
	}

	inline float NonzeroFsgn(const float& x)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecNonzeroFsgn(VecLoadScalar(&x)), &result);
			return (result);

		#else

			return ((x < 0.0F) ? -1.0F : 1.0F);

		#endif
	}

	inline float NonzeroFnsgn(const float& x)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecNonzeroFnsgn(VecLoadScalar(&x)), &result);
			return (result);

		#else

			return ((x < 0.0F) ? 1.0F : -1.0F);

		#endif
	}

	inline float Fmin(const float& x, const float& y)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecMinScalar(VecLoadScalar(&x), VecLoadScalar(&y)), &result);
			return (result);

		#else

			return ((x < y) ? x : y);

		#endif
	}

	inline float Fmin(const float& x, const float& y, const float& z)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecMinScalar(VecMinScalar(VecLoadScalar(&x), VecLoadScalar(&y)), VecLoadScalar(&z)), &result);
			return (result);

		#else

			return (Fmin(Fmin(x, y), z));

		#endif
	}

	inline float Fmin(const float& x, const float& y, const float& z, const float& w)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecMinScalar(VecMinScalar(VecLoadScalar(&x), VecLoadScalar(&y)), VecMinScalar(VecLoadScalar(&z), VecLoadScalar(&w))), &result);
			return (result);

		#else

			return (Fmin(Fmin(x, y), Fmin(z, w)));

		#endif
	}

	inline float Fmax(const float& x, const float& y)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecMaxScalar(VecLoadScalar(&x), VecLoadScalar(&y)), &result);
			return (result);

		#else

			return ((x < y) ? y : x);

		#endif
	}

	inline float Fmax(const float& x, const float& y, const float& z)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecMaxScalar(VecMaxScalar(VecLoadScalar(&x), VecLoadScalar(&y)), VecLoadScalar(&z)), &result);
			return (result);

		#else

			return (Fmax(Fmax(x, y), z));

		#endif
	}

	inline float Fmax(const float& x, const float& y, const float& z, const float& w)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecMaxScalar(VecMaxScalar(VecLoadScalar(&x), VecLoadScalar(&y)), VecMaxScalar(VecLoadScalar(&z), VecLoadScalar(&w))), &result);
			return (result);

		#else

			return (Fmax(Fmax(x, y), Fmax(z, w)));

		#endif
	}

	inline float FminZero(const float& x)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecMinScalar(VecLoadScalar(&x), VecFloatGetZero()), &result);
			return (result);

		#else

			return ((x < 0.0F) ? x : 0.0F);

		#endif
	}

	inline float FmaxZero(const float& x)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecMaxScalar(VecLoadScalar(&x), VecFloatGetZero()), &result);
			return (result);

		#else

			return ((x < 0.0F) ? 0.0F : x);

		#endif
	}

	inline float Saturate(const float& x)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecMinScalar(VecMaxScalar(VecLoadScalar(&x), VecFloatGetZero()), VecLoadVectorConstant<0x3F800000>()), &result);
			return (result);

		#else

			float f = (x < 0.0F) ? 0.0F : x;
			return ((f < 1.0F) ? f : 1.0F);

		#endif
	}

	inline float Clamp(const float& x, const float& y, const float& z)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecMinScalar(VecMaxScalar(VecLoadScalar(&x), VecLoadScalar(&y)), VecLoadScalar(&z)), &result);
			return (result);

		#else

			float f = (x < y) ? y : x;
			return ((f < z) ? f : z);

		#endif
	}

	#ifndef TERATHON_NO_SIMD

		inline float Floor(const float& x)
		{
			float	result;

			VecStoreX(VecFloorScalar(VecLoadScalar(&x)), &result);
			return (result);
		}

		inline float Ceil(const float& x)
		{
			float	result;

			VecStoreX(VecCeilScalar(VecLoadScalar(&x)), &result);
			return (result);
		}

	#else

		TERATHON_API float Floor(const float& x);
		TERATHON_API float Ceil(const float& x);

	#endif

	inline float PositiveFloor(const float& x)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecPositiveFloorScalar(VecLoadScalar(&x)), &result);
			return (result);

		#else

			return (Floor(x));

		#endif
	}

	inline float NegativeFloor(const float& x)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecNegativeFloorScalar(VecLoadScalar(&x)), &result);
			return (result);

		#else

			return (Floor(x));

		#endif
	}

	inline float PositiveCeil(const float& x)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecPositiveCeilScalar(VecLoadScalar(&x)), &result);
			return (result);

		#else

			return (Ceil(x));

		#endif
	}

	inline float NegativeCeil(const float& x)
	{
		#ifndef TERATHON_NO_SIMD

			float	result;

			VecStoreX(VecNegativeCeilScalar(VecLoadScalar(&x)), &result);
			return (result);

		#else

			return (Ceil(x));

		#endif
	}

	inline void FloorCeil(const float& x, float *f, float *c)
	{
		#ifndef TERATHON_NO_SIMD

			vec_float		vf, vc;

			VecFloorCeilScalar(VecLoadScalar(&x), &vf, &vc);
			VecStoreX(vf, f);
			VecStoreX(vc, c);

		#else

			*f = Floor(x);
			*c = Ceil(x);

		#endif
	}

	inline void PositiveFloorCeil(const float& x, float *f, float *c)
	{
		#ifndef TERATHON_NO_SIMD

			vec_float		vf, vc;

			VecPositiveFloorCeilScalar(VecLoadScalar(&x), &vf, &vc);
			VecStoreX(vf, f);
			VecStoreX(vc, c);

		#else

			*f = Floor(x);
			*c = Ceil(x);

		#endif
	}

	inline void NegativeFloorCeil(const float& x, float *f, float *c)
	{
		#ifndef TERATHON_NO_SIMD

			vec_float		vf, vc;

			VecNegativeFloorCeilScalar(VecLoadScalar(&x), &vf, &vc);
			VecStoreX(vf, f);
			VecStoreX(vc, c);

		#else

			*f = Floor(x);
			*c = Ceil(x);

		#endif
	}

	inline float Frac(const float& x)
	{
		return (x - Floor(x));
	}

	inline float PositiveFrac(const float& x)
	{
		return (x - PositiveFloor(x));
	}

	inline float NegativeFrac(const float& x)
	{
		return (x - NegativeFloor(x));
	}


	TERATHON_API float Sqrt(float x);
	TERATHON_API float InverseSqrt(float x);

	TERATHON_API float Sin(float x);
	TERATHON_API float Cos(float x);
	TERATHON_API float Tan(float x);
	TERATHON_API void CosSin(float x, float *c, float *s);

	TERATHON_API float Arcsin(float y);
	TERATHON_API float Arccos(float x);
	TERATHON_API float Arctan(float x);
	TERATHON_API float Arctan(float y, float x);

	TERATHON_API float Exp(float x);
	TERATHON_API float Log(float x);

	inline float Pow(float base, float exponent)
	{
		return (Exp(Log(base) * exponent));
	}


	namespace Math
	{
		TERATHON_API extern const float infinity;
		TERATHON_API extern const float minus_infinity;
		TERATHON_API extern const float min_float;
		TERATHON_API extern const float max_float;

		TERATHON_API extern const float tau;
		TERATHON_API extern const float two_tau;
		TERATHON_API extern const float three_tau_over_4;
		TERATHON_API extern const float three_tau_over_8;
		TERATHON_API extern const float tau_over_2;
		TERATHON_API extern const float tau_over_3;
		TERATHON_API extern const float two_tau_over_3;
		TERATHON_API extern const float tau_over_4;
		TERATHON_API extern const float tau_over_6;
		TERATHON_API extern const float tau_over_8;
		TERATHON_API extern const float tau_over_12;
		TERATHON_API extern const float tau_over_16;
		TERATHON_API extern const float tau_over_24;
		TERATHON_API extern const float tau_over_40;
		TERATHON_API extern const float one_over_tau;
		TERATHON_API extern const float two_over_tau;
		TERATHON_API extern const float four_over_tau;
		TERATHON_API extern const float one_over_two_tau;

		TERATHON_API extern const float pi;
		TERATHON_API extern const float two_pi;
		TERATHON_API extern const float four_pi;
		TERATHON_API extern const float three_pi_over_2;
		TERATHON_API extern const float three_pi_over_4;
		TERATHON_API extern const float two_pi_over_3;
		TERATHON_API extern const float four_pi_over_3;
		TERATHON_API extern const float pi_over_2;
		TERATHON_API extern const float pi_over_3;
		TERATHON_API extern const float pi_over_4;
		TERATHON_API extern const float pi_over_6;
		TERATHON_API extern const float pi_over_8;
		TERATHON_API extern const float pi_over_12;
		TERATHON_API extern const float pi_over_20;
		TERATHON_API extern const float one_over_pi;
		TERATHON_API extern const float one_over_two_pi;
		TERATHON_API extern const float one_over_four_pi;

		TERATHON_API extern const float sqrt_2;
		TERATHON_API extern const float sqrt_2_over_2;
		TERATHON_API extern const float sqrt_2_over_3;
		TERATHON_API extern const float sqrt_3;
		TERATHON_API extern const float sqrt_3_over_2;
		TERATHON_API extern const float sqrt_3_over_3;

		TERATHON_API extern const float ln_2;
		TERATHON_API extern const float one_over_ln_2;
		TERATHON_API extern const float ln_10;
		TERATHON_API extern const float one_over_ln_10;
		TERATHON_API extern const float ln_256;


		TERATHON_API extern const uint32 trigTable[256][2];
	}
}


#endif
