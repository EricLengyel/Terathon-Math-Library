//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2023, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSPlane3D_h
#define TSPlane3D_h


//# \component	Math Library
//# \prefix		Math/


#include "TSLine3D.h"


#define TERATHON_PLANE3D 1


namespace Terathon
{
	class Plane3D;
	struct ConstPlane3D;


	//# \class	Plane3D		Encapsulates a 3D plane.
	//
	//# The $Plane3D$ class encapsulates a 3D plane.
	//
	//# \def	class Plane3D : public Antivec4D<TypePlane3D>
	//
	//# \ctor	Plane3D();
	//# \ctor	Plane3D(float a, float b, float c, float d);
	//# \ctor	Plane3D(const Bivector3D& n, float d);
	//# \ctor	Plane3D(const Bivector3D& n, const Point3D& p);
	//# \ctor	Plane3D(const Point3D& p1, const Point3D& p2, const Point3D& p3);
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
	//# The $Plane3D$ class is used to store a three-dimensional plane represented as a four-dimensional trivector
	//# having floating-point components <i>x</i>, <i>y</i>, <i>z</i>, and <i>w</i>.
	//#
	//# The default constructor leaves the components of the plane undefined.
	//# If the values $a$, $b$, $c$, and $d$ are supplied, then they are assigned to the
	//# <i>x</i>, <i>y</i>, <i>z</i>, and <i>w</i> coordinates of the plane, respectively.
	//#
	//# If the $p$ parameter is specified, then the <i>w</i> coordinate is given by &minus;($n$&#x202F;&and;&#x202F;$p$).
	//# If the $p1$, $p2$, and $p3$ parameters are specified, then the plane is set to the
	//# triple wedge product $p1$&#x202F;&and;&#x202F;$p2$&#x202F;&and;&#x202F;$p3$.
	//
	//# \operator	float& operator [](machine k);
	//#				Returns a reference to the $k$-th scalar component of a plane.
	//#				The value of $k$ must be 0, 1, 2, or 3.
	//
	//# \operator	const float& operator [](machine k) const;
	//#				Returns a constant reference to the $k$-th scalar component of a plane.
	//#				The value of $k$ must be 0, 1, 2, or 3.
	//
	//# \operator	Plane3D& operator *=(float n);
	//#				Multiplies by the scalar $n$.
	//
	//# \operator	Plane3D& operator /=(float n);
	//#				Multiplies by the inverse of the scalar $n$.
	//
	//# \action		bool operator ==(const Plane3D& g, const Plane3D& h);
	//#				Returns a boolean value indicating whether the two planes $g$ and $h$ are equal.
	//
	//# \action		bool operator !=(const Plane3D& g, const Plane3D& h);
	//#				Returns a boolean value indicating whether the two planes $g$ and $h$ are not equal.
	//
	//# \action		const Plane3D& operator ~(const Plane3D& g);
	//#				Returns the antireverse of the plane $g$ (which is just the plane $g$ itself).
	//
	//# \action		Plane3D operator -(const Plane3D& g);
	//#				Returns the negation of the plane $g$.
	//
	//# \action		Plane3D operator *(const Plane3D& g, float n);
	//#				Returns the product of the plane $g$ and the scalar $n$.
	//
	//# \action		Plane3D operator *(float n, const Plane3D& g);
	//#				Returns the product of the plane $g$ and the scalar $n$.
	//
	//# \action		Plane3D operator /(const Plane3D& g, float n);
	//#				Returns the product of the plane $g$ and the inverse of the scalar $n$.
	//
	//# \action		float operator ^(const Vector4D& v, const Plane3D& g);
	//#				Returns the antiwedge product of the vector $v$ and the plane $g$.
	//
	//# \action		float operator ^(const Vector3D& v, const Plane3D& g);
	//#				Returns the antiwedge product of the 3D vector $v$ and the plane $g$. The <i>w</i> coordinate of $v$ is assumed to be 0.
	//
	//# \action		float operator ^(const Point3D& p, const Plane3D& g);
	//#				Returns the antiwedge product of the 3D point $p$ and the plane $g$. The <i>w</i> coordinate of $p$ is assumed to be 1.
	//#				This gives the distance from a unitized plane represented by a $Plane3D$ object to the point $p$.
	//
	//# \action		float operator ^(const Point2D& p, const Plane3D& g);
	//#				Returns the antiwedge product of the 2D point $p$ and the plane $g$. The <i>z</i> coordinate of $p$ is assumed to be 0, and the <i>w</i> coordinate of $p$ is assumed to be 1.
	//#				This gives the distance from a unitized plane represented by a $Plane3D$ object to the point $p$.
	//
	//# \action		Line3D operator ^(const Plane3D& g, const Plane3D& h);
	//#				Returns the antiwedge product of the planes $g$ and $h$.
	//#				The result represents the line where the two planes $g$ and $h$ intersect. The direction of the line is equal to the cross product between the normal component of $g$ and the normal component of $h$.
	//
	//# \action		Plane3D operator ^(const Line3D& l, const Point3D& p);
	//#				Returns the wedge product of the bivector $l$ and the point $p$. The <i>w</i> coordinate of $p$ is assumed to be 1.
	//#				The result represents the plane containing the line $l$ and the point $p$, wound from the direction component of $l$ toward the direction to $p$ perpendicular to the line $l$.
	//
	//# \action		Plane3D operator ^(const Point3D& p, const Line3D& l);
	//#				Returns the wedge product of the point $p$ and the bivector $l$, which is the same as $l$&#x202F;&#x2227;&#x202F;$p$. The <i>w</i> coordinate of $p$ is assumed to be 1.
	//
	//# \action		Plane3D operator ^(const Line3D& l, const Vector3D& v);
	//#				Returns the wedge product of the bivector $l$ and the direction $v$. The <i>w</i> coordinate of $v$ is assumed to be 0.
	//#				The result represents the plane containing the line $l$ and the direction $v$, wound from the direction component of $l$ toward the direction $v$.
	//
	//# \action		Plane3D operator ^(const Vector3D& v, const Line3D& l);
	//#				Returns the wedge product of the direction $v$ and the bivector $l$, which is the same as $l$&#x202F;&#x2227;&#x202F;$v$. The <i>w</i> coordinate of $v$ is assumed to be 0.
	//
	//# \action		Vector4D operator ^(const Line3D& l, const Plane3D& g);
	//#				Returns the antiwedge product of the bivector $L$ and the plane $g$.
	//#				The result represents the homogeneous point where the line and plane intersect. The <i>x</i>, <i>y</i>, and <i>z</i> must be divided by the <i>w</i> coordinate to produce a 3D point.
	//
	//# \action		Vector4D operator ^(const Plane3D& g, const Line3D& l);
	//#				Returns the antiwedge product of the plane $g$ and the bivector $l$, which is the same as $l$&#x202F;&#x2228;&#x202F;$g$.
	//
	//# \action		float BulkNorm(const Plane3D& g);
	//#				Returns the bulk norm of the plane $g$.
	//
	//# \action		float WeightNorm(const Plane3D& g);
	//#				Returns the weight norm of the plane $g$.
	//
	//# \action		Point3D Project(const Point3D& p, const Plane3D& g);
	//#				Returns the projection of the point $p$ onto the plane $g$ under the assumption that the plane is unitized.
	//
	//# \action		Line3D Project(const Line3D& l, const Plane3D& g);
	//#				Returns the projection of the line $l$ onto the plane $g$ under the assumption that the plane is unitized.
	//
	//# \action		Plane3D Antiproject(const Plane3D& g, const Point3D& p);
	//#				Returns the antiprojection of the plane $g$ onto the point $p$ (where $p$ is always unitized because it has an implicit <i>w</i> coordinate of 1).
	//
	//# \action		Plane3D Antiproject(const Plane3D& g, const Line3D& l);
	//#				Returns the antiprojection of the plane $g$ onto the line $l$ under the assumption that the line is unitized.
	//
	//# \privbase	Antivec4D	Antivectors use a generic base class to store their components.
	//
	//# \also	$@Vector4D@$
	//# \also	$@Point3D@$
	//# \also	$@Point2D@$


	//# \function	Plane3D::Set		Sets all four components of a plane.
	//
	//# \proto	Plane3D& Set(float a, float b, float c, float d);
	//# \proto	Plane3D& Set(const Bivector3D& n, float d);
	//# \proto	Plane3D& Set(const Bivector3D& n, const Point3D& p);
	//# \proto	Plane3D& Set(const Point3D& p1, const Point3D& p2, const Point3D& p3);
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
	//# The $Set$ function sets the <i>x</i>, <i>y</i>, <i>z</i>, and <i>w</i> coordinates of a plane to
	//# the values given by the $a$, $b$, $c$, and $d$ parameters, respectively.
	//#
	//# If the $p$ parameter is specified, then the <i>w</i> coordinate is given by &minus;($n$&#x202F;&and;&#x202F;$p$).
	//# If the $p1$, $p2$, and $p3$ parameters are specified, then the plane is set to the
	//# triple wedge product $p1$&#x202F;&and;&#x202F;$p2$&#x202F;&and;&#x202F;$p3$.
	//#
	//# The return value is a reference to the plane object.


	//# \function	Plane3D::Unitize		Unitizes the weight of a plane.
	//
	//# \proto	Plane3D& Unitize(void);
	//
	//# \desc
	//# The $Unitize$ function multiplies a plane by the inverse magnitude of its weight, which is the
	//# 3D bivector given by its <i>x</i>, <i>y</i>, and <i>z</i> coordinates. After calling this function, the plane
	//# has a unit-length normal. If the <i>x</i>, <i>y</i>, and <i>z</i> coordinates are all zero, then the result is undefined.
	//#
	//# The return value is a reference to the plane object.


	struct TypePlane3D
	{
		typedef float component_type;
		typedef Vector2D vector2D_type;
		typedef Bivector3D vector3D_type;
		typedef Plane3D vector4D_type;
	};


	class Plane3D : public Antivec4D<TypePlane3D>
	{
		public:

			TERATHON_API static const ConstPlane3D zero;
			TERATHON_API static const ConstPlane3D horizon;

			inline Plane3D() = default;

			Plane3D(float a, float b, float c, float d) : Antivec4D<TypePlane3D>(a, b, c, d) {}

			Plane3D(const Bivector3D& n, float d)
			{
				xyz = n.xyz;
				w = d;
			}

			Plane3D(const Bivector3D& n, const Point3D& p)
			{
				xyz = n.xyz;
				w = -(n ^ p);
			}

			Plane3D(const Point3D& p1, const Point3D& p2, const Point3D& p3)
			{
				xyz = (p2 - p1) ^ (p3 - p1);
				w = -(xyz ^ p1);
			}

			Plane3D& Set(float a, float b, float c, float d)
			{
				xyzw.Set(a, b, c, d);
				return (*this);
			}

			void Set(float a, float b, float c, float d) volatile
			{
				xyzw.Set(a, b, c, d);
			}

			Plane3D& Set(const Bivector3D& n, float d)
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

			Plane3D& Set(const Bivector3D& n, const Point3D& p)
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

			Plane3D& Set(const Point3D& p1, const Point3D& p2, const Point3D& p3)
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

			Plane3D& operator =(const Plane3D& v)
			{
				xyzw = v.xyzw;
				return (*this);
			}

			void operator =(const Plane3D& v) volatile
			{
				xyzw = v.xyzw;
			}

			template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
			Plane3D& operator =(const Subvec4D<type_struct, true, count, index_x, index_y, index_z, index_w>& v)
			{
				xyzw = v;
				return (*this);
			}

			template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
			void operator =(const Subvec4D<type_struct, true, count, index_x, index_y, index_z, index_w>& v) volatile
			{
				xyzw = v;
			}

			Plane3D& operator *=(float n)
			{
				xyzw *= n;
				return (*this);
			}

			Plane3D& operator /=(float n)
			{
				xyzw /= n;
				return (*this);
			}

			Plane3D& Unitize(void)
			{
				return (*this *= InverseSqrt(x * x + y * y + z * z));
			}
	};


	inline Plane3D Reverse(const Plane3D& g)
	{
		return (Plane3D(-g.x, -g.y, -g.z, -g.w));
	}

	inline const Plane3D& Antireverse(const Plane3D& g)
	{
		return (g);
	}

	inline const Plane3D& Complement(const Vector4D& p)
	{
		return (reinterpret_cast<const Plane3D&>(p));
	}

	inline const Vector4D& Complement(const Plane3D& g)
	{
		return (reinterpret_cast<const Vector4D&>(g));
	}

	inline const Plane3D& operator ~(const Plane3D& g)
	{
		return (Antireverse(g));
	}

	inline const Plane3D& operator !(const Vector4D& p)
	{
		return (Complement(p));
	}

	inline const Vector4D& operator !(const Plane3D& g)
	{
		return (Complement(g));
	}

	inline Plane3D operator -(const Plane3D& g)
	{
		return (Plane3D(-g.x, -g.y, -g.z, -g.w));
	}

	inline Plane3D operator *(const Plane3D& g, float n)
	{
		return (Plane3D(g.x * n, g.y * n, g.z * n, g.w * n));
	}

	inline Plane3D operator *(float n, const Plane3D& g)
	{
		return (Plane3D(n * g.x, n * g.y, n * g.z, n * g.w));
	}

	inline Plane3D operator /(const Plane3D& g, float n)
	{
		n = 1.0F / n;
		return (Plane3D(g.x * n, g.y * n, g.z * n, g.w * n));
	}

	inline float operator ^(const Vector4D& v, const Plane3D& g)
	{
		return (v.xyzw ^ g.xyzw);
	}

	inline float operator ^(const Vector3D& v, const Plane3D& g)
	{
		return (v.xyz ^ g.xyz);
	}

	inline float operator ^(const Point3D& p, const Plane3D& g)
	{
		return ((p.xyz ^ g.xyz) + g.w);
	}

	inline float operator ^(const Point2D& p, const Plane3D& g)
	{
		return (p.x * g.x + p.y * g.y + g.w);
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
	inline float operator ^(const Plane3D& g, const Subvec4D<type_struct, false, count, index_x, index_y, index_z, index_w>& h)
	{
		return (g.xyzw ^ h);
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z>
	inline float operator ^(const Plane3D& g, const Subvec3D<type_struct, false, count, index_x, index_y, index_z>& h)
	{
		return (g.xyz ^ h);
	}

	inline Line3D operator ^(const Plane3D& g, const Plane3D& h)
	{
		return (Line3D(g.z * h.y - g.y * h.z, g.x * h.z - g.z * h.x, g.y * h.x - g.x * h.y, g.x * h.w - g.w * h.x, g.y * h.w - g.w * h.y, g.z * h.w - g.w * h.z));
	}

	inline Plane3D operator ^(const Line3D& l, const Point3D& p)
	{
		return (Plane3D(l.v.y * p.z - l.v.z * p.y + l.m.x,
		                l.v.z * p.x - l.v.x * p.z + l.m.y,
		                l.v.x * p.y - l.v.y * p.x + l.m.z,
		               -l.m.x * p.x - l.m.y * p.y - l.m.z * p.z));
	}

	inline Plane3D operator ^(const Point3D& p, const Line3D& l)
	{
		return (l ^ p);
	}

	inline Plane3D operator ^(const Line3D& l, const Vector3D& v)
	{
		return (Plane3D(l.v.y * v.z - l.v.z * v.y,
		                l.v.z * v.x - l.v.x * v.z,
		                l.v.x * v.y - l.v.y * v.x,
		               -l.m.x * v.x - l.m.y * v.y - l.m.z * v.z));
	}

	inline Plane3D operator ^(const Vector3D& v, const Line3D& l)
	{
		return (l ^ v);
	}

	inline Vector4D operator ^(const Line3D& l, const Plane3D& g)
	{
		return (Vector4D(l.m.y * g.z - l.m.z * g.y + l.v.x * g.w,
		                 l.m.z * g.x - l.m.x * g.z + l.v.y * g.w,
		                 l.m.x * g.y - l.m.y * g.x + l.v.z * g.w,
		                -l.v.x * g.x - l.v.y * g.y - l.v.z * g.z));
	}

	inline Vector4D operator ^(const Plane3D& g, const Line3D& l)
	{
		return (l ^ g);
	}

	inline float BulkNorm(const Plane3D& g)
	{
		return (Fabs(g.w));
	}

	inline float WeightNorm(const Plane3D& g)
	{
		return (Sqrt(g.x * g.x + g.y * g.y + g.z * g.z));
	}

	inline Plane3D Unitize(const Plane3D& g)
	{
		return (g * InverseSqrt(g.x * g.x + g.y * g.y + g.z * g.z));
	}

	inline float Antiwedge(const Vector4D& v, const Plane3D& g)
	{
		return (v ^ g);
	}

	inline float Antiwedge(const Vector3D& v, const Plane3D& g)
	{
		return (v ^ g);
	}

	inline float Antiwedge(const Point3D& p, const Plane3D& g)
	{
		return (p ^ g);
	}

	inline float Antiwedge(const Point2D& p, const Plane3D& g)
	{
		return (p ^ g);
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
	inline float Antiwedge(const Plane3D& g, const Subvec4D<type_struct, false, count, index_x, index_y, index_z, index_w>& h)
	{
		return (g ^ h);
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z>
	inline float Antiwedge(const Plane3D& g, const Subvec3D<type_struct, false, count, index_x, index_y, index_z>& h)
	{
		return (g ^ h);
	}

	inline Line3D Antiwedge(const Plane3D& g, const Plane3D& h)
	{
		return (g ^ h);
	}

	inline Plane3D Wedge(const Line3D& l, const Point3D& p)
	{
		return (l ^ p);
	}

	inline Plane3D Wedge(const Point3D& p, const Line3D& l)
	{
		return (l ^ p);
	}

	inline Plane3D Wedge(const Line3D& l, const Vector3D& v)
	{
		return (l ^ v);
	}

	inline Plane3D Wedge(const Vector3D& v, const Line3D& l)
	{
		return (l ^ v);
	}

	inline Vector4D Antiwedge(const Line3D& l, const Plane3D& g)
	{
		return (l ^ g);
	}

	inline Vector4D Antiwedge(const Plane3D& g, const Line3D& l)
	{
		return (l ^ g);
	}

	inline Point3D Project(const Point3D& p, const Plane3D& g)
	{
		return (Point3D(p - !g.xyz * (p ^ g)));
	}

	inline Line3D Project(const Line3D& l, const Plane3D& g)
	{
		return (Line3D(l.v - !g.xyz * (g.xyz ^ l.v), g.xyz * (!g.xyz ^ l.m) - (!g.xyz ^ l.v) * g.w));
	}

	inline Plane3D Antiproject(const Plane3D& g, const Point3D& p)
	{
		return (Plane3D(g.xyz, p));
	}

	inline Plane3D Antiproject(const Plane3D& g, const Line3D& l)
	{
		return (Plane3D(g.xyz - !l.v * (g.xyz ^ l.v), l.m ^ !l.v ^ g.xyz));
	}

	inline Plane3D Translate(const Plane3D& g, const Vector3D& t)
	{
		return (Plane3D(g.xyz, g.w - (g.xyz ^ t) * 2.0F));
	}


	struct ConstPlane3D
	{
		float	x, y, z, w;

		operator const Plane3D&(void) const
		{
			return (reinterpret_cast<const Plane3D&>(*this));
		}

		const Plane3D *operator &(void) const
		{
			return (reinterpret_cast<const Plane3D *>(this));
		}

		const Plane3D *operator ->(void) const
		{
			return (reinterpret_cast<const Plane3D *>(this));
		}
	};


	typedef Plane3D Trivector4D;
	typedef Plane3D Antivector4D;
}


#endif
