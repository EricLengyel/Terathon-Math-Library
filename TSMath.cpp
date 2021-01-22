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


#include "TSMath.h"


using namespace Terathon;


namespace
{
	uint32 hex_7F800000		= 0x7F800000;
	uint32 hex_FF800000		= 0xFF800000;
	uint32 hex_00800000		= 0x00800000;
	uint32 hex_7F7FFFFF		= 0x7F7FFFFF;
}


const float Math::infinity =			(float&) hex_7F800000;
const float Math::minus_infinity =		(float&) hex_FF800000;
const float Math::min_float =			(float&) hex_00800000;
const float Math::max_float =			(float&) hex_7F7FFFFF;

const float Math::tau =					6.2831853071795864769252867665590F;
const float Math::two_tau =				12.566370614359172953850573533118F;
const float Math::three_tau_over_4 =	4.7123889803846898576939650749193F;
const float Math::three_tau_over_8 =	2.3561944901923449288469825374596F;
const float Math::tau_over_2 =			3.1415926535897932384626433832795F;
const float Math::tau_over_3 =			2.0943951023931954923084289221863F;
const float Math::two_tau_over_3 =		4.1887902047863909846168578443727F;
const float Math::tau_over_4 =			1.5707963267948966192313216916398F;
const float Math::tau_over_6 =			1.0471975511965977461542144610932F;
const float Math::tau_over_8 =			0.78539816339744830961566084581988F;
const float Math::tau_over_12 =			0.52359877559829887307710723054658F;
const float Math::tau_over_16 =			0.39269908169872415480783042290994F;
const float Math::tau_over_24 =			0.26179938779914943653855361527329F;
const float Math::tau_over_40 =			0.15707963267948966192313216916398F;
const float Math::one_over_tau =		1.0F / Math::tau;
const float Math::two_over_tau =		2.0F / Math::tau;
const float Math::four_over_tau =		4.0F / Math::tau;
const float Math::one_over_two_tau =	0.5F / Math::tau;

const float Math::pi =					3.1415926535897932384626433832795F;
const float Math::two_pi =				6.2831853071795864769252867665590F;
const float Math::four_pi =				12.566370614359172953850573533118F;
const float Math::three_pi_over_2 =		4.7123889803846898576939650749193F;
const float Math::three_pi_over_4 = 	2.3561944901923449288469825374596F;
const float Math::two_pi_over_3 =		2.0943951023931954923084289221863F;
const float Math::four_pi_over_3 = 		4.1887902047863909846168578443727F;
const float Math::pi_over_2 =			1.5707963267948966192313216916398F;
const float Math::pi_over_3 =			1.0471975511965977461542144610932F;
const float Math::pi_over_4 =			0.78539816339744830961566084581988F;
const float Math::pi_over_6 =			0.52359877559829887307710723054658F;
const float Math::pi_over_8 =			0.39269908169872415480783042290994F;
const float Math::pi_over_12 =			0.26179938779914943653855361527329F;
const float Math::pi_over_20 =			0.15707963267948966192313216916398F;
const float Math::one_over_pi =			1.0F / Math::pi;
const float Math::one_over_two_pi =		0.5F / Math::pi;
const float Math::one_over_four_pi =	0.25F / Math::pi;

const float Math::sqrt_2 =				1.4142135623730950488016887242097F;
const float Math::sqrt_2_over_2 =		0.70710678118654752440084436210485F;
const float Math::sqrt_2_over_3 =		0.47140452079103168293389624140323F;
const float Math::sqrt_3 =				1.7320508075688772935274463415059F;
const float Math::sqrt_3_over_2 =		0.86602540378443864676372317075294F;
const float Math::sqrt_3_over_3 =		0.57735026918962576450914878050196F;

const float Math::ln_2 =				0.69314718055994530941723212145818F;
const float Math::one_over_ln_2 =		1.4426950408889634073599246810019F;
const float Math::ln_10 =				2.3025850929940456840179914546844F;
const float Math::one_over_ln_10 =		0.43429448190325182765112891891661F;
const float Math::ln_256 =				5.5451774444795624753378569716654F;


alignas(128) const uint32 Terathon::Math::trigTable[256][2] =
{
	{0x3F800000, 0x00000000}, {0x3F7FEC43, 0x3CC90AB0}, {0x3F7FB10F, 0x3D48FB30}, {0x3F7F4E6D, 0x3D96A905}, {0x3F7EC46D, 0x3DC8BD36}, {0x3F7E1324, 0x3DFAB273}, {0x3F7D3AAC, 0x3E164083}, {0x3F7C3B28, 0x3E2F10A3},
	{0x3F7B14BE, 0x3E47C5C2}, {0x3F79C79D, 0x3E605C13}, {0x3F7853F8, 0x3E78CFCD}, {0x3F76BA07, 0x3E888E94}, {0x3F74FA0B, 0x3E94A031}, {0x3F731447, 0x3EA09AE5}, {0x3F710908, 0x3EAC7CD4}, {0x3F6ED89E, 0x3EB8442A},
	{0x3F6C835E, 0x3EC3EF16}, {0x3F6A09A6, 0x3ECF7BCB}, {0x3F676BD8, 0x3EDAE880}, {0x3F64AA59, 0x3EE63375}, {0x3F61C597, 0x3EF15AEA}, {0x3F5EBE05, 0x3EFC5D28}, {0x3F5B941A, 0x3F039C3D}, {0x3F584853, 0x3F08F59B},
	{0x3F54DB31, 0x3F0E39DA}, {0x3F514D3D, 0x3F13682B}, {0x3F4D9F02, 0x3F187FC0}, {0x3F49D112, 0x3F1D7FD2}, {0x3F45E403, 0x3F22679A}, {0x3F41D870, 0x3F273656}, {0x3F3DAEF9, 0x3F2BEB4A}, {0x3F396842, 0x3F3085BB},
	{0x3F3504F3, 0x3F3504F3}, {0x3F3085BA, 0x3F396842}, {0x3F2BEB49, 0x3F3DAEFA}, {0x3F273655, 0x3F41D871}, {0x3F226799, 0x3F45E403}, {0x3F1D7FD1, 0x3F49D112}, {0x3F187FC0, 0x3F4D9F02}, {0x3F13682A, 0x3F514D3D},
	{0x3F0E39D9, 0x3F54DB32}, {0x3F08F59B, 0x3F584853}, {0x3F039C3C, 0x3F5B941B}, {0x3EFC5D27, 0x3F5EBE05}, {0x3EF15AE7, 0x3F61C598}, {0x3EE63374, 0x3F64AA59}, {0x3EDAE881, 0x3F676BD8}, {0x3ECF7BC9, 0x3F6A09A7},
	{0x3EC3EF15, 0x3F6C835E}, {0x3EB84427, 0x3F6ED89E}, {0x3EAC7CD3, 0x3F710908}, {0x3EA09AE2, 0x3F731448}, {0x3E94A030, 0x3F74FA0B}, {0x3E888E93, 0x3F76BA07}, {0x3E78CFC8, 0x3F7853F8}, {0x3E605C12, 0x3F79C79D},
	{0x3E47C5BC, 0x3F7B14BF}, {0x3E2F10A0, 0x3F7C3B28}, {0x3E164085, 0x3F7D3AAC}, {0x3DFAB26C, 0x3F7E1324}, {0x3DC8BD35, 0x3F7EC46D}, {0x3D96A8FB, 0x3F7F4E6D}, {0x3D48FB29, 0x3F7FB10F}, {0x3CC90A7E, 0x3F7FEC43},
	{0x00000000, 0x3F800000}, {0xBCC90A7E, 0x3F7FEC43}, {0xBD48FB29, 0x3F7FB10F}, {0xBD96A8FB, 0x3F7F4E6D}, {0xBDC8BD35, 0x3F7EC46D}, {0xBDFAB26C, 0x3F7E1324}, {0xBE164085, 0x3F7D3AAC}, {0xBE2F10A0, 0x3F7C3B28},
	{0xBE47C5BC, 0x3F7B14BF}, {0xBE605C12, 0x3F79C79D}, {0xBE78CFC8, 0x3F7853F8}, {0xBE888E93, 0x3F76BA07}, {0xBE94A030, 0x3F74FA0B}, {0xBEA09AE2, 0x3F731448}, {0xBEAC7CD3, 0x3F710908}, {0xBEB84427, 0x3F6ED89E},
	{0xBEC3EF15, 0x3F6C835E}, {0xBECF7BC9, 0x3F6A09A7}, {0xBEDAE881, 0x3F676BD8}, {0xBEE63374, 0x3F64AA59}, {0xBEF15AE7, 0x3F61C598}, {0xBEFC5D27, 0x3F5EBE05}, {0xBF039C3C, 0x3F5B941B}, {0xBF08F59B, 0x3F584853},
	{0xBF0E39D9, 0x3F54DB32}, {0xBF13682A, 0x3F514D3D}, {0xBF187FC0, 0x3F4D9F02}, {0xBF1D7FD1, 0x3F49D112}, {0xBF226799, 0x3F45E403}, {0xBF273655, 0x3F41D871}, {0xBF2BEB49, 0x3F3DAEFA}, {0xBF3085BA, 0x3F396842},
	{0xBF3504F3, 0x3F3504F3}, {0xBF396842, 0x3F3085BB}, {0xBF3DAEF9, 0x3F2BEB4A}, {0xBF41D870, 0x3F273656}, {0xBF45E403, 0x3F22679A}, {0xBF49D112, 0x3F1D7FD2}, {0xBF4D9F02, 0x3F187FC0}, {0xBF514D3D, 0x3F13682B},
	{0xBF54DB31, 0x3F0E39DA}, {0xBF584853, 0x3F08F59B}, {0xBF5B941A, 0x3F039C3D}, {0xBF5EBE05, 0x3EFC5D28}, {0xBF61C597, 0x3EF15AEA}, {0xBF64AA59, 0x3EE63375}, {0xBF676BD8, 0x3EDAE880}, {0xBF6A09A6, 0x3ECF7BCB},
	{0xBF6C835E, 0x3EC3EF16}, {0xBF6ED89E, 0x3EB8442A}, {0xBF710908, 0x3EAC7CD4}, {0xBF731447, 0x3EA09AE5}, {0xBF74FA0B, 0x3E94A031}, {0xBF76BA07, 0x3E888E94}, {0xBF7853F8, 0x3E78CFCD}, {0xBF79C79D, 0x3E605C13},
	{0xBF7B14BE, 0x3E47C5C2}, {0xBF7C3B28, 0x3E2F10A3}, {0xBF7D3AAC, 0x3E164083}, {0xBF7E1324, 0x3DFAB273}, {0xBF7EC46D, 0x3DC8BD36}, {0xBF7F4E6D, 0x3D96A905}, {0xBF7FB10F, 0x3D48FB30}, {0xBF7FEC43, 0x3CC90AB0},
	{0xBF800000, 0x00000000}, {0xBF7FEC43, 0xBCC90AB0}, {0xBF7FB10F, 0xBD48FB30}, {0xBF7F4E6D, 0xBD96A905}, {0xBF7EC46D, 0xBDC8BD36}, {0xBF7E1324, 0xBDFAB273}, {0xBF7D3AAC, 0xBE164083}, {0xBF7C3B28, 0xBE2F10A3},
	{0xBF7B14BE, 0xBE47C5C2}, {0xBF79C79D, 0xBE605C13}, {0xBF7853F8, 0xBE78CFCD}, {0xBF76BA07, 0xBE888E94}, {0xBF74FA0B, 0xBE94A031}, {0xBF731447, 0xBEA09AE5}, {0xBF710908, 0xBEAC7CD4}, {0xBF6ED89E, 0xBEB8442A},
	{0xBF6C835E, 0xBEC3EF16}, {0xBF6A09A6, 0xBECF7BCB}, {0xBF676BD8, 0xBEDAE880}, {0xBF64AA59, 0xBEE63375}, {0xBF61C597, 0xBEF15AEA}, {0xBF5EBE05, 0xBEFC5D28}, {0xBF5B941A, 0xBF039C3D}, {0xBF584853, 0xBF08F59B},
	{0xBF54DB31, 0xBF0E39DA}, {0xBF514D3D, 0xBF13682B}, {0xBF4D9F02, 0xBF187FC0}, {0xBF49D112, 0xBF1D7FD2}, {0xBF45E403, 0xBF22679A}, {0xBF41D870, 0xBF273656}, {0xBF3DAEF9, 0xBF2BEB4A}, {0xBF396842, 0xBF3085BB},
	{0xBF3504F3, 0xBF3504F3}, {0xBF3085BA, 0xBF396842}, {0xBF2BEB49, 0xBF3DAEFA}, {0xBF273655, 0xBF41D871}, {0xBF226799, 0xBF45E403}, {0xBF1D7FD1, 0xBF49D112}, {0xBF187FC0, 0xBF4D9F02}, {0xBF13682A, 0xBF514D3D},
	{0xBF0E39D9, 0xBF54DB32}, {0xBF08F59B, 0xBF584853}, {0xBF039C3C, 0xBF5B941B}, {0xBEFC5D27, 0xBF5EBE05}, {0xBEF15AE7, 0xBF61C598}, {0xBEE63374, 0xBF64AA59}, {0xBEDAE881, 0xBF676BD8}, {0xBECF7BC9, 0xBF6A09A7},
	{0xBEC3EF15, 0xBF6C835E}, {0xBEB84427, 0xBF6ED89E}, {0xBEAC7CD3, 0xBF710908}, {0xBEA09AE2, 0xBF731448}, {0xBE94A030, 0xBF74FA0B}, {0xBE888E93, 0xBF76BA07}, {0xBE78CFC8, 0xBF7853F8}, {0xBE605C12, 0xBF79C79D},
	{0xBE47C5BC, 0xBF7B14BF}, {0xBE2F10A0, 0xBF7C3B28}, {0xBE164085, 0xBF7D3AAC}, {0xBDFAB26C, 0xBF7E1324}, {0xBDC8BD35, 0xBF7EC46D}, {0xBD96A8FB, 0xBF7F4E6D}, {0xBD48FB29, 0xBF7FB10F}, {0xBCC90A7E, 0xBF7FEC43},
	{0x00000000, 0xBF800000}, {0x3CC90A7E, 0xBF7FEC43}, {0x3D48FB29, 0xBF7FB10F}, {0x3D96A8FB, 0xBF7F4E6D}, {0x3DC8BD35, 0xBF7EC46D}, {0x3DFAB26C, 0xBF7E1324}, {0x3E164085, 0xBF7D3AAC}, {0x3E2F10A0, 0xBF7C3B28},
	{0x3E47C5BC, 0xBF7B14BF}, {0x3E605C12, 0xBF79C79D}, {0x3E78CFC8, 0xBF7853F8}, {0x3E888E93, 0xBF76BA07}, {0x3E94A030, 0xBF74FA0B}, {0x3EA09AE2, 0xBF731448}, {0x3EAC7CD3, 0xBF710908}, {0x3EB84427, 0xBF6ED89E},
	{0x3EC3EF15, 0xBF6C835E}, {0x3ECF7BC9, 0xBF6A09A7}, {0x3EDAE881, 0xBF676BD8}, {0x3EE63374, 0xBF64AA59}, {0x3EF15AE7, 0xBF61C598}, {0x3EFC5D27, 0xBF5EBE05}, {0x3F039C3C, 0xBF5B941B}, {0x3F08F59B, 0xBF584853},
	{0x3F0E39D9, 0xBF54DB32}, {0x3F13682A, 0xBF514D3D}, {0x3F187FC0, 0xBF4D9F02}, {0x3F1D7FD1, 0xBF49D112}, {0x3F226799, 0xBF45E403}, {0x3F273655, 0xBF41D871}, {0x3F2BEB49, 0xBF3DAEFA}, {0x3F3085BA, 0xBF396842},
	{0x3F3504F3, 0xBF3504F3}, {0x3F396842, 0xBF3085BB}, {0x3F3DAEF9, 0xBF2BEB4A}, {0x3F41D870, 0xBF273656}, {0x3F45E403, 0xBF22679A}, {0x3F49D112, 0xBF1D7FD2}, {0x3F4D9F02, 0xBF187FC0}, {0x3F514D3D, 0xBF13682B},
	{0x3F54DB31, 0xBF0E39DA}, {0x3F584853, 0xBF08F59B}, {0x3F5B941A, 0xBF039C3D}, {0x3F5EBE05, 0xBEFC5D28}, {0x3F61C597, 0xBEF15AEA}, {0x3F64AA59, 0xBEE63375}, {0x3F676BD8, 0xBEDAE880}, {0x3F6A09A6, 0xBECF7BCB},
	{0x3F6C835E, 0xBEC3EF16}, {0x3F6ED89E, 0xBEB8442A}, {0x3F710908, 0xBEAC7CD4}, {0x3F731447, 0xBEA09AE5}, {0x3F74FA0B, 0xBE94A031}, {0x3F76BA07, 0xBE888E94}, {0x3F7853F8, 0xBE78CFCD}, {0x3F79C79D, 0xBE605C13},
	{0x3F7B14BE, 0xBE47C5C2}, {0x3F7C3B28, 0xBE2F10A3}, {0x3F7D3AAC, 0xBE164083}, {0x3F7E1324, 0xBDFAB273}, {0x3F7EC46D, 0xBDC8BD36}, {0x3F7F4E6D, 0xBD96A905}, {0x3F7FB10F, 0xBD48FB30}, {0x3F7FEC43, 0xBCC90AB0}
};


namespace
{
	struct TrigPair
	{
		float	x;
		float	y;
	};

	inline const TrigPair *GetTrigTable(void)
	{
		return (reinterpret_cast<const TrigPair *>(Math::trigTable));
	}
}


#ifdef TERATHON_NO_SIMD

	float Terathon::Floor(const float& x)
	{
		if (Fabs(x) < 8388608.0F)
		{
			float r = x - 8388608.0F + 8388608.0F + 8388608.0F - 8388608.0F;
			return ((r > x) ? r - 1.0F : r);
		}

		return (x);
	}

	float Terathon::Ceil(const float& x)
	{
		if (Fabs(x) < 8388608.0F)
		{
			float r = x - 8388608.0F + 8388608.0F + 8388608.0F - 8388608.0F;
			return ((r < x) ? r + 1.0F : r);
		}

		return (x);
	}

#endif


float Terathon::Sqrt(float x)
{
	#ifdef TERATHON_SSE

		float	result;

		vec_float v = _mm_load_ss(&x);
		vec_float mask = _mm_cmplt_ss(v, VecLoadScalarConstant<0x00800000>());

		vec_float r = _mm_rsqrt_ss(v);
		r = _mm_mul_ss(_mm_sub_ss(VecLoadScalarConstant<0x40400000>(), _mm_mul_ss(v, _mm_mul_ss(r, r))), _mm_mul_ss(r, VecLoadScalarConstant<0x3F000001>()));

		_mm_store_ss(&result, _mm_mul_ss(_mm_andnot_ps(mask, r), v));
		return (result);

	#else

		if (x < Math::min_float)
		{
			return (0.0F);
		}

		uint32 i = 0x5F375A86 - (asuint(x) >> 1);
		float r = asfloat(i);
		r = (0.5F * r) * (3.0F - x * r * r);
		r = (0.5F * r) * (3.0F - x * r * r);
		return (r * x);

	#endif
}

float Terathon::InverseSqrt(float x)
{
	#ifdef TERATHON_SSE

		float	result;

		vec_float v = _mm_load_ss(&x);
		vec_float mask = _mm_cmplt_ss(v, VecLoadScalarConstant<0x00800000>());

		vec_float r = _mm_rsqrt_ss(v);
		r = _mm_mul_ss(_mm_sub_ss(VecLoadScalarConstant<0x40400000>(), _mm_mul_ss(v, _mm_mul_ss(r, r))), _mm_mul_ss(r, VecLoadScalarConstant<0x3F000001>()));

		_mm_store_ss(&result, _mm_or_ps(_mm_andnot_ps(mask, r), _mm_and_ps(mask, VecLoadScalarConstant<0x7F800000>())));
		return (result);

	#else

		if (x < Math::min_float)
		{
			return (Math::infinity);
		}

		uint32 i = 0x5F375A86 - (asuint(x) >> 1);
		float r = asfloat(i);
		r = (0.5F * r) * (3.0F - x * r * r);
		r = (0.5F * r) * (3.0F - x * r * r);
		return (r);

	#endif
}

float Terathon::Sin(float x)
{
	#ifndef TERATHON_NO_SIMD

		float	result;

		vec_float b = VecMulScalar(VecAndc(VecLoadScalar(&x), VecFloatGetMinusZero()), VecLoadScalarConstant<0x4222F983>());
		vec_float i = VecPositiveFloorScalar(b);
		b = VecMulScalar(VecSubScalar(b, i), VecLoadScalarConstant<0x3CC90FDB>());

		const TrigPair& cossin = GetTrigTable()[VecTruncateConvert(i) & 255];
		vec_float cosine_alpha = VecLoadScalar(&cossin.x);
		vec_float sine_alpha = VecLoadScalar(&cossin.y);

		vec_float b2 = VecMulScalar(b, b);
		vec_float sine_beta = VecNmsubScalar(VecMulScalar(b, b2), VecNmsubScalar(b2, VecLoadScalarConstant<0x3E2AAAAB>(), VecLoadScalarConstant<0x3C088889>()), b);
		vec_float cosine_beta = VecNmsubScalar(b2, VecNmsub(b2, VecLoadScalarConstant<0x3D2AAAAB>(), VecLoadScalarConstant<0x3F000000>()), VecLoadScalarConstant<0x3F800000>());

		vec_float sine = VecMaddScalar(sine_alpha, cosine_beta, VecMulScalar(cosine_alpha, sine_beta));

		VecStoreX((x < 0.0F) ? VecNegate(sine) : sine, &result);
		return (result);

	#else

		float b = Fabs(x) * 40.74366543F;	// 256 / tau
		float i = PositiveFloor(b);
		b = (b - i) * 0.0245436926F;		// tau / 256

		const TrigPair& cossin_alpha = GetTrigTable()[int32(i) & 255];

		float b2 = b * b;
		float sine_beta = b - b * b2 * (0.1666666667F - b2 * 0.008333333333F);
		float cosine_beta = 1.0F - b2 * (0.5F - b2 * 0.04166666667F);

		float sine = cossin_alpha.y * cosine_beta + cossin_alpha.x * sine_beta;
		return ((x < 0.0F) ? -sine : sine);

	#endif
}

float Terathon::Cos(float x)
{
	#ifndef TERATHON_NO_SIMD

		float	result;

		vec_float b = VecMulScalar(VecAndc(VecLoadScalar(&x), VecFloatGetMinusZero()), VecLoadScalarConstant<0x4222F983>());
		vec_float i = VecPositiveFloorScalar(b);
		b = VecMulScalar(VecSubScalar(b, i), VecLoadScalarConstant<0x3CC90FDB>());

		const TrigPair& cossin = GetTrigTable()[VecTruncateConvert(i) & 255];
		vec_float cosine_alpha = VecLoadScalar(&cossin.x);
		vec_float sine_alpha = VecLoadScalar(&cossin.y);

		vec_float b2 = VecMulScalar(b, b);
		vec_float sine_beta = VecNmsubScalar(VecMulScalar(b, b2), VecNmsubScalar(b2, VecLoadScalarConstant<0x3E2AAAAB>(), VecLoadScalarConstant<0x3C088889>()), b);
		vec_float cosine_beta = VecNmsubScalar(b2, VecNmsub(b2, VecLoadScalarConstant<0x3D2AAAAB>(), VecLoadScalarConstant<0x3F000000>()), VecLoadScalarConstant<0x3F800000>());

		VecStoreX(VecSubScalar(VecMulScalar(cosine_alpha, cosine_beta), VecMulScalar(sine_alpha, sine_beta)), &result);
		return (result);

	#else

		float b = Fabs(x) * 40.74366543F;	// 256 / tau
		float i = PositiveFloor(b);
		b = (b - i) * 0.0245436926F;		// tau / 256

		const TrigPair& cossin_alpha = GetTrigTable()[int32(i) & 255];

		float b2 = b * b;
		float sine_beta = b - b * b2 * (0.1666666667F - b2 * 0.008333333333F);
		float cosine_beta = 1.0F - b2 * (0.5F - b2 * 0.04166666667F);

		return (cossin_alpha.x * cosine_beta - cossin_alpha.y * sine_beta);

	#endif
}

float Terathon::Tan(float x)
{
	#ifndef TERATHON_NO_SIMD

		float	cosine, sine;

		vec_float b = VecMulScalar(VecAndc(VecLoadScalar(&x), VecFloatGetMinusZero()), VecLoadScalarConstant<0x4222F983>());
		vec_float i = VecPositiveFloorScalar(b);
		b = VecMulScalar(VecSubScalar(b, i), VecLoadScalarConstant<0x3CC90FDB>());

		const TrigPair& cossin = GetTrigTable()[VecTruncateConvert(i) & 255];
		vec_float cosine_alpha = VecLoadScalar(&cossin.x);
		vec_float sine_alpha = VecLoadScalar(&cossin.y);

		vec_float b2 = VecMulScalar(b, b);
		vec_float sine_beta = VecNmsubScalar(VecMulScalar(b, b2), VecNmsubScalar(b2, VecLoadScalarConstant<0x3E2AAAAB>(), VecLoadScalarConstant<0x3C088889>()), b);
		vec_float cosine_beta = VecNmsubScalar(b2, VecNmsub(b2, VecLoadScalarConstant<0x3D2AAAAB>(), VecLoadScalarConstant<0x3F000000>()), VecLoadScalarConstant<0x3F800000>());

		VecStoreX(VecMaddScalar(sine_alpha, cosine_beta, VecMulScalar(cosine_alpha, sine_beta)), &sine);
		VecStoreX(VecSubScalar(VecMulScalar(cosine_alpha, cosine_beta), VecMulScalar(sine_alpha, sine_beta)), &cosine);

		float result = sine / cosine;
		return ((x < 0.0F) ? -result : result);

	#else

		float b = Fabs(x) * 40.74366543F;	// 256 / tau
		float i = PositiveFloor(b);
		b = (b - i) * 0.0245436926F;		// tau / 256

		const TrigPair& cossin_alpha = GetTrigTable()[int32(i) & 255];

		float b2 = b * b;
		float sine_beta = b - b * b2 * (0.1666666667F - b2 * 0.008333333333F);
		float cosine_beta = 1.0F - b2 * (0.5F - b2 * 0.04166666667F);

		float sine = cossin_alpha.y * cosine_beta + cossin_alpha.x * sine_beta;
		float cosine = cossin_alpha.x * cosine_beta - cossin_alpha.y * sine_beta;

		float result = sine / cosine;
		return ((x < 0.0F) ? -result : result);

	#endif
}

void Terathon::CosSin(float x, float *c, float *s)
{
	#ifndef TERATHON_NO_SIMD

		vec_float b = VecMulScalar(VecAndc(VecLoadScalar(&x), VecFloatGetMinusZero()), VecLoadScalarConstant<0x4222F983>());
		vec_float i = VecPositiveFloorScalar(b);
		b = VecMulScalar(VecSubScalar(b, i), VecLoadScalarConstant<0x3CC90FDB>());

		const TrigPair& cossin = GetTrigTable()[VecTruncateConvert(i) & 255];
		vec_float cosine_alpha = VecLoadScalar(&cossin.x);
		vec_float sine_alpha = VecLoadScalar(&cossin.y);

		vec_float b2 = VecMulScalar(b, b);
		vec_float sine_beta = VecNmsubScalar(VecMulScalar(b, b2), VecNmsubScalar(b2, VecLoadScalarConstant<0x3E2AAAAB>(), VecLoadScalarConstant<0x3C088889>()), b);
		vec_float cosine_beta = VecNmsubScalar(b2, VecNmsub(b2, VecLoadScalarConstant<0x3D2AAAAB>(), VecLoadScalarConstant<0x3F000000>()), VecLoadScalarConstant<0x3F800000>());

		vec_float sine = VecMaddScalar(sine_alpha, cosine_beta, VecMulScalar(cosine_alpha, sine_beta));
		vec_float cosine = VecSubScalar(VecMulScalar(cosine_alpha, cosine_beta), VecMulScalar(sine_alpha, sine_beta));

		VecStoreX(cosine, c);
		VecStoreX((x < 0.0F) ? VecNegate(sine) : sine, s);

	#else

		float b = Fabs(x) * 40.74366543F;	// 256 / tau
		float i = PositiveFloor(b);
		b = (b - i) * 0.0245436926F;		// tau / 256

		const TrigPair& cossin_alpha = GetTrigTable()[int32(i) & 255];

		float b2 = b * b;
		float sine_beta = b - b * b2 * (0.1666666667F - b2 * 0.008333333333F);
		float cosine_beta = 1.0F - b2 * (0.5F - b2 * 0.04166666667F);

		*c = cossin_alpha.x * cosine_beta - cossin_alpha.y * sine_beta;
		float sine = cossin_alpha.y * cosine_beta + cossin_alpha.x * sine_beta;
		*s = (x < 0.0F) ? -sine : sine;

	#endif
}

float Terathon::Arcsin(float y)
{
	return (Arctan(y * InverseSqrt(1.0F - y * y)));
}

float Terathon::Arccos(float x)
{
	float r = Arctan(Sqrt(1.0F - x * x) / x);
	return ((x < 0.0F) ? r + Math::tau_over_2 : r);
}

float Terathon::Arctan(float x)
{
	// Values of arctan(n / 64) for integers n in the range [0, 64].

	alignas(64) static const uint32 table[65] =
	{
		0x00000000, 0x3C7FFAAB, 0x3CFFEAAE, 0x3D3FDC0C, 0x3D7FAADE, 0x3D9FACF8, 0x3DBF70C1, 0x3DDF1CF6,
		0x3DFEADD5, 0x3E0F0FD8, 0x3E1EB777, 0x3E2E4C09, 0x3E3DCBDA, 0x3E4D3547, 0x3E5C86BB, 0x3E6BBEAF,
		0x3E7ADBB0, 0x3E84EE2D, 0x3E8C5FAD, 0x3E93C1B9, 0x3E9B13BA, 0x3EA25522, 0x3EA9856D, 0x3EB0A420,
		0x3EB7B0CA, 0x3EBEAB02, 0x3EC5926A, 0x3ECC66AA, 0x3ED32776, 0x3ED9D489, 0x3EE06DA6, 0x3EE6F29A,
		0x3EED6338, 0x3EF3BF5C, 0x3EFA06E8, 0x3F001CE4, 0x3F032BF5, 0x3F0630A3, 0x3F092AED, 0x3F0C1AD4,
		0x3F0F005D, 0x3F11DB8F, 0x3F14AC73, 0x3F177314, 0x3F1A2F81, 0x3F1CE1C9, 0x3F1F89FE, 0x3F222833,
		0x3F24BC7D, 0x3F2746F3, 0x3F29C7AC, 0x3F2C3EC1, 0x3F2EAC4C, 0x3F311069, 0x3F336B32, 0x3F35BCC5,
		0x3F38053E, 0x3F3A44BC, 0x3F3C7B5E, 0x3F3EA941, 0x3F40CE86, 0x3F42EB4B, 0x3F44FFB0, 0x3F470BD5, 0x3F490FDB
	};

	// arctan(a) = arctan(b) + arctan((a - b) / (ab + 1))

	float a = Fabs(x);
	if (a <= 1.0F)
	{
		float b = a * 64.0F;
		float i = PositiveFloor(b);
		b = i * 0.015625F;

		float arctan_b = reinterpret_cast<const float *>(table)[int32(i)];
		float c = (a - b) / (a * b + 1.0F);
		float c2 = c * c;

		float arctan_c = c * (1.0F - c2 * (0.3333333333F + c2 * (0.2F - c2 * 0.1428571429F)));
		a = arctan_b + arctan_c;
	}
	else
	{
		// arctan(a) = tau / 4 - arctan(1 / a)

		a = 1.0F / a;
		float b = a * 64.0F;
		float i = PositiveFloor(b);
		b = i * 0.015625F;

		float arctan_b = reinterpret_cast<const float *>(table)[int32(i)];
		float c = (a - b) / (a * b + 1.0F);
		float c2 = c * c;

		float arctan_c = c * (1.0F - c2 * (0.3333333333F + c2 * (0.2F - c2 * 0.1428571429F)));
		a = Math::tau_over_4 - (arctan_b + arctan_c);
	}

	return ((x < 0.0F) ? -a : a);
}

float Terathon::Arctan(float y, float x)
{
	if (Fabs(y) > Math::min_float)
	{
		if (Fabs(x) > Math::min_float)
		{
			float r = Arctan(y / x);

			if (x < 0.0F)
			{
				if (y >= 0.0F)
				{
					r += Math::tau_over_2;
				}
				else
				{
					r -= Math::tau_over_2;
				}
			}

			return (r);
		}

		return ((y < 0.0F) ? -Math::tau_over_4 : Math::tau_over_4);
	}

	return ((x < 0.0F) ? Math::tau_over_2 : 0.0F);
}

float Terathon::Exp(float x)
{
	// Values of exp(n) for integers n in the range [-88, 91].

	alignas(64) static const uint32 table[180] =
	{
		0x00000000, 0x00B33687, 0x01739362, 0x022586E0, 0x02E0F96D, 0x0398E2CB, 0x044FCB22, 0x050D35D7,
		0x05BFECBA, 0x06826D27, 0x07314490, 0x07F0EE94, 0x08A3BAF0, 0x095E884F, 0x0A1739FB, 0x0ACD89C1,
		0x0B8BAD78, 0x0C3DD771, 0x0D0102BF, 0x0DAF5800, 0x0E6E511E, 0x0F21F3FE, 0x0FDC1DF9, 0x109595C7,
		0x114B4EA4, 0x120A295C, 0x12BBC7F1, 0x137F388B, 0x142D70C9, 0x14EBBAEC, 0x15A031FC, 0x1659BA5A,
		0x1713F623, 0x17C919B9, 0x1888A975, 0x1939BE2B, 0x19FC7361, 0x1AAB8EDC, 0x1B692BEB, 0x1C1E74DD,
		0x1CD75D5D, 0x1D925B02, 0x1E46EAF1, 0x1F072DBA, 0x1FB7BA0F, 0x2079B5EA, 0x2129B229, 0x21E6A405,
		0x229CBC92, 0x235506F2, 0x2410C457, 0x24C4C239, 0x2585B61D, 0x2635BB8D, 0x26F7000F, 0x27A7DAA4,
		0x28642328, 0x291B090F, 0x29D2B706, 0x2A8F3216, 0x2B429F81, 0x2C044295, 0x2CB3C295, 0x2D7451BD,
		0x2E26083C, 0x2EE1A93F, 0x2F995A46, 0x30506D87, 0x310DA433, 0x31C082B8, 0x3282D314, 0x3331CF19,
		0x33F1AADE, 0x34A43AE5, 0x355F3638, 0x3617B02A, 0x36CE2A62, 0x378C1AA1, 0x383E6BCE, 0x39016791,
		0x39AFE108, 0x3A6F0B5D, 0x3B227290, 0x3BDCC9FF, 0x3C960AAE, 0x3D4BED86, 0x3E0A9555, 0x3EBC5AB2,
		0x3F800000, 0x402DF854, 0x40EC7326, 0x41A0AF2E, 0x425A6481, 0x431469C5, 0x43C9B6E3, 0x44891443,
		0x453A4F54, 0x45FD38AC, 0x46AC14EE, 0x4769E224, 0x481EF0B3, 0x48D805AD, 0x4992CD62, 0x4A478665,
		0x4B07975F, 0x4BB849A4, 0x4C7A7910, 0x4D2A36C8, 0x4DE75844, 0x4E9D3710, 0x4F55AD6E, 0x5011357A,
		0x50C55BFE, 0x51861E9D, 0x52364993, 0x52F7C118, 0x53A85DD2, 0x5464D572, 0x551B8238, 0x55D35BB3,
		0x568FA1FE, 0x5743379A, 0x5804A9F1, 0x58B44F11, 0x597510AD, 0x5A2689FE, 0x5AE2599A, 0x5B99D21F,
		0x5C51106A, 0x5D0E12E4, 0x5DC1192B, 0x5E833952, 0x5F325A0E, 0x5FF267BB, 0x60A4BB3E, 0x615FE4A9,
		0x621826B5, 0x62CECB81, 0x638C881F, 0x643F009E, 0x6501CCB3, 0x65B06A7B, 0x666FC62D, 0x6722F184,
		0x67DD768B, 0x68967FF0, 0x694C8CE5, 0x6A0B01A3, 0x6ABCEDE5, 0x6B806408, 0x6C2E804A, 0x6CED2BEF,
		0x6DA12CC1, 0x6E5B0F2E, 0x6F14DDC1, 0x6FCA5487, 0x70897F64, 0x713AE0EE, 0x71FDFE91, 0x72AC9B6A,
		0x736A98EC, 0x741F6CE9, 0x74D8AE7F, 0x7593401C, 0x76482254, 0x77080156, 0x77B8D9AA, 0x787B3CCF,
		0x792ABBCE, 0x79E80D11, 0x7A9DB1ED, 0x7B56546B, 0x7C11A6F5, 0x7CC5F63B, 0x7D86876D, 0x7E36D809,
		0x7EF882B7, 0x7F800000
	};

	float f = Floor(x);
	int32 i = int32(f) + 88;
	if (i > 0)
	{
		x -= f;

		float r = 1.0F / 362880.0F;
		r = r * x + 1.0F / 40320.0F;
		r = r * x + 1.0F / 5040.0F;
		r = r * x + 1.0F / 720.0F;
		r = r * x + 1.0F / 120.0F;
		r = r * x + 1.0F / 24.0F;
		r = r * x + 1.0F / 6.0F;
		r = r * x + 0.5F;

		return ((r * (x * x) + (x + 1.0F)) * reinterpret_cast<const float *>(table)[(i < 179) ? i : 179]);
	}

	return (0.0F);
}

float Terathon::Log(float x)
{
	int32 i = reinterpret_cast<int32&>(x);
	if (i > 0)
	{
		int32 e = (i >> 23) - 127;
		i = (i & 0x007FFFFF) | 0x3F800000;
		float f = asfloat(i);
		float y = (f - 1.0F) / (f + 1.0F);
		float z = y * y;

		float r = 1.0F / 13.0F;
		r = r * z + 1.0F / 11.0F;
		r = r * z + 1.0F / 9.0F;
		r = r * z + 1.0F / 7.0F;
		r = r * z + 1.0F / 5.0F;
		r = r * z + 1.0F / 3.0F;
		r = r * z + 1.0F;

		return (r * (y * 2.0F) + float(e) * Math::ln_2);
	}
	else if (x >= 0.0F)
	{
		return (Math::minus_infinity);
	}

	static const uint32 nan = 0x7FFFFFFF;
	return (asfloat(nan));
}
