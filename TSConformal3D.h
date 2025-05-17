//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSConformal3D_h
#define TSConformal3D_h


#include "TSRigid3D.h"


#define TERATHON_ROUNDPOINT3D 1
#define TERATHON_DIPOLE3D 1
#define TERATHON_CIRCLE3D 1
#define TERATHON_SPHERE3D 1


namespace Terathon
{
	struct ConstRoundPoint3D;
	struct ConstDipole3D;
	struct ConstCircle3D;
	struct ConstSphere3D;


	// ==============================================
	//	RoundPoint3D
	// ==============================================

	/// \brief Encapsulates a 3D <a href="https://conformalgeometricalgebra.org/wiki/index.php?title=Round_point">round point</a> in conformal geometric algebra.
	///
	/// The $RoundPoint3D$ class is used to store a three-dimensional round point with a five-dimensional vector representation in conformal geometric algebra.
	///
	/// \also Dipole3D
	/// \also Circle3D
	/// \also Sphere3D

	class RoundPoint3D
	{
		public:

			float	x, y, z, w, u;

			TERATHON_API static const ConstRoundPoint3D zero;

			/// \brief Default constructor that leaves the components uninitialized.

			inline RoundPoint3D() = default;

			/// \brief Constructor that sets components explicitly.
			/// \param ax,ay,az,aw,au	The components of the round point.

			RoundPoint3D(float ax, float ay, float az, float aw, float au)
			{
				x = ax;
				y = ay;
				z = az;
				w = aw;
				u = au;
			}

			/// \brief Constructor that converts a Euclidean point to a round point.
			/// \param p	The Euclidean point to convert. The <i>w</i> component of the round point is set to 1.0, and the <i>u</i> component is set to (<i>x</i><sup>2</sup> + <i>y</i><sup>2</sup> + <i>z</i><sup>2</sup>) / 2.

			RoundPoint3D(const Point3D& p)
			{
				x = p.x;
				y = p.y;
				z = p.z;
				w = 1.0F;
				u = (p.x * p.x + p.y * p.y + p.z * p.z) * 0.5F;
			}

			/// \brief Sets all five components of a 3D round point.
			/// \param ax,ay,az,aw,au	The new components of the round point.

			RoundPoint3D& Set(float ax, float ay, float az, float aw, float au)
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

			/// \brief Returns a reference to a scalar component of a 3D round point.
			/// \param k	The index of the component. Must be 0, 1, 2, 3, or 4.

			float& operator [](machine k)
			{
				return ((&x)[k]);
			}

			const float& operator [](machine k) const
			{
				return ((&x)[k]);
			}

			RoundPoint3D& operator *=(float n)
			{
				x *= n;
				y *= n;
				z *= n;
				w *= n;
				u *= n;
				return (*this);
			}

			RoundPoint3D& operator /=(float n)
			{
				n = 1.0F / n;
				x *= n;
				y *= n;
				z *= n;
				w *= n;
				u *= n;
				return (*this);
			}

			RoundPoint3D& Unitize(void)
			{
				float n = 1.0F / w;
				x *= n;
				y *= n;
				z *= n;
				u *= n;
				w = 1.0F;
				return (*this);
			}
	};


	/// \brief Returns the negation of the 3D round point $a$.
	/// \related RoundPoint3D

	inline RoundPoint3D operator -(const RoundPoint3D& a)
	{
		return (RoundPoint3D(-a.x, -a.y, -a.z, -a.w, -a.u));
	}

	/// \brief Returns the product of the 3D round point $a$ and the scalar $n$.
	/// \related RoundPoint3D

	inline RoundPoint3D operator *(const RoundPoint3D& a, float n)
	{
		return (RoundPoint3D(a.x * n, a.y * n, a.z * n, a.w * n, a.u * n));
	}

	/// \brief Returns the product of the 3D round point $a$ and the scalar $n$.
	/// \related RoundPoint3D

	inline RoundPoint3D operator *(float n, const RoundPoint3D& a)
	{
		return (RoundPoint3D(n * a.x, n * a.y, n * a.z, n * a.w, n * a.u));
	}

	/// \brief Returns the product of the 3D round point $a$ and the inverse of the scalar $n$.
	/// \related RoundPoint3D

	inline RoundPoint3D operator /(const RoundPoint3D& a, float n)
	{
		n = 1.0F / n;
		return (RoundPoint3D(a.x * n, a.y * n, a.z * n, a.w * n, a.u * n));
	}

	/// \brief Returns a boolean value indicating whether the two 3D round points $a$ and $b$ are equal.
	/// \related RoundPoint3D

	inline bool operator ==(const RoundPoint3D& a, const RoundPoint3D& b)
	{
		return ((a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w) && (a.u == b.u));
	}

	/// \brief Returns a boolean value indicating whether the two 3D round points $a$ and $b$ are not equal.
	/// \related RoundPoint3D

	inline bool operator !=(const RoundPoint3D& a, const RoundPoint3D& b)
	{
		return ((a.x != b.x) || (a.y != b.y) || (a.z != b.z) || (a.w != b.w) || (a.u != b.u));
	}


	// ==============================================
	//	Dipole3D
	// ==============================================

	/// \brief Encapsulates a 3D <a href="https://conformalgeometricalgebra.org/wiki/index.php?title=Dipole">dipole</a> in conformal geometric algebra.
	///
	/// The $Dipole3D$ class is used to store a three-dimensional dipole with a five-dimensional bivector representation in conformal geometric algebra.
	///
	/// \also RoundPoint3D
	/// \also Circle3D
	/// \also Sphere3D

	class Dipole3D
	{
		public:

			Vector3D		v;
			Bivector3D		m;
			FlatPoint3D		p;

			TERATHON_API static const ConstDipole3D zero;

			/// \brief Default constructor that leaves the components uninitialized.

			inline Dipole3D() = default;

			/// \brief Constructor that sets components explicitly.
			/// \param vx,vy,vz		The components of the dipole corresponding to the <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, and <b>e</b><sub>43</sub> basis elements.
			/// \param mx,my,mz		The components of the dipole corresponding to the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, and <b>e</b><sub>12</sub> basis elements.
			/// \param px,py,pz,pw	The components of the dipole corresponding to the <b>e</b><sub>15</sub>, <b>e</b><sub>25</sub>, <b>e</b><sub>35</sub>, and <b>e</b><sub>45</sub> basis elements.

			Dipole3D(float vx, float vy, float vz, float mx, float my, float mz, float px, float py, float pz, float pw)
			{
				v.Set(vx, vy, vz);
				m.Set(mx, my, mz);
				p.Set(px, py, pz, pw);
			}

			/// \brief Constructor that sets components explicitly.
			/// \param direction	The direction of the carrier line.
			/// \param moment		The moment of the carrier line.
			/// \param point		The flat point component.

			Dipole3D(const Vector3D& direction, const Bivector3D& moment, const FlatPoint3D& point)
			{
				v = direction;
				m = moment;
				p = point;
			}

			/// \brief Sets all ten components of a 3D dipole.
			/// \param vx,vy,vz		The components of the dipole corresponding to the <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, and <b>e</b><sub>43</sub> basis elements.
			/// \param mx,my,mz		The components of the dipole corresponding to the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, and <b>e</b><sub>12</sub> basis elements.
			/// \param px,py,pz,pw	The components of the dipole corresponding to the <b>e</b><sub>15</sub>, <b>e</b><sub>25</sub>, <b>e</b><sub>35</sub>, and <b>e</b><sub>45</sub> basis elements.

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

			/// \brief Sets all ten components of a 3D dipole.
			/// \param direction	The direction of the carrier line.
			/// \param moment		The moment of the carrier line.
			/// \param point		The flat point component.

			Dipole3D& Set(const Vector3D& direction, const Bivector3D& moment, const FlatPoint3D& point)
			{
				v = direction;
				m = moment;
				p = point;
				return (*this);
			}

			void Set(const Vector3D& direction, const Bivector3D& moment, const FlatPoint3D& point) volatile
			{
				v = direction;
				m = moment;
				p = point;
			}

			Dipole3D& operator *=(float n)
			{
				v *= n;
				m *= n;
				p *= n;
				return (*this);
			}

			Dipole3D& operator /=(float n)
			{
				n = 1.0F / n;
				v *= n;
				m *= n;
				p *= n;
				return (*this);
			}

			Dipole3D& Unitize(void)
			{
				return (*this *= InverseMag(v));
			}
	};


	/// \brief Returns the negation of the 3D dipole $d$.
	/// \related Dipole3D

	inline Dipole3D operator -(const Dipole3D& d)
	{
		return (Dipole3D(-d.v.x, -d.v.y, -d.v.z, -d.m.x, -d.m.y, -d.m.z, -d.p.x, -d.p.y, -d.p.z, -d.p.w));
	}

	/// \brief Returns the product of the 3D dipole $d$ and the scalar $n$.
	/// \related Dipole3D

	inline Dipole3D operator *(const Dipole3D& d, float n)
	{
		return (Dipole3D(d.v.x * n, d.v.y * n, d.v.z * n, d.m.x * n, d.m.y * n, d.m.z * n, d.p.x * n, d.p.y * n, d.p.z * n, d.p.w * n));
	}

	/// \brief Returns the product of the 3D dipole $d$ and the scalar $n$.
	/// \related Dipole3D

	inline Dipole3D operator *(float n, const Dipole3D& d)
	{
		return (Dipole3D(n * d.v.x, n * d.v.y, n * d.v.z, n * d.m.x, n * d.m.y, n * d.m.z, n * d.p.x, n * d.p.y, n * d.p.z, n * d.p.w));
	}

	/// \brief Returns the product of the 3D dipole $d$ and the inverse of the scalar $n$.
	/// \related Dipole3D

	inline Dipole3D operator /(const Dipole3D& d, float n)
	{
		n = 1.0F / n;
		return (Dipole3D(d.v.x * n, d.v.y * n, d.v.z * n, d.m.x * n, d.m.y * n, d.m.z * n, d.p.x * n, d.p.y * n, d.p.z * n, d.p.w * n));
	}

	/// \brief Returns a boolean value indicating whether the two 3D dipoles $d$ and $f$ are equal.
	/// \related Dipole3D

	inline bool operator ==(const Dipole3D& d, const Dipole3D& f)
	{
		return ((d.v == f.v) && (d.m == f.m) && (d.p == f.p));
	}

	/// \brief Returns a boolean value indicating whether the two 3D dipoles $d$ and $f$ are not equal.
	/// \related Dipole3D

	inline bool operator !=(const Dipole3D& d, const Dipole3D& f)
	{
		return ((d.v != f.v) || (d.m != f.m) || (d.p != f.p));
	}


	// ==============================================
	//	Circle3D
	// ==============================================

	/// \brief Encapsulates a 3D <a href="https://conformalgeometricalgebra.org/wiki/index.php?title=Circle">circle</a> in conformal geometric algebra.
	///
	/// The $Circle3D$ class is used to store a three-dimensional circle with a five-dimensional trivector representation in conformal geometric algebra.
	///
	/// \also RoundPoint3D
	/// \also Dipole3D
	/// \also Sphere3D

	class Circle3D
	{
		public:

			Plane3D			g;
			Vector3D		v;
			Bivector3D		m;

			TERATHON_API static const ConstCircle3D zero;

			/// \brief Default constructor that leaves the components uninitialized.

			inline Circle3D() = default;

			/// \brief Constructor that sets components explicitly.
			/// \param gx,gy,gz,gw	The components of the circle corresponding to the <b>e</b><sub>423</sub>, <b>e</b><sub>431</sub>, <b>e</b><sub>412</sub>, and <b>e</b><sub>321</sub> basis elements.
			/// \param vx,vy,vz		The components of the circle corresponding to the <b>e</b><sub>415</sub>, <b>e</b><sub>425</sub>, and <b>e</b><sub>435</sub> basis elements.
			/// \param mx,my,mz		The components of the circle corresponding to the <b>e</b><sub>235</sub>, <b>e</b><sub>315</sub>, and <b>e</b><sub>125</sub> basis elements.

			Circle3D(float gx, float gy, float gz, float gw, float vx, float vy, float vz, float mx, float my, float mz)
			{
				g.Set(gx, gy, gz, gw);
				v.Set(vx, vy, vz);
				m.Set(mx, my, mz);
			}

			/// \brief Constructor that sets components explicitly.
			/// \param plane		The carrier plane.
			/// \param direction	The direction of the flat line component.
			/// \param moment		The moment of the flat line component.

			Circle3D(const Plane3D& plane, const Vector3D& direction, const Bivector3D& moment)
			{
				g = plane;
				v = direction;
				m = moment;
			}

			/// \brief Sets all ten components of a 3D circle.
			/// \param gx,gy,gz,gw	The components of the circle corresponding to the <b>e</b><sub>423</sub>, <b>e</b><sub>431</sub>, <b>e</b><sub>412</sub>, and <b>e</b><sub>321</sub> basis elements.
			/// \param vx,vy,vz		The components of the circle corresponding to the <b>e</b><sub>415</sub>, <b>e</b><sub>425</sub>, and <b>e</b><sub>435</sub> basis elements.
			/// \param mx,my,mz		The components of the circle corresponding to the <b>e</b><sub>235</sub>, <b>e</b><sub>315</sub>, and <b>e</b><sub>125</sub> basis elements.

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

			/// \brief Sets all ten components of a 3D circle.
			/// \param plane		The carrier plane.
			/// \param direction	The direction of the flat line component.
			/// \param moment		The moment of the flat line component.

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

			Circle3D& operator *=(float n)
			{
				g *= n;
				v *= n;
				m *= n;
				return (*this);
			}

			Circle3D& operator /=(float n)
			{
				n = 1.0F / n;
				g *= n;
				v *= n;
				m *= n;
				return (*this);
			}

			Circle3D& Unitize(void)
			{
				return (*this *= InverseSqrt(g.x * g.x + g.y * g.y + g.z * g.z));
			}
	};


	/// \brief Returns the negation of the 3D circle $c$.
	/// \related Circle3D

	inline Circle3D operator -(const Circle3D& c)
	{
		return (Circle3D(-c.g.x, -c.g.y, -c.g.z, -c.g.w, -c.v.x, -c.v.y, -c.v.z, -c.m.x, -c.m.y, -c.m.z));
	}

	/// \brief Returns the product of the 3D circle $c$ and the scalar $n$.
	/// \related Circle3D

	inline Circle3D operator *(const Circle3D& c, float n)
	{
		return (Circle3D(c.g.x * n, c.g.y * n, c.g.z * n, c.g.w * n, c.v.x * n, c.v.y * n, c.v.z * n, c.m.x * n, c.m.y * n, c.m.z * n));
	}

	/// \brief Returns the product of the 3D circle $c$ and the scalar $n$.
	/// \related Circle3D

	inline Circle3D operator *(float n, const Circle3D& c)
	{
		return (Circle3D(n * c.g.x, n * c.g.y, n * c.g.z, n * c.g.w, n * c.v.x, n * c.v.y, n * c.v.z, n * c.m.x, n * c.m.y, n * c.m.z));
	}

	/// \brief Returns the product of the 3D circle $c$ and the inverse of the scalar $n$.
	/// \related Circle3D

	inline Circle3D operator /(const Circle3D& c, float n)
	{
		n = 1.0F / n;
		return (Circle3D(c.g.x * n, c.g.y * n, c.g.z * n, c.g.w * n, c.v.x * n, c.v.y * n, c.v.z * n, c.m.x * n, c.m.y * n, c.m.z * n));
	}

	/// \brief Returns a boolean value indicating whether the two 3D circles $c$ and $o$ are equal.
	/// \related Circle3D

	inline bool operator ==(const Circle3D& c, const Circle3D& o)
	{
		return ((c.g == o.g) && (c.v == o.v) && (c.m == o.m));
	}

	/// \brief Returns a boolean value indicating whether the two 3D circles $c$ and $o$ are not equal.
	/// \related Circle3D

	inline bool operator !=(const Circle3D& c, const Circle3D& o)
	{
		return ((c.g != o.g) || (c.v != o.v) || (c.m != o.m));
	}


	// ==============================================
	//	Sphere3D
	// ==============================================

	/// \brief Encapsulates a 3D <a href="https://conformalgeometricalgebra.org/wiki/index.php?title=Sphere">sphere</a> in conformal geometric algebra.
	///
	/// The $Sphere3D$ class is used to store a three-dimensional sphere with a five-dimensional quadrivector representation in conformal geometric algebra.
	///
	/// \also RoundPoint3D
	/// \also Dipole3D
	/// \also Circle3D

	class Sphere3D
	{
		public:

			float	u, x, y, z, w;

			TERATHON_API static const ConstSphere3D zero;

			/// \brief Default constructor that leaves the components uninitialized.

			inline Sphere3D() = default;

			/// \brief Constructor that sets components explicitly.
			/// \param su,sx,sy,sz,sw	The components of the sphere.

			Sphere3D(float su, float sx, float sy, float sz, float sw)
			{
				u = su;
				x = sx;
				y = sy;
				z = sz;
				w = sw;
			}

			/// \brief Sets all five components of a 3D sphere.
			/// \param su,sx,sy,sz,sw	The new components of the sphere.

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

			Sphere3D& operator *=(float n)
			{
				u *= n;
				x *= n;
				y *= n;
				z *= n;
				w *= n;
				return (*this);
			}

			Sphere3D& operator /=(float n)
			{
				n = 1.0F / n;
				u *= n;
				x *= n;
				y *= n;
				z *= n;
				w *= n;
				return (*this);
			}

			Sphere3D& Unitize(void)
			{
				float n = -1.0F / u;
				x *= n;
				y *= n;
				z *= n;
				w *= n;
				u = -1.0F;
				return (*this);
			}
	};


	/// \brief Returns the negation of the 3D sphere $s$.
	/// \related Sphere3D

	inline Sphere3D operator -(const Sphere3D& s)
	{
		return (Sphere3D(-s.u, -s.x, -s.y, -s.z, -s.w));
	}

	/// \brief Returns the product of the 3D sphere $s$ and the scalar $n$.
	/// \related Sphere3D

	inline Sphere3D operator *(const Sphere3D& s, float n)
	{
		return (Sphere3D(s.u * n, s.x * n, s.y * n, s.z * n, s.w * n));
	}

	/// \brief Returns the product of the 3D sphere $s$ and the scalar $n$.
	/// \related Sphere3D

	inline Sphere3D operator *(float n, const Sphere3D& s)
	{
		return (Sphere3D(n * s.u, n * s.x, n * s.y, n * s.z, n * s.w));
	}

	/// \brief Returns the product of the 3D sphere $s$ and the inverse of the scalar $n$.
	/// \related Sphere3D

	inline Sphere3D operator /(const Sphere3D& s, float n)
	{
		n = 1.0F / n;
		return (Sphere3D(s.u * n, s.x * n, s.y * n, s.z * n, s.w * n));
	}

	/// \brief Returns a boolean value indicating whether the two 3D spheres $s$ and $t$ are equal.
	/// \related Sphere3D

	inline bool operator ==(const Sphere3D& s, const Sphere3D& t)
	{
		return ((s.u == t.u) && (s.x == t.x) && (s.y == t.y) && (s.z == t.z) && (s.w == t.w));
	}

	/// \brief Returns a boolean value indicating whether the two 3D spheres $s$ and $t$ are not equal.
	/// \related Sphere3D

	inline bool operator !=(const Sphere3D& s, const Sphere3D& t)
	{
		return ((s.u != t.u) || (s.x != t.x) || (s.y != t.y) || (s.z != t.z) || (s.w != t.w));
	}


	// ==============================================
	//	Dual
	// ==============================================

	/// \brief Returns the dual of the 3D round point $a$, which is a 3D sphere.
	/// \related RoundPoint3D

	inline Sphere3D Dual(const RoundPoint3D& a)
	{
		return (Sphere3D(-a.w, a.x, a.y, a.z, -a.u));
	}

	/// \brief Returns the dual of the 3D dipole $d$, which is a 3D circle.
	/// \related Dipole3D

	inline Circle3D Dual(const Dipole3D& d)
	{
		return (Circle3D(-d.v.x, -d.v.y, -d.v.z, d.p.w, -d.m.x, -d.m.y, -d.m.z, -d.p.x, -d.p.y, -d.p.z));
	}

	/// \brief Returns the dual of the 3D circle $c$, which is a 3D dipole.
	/// \related Circle3D

	inline Dipole3D Dual(const Circle3D& c)
	{
		return (Dipole3D(c.g.x, c.g.y, c.g.z, c.v.x, c.v.y, c.v.z, c.m.x, c.m.y, c.m.z, -c.g.w));
	}

	/// \brief Returns the dual of the 3D sphere $s$, which is a 3D round point.
	/// \related Sphere3D

	inline RoundPoint3D Dual(const Sphere3D& s)
	{
		return (RoundPoint3D(-s.x, -s.y, -s.z, s.u, s.w));
	}

	// ==============================================
	//	Antidual
	// ==============================================

	/// \brief Returns the antidual of the 3D round point $a$, which is a 3D sphere.
	/// \related RoundPoint3D

	inline Sphere3D Antidual(const RoundPoint3D& a)
	{
		return (Sphere3D(a.w, -a.x, -a.y, -a.z, a.u));
	}

	/// \brief Returns the antidual of the 3D dipole $d$, which is a 3D circle.
	/// \related Dipole3D

	inline Circle3D Antidual(const Dipole3D& d)
	{
		return (Circle3D(d.v.x, d.v.y, d.v.z, -d.p.w, d.m.x, d.m.y, d.m.z, d.p.x, d.p.y, d.p.z));
	}

	/// \brief Returns the antidual of the 3D circle $c$, which is a 3D dipole.
	/// \related Circle3D

	inline Dipole3D Antidual(const Circle3D& c)
	{
		return (Dipole3D(-c.g.x, -c.g.y, -c.g.z, -c.v.x, -c.v.y, -c.v.z, -c.m.x, -c.m.y, -c.m.z, c.g.w));
	}

	/// \brief Returns the antidual of the 3D sphere $s$, which is a 3D round point.
	/// \related Sphere3D

	inline RoundPoint3D Antidual(const Sphere3D& s)
	{
		return (RoundPoint3D(s.x, s.y, s.z, -s.u, -s.w));
	}

	// ==============================================
	//	Reverse
	// ==============================================

	/// \brief Returns the reverse of the 3D round point $a$.
	/// \related RoundPoint3D

	inline const RoundPoint3D& Reverse(const RoundPoint3D& a)
	{
		return (a);
	}

	/// \brief Returns the reverse of the 3D dipole $d$.
	/// \related Dipole3D

	inline Dipole3D Reverse(const Dipole3D& d)
	{
		return (Dipole3D(-d.v.x, -d.v.y, -d.v.z, -d.m.x, -d.m.y, -d.m.z, -d.p.x, -d.p.y, -d.p.z, -d.p.w));
	}

	/// \brief Returns the reverse of the 3D circle $c$.
	/// \related Circle3D

	inline Circle3D Reverse(const Circle3D& c)
	{
		return (Circle3D(-c.g.x, -c.g.y, -c.g.z, -c.g.w, -c.v.x, -c.v.y, -c.v.z, -c.m.x, -c.m.y, -c.m.z));
	}

	/// \brief Returns the reverse of the 3D sphere $s$.
	/// \related Sphere3D

	inline const Sphere3D& Reverse(const Sphere3D& s)
	{
		return (s);
	}

	inline const RoundPoint3D& operator ~(const RoundPoint3D& a) {return (Reverse(a));}
	inline Dipole3D operator ~(const Dipole3D& d) {return (Reverse(d));}
	inline Circle3D operator ~(const Circle3D& c) {return (Reverse(c));}
	inline const Sphere3D& operator ~(const Sphere3D& s) {return (Reverse(s));}

	// ==============================================
	//	Attitude
	// ==============================================

	/// \brief Returns the attitude of the 3D round point $a$, which is a scalar.
	/// \related RoundPoint3D

	inline float Attitude(const RoundPoint3D& a)
	{
		return (a.w);
	}

	/// \brief Returns the attitude of the 3D dipole $d$, which is a 3D round point.
	/// \related Dipole3D

	inline RoundPoint3D Attitude(const Dipole3D& d)
	{
		return (RoundPoint3D(d.v.x, d.v.y, d.v.z, 0.0F, d.p.w));
	}

	/// \brief Returns the attitude of the 3D circle $c$, which is a 3D dipole.
	/// \related Circle3D

	inline Dipole3D Attitude(const Circle3D& c)
	{
		return (Dipole3D(0.0F, 0.0F, 0.0F, c.g.x, c.g.y, c.g.z, c.v.x, c.v.y, c.v.z, 0.0F));
	}

	/// \brief Returns the attitude of the 3D sphere $s$, which is a 3D circle.
	/// \related Sphere3D

	inline Circle3D Attitude(const Sphere3D& s)
	{
		return (Circle3D(0.0F, 0.0F, 0.0F, s.u, 0.0F, 0.0F, 0.0F, s.x, s.y, s.z));
	}

	// ==============================================
	//	Carrier
	// ==============================================

	/// \brief Returns the carrier of the 3D round point $a$, which is a 3D flat point.
	/// \related RoundPoint3D

	inline FlatPoint3D Carrier(const RoundPoint3D& a)
	{
		return (FlatPoint3D(a.x, a.y, a.z, a.w));
	}

	/// \brief Returns the carrier of the 3D dipole $d$, which is a 3D line.
	/// \related Dipole3D

	inline Line3D Carrier(const Dipole3D& d)
	{
		return (Line3D(d.v, d.m));
	}

	/// \brief Returns the carrier of the 3D circle $c$, which is a 3D plane.
	/// \related Circle3D

	inline Plane3D Carrier(const Circle3D& c)
	{
		return (c.g);
	}

	// ==============================================
	//	Cocarrier
	// ==============================================

	/// \brief Returns the cocarrier of the 3D dipole $d$, which is a 3D plane.
	/// \related Dipole3D

	inline Plane3D Cocarrier(const Dipole3D& d)
	{
		return (Plane3D(d.v.x, d.v.y, d.v.z, -d.p.w));
	}

	/// \brief Returns the cocarrier of the 3D circle $c$, which is a 3D line.
	/// \related Circle3D

	inline Line3D Cocarrier(const Circle3D& c)
	{
		return (Line3D(-c.v.x, -c.v.y, -c.v.z, -c.g.x, -c.g.y, -c.g.z));
	}

	/// \brief Returns the cocarrier of the 3D sphere $s$, which is a 3D flat point.
	/// \related Sphere3D

	inline FlatPoint3D Cocarrier(const Sphere3D& s)
	{
		return (FlatPoint3D(s.x, s.y, s.z, -s.u));
	}

	// ==============================================
	//	Center
	// ==============================================

	/// \brief Returns the center of the 3D round point $a$.
	/// \related RoundPoint3D

	inline RoundPoint3D Center(const RoundPoint3D& a)
	{
		return (RoundPoint3D(a.x * a.w, a.y * a.w, a.z * a.w, a.w * a.w, a.w * a.u));
	}

	/// \brief Returns the center of the 3D dipole $d$.
	/// \related Dipole3D

	TERATHON_API RoundPoint3D Center(const Dipole3D& d);

	/// \brief Returns the center of the 3D circle $c$.
	/// \related Circle3D

	TERATHON_API RoundPoint3D Center(const Circle3D& c);

	/// \brief Returns the center of the 3D sphere $s$.
	/// \related Sphere3D

	inline RoundPoint3D Center(const Sphere3D& s)
	{
		return (RoundPoint3D(-s.x * s.u, -s.y * s.u, -s.z * s.u, s.u * s.u, s.x * s.x + s.y * s.y + s.z * s.z - s.w * s.u));
	}

	// ==============================================
	//	FlatCenter
	// ==============================================

	/// \brief Returns the flat center of the 3D round point $a$.
	/// \related RoundPoint3D

	inline FlatPoint3D FlatCenter(const RoundPoint3D& a)
	{
		return (FlatPoint3D(a.x, a.y, a.z, a.w));
	}

	/// \brief Returns the flat center of the 3D dipole $d$.
	/// \related Dipole3D

	TERATHON_API FlatPoint3D FlatCenter(const Dipole3D& d);

	/// \brief Returns the flat center of the 3D circle $c$.
	/// \related Circle3D

	TERATHON_API FlatPoint3D FlatCenter(const Circle3D& c);

	/// \brief Returns the flat center of the 3D sphere $s$.
	/// \related Sphere3D

	inline FlatPoint3D FlatCenter(const Sphere3D& s)
	{
		return (FlatPoint3D(s.x, s.y, s.z, -s.u));
	}

	// ==============================================
	//	Container
	// ==============================================

	/// \brief Returns the container of the 3D round point $a$.
	/// \related RoundPoint3D

	inline Sphere3D Container(const RoundPoint3D& a)
	{
		return (Sphere3D(-a.w * a.w, a.x * a.w, a.y * a.w, a.z * a.w, a.w * a.u - a.x * a.x - a.y * a.y - a.z * a.z));
	}

	/// \brief Returns the container of the 3D dipole $d$.
	/// \related Dipole3D

	TERATHON_API Sphere3D Container(const Dipole3D& d);

	/// \brief Returns the container of the 3D circle $c$.
	/// \related Circle3D

	TERATHON_API Sphere3D Container(const Circle3D& c);

	/// \brief Returns the container of the 3D sphere $s$.
	/// \related Sphere3D

	inline Sphere3D Container(const Sphere3D& s)
	{
		return (Sphere3D(s.u * s.u, s.x * s.u, s.y * s.u, s.z * s.u, s.w * s.u));
	}

	// ==============================================
	//	Partner
	// ==============================================

	/// \brief Returns the partner of the 3D round point $a$.
	/// \related RoundPoint3D

	inline RoundPoint3D Partner(const RoundPoint3D& a)
	{
		float w2 = a.w * a.w;
		return (RoundPoint3D(a.x * w2, a.y * w2, a.z * w2, a.w * w2, (a.x * a.x + a.y * a.y + a.z * a.z - a.w * a.u) * a.w));
	}

	/// \brief Returns the partner of the 3D dipole $d$.
	/// \related Dipole3D

	TERATHON_API Dipole3D Partner(const Dipole3D& d);

	/// \brief Returns the partner of the 3D circle $c$.
	/// \related Circle3D

	TERATHON_API Circle3D Partner(const Circle3D& c);

	/// \brief Returns the partner of the 3D sphere $s$.
	/// \related Sphere3D

	inline Sphere3D Partner(const Sphere3D& s)
	{
		float u2 = s.u * s.u;
		return (Sphere3D(s.u * u2, s.x * u2, s.y * u2, s.z * u2, (s.x * s.x + s.y * s.y + s.z * s.z - s.w * s.u) * s.u));
	}

	// ==============================================
	//	SquaredRadiusNorm
	// ==============================================

	/// \brief Returns the squared radius of the 3D round point $a$.
	/// \related RoundPoint3D

	inline float SquaredRadiusNorm(const RoundPoint3D& a)
	{
		return (a.w * a.u * 2.0F - a.x * a.x - a.y * a.y - a.z * a.z);
	}

	/// \brief Returns the squared radius of the 3D dipole $d$.
	/// \related Dipole3D

	inline float SquaredRadiusNorm(const Dipole3D& d)
	{
		return (d.p.w * d.p.w - d.m.x * d.m.x - d.m.y * d.m.y - d.m.z * d.m.z - (d.p.x * d.v.x + d.p.y * d.v.y + d.p.z * d.v.z) * 2.0F);
	}

	/// \brief Returns the squared radius of the 3D circle $c$.
	/// \related Circle3D

	inline float SquaredRadiusNorm(const Circle3D& c)
	{
		return (c.v.x * c.v.x + c.v.y * c.v.y + c.v.z * c.v.z + (c.g.x * c.m.x + c.g.y * c.m.y + c.g.z * c.m.z) * 2.0F - c.g.w * c.g.w);
	}

	/// \brief Returns the squared radius of the 3D sphere $s$.
	/// \related Sphere3D

	inline float SquaredRadiusNorm(const Sphere3D& s)
	{
		return (s.x * s.x + s.y * s.y + s.z * s.z - s.w * s.u * 2.0F);
	}

	// ==============================================
	//	SquaredCenterNorm
	// ==============================================

	/// \brief Returns the squared distance from the origin to the center of the 3D round point $a$.
	/// \related RoundPoint3D

	inline float SquaredCenterNorm(const RoundPoint3D& a)
	{
		return (a.x * a.x + a.y * a.y + a.z * a.z);
	}

	/// \brief Returns the squared distance from the origin to the center of the 3D dipole $d$.
	/// \related Dipole3D

	inline float SquaredCenterNorm(const Dipole3D& d)
	{
		return (d.m.x * d.m.x + d.m.y * d.m.y + d.m.z * d.m.z + d.p.w * d.p.w);
	}

	/// \brief Returns the squared distance from the origin to the center of the 3D circle $c$.
	/// \related Circle3D

	inline float SquaredCenterNorm(const Circle3D& c)
	{
		return (c.g.w * c.g.w + c.v.x * c.v.x + c.v.y * c.v.y + c.v.z * c.v.z);
	}

	/// \brief Returns the squared distance from the origin to the center of the 3D sphere $s$.
	/// \related Sphere3D

	inline float SquaredCenterNorm(const Sphere3D& s)
	{
		return (s.x * s.x + s.y * s.y + s.z * s.z);
	}

	// ==============================================
	//	SquaredBulkNorm
	// ==============================================

	/// \brief Returns the squared round bulk of the 3D round point $a$.
	/// \related RoundPoint3D

	inline float SquaredBulkNorm(const RoundPoint3D& a)
	{
		return (a.x * a.x + a.y * a.y + a.z * a.z);
	}

	/// \brief Returns the squared round bulk of the 3D dipole $d$.
	/// \related Dipole3D

	inline float SquaredBulkNorm(const Dipole3D& d)
	{
		return (d.m.x * d.m.x + d.m.y * d.m.y + d.m.z * d.m.z);
	}

	/// \brief Returns the squared round bulk of the 3D circle $c$.
	/// \related Circle3D

	inline float SquaredBulkNorm(const Circle3D& c)
	{
		return (c.g.w * c.g.w);
	}

	/// \brief Returns the squared round bulk of the 3D sphere $s$.
	/// \related Sphere3D

	inline float SquaredBulkNorm(const Sphere3D& s)
	{
		return (0.0F);
	}

	// ==============================================
	//	SquaredWeightNorm
	// ==============================================

	/// \brief Returns the squared round weight of the 3D round point $a$.
	/// \related RoundPoint3D

	inline float SquaredWeightNorm(const RoundPoint3D& a)
	{
		return (a.w * a.w);
	}

	/// \brief Returns the squared round weight of the 3D dipole $d$.
	/// \related Dipole3D

	inline float SquaredWeightNorm(const Dipole3D& d)
	{
		return (d.v.x * d.v.x + d.v.y * d.v.y + d.v.z * d.v.z);
	}

	/// \brief Returns the squared round weight of the 3D circle $c$.
	/// \related Circle3D

	inline float SquaredWeightNorm(const Circle3D& c)
	{
		return (c.g.x * c.g.x + c.g.y * c.g.y + c.g.z * c.g.z);
	}

	/// \brief Returns the squared round weight of the 3D sphere $s$.
	/// \related Sphere3D

	inline float SquaredWeightNorm(const Sphere3D& s)
	{
		return (s.u * s.u);
	}

	// ==============================================
	//	SquaredFlatBulkNorm
	// ==============================================

	/// \brief Returns the squared flat bulk of the 3D round point $a$.
	/// \related RoundPoint3D

	inline float SquaredFlatBulkNorm(const RoundPoint3D& a)
	{
		return (a.u * a.u);
	}

	/// \brief Returns the squared flat bulk of the 3D dipole $d$.
	/// \related Dipole3D

	inline float SquaredFlatBulkNorm(const Dipole3D& d)
	{
		return (d.p.x * d.p.x + d.p.y * d.p.y + d.p.z * d.p.z);
	}

	/// \brief Returns the squared flat bulk of the 3D circle $c$.
	/// \related Circle3D

	inline float SquaredFlatBulkNorm(const Circle3D& c)
	{
		return (c.m.x * c.m.x + c.m.y * c.m.y + c.m.z * c.m.z);
	}

	/// \brief Returns the squared flat bulk of the 3D sphere $s$.
	/// \related Sphere3D

	inline float SquaredFlatBulkNorm(const Sphere3D& s)
	{
		return (s.w * s.w);
	}

	// ==============================================
	//	SquaredFlatWeightNorm
	// ==============================================

	/// \brief Returns the squared flat weight of the 3D round point $a$.
	/// \related RoundPoint3D

	inline float SquaredFlatWeightNorm(const RoundPoint3D& a)
	{
		return (0.0F);
	}

	/// \brief Returns the squared flat weight of the 3D dipole $d$.
	/// \related Dipole3D

	inline float SquaredFlatWeightNorm(const Dipole3D& d)
	{
		return (d.p.w * d.p.w);
	}

	/// \brief Returns the squared flat weight of the 3D circle $c$.
	/// \related Circle3D

	inline float SquaredFlatWeightNorm(const Circle3D& c)
	{
		return (c.v.x * c.v.x + c.v.y * c.v.y + c.v.z * c.v.z);
	}

	/// \brief Returns the squared flat weight of the 3D sphere $s$.
	/// \related Sphere3D

	inline float SquaredFlatWeightNorm(const Sphere3D& s)
	{
		return (s.x * s.x + s.y * s.y + s.z * s.z);
	}

	// ==============================================
	//	Unitize
	// ==============================================

	/// \brief Calculates the unitized equivalent of a 3D round point.
	///
	/// Multiplies the 3D round point $a$ by the inverse magnitude of its weight, which is its <i>w</i> component.
	/// The return value is a round point having a <i>w</i> coordinate of one.
	///
	/// \related RoundPoint3D

	inline RoundPoint3D Unitize(const RoundPoint3D& a)
	{
		float n = 1.0F / a.w;
		return (RoundPoint3D(a.x * n, a.y * n, a.z * n, 1.0F, a.u * n));
	}

	/// \brief Calculates the unitized equivalent of a 3D dipole.
	///
	/// Multiplies the 3D dipole $d$ by the inverse magnitude of its weight, which is the 3D direction component of its carrier line.
	/// The direction component of the carrier line of the returned dipole has unit length, and the magnitude of its moment component
	/// is the perpendicular distance between the origin and the carrier line.
	///
	/// \related Dipole3D

	inline Dipole3D Unitize(const Dipole3D& d)
	{
		return (d * InverseSqrt(d.v.x * d.v.x + d.v.y * d.v.y + d.v.z * d.v.z));
	}

	/// \brief Calculates the unitized equivalent of a 3D circle.
	///
	/// Multiplies the 3D circle $c$ by the inverse magnitude of its weight, which is the 3D trivector given by its
	/// <i>gx</i>, <i>gy</i>, and <i>gz</i> coordinates. The carrier plane of the returned circle has a unit-length normal.
	///
	/// \related Circle3D

	inline Circle3D Unitize(const Circle3D& c)
	{
		return (c * InverseSqrt(c.g.x * c.g.x + c.g.y * c.g.y + c.g.z * c.g.z));
	}

	/// \brief Calculates the unitized equivalent of a 3D sphere.
	///
	/// Multiplies the 3D sphere $s$ by the negated inverse magnitude of its weight, which is its <i>u</i> component.
	/// The return value is a sphere having a <i>u</i> coordinate of negative one.
	///
	/// \related Sphere3D

	inline Sphere3D Unitize(const Sphere3D& s)
	{
		float n = -1.0F / s.u;
		return (Sphere3D(-1.0F, s.x * n, s.y * n, s.z * n, s.w * n));
	}

	// ==============================================
	//	Join
	// ==============================================

	/// \brief Calculates the join of the 3D round points $a$ and $b$ to produce a 3D dipole.
	/// \related RoundPoint3D

	TERATHON_API Dipole3D Wedge(const RoundPoint3D& a, const RoundPoint3D& b);

	/// \brief Calculates the join of the 3D flat point $p$ and 3D round point $a$ to produce a 3D line.
	/// \related Line3D

	TERATHON_API Line3D Wedge(const FlatPoint3D& p, const RoundPoint3D& a);

	/// \brief Calculates the join of the 3D Euclidean point $p$ and 3D round point $a$ to produce a 3D line.
	/// \related Line3D

	TERATHON_API Line3D Wedge(const Point3D& p, const RoundPoint3D& a);

	/// \brief Calculates the join of the 3D dipole $d$ and 3D round point $a$ to produce a 3D circle.
	/// \related Circle3D

	TERATHON_API Circle3D Wedge(const Dipole3D& d, const RoundPoint3D& a);

	/// \brief Calculates the join of the 3D line $l$ and 3D round point $a$ to produce a 3D plane.
	/// \related Plane3D

	TERATHON_API Plane3D Wedge(const Line3D& l, const RoundPoint3D& a);

	/// \brief Calculates the join of the 3D round point $a$ and the line $l$ to produce a 3D plane.
	/// \related Plane3D

	TERATHON_API Plane3D Wedge(const RoundPoint3D& a, const Line3D& l);

	/// \brief Calculates the join of the 3D dipole $d$ and 3D flat point $p$ to produce a 3D plane.
	/// \related Plane3D

	TERATHON_API Plane3D Wedge(const Dipole3D& d, const FlatPoint3D& p);

	/// \brief Calculates the join of the 3D circle $d$ and 3D Euclidean point $p$ to produce a 3D plane.
	/// \related Plane3D

	TERATHON_API Plane3D Wedge(const Dipole3D& d, const Point3D& p);

	/// \brief Calculates the join of the 3D circle $c$ and 3D round point $a$ to produce a 3D sphere.
	/// \related Sphere3D

	TERATHON_API Sphere3D Wedge(const Circle3D& c, const RoundPoint3D& a);

	/// \brief Calculates the join of the 3D round point $a$ and 3D circle $c$ to produce a 3D sphere.
	/// \related Sphere3D

	TERATHON_API Sphere3D Wedge(const RoundPoint3D& a, const Circle3D& c);

	/// \brief Calculates the join of the 3D dipoles $d$ and $f$ to produce a 3D sphere.
	/// \related Sphere3D

	TERATHON_API Sphere3D Wedge(const Dipole3D& d, const Dipole3D& f);

	inline Line3D Wedge(const RoundPoint3D& a, const FlatPoint3D& p) {return (Wedge(p, a));}
	inline Line3D Wedge(const RoundPoint3D& a, const Point3D& p) {return (Wedge(p, a));}
	inline Circle3D Wedge(const RoundPoint3D& a, const Dipole3D& d) {return (Wedge(d, a));}
	inline Plane3D Wedge(const FlatPoint3D& p, const Dipole3D& d) {return (Wedge(d, p));}
	inline Plane3D Wedge(const Point3D& p, const Dipole3D& d) {return (Wedge(d, p));}

	inline Dipole3D operator ^(const RoundPoint3D& a, const RoundPoint3D& b) {return (Wedge(a, b));}
	inline Line3D operator ^(const FlatPoint3D& p, const RoundPoint3D& a) {return (Wedge(p, a));}
	inline Line3D operator ^(const Point3D& p, const RoundPoint3D& a) {return (Wedge(p, a));}
	inline Circle3D operator ^(const Dipole3D& d, const RoundPoint3D& a) {return (Wedge(d, a));}
	inline Plane3D operator ^(const Line3D& l, const RoundPoint3D& a) {return (Wedge(l, a));}
	inline Plane3D operator ^(const RoundPoint3D& a, const Line3D& l) {return (Wedge(a, l));}
	inline Plane3D operator ^(const Dipole3D& d, const FlatPoint3D& p) {return (Wedge(d, p));}
	inline Plane3D operator ^(const Dipole3D& d, const Point3D& p) {return (Wedge(d, p));}
	inline Sphere3D operator ^(const Circle3D& c, const RoundPoint3D& a) {return (Wedge(c, a));}
	inline Sphere3D operator ^(const RoundPoint3D& a, const Circle3D& c) {return (Wedge(a, c));}
	inline Sphere3D operator ^(const Dipole3D& d, const Dipole3D& f) {return (Wedge(d, f));}

	inline Line3D operator ^(const RoundPoint3D& a, const FlatPoint3D& p) {return (Wedge(p, a));}
	inline Line3D operator ^(const RoundPoint3D& a, const Point3D& p) {return (Wedge(p, a));}
	inline Circle3D operator ^(const RoundPoint3D& a, const Dipole3D& d) {return (Wedge(d, a));}
	inline Plane3D operator ^(const FlatPoint3D& p, const Dipole3D& d) {return (Wedge(d, p));}
	inline Plane3D operator ^(const Point3D& p, const Dipole3D& d) {return (Wedge(d, p));}

	// ==============================================
	//	Meet
	// ==============================================

	/// \brief Calculates the meet of the 3D spheres $s$ and $t$ to produce a 3D circle.
	/// \related Circle3D

	TERATHON_API Circle3D Antiwedge(const Sphere3D& s, const Sphere3D& t);

	/// \brief Calculates the meet of the 3D sphere $s$ and 3D plane $g$ to produce a 3D circle.
	/// \related Circle3D

	TERATHON_API Circle3D Antiwedge(const Sphere3D& s, const Plane3D& g);

	/// \brief Calculates the meet of the 3D plane $g$ and 3D sphere $s$ to produce a 3D circle.
	/// \related Circle3D

	TERATHON_API Circle3D Antiwedge(const Plane3D& g, const Sphere3D& s);

	/// \brief Calculates the meet of the 3D sphere $s$ and 3D circle $c$ to produce a 3D dipole.
	/// \related Dipole3D

	TERATHON_API Dipole3D Antiwedge(const Sphere3D& s, const Circle3D& c);

	/// \brief Calculates the meet of the 3D plane $g$ and 3D circle $c$ to produce a 3D dipole.
	/// \related Dipole3D

	TERATHON_API Dipole3D Antiwedge(const Plane3D& g, const Circle3D& c);

	/// \brief Calculates the meet of the 3D sphere $s$ and 3D line $l$ to produce a 3D dipole.
	/// \related Dipole3D

	TERATHON_API Dipole3D Antiwedge(const Sphere3D& s, const Line3D& l);

	/// \brief Calculates the meet of the 3D circles $c$ and $o$ to produce a 3D round point.
	/// \related RoundPoint3D

	TERATHON_API RoundPoint3D Antiwedge(const Circle3D& c, const Circle3D& o);

	/// \brief Calculates the meet of the 3D circle $c$ and 3D line $l$ to produce a 3D round point.
	/// \related RoundPoint3D

	TERATHON_API RoundPoint3D Antiwedge(const Circle3D& c, const Line3D& l);

	/// \brief Calculates the meet of the 3D sphere $s$ and 3D dipole $d$ to produce a 3D round point.
	/// \related RoundPoint3D

	TERATHON_API RoundPoint3D Antiwedge(const Sphere3D& s, const Dipole3D& d);

	/// \brief Calculates the meet of the 3D dipole $d$ and 3D sphere $s$ to produce a 3D round point.
	/// \related RoundPoint3D

	TERATHON_API RoundPoint3D Antiwedge(const Dipole3D& d, const Sphere3D& s);

	/// \brief Calculates the meet of the 3D plane $g$ and 3D dipole $d$ to produce a 3D round point.
	/// \related RoundPoint3D

	TERATHON_API RoundPoint3D Antiwedge(const Plane3D& g, const Dipole3D& d);

	/// \brief Calculates the meet of the 3D dipole $d$ and 3D plane $g$ to produce a 3D round point.
	/// \related RoundPoint3D

	TERATHON_API RoundPoint3D Antiwedge(const Dipole3D& d, const Plane3D& g);

	/// \brief Calculates the meet of the 3D sphere $s$ and 3D flat point $p$ to produce a 3D round point.
	/// \related RoundPoint3D

	TERATHON_API RoundPoint3D Antiwedge(const Sphere3D& s, const FlatPoint3D& p);

	/// \brief Calculates the meet of the 3D flat point $p$ and 3D sphere $s$ to produce a 3D round point.
	/// \related RoundPoint3D

	TERATHON_API RoundPoint3D Antiwedge(const FlatPoint3D& p, const Sphere3D& s);

	/// \brief Calculates the meet of the 3D sphere $s$ and 3D Euclidean $p$ to produce a 3D round point.
	/// \related RoundPoint3D

	TERATHON_API RoundPoint3D Antiwedge(const Sphere3D& s, const Point3D& p);

	/// \brief Calculates the meet of the 3D Euclidean $p$ and 3D sphere $s$ to produce a 3D round point.
	/// \related RoundPoint3D

	TERATHON_API RoundPoint3D Antiwedge(const Point3D& p, const Sphere3D& s);

	inline Dipole3D Antiwedge(const Circle3D& c, const Plane3D& g) {return (Antiwedge(g, c));}
	inline RoundPoint3D Antiwedge(const Line3D& l, const Circle3D& c) {return (Antiwedge(c, l));}
	inline Dipole3D Antiwedge(const Circle3D& c, const Sphere3D& s) {return (Antiwedge(s, c));}
	inline Dipole3D Antiwedge(const Line3D& l, const Sphere3D& s) {return (Antiwedge(s, l));}

	inline Circle3D operator ^(const Sphere3D& s, const Sphere3D& t) {return (Antiwedge(s, t));}
	inline Circle3D operator ^(const Sphere3D& s, const Plane3D& g) {return (Antiwedge(s, g));}
	inline Circle3D operator ^(const Plane3D& g, const Sphere3D& s) {return (Antiwedge(g, s));}
	inline Dipole3D operator ^(const Sphere3D& s, const Circle3D& c) {return (Antiwedge(s, c));}
	inline Dipole3D operator ^(const Plane3D& g, const Circle3D& c) {return (Antiwedge(g, c));}
	inline Dipole3D operator ^(const Sphere3D& s, const Line3D& l) {return (Antiwedge(s, l));}
	inline RoundPoint3D operator ^(const Circle3D& c, const Circle3D& o) {return (Antiwedge(c, o));}
	inline RoundPoint3D operator ^(const Circle3D& c, const Line3D& l) {return (Antiwedge(c, l));}
	inline RoundPoint3D operator ^(const Sphere3D& s, const Dipole3D& d) {return (Antiwedge(s, d));}
	inline RoundPoint3D operator ^(const Dipole3D& d, const Sphere3D& s) {return (Antiwedge(d, s));}
	inline RoundPoint3D operator ^(const Plane3D& g, const Dipole3D& d) {return (Antiwedge(g, d));}
	inline RoundPoint3D operator ^(const Dipole3D& d, const Plane3D& g) {return (Antiwedge(d, g));}
	inline RoundPoint3D operator ^(const Sphere3D& s, const FlatPoint3D& p) {return (Antiwedge(s, p));}
	inline RoundPoint3D operator ^(const FlatPoint3D& p, const Sphere3D& s) {return (Antiwedge(p, s));}
	inline RoundPoint3D operator ^(const Sphere3D& s, const Point3D& p) {return (Antiwedge(s, p));}
	inline RoundPoint3D operator ^(const Point3D& p, const Sphere3D& s) {return (Antiwedge(p, s));}

	inline Dipole3D operator ^(const Circle3D& c, const Plane3D& g) {return (Antiwedge(g, c));}
	inline RoundPoint3D operator ^(const Line3D& l, const Circle3D& c) {return (Antiwedge(c, l));}
	inline Dipole3D operator ^(const Circle3D& c, const Sphere3D& s) {return (Antiwedge(s, c));}
	inline Dipole3D operator ^(const Line3D& l, const Sphere3D& s) {return (Antiwedge(s, l));}


	// ==============================================
	//	POD structures
	// ==============================================

	struct ConstRoundPoint3D
	{
		float	ax, ay, az, aw, au;

		operator const RoundPoint3D&(void) const
		{
			return (reinterpret_cast<const RoundPoint3D&>(*this));
		}

		const RoundPoint3D *operator &(void) const
		{
			return (reinterpret_cast<const RoundPoint3D *>(this));
		}

		const RoundPoint3D *operator ->(void) const
		{
			return (reinterpret_cast<const RoundPoint3D *>(this));
		}
	};


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
