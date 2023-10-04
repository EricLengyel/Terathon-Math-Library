//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2023, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSBivector3D_h
#define TSBivector3D_h


#include "TSVector3D.h"


#define TERATHON_BIVECTOR3D 1


namespace Terathon
{
	class Bivector3D;
	struct ConstBivector3D;


	//# \class	Bivector3D		Encapsulates a 3D bivector.
	//
	//# The $Bivector3D$ class encapsulates a 3D bivector.
	//
	//# \def	class Bivector3D : public Antivec3D<TypeBivector3D>
	//
	//# \ctor	Bivector3D();
	//# \ctor	Bivector3D(float a, float b, float c);
	//
	//# \param	a		The value of the <b>e</b><sub>23</sub> coordinate.
	//# \param	b		The value of the <b>e</b><sub>31</sub> coordinate.
	//# \param	c		The value of the <b>e</b><sub>12</sub> coordinate.
	//
	//# \desc
	//# The $Bivector3D$ class is used to store a three-dimensional bivector having three floating-point components
	//# named $x$, $y$, and $z$.
	//#
	//# \operator	Bivector3D& operator +=(const Bivector3D& v);
	//#				Adds the bivector $v$.
	//
	//# \operator	Bivector3D& operator -=(const Bivector3D& v);
	//#				Subtracts the bivector $v$.
	//
	//# \operator	Bivector3D& operator *=(float n);
	//#				Multiplies by the scalar $n$.
	//
	//# \operator	Bivector3D& operator /=(float n);
	//#				Multiplies by the inverse of the scalar $n$.
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
	//# \action		Bivector3D operator *(const Bivector3D& v, float n);
	//#				Returns the product of the bivector $v$ and the scalar $n$.
	//
	//# \action		Bivector3D operator *(float n, const Bivector3D& v);
	//#				Returns the product of the bivector $v$ and the scalar $n$.
	//
	//# \action		Bivector3D operator /(const Bivector3D& v, float n);
	//#				Returns the product of the bivector $v$ and the inverse of the scalar $n$.
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
	//# \privbase	Antivec3D	Antivectors use a generic base class to store their components.
	//
	//# \also	$@Vector3D@$
	//# \also	$@Vector2D@$
	//# \also	$@Point2D@$


	// ==============================================
	//	Bivector3D
	// ==============================================

	struct TypeBivector3D
	{
		typedef float component_type;
		typedef Vector2D vector2D_type;
		typedef Bivector3D vector3D_type;
	};


	/// @brief Encapsulates a 3D bivector.
	///
	/// The \c Bivector3D class is used to store a three-dimensional bivector having floating-point
	/// components <i>x</i>, <i>y</i>, and <i>z</i>.
	///
	/// @sa Vector3D

	class Bivector3D : public Antivec3D<TypeBivector3D>
	{
		public:

			TERATHON_API static const ConstBivector3D zero;

			TERATHON_API static const ConstBivector3D yz_unit;
			TERATHON_API static const ConstBivector3D zx_unit;
			TERATHON_API static const ConstBivector3D xy_unit;

			TERATHON_API static const ConstBivector3D minus_yz_unit;
			TERATHON_API static const ConstBivector3D minus_zx_unit;
			TERATHON_API static const ConstBivector3D minus_xy_unit;

			/// @brief Default constructor that leaves the components uninitialized.

			inline Bivector3D() = default;

			/// @brief Constructor that sets components explicitly.
			/// @param a,b,c	The components of the bivector.

			Bivector3D(float a, float b, float c) : Antivec3D<TypeBivector3D>(a, b, c) {}

			template <typename type>
			explicit Bivector3D(const Antivec3D<type>& v) : Antivec3D<TypeBivector3D>(float(v.x), float(v.y), float(v.z)) {}

			/// @brief Sets all three components of a 3D bivector.
			/// @param a,b,c	The new components of the bivector.

			Bivector3D& Set(float a, float b, float c)
			{
				xyz.Set(a, b, c);
				return (*this);
			}

			void Set(float a, float b, float c) volatile
			{
				xyz.Set(a, b, c);
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

			Bivector3D& operator *=(float n)
			{
				xyz *= n;
				return (*this);
			}

			Bivector3D& operator /=(float n)
			{
				xyz /= n;
				return (*this);
			}

			Bivector3D& Normalize(void)
			{
				return (static_cast<Bivector3D&>(xyz.Normalize()));
			}
	};


	/// @brief Returns the negation of the 3D bivector \c v.
	/// @related Bivector3D

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

	/// @brief Returns the product of the 3D bivector \c v and the scalar \c n.
	/// @related Bivector3D

	inline Bivector3D operator *(const Bivector3D& v, float n)
	{
		return (Bivector3D(v.x * n, v.y * n, v.z * n));
	}

	/// @brief Returns the product of the 3D bivector \c v and the scalar \c n.
	/// @related Bivector3D

	inline Bivector3D operator *(float n, const Bivector3D& v)
	{
		return (Bivector3D(n * v.x, n * v.y, n * v.z));
	}

	/// @brief Returns the product of the 3D bivector \c v and the inverse of the scalar \c n.
	/// @related Bivector3D

	inline Bivector3D operator /(const Bivector3D& v, float n)
	{
		n = 1.0F / n;
		return (Bivector3D(v.x * n, v.y * n, v.z * n));
	}

	/// @brief Returns the componentwise product of the 3D bivectors \c a and \c b.
	/// @related Bivector3D

	inline Bivector3D operator *(const Bivector3D& a, const Bivector3D& b)
	{
		return (Bivector3D(a.x * b.x, a.y * b.y, a.z * b.z));
	}

	// ==============================================
	//	Magnitude
	// ==============================================

	/// @brief Returns the magnitude of the 3D bivector \c v.
	/// @relatedalso Bivector3D

	inline float Magnitude(const Bivector3D& v)
	{
		return (Sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	}

	/// @brief Returns the inverse magnitude of the 3D bivector \c v.
	/// @relatedalso Bivector3D

	inline float InverseMag(const Bivector3D& v)
	{
		return (InverseSqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	}

	/// @brief Returns the squared magnitude of the 3D bivector \c v.
	/// @relatedalso Bivector3D

	inline float SquaredMag(const Bivector3D& v)
	{
		return (v.x * v.x + v.y * v.y + v.z * v.z);
	}

	/// @brief Calculates the normalized version of the 3D bivector \c v.
	///
	/// Multiplies the 3D bivector \c v by the inverse of its magnitude. The return value is a
	/// bivector having unit area with the same attitude as \c v. If the magnitude of \c v is
	/// zero, then the result is undefined.
	///
	/// @relatedalso Bivector3D

	inline Bivector3D Normalize(const Bivector3D& v)
	{
		return (v * InverseSqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	}

	// ==============================================
	//	Dot
	// ==============================================

	/// @brief Calculates the dot product of the 3D bivectors \c a and \c b.
	/// @relatedalso Bivector3D

	inline float Dot(const Bivector3D& a, const Bivector3D& b)
	{
		return (a.x * b.x + a.y * b.y + a.z * b.z);
	}

	// ==============================================
	//	Complement
	// ==============================================

	inline const Bivector3D& Complement(const Vector3D& v)
	{
		return (reinterpret_cast<const Bivector3D&>(v));
	}

	inline const Vector3D& Complement(const Bivector3D& v)
	{
		return (reinterpret_cast<const Vector3D&>(v));
	}

	inline auto operator !(const Vector3D& v) {return (Complement(v));}
	inline auto operator !(const Bivector3D& v) {return (Complement(v));}

	// ==============================================
	//	Wedge
	// ==============================================

	inline Bivector3D Wedge(const Vector3D& a, const Vector3D& b)
	{
		return (Bivector3D(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x));
	}

	inline Vector3D Antiwedge(const Bivector3D& a, const Bivector3D& b)
	{
		return (Vector3D(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x));
	}

	inline float Antiwedge(const Bivector3D& a, const Vector3D& b)
	{
		return (a.xyz ^ b.xyz);
	}

	inline float Antiwedge(const Vector3D& a, const Bivector3D& b)
	{
		return (a.xyz ^ b.xyz);
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z>
	inline float Antiwedge(const Bivector3D& a, const Subvec3D<type_struct, false, count, index_x, index_y, index_z>& b)
	{
		return (a.xyz ^ b);
	}

	inline auto operator ^(const Vector3D& a, const Vector3D& b) {return (Wedge(a, b));}
	inline auto operator ^(const Bivector3D& a, const Bivector3D& b) {return (Antiwedge(a, b));}
	inline auto operator ^(const Bivector3D& a, const Vector3D& b) {return (Antiwedge(a, b));}
	inline auto operator ^(const Vector3D& a, const Bivector3D& b) {return (Antiwedge(a, b));}

	template <typename type_struct, int count, int index_x, int index_y, int index_z>
	inline auto operator ^(const Bivector3D& a, const Subvec3D<type_struct, false, count, index_x, index_y, index_z>& b) {return (Antiwedge(a, b));}


	// ==============================================
	//	POD Structures
	// ==============================================

	struct ConstBivector3D
	{
		float	x, y, z;

		operator const Bivector3D&(void) const
		{
			return (reinterpret_cast<const Bivector3D&>(*this));
		}

		const Bivector3D *operator &(void) const
		{
			return (reinterpret_cast<const Bivector3D *>(this));
		}

		const Bivector3D *operator ->(void) const
		{
			return (reinterpret_cast<const Bivector3D *>(this));
		}
	};


	typedef Bivector3D Antivector3D;
}


#endif
