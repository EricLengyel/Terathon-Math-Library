//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2022, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSTrivector4D_h
#define TSTrivector4D_h


//# \component	Math Library
//# \prefix		Math/


#include "TSVector4D.h"
#include "TSBivector3D.h"


#define TERATHON_TRIVECTOR4D 1


namespace Terathon
{
	class Trivector4D;
	struct ConstTrivector4D;


	//# \class	Trivector4D		Encapsulates a 4D trivector.
	//
	//# The $Trivector4D$ class encapsulates a 4D trivector.
	//
	//# \def	class Trivector4D : public Antivec4D<TypeTrivector4D>
	//
	//# \ctor	Trivector4D();
	//# \ctor	Trivector4D(float a, float b, float c, float d);
	//# \ctor	Trivector4D(const Bivector3D& n, float d);
	//# \ctor	Trivector4D(const Bivector3D& n, const Point3D& p);
	//# \ctor	Trivector4D(const Point3D& p1, const Point3D& p2, const Point3D& p3);
	//
	//# \param	a			The value of the <i>x</i> coordinate.
	//# \param	b			The value of the <i>y</i> coordinate.
	//# \param	c			The value of the <i>z</i> coordinate.
	//# \param	d			The value of the <i>w</i> coordinate.
	//# \param	n			A 3D bivector whose entries are copied to the <i>x</i>, <i>y</i>, and <i>z</i> coordinates.
	//# \param	p			A 3D point lying in the plane.
	//# \param	p1,p2,p3	Three 3D points that lie in the plane.
	//
	//# \desc
	//# The $Trivector4D$ class is used to store a four-dimensional trivector
	//# having floating-point components <i>x</i>, <i>y</i>, <i>z</i>, and <i>w</i>.
	//#
	//# The default constructor leaves the components of the trivector undefined.
	//# If the values $a$, $b$, $c$, and $d$ are supplied, then they are assigned to the
	//# <i>x</i>, <i>y</i>, <i>z</i>, and <i>w</i> coordinates of the trivector, respectively.
	//#
	//# If the $p$ parameter is specified, then the <i>w</i> coordinate is given by &minus;($n$&#x202F;&and;&#x202F;$p$).
	//# If the $p1$, $p2$, and $p3$ parameters are specified, then the trivector is set to the
	//# triple wedge product $p1$&#x202F;&and;&#x202F;$p2$&#x202F;&and;&#x202F;$p3$.
	//
	//# \operator	float& operator [](machine k);
	//#				Returns a reference to the $k$-th scalar component of a trivector.
	//#				The value of $k$ must be 0, 1, 2, or 3.
	//
	//# \operator	const float& operator [](machine k) const;
	//#				Returns a constant reference to the $k$-th scalar component of a trivector.
	//#				The value of $k$ must be 0, 1, 2, or 3.
	//
	//# \operator	Trivector4D& operator *=(float s);
	//#				Multiplies by the scalar $s$.
	//
	//# \operator	Trivector4D& operator /=(float s);
	//#				Multiplies by the inverse of the scalar $s$.
	//
	//# \action		bool operator ==(const Trivector4D& a, const Trivector4D& b);
	//#				Returns a boolean value indicating whether the two trivectors $a$ and $b$ are equal.
	//
	//# \action		bool operator !=(const Trivector4D& a, const Trivector4D& b);
	//#				Returns a boolean value indicating whether the two trivectors $a$ and $b$ are not equal.
	//
	//# \action		const Trivector4D& operator ~(const Trivector4D& v);
	//#				Returns the antireverse of the trivector $v$ (which is just the trivector $v$ itself).
	//
	//# \action		Trivector4D operator -(const Trivector4D& v);
	//#				Returns the negation of the trivector $v$.
	//
	//# \action		Trivector4D operator *(const Trivector4D& v, float s);
	//#				Returns the product of the trivector $v$ and the scalar $s$.
	//
	//# \action		Trivector4D operator *(float s, const Trivector4D& v);
	//#				Returns the product of the trivector $v$ and the scalar $s$.
	//
	//# \action		Trivector4D operator /(const Trivector4D& v, float s);
	//#				Returns the product of the trivector $v$ and the inverse of the scalar $s$.
	//
	//# \action		float operator ^(const Vector4D& v, const Trivector4D& f);
	//#				Returns the antiwedge product of the vector $v$ and the trivector $f$.
	//
	//# \action		float operator ^(const Vector3D& v, const Trivector4D& f);
	//#				Returns the antiwedge product of the 3D vector $v$ and the trivector $f$. The <i>w</i> coordinate of $v$ is assumed to be 0.
	//
	//# \action		float operator ^(const Point3D& p, const Trivector4D& v);
	//#				Returns the antiwedge product of the 3D point $p$ and the trivector $f$. The <i>w</i> coordinate of $p$ is assumed to be 1.
	//#				This gives the distance from a unitized plane represented by a $Trivector4D$ object to the point $p$.
	//
	//# \action		float operator ^(const Point2D& p, const Trivector4D& f);
	//#				Returns the antiwedge product of the 2D point $p$ and the trivector $f$. The <i>z</i> coordinate of $p$ is assumed to be 0, and the <i>w</i> coordinate of $p$ is assumed to be 1.
	//#				This gives the distance from a unitized plane represented by a $Trivector4D$ object to the point $p$.
	//
	//# \action		float BulkNorm(const Trivector4D& v);
	//#				Returns the bulk norm of the trivector $v$.
	//
	//# \action		float WeightNorm(const Trivector4D& v);
	//#				Returns the weight norm of the trivector $v$.
	//
	//# \action		Point3D Project(const Point3D& p, const Trivector4D& f);
	//#				Returns the projection of the point $p$ onto the plane $f$ under the assumption that the plane is unitized.
	//
	//# \action		Trivector4D Antiproject(const Trivector4D& f, const Point3D& p);
	//#				Returns the antiprojection of the plane $f$ onto the point $p$ (where $p$ is always unitized because it has an implicit <i>w</i> coordinate of 1).
	//
	//# \privbase	Antivec4D	Antivectors use a generic base class to store their components.
	//
	//# \also	$@Vector4D@$
	//# \also	$@Point3D@$
	//# \also	$@Point2D@$


	//# \function	Trivector4D::Set		Sets all four components of a trivector.
	//
	//# \proto	Trivector4D& Set(float a, float b, float c, float d);
	//# \proto	Trivector4D& Set(const Bivector3D& n, float d);
	//# \proto	Trivector4D& Set(const Bivector3D& n, const Point3D& p);
	//# \proto	Trivector4D& Set(const Point3D& p1, const Point3D& p2, const Point3D& p3);
	//
	//# \param	a			The new <i>x</i> coordinate.
	//# \param	b			The new <i>y</i> coordinate.
	//# \param	c			The new <i>z</i> coordinate.
	//# \param	d			The new <i>w</i> coordinate.
	//# \param	n			A 3D bivector whose entries are copied to the <i>x</i>, <i>y</i>, and <i>z</i> coordinates.
	//# \param	p			A 3D point lying in the plane.
	//# \param	p1,p2,p3	Three 3D points that lie in the plane.
	//
	//# \desc
	//# The $Set$ function sets the <i>x</i>, <i>y</i>, <i>z</i>, and <i>w</i> coordinates of a trivector to
	//# the values given by the $a$, $b$, $c$, and $d$ parameters, respectively.
	//#
	//# If the $p$ parameter is specified, then the <i>w</i> coordinate is given by &minus;($n$&#x202F;&and;&#x202F;$p$).
	//# If the $p1$, $p2$, and $p3$ parameters are specified, then the trivector is set to the
	//# triple wedge product $p1$&#x202F;&and;&#x202F;$p2$&#x202F;&and;&#x202F;$p3$.
	//#
	//# The return value is a reference to the trivector object.


	//# \function	Trivector4D::Unitize		Unitizes the weight of a 4D trivector.
	//
	//# \proto	Trivector4D& Unitize(void);
	//
	//# \desc
	//# The $Unitize$ function multiplies a 4D trivector by the inverse magnitude of its weight, which is the
	//# 3D bivector given by its <i>x</i>, <i>y</i>, and <i>z</i> coordinates. After calling this function, the plane
	//# has a unit-length normal. If the <i>x</i>, <i>y</i>, and <i>z</i> coordinates are all zero, then the result is undefined.
	//#
	//# The return value is a reference to the trivector object.


	struct TypeTrivector4D
	{
		typedef float component_type;
		typedef Vector2D vector2D_type;
		typedef Bivector3D vector3D_type;
		typedef Trivector4D vector4D_type;
	};


	class Trivector4D : public Antivec4D<TypeTrivector4D>
	{
		public:

			TERATHON_API static const ConstTrivector4D zero;
			TERATHON_API static const ConstTrivector4D infinity;

			inline Trivector4D() = default;

			Trivector4D(float a, float b, float c, float d) : Antivec4D<TypeTrivector4D>(a, b, c, d) {}

			Trivector4D(const Bivector3D& n, float d)
			{
				xyz = n.xyz;
				w = d;
			}

			Trivector4D(const Bivector3D& n, const Point3D& p)
			{
				xyz = n.xyz;
				w = -(n ^ p);
			}

			Trivector4D(const Point3D& p1, const Point3D& p2, const Point3D& p3)
			{
				xyz = (p2 - p1) ^ (p3 - p1);
				w = -(xyz ^ p1);
			}

			Trivector4D& Set(float a, float b, float c, float d)
			{
				xyzw.Set(a, b, c, d);
				return (*this);
			}

			void Set(float a, float b, float c, float d) volatile
			{
				xyzw.Set(a, b, c, d);
			}

			Trivector4D& Set(const Bivector3D& n, float d)
			{
				xyz.Set(n.x, n.y, n.z);
				w = d;
				return (*this);
			}

			void Set(const Bivector3D& n, float d) volatile
			{
				xyz.Set(n.x, n.y, n.z);
				w = d;
			}

			Trivector4D& Set(const Bivector3D& n, const Point3D& p)
			{
				xyz.Set(n.x, n.y, n.z);
				w = -(n ^ p);
				return (*this);
			}

			void Set(const Bivector3D& n, const Point3D& p) volatile
			{
				xyz.Set(n.x, n.y, n.z);
				w = -(n ^ p);
			}

			Trivector4D& Set(const Point3D& p1, const Point3D& p2, const Point3D& p3)
			{
				xyz = (p2 - p1) ^ (p3 - p1);
				w = -(xyz ^ p1);
				return (*this);
			}

			float& operator [](machine k)
			{
				return ((&x)[k]);
			}

			const float& operator [](machine k) const
			{
				return ((&x)[k]);
			}

			Trivector4D& operator =(const Trivector4D& v)
			{
				xyzw = v.xyzw;
				return (*this);
			}

			void operator =(const Trivector4D& v) volatile
			{
				xyzw = v.xyzw;
			}

			template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
			Trivector4D& operator =(const Subvec4D<type_struct, true, count, index_x, index_y, index_z, index_w>& v)
			{
				xyzw = v;
				return (*this);
			}

			template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
			void operator =(const Subvec4D<type_struct, true, count, index_x, index_y, index_z, index_w>& v) volatile
			{
				xyzw = v;
			}

			Trivector4D& operator *=(float s)
			{
				xyzw *= s;
				return (*this);
			}

			Trivector4D& operator /=(float s)
			{
				xyzw /= s;
				return (*this);
			}

			Trivector4D& Unitize(void)
			{
				return (*this *= InverseSqrt(x * x + y * y + z * z));
			}
	};


	inline const Trivector4D& operator !(const Vector4D& v)
	{
		return (reinterpret_cast<const Trivector4D&>(v));
	}

	inline const Vector4D& operator !(const Trivector4D& v)
	{
		return (reinterpret_cast<const Vector4D&>(v));
	}

	inline const Trivector4D& Complement(const Vector4D& v)
	{
		return (reinterpret_cast<const Trivector4D&>(v));
	}

	inline const Vector4D& Complement(const Trivector4D& v)
	{
		return (reinterpret_cast<const Vector4D&>(v));
	}

	inline const Trivector4D& operator ~(const Trivector4D& v)
	{
		return (v);
	}

	inline Trivector4D operator -(const Trivector4D& v)
	{
		return (Trivector4D(-v.x, -v.y, -v.z, -v.w));
	}

	inline Trivector4D operator *(const Trivector4D& v, float s)
	{
		return (Trivector4D(v.x * s, v.y * s, v.z * s, v.w * s));
	}

	inline Trivector4D operator *(float s, const Trivector4D& v)
	{
		return (Trivector4D(s * v.x, s * v.y, s * v.z, s * v.w));
	}

	inline Trivector4D operator /(const Trivector4D& v, float s)
	{
		s = 1.0F / s;
		return (Trivector4D(v.x * s, v.y * s, v.z * s, v.w * s));
	}

	inline float operator ^(const Vector4D& v, const Trivector4D& f)
	{
		return (v.xyzw ^ f.xyzw);
	}

	inline float operator ^(const Vector3D& v, const Trivector4D& f)
	{
		return (v.xyz ^ f.xyz);
	}

	inline float operator ^(const Point3D& p, const Trivector4D& f)
	{
		return ((p.xyz ^ f.xyz) + f.w);
	}

	inline float operator ^(const Point2D& p, const Trivector4D& f)
	{
		return (p.x * f.x + p.y * f.y + f.w);
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
	inline float operator ^(const Trivector4D& a, const Subvec4D<type_struct, false, count, index_x, index_y, index_z, index_w>& b)
	{
		return (a.xyzw ^ b);
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z>
	inline float operator ^(const Trivector4D& a, const Subvec3D<type_struct, false, count, index_x, index_y, index_z>& b)
	{
		return (a.xyz ^ b);
	}

	inline Trivector4D Reverse(const Trivector4D& v)
	{
		return (-v);
	}

	inline const Trivector4D& Antireverse(const Trivector4D& v)
	{
		return (~v);
	}

	inline float BulkNorm(const Trivector4D& v)
	{
		return (Fabs(v.w));
	}

	inline float WeightNorm(const Trivector4D& v)
	{
		return (Sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	}

	inline Trivector4D Unitize(const Trivector4D& v)
	{
		return (v * InverseSqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	}

	inline float Antiwedge(const Vector4D& v, const Trivector4D& f)
	{
		return (v ^ f);
	}

	inline float Antiwedge(const Vector3D& v, const Trivector4D& f)
	{
		return (v ^ f);
	}

	inline float Antiwedge(const Point3D& p, const Trivector4D& f)
	{
		return (p ^ f);
	}

	inline float Antiwedge(const Point2D& p, const Trivector4D& f)
	{
		return (p ^ f);
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
	inline float Antiwedge(const Trivector4D& a, const Subvec4D<type_struct, false, count, index_x, index_y, index_z, index_w>& b)
	{
		return (a ^ b);
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z>
	inline float Antiwedge(const Trivector4D& a, const Subvec3D<type_struct, false, count, index_x, index_y, index_z>& b)
	{
		return (a ^ b);
	}

	inline Point3D Project(const Point3D& p, const Trivector4D& f)
	{
		return (Point3D(p - !f.xyz * (p ^ f)));
	}

	inline Trivector4D Antiproject(const Trivector4D& f, const Point3D& p)
	{
		return (Trivector4D(f.xyz, p));
	}


	struct ConstTrivector4D
	{
		float	x;
		float	y;
		float	z;
		float	w;

		operator const Trivector4D&(void) const
		{
			return (reinterpret_cast<const Trivector4D&>(*this));
		}

		const Trivector4D *operator &(void) const
		{
			return (reinterpret_cast<const Trivector4D *>(this));
		}
	};
}


#endif
