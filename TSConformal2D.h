//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSConformal2D_h
#define TSConformal2D_h


#include "TSRigid2D.h"


#define TERATHON_ROUNDPOINT2D 1
#define TERATHON_DIPOLE2D 1
#define TERATHON_CIRCLE2D 1


namespace Terathon
{
	struct ConstRoundPoint2D;
	struct ConstDipole2D;
	struct ConstCircle2D;


	// ==============================================
	//	RoundPoint2D
	// ==============================================

	/// \brief Encapsulates a 2D round point in conformal geometric algebra.
	///
	/// The $RoundPoint2D$ class is used to store a two-dimensional round point with a four-dimensional vector representation in conformal geometric algebra.
	///
	/// \also Dipole2D
	/// \also Circle2D

	class RoundPoint2D
	{
		public:

			float	x, y, z, w;

			TERATHON_API static const ConstRoundPoint2D zero;

			/// \brief Default constructor that leaves the components uninitialized.

			inline RoundPoint2D() = default;

			/// \brief Constructor that sets components explicitly.
			/// \param ax,ay,az,aw		The components of the round point.

			RoundPoint2D(float ax, float ay, float az, float aw)
			{
				x = ax;
				y = ay;
				z = az;
				w = aw;
			}

			/// \brief Constructor that converts a Euclidean point to a round point.
			/// \param p	The Euclidean point to convert. The <i>z</i> component of the round point is set to 1.0, and the <i>w</i> component is set to (<i>x</i><sup>2</sup> + <i>y</i><sup>2</sup>) / 2.

			RoundPoint2D(const Point2D& p)
			{
				x = p.x;
				y = p.y;
				z = 1.0F;
				w = (p.x * p.x + p.y * p.y) * 0.5F;
			}

			/// \brief Sets all five components of a 2D round point.
			/// \param ax,ay,az,aw		The new components of the round point.

			RoundPoint2D& Set(float ax, float ay, float az, float aw)
			{
				x = ax;
				y = ay;
				z = az;
				w = aw;
				return (*this);
			}

			void Set(float ax, float ay, float az, float aw) volatile
			{
				x = ax;
				y = ay;
				z = az;
				w = aw;
			}

			/// \brief Returns a reference to a scalar component of a 2D round point.
			/// \param k	The index of the component. Must be 0, 1, 2, or 3.

			float& operator [](machine k)
			{
				return ((&x)[k]);
			}

			const float& operator [](machine k) const
			{
				return ((&x)[k]);
			}

			RoundPoint2D& operator *=(float n)
			{
				x *= n;
				y *= n;
				z *= n;
				w *= n;
				return (*this);
			}

			RoundPoint2D& operator /=(float n)
			{
				n = 1.0F / n;
				x *= n;
				y *= n;
				z *= n;
				w *= n;
				return (*this);
			}

			RoundPoint2D& Unitize(void)
			{
				float n = 1.0F / z;
				x *= n;
				y *= n;
				w *= n;
				z = 1.0F;
				return (*this);
			}
	};


	/// \brief Returns the negation of the 2D round point $a$.
	/// \related RoundPoint2D

	inline RoundPoint2D operator -(const RoundPoint2D& a)
	{
		return (RoundPoint2D(-a.x, -a.y, -a.z, -a.w));
	}

	/// \brief Returns the product of the 2D round point $a$ and the scalar $n$.
	/// \related RoundPoint2D

	inline RoundPoint2D operator *(const RoundPoint2D& a, float n)
	{
		return (RoundPoint2D(a.x * n, a.y * n, a.z * n, a.w * n));
	}

	/// \brief Returns the product of the 2D round point $a$ and the scalar $n$.
	/// \related RoundPoint2D

	inline RoundPoint2D operator *(float n, const RoundPoint2D& a)
	{
		return (RoundPoint2D(n * a.x, n * a.y, n * a.z, n * a.w));
	}

	/// \brief Returns the product of the 2D round point $a$ and the inverse of the scalar $n$.
	/// \related RoundPoint2D

	inline RoundPoint2D operator /(const RoundPoint2D& a, float n)
	{
		n = 1.0F / n;
		return (RoundPoint2D(a.x * n, a.y * n, a.z * n, a.w * n));
	}

	/// \brief Returns a boolean value indicating whether the two 2D round points $a$ and $b$ are equal.
	/// \related RoundPoint2D

	inline bool operator ==(const RoundPoint2D& a, const RoundPoint2D& b)
	{
		return ((a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w));
	}

	/// \brief Returns a boolean value indicating whether the two 2D round points $a$ and $b$ are not equal.
	/// \related RoundPoint2D

	inline bool operator !=(const RoundPoint2D& a, const RoundPoint2D& b)
	{
		return ((a.x != b.x) || (a.y != b.y) || (a.z != b.z) || (a.w != b.w));
	}


	// ==============================================
	//	Dipole2D
	// ==============================================

	/// \brief Encapsulates a 2D dipole in conformal geometric algebra.
	///
	/// The $Dipole2D$ class is used to store a two-dimensional dipole with a four-dimensional bivector representation in conformal geometric algebra.
	///
	/// \also RoundPoint2D
	/// \also Circle2D

	class Dipole2D
	{
		public:

			Line2D			g;
			FlatPoint2D		p;

			TERATHON_API static const ConstDipole2D zero;

			/// \brief Default constructor that leaves the components uninitialized.

			inline Dipole2D() = default;

			/// \brief Constructor that sets components explicitly.
			/// \param gx,gy,gz		The components of the dipole corresponding to the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, and <b>e</b><sub>12</sub> basis elements.
			/// \param px,py,pz		The components of the dipole corresponding to the <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, and <b>e</b><sub>43</sub> basis elements.

			Dipole2D(float gx, float gy, float gz, float px, float py, float pz)
			{
				g.Set(gx, gy, gz);
				p.Set(px, py, pz);
			}

			/// \brief Constructor that sets components explicitly.
			/// \param line			The carrier line.
			/// \param point		The flat point component.

			Dipole2D(const Line2D& line, const FlatPoint2D& point)
			{
				g = line;
				p = point;
			}

			/// \brief Sets all six components of a 2D dipole.
			/// \param gx,gy,gz		The components of the dipole corresponding to the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, and <b>e</b><sub>12</sub> basis elements.
			/// \param px,py,pz		The components of the dipole corresponding to the <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, and <b>e</b><sub>43</sub> basis elements.

			Dipole2D& Set(float gx, float gy, float gz, float px, float py, float pz)
			{
				g.Set(gx, gy, gz);
				p.Set(px, py, pz);
				return (*this);
			}

			void Set(float gx, float gy, float gz, float px, float py, float pz) volatile
			{
				g.Set(gx, gy, gz);
				p.Set(px, py, pz);
			}

			/// \brief Sets all ten components of a 2D dipole.
			/// \param line			The carrier line.
			/// \param point		The flat point component.

			Dipole2D& Set(const Line2D& line, const FlatPoint2D& point)
			{
				g = line;
				p = point;
				return (*this);
			}

			void Set(const Line2D& line, const FlatPoint2D& point) volatile
			{
				g = line;
				p = point;
			}

			Dipole2D& operator *=(float n)
			{
				g *= n;
				p *= n;
				return (*this);
			}

			Dipole2D& operator /=(float n)
			{
				n = 1.0F / n;
				g *= n;
				p *= n;
				return (*this);
			}

			Dipole2D& Unitize(void)
			{
				return (*this *= InverseSqrt(g.x * g.x + g.y * g.y));
			}
	};


	/// \brief Returns the negation of the 2D dipole $d$.
	/// \related Dipole2D

	inline Dipole2D operator -(const Dipole2D& d)
	{
		return (Dipole2D(-d.g.x, -d.g.y, -d.g.z, -d.p.x, -d.p.y, -d.p.z));
	}

	/// \brief Returns the product of the 2D dipole $d$ and the scalar $n$.
	/// \related Dipole2D

	inline Dipole2D operator *(const Dipole2D& d, float n)
	{
		return (Dipole2D(d.g.x * n, d.g.y * n, d.g.z * n, d.p.x * n, d.p.y * n, d.p.z * n));
	}

	/// \brief Returns the product of the 2D dipole $d$ and the scalar $n$.
	/// \related Dipole2D

	inline Dipole2D operator *(float n, const Dipole2D& d)
	{
		return (Dipole2D(n * d.g.x, n * d.g.y, n * d.g.z, n * d.p.x, n * d.p.y, n * d.p.z));
	}

	/// \brief Returns the product of the 2D dipole $d$ and the inverse of the scalar $n$.
	/// \related Dipole2D

	inline Dipole2D operator /(const Dipole2D& d, float n)
	{
		n = 1.0F / n;
		return (Dipole2D(d.g.x * n, d.g.y * n, d.g.z * n, d.p.x * n, d.p.y * n, d.p.z * n));
	}

	/// \brief Returns a boolean value indicating whether the two 2D dipoles $d$ and $f$ are equal.
	/// \related Dipole2D

	inline bool operator ==(const Dipole2D& d, const Dipole2D& f)
	{
		return ((d.g == f.g) && (d.p == f.p));
	}

	/// \brief Returns a boolean value indicating whether the two 2D dipoles $d$ and $f$ are not equal.
	/// \related Dipole2D

	inline bool operator !=(const Dipole2D& d, const Dipole2D& f)
	{
		return ((d.g != f.g) || (d.p != f.p));
	}


	// ==============================================
	//	Circle2D
	// ==============================================

	/// \brief Encapsulates a 2D circle in conformal geometric algebra.
	///
	/// The $Circle2D$ class is used to store a two-dimensional circle with a four-dimensional trivector representation in conformal geometric algebra.
	///
	/// \also RoundPoint3D
	/// \also Dipole3D

	class Circle2D
	{
		public:

			float		w, x, y, z;

			TERATHON_API static const ConstCircle2D zero;

			/// \brief Default constructor that leaves the components uninitialized.

			inline Circle2D() = default;

			/// \brief Constructor that sets components explicitly.
			/// \param cw,cx,cy,cz	The components of the circle.

			Circle2D(float cw, float cx, float cy, float cz)
			{
				w = cw;
				x = cx;
				y = cy;
				z = cz;
			}

			/// \brief Sets all four components of a 3D circle.
			/// \param cw,cx,cy,cz	The new components of the circle.

			Circle2D& Set(float cw, float cx, float cy, float cz)
			{
				w = cw;
				x = cx;
				y = cy;
				z = cz;
				return (*this);
			}

			void Set(float cw, float cx, float cy, float cz) volatile
			{
				w = cw;
				x = cx;
				y = cy;
				z = cz;
			}

			Circle2D& operator *=(float n)
			{
				w *= n;
				x *= n;
				y *= n;
				z *= n;
				return (*this);
			}

			Circle2D& operator /=(float n)
			{
				n = 1.0F / n;
				w *= n;
				x *= n;
				y *= n;
				z *= n;
				return (*this);
			}

			Circle2D& Unitize(void)
			{
				float n = -1.0F / w;
				x *= n;
				y *= n;
				z *= n;
				w = -1.0F;
				return (*this);
			}
	};


	/// \brief Returns the negation of the 2D circle $c$.
	/// \related Circle2D

	inline Circle2D operator -(const Circle2D& c)
	{
		return (Circle2D(-c.w, -c.x, -c.y, -c.z));
	}

	/// \brief Returns the product of the 2D circle $c$ and the scalar $n$.
	/// \related Circle2D

	inline Circle2D operator *(const Circle2D& c, float n)
	{
		return (Circle2D(c.w * n, c.x * n, c.y * n, c.z * n));
	}

	/// \brief Returns the product of the 2D circle $c$ and the scalar $n$.
	/// \related Circle2D

	inline Circle2D operator *(float n, const Circle2D& c)
	{
		return (Circle2D(n * c.w, n * c.x, n * c.y, n * c.z));
	}

	/// \brief Returns the product of the 2D circle $c$ and the inverse of the scalar $n$.
	/// \related Circle2D

	inline Circle2D operator /(const Circle2D& c, float n)
	{
		n = 1.0F / n;
		return (Circle2D(c.w * n, c.x * n, c.y * n, c.z * n));
	}

	/// \brief Returns a boolean value indicating whether the two 2D circles $c$ and $o$ are equal.
	/// \related Circle2D

	inline bool operator ==(const Circle2D& c, const Circle2D& o)
	{
		return ((c.w == o.w) && (c.x == o.x) && (c.y == o.y) && (c.z == o.z));
	}

	/// \brief Returns a boolean value indicating whether the two 2D circles $c$ and $o$ are not equal.
	/// \related Circle2D

	inline bool operator !=(const Circle2D& c, const Circle2D& o)
	{
		return ((c.w != o.w) || (c.x != o.x) || (c.y != o.y) || (c.z != o.z));
	}


	// ==============================================
	//	Dual
	// ==============================================

	/// \brief Returns the dual of the 2D round point $a$, which is a 2D circle.
	/// \related RoundPoint2D

	inline Circle2D Dual(const RoundPoint2D& a)
	{
		return (Circle2D(-a.z, a.x, a.y, -a.w));
	}

	/// \brief Returns the dual of the 2D dipole $d$, which is a 2D dipole.
	/// \related Dipole2D

	inline Dipole2D Dual(const Dipole2D& d)
	{
		return (Dipole2D(d.g.y, -d.g.x, -d.p.z, -d.p.y, d.p.x, -d.g.z));
	}

	/// \brief Returns the dual of the 2D circle $c$, which is a 2D round point.
	/// \related Circle2D

	inline RoundPoint2D Dual(const Circle2D& c)
	{
		return (RoundPoint2D(c.x, c.y, -c.w, -c.z));
	}

	// ==============================================
	//	Reverse
	// ==============================================

	/// \brief Returns the reverse of the 2D round point $a$.
	/// \related RoundPoint2D

	inline const RoundPoint2D& Reverse(const RoundPoint2D& a)
	{
		return (a);
	}

	/// \brief Returns the reverse of the 2D dipole $d$.
	/// \related Dipole2D

	inline Dipole2D Reverse(const Dipole2D& d)
	{
		return (Dipole2D(-d.g.x, -d.g.y, -d.g.z, -d.p.x, -d.p.y, -d.p.z));
	}

	/// \brief Returns the reverse of the 2D circle $c$.
	/// \related Circle2D

	inline Circle2D Reverse(const Circle2D& c)
	{
		return (Circle2D(-c.w, -c.x, -c.y, -c.z));
	}

	// ==============================================
	//	Antireverse
	// ==============================================

	/// \brief Returns the antireverse of the 2D round point $a$.
	/// \related RoundPoint2D

	inline RoundPoint2D Antireverse(const RoundPoint2D& a)
	{
		return (RoundPoint2D(-a.x, -a.y, -a.z, a.w));
	}

	/// \brief Returns the antireverse of the 2D dipole $d$.
	/// \related Dipole2D

	inline Dipole2D Antireverse(const Dipole2D& d)
	{
		return (Dipole2D(-d.g.x, -d.g.y, -d.g.z, -d.p.x, -d.p.y, -d.p.z));
	}

	/// \brief Returns the antireverse of the 2D circle $c$.
	/// \related Circle2D

	inline const Circle2D& Antireverse(const Circle2D& c)
	{
		return (c);
	}

	inline RoundPoint2D operator ~(const RoundPoint2D& a) {return (Antireverse(a));}
	inline Dipole2D operator ~(const Dipole2D& d) {return (Antireverse(d));}
	inline const Circle2D& operator ~(const Circle2D& c) {return (Antireverse(c));}

	// ==============================================
	//	Attitude
	// ==============================================

	/// \brief Returns the attitude of the 2D round point $a$, which is a scalar.
	/// \related RoundPoint2D

	inline float Attitude(const RoundPoint2D& a)
	{
		return (-a.z);
	}

	/// \brief Returns the attitude of the 2D dipole $d$, which is a 2D round point.
	/// \related Dipole2D

	inline RoundPoint2D Attitude(const Dipole2D& d)
	{
		return (RoundPoint2D(d.g.y, -d.g.x, 0.0F, -d.p.z));
	}

	/// \brief Returns the attitude of the 2D circle $c$, which is a 2D dipole.
	/// \related Circle2D

	inline Dipole2D Attitude(const Circle2D& c)
	{
		return (Dipole2D(0.0F, 0.0F, c.w, c.y, -c.x, 0.0F));
	}

	// ==============================================
	//	Carrier
	// ==============================================

	/// \brief Returns the carrier of the 2D round point $a$, which is a 2D flat point.
	/// \related RoundPoint2D

	inline FlatPoint2D Carrier(const RoundPoint2D& a)
	{
		return (FlatPoint2D(a.x, a.y, a.z));
	}

	/// \brief Returns the carrier of the 2D dipole $d$, which is a 2D line.
	/// \related Dipole2D

	inline Line2D Carrier(const Dipole2D& d)
	{
		return (Line2D(d.g.x, d.g.y, d.g.z));
	}

	// ==============================================
	//	Cocarrier
	// ==============================================

	/// \brief Returns the cocarrier of the 2D dipole $d$, which is a 2D line.
	/// \related Dipole3D

	inline Line2D Cocarrier(const Dipole2D& d)
	{
		return (Line2D(-d.g.y, d.g.x, -d.p.z));
	}

	/// \brief Returns the cocarrier of the 2D circle $c$, which is a 2D flat point.
	/// \related Circle2D

	inline FlatPoint2D Cocarrier(const Circle2D& c)
	{
		return (FlatPoint2D(-c.x, -c.y, c.w));
	}

	// ==============================================
	//	Center
	// ==============================================

	/// \brief Returns the center of the 2D round point $a$.
	/// \related RoundPoint2D

	inline RoundPoint2D Center(const RoundPoint2D& a)
	{
		return (RoundPoint2D(a.x * a.z, a.y * a.z, a.z * a.z, a.z * a.w));
	}

	/// \brief Returns the center of the 2D dipole $d$.
	/// \related Dipole2D

	TERATHON_API RoundPoint2D Center(const Dipole2D& d);

	/// \brief Returns the center of the 2D circle $c$.
	/// \related Circle2D

	inline RoundPoint2D Center(const Circle2D& c)
	{
		return (RoundPoint2D(-c.x * c.w, -c.y * c.w, c.w * c.w, c.x * c.x + c.y * c.y - c.z * c.w));
	}

	// ==============================================
	//	FlatCenter
	// ==============================================

	/// \brief Returns the flat center of the 2D round point $a$.
	/// \related RoundPoint2D

	inline FlatPoint2D FlatCenter(const RoundPoint2D& a)
	{
		return (FlatPoint2D(a.x, a.y, a.z));
	}

	/// \brief Returns the flat center of the 2D dipole $d$.
	/// \related Dipole2D

	TERATHON_API FlatPoint2D FlatCenter(const Dipole2D& d);

	/// \brief Returns the flat center of the 3D sphere $s$.
	/// \related Sphere3D

	inline FlatPoint2D FlatCenter(const Circle2D& c)
	{
		return (FlatPoint2D(-c.x, -c.y, c.w));
	}

	// ==============================================
	//	Container
	// ==============================================

	/// \brief Returns the container of the 2D round point $a$.
	/// \related RoundPoint2D

	inline Circle2D Container(const RoundPoint2D& a)
	{
		return (Circle2D(-a.z * a.z, a.x * a.z, a.y * a.z, a.z * a.w - a.x * a.x - a.y * a.y));
	}

	/// \brief Returns the container of the 2D dipole $d$.
	/// \related Dipole2D

	TERATHON_API Circle2D Container(const Dipole2D& d);

	/// \brief Returns the container of the 2D circle $c$.
	/// \related Circle2D

	inline Circle2D Container(const Circle2D& c)
	{
		return (Circle2D(-c.w * c.w, -c.x * c.w, -c.y * c.w, -c.z * c.w));
	}

	// ==============================================
	//	Partner
	// ==============================================

	/// \brief Returns the partner of the 2D round point $a$.
	/// \related RoundPoint2D

	inline RoundPoint2D Partner(const RoundPoint2D& a)
	{
		float z2 = a.z * a.z;
		return (RoundPoint2D(a.x * z2, a.y * z2, a.z * z2, (a.x * a.x + a.y * a.y - a.z * a.w) * a.z));
	}

	/// \brief Returns the partner of the 2D dipole $d$.
	/// \related Dipole2D

	TERATHON_API Dipole2D Partner(const Dipole2D& d);

	/// \brief Returns the partner of the 2D circle $c$.
	/// \related Circle2D

	inline Circle2D Partner(const Circle2D& c)
	{
		float w2 = c.w * c.w;
		return (Circle2D(c.w * w2, c.x * w2, c.y * w2, (c.x * c.x + c.y * c.y - c.z * c.w) * c.w));
	}

	// ==============================================
	//	SquaredRadiusNorm
	// ==============================================

	/// \brief Returns the squared radius of the 2D round point $a$.
	/// \related RoundPoint2D

	inline float SquaredRadiusNorm(const RoundPoint2D& a)
	{
		return (a.z * a.w * 2.0F - a.x * a.x - a.y * a.y);
	}

	/// \brief Returns the squared radius of the 2D dipole $d$.
	/// \related Dipole2D

	inline float SquaredRadiusNorm(const Dipole2D& d)
	{
		return (d.p.z * d.p.z - d.g.z * d.g.z - (d.g.x * d.p.y - d.g.y * d.p.x) * 2.0F);
	}

	/// \brief Returns the squared radius of the 2D circle $c$.
	/// \related Circle2D

	inline float SquaredRadiusNorm(const Circle2D& c)
	{
		return (c.x * c.x + c.y * c.y - c.z * c.w * 2.0F);
	}

	// ==============================================
	//	SquaredCenterNorm
	// ==============================================

	/// \brief Returns the squared distance from the origin to the center of the 2D round point $a$.
	/// \related RoundPoint2D

	inline float SquaredCenterNorm(const RoundPoint2D& a)
	{
		return (a.x * a.x + a.y * a.y);
	}

	/// \brief Returns the squared distance from the origin to the center of the 2D dipole $d$.
	/// \related Dipole2D

	inline float SquaredCenterNorm(const Dipole2D& d)
	{
		return (d.g.z * d.g.z + d.p.z * d.p.z);
	}

	/// \brief Returns the squared distance from the origin to the center of the 2D circle $c$.
	/// \related Circle2D

	inline float SquaredCenterNorm(const Circle2D& c)
	{
		return (c.x * c.x + c.y * c.y);
	}

	// ==============================================
	//	SquaredBulkNorm
	// ==============================================

	/// \brief Returns the squared round bulk of the 2D round point $a$.
	/// \related RoundPoint2D

	inline float SquaredBulkNorm(const RoundPoint2D& a)
	{
		return (a.x * a.x + a.y * a.y);
	}

	/// \brief Returns the squared round bulk of the 2D dipole $d$.
	/// \related Dipole2D

	inline float SquaredBulkNorm(const Dipole2D& d)
	{
		return (d.g.z * d.g.z);
	}

	/// \brief Returns the squared round bulk of the 2D circle $c$.
	/// \related Circle2D

	inline float SquaredBulkNorm(const Circle2D& c)
	{
		return (0.0F);
	}

	// ==============================================
	//	SquaredWeightNorm
	// ==============================================

	/// \brief Returns the squared round weight of the 2D round point $a$.
	/// \related RoundPoint2D

	inline float SquaredWeightNorm(const RoundPoint2D& a)
	{
		return (a.z * a.z);
	}

	/// \brief Returns the squared round weight of the 2D dipole $d$.
	/// \related Dipole2D

	inline float SquaredWeightNorm(const Dipole2D& d)
	{
		return (d.g.x * d.g.x + d.g.y * d.g.y);
	}

	/// \brief Returns the squared round weight of the 2D circle $c$.
	/// \related Circle2D

	inline float SquaredWeightNorm(const Circle2D& c)
	{
		return (c.w * c.w);
	}

	// ==============================================
	//	SquaredFlatBulkNorm
	// ==============================================

	/// \brief Returns the squared flat bulk of the 2D round point $a$.
	/// \related RoundPoint2D

	inline float SquaredFlatBulkNorm(const RoundPoint2D& a)
	{
		return (a.w * a.w);
	}

	/// \brief Returns the squared flat bulk of the 2D dipole $d$.
	/// \related Dipole2D

	inline float SquaredFlatBulkNorm(const Dipole2D& d)
	{
		return (d.p.x * d.p.x + d.p.y * d.p.y);
	}

	/// \brief Returns the squared flat bulk of the 2D circle $c$.
	/// \related Circle2D

	inline float SquaredFlatBulkNorm(const Circle2D& c)
	{
		return (c.z * c.z);
	}

	// ==============================================
	//	SquaredFlatWeightNorm
	// ==============================================

	/// \brief Returns the squared flat weight of the 2D round point $a$.
	/// \related RoundPoint2D

	inline float SquaredFlatWeightNorm(const RoundPoint2D& a)
	{
		return (0.0F);
	}

	/// \brief Returns the squared flat weight of the 2D dipole $d$.
	/// \related Dipole2D

	inline float SquaredFlatWeightNorm(const Dipole2D& d)
	{
		return (d.p.z * d.p.z);
	}

	/// \brief Returns the squared flat weight of the 2D circle $c$.
	/// \related Circle2D

	inline float SquaredFlatWeightNorm(const Circle2D& c)
	{
		return (c.x * c.x + c.y * c.y);
	}

	// ==============================================
	//	Unitize
	// ==============================================

	/// \brief Calculates the unitized equivalent of a 2D round point.
	///
	/// Multiplies the 2D round point $a$ by the inverse magnitude of its weight, which is its <i>z</i> component.
	/// The return value is a round point having a <i>z</i> coordinate of one.
	///
	/// \related RoundPoint2D

	inline RoundPoint2D Unitize(const RoundPoint2D& a)
	{
		float n = 1.0F / a.z;
		return (RoundPoint2D(a.x * n, a.y * n, 1.0F, a.w * n));
	}

	/// \brief Calculates the unitized equivalent of a 2D dipole.
	///
	/// Multiplies the 2D dipole $d$ by the inverse magnitude of its weight, which is the 2D bivector given by its
	/// <i>gx</i> and <i>gy</i> coordinates. The carrier line of the returned dipole has a unit-length normal.
	///
	/// \related Dipole2D

	inline Dipole2D Unitize(const Dipole2D& d)
	{
		return (d * InverseSqrt(d.g.x * d.g.x + d.g.y * d.g.y));
	}

	/// \brief Calculates the unitized equivalent of a 2D circle.
	///
	/// Multiplies the 2D circle $c$ by the negated inverse magnitude of its weight, which is its <i>w</i> component.
	/// The return value is a circle having a <i>w</i> coordinate of negative one.
	///
	/// \related Circle2D

	inline Circle2D Unitize(const Circle2D& c)
	{
		float n = -1.0F / c.w;
		return (Circle2D(-1.0F, c.x * n, c.y * n, c.z * n));
	}

	// ==============================================
	//	Join
	// ==============================================

	/// \brief Calculates the join of the 2D round points $a$ and $b$ to produce a 2D dipole.
	/// \related RoundPoint2D

	TERATHON_API Dipole2D Wedge(const RoundPoint2D& a, const RoundPoint2D& b);

	/// \brief Calculates the join of the 2D flat point $p$ and 2D round point $a$ to produce a 2D line.
	/// \related Line2D

	TERATHON_API Line2D Wedge(const FlatPoint2D& p, const RoundPoint2D& a);

	/// \brief Calculates the join of the 2D Euclidean point $p$ and 2D round point $a$ to produce a 2D line.
	/// \related Line2D

	TERATHON_API Line2D Wedge(const Point2D& p, const RoundPoint2D& a);

	/// \brief Calculates the join of the 2D dipole $d$ and 2D round point $a$ to produce a 2D circle.
	/// \related Circle2D

	TERATHON_API Circle2D Wedge(const Dipole2D& d, const RoundPoint2D& a);

	inline Line2D Wedge(const RoundPoint2D& a, const FlatPoint2D& p) {return (Wedge(p, a));}
	inline Line2D Wedge(const RoundPoint2D& a, const Point2D& p) {return (Wedge(p, a));}
	inline Circle2D Wedge(const RoundPoint2D& a, const Dipole2D& d) {return (Wedge(d, a));}

	inline Dipole2D operator ^(const RoundPoint2D& a, const RoundPoint2D& b) {return (Wedge(a, b));}
	inline Line2D operator ^(const FlatPoint2D& p, const RoundPoint2D& a) {return (Wedge(p, a));}
	inline Line2D operator ^(const Point2D& p, const RoundPoint2D& a) {return (Wedge(p, a));}
	inline Circle2D operator ^(const Dipole2D& d, const RoundPoint2D& a) {return (Wedge(d, a));}

	inline Line2D operator ^(const RoundPoint2D& a, const FlatPoint2D& p) {return (Wedge(p, a));}
	inline Line2D operator ^(const RoundPoint2D& a, const Point2D& p) {return (Wedge(p, a));}
	inline Circle2D operator ^(const RoundPoint2D& a, const Dipole2D& d) {return (Wedge(d, a));}

	// ==============================================
	//	Meet
	// ==============================================

	/// \brief Calculates the meet of the 2D circles $c$ and $o$ to produce a 2D dipole.
	/// \related Dipole2D

	TERATHON_API Dipole2D Antiwedge(const Circle2D& c, const Circle2D& o);

	/// \brief Calculates the meet of the 2D circle $c$ and 2D line $g$ to produce a 2D dipole.
	/// \related Dipole2D

	TERATHON_API Dipole2D Antiwedge(const Circle2D& c, const Line2D& g);

	/// \brief Calculates the meet of the 2D line $g$ and 2D circle $c$ to produce a 2D dipole.
	/// \related Dipole2D

	TERATHON_API Dipole2D Antiwedge(const Line2D& g, const Circle2D& c);

	/// \brief Calculates the meet of the 2D circle $c$ and 2D dipole $d$ to produce a 2D round point.
	/// \related RoundPoint2D

	TERATHON_API RoundPoint2D Antiwedge(const Circle2D& c, const Dipole2D& d);

	/// \brief Calculates the meet of the 2D line $g$ and 2D dipole $d$ to produce a 2D round point.
	/// \related RoundPoint2D

	TERATHON_API RoundPoint2D Antiwedge(const Line2D& g, const Dipole2D& d);

	/// \brief Calculates the meet of the 2D circle $c$ and 2D flat point $p$ to produce a 2D round point.
	/// \related RoundPoint2D

	TERATHON_API RoundPoint2D Antiwedge(const Circle2D& c, const FlatPoint2D& p);

	/// \brief Calculates the meet of the 2D circle $c$ and 2D Euclidean point $p$ to produce a 2D round point.
	/// \related RoundPoint2D

	TERATHON_API RoundPoint2D Antiwedge(const Circle2D& c, const Point2D& p);

	inline RoundPoint2D Antiwedge(const Dipole2D& d, const Circle2D& c) {return (Antiwedge(c, d));}
	inline RoundPoint2D Antiwedge(const Dipole2D& d, const Line2D& g) {return (Antiwedge(g, d));}
	inline RoundPoint2D Antiwedge(const FlatPoint2D& p, const Circle2D& c) {return (Antiwedge(c, p));}
	inline RoundPoint2D Antiwedge(const Point2D& p, const Circle2D& c) {return (Antiwedge(c, p));}

	inline Dipole2D operator ^(const Circle2D& c, const Circle2D& o) {return (Antiwedge(c, o));}
	inline Dipole2D operator ^(const Circle2D& c, const Line2D& g) {return (Antiwedge(c, g));}
	inline Dipole2D operator ^(const Line2D& g, const Circle2D& c) {return (Antiwedge(g, c));}
	inline RoundPoint2D operator ^(const Circle2D& c, const Dipole2D& d) {return (Antiwedge(c, d));}
	inline RoundPoint2D operator ^(const Circle2D& c, const FlatPoint2D& p) {return (Antiwedge(c, p));}
	inline RoundPoint2D operator ^(const Circle2D& c, const Point2D& p) {return (Antiwedge(c, p));}

	inline RoundPoint2D operator ^(const Dipole2D& d, const Circle2D& c) {return (Antiwedge(c, d));}
	inline RoundPoint2D operator ^(const Dipole2D& d, const Line2D& g) {return (Antiwedge(g, d));}
	inline RoundPoint2D operator ^(const FlatPoint2D& p, const Circle2D& c) {return (Antiwedge(c, p));}
	inline RoundPoint2D operator ^(const Point2D& p, const Circle2D& c) {return (Antiwedge(c, p));}


	// ==============================================
	//	POD structures
	// ==============================================

	struct ConstRoundPoint2D
	{
		float	ax, ay, az, aw;

		operator const RoundPoint2D&(void) const
		{
			return (reinterpret_cast<const RoundPoint2D&>(*this));
		}

		const RoundPoint2D *operator &(void) const
		{
			return (reinterpret_cast<const RoundPoint2D *>(this));
		}

		const RoundPoint2D *operator ->(void) const
		{
			return (reinterpret_cast<const RoundPoint2D *>(this));
		}
	};


	struct ConstDipole2D
	{
		float	gx, gy, gz;
		float	px, py, pz;

		operator const Dipole2D&(void) const
		{
			return (reinterpret_cast<const Dipole2D&>(*this));
		}

		const Dipole2D *operator &(void) const
		{
			return (reinterpret_cast<const Dipole2D *>(this));
		}

		const Dipole2D *operator ->(void) const
		{
			return (reinterpret_cast<const Dipole2D *>(this));
		}
	};


	struct ConstCircle2D
	{
		float	cw, cx, cy, cz;

		operator const Circle2D&(void) const
		{
			return (reinterpret_cast<const Circle2D&>(*this));
		}

		const Circle2D *operator &(void) const
		{
			return (reinterpret_cast<const Circle2D *>(this));
		}

		const Circle2D *operator ->(void) const
		{
			return (reinterpret_cast<const Circle2D *>(this));
		}
	};
}


#endif
