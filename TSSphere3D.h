//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2023, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSSphere3D_h
#define TSSphere3D_h


//# \component	Math Library
//# \prefix		Math/


#include "TSCircle3D.h"


#define TERATHON_SPHERE3D 1


namespace Terathon
{
	struct ConstSphere3D;


	//# \class	Sphere3D	Encapsulates a 3D <a href="https://conformalgeometricalgebra.org/wiki/index.php?title=Sphere">sphere</a> in conformal geometric algebra.
	//
	//# The $Sphere3D$ class encapsulates a 3D <a href="https://conformalgeometricalgebra.org/wiki/index.php?title=Sphere">sphere</a> in conformal geometric algebra.
	//
	//# \def	class Sphere3D
	//
	//# \ctor	Sphere3D();
	//# \ctor	Sphere3D(float su, float sx, float sy, float sz, float sw);
	//
	//# \param	su,sx,sy,sz,sw		The coordinates of the sphere.
	//
	//# \desc
	//# The $Sphere3D$ class is used to store a three-dimensional sphere with a
	//# five-dimensional quadrivector representation in conformal geometric algebra.
	//#
	//# The default constructor leaves the components of the sphere undefined.
	//# If the initialization values are supplied, then they are assigned to the five
	//# coordinates of the sphere.
	//
	//# \action		bool operator ==(const Sphere3D& s, const Sphere3D& t) const;
	//#				Returns a boolean value indicating whether the two spheres $s$ and $t$ are equal.
	//
	//# \action		bool operator !=(const Sphere3D& s, const Sphere3D& t) const;
	//#				Returns a boolean value indicating whether the two spheres $s$ and $t$ are not equal.
	//
	//# \action		Sphere3D operator -(const Sphere3D& s);
	//#				Returns the negation of the sphere $s$.
	//
	//# \action		Sphere3D operator *(const Sphere3D& s, float n);
	//#				Returns the product of the sphere $s$ and the scalar $n$.
	//
	//# \action		Sphere3D operator *(float n, Sphere3D& s);
	//#				Returns the product of the sphere $s$ and the scalar $n$.
	//
	//# \action		Sphere3D operator /(const Sphere3D& s, float n);
	//#				Returns the product of the sphere $s$ and the inverse of the scalar $n$.
	//
	//# \action		const Sphere3D& Reverse(const Sphere3D& s);
	//#				Returns the reverse of the sphere $s$.
	//
	//# \action		Round3D Dual(const Sphere3D& sSphere3D& s);
	//#				Returns the reverse of the sphere $s$.
	//
	//# \action		Vector4D Anticarrier(const Sphere3D& s);
	//#				Returns the anticarrier of the sphere $s$.
	//
	//# \action		Circle3D Attitude(const Sphere3D& s);
	//#				Returns the attitude of the sphere $s$.
	//
	//# \action		Round3D Center(const Sphere3D& s);
	//#				Returns the center of the sphere $s$.
	//
	//# \action		Point3D FlatCenter(const Sphere3D& s);
	//#				Returns the flat center of the sphere $s$.
	//
	//# \action		Sphere3D Container(const Sphere3D& s);
	//#				Returns the container of the sphere $s$.
	//
	//# \action		Sphere3D Partner(const Sphere3D& s);
	//#				Returns the partner of the sphere $s$.
	//
	//# \action		float SquaredRadiusNorm(const Sphere3D& s);
	//#				Returns the squared radius of the sphere $s$.
	//
	//# \action		float SquaredCenterNorm(const Sphere3D& s);
	//#				Returns the squared distance from the origin to the center of the sphere $s$.
	//
	//# \action		float SquaredWeightNorm(const Sphere3D& s);
	//#				Returns the squared weight of the sphere $s$.
	//
	//# \also	$@Round3D@$
	//# \also	$@Dipole3D@$
	//# \also	$@Circle3D@$


	//# \function	Sphere3D::Set		Sets all five components of a sphere.
	//
	//# \proto	Sphere3D& Set(float su, float sx, float sy, float sz, float sw);
	//
	//# \param	su,sx,sy,sz,sw		The new coordinates of the sphere.
	//
	//# \desc
	//# The $Set$ function sets the five coordinates of a sphere to the values specified.
	//#
	//# The return value is a reference to the sphere object.


	class Sphere3D
	{
		public:

			float	u, x, y, z, w;

			TERATHON_API static const ConstSphere3D zero;

			inline Sphere3D() = default;

			Sphere3D(float su, float sx, float sy, float sz, float sw)
			{
				u = su;
				x = sx;
				y = sy;
				z = sz;
				w = sw;
			}

			Sphere3D& Set(float su, float sx, float sy, float sz, float sw)
			{
				u = su;
				x = sx;
				y = sy;
				z = sz;
				w = sw;
				return (*this);
			}

			void Set(float su, float sx, float sy, float sz, float sw) volatile
			{
				u = su;
				x = sx;
				y = sy;
				z = sz;
				w = sw;
			}
	};


	inline const Sphere3D& Reverse(const Sphere3D& s)
	{
		return (s);
	}

	inline Round3D Dual(const Sphere3D& s)
	{
		return (Round3D(-s.x, -s.y, -s.z, s.u, s.w));
	}

	inline Sphere3D Dual(const Round3D& a)
	{
		return (Sphere3D(-a.w, a.x, a.y, a.z, -a.u));
	}

	inline Vector4D Anticarrier(const Sphere3D& s)
	{
		return (Vector4D(-s.x, -s.y, -s.z, s.u));
	}

	inline Circle3D Attitude(const Sphere3D& s)
	{
		return (Circle3D(0.0F, 0.0F, 0.0F, s.u, 0.0F, 0.0F, 0.0F, s.x, s.y, s.z));
	}

	inline Sphere3D Container(const Round3D& a)
	{
		return (Sphere3D(-a.w * a.w, a.x * a.w, a.y * a.w, a.z * a.w, a.w * a.u - a.x * a.x - a.y * a.y - a.z * a.z));
	}

	Sphere3D Container(const Dipole3D& d);
	Sphere3D Container(const Circle3D& c);

	inline Sphere3D Container(const Sphere3D& s)
	{
		return (Sphere3D(-s.u * s.u, -s.x * s.u, -s.y * s.u, -s.z * s.u, -s.w * s.u));
	}

	inline Round3D Center(const Sphere3D& s)
	{
		return (Round3D(-s.x * s.u, -s.y * s.u, -s.z * s.u, -s.u * s.u, s.x * s.x + s.y * s.y + s.z * s.z - s.w * s.u));
	}

	inline Point3D FlatCenter(const Sphere3D& s)
	{
		float f = -1.0F / s.u;
		return (Point3D(s.x * f, s.y * f, s.z * f));
	}

	inline Sphere3D Partner(const Sphere3D& s)
	{
		float u2 = s.u * s.u;
		return (Sphere3D(-s.u * u2, -s.x * u2, -s.y * u2, -s.z * u2, (s.w * s.u - s.x * s.x - s.y * s.y - s.z * s.z) * s.u));
	}

	inline float SquaredRadiusNorm(const Sphere3D& s)
	{
		return (s.x * s.x + s.y * s.y + s.z * s.z - s.w * s.u * 2.0F);
	}

	inline float SquaredCenterNorm(const Sphere3D& s)
	{
		return (s.x * s.x + s.y * s.y + s.z * s.z);
	}

	inline float SquaredWeightNorm(const Sphere3D& s)
	{
		return (s.u * s.u);
	}

	inline const Sphere3D& operator ~(const Sphere3D& s)
	{
		return (Reverse(s));
	}

	inline Sphere3D operator -(const Sphere3D& s)
	{
		return (Sphere3D(-s.u, -s.x, -s.y, -s.z, -s.w));
	}

	inline Sphere3D operator *(const Sphere3D& s, float n)
	{
		return (Sphere3D(s.u * n, s.x * n, s.y * n, s.z * n, s.w * n));
	}

	inline Sphere3D operator *(float n, const Sphere3D& s)
	{
		return (Sphere3D(n * s.u, n * s.x, n * s.y, n * s.z, n * s.w));
	}

	inline Sphere3D operator /(const Sphere3D& s, float n)
	{
		n = 1.0F / n;
		return (Sphere3D(s.u * n, s.x * n, s.y * n, s.z * n, s.w * n));
	}

	inline bool operator ==(const Sphere3D& s, const Sphere3D& t)
	{
		return ((s.u == t.u) && (s.x == t.x) && (s.y == t.y) && (s.z == t.z) && (s.w == t.w));
	}

	inline bool operator !=(const Sphere3D& s, const Sphere3D& t)
	{
		return ((s.u != t.u) || (s.x != t.x) || (s.y != t.y) || (s.z != t.z) || (s.w != t.w));
	}

	Sphere3D Wedge(const Round3D& a, const Circle3D& c);
	Sphere3D Wedge(const Circle3D& c, const Round3D& a);
	Sphere3D Wedge(const Dipole3D& d, const Dipole3D& f);
	Circle3D Antiwedge(const Sphere3D& s, const Sphere3D& t);
	Circle3D Antiwedge(const Sphere3D& s, const Plane3D& g);
	Circle3D Antiwedge(const Plane3D& g, const Sphere3D& s);
	Dipole3D Antiwedge(const Sphere3D& s, const Circle3D& c);
	Dipole3D Antiwedge(const Sphere3D& s, const Line3D& l);
	Round3D Antiwedge(const Sphere3D& s, const Dipole3D& d);
	Round3D Antiwedge(const Dipole3D& d, const Sphere3D& s);
	Round3D Antiwedge(const Sphere3D& s, const Vector4D& p);
	Round3D Antiwedge(const Vector4D& p, const Sphere3D& s);
	Round3D Antiwedge(const Sphere3D& s, const Point3D& p);
	Round3D Antiwedge(const Point3D& p, const Sphere3D& s);

	inline Dipole3D Antiwedge(const Circle3D& c, const Sphere3D& s)
	{
		return (Antiwedge(s, c));
	}

	inline Dipole3D Antiwedge(const Line3D& l, const Sphere3D& s)
	{
		return (Antiwedge(s, l));
	}

	inline Sphere3D operator ^(const Round3D& a, const Circle3D& c)
	{
		return (Wedge(a, c));
	}

	inline Sphere3D operator ^(const Circle3D& c, const Round3D& a)
	{
		return (Wedge(c, a));
	}

	inline Sphere3D operator ^(const Dipole3D& d, const Dipole3D& f)
	{
		return (Wedge(d, f));
	}

	inline Circle3D operator ^(const Sphere3D& s, const Sphere3D& t)
	{
		return (Antiwedge(s, t));
	}

	inline Circle3D operator ^(const Sphere3D& s, const Plane3D& g)
	{
		return (Antiwedge(s, g));
	}

	inline Circle3D operator ^(const Plane3D& g, const Sphere3D& s)
	{
		return (Antiwedge(g, s));
	}

	inline Dipole3D operator ^(const Sphere3D& s, const Circle3D& c)
	{
		return (Antiwedge(s, c));
	}

	inline Dipole3D operator ^(const Sphere3D& s, const Line3D& l)
	{
		return (Antiwedge(s, l));
	}

	inline Round3D operator ^(const Sphere3D& s, const Dipole3D& d)
	{
		return (Antiwedge(s, d));
	}

	inline Round3D operator ^(const Dipole3D& d, const Sphere3D& s)
	{
		return (Antiwedge(d, s));
	}

	inline Round3D operator ^(const Sphere3D& s, const Vector4D& p)
	{
		return (Antiwedge(s, p));
	}

	inline Round3D operator ^(const Vector4D& p, const Sphere3D& s)
	{
		return (Antiwedge(p, s));
	}

	inline Round3D operator ^(const Sphere3D& s, const Point3D& p)
	{
		return (Antiwedge(s, p));
	}

	inline Round3D operator ^(const Point3D& p, const Sphere3D& s)
	{
		return (Antiwedge(p, s));
	}

	inline Dipole3D operator ^(const Circle3D& c, const Sphere3D& s)
	{
		return (Antiwedge(c, s));
	}

	inline Dipole3D operator ^(const Line3D& l, const Sphere3D& s)
	{
		return (Antiwedge(l, s));
	}


	struct ConstSphere3D
	{
		float	su, sx, sy, sz, sw;

		operator const Sphere3D&(void) const
		{
			return (reinterpret_cast<const Sphere3D&>(*this));
		}

		const Sphere3D *operator &(void) const
		{
			return (reinterpret_cast<const Sphere3D *>(this));
		}

		const Sphere3D *operator ->(void) const
		{
			return (reinterpret_cast<const Sphere3D *>(this));
		}
	};
}


#endif
