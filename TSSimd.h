//
// This file is part of the Terathon Common Library, by Eric Lengyel.
// Copyright 1999-2022, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
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

#if defined(__ARM_NEON)

	#define TERATHON_NEON 1

#endif


#ifdef TERATHON_NO_SYSTEM

	#if defined(TERATHON_SSE)

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

		#define _MM_SHUFFLE(p3,p2,p1,p0) (((p3) << 6) | ((p2) << 4) | ((p1) << 2) | (p0))

		extern "C"
		{
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
		}

	#endif

	#if defined(TERATHON_AVX)

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

		extern "C"
		{
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
		}

	#endif

#else

	#if defined(TERATHON_SSE)

		#include <emmintrin.h>

	#endif

	#if defined(TERATHON_AVX)

		#include <immintrin.h>

	#endif

	#if defined(TERATHON_NEON)

		#include <arm_neon.h>

	#endif

#endif


namespace Terathon
{
	struct vec_float
	{
		#if defined(TERATHON_SSE)

			__m128			v;

			vec_float(__m128 m) {v = m;}

			operator __m128&(void) {return (v);}
			operator const __m128&(void) const {return (v);}
			operator volatile __m128&(void) volatile {return (v);}
			operator const volatile __m128&(void) const volatile {return (v);}

		#elif defined(TERATHON_NEON)

			float32x4_t		v;

			vec_float(float32x4_t m) {v = m;}

			operator float32x4_t&(void) {return (v);}
			operator const float32x4_t&(void) const {return (v);}
			operator volatile float32x4_t&(void) volatile {return (v);}
			operator const volatile float32x4_t&(void) const volatile {return (v);}

		#else

			float			v[4];

		#endif

		inline vec_float() = default;
		inline vec_float(const vec_float&) = default;
		inline vec_float& operator =(const vec_float& m) = default;
	};


	struct exv_float
	{
		#if defined(TERATHON_AVX)

			__m256		v;

			exv_float(__m256 m) {v = m;}

			operator __m256&(void) {return (v);}
			operator const __m256&(void) const {return (v);}
			operator volatile __m256&(void) volatile {return (v);}
			operator const volatile __m256&(void) const volatile {return (v);}

		#else

			float		v[8];

		#endif

		inline exv_float() = default;
		inline exv_float(const exv_float&) = default;
		inline exv_float& operator =(const exv_float&) = default;
	};


	#if defined(TERATHON_SSE)

		typedef __m128i vec_int8;
		typedef __m128i vec_int16;
		typedef __m128i vec_int32;
		typedef __m128i vec_uint8;
		typedef __m128i vec_uint16;
		typedef __m128i vec_uint32;

	#elif defined(TERATHON_NEON)

		typedef int8x16_t vec_int8;
		typedef int16x8_t vec_int16;
		typedef int32x4_t vec_int32;
		typedef uint8x16_t vec_uint8;
		typedef uint16x8_t vec_uint16;
		typedef uint32x4_t vec_uint32;

	#endif

	#if defined(TERATHON_AVX)

		typedef __m256i exv_int8;
		typedef __m256i exv_int16;
		typedef __m256i exv_int32;
		typedef __m256i exv_uint8;
		typedef __m256i exv_uint16;
		typedef __m256i exv_uint32;

	#endif


	inline vec_float VecFloatGetZero(void)
	{
		#if defined(TERATHON_SSE)

			return (_mm_setzero_ps());

		#elif defined(TERATHON_NEON)

			return (vmovq_n_f32(0.0F));

		#endif
	}

	inline vec_float VecFloatGetMinusZero(void)
	{
		#if defined(TERATHON_SSE)

			alignas(16) static const uint32 float_80000000[4] = {0x80000000, 0x80000000, 0x80000000, 0x80000000};
			return (_mm_load_ps(reinterpret_cast<const float *>(float_80000000)));

		#elif defined(TERATHON_NEON)

			return (vmovq_n_f32(-0.0F));

		#endif
	}

	template <uint32 value>
	inline vec_float VecLoadVectorConstant(void)
	{
		#if defined(TERATHON_SSE)

			alignas(16) static const uint32 k[4] = {value, value, value, value};
			return (_mm_load_ps(reinterpret_cast<const float *>(k)));

		#elif defined(TERATHON_NEON)

			return (vreinterpretq_f32_u32(vdupq_n_u32(value)));

		#endif
	}

	template <uint32 value>
	inline vec_float VecLoadScalarConstant(void)
	{
		#if defined(TERATHON_SSE)

			static const uint32 k = value;
			return (_mm_load_ss(reinterpret_cast<const float *>(&k)));

		#elif defined(TERATHON_NEON)

			return (vreinterpretq_f32_u32(vdupq_n_u32(value)));

		#endif
	}

	inline vec_float VecSmearX(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0)));

		#elif defined(TERATHON_NEON)

			return (vdupq_n_f32(vgetq_lane_f32(v, 0)));

		#endif
	}

	inline vec_float VecSmearY(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1)));

		#elif defined(TERATHON_NEON)

			return (vdupq_n_f32(vgetq_lane_f32(v, 1)));

		#endif
	}

	inline vec_float VecSmearZ(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2)));

		#elif defined(TERATHON_NEON)

			return (vdupq_n_f32(vgetq_lane_f32(v, 2)));

		#endif
	}

	inline vec_float VecSmearW(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 3, 3, 3)));

		#elif defined(TERATHON_NEON)

			return (vdupq_n_f32(vgetq_lane_f32(v, 3)));

		#endif
	}

	#if defined(TERATHON_SSE)

		template <int p3, int p2, int p1, int p0>
		inline vec_float VecShuffle(const vec_float& v1, const vec_float& v2)
		{
			return (_mm_shuffle_ps(v1, v2, _MM_SHUFFLE(p3, p2, p1, p0)));
		}

	#endif

	inline vec_float VecLoad(const float *ptr)
	{
		#if defined(TERATHON_SSE)

			return (_mm_load_ps(ptr));

		#elif defined(TERATHON_NEON)

			return (vld1q_f32(ptr));

		#endif
	}

	inline vec_float VecLoadUnaligned(const float *ptr)
	{
		#if defined(TERATHON_SSE)

			return (_mm_loadu_ps(ptr));

		#elif defined(TERATHON_NEON)

			return (vld1q_f32(ptr));

		#endif
	}

	inline vec_float VecLoadScalar(const float *ptr)
	{
		#if defined(TERATHON_SSE)

			return (_mm_load_ss(ptr));

		#elif defined(TERATHON_NEON)

			return (vld1q_dup_f32(ptr));

		#endif
	}

	inline vec_float VecLoadSmearScalar(const float *ptr)
	{
		#if defined(TERATHON_SSE)

			vec_float v = _mm_load_ss(ptr);
			return (_mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0)));

		#elif defined(TERATHON_NEON)

			return (vld1q_dup_f32(ptr));

		#endif
	}

	inline void VecStore(const vec_float& v, float *ptr)
	{
		#if defined(TERATHON_SSE)

			_mm_store_ps(ptr, v);

		#elif defined(TERATHON_NEON)

			vst1q_f32(ptr, v);

		#endif
	}

	inline void VecStoreUnaligned(const vec_float& v, float *ptr)
	{
		#if defined(TERATHON_SSE)

			_mm_storeu_ps(ptr, v);

		#elif defined(TERATHON_NEON)

			vst1q_f32(ptr, v);

		#endif
	}

	inline void VecStoreX(const vec_float& v, float *ptr)
	{
		#if defined(TERATHON_SSE4)

			*ptr = v[0];

		#elif defined(TERATHON_SSE)

			_mm_store_ss(ptr, v);

		#elif defined(TERATHON_NEON)

			vst1q_lane_f32(ptr, v, 0);

		#endif
	}

	inline void VecStoreY(const vec_float& v, float *ptr)
	{
		#if defined(TERATHON_SSE4)

			*ptr = v[1];

		#elif defined(TERATHON_SSE)

			_mm_store_ss(ptr, _mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1)));

		#elif defined(TERATHON_NEON)

			vst1q_lane_f32(ptr, v, 1);

		#endif
	}

	inline void VecStoreZ(const vec_float& v, float *ptr)
	{
		#if defined(TERATHON_SSE4)

			*ptr = v[2];

		#elif defined(TERATHON_SSE)

			_mm_store_ss(ptr, _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2)));

		#elif defined(TERATHON_NEON)

			vst1q_lane_f32(ptr, v, 2);

		#endif
	}

	inline void VecStoreW(const vec_float& v, float *ptr)
	{
		#if defined(TERATHON_SSE4)

			*ptr = v[3];

		#elif defined(TERATHON_SSE)

			_mm_store_ss(ptr, _mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 3, 3, 3)));

		#elif defined(TERATHON_NEON)

			vst1q_lane_f32(ptr, v, 3);

		#endif
	}

	inline void VecStore3D(const vec_float& v, float *ptr)
	{
		#if defined(TERATHON_SSE4)

			ptr[0] = v[0];
			ptr[1] = v[1];
			ptr[2] = v[2];

		#elif defined(TERATHON_SSE)

			_mm_store_ss(&ptr[0], v);
			_mm_store_ss(&ptr[1], _mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1)));
			_mm_store_ss(&ptr[2], _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2)));

		#elif defined(TERATHON_NEON)

			vst1q_lane_f32(&ptr[0], v, 0);
			vst1q_lane_f32(&ptr[1], v, 1);
			vst1q_lane_f32(&ptr[2], v, 2);

		#endif
	}

	inline int32 VecTruncateConvert(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_cvtt_ss2si(v));

		#elif defined(TERATHON_NEON)

			return (vgetq_lane_s32(vcvtq_s32_f32(v), 0));

		#endif
	}

	inline vec_float VecNegate(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_sub_ps(_mm_setzero_ps(), v));

		#elif defined(TERATHON_NEON)

			return (vnegq_f32(v));

		#endif
	}

	inline vec_float operator -(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_sub_ps(_mm_setzero_ps(), v));

		#elif defined(TERATHON_NEON)

			return (vnegq_f32(v));

		#endif
	}

	inline vec_float VecMin(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_min_ps(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vminq_f32(v1, v2));

		#endif
	}

	inline vec_float VecMinScalar(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_min_ss(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vminq_f32(v1, v2));

		#endif
	}

	inline vec_float VecMax(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_max_ps(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vmaxq_f32(v1, v2));

		#endif
	}

	inline vec_float VecMaxScalar(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_max_ss(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vmaxq_f32(v1, v2));

		#endif
	}

	inline vec_float VecAdd(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_add_ps(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vaddq_f32(v1, v2));

		#endif
	}

	inline vec_float operator +(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_add_ps(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vaddq_f32(v1, v2));

		#endif
	}

	inline vec_float VecAddScalar(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_add_ss(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vaddq_f32(v1, v2));

		#endif
	}

	inline vec_float VecSub(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_sub_ps(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vsubq_f32(v1, v2));

		#endif
	}

	inline vec_float operator -(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_sub_ps(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vsubq_f32(v1, v2));

		#endif
	}

	inline vec_float VecSubScalar(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_sub_ss(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vsubq_f32(v1, v2));

		#endif
	}

	inline vec_float VecMul(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_mul_ps(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vmulq_f32(v1, v2));

		#endif
	}

	inline vec_float operator *(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_mul_ps(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vmulq_f32(v1, v2));

		#endif
	}

	inline vec_float VecMulScalar(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_mul_ss(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vmulq_f32(v1, v2));

		#endif
	}

	inline vec_float VecMadd(const vec_float& v1, const vec_float& v2, const vec_float& v3)
	{
		#if defined(TERATHON_SSE)

			return (_mm_add_ps(_mm_mul_ps(v1, v2), v3));

		#elif defined(TERATHON_NEON)

			return (vfmaq_f32(v3, v1, v2));

		#endif
	}

	inline vec_float VecMaddScalar(const vec_float& v1, const vec_float& v2, const vec_float& v3)
	{
		#if defined(TERATHON_SSE)

			return (_mm_add_ss(_mm_mul_ss(v1, v2), v3));

		#elif defined(TERATHON_NEON)

			return (vfmaq_f32(v3, v1, v2));

		#endif
	}

	inline vec_float VecNmsub(const vec_float& v1, const vec_float& v2, const vec_float& v3)
	{
		#if defined(TERATHON_SSE)

			return (_mm_sub_ps(v3, _mm_mul_ps(v1, v2)));

		#elif defined(TERATHON_NEON)

			return (vfmsq_f32(v3, v1, v2));

		#endif
	}

	inline vec_float VecNmsubScalar(const vec_float& v1, const vec_float& v2, const vec_float& v3)
	{
		#if defined(TERATHON_SSE)

			return (_mm_sub_ss(v3, _mm_mul_ss(v1, v2)));

		#elif defined(TERATHON_NEON)

			return (vfmsq_f32(v3, v1, v2));

		#endif
	}

	inline vec_float VecDiv(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_div_ps(v1, v2));

		#elif defined(TERATHON_NEON)

			vec_float f = vrecpeq_f32(v2);
			f = vmulq_f32(f, vrecpsq_f32(v2, f));
			return (vmulq_f32(v1, f));

		#endif
	}

	inline vec_float operator /(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_div_ps(v1, v2));

		#elif defined(TERATHON_NEON)

			vec_float f = vrecpeq_f32(v2);
			f = vmulq_f32(f, vrecpsq_f32(v2, f));
			return (vmulq_f32(v1, f));

		#endif
	}

	inline vec_float VecDivScalar(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_div_ss(v1, v2));

		#elif defined(TERATHON_NEON)

			vec_float f = vrecpeq_f32(v2);
			f = vmulq_f32(f, vrecpsq_f32(v2, f));
			return (vmulq_f32(v1, f));

		#endif
	}

	inline vec_float VecAnd(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_and_ps(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vreinterpretq_f32_u32(vandq_u32(vreinterpretq_u32_f32(v1), vreinterpretq_u32_f32(v2))));

		#endif
	}

	inline vec_float operator &(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_and_ps(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vreinterpretq_f32_u32(vandq_u32(vreinterpretq_u32_f32(v1), vreinterpretq_u32_f32(v2))));

		#endif
	}

	inline vec_float VecAndc(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_andnot_ps(v2, v1));

		#elif defined(TERATHON_NEON)

			return (vreinterpretq_f32_u32(vbicq_u32(vreinterpretq_u32_f32(v1), vreinterpretq_u32_f32(v2))));

		#endif
	}

	inline vec_float VecOr(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_or_ps(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vreinterpretq_f32_u32(vorrq_u32(vreinterpretq_u32_f32(v1), vreinterpretq_u32_f32(v2))));

		#endif
	}

	inline vec_float operator |(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_or_ps(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vreinterpretq_f32_u32(vorrq_u32(vreinterpretq_u32_f32(v1), vreinterpretq_u32_f32(v2))));

		#endif
	}

	inline vec_float VecXor(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_xor_ps(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vreinterpretq_f32_u32(veorq_u32(vreinterpretq_u32_f32(v1), vreinterpretq_u32_f32(v2))));

		#endif
	}

	inline vec_float operator ^(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_xor_ps(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vreinterpretq_f32_u32(veorq_u32(vreinterpretq_u32_f32(v1), vreinterpretq_u32_f32(v2))));

		#endif
	}

	inline vec_float VecSelect(const vec_float& v1, const vec_float& v2, const vec_float& mask)
	{
		#if defined(TERATHON_SSE)

			return (_mm_or_ps(_mm_andnot_ps(mask, v1), _mm_and_ps(mask, v2)));

		#elif defined(TERATHON_NEON)

			return (vbslq_f32(vreinterpretq_u32_f32(mask), v2, v1));

		#endif
	}

	inline vec_float VecMaskCmpeq(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_cmpeq_ps(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vreinterpretq_f32_u32(vceqq_f32(v1, v2)));

		#endif
	}

	inline vec_float VecMaskCmplt(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_cmplt_ps(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vreinterpretq_f32_u32(vcltq_f32(v1, v2)));

		#endif
	}

	inline vec_float VecMaskCmpgt(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_cmplt_ps(v2, v1));

		#elif defined(TERATHON_NEON)

			return (vreinterpretq_f32_u32(vcgtq_f32(v1, v2)));

		#endif
	}

	inline bool VecCmpeqScalar(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_comieq_ss(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vgetq_lane_f32(v1, 0) == vgetq_lane_f32(v2, 0));

		#endif
	}

	inline bool VecCmpltScalar(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_comilt_ss(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vgetq_lane_f32(v1, 0) < vgetq_lane_f32(v2, 0));

		#endif
	}

	inline bool VecCmpgtScalar(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_comigt_ss(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vgetq_lane_f32(v1, 0) > vgetq_lane_f32(v2, 0));

		#endif
	}

	inline bool VecCmpltAny3D(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return ((_mm_comilt_ss(v1, v2) | _mm_comilt_ss(VecSmearY(v1), VecSmearY(v2)) | _mm_comilt_ss(VecSmearZ(v1), VecSmearZ(v2))) != 0);

		#elif defined(TERATHON_NEON)

			return ((vgetq_lane_f32(v1, 0) < vgetq_lane_f32(v2, 0)) || (vgetq_lane_f32(v1, 1) < vgetq_lane_f32(v2, 1)) || (vgetq_lane_f32(v1, 2) < vgetq_lane_f32(v2, 2)));

		#endif
	}

	inline bool VecCmpgtAny3D(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			return ((_mm_comigt_ss(v1, v2) | _mm_comigt_ss(VecSmearY(v1), VecSmearY(v2)) | _mm_comigt_ss(VecSmearZ(v1), VecSmearZ(v2))) != 0);

		#elif defined(TERATHON_NEON)

			return ((vgetq_lane_f32(v1, 0) > vgetq_lane_f32(v2, 0)) || (vgetq_lane_f32(v1, 1) > vgetq_lane_f32(v2, 1)) || (vgetq_lane_f32(v1, 2) > vgetq_lane_f32(v2, 2)));

		#endif
	}

	inline vec_float VecInverseSqrt(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			const vec_float three = VecLoadVectorConstant<0x40400000>();
			const vec_float half = VecLoadVectorConstant<0x3F000000>();

			vec_float f = _mm_rsqrt_ps(v);
			return (_mm_mul_ps(_mm_mul_ps(_mm_sub_ps(three, _mm_mul_ps(v, _mm_mul_ps(f, f))), f), half));

		#elif defined(TERATHON_NEON)

			vec_float f = vrsqrteq_f32(v);
			return (vmulq_f32(f, vrsqrtsq_f32(v, vmulq_f32(f, f))));

		#endif
	}

	inline vec_float VecInverseSqrtScalar(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			const vec_float three = VecLoadVectorConstant<0x40400000>();
			const vec_float half = VecLoadVectorConstant<0x3F000000>();

			vec_float f = _mm_rsqrt_ss(v);
			return (_mm_mul_ss(_mm_mul_ss(_mm_sub_ss(three, _mm_mul_ss(v, _mm_mul_ss(f, f))), f), half));

		#elif defined(TERATHON_NEON)

			vec_float f = vrsqrteq_f32(v);
			return (vmulq_f32(f, vrsqrtsq_f32(v, vmulq_f32(f, f))));

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
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				return (_mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ps(_mm_add_ps(_mm_add_ps(_mm_sub_ps(v, two23), two23), two23), two23);
				result = _mm_sub_ps(result, _mm_and_ps(one, _mm_cmplt_ps(v, result)));

				vec_float mask = _mm_cmplt_ps(two23, _mm_andnot_ps(VecFloatGetMinusZero(), v));
				return (_mm_or_ps(_mm_andnot_ps(mask, result), _mm_and_ps(mask, v)));

			#endif

		#elif defined(TERATHON_NEON)

			const vec_uint32 one = vdupq_n_u32(0x3F800000);
			const vec_float two23 = vdupq_n_f32(8388608.0F);

			vec_float result = vsubq_f32(vaddq_f32(vaddq_f32(vsubq_f32(v, two23), two23), two23), two23);
			result = vsubq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(v, result))));

			vec_uint32 mask = vcltq_f32(two23, vabsq_f32(v));
			return (vbslq_f32(mask, v, result));

		#endif
	}

	inline vec_float VecFloorScalar(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				return (_mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ss(_mm_add_ss(_mm_add_ss(_mm_sub_ss(v, two23), two23), two23), two23);
				result = _mm_sub_ss(result, _mm_and_ps(one, _mm_cmplt_ps(v, result)));

				vec_float mask = _mm_cmplt_ps(two23, _mm_andnot_ps(VecFloatGetMinusZero(), v));
				return (_mm_or_ps(_mm_andnot_ps(mask, result), _mm_and_ps(mask, v)));

			#endif

		#elif defined(TERATHON_NEON)

			const vec_uint32 one = vdupq_n_u32(0x3F800000);
			const vec_float two23 = vdupq_n_f32(8388608.0F);

			vec_float result = vsubq_f32(vaddq_f32(vaddq_f32(vsubq_f32(v, two23), two23), two23), two23);
			result = vsubq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(v, result))));

			vec_uint32 mask = vcltq_f32(two23, vabsq_f32(v));
			return (vbslq_f32(mask, v, result));

		#endif
	}

	inline vec_float VecPositiveFloor(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				return (_mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ps(_mm_add_ps(v, two23), two23);
				return (_mm_sub_ps(result, _mm_and_ps(one, _mm_cmplt_ps(v, result))));

			#endif

		#elif defined(TERATHON_NEON)

			const vec_uint32 one = vdupq_n_u32(0x3F800000);
			const vec_float two23 = vdupq_n_f32(8388608.0F);

			vec_float result = vsubq_f32(vaddq_f32(v, two23), two23);
			return (vsubq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(v, result)))));

		#endif
	}

	inline vec_float VecPositiveFloorScalar(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				return (_mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ss(_mm_add_ss(v, two23), two23);
				return (_mm_sub_ss(result, _mm_and_ps(one, _mm_cmplt_ps(v, result))));

			#endif

		#elif defined(TERATHON_NEON)

			const vec_uint32 one = vdupq_n_u32(0x3F800000);
			const vec_float two23 = vdupq_n_f32(8388608.0F);

			vec_float result = vsubq_f32(vaddq_f32(v, two23), two23);
			return (vsubq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(v, result)))));

		#endif
	}

	inline vec_float VecNegativeFloor(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				return (_mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_add_ps(_mm_sub_ps(v, two23), two23);
				return (_mm_sub_ps(result, _mm_and_ps(one, _mm_cmplt_ps(v, result))));

			#endif

		#elif defined(TERATHON_NEON)

			const vec_uint32 one = vdupq_n_u32(0x3F800000);
			const vec_float two23 = vdupq_n_f32(8388608.0F);

			vec_float result = vaddq_f32(vsubq_f32(v, two23), two23);
			return (vsubq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(v, result)))));

		#endif
	}

	inline vec_float VecNegativeFloorScalar(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				return (_mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_add_ss(_mm_sub_ss(v, two23), two23);
				return (_mm_sub_ss(result, _mm_and_ps(one, _mm_cmplt_ps(v, result))));

			#endif

		#elif defined(TERATHON_NEON)

			const vec_uint32 one = vdupq_n_u32(0x3F800000);
			const vec_float two23 = vdupq_n_f32(8388608.0F);

			vec_float result = vaddq_f32(vsubq_f32(v, two23), two23);
			return (vsubq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(v, result)))));

		#endif
	}

	inline vec_float VecCeil(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				return (_mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ps(_mm_add_ps(_mm_add_ps(_mm_sub_ps(v, two23), two23), two23), two23);
				result = _mm_add_ps(result, _mm_and_ps(one, _mm_cmplt_ps(result, v)));

				vec_float mask = _mm_cmplt_ps(two23, _mm_andnot_ps(VecFloatGetMinusZero(), v));
				return (_mm_or_ps(_mm_andnot_ps(mask, result), _mm_and_ps(mask, v)));

			#endif

		#elif defined(TERATHON_NEON)

			const vec_uint32 one = vdupq_n_u32(0x3F800000);
			const vec_float two23 = vdupq_n_f32(8388608.0F);

			vec_float result = vsubq_f32(vaddq_f32(vaddq_f32(vsubq_f32(v, two23), two23), two23), two23);
			result = vaddq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(result, v))));

			vec_uint32 mask = vcltq_f32(two23, vabsq_f32(v));
			return (vbslq_f32(mask, v, result));

		#endif
	}

	inline vec_float VecCeilScalar(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				return (_mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ss(_mm_add_ss(_mm_add_ss(_mm_sub_ss(v, two23), two23), two23), two23);
				result = _mm_add_ss(result, _mm_and_ps(one, _mm_cmplt_ps(result, v)));

				vec_float mask = _mm_cmplt_ps(two23, _mm_andnot_ps(VecFloatGetMinusZero(), v));
				return (_mm_or_ps(_mm_andnot_ps(mask, result), _mm_and_ps(mask, v)));

			#endif

		#elif defined(TERATHON_NEON)

			const vec_uint32 one = vdupq_n_u32(0x3F800000);
			const vec_float two23 = vdupq_n_f32(8388608.0F);

			vec_float result = vsubq_f32(vaddq_f32(vaddq_f32(vsubq_f32(v, two23), two23), two23), two23);
			result = vaddq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(result, v))));

			vec_uint32 mask = vcltq_f32(two23, vabsq_f32(v));
			return (vbslq_f32(mask, v, result));

		#endif
	}

	inline vec_float VecPositiveCeil(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				return (_mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ps(_mm_add_ps(v, two23), two23);
				return (_mm_add_ps(result, _mm_and_ps(one, _mm_cmplt_ps(result, v))));

			#endif

		#elif defined(TERATHON_NEON)

			const vec_uint32 one = vdupq_n_u32(0x3F800000);
			const vec_float two23 = vdupq_n_f32(8388608.0F);

			vec_float result = vsubq_f32(vaddq_f32(v, two23), two23);
			return (vaddq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(result, v)))));

		#endif
	}

	inline vec_float VecPositiveCeilScalar(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				return (_mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ss(_mm_add_ss(v, two23), two23);
				return (_mm_add_ss(result, _mm_and_ps(one, _mm_cmplt_ps(result, v))));

			#endif

		#elif defined(TERATHON_NEON)

			const vec_uint32 one = vdupq_n_u32(0x3F800000);
			const vec_float two23 = vdupq_n_f32(8388608.0F);

			vec_float result = vsubq_f32(vaddq_f32(v, two23), two23);
			return (vaddq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(result, v)))));

		#endif
	}

	inline vec_float VecNegativeCeil(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				return (_mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_add_ps(_mm_sub_ps(v, two23), two23);
				return (_mm_add_ps(result, _mm_and_ps(one, _mm_cmplt_ps(result, v))));

			#endif

		#elif defined(TERATHON_NEON)

			const vec_uint32 one = vdupq_n_u32(0x3F800000);
			const vec_float two23 = vdupq_n_f32(8388608.0F);

			vec_float result = vaddq_f32(vsubq_f32(v, two23), two23);
			return (vaddq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(result, v)))));

		#endif
	}

	inline vec_float VecNegativeCeilScalar(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				return (_mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC));

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_add_ss(_mm_sub_ss(v, two23), two23);
				return (_mm_add_ss(result, _mm_and_ps(one, _mm_cmplt_ps(result, v))));

			#endif

		#elif defined(TERATHON_NEON)

			const vec_uint32 one = vdupq_n_u32(0x3F800000);
			const vec_float two23 = vdupq_n_f32(8388608.0F);

			vec_float result = vaddq_f32(vsubq_f32(v, two23), two23);
			return (vaddq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(result, v)))));

		#endif
	}

	inline void VecFloorCeil(const vec_float& v, vec_float *f, vec_float *c)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				*f = _mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
				*c = _mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ps(_mm_add_ps(_mm_add_ps(_mm_sub_ps(v, two23), two23), two23), two23);
				*f = _mm_sub_ps(result, _mm_and_ps(one, _mm_cmplt_ps(v, result)));
				*c = _mm_add_ps(result, _mm_and_ps(one, _mm_cmplt_ps(result, v)));

			#endif

		#elif defined(TERATHON_NEON)

			const vec_uint32 one = vdupq_n_u32(0x3F800000);
			const vec_float two23 = vdupq_n_f32(8388608.0F);

			vec_float result = vsubq_f32(vaddq_f32(vaddq_f32(vsubq_f32(v, two23), two23), two23), two23);
			*f = vsubq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(v, result))));
			*c = vaddq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(result, v))));

		#endif
	}

	inline void VecFloorCeilScalar(const vec_float& v, vec_float *f, vec_float *c)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				*f = _mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
				*c = _mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ss(_mm_add_ss(_mm_add_ss(_mm_sub_ss(v, two23), two23), two23), two23);
				*f = _mm_sub_ss(result, _mm_and_ps(one, _mm_cmplt_ps(v, result)));
				*c = _mm_add_ss(result, _mm_and_ps(one, _mm_cmplt_ps(result, v)));

			#endif

		#elif defined(TERATHON_NEON)

			const vec_uint32 one = vdupq_n_u32(0x3F800000);
			const vec_float two23 = vdupq_n_f32(8388608.0F);

			vec_float result = vsubq_f32(vaddq_f32(vaddq_f32(vsubq_f32(v, two23), two23), two23), two23);
			*f = vsubq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(v, result))));
			*c = vaddq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(result, v))));

		#endif
	}

	inline void VecPositiveFloorCeil(const vec_float& v, vec_float *f, vec_float *c)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				*f = _mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
				*c = _mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ps(_mm_add_ps(v, two23), two23);
				*f = _mm_sub_ps(result, _mm_and_ps(one, _mm_cmplt_ps(v, result)));
				*c = _mm_add_ps(result, _mm_and_ps(one, _mm_cmplt_ps(result, v)));

			#endif

		#elif defined(TERATHON_NEON)

			const vec_uint32 one = vdupq_n_u32(0x3F800000);
			const vec_float two23 = vdupq_n_f32(8388608.0F);

			vec_float result = vsubq_f32(vaddq_f32(v, two23), two23);
			*f = vsubq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(v, result))));
			*c = vaddq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(result, v))));

		#endif
	}

	inline void VecPositiveFloorCeilScalar(const vec_float& v, vec_float *f, vec_float *c)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				*f = _mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
				*c = _mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_sub_ss(_mm_add_ss(v, two23), two23);
				*f = _mm_sub_ss(result, _mm_and_ps(one, _mm_cmplt_ps(v, result)));
				*c = _mm_add_ss(result, _mm_and_ps(one, _mm_cmplt_ps(result, v)));

			#endif

		#elif defined(TERATHON_NEON)

			const vec_uint32 one = vdupq_n_u32(0x3F800000);
			const vec_float two23 = vdupq_n_f32(8388608.0F);

			vec_float result = vsubq_f32(vaddq_f32(v, two23), two23);
			*f = vsubq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(v, result))));
			*c = vaddq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(result, v))));

		#endif
	}

	inline void VecNegativeFloorCeil(const vec_float& v, vec_float *f, vec_float *c)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				*f = _mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
				*c = _mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_add_ps(_mm_sub_ps(v, two23), two23);
				*f = _mm_sub_ps(result, _mm_and_ps(one, _mm_cmplt_ps(v, result)));
				*c = _mm_add_ps(result, _mm_and_ps(one, _mm_cmplt_ps(result, v)));

			#endif

		#elif defined(TERATHON_NEON)

			const vec_uint32 one = vdupq_n_u32(0x3F800000);
			const vec_float two23 = vdupq_n_f32(8388608.0F);

			vec_float result = vaddq_f32(vsubq_f32(v, two23), two23);
			*f = vsubq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(v, result))));
			*c = vaddq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(result, v))));

		#endif
	}

	inline void VecNegativeFloorCeilScalar(const vec_float& v, vec_float *f, vec_float *c)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				*f = _mm_round_ps(v, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
				*c = _mm_round_ps(v, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);

			#else

				const vec_float one = VecLoadVectorConstant<0x3F800000>();
				const vec_float two23 = VecLoadVectorConstant<0x4B000000>();

				vec_float result = _mm_add_ss(_mm_sub_ss(v, two23), two23);
				*f = _mm_sub_ss(result, _mm_and_ps(one, _mm_cmplt_ps(v, result)));
				*c = _mm_add_ss(result, _mm_and_ps(one, _mm_cmplt_ps(result, v)));

			#endif

		#elif defined(TERATHON_NEON)

			const vec_uint32 one = vdupq_n_u32(0x3F800000);
			const vec_float two23 = vdupq_n_f32(8388608.0F);

			vec_float result = vaddq_f32(vsubq_f32(v, two23), two23);
			*f = vsubq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(v, result))));
			*c = vaddq_f32(result, vreinterpretq_f32_u32(vandq_u32(one, vcltq_f32(result, v))));

		#endif
	}

	inline vec_float VecFsgn(const vec_float& v)
	{
		vec_float result = VecLoadVectorConstant<0x3F800000>();
		result = result | (VecFloatGetMinusZero() & v);
		return (VecAndc(result, VecMaskCmpeq(v, VecFloatGetZero())));
	}

	inline vec_float VecFnsgn(const vec_float& v)
	{
		vec_float result = VecLoadVectorConstant<0x3F800000>();
		result = result | VecAndc(VecFloatGetMinusZero(), v);
		return (VecAndc(result, VecMaskCmpeq(v, VecFloatGetZero())));
	}

	inline vec_float VecNonzeroFsgn(const vec_float& v)
	{
		vec_float result = VecLoadVectorConstant<0x3F800000>();
		return (result | (VecFloatGetMinusZero() & v));
	}

	inline vec_float VecNonzeroFnsgn(const vec_float& v)
	{
		vec_float result = VecLoadVectorConstant<0x3F800000>();
		return (result | VecAndc(VecFloatGetMinusZero(), v));
	}

	inline vec_float VecHorizontalSum3D(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				return (_mm_add_ss(_mm_hadd_ps(v, v), _mm_insert_ps(v, v, 0x8E)));

			#else

				return (_mm_add_ss(_mm_add_ss(v, VecSmearY(v)), VecSmearZ(v)));

			#endif

		#elif defined(TERATHON_NEON)

			return (vaddq_f32(vpaddq_f32(v, v), vdupq_n_f32(vgetq_lane_f32(v, 2))));

		#endif
	}

	inline vec_float VecDot3D(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				vec_float r = _mm_mul_ps(v1, v2);
				r = _mm_insert_ps(r, r, 0x08);
				r = _mm_hadd_ps(r, r);
				return (_mm_hadd_ps(r, r));

			#else

				vec_float d = _mm_mul_ps(v1, v2);
				return (_mm_add_ss(_mm_add_ss(d, VecSmearY(d)), VecSmearZ(d)));

			#endif

		#elif defined(TERATHON_NEON)

			vec_float d = vmulq_f32(v1, v2);
			return (vaddq_f32(vpaddq_f32(d, d), vdupq_n_f32(vgetq_lane_f32(d, 2))));

		#endif
	}

	inline vec_float VecDot4D(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				vec_float r = _mm_mul_ps(v1, v2);
				r = _mm_hadd_ps(r, r);
				return (_mm_hadd_ps(r, r));

			#else

				vec_float d = _mm_mul_ps(v1, v2);
				return (_mm_add_ss(_mm_add_ss(_mm_add_ss(d, VecSmearY(d)), VecSmearZ(d)), VecSmearW(d)));

			#endif

		#elif defined(TERATHON_NEON)

			vec_float d = vmulq_f32(v1, v2);
			return (vaddq_f32(vaddq_f32(vpaddq_f32(d, d), vdupq_n_f32(vgetq_lane_f32(d, 2))), vdupq_n_f32(vgetq_lane_f32(d, 3))));

		#endif
	}

	inline vec_float VecPlaneDotPoint3D(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			#if defined(TERATHON_SSE4)

				const vec_float one = VecLoadScalarConstant<0x3F800000>();
				vec_float p = _mm_insert_ps(v2, one, 0x30);
				vec_float r = _mm_mul_ps(v1, p);
				r = _mm_hadd_ps(r, r);
				return (_mm_hadd_ps(r, r));

			#else

				vec_float d = _mm_mul_ps(v1, v2);
				return (_mm_add_ss(_mm_add_ss(_mm_add_ss(d, VecSmearY(d)), VecSmearZ(d)), VecSmearW(v1)));

			#endif

		#elif defined(TERATHON_NEON)

			vec_float d = vmulq_f32(v1, v2);
			return (vaddq_f32(vaddq_f32(vpaddq_f32(d, d), vdupq_n_f32(vgetq_lane_f32(d, 2))), vdupq_n_f32(vgetq_lane_f32(v1, 3))));

		#endif
	}

	inline vec_float VecProject3D(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			vec_float d = VecDot3D(v1, v2);
			return (_mm_mul_ps(v2, VecSmearX(d)));

		#elif defined(TERATHON_NEON)

			vec_float d = VecDot3D(v1, v2);
			return (vmulq_f32(v2, vdupq_n_f32(vgetq_lane_f32(d, 0))));

		#endif
	}

	inline vec_float VecReject3D(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			vec_float d = VecDot3D(v1, v2);
			return (_mm_sub_ps(v1, _mm_mul_ps(v2, VecSmearX(d))));

		#elif defined(TERATHON_NEON)

			vec_float d = VecDot3D(v1, v2);
			return (vsubq_f32(v1, vmulq_f32(v2, vdupq_n_f32(vgetq_lane_f32(d, 0)))));

		#endif
	}

	inline vec_float VecCross3D(const vec_float& v1, const vec_float& v2)
	{
		#if defined(TERATHON_SSE)

			vec_float c = _mm_mul_ps(v1, _mm_shuffle_ps(v2, v2, _MM_SHUFFLE(3, 0, 2, 1)));
			c = _mm_sub_ps(c, _mm_mul_ps(_mm_shuffle_ps(v1, v1, _MM_SHUFFLE(3, 0, 2, 1)), v2));
			return (_mm_shuffle_ps(c, c, _MM_SHUFFLE(3, 0, 2, 1)));

		#elif defined(TERATHON_NEON)

			static const uint32 mask[4] = {0x00000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};

			vec_uint32 m = vld1q_u32(mask);

			float32x4x2_t u1 = vuzpq_f32(v1, v1);
			float32x4x2_t u2 = vuzpq_f32(v2, v2);
			vec_float w1 = vbslq_f32(m, u1.val[0], u1.val[1]);
			vec_float w2 = vbslq_f32(m, u2.val[0], u2.val[1]);
			vec_float r = vfmsq_f32(vmulq_f32(v1, w2), w1, v2);
			float32x4x2_t s = vuzpq_f32(r, r);
			return (vbslq_f32(m, s.val[0], s.val[1]));

		#endif
	}

	inline vec_float VecTransformVector3D(const vec_float& c1, const vec_float& c2, const vec_float& c3, const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			vec_float result = _mm_mul_ps(c1, VecSmearX(v));
			result = _mm_add_ps(result, _mm_mul_ps(c2, VecSmearY(v)));
			return (_mm_add_ps(result, _mm_mul_ps(c3, VecSmearZ(v))));

		#elif defined(TERATHON_NEON)

			vec_float result = vmulq_f32(c1, VecSmearX(v));
			result = vfmaq_f32(result, c2, VecSmearY(v));
			return (vfmaq_f32(result, c3, VecSmearZ(v)));

		#endif
	}

	inline vec_float VecTransformPoint3D(const vec_float& c1, const vec_float& c2, const vec_float& c3, const vec_float& c4, const vec_float& p)
	{
		#if defined(TERATHON_SSE)

			vec_float result = _mm_mul_ps(c1, VecSmearX(p));
			result = _mm_add_ps(result, _mm_mul_ps(c2, VecSmearY(p)));
			result = _mm_add_ps(result, _mm_mul_ps(c3, VecSmearZ(p)));
			return (_mm_add_ps(result, c4));

		#elif defined(TERATHON_NEON)

			vec_float result = vmulq_f32(c1, VecSmearX(p));
			result = vfmaq_f32(result, c2, VecSmearY(p));
			return (vaddq_f32(vfmaq_f32(result, c3, VecSmearZ(p)), c4));

		#endif
	}

	inline vec_int8 VecInt8GetZero(void)
	{
		#if defined(TERATHON_SSE)

			return (_mm_setzero_si128());

		#elif defined(TERATHON_NEON)

			return (vmovq_n_s8(0));

		#endif
	}

	inline vec_int16 VecInt16GetZero(void)
	{
		#if defined(TERATHON_SSE)

			return (_mm_setzero_si128());

		#elif defined(TERATHON_NEON)

			return (vmovq_n_s16(0));

		#endif
	}

	inline vec_int32 VecInt32GetZero(void)
	{
		#if defined(TERATHON_SSE)

			return (_mm_setzero_si128());

		#elif defined(TERATHON_NEON)

			return (vmovq_n_s32(0));

		#endif
	}

	inline vec_int8 VecInt8GetInfinity(void)
	{
		#if defined(TERATHON_SSE)

			alignas(16) static const uint8 int_80[16] = {0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80};
			return (_mm_load_si128(reinterpret_cast<const __m128i *>(int_80)));

		#elif defined(TERATHON_NEON)

			return (vmovq_n_s8(-128));

		#endif
	}

	inline vec_int8 VecInt8Load(const int8 *ptr)
	{
		#if defined(TERATHON_SSE)

			return (_mm_load_si128(reinterpret_cast<const __m128i *>(ptr)));

		#elif defined(TERATHON_NEON)

			return (vld1q_s8(ptr));

		#endif
	}

	inline vec_int8 VecInt8LoadUnaligned(const int8 *ptr)
	{
		#if defined(TERATHON_SSE)

			return (_mm_loadu_si128(reinterpret_cast<const __m128i *>(ptr)));

		#elif defined(TERATHON_NEON)

			return (vld1q_s8(ptr));

		#endif
	}

	inline vec_uint8 VecUInt8Load(const uint8 *ptr)
	{
		#if defined(TERATHON_SSE)

			return (_mm_load_si128(reinterpret_cast<const __m128i *>(ptr)));

		#elif defined(TERATHON_NEON)

			return (vld1q_u8(ptr));

		#endif
	}

	inline vec_uint8 VecUInt8LoadUnaligned(const uint8 *ptr)
	{
		#if defined(TERATHON_SSE)

			return (_mm_loadu_si128(reinterpret_cast<const __m128i *>(ptr)));

		#elif defined(TERATHON_NEON)

			return (vld1q_u8(ptr));

		#endif
	}

	inline vec_int16 VecInt16Load(const int16 *ptr)
	{
		#if defined(TERATHON_SSE)

			return (_mm_load_si128(reinterpret_cast<const __m128i *>(ptr)));

		#elif defined(TERATHON_NEON)

			return (vld1q_s16(ptr));

		#endif
	}

	inline vec_int16 VecInt16LoadUnaligned(const int16 *ptr)
	{
		#if defined(TERATHON_SSE)

			return (_mm_loadu_si128(reinterpret_cast<const __m128i *>(ptr)));

		#elif defined(TERATHON_NEON)

			return (vld1q_s16(ptr));

		#endif
	}

	inline vec_uint16 VecUInt16Load(const uint16 *ptr)
	{
		#if defined(TERATHON_SSE)

			return (_mm_load_si128(reinterpret_cast<const __m128i *>(ptr)));

		#elif defined(TERATHON_NEON)

			return (vld1q_u16(ptr));

		#endif
	}

	inline vec_uint16 VecUInt16LoadUnaligned(const uint16 *ptr)
	{
		#if defined(TERATHON_SSE)

			return (_mm_loadu_si128(reinterpret_cast<const __m128i *>(ptr)));

		#elif defined(TERATHON_NEON)

			return (vld1q_u16(ptr));

		#endif
	}

	inline void VecInt32StoreX(const vec_int32& v, int32 *ptr)
	{
		#if defined(TERATHON_SSE)

			*ptr = _mm_cvtsi128_si32(v);

		#elif defined(TERATHON_NEON)

			vst1q_lane_s32(ptr, v, 0);

		#endif
	}

	inline void VecInt32StoreY(const vec_int32& v, int32 *ptr)
	{
		#if defined(TERATHON_SSE)

			*ptr = _mm_cvtsi128_si32(_mm_shuffle_epi32(v, _MM_SHUFFLE(1, 1, 1, 1)));

		#elif defined(TERATHON_NEON)

			vst1q_lane_s32(ptr, v, 1);

		#endif
	}

	inline void VecInt32StoreZ(const vec_int32& v, int32 *ptr)
	{
		#if defined(TERATHON_SSE)

			*ptr = _mm_cvtsi128_si32(_mm_shuffle_epi32(v, _MM_SHUFFLE(2, 2, 2, 2)));

		#elif defined(TERATHON_NEON)

			vst1q_lane_s32(ptr, v, 2);

		#endif
	}

	inline void VecInt32StoreW(const vec_int32& v, int32 *ptr)
	{
		#if defined(TERATHON_SSE)

			*ptr = _mm_cvtsi128_si32(_mm_shuffle_epi32(v, _MM_SHUFFLE(3, 3, 3, 3)));

		#elif defined(TERATHON_NEON)

			vst1q_lane_s32(ptr, v, 3);

		#endif
	}

	inline vec_int16 VecInt32PackSaturate(const vec_int32& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_packs_epi32(v, v));

		#elif defined(TERATHON_NEON)

			int16x4_t r = vqmovn_s32(v);
			return (vcombine_s16(r, r));

		#endif
	}

	inline vec_int16 VecInt32PackSaturate(const vec_int32& v1, const vec_int32& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_packs_epi32(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vcombine_s16(vqmovn_s32(v1), vqmovn_s32(v2)));

		#endif
	}

	inline vec_int8 VecInt16PackSaturate(const vec_int16& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_packs_epi16(v, v));

		#elif defined(TERATHON_NEON)

			int8x8_t r = vqmovn_s16(v);
			return (vcombine_s8(r, r));

		#endif
	}

	inline vec_uint8 VecInt16PackUnsignedSaturate(const vec_int16& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_packus_epi16(v, v));

		#elif defined(TERATHON_NEON)

			uint8x8_t r = vqmovun_s16(v);
			return (vcombine_u8(r, r));

		#endif
	}

	inline vec_int16 VecInt8UnpackA(const vec_int8& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_unpacklo_epi8(v, _mm_cmplt_epi8(v, _mm_setzero_si128())));

		#elif defined(TERATHON_NEON)

			return (vmovl_s8(vget_low_s8(v)));

		#endif
	}

	inline vec_int16 VecInt8UnpackB(const vec_int8& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_unpackhi_epi8(v, _mm_cmplt_epi8(v, _mm_setzero_si128())));

		#elif defined(TERATHON_NEON)

			return (vmovl_s8(vget_high_s8(v)));

		#endif
	}

	inline vec_uint16 VecUInt8UnpackA(const vec_uint8& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_unpacklo_epi8(v, _mm_setzero_si128()));

		#elif defined(TERATHON_NEON)

			return (vmovl_u8(vget_low_u8(v)));

		#endif
	}

	inline vec_uint16 VecUInt8UnpackB(const vec_uint8& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_unpackhi_epi8(v, _mm_setzero_si128()));

		#elif defined(TERATHON_NEON)

			return (vmovl_u8(vget_high_u8(v)));

		#endif
	}

	inline vec_int32 VecInt16UnpackA(const vec_int16& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_unpacklo_epi16(v, _mm_cmplt_epi16(v, _mm_setzero_si128())));

		#elif defined(TERATHON_NEON)

			return (vmovl_s16(vget_low_s16(v)));

		#endif
	}

	inline vec_int32 VecInt16UnpackB(const vec_int16& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_unpackhi_epi16(v, _mm_cmplt_epi16(v, _mm_setzero_si128())));

		#elif defined(TERATHON_NEON)

			return (vmovl_s16(vget_high_s16(v)));

		#endif
	}

	inline vec_uint32 VecUInt16UnpackA(const vec_uint16& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_unpacklo_epi16(v, _mm_setzero_si128()));

		#elif defined(TERATHON_NEON)

			return (vmovl_u16(vget_low_u16(v)));

		#endif
	}

	inline vec_uint32 VecUInt16UnpackB(const vec_uint16& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_unpackhi_epi16(v, _mm_setzero_si128()));

		#elif defined(TERATHON_NEON)

			return (vmovl_u16(vget_high_u16(v)));

		#endif
	}

	inline vec_int8 VecInt8MergeA(const vec_int8& v1, const vec_int8& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_unpacklo_epi8(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vzipq_s8(v1, v2).val[0]);

		#endif
	}

	inline vec_int8 VecInt8MergeB(const vec_int8& v1, const vec_int8& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_unpackhi_epi8(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vzipq_s8(v1, v2).val[1]);

		#endif
	}

	inline vec_uint8 VecUInt8MergeA(const vec_uint8& v1, const vec_uint8& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_unpacklo_epi8(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vzipq_u8(v1, v2).val[0]);

		#endif
	}

	inline vec_uint8 VecUInt8MergeB(const vec_uint8& v1, const vec_uint8& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_unpackhi_epi8(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vzipq_u8(v1, v2).val[1]);

		#endif
	}

	inline vec_int16 VecInt16Deinterleave(const vec_int16& v)
	{
		#if defined(TERATHON_SSE)

			vec_int16 i = _mm_shufflelo_epi16(v, _MM_SHUFFLE(3, 1, 2, 0));
			i = _mm_shufflehi_epi16(i, _MM_SHUFFLE(3, 1, 2, 0));
			return (_mm_shuffle_epi32(i, _MM_SHUFFLE(3, 1, 2, 0)));

		#elif defined(TERATHON_NEON)

			int16x4x2_t r = vuzp_s16(vget_low_s16(v), vget_high_s16(v));
			return (vcombine_s16(r.val[0], r.val[1]));

		#endif
	}

	inline vec_float VecInt32ConvertFloat(const vec_int32& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_cvtepi32_ps(v));

		#elif defined(TERATHON_NEON)

			return (vcvtq_f32_s32(v));

		#endif
	}

	inline vec_int32 VecConvertInt32(const vec_float& v)
	{
		#if defined(TERATHON_SSE)

			return (_mm_cvtps_epi32(v));

		#elif defined(TERATHON_NEON)

			return (vcvtq_s32_f32(v));

		#endif
	}

	inline vec_int32 VecInt32Add(const vec_int32& v1, const vec_int32& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_add_epi32(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vaddq_s32(v1, v2));

		#endif
	}

	inline vec_int32 VecInt32Sub(const vec_int32& v1, const vec_int32& v2)
	{
		#if defined(TERATHON_SSE)

			return (_mm_sub_epi32(v1, v2));

		#elif defined(TERATHON_NEON)

			return (vsubq_s32(v1, v2));

		#endif
	}

	#if defined(TERATHON_AVX)

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

		inline exv_float operator *(const exv_float& v1, const exv_float& v2)
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
