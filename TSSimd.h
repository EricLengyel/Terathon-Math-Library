//
// This file is part of the Terathon Common Library, by Eric Lengyel.
// Copyright 1999-2021, Terathon Software LLC
//
// This software is licensed under the GNU General Public License version 3.
// Separate proprietary licenses are available from Terathon Software.
//
// THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
// EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. 
//


#ifndef TSSimd_h
#define TSSimd_h


#include "TSPlatform.h"


#if defined(_M_X64) || defined(_M_IX86) || defined(__x86_64__) || defined(__SSE__)

	#define TERATHON_SSE 1

#endif

#if defined(__AVX__)

	#define TERATHON_AVX 1

#endif


#ifdef TERATHON_NO_SYSTEM

	#ifdef TERATHON_SSE

		typedef union __declspec(intrin_type) __declspec(align(16)) __m128
		{
			float				m128_f32[4];
			unsigned __int64	m128_u64[2];
			__int8				m128_i8[16];
			__int16				m128_i16[8];
			__int32				m128_i32[4];
			__int64				m128_i64[2];
			unsigned __int8		m128_u8[16];
			unsigned __int16	m128_u16[8];
			unsigned __int32	m128_u32[4];
		} __m128;

		typedef union __declspec(intrin_type) __declspec(align(16)) __m128i
		{
			__int8				m128i_i8[16];
			__int16				m128i_i16[8];
			__int32				m128i_i32[4];
			__int64				m128i_i64[2];
			unsigned __int8		m128i_u8[16];
			unsigned __int16	m128i_u16[8];
			unsigned __int32	m128i_u32[4];
			unsigned __int64	m128i_u64[2];
		} __m128i;

		#define _MM_SHUFFLE(fp3,fp2,fp1,fp0) (((fp3) << 6) | ((fp2) << 4) | ((fp1) << 2) | ((fp0)))

	#endif

	#ifdef TERATHON_AVX

		typedef union __declspec(intrin_type) __declspec(align(32)) __m256
		{
			float				m256_f32[8];
		} __m256;

		typedef union __declspec(intrin_type) __declspec(align(32)) __m256i
		{
			__int8				m256i_i8[32];
			__int16				m256i_i16[16];
			__int32				m256i_i32[8];
			__int64				m256i_i64[4];
			unsigned __int8		m256i_u8[32];
			unsigned __int16	m256i_u16[16];
			unsigned __int32	m256i_u32[8];
			unsigned __int64	m256i_u64[4];
		} __m256i;

	#endif

	extern "C"
	{
		#ifdef TERATHON_SSE

			extern __m128 _mm_add_ss(__m128, __m128);
			extern __m128 _mm_add_ps(__m128, __m128);
			extern __m128 _mm_sub_ss(__m128, __m128);
			extern __m128 _mm_sub_ps(__m128, __m128);
			extern __m128 _mm_mul_ss(__m128, __m128);
			extern __m128 _mm_mul_ps(__m128, __m128);
			extern __m128 _mm_div_ss(__m128, __m128);
			extern __m128 _mm_div_ps(__m128, __m128);
			extern __m128 _mm_rsqrt_ss(__m128);
			extern __m128 _mm_rsqrt_ps(__m128);
			extern __m128 _mm_min_ss(__m128, __m128);
			extern __m128 _mm_min_ps(__m128, __m128);
			extern __m128 _mm_max_ss(__m128, __m128);
			extern __m128 _mm_max_ps(__m128, __m128);
			extern __m128 _mm_and_ps(__m128, __m128);
			extern __m128 _mm_andnot_ps(__m128, __m128);
			extern __m128 _mm_or_ps(__m128, __m128);
			extern __m128 _mm_xor_ps(__m128, __m128);
			extern __m128 _mm_cmpeq_ps(__m128, __m128);
			extern __m128 _mm_cmplt_ss(__m128, __m128);
			extern __m128 _mm_cmplt_ps(__m128, __m128);
			extern int _mm_comieq_ss(__m128, __m128);
			extern int _mm_comilt_ss(__m128, __m128);
			extern int _mm_comigt_ss(__m128, __m128);
			extern int _mm_cvtt_ss2si(__m128);
			extern __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
			extern __m128 _mm_setzero_ps(void);
			extern __m128 _mm_load_ss(const float *);
			extern __m128 _mm_load_ps(const float *);
			extern __m128 _mm_loadu_ps(const float *);
			extern void _mm_store_ss(float *, __m128);
			extern void _mm_store_ps(float *, __m128);
			extern void _mm_storeu_ps(float *, __m128);
			extern unsigned int _mm_getcsr(void);
			extern void _mm_setcsr(unsigned int);

			extern __m128i _mm_setzero_si128(void);
			extern __m128i _mm_load_si128(const __m128i *);
			extern __m128i _mm_loadu_si128(const __m128i *);
			extern void _mm_store_si128(__m128i *, __m128i);
			extern void _mm_storeu_si128(__m128i *, __m128i);
			extern int _mm_cvtsi128_si32(__m128i);
			extern __m128i _mm_shuffle_epi32(__m128i, int);
			extern __m128i _mm_shufflehi_epi16(__m128i, int);
			extern __m128i _mm_shufflelo_epi16(__m128i, int);
			extern __m128i _mm_packs_epi16(__m128i, __m128i);
			extern __m128i _mm_packs_epi32(__m128i, __m128i);
			extern __m128i _mm_packus_epi16(__m128i, __m128i);
			extern __m128i _mm_unpacklo_epi8(__m128i, __m128i);
			extern __m128i _mm_unpackhi_epi8(__m128i, __m128i);
			extern __m128i _mm_unpacklo_epi16(__m128i, __m128i);
			extern __m128i _mm_unpackhi_epi16(__m128i, __m128i);
			extern __m128i _mm_cmplt_epi8(__m128i, __m128i);
			extern __m128i _mm_cmplt_epi16(__m128i, __m128i);
			extern __m128 _mm_cvtepi32_ps(__m128i);
			extern __m128i _mm_cvtps_epi32(__m128);
			extern __m128i _mm_add_epi32(__m128i, __m128i);
			extern __m128i _mm_sub_epi32(__m128i, __m128i);

		#endif

		#ifdef TERATHON_AVX

			extern __m256 __cdecl _mm256_add_ps(__m256, __m256);
			extern __m256 __cdecl _mm256_sub_ps(__m256, __m256);
			extern __m256 __cdecl _mm256_mul_ps(__m256, __m256);
			extern __m256 __cdecl _mm256_div_ps(__m256, __m256);
			extern __m256 __cdecl _mm256_rsqrt_ps(__m256);
			extern __m256 __cdecl _mm256_min_ps(__m256, __m256);
			extern __m256 __cdecl _mm256_max_ps(__m256, __m256);
			extern __m256 __cdecl _mm256_and_ps(__m256, __m256);
			extern __m256 __cdecl _mm256_andnot_ps(__m256, __m256);
			extern __m256 __cdecl _mm256_or_ps(__m256, __m256);
			extern __m256 __cdecl _mm256_xor_ps(__m256, __m256);
			extern __m256 __cdecl _mm256_cmp_ps(__m256, __m256, int);
			extern __m256 __cdecl _mm256_permute_ps(__m256, int);
			extern __m256 __cdecl _mm256_permute2f128_ps(__m256, __m256, int);
			extern __m256 __cdecl _mm256_insertf128_ps(__m256, __m128, int);
			extern __m128 __cdecl _mm256_castps256_ps128(__m256);
			extern __m256 __cdecl _mm256_castps128_ps256(__m128);
			extern __m256 __cdecl _mm256_setzero_ps(void);
			extern __m256 __cdecl _mm256_load_ps(const float *);
			extern __m256 __cdecl _mm256_broadcast_ss(const float *);
			extern void __cdecl _mm256_store_ps(float *, __m256);

		#endif
	}

#else

	#ifdef TERATHON_SSE

		#include <emmintrin.h>

	#endif

	#ifdef TERATHON_AVX

		#include <immintrin.h>

	#endif

#endif


namespace Terathon
{
	#ifdef TERATHON_SSE

		typedef __m128 vec_float;
		typedef __m128i vec_int8;
		typedef __m128i vec_int16;
		typedef __m128i vec_int32;
		typedef __m128i vec_uint8;
		typedef __m128i vec_uint16;
		typedef __m128i vec_uint32;

	#endif

	#ifdef TERATHON_AVX

		typedef __m256 exv_float;
		typedef __m256i exv_int8;
		typedef __m256i exv_int16;
		typedef __m256i exv_int32;
		typedef __m256i exv_uint8;
		typedef __m256i exv_uint16;
		typedef __m256i exv_uint32;

	#endif


	inline vec_float VecFloatGetZero(void)
	{
		#ifdef TERATHON_SSE

			return (_mm_setzero_ps());

		#endif
	}

	inline vec_float VecFloatGetMinusZero(void)
	{
		#ifdef TERATHON_SSE

			alignas(16) static const uint32 float_80000000[4] = {0x80000000, 0x80000000, 0x80000000, 0x80000000};
			return (_mm_load_ps(reinterpret_cast<const float *>(float_80000000)));

		#endif
	}

	template <uint32 value>
	inline vec_float VecLoadVectorConstant(void)
	{
		#ifdef TERATHON_SSE

			alignas(16) static const uint32 k[4] = {value, value, value, value};
			return (_mm_load_ps(reinterpret_cast<const float *>(k)));

		#endif
	}

	template <uint32 value>
	inline vec_float VecLoadScalarConstant(void)
	{
		#ifdef TERATHON_SSE

			static const uint32 k = value;
			return (_mm_load_ss(reinterpret_cast<const float *>(&k)));

		#endif
	}

	inline vec_float VecSmearX(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			return (_mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0)));

		#endif
	}

	inline vec_float VecSmearY(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			return (_mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1)));

		#endif
	}

	inline vec_float VecSmearZ(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			return (_mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2)));

		#endif
	}

	inline vec_float VecSmearW(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			return (_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 3, 3, 3)));

		#endif
	}

	inline vec_float VecLoad(const float *ptr)
	{
		#ifdef TERATHON_SSE

			return (_mm_load_ps(ptr));

		#endif
	}

	inline vec_float VecLoadUnaligned(const float *ptr)
	{
		#ifdef TERATHON_SSE

			return (_mm_loadu_ps(ptr));

		#endif
	}

	inline vec_float VecLoadScalar(const float *ptr)
	{
		#ifdef TERATHON_SSE

			return (_mm_load_ss(ptr));

		#endif
	}

	inline vec_float VecLoadSmearScalar(const float *ptr)
	{
		#ifdef TERATHON_SSE

			vec_float v = _mm_load_ss(ptr);
			return (_mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0)));

		#endif
	}

	inline void VecStore(const vec_float& v, float *ptr)
	{
		#ifdef TERATHON_SSE

			_mm_store_ps(ptr, v);

		#endif
	}

	inline void VecStoreUnaligned(const vec_float& v, float *ptr)
	{
		#ifdef TERATHON_SSE

			_mm_storeu_ps(ptr, v);

		#endif
	}

	inline void VecStoreX(const vec_float& v, float *ptr)
	{
		#ifdef TERATHON_SSE4

			*ptr = v[0];

		#elif defined(TERATHON_SSE)

			_mm_store_ss(ptr, v);

		#endif
	}

	inline void VecStoreY(const vec_float& v, float *ptr)
	{
		#ifdef TERATHON_SSE4

			*ptr = v[1];

		#elif defined(TERATHON_SSE)

			_mm_store_ss(ptr, _mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1)));

		#endif
	}

	inline void VecStoreZ(const vec_float& v, float *ptr)
	{
		#ifdef TERATHON_SSE4

			*ptr = v[2];

		#elif defined(TERATHON_SSE)

			_mm_store_ss(ptr, _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2)));

		#endif
	}

	inline void VecStoreW(const vec_float& v, float *ptr)
	{
		#ifdef TERATHON_SSE4

			*ptr = v[3];

		#elif defined(TERATHON_SSE)

			_mm_store_ss(ptr, _mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 3, 3, 3)));

		#endif
	}

	inline void VecStore3D(const vec_float& v, float *ptr)
	{
		#ifdef TERATHON_SSE4

			ptr[0] = v[0];
			ptr[1] = v[1];
			ptr[2] = v[2];

		#elif defined(TERATHON_SSE)

			_mm_store_ss(&ptr[0], v);
			_mm_store_ss(&ptr[1], _mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1)));
			_mm_store_ss(&ptr[2], _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2)));

		#endif
	}

	inline int32 VecTruncateConvert(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			return (_mm_cvtt_ss2si(v));

		#endif
	}

	inline vec_float VecNegate(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			return (_mm_sub_ps(_mm_setzero_ps(), v));

		#endif
	}

	inline vec_float VecMin(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_min_ps(v1, v2));

		#endif
	}

	inline vec_float VecMinScalar(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_min_ss(v1, v2));

		#endif
	}

	inline vec_float VecMax(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_max_ps(v1, v2));

		#endif
	}

	inline vec_float VecMaxScalar(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_max_ss(v1, v2));

		#endif
	}

	inline vec_float VecAdd(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_add_ps(v1, v2));

		#endif
	}

	inline vec_float VecAddScalar(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_add_ss(v1, v2));

		#endif
	}

	inline vec_float VecSub(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_sub_ps(v1, v2));

		#endif
	}

	inline vec_float VecSubScalar(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_sub_ss(v1, v2));

		#endif
	}

	inline vec_float VecMul(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_mul_ps(v1, v2));

		#endif
	}

	inline vec_float VecMulScalar(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_mul_ss(v1, v2));

		#endif
	}

	inline vec_float VecMadd(const vec_float& v1, const vec_float& v2, const vec_float& v3)
	{
		#ifdef TERATHON_SSE

			return (_mm_add_ps(_mm_mul_ps(v1, v2), v3));

		#endif
	}

	inline vec_float VecMaddScalar(const vec_float& v1, const vec_float& v2, const vec_float& v3)
	{
		#ifdef TERATHON_SSE

			return (_mm_add_ss(_mm_mul_ss(v1, v2), v3));

		#endif
	}

	inline vec_float VecNmsub(const vec_float& v1, const vec_float& v2, const vec_float& v3)
	{
		#ifdef TERATHON_SSE

			return (_mm_sub_ps(v3, _mm_mul_ps(v1, v2)));

		#endif
	}

	inline vec_float VecNmsubScalar(const vec_float& v1, const vec_float& v2, const vec_float& v3)
	{
		#ifdef TERATHON_SSE

			return (_mm_sub_ss(v3, _mm_mul_ss(v1, v2)));

		#endif
	}

	inline vec_float VecDiv(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_div_ps(v1, v2));

		#endif
	}

	inline vec_float VecDivScalar(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_div_ss(v1, v2));

		#endif
	}

	inline vec_float VecAnd(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_and_ps(v1, v2));

		#endif
	}

	inline vec_float VecAndc(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_andnot_ps(v2, v1));

		#endif
	}

	inline vec_float VecOr(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_or_ps(v1, v2));

		#endif
	}

	inline vec_float VecXor(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_xor_ps(v1, v2));

		#endif
	}

	inline vec_float VecSelect(const vec_float& v1, const vec_float& v2, const vec_float& mask)
	{
		#ifdef TERATHON_SSE

			return (_mm_or_ps(_mm_andnot_ps(mask, v1), _mm_and_ps(mask, v2)));

		#endif
	}

	inline vec_float VecMaskCmpeq(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_cmpeq_ps(v1, v2));

		#endif
	}

	inline vec_float VecMaskCmplt(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_cmplt_ps(v1, v2));

		#endif
	}

	inline vec_float VecMaskCmpgt(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_cmplt_ps(v2, v1));

		#endif
	}

	inline bool VecCmpeqScalar(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_comieq_ss(v1, v2));

		#endif
	}

	inline bool VecCmpltScalar(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_comilt_ss(v1, v2));

		#endif
	}

	inline bool VecCmpgtScalar(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_comigt_ss(v1, v2));

		#endif
	}

	inline bool VecCmpltAny3D(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return ((_mm_comilt_ss(v1, v2) | _mm_comilt_ss(VecSmearY(v1), VecSmearY(v2)) | _mm_comilt_ss(VecSmearZ(v1), VecSmearZ(v2))) != 0);

		#endif
	}

	inline bool VecCmpgtAny3D(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			return ((_mm_comigt_ss(v1, v2) | _mm_comigt_ss(VecSmearY(v1), VecSmearY(v2)) | _mm_comigt_ss(VecSmearZ(v1), VecSmearZ(v2))) != 0);

		#endif
	}

	inline vec_float VecInverseSqrt(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			const vec_float three = VecLoadVectorConstant<0x40400000>();
			const vec_float half = VecLoadVectorConstant<0x3F000000>();

			vec_float f = _mm_rsqrt_ps(v);
			return (_mm_mul_ps(_mm_mul_ps(_mm_sub_ps(three, _mm_mul_ps(v, _mm_mul_ps(f, f))), f), half));

		#endif
	}

	inline vec_float VecInverseSqrtScalar(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			const vec_float three = VecLoadVectorConstant<0x40400000>();
			const vec_float half = VecLoadVectorConstant<0x3F000000>();

			vec_float f = _mm_rsqrt_ss(v);
			return (_mm_mul_ss(_mm_mul_ss(_mm_sub_ss(three, _mm_mul_ss(v, _mm_mul_ss(f, f))), f), half));

		#endif
	}

	inline vec_float VecSqrt(const vec_float& v)
	{
		vec_float mask = VecMaskCmpeq(v, VecFloatGetZero());
		return (VecAndc(VecMul(VecInverseSqrt(v), v), mask));
	}

	inline vec_float VecSqrtScalar(const vec_float& v)
	{
		vec_float mask = VecMaskCmpeq(v, VecFloatGetZero());
		return (VecAndc(VecMulScalar(VecInverseSqrtScalar(v), v), mask));
	}

	inline vec_float VecFloor(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				return (_mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ps(_mm_add_ps(_mm_add_ps(_mm_sub_ps(v, two23), two23), two23), two23);
				result = _mm_sub_ps(result, _mm_and_ps(one, _mm_cmplt_ps(v, result)));

				vec_float mask = _mm_cmplt_ps(two23, _mm_andnot_ps(VecFloatGetMinusZero(), v));
				return (_mm_or_ps(_mm_andnot_ps(mask, result), _mm_and_ps(mask, v)));

			#endif

		#endif
	}

	inline vec_float VecFloorScalar(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				return (_mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ss(_mm_add_ss(_mm_add_ss(_mm_sub_ss(v, two23), two23), two23), two23);
				result = _mm_sub_ss(result, _mm_and_ps(one, _mm_cmplt_ps(v, result)));

				vec_float mask = _mm_cmplt_ps(two23, _mm_andnot_ps(VecFloatGetMinusZero(), v));
				return (_mm_or_ps(_mm_andnot_ps(mask, result), _mm_and_ps(mask, v)));

			#endif

		#endif
	}

	inline vec_float VecPositiveFloor(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				return (_mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ps(_mm_add_ps(v, two23), two23);
				return (_mm_sub_ps(result, _mm_and_ps(one, _mm_cmplt_ps(v, result))));

			#endif

		#endif
	}

	inline vec_float VecPositiveFloorScalar(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				return (_mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ss(_mm_add_ss(v, two23), two23);
				return (_mm_sub_ss(result, _mm_and_ps(one, _mm_cmplt_ps(v, result))));

			#endif

		#endif
	}

	inline vec_float VecNegativeFloor(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				return (_mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_add_ps(_mm_sub_ps(v, two23), two23);
				return (_mm_sub_ps(result, _mm_and_ps(one, _mm_cmplt_ps(v, result))));

			#endif

		#endif
	}

	inline vec_float VecNegativeFloorScalar(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				return (_mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_add_ss(_mm_sub_ss(v, two23), two23);
				return (_mm_sub_ss(result, _mm_and_ps(one, _mm_cmplt_ps(v, result))));

			#endif

		#endif
	}

	inline vec_float VecCeil(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				return (_mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ps(_mm_add_ps(_mm_add_ps(_mm_sub_ps(v, two23), two23), two23), two23);
				result = _mm_add_ps(result, _mm_and_ps(one, _mm_cmplt_ps(result, v)));

				vec_float mask = _mm_cmplt_ps(two23, _mm_andnot_ps(VecFloatGetMinusZero(), v));
				return (_mm_or_ps(_mm_andnot_ps(mask, result), _mm_and_ps(mask, v)));

			#endif

		#endif
	}

	inline vec_float VecCeilScalar(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				return (_mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ss(_mm_add_ss(_mm_add_ss(_mm_sub_ss(v, two23), two23), two23), two23);
				result = _mm_add_ss(result, _mm_and_ps(one, _mm_cmplt_ps(result, v)));

				vec_float mask = _mm_cmplt_ps(two23, _mm_andnot_ps(VecFloatGetMinusZero(), v));
				return (_mm_or_ps(_mm_andnot_ps(mask, result), _mm_and_ps(mask, v)));

			#endif

		#endif
	}

	inline vec_float VecPositiveCeil(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				return (_mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ps(_mm_add_ps(v, two23), two23);
				return (_mm_add_ps(result, _mm_and_ps(one, _mm_cmplt_ps(result, v))));

			#endif

		#endif
	}

	inline vec_float VecPositiveCeilScalar(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				return (_mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ss(_mm_add_ss(v, two23), two23);
				return (_mm_add_ss(result, _mm_and_ps(one, _mm_cmplt_ps(result, v))));

			#endif

		#endif
	}

	inline vec_float VecNegativeCeil(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				return (_mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_add_ps(_mm_sub_ps(v, two23), two23);
				return (_mm_add_ps(result, _mm_and_ps(one, _mm_cmplt_ps(result, v))));

			#endif

		#endif
	}

	inline vec_float VecNegativeCeilScalar(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				return (_mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_add_ss(_mm_sub_ss(v, two23), two23);
				return (_mm_add_ss(result, _mm_and_ps(one, _mm_cmplt_ps(result, v))));

			#endif

		#endif
	}

	inline void VecFloorCeil(const vec_float& v, vec_float *f, vec_float *c)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				*f = _mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
				*c = _mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ps(_mm_add_ps(_mm_add_ps(_mm_sub_ps(v, two23), two23), two23), two23);
				*f = _mm_sub_ps(result, _mm_and_ps(one, _mm_cmplt_ps(v, result)));
				*c = _mm_add_ps(result, _mm_and_ps(one, _mm_cmplt_ps(result, v)));

			#endif

		#endif
	}

	inline void VecFloorCeilScalar(const vec_float& v, vec_float *f, vec_float *c)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				*f = _mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
				*c = _mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ss(_mm_add_ss(_mm_add_ss(_mm_sub_ss(v, two23), two23), two23), two23);
				*f = _mm_sub_ss(result, _mm_and_ps(one, _mm_cmplt_ps(v, result)));
				*c = _mm_add_ss(result, _mm_and_ps(one, _mm_cmplt_ps(result, v)));

			#endif

		#endif
	}

	inline void VecPositiveFloorCeil(const vec_float& v, vec_float *f, vec_float *c)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				*f = _mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
				*c = _mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ps(_mm_add_ps(v, two23), two23);
				*f = _mm_sub_ps(result, _mm_and_ps(one, _mm_cmplt_ps(v, result)));
				*c = _mm_add_ps(result, _mm_and_ps(one, _mm_cmplt_ps(result, v)));

			#endif

		#endif
	}

	inline void VecPositiveFloorCeilScalar(const vec_float& v, vec_float *f, vec_float *c)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				*f = _mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
				*c = _mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ss(_mm_add_ss(v, two23), two23);
				*f = _mm_sub_ss(result, _mm_and_ps(one, _mm_cmplt_ps(v, result)));
				*c = _mm_add_ss(result, _mm_and_ps(one, _mm_cmplt_ps(result, v)));

			#endif

		#endif
	}

	inline void VecNegativeFloorCeil(const vec_float& v, vec_float *f, vec_float *c)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				*f = _mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
				*c = _mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_add_ps(_mm_sub_ps(v, two23), two23);
				*f = _mm_sub_ps(result, _mm_and_ps(one, _mm_cmplt_ps(v, result)));
				*c = _mm_add_ps(result, _mm_and_ps(one, _mm_cmplt_ps(result, v)));

			#endif

		#endif
	}

	inline void VecNegativeFloorCeilScalar(const vec_float& v, vec_float *f, vec_float *c)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				*f = _mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
				*c = _mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_add_ss(_mm_sub_ss(v, two23), two23);
				*f = _mm_sub_ss(result, _mm_and_ps(one, _mm_cmplt_ps(v, result)));
				*c = _mm_add_ss(result, _mm_and_ps(one, _mm_cmplt_ps(result, v)));

			#endif

		#endif
	}

	inline vec_float VecFsgn(const vec_float& v)
	{
		vec_float result = VecLoadVectorConstant<0x3F800000>();
		result = VecOr(result, VecAnd(VecFloatGetMinusZero(), v));
		return (VecAndc(result, VecMaskCmpeq(v, VecFloatGetZero())));
	}

	inline vec_float VecFnsgn(const vec_float& v)
	{
		vec_float result = VecLoadVectorConstant<0x3F800000>();
		result = VecOr(result, VecAndc(VecFloatGetMinusZero(), v));
		return (VecAndc(result, VecMaskCmpeq(v, VecFloatGetZero())));
	}

	inline vec_float VecNonzeroFsgn(const vec_float& v)
	{
		vec_float result = VecLoadVectorConstant<0x3F800000>();
		return (VecOr(result, VecAnd(VecFloatGetMinusZero(), v)));
	}

	inline vec_float VecNonzeroFnsgn(const vec_float& v)
	{
		vec_float result = VecLoadVectorConstant<0x3F800000>();
		return (VecOr(result, VecAndc(VecFloatGetMinusZero(), v)));
	}

	inline vec_float VecHorizontalSum3D(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				return (_mm_add_ss(_mm_hadd_ps(v, v), _mm_insert_ps(v, v, 0x8E)));

			#else

				return (_mm_add_ss(_mm_add_ss(v, VecSmearY(v)), VecSmearZ(v)));

			#endif

		#endif
	}

	inline vec_float VecDot3D(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				vec_float r = _mm_mul_ps(v1, v2);
				r = _mm_insert_ps(r, r, 0x08);
				r = _mm_hadd_ps(r, r);
				return (_mm_hadd_ps(r, r));

			#else

				vec_float d = _mm_mul_ps(v1, v2);
				return (_mm_add_ss(_mm_add_ss(d, VecSmearY(d)), VecSmearZ(d)));

			#endif

		#endif
	}

	inline vec_float VecDot4D(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				vec_float r = _mm_mul_ps(v1, v2);
				r = _mm_hadd_ps(r, r);
				return (_mm_hadd_ps(r, r));

			#else

				vec_float d = _mm_mul_ps(v1, v2);
				return (_mm_add_ss(_mm_add_ss(_mm_add_ss(d, VecSmearY(d)), VecSmearZ(d)), VecSmearW(d)));

			#endif

		#endif
	}

	inline vec_float VecPlaneDotPoint3D(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			#ifdef TERATHON_SSE4

				const vec_float one = VecLoadScalarConstant<0x3F800000>();
				vec_float p = _mm_insert_ps(v2, one, 0x30);
				vec_float r = _mm_mul_ps(v1, p);
				r = _mm_hadd_ps(r, r);
				return (_mm_hadd_ps(r, r));

			#else

				vec_float d = _mm_mul_ps(v1, v2);
				return (_mm_add_ss(_mm_add_ss(_mm_add_ss(d, VecSmearY(d)), VecSmearZ(d)), VecSmearW(v1)));

			#endif

		#endif
	}

	inline vec_float VecProject3D(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			vec_float d = VecDot3D(v1, v2);
			return (_mm_mul_ps(v2, VecSmearX(d)));

		#endif
	}

	inline vec_float VecReject3D(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			vec_float d = VecDot3D(v1, v2);
			return (_mm_sub_ps(v1, _mm_mul_ps(v2, VecSmearX(d))));

		#endif
	}

	inline vec_float VecCross3D(const vec_float& v1, const vec_float& v2)
	{
		#ifdef TERATHON_SSE

			vec_float c = _mm_mul_ps(v1, _mm_shuffle_ps(v2, v2, _MM_SHUFFLE(3, 0, 2, 1)));
			c = _mm_sub_ps(c, _mm_mul_ps(_mm_shuffle_ps(v1, v1, _MM_SHUFFLE(3, 0, 2, 1)), v2));
			return (_mm_shuffle_ps(c, c, _MM_SHUFFLE(3, 0, 2, 1)));

		#endif
	}

	inline vec_float VecTransformVector3D(const vec_float& c1, const vec_float& c2, const vec_float& c3, const vec_float& v)
	{
		#ifdef TERATHON_SSE

			vec_float result = _mm_mul_ps(c1, VecSmearX(v));
			result = _mm_add_ps(result, _mm_mul_ps(c2, VecSmearY(v)));
			return (_mm_add_ps(result, _mm_mul_ps(c3, VecSmearZ(v))));

		#endif
	}

	inline vec_float VecTransformPoint3D(const vec_float& c1, const vec_float& c2, const vec_float& c3, const vec_float& c4, const vec_float& p)
	{
		#ifdef TERATHON_SSE

			vec_float result = _mm_mul_ps(c1, VecSmearX(p));
			result = _mm_add_ps(result, _mm_mul_ps(c2, VecSmearY(p)));
			result = _mm_add_ps(result, _mm_mul_ps(c3, VecSmearZ(p)));
			return (_mm_add_ps(result, c4));

		#endif
	}

	inline vec_int8 VecInt8GetZero(void)
	{
		#ifdef TERATHON_SSE

			return (_mm_setzero_si128());

		#endif
	}

	inline vec_int16 VecInt16GetZero(void)
	{
		#ifdef TERATHON_SSE

			return (_mm_setzero_si128());

		#endif
	}

	inline vec_int32 VecInt32GetZero(void)
	{
		#ifdef TERATHON_SSE

			return (_mm_setzero_si128());

		#endif
	}

	inline vec_int8 VecInt8GetInfinity(void)
	{
		#ifdef TERATHON_SSE

			alignas(16) static const uint8 int_80[16] = {0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80};
			return (_mm_load_si128(reinterpret_cast<const __m128i *>(int_80)));

		#endif
	}

	inline vec_int8 VecInt8Load(const int8 *ptr)
	{
		#ifdef TERATHON_SSE

			return (_mm_load_si128(reinterpret_cast<const __m128i *>(ptr)));

		#endif
	}

	inline vec_int8 VecInt8LoadUnaligned(const int8 *ptr)
	{
		#ifdef TERATHON_SSE

			return (_mm_loadu_si128(reinterpret_cast<const __m128i *>(ptr)));

		#endif
	}

	inline vec_uint8 VecUInt8Load(const uint8 *ptr)
	{
		#ifdef TERATHON_SSE

			return (_mm_load_si128(reinterpret_cast<const __m128i *>(ptr)));

		#endif
	}

	inline vec_uint8 VecUInt8LoadUnaligned(const uint8 *ptr)
	{
		#ifdef TERATHON_SSE

			return (_mm_loadu_si128(reinterpret_cast<const __m128i *>(ptr)));

		#endif
	}

	inline vec_int16 VecInt16Load(const int16 *ptr)
	{
		#ifdef TERATHON_SSE

			return (_mm_load_si128(reinterpret_cast<const __m128i *>(ptr)));

		#endif
	}

	inline vec_int16 VecInt16LoadUnaligned(const int16 *ptr)
	{
		#ifdef TERATHON_SSE

			return (_mm_loadu_si128(reinterpret_cast<const __m128i *>(ptr)));

		#endif
	}

	inline vec_uint16 VecUInt16Load(const uint16 *ptr)
	{
		#ifdef TERATHON_SSE

			return (_mm_load_si128(reinterpret_cast<const __m128i *>(ptr)));

		#endif
	}

	inline vec_uint16 VecUInt16LoadUnaligned(const uint16 *ptr)
	{
		#ifdef TERATHON_SSE

			return (_mm_loadu_si128(reinterpret_cast<const __m128i *>(ptr)));

		#endif
	}

	inline void VecInt32StoreX(const vec_int32& v, int32 *ptr)
	{
		#ifdef TERATHON_SSE

			*ptr = _mm_cvtsi128_si32(v);

		#endif
	}

	inline void VecInt32StoreY(const vec_int32& v, int32 *ptr)
	{
		#ifdef TERATHON_SSE

			*ptr = _mm_cvtsi128_si32(_mm_shuffle_epi32(v, _MM_SHUFFLE(1, 1, 1, 1)));

		#endif
	}

	inline void VecInt32StoreZ(const vec_int32& v, int32 *ptr)
	{
		#ifdef TERATHON_SSE

			*ptr = _mm_cvtsi128_si32(_mm_shuffle_epi32(v, _MM_SHUFFLE(2, 2, 2, 2)));

		#endif
	}

	inline void VecInt32StoreW(const vec_int32& v, int32 *ptr)
	{
		#ifdef TERATHON_SSE

			*ptr = _mm_cvtsi128_si32(_mm_shuffle_epi32(v, _MM_SHUFFLE(3, 3, 3, 3)));

		#endif
	}

	inline vec_int16 VecInt32PackSaturate(const vec_int32& v)
	{
		#ifdef TERATHON_SSE

			return (_mm_packs_epi32(v, v));

		#endif
	}

	inline vec_int16 VecInt32PackSaturate(const vec_int32& v1, const vec_int32& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_packs_epi32(v1, v2));

		#endif
	}

	inline vec_int8 VecInt16PackSaturate(const vec_int16& v)
	{
		#ifdef TERATHON_SSE

			return (_mm_packs_epi16(v, v));

		#endif
	}

	inline vec_uint8 VecInt16PackUnsignedSaturate(const vec_int16& v)
	{
		#ifdef TERATHON_SSE

			return (_mm_packus_epi16(v, v));

		#endif
	}

	inline vec_int16 VecInt8UnpackA(const vec_int8& v)
	{
		#ifdef TERATHON_SSE

			return (_mm_unpacklo_epi8(v, _mm_cmplt_epi8(v, _mm_setzero_si128())));

		#endif
	}

	inline vec_int16 VecInt8UnpackB(const vec_int8& v)
	{
		#ifdef TERATHON_SSE

			return (_mm_unpackhi_epi8(v, _mm_cmplt_epi8(v, _mm_setzero_si128())));

		#endif
	}

	inline vec_uint16 VecUInt8UnpackA(const vec_uint8& v)
	{
		#ifdef TERATHON_SSE

			return (_mm_unpacklo_epi8(v, _mm_setzero_si128()));

		#endif
	}

	inline vec_uint16 VecUInt8UnpackB(const vec_uint8& v)
	{
		#ifdef TERATHON_SSE

			return (_mm_unpackhi_epi8(v, _mm_setzero_si128()));

		#endif
	}

	inline vec_int32 VecInt16UnpackA(const vec_int16& v)
	{
		#ifdef TERATHON_SSE

			return (_mm_unpacklo_epi16(v, _mm_cmplt_epi16(v, _mm_setzero_si128())));

		#endif
	}

	inline vec_int32 VecInt16UnpackB(const vec_int16& v)
	{
		#ifdef TERATHON_SSE

			return (_mm_unpackhi_epi16(v, _mm_cmplt_epi16(v, _mm_setzero_si128())));

		#endif
	}

	inline vec_uint32 VecUInt16UnpackA(const vec_uint16& v)
	{
		#ifdef TERATHON_SSE

			return (_mm_unpacklo_epi16(v, _mm_setzero_si128()));

		#endif
	}

	inline vec_uint32 VecUInt16UnpackB(const vec_uint16& v)
	{
		#ifdef TERATHON_SSE

			return (_mm_unpackhi_epi16(v, _mm_setzero_si128()));

		#endif
	}

	inline vec_int8 VecInt8MergeA(const vec_int8& v1, const vec_int8& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_unpacklo_epi8(v1, v2));

		#endif
	}

	inline vec_int8 VecInt8MergeB(const vec_int8& v1, const vec_int8& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_unpackhi_epi8(v1, v2));

		#endif
	}

	inline vec_uint8 VecUInt8MergeA(const vec_uint8& v1, const vec_uint8& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_unpacklo_epi8(v1, v2));

		#endif
	}

	inline vec_uint8 VecUInt8MergeB(const vec_uint8& v1, const vec_uint8& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_unpackhi_epi8(v1, v2));

		#endif
	}

	inline vec_int16 VecInt16Deinterleave(const vec_int16& v)
	{
		#ifdef TERATHON_SSE

			vec_int16 i = _mm_shufflelo_epi16(v, _MM_SHUFFLE(3, 1, 2, 0));
			i = _mm_shufflehi_epi16(i, _MM_SHUFFLE(3, 1, 2, 0));
			return (_mm_shuffle_epi32(i, _MM_SHUFFLE(3, 1, 2, 0)));

		#endif
	}

	inline vec_float VecInt32ConvertFloat(const vec_int32& v)
	{
		#ifdef TERATHON_SSE

			return (_mm_cvtepi32_ps(v));

		#endif
	}

	inline vec_int32 VecConvertInt32(const vec_float& v)
	{
		#ifdef TERATHON_SSE

			return (_mm_cvtps_epi32(v));

		#endif
	}

	inline vec_int32 VecInt32Add(const vec_int32& v1, const vec_int32& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_add_epi32(v1, v2));

		#endif
	}

	inline vec_int32 VecInt32Sub(const vec_int32& v1, const vec_int32& v2)
	{
		#ifdef TERATHON_SSE

			return (_mm_sub_epi32(v1, v2));

		#endif
	}

	#ifdef TERATHON_AVX

		inline exv_float ExvFloat(const vec_float& v1, const vec_float& v2)
		{
			return (_mm256_insertf128_ps(_mm256_castps128_ps256(v1), v2, 1));
		}

		inline exv_float ExvFloatGetZero(void)
		{
			return (_mm256_setzero_ps());
		}

		inline exv_float ExvFloatGetMinusZero(void)
		{
			alignas(32) static const uint32 float_80000000[8] = {0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000};
			return (_mm256_load_ps(reinterpret_cast<const float *>(float_80000000)));
		}

		inline exv_float ExvSmearX(const exv_float& v)
		{
			return (_mm256_permute_ps(v, 0x00));
		}

		inline exv_float ExvSmearY(const exv_float& v)
		{
			return (_mm256_permute_ps(v, 0x55));
		}

		inline exv_float ExvSmearZ(const exv_float& v)
		{
			return (_mm256_permute_ps(v, 0xAA));
		}

		inline exv_float ExvSmearW(const exv_float& v)
		{
			return (_mm256_permute_ps(v, 0xFF));
		}

		inline exv_float ExvSmearVecLo(const exv_float& v)
		{
			return (_mm256_permute2f128_ps(v, v, 0x00));
		}

		inline exv_float ExvSmearVecHi(const exv_float& v)
		{
			return (_mm256_permute2f128_ps(v, v, 0x11));
		}

		inline exv_float ExvLoad(const float *ptr)
		{
			return (_mm256_load_ps(ptr));
		}

		inline exv_float ExvLoadSmearScalar(const float *ptr)
		{
			return (_mm256_broadcast_ss(ptr));
		}

		inline void ExvStore(const exv_float& v, float *ptr)
		{
			_mm256_store_ps(ptr, v);
		}

		inline void ExvStoreX(const exv_float& v, float *ptr)
		{
			_mm_store_ss(ptr, _mm256_castps256_ps128(v));
		}

		inline void ExvStoreY(const exv_float& v, float *ptr)
		{
			_mm_store_ss(ptr, _mm256_castps256_ps128(_mm256_permute_ps(v, 0x55)));
		}

		inline void ExvStoreZ(const exv_float& v, float *ptr)
		{
			_mm_store_ss(ptr, _mm256_castps256_ps128(_mm256_permute_ps(v, 0xAA)));
		}

		inline void ExvStoreW(const exv_float& v, float *ptr)
		{
			_mm_store_ss(ptr, _mm256_castps256_ps128(_mm256_permute_ps(v, 0xFF)));
		}

		inline exv_float ExvMul(const exv_float& v1, const exv_float& v2)
		{
			return (_mm256_mul_ps(v1, v2));
		}

		inline exv_float ExvMadd(const exv_float& v1, const exv_float& v2, const exv_float& v3)
		{
			return (_mm256_add_ps(_mm256_mul_ps(v1, v2), v3));
		}

	#endif
}


#endif
