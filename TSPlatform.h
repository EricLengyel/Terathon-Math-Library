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


#ifndef TSPlatform_h
#define TSPlatform_h


#if defined(TERATHON_EXPORT)

	#if defined(_MSC_VER)

		#define TERATHON_API __declspec(dllexport)

	#elif defined(__GNUC__)

		#define TERATHON_API __attribute__((visibility("default")))

	#else

		#define TERATHON_API

	#endif

#elif defined(TERATHON_IMPORT)

	#if defined(_MSC_VER)

		#define TERATHON_API __declspec(dllimport)

	#else

		#define TERATHON_API

	#endif

#else

	#define TERATHON_API

#endif


#ifdef TERATHON_NO_SYSTEM

	void *__cdecl operator new(size_t);
	void *__cdecl operator new[](size_t);
	void __cdecl operator delete(void *);
	void __cdecl operator delete[](void *);

	inline void *__cdecl operator new(size_t, void *ptr)
	{
		return (ptr);
	}

	inline void *__cdecl operator new[](size_t, void *ptr)
	{
		return (ptr);
	}

	inline void __cdecl operator delete(void *, void *)
	{
	}

	inline void __cdecl operator delete[](void *, void *)
	{
	}

	extern "C"
	{
		void *__cdecl memcpy(void *, const void *, size_t);
		#pragma intrinsic(memcpy)

		void *__cdecl memset(void *, int, size_t);
		#pragma intrinsic(memset)
	}

#else

	#if defined(_MSC_VER)

		#pragma warning(push)
		#pragma warning(disable: 4530)		// C++ exception handler used, but unwind semantics are not enabled
		#pragma warning(disable: 4577)		// 'noexcept' used with no exception handling mode specified

	#endif

	#include <new>
	#include <string.h>

	#if defined(_MSC_VER)

		#pragma warning(pop)

	#endif

#endif


namespace Terathon
{
	#if defined(_MSC_VER)

		typedef signed char				int8;
		typedef short					int16;
		typedef int						int32;
		typedef __int64					int64;
		typedef unsigned char			uint8;
		typedef unsigned short			uint16;
		typedef unsigned int			uint32;
		typedef unsigned __int64		uint64;

		#ifdef _M_X64

			typedef __int64				machine;
			typedef unsigned __int64	umachine;

		#else

			typedef int					machine;
			typedef unsigned int		umachine;

		#endif

		#define restrict __restrict

		#pragma warning(disable: 4100)		// unreferenced formal parameter
		#pragma warning(disable: 4244)		// conversion, possible loss of data
		#pragma warning(disable: 4324)		// structure was padded due to alignment specifier
		#pragma warning(disable: 4458)		// declaration hides class member
		#pragma warning(disable: 4522)		// multiple assignment operators specified

	#elif defined(__ORBIS__) || defined(__PROSPERO__)

		typedef signed char				int8;
		typedef short					int16;
		typedef int						int32;
		typedef long					int64;
		typedef long					machine;
		typedef unsigned char			uint8;
		typedef unsigned short			uint16;
		typedef unsigned int			uint32;
		typedef unsigned long			uint64;
		typedef unsigned long			umachine;

	#elif defined(__GNUC__)

		typedef signed char				int8;
		typedef short					int16;
		typedef int						int32;
		typedef long long				int64;
		typedef long long				machine;
		typedef unsigned char			uint8;
		typedef unsigned short			uint16;
		typedef unsigned int			uint32;
		typedef unsigned long long		uint64;
		typedef unsigned long long		umachine;

		#if !defined(restrict)

			#define restrict __restrict__

		#endif

	#endif


	typedef uint64 machine_address;


	inline machine_address GetPointerAddress(const volatile void *ptr)
	{
		return (reinterpret_cast<machine_address>(ptr));
	}


	inline const float& asfloat(const int32& i)
	{
		return (reinterpret_cast<const float&>(i));
	}

	inline const float& asfloat(const uint32& i)
	{
		return (reinterpret_cast<const float&>(i));
	}

	inline const int32& asint(const float& f)
	{
		return (reinterpret_cast<const int32&>(f));
	}

	inline const uint32& asuint(const float& f)
	{
		return (reinterpret_cast<const uint32&>(f));
	}


	#undef CopyMemory
	#undef FillMemory
	#undef ClearMemory


	inline void CopyMemory(const void *source, void *dest, uint32 size)
	{
		memcpy(dest, source, size);
	}

	inline void FillMemory(void *ptr, uint32 size, uint8 value)
	{
		memset(ptr, value, size);
	}

	inline void ClearMemory(void *ptr, uint32 size)
	{
		memset(ptr, 0, size);
	}
}


#endif
