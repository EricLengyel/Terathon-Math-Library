//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2023, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSDipole3D_h
#define TSDipole3D_h


//# \component	Math Library
//# \prefix		Math/


#include "TSRound3D.h"


#define TERATHON_DIPOLE3D 1


namespace Terathon
{
	struct ConstDipole3D;


	//# \class	Dipole3D	Encapsulates a 3D <a href="https://conformalgeometricalgebra.org/wiki/index.php?title=Dipole">dipole</a> in conformal geometric algebra.
	//
	//# The $Dipole3D$ class encapsulates a 3D <a href="https://conformalgeometricalgebra.org/wiki/index.php?title=Dipole">dipole</a> in conformal geometric algebra.
	//
	//# \def	class Dipole3D
	//
	//# \ctor	Dipole3D();
	//# \ctor	Dipole3D(float vx, float vy, float vz, float mx, float my, float mz, float px, float py, float pz, float pw);
	//# \ctor	Dipole3D(const Vector3D& direction, const Bivector3D& moment, const Vector4D& point);
	//
	//# \param	vx,vy,vz		The coordinates of the direction of the carrier line.
	//# \param	mx,my,mz		The coordinates of the moment of the carrier line.
	//# \param	px,py,pz,pw		The coordinates of the flat point component.
	//# \param	direction		The direction of the carrier line.
	//# \param	moment			The moment of the carrier line.
	//# \param	point			The flat point component.
	//
	//# \desc
	//# The $Dipole3D$ class is used to store a three-dimensional dipole with a
	//# five-dimensional bivector representation in conformal geometric algebra.
	//#
	//# The default constructor leaves the components of the dipole undefined.
	//# If the initialization values are supplied, then they are assigned to the ten
	//# coordinates of the dipole.
	//
	//# \action		bool operator ==(const Dipole3D& d, const Dipole3D& f) const;
	//#				Returns a boolean value indicating whether the two dipoles $d$ and $f$ are equal.
	//
	//# \action		bool operator !=(const Dipole3D& d, const Dipole3D& f) const;
	//#				Returns a boolean value indicating whether the two dipoles $d$ and $f$ are not equal.
	//
	//# \action		Dipole3D operator -(const Dipole3D& d);
	//#				Returns the negation of the dipole $d$.
	//
	//# \action		Dipole3D operator *(const Dipole3D& d, float n);
	//#				Returns the product of the dipole $d$ and the scalar $n$.
	//
	//# \action		Dipole3D operator *(float n, const Dipole3D& d);
	//#				Returns the product of the dipole $d$ and the scalar $n$.
	//
	//# \action		Dipole3D operator /(const Dipole3D& d, float n);
	//#				Returns the product of the dipole $d$ and the inverse of the scalar $n$.
	//
	//# \action		Dipole3D Reverse(const Dipole3D& d);
	//#				Returns the reverse of the dipole $d$.
	//
	//# \action		Circle3D Dual(const Dipole3D& d);
	//#				Returns the reverse of the dipole $d$.
	//
	//# \action		Line3D Carrier(const Dipole3D& d);
	//#				Returns the carrier of the dipole $d$.
	//
	//# \action		Plane3D Anticarrier(const Dipole3D& d);
	//#				Returns the anticarrier of the dipole $d$.
	//
	//# \action		Round3D Attitude(const Dipole3D& d);
	//#				Returns the attitude of the dipole $d$.
	//
	//# \action		Round3D Center(const Dipole3D& d);
	//#				Returns the center of the dipole $d$.
	//
	//# \action		Point3D FlatCenter(const Dipole3D& d);
	//#				Returns the flat center of the dipole $d$.
	//
	//# \action		Sphere3D Container(const Dipole3D& d);
	//#				Returns the container of the dipole $d$.
	//
	//# \action		Dipole3D Partner(const Dipole3D& d);
	//#				Returns the partner of the dipole $d$.
	//
	//# \action		float SquaredRadiusNorm(const Dipole3D& d);
	//#				Returns the squared radius of the dipole $d$.
	//
	//# \action		float SquaredCenterNorm(const Dipole3D& d);
	//#				Returns the squared distance from the origin to the center of the dipole $d$.
	//
	//# \action		float SquaredWeightNorm(const Dipole3D& d);
	//#				Returns the squared weight of the dipole $d$.
	//
	//# \also	$@Round3D@$
	//# \also	$@Circle3D@$
	//# \also	$@Sphere3D@$


	//# \function	Dipole3D::Set		Sets all ten components of a dipole.
	//
	//# \proto	Dipole3D& Set(float vx, float vy, float vz, float mx, float my, float mz, float px, float py, float pz, float pw);
	//# \proto	Dipole3D& Set(const Vector3D& direction, const Bivector3D& moment, const Vector4D& point);
	//
	//# \param	vx,vy,vz		The coordinates of the direction of the carrier line.
	//# \param	mx,my,mz		The coordinates of the moment of the carrier line.
	//# \param	px,py,pz,pw		The coordinates of the flat point component.
	//# \param	direction		The direction of the carrier line.
	//# \param	moment			The moment of the carrier line.
	//# \param	point			The flat point component.
	//
	//# \desc
	//# The $Set$ function sets the ten coordinates of a dipole to the values specified.
	//#
	//# The return value is a reference to the dipole object.


	class Dipole3D
	{
		public:

			Vector3D		v;
			Bivector3D		m;
			Vector4D		p;

			TERATHON_API static const ConstDipole3D zero;

			inline Dipole3D() = default;

			Dipole3D(float vx, float vy, float vz, float mx, float my, float mz, float px, float py, float pz, float pw)
			{
				v.Set(vx, vy, vz);
				m.Set(mx, my, mz);
				p.Set(px, py, pz, pw);
			}

			Dipole3D(const Vector3D& direction, const Bivector3D& moment, const Vector4D& point)
			{
				v = direction;
				m = moment;
				p = point;
			}

			Dipole3D& Set(float vx, float vy, float vz, float mx, float my, float mz, float px, float py, float pz, float pw)
			{
				v.Set(vx, vy, vz);
				m.Set(mx, my, mz);
				p.Set(px, py, pz, pw);
				return (*this);
			}

			void Set(float vx, float vy, float vz, float mx, float my, float mz, float px, float py, float pz, float pw) volatile
			{
				v.Set(vx, vy, vz);
				m.Set(mx, my, mz);
				p.Set(px, py, pz, pw);
			}

			Dipole3D& Set(const Vector3D& direction, const Bivector3D& moment, const Vector4D& point)
			{
				v = direction;
				m = moment;
				p = point;
				return (*this);
			}

			void Set(const Vector3D& direction, const Bivector3D& moment, const Vector4D& point) volatile
			{
				v = direction;
				m = moment;
				p = point;
			}
	};


	inline Dipole3D Reverse(const Dipole3D& d)
	{
		return (Dipole3D(-d.v.x, -d.v.y, -d.v.z, -d.m.x, -d.m.y, -d.m.z, -d.p.x, -d.p.y, -d.p.z, -d.p.w));
	}

	inline Line3D Carrier(const Dipole3D& d)
	{
		return (Line3D(d.v, d.m));
	}

	inline Plane3D Anticarrier(const Dipole3D& d)
	{
		return (Plane3D(-d.v.x, -d.v.y, -d.v.z, d.p.w));
	}

	inline Round3D Attitude(const Dipole3D& d)
	{
		return (Round3D(d.v.x, d.v.y, d.v.z, 0.0F, d.p.w));
	}

	Round3D Center(const Dipole3D& d);
	Point3D FlatCenter(const Dipole3D& d);
	Dipole3D Partner(const Dipole3D& d);

	inline float SquaredRadiusNorm(const Dipole3D& d)
	{
		return (d.p.w * d.p.w - d.m.x * d.m.x - d.m.y * d.m.y - d.m.z * d.m.z - (d.p.x * d.v.x + d.p.y * d.v.y + d.p.z * d.v.z) * 2.0F);
	}

	inline float SquaredCenterNorm(const Dipole3D& d)
	{
		return (d.m.x * d.m.x + d.m.y * d.m.y + d.m.z * d.m.z + d.p.w * d.p.w);
	}

	inline float SquaredWeightNorm(const Dipole3D& d)
	{
		return (d.v.x * d.v.x + d.v.y * d.v.y + d.v.z * d.v.z);
	}

	inline Dipole3D operator ~(const Dipole3D& d)
	{
		return (Reverse(d));
	}

	inline Dipole3D operator -(const Dipole3D& d)
	{
		return (Dipole3D(-d.v.x, -d.v.y, -d.v.z, -d.m.x, -d.m.y, -d.m.z, -d.p.x, -d.p.y, -d.p.z, -d.p.w));
	}

	inline Dipole3D operator *(const Dipole3D& d, float n)
	{
		return (Dipole3D(d.v.x * n, d.v.y * n, d.v.z * n, d.m.x * n, d.m.y * n, d.m.z * n, d.p.x * n, d.p.y * n, d.p.z * n, d.p.w * n));
	}

	inline Dipole3D operator *(float n, const Dipole3D& d)
	{
		return (Dipole3D(n * d.v.x, n * d.v.y, n * d.v.z, n * d.m.x, n * d.m.y, n * d.m.z, n * d.p.x, n * d.p.y, n * d.p.z, n * d.p.w));
	}

	inline Dipole3D operator /(const Dipole3D& d, float n)
	{
		n = 1.0F / n;
		return (Dipole3D(d.v.x * n, d.v.y * n, d.v.z * n, d.m.x * n, d.m.y * n, d.m.z * n, d.p.x * n, d.p.y * n, d.p.z * n, d.p.w * n));
	}

	inline bool operator ==(const Dipole3D& d, const Dipole3D& f)
	{
		return ((d.v == f.v) && (d.m == f.m) && (d.p == f.p));
	}

	inline bool operator !=(const Dipole3D& d, const Dipole3D& f)
	{
		return ((d.v != f.v) || (d.m != f.m) || (d.p != f.p));
	}

	Dipole3D Wedge(const Round3D& a, const Round3D& b);
	Plane3D Wedge(const Vector4D& p, const Dipole3D& d);
	Plane3D Wedge(const Point3D& p, const Dipole3D& d);
	Round3D Antiwedge(const Plane3D& g, Dipole3D& d);
	Round3D Antiwedge(Dipole3D& d, const Plane3D& g);

	inline Plane3D Wedge(const Dipole3D& d, const Vector4D& p)
	{
		return (Wedge(p, d));
	}

	inline Plane3D Wedge(const Dipole3D& d, const Point3D& p)
	{
		return (Wedge(p, d));
	}

	inline Dipole3D operator ^(const Round3D& a, const Round3D& b)
	{
		return (Wedge(a, b));
	}

	inline Plane3D operator ^(const Vector4D& p, const Dipole3D& d)
	{
		return (Wedge(p, d));
	}

	inline Plane3D operator ^(const Point3D& p, const Dipole3D& d)
	{
		return (Wedge(p, d));
	}

	inline Round3D operator ^(const Plane3D& g, Dipole3D& d)
	{
		return (Antiwedge(g, d));
	}

	inline Round3D operator ^(Dipole3D& d, const Plane3D& g)
	{
		return (Antiwedge(d, g));
	}

	inline Plane3D operator ^(const Dipole3D& d, const Vector4D& p)
	{
		return (Wedge(p, d));
	}

	inline Plane3D operator ^(const Dipole3D& d, const Point3D& p)
	{
		return (Wedge(p, d));
	}


	struct ConstDipole3D
	{
		float	vx, vy, vz;
		float	mx, my, mz;
		float	px, py, pz, pw;

		operator const Dipole3D&(void) const
		{
			return (reinterpret_cast<const Dipole3D&>(*this));
		}

		const Dipole3D *operator &(void) const
		{
			return (reinterpret_cast<const Dipole3D *>(this));
		}

		const Dipole3D *operator ->(void) const
		{
			return (reinterpret_cast<const Dipole3D *>(this));
		}
	};
}


#endif
