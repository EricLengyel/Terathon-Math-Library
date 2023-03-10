//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2023, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSCircle3D_h
#define TSCircle3D_h


//# \component	Math Library
//# \prefix		Math/


#include "TSDipole3D.h"


#define TERATHON_CIRCLE3D 1


namespace Terathon
{
	struct ConstCircle3D;


	//# \class	Circle3D	Encapsulates a 3D <a href="https://conformalgeometricalgebra.org/wiki/index.php?title=Circle">circle</a> in conformal geometric algebra.
	//
	//# The $Circle3D$ class encapsulates a 3D <a href="https://conformalgeometricalgebra.org/wiki/index.php?title=Circle">circle</a> in conformal geometric algebra.
	//
	//# \def	class Circle3D
	//
	//# \ctor	Circle3D();
	//# \ctor	Circle3D(float gx, float gy, float gz, float gw, float vx, float vy, float vz, float mx, float my, float mz);
	//# \ctor	Circle3D(const Plane3D& plane, const Vector3D& direction, const Bivector3D& moment);
	//
	//# \param	gx,gy,gz,gw		The coordinates of the carrier plane.
	//# \param	vx,vy,vz		The coordinates of the direction of the flat line component.
	//# \param	mx,my,mz		The coordinates of the moment of the flat line component.
	//# \param	plane			The carrier plane.
	//# \param	direction		The direction of the flat line component.
	//# \param	moment			The moment of the flat line component.
	//
	//# \desc
	//# The $Circle3D$ class is used to store a three-dimensional circle with a
	//# five-dimensional trivector representation in conformal geometric algebra.
	//#
	//# The default constructor leaves the components of the circle undefined.
	//# If the initialization values are supplied, then they are assigned to the ten
	//# coordinates of the circle.
	//
	//# \action		bool operator ==(const Circle3D& c, const Circle3D& o) const;
	//#				Returns a boolean value indicating whether the two circles $c$ and $o$ are equal.
	//
	//# \action		bool operator !=(const Circle3D& c, const Circle3D& o) const;
	//#				Returns a boolean value indicating whether the two circles $c$ and $o$ are not equal.
	//
	//# \action		Circle3D operator -(const Circle3D& c);
	//#				Returns the negation of the circle $c$.
	//
	//# \action		Circle3D operator *(const Circle3D& c, float n);
	//#				Returns the product of the circle $c$ and the scalar $n$.
	//
	//# \action		Circle3D operator *(float n, Circle3D& c);
	//#				Returns the product of the circle $c$ and the scalar $n$.
	//
	//# \action		Circle3D operator /(const Circle3D& c, float n);
	//#				Returns the product of the circle $c$ and the inverse of the scalar $n$.
	//
	//# \action		Circle3D Reverse(const Circle3D& c);
	//#				Returns the reverse of the circle $c$.
	//
	//# \action		Dipole3D Dual(const Circle3D& c);
	//#				Returns the reverse of the circle $c$.
	//
	//# \action		Plane3D Carrier(const Circle3D& c);
	//#				Returns the carrier of the circle $c$.
	//
	//# \action		Line3D Anticarrier(const Circle3D& c);
	//#				Returns the anticarrier of the circle $c$.
	//
	//# \action		Dipole3D Attitude(const Circle3D& c);
	//#				Returns the attitude of the circle $c$.
	//
	//# \action		Round3D Center(const Circle3D& c);
	//#				Returns the center of the circle $c$.
	//
	//# \action		Point3D FlatCenter(const Circle3D& c);
	//#				Returns the flat center of the circle $c$.
	//
	//# \action		Sphere3D Container(const Circle3D& c);
	//#				Returns the container of the circle $c$.
	//
	//# \action		Circle3D Partner(const Circle3D& c);
	//#				Returns the partner of the circle $c$.
	//
	//# \action		float SquaredRadiusNorm(const Circle3D& c);
	//#				Returns the squared radius of the circle $c$.
	//
	//# \action		float SquaredCenterNorm(const Circle3D& c);
	//#				Returns the squared distance from the origin to the center of the circle $c$.
	//
	//# \action		float SquaredWeightNorm(const Circle3D& c);
	//#				Returns the squared weight of the circle $c$.
	//
	//# \also	$@Round3D@$
	//# \also	$@Dipole3D@$
	//# \also	$@Sphere3D@$


	//# \function	Circle3D::Set		Sets all ten components of a circle.
	//
	//# \proto	Circle3D& Set(float gx, float gy, float gz, float gw, float vx, float vy, float vz, float mx, float my, float mz);
	//# \proto	Circle3D& Set(const Plane3D& plane, const Vector3D& direction, const Bivector3D& moment);
	//
	//# \param	gx,gy,gz,gw		The coordinates of the carrier plane.
	//# \param	vx,vy,vz		The coordinates of the direction of the flat line component.
	//# \param	mx,my,mz		The coordinates of the moment of the flat line component.
	//# \param	plane			The carrier plane.
	//# \param	direction		The direction of the flat line component.
	//# \param	moment			The moment of the flat line component.
	//
	//# \desc
	//# The $Set$ function sets the ten coordinates of a circle to the values specified.
	//#
	//# The return value is a reference to the circle object.


	class Circle3D
	{
		public:

			Plane3D			g;
			Vector3D		v;
			Bivector3D		m;

			TERATHON_API static const ConstCircle3D zero;

			inline Circle3D() = default;

			Circle3D(float gx, float gy, float gz, float gw, float vx, float vy, float vz, float mx, float my, float mz)
			{
				g.Set(gx, gy, gz, gw);
				v.Set(vx, vy, vz);
				m.Set(mx, my, mz);
			}

			Circle3D(const Plane3D& plane, const Vector3D& direction, const Bivector3D& moment)
			{
				g = plane;
				v = direction;
				m = moment;
			}

			Circle3D& Set(float gx, float gy, float gz, float gw, float vx, float vy, float vz, float mx, float my, float mz)
			{
				g.Set(gx, gy, gz, gw);
				v.Set(vx, vy, vz);
				m.Set(mx, my, mz);
				return (*this);
			}

			void Set(float gx, float gy, float gz, float gw, float vx, float vy, float vz, float mx, float my, float mz) volatile
			{
				g.Set(gx, gy, gz, gw);
				v.Set(vx, vy, vz);
				m.Set(mx, my, mz);
			}

			Circle3D& Set(const Plane3D& plane, const Vector3D& direction, const Bivector3D& moment)
			{
				g = plane;
				v = direction;
				m = moment;
				return (*this);
			}

			void Set(const Plane3D& plane, const Vector3D& direction, const Bivector3D& moment) volatile
			{
				g = plane;
				v = direction;
				m = moment;
			}
	};


	inline Circle3D Reverse(const Circle3D& c)
	{
		return (Circle3D(-c.g.x, -c.g.y, -c.g.z, -c.g.w, -c.v.x, -c.v.y, -c.v.z, -c.m.x, -c.m.y, -c.m.z));
	}

	inline Dipole3D Dual(const Circle3D& c)
	{
		return (Dipole3D(c.g.x, c.g.y, c.g.z, c.v.x, c.v.y, c.v.z, c.m.x, c.m.y, c.m.z, -c.g.w));
	}

	inline Circle3D Dual(const Dipole3D& d)
	{
		return (Circle3D(-d.v.x, -d.v.y, -d.v.z, d.p.w, -d.m.x, -d.m.y, -d.m.z, -d.p.x, -d.p.y, -d.p.z));
	}

	inline Plane3D Carrier(const Circle3D& c)
	{
		return (c.g);
	}

	inline Line3D Anticarrier(const Circle3D& c)
	{
		return (Line3D(c.v.x, c.v.y, c.v.z, c.g.x, c.g.y, c.g.z));
	}

	inline Dipole3D Attitude(const Circle3D& c)
	{
		return (Dipole3D(0.0F, 0.0F, 0.0F, c.g.x, c.g.y, c.g.z, c.v.x, c.v.y, c.v.z, 0.0F));
	}

	Round3D Center(const Circle3D& c);
	Point3D FlatCenter(const Circle3D& c);
	Circle3D Partner(const Circle3D& c);

	inline float SquaredRadiusNorm(const Circle3D& c)
	{
		return (c.v.x * c.v.x + c.v.y * c.v.y + c.v.z * c.v.z + (c.g.x * c.m.x + c.g.y * c.m.y + c.g.z * c.m.z) * 2.0F - c.g.w * c.g.w);
	}

	inline float SquaredCenterNorm(const Circle3D& c)
	{
		return (c.g.w * c.g.w + c.v.x * c.v.x + c.v.y * c.v.y + c.v.z * c.v.z);
	}

	inline float SquaredWeightNorm(const Circle3D& c)
	{
		return (c.g.x * c.g.x + c.g.y * c.g.y + c.g.z * c.g.z);
	}

	inline Circle3D operator ~(const Circle3D& c)
	{
		return (Reverse(c));
	}

	inline Circle3D operator -(const Circle3D& c)
	{
		return (Circle3D(-c.g.x, -c.g.y, -c.g.z, -c.g.w, -c.v.x, -c.v.y, -c.v.z, -c.m.x, -c.m.y, -c.m.z));
	}

	inline Circle3D operator *(const Circle3D& c, float n)
	{
		return (Circle3D(c.g.x * n, c.g.y * n, c.g.z * n, c.g.w * n, c.v.x * n, c.v.y * n, c.v.z * n, c.m.x * n, c.m.y * n, c.m.z * n));
	}

	inline Circle3D operator *(float n, const Circle3D& c)
	{
		return (Circle3D(n * c.g.x, n * c.g.y, n * c.g.z, n * c.g.w, n * c.v.x, n * c.v.y, n * c.v.z, n * c.m.x, n * c.m.y, n * c.m.z));
	}

	inline Circle3D operator /(const Circle3D& c, float n)
	{
		n = 1.0F / n;
		return (Circle3D(c.g.x * n, c.g.y * n, c.g.z * n, c.g.w * n, c.v.x * n, c.v.y * n, c.v.z * n, c.m.x * n, c.m.y * n, c.m.z * n));
	}

	inline bool operator ==(const Circle3D& c, const Circle3D& o)
	{
		return ((c.g == o.g) && (c.v == o.v) && (c.m == o.m));
	}

	inline bool operator !=(const Circle3D& c, const Circle3D& o)
	{
		return ((c.g != o.g) || (c.v != o.v) || (c.m != o.m));
	}

	Circle3D Wedge(const Round3D& a, const Dipole3D& d);
	Dipole3D Antiwedge(const Circle3D& c, const Plane3D& g);
	Round3D Antiwedge(const Circle3D& c, const Circle3D& o);
	Round3D Antiwedge(const Circle3D& c, const Line3D& l);

	inline Circle3D Wedge(const Dipole3D& d, const Round3D& a)
	{
		return (Wedge(a, d));
	}

	inline Dipole3D Antiwedge(const Plane3D& g, const Circle3D& c)
	{
		return (Antiwedge(c, g));
	}

	inline Round3D Antiwedge(const Line3D& l, const Circle3D& c)
	{
		return (Antiwedge(c, l));
	}

	inline Circle3D operator ^(const Round3D& a, const Dipole3D& d)
	{
		return (Wedge(a, d));
	}

	inline Dipole3D operator ^(const Circle3D& c, const Plane3D& g)
	{
		return (Antiwedge(c, g));
	}

	inline Round3D operator ^(const Circle3D& c, const Circle3D& o)
	{
		return (Antiwedge(c, o));
	}

	inline Round3D operator ^(const Circle3D& c, const Line3D& l)
	{
		return (Antiwedge(c, l));
	}

	inline Circle3D operator ^(const Dipole3D& d, const Round3D& a)
	{
		return (Wedge(a, d));
	}

	inline Dipole3D operator ^(const Plane3D& g, const Circle3D& c)
	{
		return (Antiwedge(c, g));
	}

	inline Round3D operator ^(const Line3D& l, const Circle3D& c)
	{
		return (Antiwedge(c, l));
	}


	struct ConstCircle3D
	{
		float	gx, gy, gz, gw;
		float	vx, vy, vz;
		float	mx, my, mz;

		operator const Circle3D&(void) const
		{
			return (reinterpret_cast<const Circle3D&>(*this));
		}

		const Circle3D *operator &(void) const
		{
			return (reinterpret_cast<const Circle3D *>(this));
		}

		const Circle3D *operator ->(void) const
		{
			return (reinterpret_cast<const Circle3D *>(this));
		}
	};
}


#endif
