//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2023, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSRound3D_h
#define TSRound3D_h


//# \component	Math Library
//# \prefix		Math/


#include "TSPlane3D.h"


#define TERATHON_ROUND3D 1


namespace Terathon
{
	struct ConstRound3D;


	//# \class	Round3D		Encapsulates a 3D <a href="https://conformalgeometricalgebra.org/wiki/index.php?title=Round_point">round point</a> in conformal geometric algebra.
	//
	//# The $Round3D$ class encapsulates a 3D <a href="https://conformalgeometricalgebra.org/wiki/index.php?title=Round_point">round point</a> in conformal geometric algebra.
	//
	//# \def	class Round3D
	//
	//# \ctor	Round3D();
	//# \ctor	Round3D(float ax, float ay, float az, float aw, float au);
	//# \ctor	Round3D(const Point3D& p);
	//
	//# \param	ax,ay,az,aw,au		The coordinates of the round point.
	//# \param	p					An ordinary 3D point.
	//
	//# \desc
	//# The $Round3D$ class is used to store a three-dimensional round point with a
	//# five-dimensional vector representation in conformal geometric algebra.
	//#
	//# The default constructor leaves the components of the round point undefined.
	//# If the initialization values are supplied, then they are assigned to the five
	//# coordinates of the round point.
	//#
	//# If the $p$ parameter is supplied, then its three coordinates are assigned to
	//# the <i>x</i>, <i>y</i>, and <i>z</i> coordinates of the round point. In this
	//# case, the <i>w</i> coordinate is set to 1.0, and the $u$ coordinates is set
	//# to (<i>x</i><sup>2</sup> + <i>y</i><sup>2</sup> + <i>z</i><sup>2</sup>) / 2.
	//
	//# \operator	float& operator [](machine k);
	//#				Returns a reference to the $k$-th scalar component of a round point.
	//#				The value of $k$ must be 0, 1, 2, 3, or 4.
	//
	//# \operator	const float& operator [](machine k) const;
	//#				Returns a constant reference to the $k$-th scalar component of a round point.
	//#				The value of $k$ must be 0, 1, 2, 3, or 4.
	//
	//# \action		bool operator ==(const Round3D& a, const Round3D& b) const;
	//#				Returns a boolean value indicating whether the two round points $a$ and $b$ are equal.
	//
	//# \action		bool operator !=(const Round3D& a, const Round3D& b) const;
	//#				Returns a boolean value indicating whether the two round points $a$ and $b$ are not equal.
	//
	//# \action		Round3D operator -(const Round3D& a);
	//#				Returns the negation of the round point $a$.
	//
	//# \action		Round3D operator *(const Round3D& a, float n);
	//#				Returns the product of the round point $a$ and the scalar $n$.
	//
	//# \action		Round3D operator *(float n, const Round3D& a);
	//#				Returns the product of the round point $a$ and the scalar $n$.
	//
	//# \action		Round3D operator /(const Round3D& a, float n);
	//#				Returns the product of the round point $a$ and the inverse of the scalar $n$.
	//
	//# \action		const Round3D& Reverse(const Round3D& a);
	//#				Returns the reverse of the round point $a$.
	//
	//# \action		Vector4D Carrier(const Round3D& a);
	//#				Returns the carrier of the round point $a$.
	//
	//# \action		Round3D Center(const Round3D& a);
	//#				Returns the center of the round point $a$.
	//
	//# \action		Point3D FlatCenter(const Round3D& a);
	//#				Returns the flat center of the round point $a$.
	//
	//# \action		Sphere3D Container(const Round3D& a);
	//#				Returns the container of the round point $a$.
	//
	//# \action		Round3D Partner(const Round3D& a);
	//#				Returns the partner of the round point $a$.
	//
	//# \action		float SquaredRadiusNorm(const Round3D& a);
	//#				Returns the squared radius of the round point $a$.
	//
	//# \action		float SquaredCenterNorm(const Round3D& a);
	//#				Returns the squared distance from the origin to the center of the round point $a$.
	//
	//# \action		float SquaredWeightNorm(const Round3D& a);
	//#				Returns the squared weight of the round point $a$.
	//
	//# \also	$@Dipole3D@$
	//# \also	$@Circle3D@$
	//# \also	$@Sphere3D@$


	//# \function	Round3D::Set	Sets all five components of a round point.
	//
	//# \proto	Round3D& Set(float ax, float ay, float az, float aw, float au);
	//
	//# \param	ax,ay,az,aw,au		The new coordinates of the round point.
	//
	//# \desc
	//# The $Set$ function sets the five coordinates of a round point to the values specified.
	//#
	//# The return value is a reference to the round point object.


	class Round3D
	{
		public:

			float	x, y, z, w, u;

			TERATHON_API static const ConstRound3D zero;

			inline Round3D() = default;

			Round3D(float ax, float ay, float az, float aw, float au)
			{
				x = ax;
				y = ay;
				z = az;
				w = aw;
				u = au;
			}

			Round3D(const Point3D& p)
			{
				x = p.x;
				y = p.y;
				z = p.z;
				w = 1.0F;
				u = (p.x * p.x + p.y * p.y + p.z * p.z) * 0.5F;
			}

			Round3D& Set(float ax, float ay, float az, float aw, float au)
			{
				x = ax;
				y = ay;
				z = az;
				w = aw;
				u = au;
				return (*this);
			}

			void Set(float ax, float ay, float az, float aw, float au) volatile
			{
				x = ax;
				y = ay;
				z = az;
				w = aw;
				u = au;
			}

			float& operator [](machine k)
			{
				return ((&x)[k]);
			}

			const float& operator [](machine k) const
			{
				return ((&x)[k]);
			}
	};


	inline const Round3D& Reverse(const Round3D& a)
	{
		return (a);
	}

	inline Vector4D Carrier(const Round3D& a)
	{
		return (Vector4D(a.x, a.y, a.z, a.w));
	}

	inline Round3D Center(const Round3D& a)
	{
		return (Round3D(a.x * a.w, a.y * a.w, a.z * a.w, a.w * a.w, a.w * a.u));
	}

	inline Point3D FlatCenter(const Round3D& a)
	{
		float f = 1.0F / a.w;
		return (Point3D(a.x * f, a.y * f, a.z * f));
	}

	inline Round3D Partner(const Round3D& a)
	{
		float w2 = a.w * a.w;
		return (Round3D(a.x * w2, a.y * w2, a.z * w2, a.w * w2, (a.x * a.x + a.y * a.y + a.z * a.z - a.w * a.u) * a.w));
	}

	inline float SquaredRadiusNorm(const Round3D& a)
	{
		return (a.w * a.u * 2.0F - a.x * a.x - a.y * a.y - a.z * a.z);
	}

	inline float SquaredCenterNorm(const Round3D& a)
	{
		return (a.x * a.x + a.y * a.y + a.z * a.z);
	}

	inline float SquaredWeightNorm(const Round3D& a)
	{
		return (a.w * a.w);
	}

	inline const Round3D& operator ~(const Round3D& a)
	{
		return (Reverse(a));
	}

	inline Round3D operator -(const Round3D& a)
	{
		return (Round3D(-a.x, -a.y, -a.z, -a.w, -a.u));
	}

	inline Round3D operator *(const Round3D& a, float n)
	{
		return (Round3D(a.x * n, a.y * n, a.z * n, a.w * n, a.u * n));
	}

	inline Round3D operator *(float n, const Round3D& a)
	{
		return (Round3D(n * a.x, n * a.y, n * a.z, n * a.w, n * a.u));
	}

	inline Round3D operator /(const Round3D& a, float n)
	{
		n = 1.0F / n;
		return (Round3D(a.x * n, a.y * n, a.z * n, a.w * n, a.u * n));
	}

	inline bool operator ==(const Round3D& a, const Round3D& b)
	{
		return ((a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w) && (a.u == b.u));
	}

	inline bool operator !=(const Round3D& a, const Round3D& b)
	{
		return ((a.x != b.x) || (a.y != b.y) || (a.z != b.z) || (a.w != b.w) || (a.u != b.u));
	}

	inline Line3D Wedge(const Round3D& a, const Vector4D& p)
	{
		return (Line3D(a.w * p.x - a.x * p.w, a.w * p.y - a.y * p.w, a.w * p.z - a.z * p.w, a.y * p.z - a.z * p.y, a.z * p.x - a.x * p.z, a.x * p.y - a.y * p.x));
	}

	inline Line3D Wedge(const Round3D& a, const Point3D& p)
	{
		return (Line3D(a.w * p.x - a.x, a.w * p.y - a.y, a.w * p.z - a.z, a.y * p.z - a.z * p.y, a.z * p.x - a.x * p.z, a.x * p.y - a.y * p.x));
	}

	inline Line3D Wedge(const Vector4D& p, const Round3D& a)
	{
		return (Wedge(a, p));
	}

	inline Line3D Wedge(const Point3D& p, const Round3D& a)
	{
		return (Wedge(a, p));
	}

	Plane3D Wedge(const Round3D& a, const Line3D& l);
	Plane3D Wedge(const Line3D& l, const Round3D& a);

	inline Line3D operator ^(const Round3D& a, const Vector4D& p)
	{
		return (Wedge(a, p));
	}

	inline Line3D operator ^(const Round3D& a, const Point3D& p)
	{
		return (Wedge(a, p));
	}

	inline Line3D operator ^(const Vector4D& p, const Round3D& a)
	{
		return (Wedge(a, p));
	}

	inline Line3D operator ^(const Point3D& p, const Round3D& a)
	{
		return (Wedge(a, p));
	}

	inline Plane3D operator ^(const Round3D& a, const Line3D& l)
	{
		return (Wedge(a, l));
	}

	inline Plane3D operator ^(const Line3D& l, const Round3D& a)
	{
		return (Wedge(l, a));
	}


	struct ConstRound3D
	{
		float	px, py, pz, pw, pu;

		operator const Round3D&(void) const
		{
			return (reinterpret_cast<const Round3D&>(*this));
		}

		const Round3D *operator &(void) const
		{
			return (reinterpret_cast<const Round3D *>(this));
		}

		const Round3D *operator ->(void) const
		{
			return (reinterpret_cast<const Round3D *>(this));
		}
	};
}


#endif
