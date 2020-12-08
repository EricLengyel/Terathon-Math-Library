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


#ifndef TSBivector3D_h
#define TSBivector3D_h


//# \component	Math Library
//# \prefix		Math/


#include "TSVector3D.h"


#define TERATHON_BIVECTOR3D 1


namespace Terathon
{
	class Bivector3D;
	struct ConstBivector3D;


	struct TypeBivector3D
	{
		typedef float component_type;
		typedef Vector2D vector2D_type;
		typedef Bivector3D vector3D_type;
	};


	class Bivector3D : public Antivec3D<TypeBivector3D>
	{
		public:

			inline Bivector3D() = default;

			Bivector3D(float a, float b, float c) : Antivec3D<TypeBivector3D>(a, b, c) {}

			template <typename type>
			explicit Bivector3D(const Antivec3D<type>& v) : Antivec3D<TypeBivector3D>(float(v.x), float(v.y), float(v.z)) {}

			Bivector3D(const Point2D& a, const Point2D& b)
			{
				xyz.Set(a.y - b.y, b.x - a.x, a.x * b.y - a.y * b.x);
			}

			Bivector3D(const Point2D& p, const Vector2D& v)
			{
				xyz.Set(-v.y, v.x, p.x * v.y - p.y * v.x);
			}

			Bivector3D& Set(float a, float b, float c)
			{
				xyz.Set(a, b, c);
				return (*this);
			}

			void Set(float a, float b, float c) volatile
			{
				xyz.Set(a, b, c);
			}

			Bivector3D& Set(const Point2D& a, const Point2D& b)
			{
				xyz.Set(a.y - b.y, b.x - a.x, a.x * b.y - a.y * b.x);
				return (*this);
			}

			void Set(const Point2D& a, const Point2D& b) volatile
			{
				xyz.Set(a.y - b.y, b.x - a.x, a.x * b.y - a.y * b.x);
			}

			Bivector3D& Set(const Point2D& p, const Vector2D& v)
			{
				xyz.Set(-v.y, v.x, p.x * v.y - p.y * v.x);
				return (*this);
			}

			void Set(const Point2D& p, const Vector2D& v) volatile
			{
				xyz.Set(-v.y, v.x, p.x * v.y - p.y * v.x);
			}

			Bivector3D& operator =(const Bivector3D& v)
			{
				xyz = v.xyz;
				return (*this);
			}

			void operator =(const Bivector3D& v) volatile
			{
				xyz = v.xyz;
			}

			template <typename type_struct, int count, int index_x, int index_y, int index_z>
			Bivector3D& operator =(const Subvec3D<type_struct, true, count, index_x, index_y, index_z>& v)
			{
				xyz = v;
				return (*this);
			}

			template <typename type_struct, int count, int index_x, int index_y, int index_z>
			void operator =(const Subvec3D<type_struct, true, count, index_x, index_y, index_z>& v) volatile
			{
				xyz = v;
			}

			Bivector3D& operator +=(const Bivector3D& v)
			{
				xyz += v.xyz;
				return (*this);
			}

			template <typename type_struct, int count, int index_x, int index_y, int index_z>
			Bivector3D& operator +=(const Subvec3D<type_struct, true, count, index_x, index_y, index_z>& v)
			{
				xyz += v;
				return (*this);
			}

			Bivector3D& operator -=(const Bivector3D& v)
			{
				xyz += v.xyz;
				return (*this);
			}

			template <typename type_struct, int count, int index_x, int index_y, int index_z>
			Bivector3D& operator -=(const Subvec3D<type_struct, true, count, index_x, index_y, index_z>& v)
			{
				xyz -= v;
				return (*this);
			}

			Bivector3D& operator *=(float s)
			{
				xyz *= s;
				return (*this);
			}

			Bivector3D& operator /=(float s)
			{
				xyz /= s;
				return (*this);
			}

			Bivector3D& Normalize(void)
			{
				return (static_cast<Bivector3D&>(xyz.Normalize()));
			}

			TERATHON_API static const ConstBivector3D yz_unit;
			TERATHON_API static const ConstBivector3D zx_unit;
			TERATHON_API static const ConstBivector3D xy_unit;

			TERATHON_API static const ConstBivector3D minus_yz_unit;
			TERATHON_API static const ConstBivector3D minus_zx_unit;
			TERATHON_API static const ConstBivector3D minus_xy_unit;
	};


	inline const Bivector3D& operator !(const Vector3D& v)
	{
		return (reinterpret_cast<const Bivector3D&>(v));
	}

	inline const Vector3D& operator !(const Bivector3D& v)
	{
		return (reinterpret_cast<const Vector3D&>(v));
	}

	inline const Bivector3D& Complement(const Vector3D& v)
	{
		return (reinterpret_cast<const Bivector3D&>(v));
	}

	inline const Vector3D& Complement(const Bivector3D& v)
	{
		return (reinterpret_cast<const Vector3D&>(v));
	}

	inline Bivector3D operator -(const Bivector3D& v)
	{
		return (Bivector3D(-v.x, -v.y, -v.z));
	}

	inline Bivector3D operator +(const Bivector3D& a, const Bivector3D& b)
	{
		return (Bivector3D(a.x + b.x, a.y + b.y, a.z + b.z));
	}

	inline Bivector3D operator -(const Bivector3D& a, const Bivector3D& b)
	{
		return (Bivector3D(a.x - b.x, a.y - b.y, a.z - b.z));
	}

	inline Bivector3D operator *(const Bivector3D& v, float s)
	{
		return (Bivector3D(v.x * s, v.y * s, v.z * s));
	}

	inline Bivector3D operator *(float s, const Bivector3D& v)
	{
		return (Bivector3D(s * v.x, s * v.y, s * v.z));
	}

	inline Bivector3D operator /(const Bivector3D& v, float s)
	{
		s = 1.0F / s;
		return (Bivector3D(v.x * s, v.y * s, v.z * s));
	}

	inline Bivector3D operator *(const Bivector3D& a, const Bivector3D& b)
	{
		return (Bivector3D(a.x * b.x, a.y * b.y, a.z * b.z));
	}

	inline Bivector3D operator ^(const Vector3D& a, const Vector3D& b)
	{
		return (Bivector3D(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x));
	}

	inline Bivector3D operator ^(const Point2D& a, const Point2D& b)
	{
		return (Bivector3D(a.y - b.y, b.x - a.x, a.x * b.y - a.y * b.x));
	}

	inline Bivector3D operator ^(const Point2D& p, const Vector2D& v)
	{
		return (Bivector3D(-v.y, v.x, p.x * v.y - p.y * v.x));
	}

	inline Vector3D operator ^(const Bivector3D& a, const Bivector3D& b)
	{
		return (Vector3D(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x));
	}

	inline float operator ^(const Bivector3D& a, const Vector3D& b)
	{
		return (a.xyz ^ b.xyz);
	}

	inline float operator ^(const Vector3D& a, const Bivector3D& b)
	{
		return (a.xyz ^ b.xyz);
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z>
	inline float operator ^(const Bivector3D& a, const Subvec3D<type_struct, false, count, index_x, index_y, index_z>& b)
	{
		return (a.xyz ^ b);
	}

	inline Bivector3D Wedge(const Vector3D& a, const Vector3D& b)
	{
		return (a ^ b);
	}

	inline Bivector3D Wedge(const Point2D& a, const Point2D& b)
	{
		return (a ^ b);
	}

	inline Bivector3D Wedge(const Point2D& p, const Vector2D& v)
	{
		return (p ^ v);
	}

	inline Vector3D Antiwedge(const Bivector3D& a, const Bivector3D& b)
	{
		return (a ^ b);
	}

	inline float Antiwedge(const Bivector3D& a, const Vector3D& b)
	{
		return (a ^ b);
	}

	inline float Antiwedge(const Vector3D& a, const Bivector3D& b)
	{
		return (a ^ b);
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z>
	inline float Antiwedge(const Bivector3D& a, const Subvec3D<type_struct, false, count, index_x, index_y, index_z>& b)
	{
		return (a ^ b);
	}

	inline float Dot(const Bivector3D& a, const Bivector3D& b)
	{
		return (a.x * b.x + a.y * b.y + a.z * b.z);
	}

	inline Bivector3D Project(const Bivector3D& a, const Vector3D& b)
	{
		return (!b * (a ^ b));
	}

	inline Bivector3D Reject(const Bivector3D& a, const Vector3D& b)
	{
		return (a - !b * (a ^ b));
	}

	inline float Magnitude(const Bivector3D& v)
	{
		return (Sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	}

	inline float InverseMag(const Bivector3D& v)
	{
		return (InverseSqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	}

	inline float SquaredMag(const Bivector3D& v)
	{
		return (v.x * v.x + v.y * v.y + v.z * v.z);
	}

	inline Bivector3D Normalize(const Bivector3D& v)
	{
		return (v * InverseSqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	}


	struct ConstBivector3D
	{
		float	x;
		float	y;
		float	z;

		operator const Bivector3D&(void) const
		{
			return (reinterpret_cast<const Bivector3D&>(*this));
		}

		const Bivector3D *operator &(void) const
		{
			return (reinterpret_cast<const Bivector3D *>(this));
		}
	};


	class Bizero3DType
	{
		private:

			TERATHON_API static ConstBivector3D zero;

		public:

			operator const Bivector3D&(void) const
			{
				return (zero);
			}
	};


	TERATHON_API extern const Bizero3DType Bizero3D;
}


#endif
