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


	//# \class	Bivector3D		Encapsulates a 3D bivector.
	//
	//# The $Bivector3D$ class encapsulates a 3D bivector.
	//
	//# \def	class Bivector3D
	//
	//# \ctor	Bivector3D();
	//# \ctor	Bivector3D(float a, float b, float c);
	//# \ctor	Bivector4D(const Point2D& p, const Point2D& q);
	//# \ctor	Bivector4D(const Point2D& p, const Vector2D& v);
	//
	//# \param	a		The value of the <b>e</b><sub>23</sub> coordinate.
	//# \param	b		The value of the <b>e</b><sub>31</sub> coordinate.
	//# \param	c		The value of the <b>e</b><sub>12</sub> coordinate.
	//# \param	p,q		Two 2D points that lie on the line.
	//# \param	v		A 2D direction vector.
	//
	//# \desc
	//# The $Bivector3D$ class is used to store a three-dimensional bivector having three floating-point components
	//# named $x$, $y$, and $z$.
	//#
	//# The default constructor leaves the components of the bivector undefined.
	//#
	//# If points $p$ and $q$ are specified, then the bivector is initialized to the wedge product between homogeneous
	//# extensions of $p$ and $q$ with <i>z</i> coordinates set to 1, giving a representation of the 2D line containing
	//# both points. If the point $p$ and the direction $v$ are specified, then the line contains the point $p$ and runs
	//# parallel to the direction $v$.
	//
	//# \operator	Bivector3D& operator +=(const Bivector3D& v);
	//#				Adds the bivector $v$.
	//
	//# \operator	Bivector3D& operator -=(const Bivector3D& v);
	//#				Subtracts the bivector $v$.
	//
	//# \operator	Bivector3D& operator *=(float s);
	//#				Multiplies by the scalar $s$.
	//
	//# \operator	Bivector3D& operator /=(float s);
	//#				Multiplies by the inverse of the scalar $s$.
	//
	//# \action		bool operator ==(const Bivector3D& a, const Bivector3D& b);
	//#				Returns a boolean value indicating whether the two bivectors $a$ and $b$ are equal.
	//
	//# \action		bool operator !=(const Bivector3D& a, const Bivector3D& b);
	//#				Returns a boolean value indicating whether the two bivectors $a$ and $b$ are not equal.
	//
	//# \action		Bivector3D operator !(const Vector3D& v);
	//#				Returns the complement of the vector $v$.
	//
	//# \action		Vector3D operator !(const Bivector3D& v);
	//#				Returns the complement of the bivector $v$.
	//
	//# \action		Bivector3D operator -(const Bivector3D& v);
	//#				Returns the negation of the bivector $v$.
	//
	//# \action		Bivector3D operator +(const Bivector3D& a, const Bivector3D& b);
	//#				Returns the sum of the bivectors $a$ and $b$.
	//
	//# \action		Bivector3D operator -(const Bivector3D& a, const Bivector3D& b);
	//#				Returns the difference of the bivectors $a$ and $b$.
	//
	//# \action		Bivector3D operator *(const Bivector3D& v, float s);
	//#				Returns the product of the bivector $v$ and the scalar $s$.
	//
	//# \action		Bivector3D operator *(float s, const Bivector3D& L);
	//#				Returns the product of the bivector $v$ and the scalar $s$.
	//
	//# \action		Bivector3D operator /(const Bivector3D& v, float s);
	//#				Returns the product of the bivector $v$ and the inverse of the scalar $s$.
	//
	//# \action		bool operator ==(const Bivector3D& a, const Bivector3D& b);
	//#				Returns a boolean value indicating whether the two bivectors $a$ and $b$ are equal.
	//
	//# \action		bool operator !=(const Bivector3D& a, const Bivector3D& b);
	//#				Returns a boolean value indicating whether the two bivectors $a$ and $b$ are not equal.
	//
	//# \action		Bivector3D operator ^(const Vector3D& a, const Vector3D& b);
	//#				Returns the wedge product of the vectors $a$ and $b$.
	//
	//# \action		Bivector3D operator ^(const Point2D& p, const Point2D& q);
	//#				Returns the wedge product of the 2D points $p$ and $q$. The <i>z</i> coordinates of $p$ and $q$ are assumed to be 1.
	//
	//# \action		Bivector3D operator ^(const Point2D& p, const Vector2D& v);
	//#				Returns the wedge product of the 2D point $p$ and the 2D vector $v$. The <i>z</i> coordinate of $p$ is assumed to be 1.
	//
	//# \action		Vector3D operator ^(const Bivector3D& a, const Bivector3D& b);
	//#				Returns the antiwedge product of the bivectors $a$ and $b$.
	//
	//# \action		float operator ^(const Bivector3D& a, const Vector3D& b);
	//#				Returns the antiwedge product of the bivector $a$ and the vector $b$.
	//
	//# \action		float operator ^(const Vector3D& a, const Bivector3D& b);
	//#				Returns the antiwedge product of the vector $a$ and the bivector $b$.
	//
	//# \action		Vector3D Project(const Vector3D& a, const Bivector3D& b);
	//#				Returns (<b>b&#x0332;</b>&#x202F;&#x2227;&#x202F;<b>a</b>)&#x202F;&#x2228;&#x202F;<b>b</b>, which is the projection of $a$ onto $b$ under the assumption that the magnitude of $b$ is one.
	//
	//# \also	$@Vector3D@$
	//# \also	$@Vector2D@$
	//# \also	$@Point2D@$


	//# \function	Bivector3D::Set		Sets all three components of a bivector.
	//
	//# \proto	Bivector3D& Set(float a, float b, float c);
	//# \proto	Bivector3D& Set(const Point2D& p, const Point2D& q);
	//# \proto	Bivector3D& Set(const Point2D& p, const Vector2D& v);
	//
	//# \param	a		The value of the <b>e</b><sub>23</sub> coordinate.
	//# \param	b		The value of the <b>e</b><sub>31</sub> coordinate.
	//# \param	c		The value of the <b>e</b><sub>12</sub> coordinate.
	//# \param	p,q		Two 2D points that lie on the line.
	//# \param	v		A 2D direction vector.
	//
	//# \desc
	//# The $Set$ function replaces all three components of a bivector with new values.
	//#
	//# If points $p$ and $q$ are specified, then the bivector is initialized to the wedge product between homogeneous
	//# extensions of $p$ and $q$ with <i>z</i> coordinates set to 1, giving a representation of the 2D line containing
	//# both points. If the point $p$ and the direction $v$ are specified, then the line contains the point $p$ and runs
	//# parallel to the direction $v$.
	//#
	//# The return value is a reference to the bivector object.


	class Bivector3D : public Antivec3D<TypeBivector3D>
	{
		public:

			inline Bivector3D() = default;

			Bivector3D(float a, float b, float c) : Antivec3D<TypeBivector3D>(a, b, c) {}

			template <typename type>
			explicit Bivector3D(const Antivec3D<type>& v) : Antivec3D<TypeBivector3D>(float(v.x), float(v.y), float(v.z)) {}

			Bivector3D(const Point2D& p, const Point2D& q)
			{
				xyz.Set(p.y - q.y, q.x - p.x, p.x * q.y - p.y * q.x);
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

			Bivector3D& Set(const Point2D& p, const Point2D& q)
			{
				xyz.Set(p.y - q.y, q.x - p.x, p.x * q.y - p.y * q.x);
				return (*this);
			}

			void Set(const Point2D& p, const Point2D& q) volatile
			{
				xyz.Set(p.y - q.y, q.x - p.x, p.x * q.y - p.y * q.x);
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

	inline Bivector3D operator ^(const Point2D& p, const Point2D& q)
	{
		return (Bivector3D(p.y - q.y, q.x - p.x, p.x * q.y - p.y * q.x));
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

	inline Bivector3D Wedge(const Point2D& p, const Point2D& q)
	{
		return (p ^ q);
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

	inline Vector3D Project(const Vector3D& a, const Bivector3D& b)
	{
		return ((!b ^ a) ^ b);
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
