//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSRigid3D_h
#define TSRigid3D_h


#include "TSBivector3D.h"
#include "TSVector4D.h"


#define TERATHON_FLATPOINT3D 1
#define TERATHON_LINE3D 1
#define TERATHON_PLANE3D 1


namespace Terathon
{
	class Plane3D;
	struct ConstFlatPoint3D;
	struct ConstLine3D;
	struct ConstPlane3D;


	// ==============================================
	//	FlatPoint3D
	// ==============================================

	/// \brief Encapsulates a 3D <a href="https://rigidgeometricalgebra.org/wiki/index.php?title=Point">point</a> in rigid geometric algebra.
	///
	/// The $FlatPoint3D$ class is used to store a three-dimensional flat point with a four-dimensional homogeneous vector representation in rigid geometric algebra.
	///
	/// \also Line3D
	/// \also Plane3D

	class FlatPoint3D : public Vector4D
	{
		public:

			TERATHON_API static const ConstFlatPoint3D origin;

			/// \brief Default constructor that leaves the components uninitialized.

			inline FlatPoint3D() = default;

			/// \brief Constructor that sets components explicitly.
			/// \param a,b,c,d		The components of the flat point.

			FlatPoint3D(float a, float b, float c, float d) : Vector4D(a, b, c, d) {}

			FlatPoint3D(const Point3D& p) : Vector4D(p) {}
			FlatPoint3D(const Vector3D& v) : Vector4D(v) {}
			FlatPoint3D(const Vector3D& v, float d) : Vector4D(v, d) {}
			explicit FlatPoint3D(const Vector4D& p) : Vector4D(p) {}

			FlatPoint3D& operator =(const Vector4D& v)
			{
				xyzw = v.xyzw;
				return (*this);
			}

			void operator =(const Vector4D& v) volatile
			{
				xyzw = v.xyzw;
			}

			FlatPoint3D& operator =(const Point3D& p)
			{
				xyz = p.xyz;
				w = 1.0F;
				return (*this);
			}

			void operator =(const Point3D& p) volatile
			{
				xyz = p.xyz;
				w = 1.0F;
			}

			FlatPoint3D& operator =(const Vector3D& v)
			{
				xyz = v.xyz;
				w = 0.0F;
				return (*this);
			}

			void operator =(const Vector3D& v) volatile
			{
				xyz = v.xyz;
				w = 0.0F;
			}

			template <typename type>
			FlatPoint3D& operator =(const Vec4D<type>& v)
			{
				x = float(v.x);
				y = float(v.y);
				z = float(v.z);
				w = float(v.w);
				return (*this);
			}

			FlatPoint3D& operator +=(const Vector4D& v)
			{
				xyzw += v.xyzw;
				return (*this);
			}

			FlatPoint3D& operator -=(const Vector4D& v)
			{
				xyzw -= v.xyzw;
				return (*this);
			}

			FlatPoint3D& operator *=(const Vector4D& v)
			{
				xyzw *= v.xyzw;
				return (*this);
			}

			FlatPoint3D& operator *=(float n)
			{
				xyzw *= n;
				return (*this);
			}

			FlatPoint3D& operator /=(float n)
			{
				xyzw /= n;
				return (*this);
			}

			FlatPoint3D& Unitize(void)
			{
				xyz /= w;
				w = 1.0F;
				return (*this);
			}
	};


	/// \brief Returns the negation of the 3D point $p$.
	/// \related FlatPoint3D

	inline FlatPoint3D operator -(const FlatPoint3D& p)
	{
		return (FlatPoint3D(-p.x, -p.y, -p.z, -p.w));
	}

	inline FlatPoint3D operator +(const FlatPoint3D& p, const Vector4D& v)
	{
		return (FlatPoint3D(p.x + v.x, p.y + v.y, p.z + v.z, p.w + v.w));
	}

	inline FlatPoint3D operator +(const Vector4D& v, const FlatPoint3D& p)
	{
		return (FlatPoint3D(v.x + p.x, v.y + p.y, v.z + p.z, v.w + p.w));
	}

	inline FlatPoint3D operator -(const FlatPoint3D& p, const Vector4D& v)
	{
		return (FlatPoint3D(p.x - v.x, p.y - v.y, p.z - v.z, p.w - v.w));
	}

	inline FlatPoint3D operator -(const Vector4D& v, const FlatPoint3D& p)
	{
		return (FlatPoint3D(v.x - p.x, v.y - p.y, v.z - p.z, v.w - p.w));
	}

	/// \brief Returns the product of the 3D point $p$ and the scalar $n$.
	/// \related FlatPoint3D

	inline FlatPoint3D operator *(const FlatPoint3D& p, float n)
	{
		return (FlatPoint3D(p.x * n, p.y * n, p.z * n, p.w * n));
	}

	/// \brief Returns the product of the 3D point $p$ and the scalar $n$.
	/// \related FlatPoint3D

	inline FlatPoint3D operator *(float n, const FlatPoint3D& p)
	{
		return (FlatPoint3D(n * p.x, n * p.y, n * p.z, n * p.w));
	}

	/// \brief Returns the product of the 3D point $p$ and the inverse of the scalar $n$.
	/// \related FlatPoint3D

	inline FlatPoint3D operator /(const FlatPoint3D& p, float n)
	{
		n = 1.0F / n;
		return (FlatPoint3D(p.x * n, p.y * n, p.z * n, p.w * n));
	}


	// ==============================================
	//	Line3D
	// ==============================================

	/// \brief Encapsulates a 3D <a href="https://rigidgeometricalgebra.org/wiki/index.php?title=Line">line</a> in rigid geometric algebra.
	///
	/// The $Line3D$ class is used to store a three-dimensional line with a four-dimensional bivector representation in rigid geometric algebra.
	/// The components of the line are stored as a Vector3D member named $v$ and a Bivector3D member named $m$.
	///
	/// \also FlatPoint3D
	/// \also Plane3D

	class Line3D
	{
		public:

			Vector3D		v;
			Bivector3D		m;

			TERATHON_API static const ConstLine3D zero;

			/// \brief Default constructor that leaves the components uninitialized.

			inline Line3D() = default;

			Line3D(const Line3D& l)
			{
				v = l.v;
				m = l.m;
			}

			/// \brief Constructor that sets components explicitly.
			/// \param vx,vy,vz		The components of the direction corresponding to the <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, and <b>e</b><sub>43</sub> basis elements.
			/// \param mx,my,mz		The components of the moment corresponding to the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, and <b>e</b><sub>12</sub> basis elements.

			Line3D(float vx, float vy, float vz, float mx, float my, float mz)
			{
				v.Set(vx, vy, vz);
				m.Set(mx, my, mz);
			}

			/// \brief Constructor that sets components explicitly.
			/// \param direction	A 3D vector corresponding to the direction of the line.
			/// \param moment		A 3D bivector corresponding to the moment of the line.

			Line3D(const Vector3D& direction, const Bivector3D& moment)
			{
				v = direction;
				m = moment;
			}

			/// \brief Sets all six components of a 3D line.
			/// \param vx,vy,vz		The components of the direction corresponding to the <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, and <b>e</b><sub>43</sub> basis elements.
			/// \param mx,my,mz		The components of the moment corresponding to the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, and <b>e</b><sub>12</sub> basis elements.

			Line3D& Set(float vx, float vy, float vz, float mx, float my, float mz)
			{
				v.Set(vx, vy, vz);
				m.Set(mx, my, mz);
				return (*this);
			}

			void Set(float vx, float vy, float vz, float mx, float my, float mz) volatile
			{
				v.Set(vx, vy, vz);
				m.Set(mx, my, mz);
			}

			/// \brief Sets all six components of a 3D line.
			/// \param direction	A 3D vector corresponding to the direction of the line.
			/// \param moment		A 3D bivector corresponding to the moment of the line.

			Line3D& Set(const Vector3D& direction, const Bivector3D& moment)
			{
				v = direction;
				m = moment;
				return (*this);
			}

			void Set(const Vector3D& direction, const Bivector3D& moment) volatile
			{
				v = direction;
				m = moment;
			}

			Line3D& operator =(const Line3D& l)
			{
				v = l.v;
				m = l.m;
				return (*this);
			}

			void operator =(const Line3D& l) volatile
			{
				v = l.v;
				m = l.m;
			}

			Line3D& operator *=(float n)
			{
				v *= n;
				m *= n;
				return (*this);
			}

			Line3D& operator /=(float n)
			{
				n = 1.0F / n;
				v *= n;
				m *= n;
				return (*this);
			}

			Line3D& Unitize(void)
			{
				return (*this *= InverseMag(v));
			}
	};


	/// \brief Returns the negation of the 3D line $l$.
	/// \related Line3D

	inline Line3D operator -(const Line3D& l)
	{
		return (Line3D(-l.v.x, -l.v.y, -l.v.z, -l.m.x, -l.m.y, -l.m.z));
	}

	/// \brief Returns the product of the 3D line $l$ and the scalar $n$.
	/// \related Line3D

	inline Line3D operator *(const Line3D& l, float n)
	{
		return (Line3D(l.v.x * n, l.v.y * n, l.v.z * n, l.m.x * n, l.m.y * n, l.m.z * n));
	}

	/// \brief Returns the product of the 3D line $l$ and the scalar $n$.
	/// \related Line3D

	inline Line3D operator *(float n, const Line3D& l)
	{
		return (Line3D(n * l.v.x, n * l.v.y, n * l.v.z, n * l.m.x, n * l.m.y, n * l.m.z));
	}

	/// \brief Returns the product of the 3D line $l$ and the inverse of the scalar $n$.
	/// \related Line3D

	inline Line3D operator /(const Line3D& l, float n)
	{
		n = 1.0F / n;
		return (Line3D(l.v.x * n, l.v.y * n, l.v.z * n, l.m.x * n, l.m.y * n, l.m.z * n));
	}

	/// \brief Returns a boolean value indicating whether the two 3D lines $k$ and $l$ are equal.
	/// \related Line3D

	inline bool operator ==(const Line3D& k, const Line3D& l)
	{
		return ((k.v == l.v) && (k.m == l.m));
	}

	/// \brief Returns a boolean value indicating whether the two 3D lines $k$ and $l$ are not equal.
	/// \related Line3D

	inline bool operator !=(const Line3D& k, const Line3D& l)
	{
		return ((k.v != l.v) || (k.m != l.m));
	}


	// ==============================================
	//	Plane3D
	// ==============================================

	struct TypePlane3D
	{
		typedef float component_type;
		typedef Vector2D vector2D_type;
		typedef Bivector3D vector3D_type;
		typedef Plane3D vector4D_type;
	};


	/// \brief Encapsulates a 3D <a href="https://rigidgeometricalgebra.org/wiki/index.php?title=Plane">plane</a> in rigid geometric algebra.
	///
	/// The $Plane3D$ class is used to store a three-dimensional plane with a four-dimensional trivector representation in rigid geometric algebra.
	///
	/// \also FlatPoint3D
	/// \also Line3D

	class Plane3D : public Antivec4D<TypePlane3D>
	{
		public:

			TERATHON_API static const ConstPlane3D zero;
			TERATHON_API static const ConstPlane3D horizon;

			/// \brief Default constructor that leaves the components uninitialized.

			inline Plane3D() = default;

			Plane3D(const Plane3D& g)
			{
				xyzw = g.xyzw;
			}

			/// \brief Constructor that sets components explicitly.
			/// \param a,b,c,d		The components of the plane.

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

			/// \brief Sets all four components of a 3D plane.
			/// \param a,b,c,d		The new components of the plane.

			Plane3D& Set(float a, float b, float c, float d)
			{
				xyzw.Set(a, b, c, d);
				return (*this);
			}

			void Set(float a, float b, float c, float d) volatile
			{
				xyzw.Set(a, b, c, d);
			}

			/// \brief Sets all four components of a 3D plane.
			/// \param n		The plane normal corresponding to the <b>e</b><sub>423</sub>, <b>e</b><sub>431</sub>, and <b>e</b><sub>412</sub> basis elements.
			/// \param d		The plane distance corresponding to the <b>e</b><sub>321</sub> basis element.

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

			/// \brief Sets all four components of a 3D plane.
			/// \param n		The plane normal corresponding to the <b>e</b><sub>423</sub>, <b>e</b><sub>431</sub>, and <b>e</b><sub>412</sub> basis elements.
			/// \param p		A point on the plane. The <i>w</i> coordinate corresponding to the <b>e</b><sub>321</sub> basis element is given by &minus;(<b>n</b>&#x202F;&and;&#x202F;<b>p</b>).

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

			Plane3D& operator =(const Plane3D& g)
			{
				xyzw = g.xyzw;
				return (*this);
			}

			void operator =(const Plane3D& g) volatile
			{
				xyzw = g.xyzw;
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


	/// \brief Returns the negation of the 3D plane $g$.
	/// \related Plane3D

	inline Plane3D operator -(const Plane3D& g)
	{
		return (Plane3D(-g.x, -g.y, -g.z, -g.w));
	}

	/// \brief Returns the product of the 3D plane $g$ and the scalar $n$.
	/// \related Plane3D

	inline Plane3D operator *(const Plane3D& g, float n)
	{
		return (Plane3D(g.x * n, g.y * n, g.z * n, g.w * n));
	}

	/// \brief Returns the product of the 3D plane $g$ and the scalar $n$.
	/// \related Plane3D

	inline Plane3D operator *(float n, const Plane3D& g)
	{
		return (Plane3D(n * g.x, n * g.y, n * g.z, n * g.w));
	}

	/// \brief Returns the product of the 3D plane $g$ and the inverse of the scalar $n$.
	/// \related Plane3D

	inline Plane3D operator /(const Plane3D& g, float n)
	{
		n = 1.0F / n;
		return (Plane3D(g.x * n, g.y * n, g.z * n, g.w * n));
	}

	// ==============================================
	//	Complements
	// ==============================================

	/// \brief Returns the left complement of the 3D flat point $p$, which is a 3D plane.
	/// \related FlatPoint3D

	inline Plane3D LeftComplement(const FlatPoint3D& p)
	{
		return (Plane3D(-p.x, -p.y, -p.z, -p.w));
	}

	/// \brief Returns the right complement of the 3D flat point $p$, which is a 3D plane.
	/// \related FlatPoint3D

	inline const Plane3D& RightComplement(const FlatPoint3D& p)
	{
		return (reinterpret_cast<const Plane3D&>(p));
	}

	/// \brief Returns the left complement of the 3D line $l$, which is another 3D line.
	/// \related Line3D

	inline Line3D LeftComplement(const Line3D& l)
	{
		return (Line3D(-l.m.x, -l.m.y, -l.m.z, -l.v.x, -l.v.y, -l.v.z));
	}

	/// \brief Returns the right complement of the 3D line $l$, which is another 3D line.
	/// \related Line3D

	inline Line3D RightComplement(const Line3D& l)
	{
		return (Line3D(-l.m.x, -l.m.y, -l.m.z, -l.v.x, -l.v.y, -l.v.z));
	}

	/// \brief Returns the left complement of the 3D plane $g$, which is a 3D flat point.
	/// \related Plane3D

	inline const FlatPoint3D& LeftComplement(const Plane3D& g)
	{
		return (reinterpret_cast<const FlatPoint3D&>(g));
	}

	/// \brief Returns the right complement of the 3D plane $g$, which is a 3D flat point.
	/// \related Plane3D

	inline FlatPoint3D RightComplement(const Plane3D& g)
	{
		return (FlatPoint3D(-g.x, -g.y, -g.z, -g.w));
	}

	inline Plane3D operator !(const Point3D& p) {return (RightComplement(p));}
	inline Line3D operator !(const Line3D& l) {return (RightComplement(l));}
	inline FlatPoint3D operator !(const Plane3D& g) {return (RightComplement(g));}

	// ==============================================
	//	BulkDual
	// ==============================================

	/// \brief Returns the bulk dual of the 3D flat point $p$, which is a 3D plane through the origin.
	/// \related FlatPoint3D

	inline Plane3D BulkDual(const FlatPoint3D& p)
	{
		return (Plane3D(-p.x, -p.y, -p.z, 0.0F));
	}

	/// \brief Returns the bulk dual of the 3D line $l$, which is a 3D line through the origin.
	/// \related Line3D

	inline Line3D BulkDual(const Line3D& l)
	{
		return (Line3D(-l.m.x, -l.m.y, -l.m.z, 0.0F, 0.0F, 0.0F));
	}

	/// \brief Returns the bulk dual of the 3D plane $g$, which is the 3D origin.
	/// \related Plane3D

	inline FlatPoint3D BulkDual(const Plane3D& g)
	{
		return (FlatPoint3D(0.0F, 0.0F, 0.0F, g.w));
	}

	// ==============================================
	//	WeightDual
	// ==============================================

	/// \brief Returns the weight dual of the 3D flat point $p$, which is the 3D horizon.
	/// \related FlatPoint3D

	inline Plane3D WeightDual(const FlatPoint3D& p)
	{
		return (Plane3D(0.0F, 0.0F, 0.0F, -p.w));
	}

	/// \brief Returns the weight dual of the 3D line $l$, which is a 3D line in the horizon.
	/// \related Line3D

	inline Line3D WeightDual(const Line3D& l)
	{
		return (Line3D(0.0F, 0.0F, 0.0F, -l.v.x, -l.v.y, -l.v.z));
	}

	/// \brief Returns the weight dual of the 3D plane $g$, which is a 3D flat point in the horizon.
	/// \related Plane3D

	inline FlatPoint3D WeightDual(const Plane3D& g)
	{
		return (FlatPoint3D(g.x, g.y, g.z, 0.0F));
	}

	// ==============================================
	//	Support
	// ==============================================

	inline FlatPoint3D Support(const Line3D& l)
	{
		return (FlatPoint3D(l.v.y * l.m.z - l.v.z * l.m.y, l.v.z * l.m.x - l.v.x * l.m.z, l.v.x * l.m.y - l.v.y * l.m.x, l.v.x * l.v.x + l.v.y * l.v.y + l.v.z * l.v.z));
	}

	inline FlatPoint3D Support(const Plane3D& g)
	{
		return (FlatPoint3D(-g.x * g.w, -g.y * g.w, -g.z * g.w, g.x * g.x + g.y * g.y + g.z * g.z));
	}

	// ==============================================
	//	Antisupport
	// ==============================================

	inline Plane3D Antisupport(const FlatPoint3D& p)
	{
		return (Plane3D(-p.x * p.w, -p.y * p.w, -p.z * p.w, p.x * p.x + p.y * p.y + p.z * p.z));
	}

	inline Plane3D Antisupport(const Point3D& p)
	{
		return (Plane3D(-p.x, -p.y, -p.z, p.x * p.x + p.y * p.y + p.z * p.z));
	}

	inline Plane3D Antisupport(const Line3D& l)
	{
		return (Plane3D(l.v.z * l.m.y - l.v.y * l.m.z, l.v.x * l.m.z - l.v.z * l.m.x, l.v.y * l.m.x - l.v.x * l.m.y, l.m.x * l.m.x + l.m.y * l.m.y + l.m.z * l.m.z));
	}

	// ==============================================
	//	Reverse
	// ==============================================

	/// \brief Returns the reverse of the 3D flat point $p$.
	/// \related FlatPoint3D

	inline const FlatPoint3D& Reverse(const FlatPoint3D& p)
	{
		return (p);
	}

	/// \brief Returns the reverse of the 3D line $l$.
	/// \related Line3D

	inline Line3D Reverse(const Line3D& l)
	{
		return (Line3D(-l.v.x, -l.v.y, -l.v.z, -l.m.x, -l.m.y, -l.m.z));
	}

	/// \brief Returns the reverse of the 3D plane $g$.
	/// \related Plane3D

	inline Plane3D Reverse(const Plane3D& g)
	{
		return (Plane3D(-g.x, -g.y, -g.z, -g.w));
	}

	// ==============================================
	//	Antireverse
	// ==============================================

	/// \brief Returns the antireverse of the 3D flat point $p$.
	/// \related FlatPoint3D

	inline FlatPoint3D Antireverse(const FlatPoint3D& p)
	{
		return (FlatPoint3D(-p.x, -p.y, -p.z, -p.w));
	}

	/// \brief Returns the antireverse of the 3D line $l$.
	/// \related Line3D

	inline Line3D Antireverse(const Line3D& l)
	{
		return (Line3D(-l.v.x, -l.v.y, -l.v.z, -l.m.x, -l.m.y, -l.m.z));
	}

	/// \brief Returns the antireverse of the 3D plane $g$.
	/// \related Plane3D

	inline const Plane3D& Antireverse(const Plane3D& g)
	{
		return (g);
	}

	inline FlatPoint3D operator ~(const FlatPoint3D& p) {return (Antireverse(p));}
	inline Line3D operator ~(const Line3D& l) {return (Antireverse(l));}
	inline const Plane3D& operator ~(const Plane3D& g) {return (Antireverse(g));}

	// ==============================================
	//	Attitude
	// ==============================================

	/// \brief Returns the attitude of the 3D flat point $p$, which is a scalar.
	/// \related FlatPoint3D

	inline float Attitude(const FlatPoint3D& p)
	{
		return (p.w);
	}

	/// \brief Returns the attitude of the 3D line $l$ as a 3D vector.
	/// \related Line3D

	inline Vector3D Attitude(const Line3D& l)
	{
		return (Vector3D(l.v.x, l.v.y, l.v.z));
	}

	/// \brief Returns the attitude of the 3D plane $g$ as a 3D bivector.
	/// \related Plane3D

	inline Bivector3D Attitude(const Plane3D& g)
	{
		return (Bivector3D(g.x, g.y, g.z));
	}

	// ==============================================
	//	SquaredBulkNorm
	// ==============================================

	/// \brief Returns the squared bulk of the 3D flat point $p$.
	/// \related FlatPoint3D

	inline float SquaredBulkNorm(const FlatPoint3D& p)
	{
		return (p.x * p.x + p.y * p.y + p.z * p.z);
	}

	/// \brief Returns the squared bulk of the 3D line $l$.
	/// \related Line3D

	inline float SquaredBulkNorm(const Line3D& l)
	{
		return (l.m.x * l.m.x + l.m.y * l.m.y + l.m.z * l.m.z);
	}

	/// \brief Returns the squared bulk of the 3D plane $g$.
	/// \related Plane3D

	inline float SquaredBulkNorm(const Plane3D& g)
	{
		return (g.w * g.w);
	}

	// ==============================================
	//	SquaredWeightNorm
	// ==============================================

	/// \brief Returns the squared weight of the 3D flat point $p$.
	/// \related FlatPoint3D

	inline float SquaredWeightNorm(const FlatPoint3D& p)
	{
		return (p.w * p.w);
	}

	/// \brief Returns the squared weight of the 3D line $l$.
	/// \related Line3D

	inline float SquaredWeightNorm(const Line3D& l)
	{
		return (l.v.x * l.v.x + l.v.y * l.v.y + l.v.z * l.v.z);
	}

	/// \brief Returns the squared weight of the 3D plane $g$.
	/// \related Plane3D

	inline float SquaredWeightNorm(const Plane3D& g)
	{
		return (g.x * g.x + g.y * g.y + g.z * g.z);
	}

	// ==============================================
	//	Unitize
	// ==============================================

	/// \brief Calculates the unitized equivalent of a 3D point.
	///
	/// Multiplies the 3D point $p$ by the inverse magnitude of its weight, which is its <i>w</i> component.
	/// The return value is a Euclidean point having an implicit <i>w</i> coordinate of one.
	///
	/// \related FlatPoint3D

	inline Point3D Unitize(const FlatPoint3D& p)
	{
		float n = 1.0F / p.w;
		return (Point3D(p.x * n, p.y * n, p.z * n));
	}

	/// \brief Calculates the unitized equivalent of a 3D line.
	///
	/// Multiplies the 3D line $l$ by the inverse magnitude of its weight, which is the 3D direction component.
	/// The direction component of the returned line has unit length, and the magnitude of its moment component
	/// is the perpendicular distance between the origin and the line.
	///
	/// \related Line3D

	inline Line3D Unitize(const Line3D& l)
	{
		return (l * InverseSqrt(l.v.x * l.v.x + l.v.y * l.v.y + l.v.z * l.v.z));
	}

	/// \brief Calculates the unitized equivalent of a 3D plane.
	///
	/// Multiplies the 3D plane $g$ by the inverse magnitude of its weight, which is the 3D bivector given by
	/// its <i>x</i>, <i>y</i>, and <i>z</i> coordinates. The returned plane has a unit-length normal.
	/// If the <i>x</i>, <i>y</i>, and <i>z</i> coordinates are all zero, then the result is undefined.
	///
	/// \related Plane3D

	inline Plane3D Unitize(const Plane3D& g)
	{
		return (g * InverseSqrt(g.x * g.x + g.y * g.y + g.z * g.z));
	}

	// ==============================================
	//	Dot
	// ==============================================

	/// \brief Returns the dot product between 3D flat points $a$ and $b$.
	/// \related FlatPoint3D

	inline float Dot(const FlatPoint3D& a, const FlatPoint3D& b)
	{
		return (a.x * b.x + a.y * b.y + a.z * b.z);
	}

	/// \brief Returns the dot product between 3D lines $k$ and $l$.
	/// \related Line3D

	inline float Dot(const Line3D& k, const Line3D& l)
	{
		return (k.m.x * l.m.x + k.m.y * l.m.y + k.m.z * l.m.z);
	}

	/// \brief Returns the dot product between 3D planes $g$ and $h$.
	/// \related Plane3D

	inline float Dot(const Plane3D& g, const Plane3D& h)
	{
		return (g.w * h.w);
	}

	// ==============================================
	//	Antidot
	// ==============================================

	/// \brief Returns the antidot product between 3D flat points $a$ and $b$.
	/// \related FlatPoint3D

	inline float Antidot(const FlatPoint3D& a, const FlatPoint3D& b)
	{
		return (a.w * b.w);
	}

	/// \brief Returns the antidot product between 3D lines $k$ and $l$.
	/// \related Line3D

	inline float Antidot(const Line3D& k, const Line3D& l)
	{
		return (k.v.x * l.v.x + k.v.y * l.v.y + k.v.z * l.v.z);
	}

	/// \brief Returns the dot product between 3D planes $g$ and $h$.
	/// \related Plane3D

	inline float Antidot(const Plane3D& g, const Plane3D& h)
	{
		return (g.x * h.x + g.y * h.y + g.z * h.z);
	}

	// ==============================================
	//	Translate
	// ==============================================

	/// \brief Translates the 3D flat point $p$ by the vector $t$.
	/// \related FlatPoint3D

	inline FlatPoint3D Translate(const FlatPoint3D& p, const Vector3D& t)
	{
		return (FlatPoint3D(p.xyz + t.xyz * p.w, p.w));
	}

	/// \brief Translates the 3D line $l$ by the vector $t$.
	/// \related Line3D

	inline Line3D Translate(const Line3D& l, const Vector3D& t)
	{
		return (Line3D(l.v, l.m + (t ^ l.v)));
	}

	/// \brief Translates the 3D plane $g$ by the vector $t$.
	/// \related Plane3D

	inline Plane3D Translate(const Plane3D& g, const Vector3D& t)
	{
		return (Plane3D(g.xyz, g.w - g.x * t.x - g.y * t.y - g.z * t.z));
	}

	// ==============================================
	//	Join
	// ==============================================

	/// \brief Calculates the join of the 3D flat points $p$ and $q$ to produce a 3D line.
	/// \related Line3D

	inline Line3D Wedge(const FlatPoint3D& p, const FlatPoint3D& q)
	{
		return (Line3D(p.w * q.x - p.x * q.w, p.w * q.y - p.y * q.w, p.w * q.z - p.z * q.w, p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x));
	}

	/// \brief Calculates the join of the 3D Euclidean points $p$ and $q$ to produce a 3D line.
	/// \related Line3D

	inline Line3D Wedge(const Point3D& p, const Point3D& q)
	{
		return (Line3D(q.x - p.x, q.y - p.y, q.z - p.z, p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x));
	}

	/// \brief Calculates the join of the 3D Euclidean point $p$ and 3D direction vector $v$ to produce a 3D line.
	/// \related Line3D

	inline Line3D Wedge(const Point3D& p, const Vector3D& v)
	{
		return (Line3D(v.x, v.y, v.z, p.y * v.z - p.z * v.y, p.z * v.x - p.x * v.z, p.x * v.y - p.y * v.x));
	}

	/// \brief Calculates the join of the 3D line $l$ and 3D flat point $p$ to produce a 3D plane.
	/// \related Plane3D

	inline Plane3D Wedge(const Line3D& l, const FlatPoint3D& p)
	{
		return (Plane3D(l.v.y * p.z - l.v.z * p.y + l.m.x * p.w,
		                l.v.z * p.x - l.v.x * p.z + l.m.y * p.w,
		                l.v.x * p.y - l.v.y * p.x + l.m.z * p.w,
		               -l.m.x * p.x - l.m.y * p.y - l.m.z * p.z));
	}

	/// \brief Calculates the join of the 3D line $l$ and 3D Euclidean point $p$ to produce a 3D plane.
	/// \related Plane3D

	inline Plane3D Wedge(const Line3D& l, const Point3D& p)
	{
		return (Plane3D(l.v.y * p.z - l.v.z * p.y + l.m.x,
		                l.v.z * p.x - l.v.x * p.z + l.m.y,
		                l.v.x * p.y - l.v.y * p.x + l.m.z,
		               -l.m.x * p.x - l.m.y * p.y - l.m.z * p.z));
	}

	/// \brief Calculates the join of the 3D line $l$ and 3D direction vector $v$ to produce a 3D plane.
	/// \related Plane3D

	inline Plane3D Wedge(const Line3D& l, const Vector3D& v)
	{
		return (Plane3D(l.v.y * v.z - l.v.z * v.y,
		                l.v.z * v.x - l.v.x * v.z,
		                l.v.x * v.y - l.v.y * v.x,
		               -l.m.x * v.x - l.m.y * v.y - l.m.z * v.z));
	}

	inline Plane3D Wedge(const FlatPoint3D& p, const Line3D& l) {return (Wedge(l, p));}
	inline Plane3D Wedge(const Point3D& p, const Line3D& l) {return (Wedge(l, p));}
	inline Plane3D Wedge(const Vector3D& v, const Line3D& l) {return (Wedge(l, v));}

	inline Line3D operator ^(const FlatPoint3D& p, const FlatPoint3D& q) {return (Wedge(p, q));}
	inline Line3D operator ^(const Point3D& p, const Point3D& q) {return (Wedge(p, q));}
	inline Line3D operator ^(const Point3D& p, const Vector3D& v) {return (Wedge(p, v));}
	inline Plane3D operator ^(const Line3D& l, const FlatPoint3D& p) {return (Wedge(l, p));}
	inline Plane3D operator ^(const Line3D& l, const Point3D& p) {return (Wedge(l, p));}
	inline Plane3D operator ^(const Line3D& l, const Vector3D& v) {return (Wedge(l, v));}

	inline Plane3D operator ^(const FlatPoint3D& p, const Line3D& l) {return (Wedge(l, p));}
	inline Plane3D operator ^(const Point3D& p, const Line3D& l) {return (Wedge(l, p));}
	inline Plane3D operator ^(const Vector3D& v, const Line3D& l) {return (Wedge(l, v));}

	// ==============================================
	//	Meet
	// ==============================================

	/// \brief Calculates the meet of the 3D planes $g$ and $h$ to produce a 3D line.
	/// \related Line3D

	inline Line3D Antiwedge(const Plane3D& g, const Plane3D& h)
	{
		return (Line3D(g.z * h.y - g.y * h.z, g.x * h.z - g.z * h.x, g.y * h.x - g.x * h.y, g.x * h.w - g.w * h.x, g.y * h.w - g.w * h.y, g.z * h.w - g.w * h.z));
	}

	/// \brief Calculates the meet of the 3D plane $g$ and 3D line $l$ to produce a 3D flat point.
	/// \related FlatPoint3D

	inline FlatPoint3D Antiwedge(const Plane3D& g, const Line3D& l)
	{
		return (FlatPoint3D(l.m.y * g.z - l.m.z * g.y + l.v.x * g.w,
		                    l.m.z * g.x - l.m.x * g.z + l.v.y * g.w,
		                    l.m.x * g.y - l.m.y * g.x + l.v.z * g.w,
		                   -l.v.x * g.x - l.v.y * g.y - l.v.z * g.z));
	}

	/// \brief Calculates the meet of the 3D lines $k$ and $l$ to produce a scalar representing the crossing relationship.
	/// \related Line3D

	inline float Antiwedge(const Line3D& k, const Line3D& l)
	{
		return (-(k.v ^ l.m) - (k.m ^ l.v));
	}

	/// \brief Calculates the meet of the 3D flat point $p$ and 3D plane $g$ to produce a scalar representing the weighted signed distance between them.
	/// \related Plane3D

	inline float Antiwedge(const FlatPoint3D& p, const Plane3D& g)
	{
		return (p.xyzw ^ g.xyzw);
	}

	inline float Antiwedge(const Point3D& p, const Plane3D& g)
	{
		return ((p.xyz ^ g.xyz) + g.w);
	}

	inline float Antiwedge(const Vector3D& v, const Plane3D& g)
	{
		return (v ^ g.xyz);
	}

	inline float Antiwedge(const Point2D& p, const Plane3D& g)
	{
		return (p.x * g.x + p.y * g.y + g.w);
	}

	inline FlatPoint3D Antiwedge(const Line3D& l, const Plane3D& g) {return (Antiwedge(g, l));}

	inline Line3D operator ^(const Plane3D& g, const Plane3D& h) {return (Antiwedge(g, h));}
	inline FlatPoint3D operator ^(const Plane3D& g, const Line3D& l) {return (Antiwedge(g, l));}
	inline float operator ^(const Line3D& k, const Line3D& l) {return (Antiwedge(k, l));}
	inline float operator ^(const FlatPoint3D& p, const Plane3D& g) {return (Antiwedge(p, g));}
	inline float operator ^(const Point3D& p, const Plane3D& g) {return (Antiwedge(p, g));}
	inline float operator ^(const Vector3D& v, const Plane3D& g) {return (Antiwedge(v, g));}
	inline float operator ^(const Point2D& p, const Plane3D& g) {return (Antiwedge(p, g));}

	inline FlatPoint3D operator ^(const Line3D& l, const Plane3D& g) {return (Antiwedge(g, l));}

	// ==============================================
	//	Project
	// ==============================================

	/// \brief Returns the projection of the 3D point $p$ onto the 3D line $l$ under the assumption that the line is unitized.

	inline Point3D Project(const Point3D& p, const Line3D& l)
	{
		float d = Dot(l.v, p);
		return (Point3D(d * l.v.x + l.v.y * l.m.z - l.v.z * l.m.y, d * l.v.y + l.v.z * l.m.x - l.v.x * l.m.z, d * l.v.z + l.v.x * l.m.y - l.v.y * l.m.x));
	}

	/// \brief Returns the projection of the 3D point $p$ onto the 3D plane $g$ under the assumption that the plane is unitized.

	inline Point3D Project(const Point3D& p, const Plane3D& g)
	{
		return (Point3D(p - !g.xyz * (p ^ g)));
	}

	/// \brief Returns the projection of the 3D line $l$ onto the 3D plane $g$ under the assumption that the plane is unitized.

	inline Line3D Project(const Line3D& l, const Plane3D& g)
	{
		return (Line3D(l.v - !g.xyz * (g.xyz ^ l.v), g.xyz * (!g.xyz ^ l.m) - (!g.xyz ^ l.v) * g.w));
	}

	// ==============================================
	//	Antiproject
	// ==============================================

	/// \brief Returns the antiprojection of the 3D line $l$ onto the 3D point $p$ (where $p$ is always unitized because it has an implicit <i>w</i> coordinate of 1).

	inline Line3D Antiproject(const Line3D& l, const Point3D& p)
	{
		return (p ^ l.v);
	}

	/// \brief Returns the antiprojection of the 3D plane $g$ onto the 3D point $p$ (where $p$ is always unitized because it has an implicit <i>w</i> coordinate of 1).

	inline Plane3D Antiproject(const Plane3D& g, const Point3D& p)
	{
		return (Plane3D(g.xyz, p));
	}

	/// \brief Returns the antiprojection of the 3D plane $g$ onto the 3D line $l$ under the assumption that the line is unitized.

	inline Plane3D Antiproject(const Plane3D& g, const Line3D& l)
	{
		return (Plane3D(g.xyz - !l.v * (g.xyz ^ l.v), l.m ^ !l.v ^ g.xyz));
	}


	// ==============================================
	//	POD Structures
	// ==============================================

	struct ConstFlatPoint3D
	{
		float	x, y, z, w;

		operator const FlatPoint3D&(void) const
		{
			return (reinterpret_cast<const FlatPoint3D&>(*this));
		}

		const FlatPoint3D *operator &(void) const
		{
			return (reinterpret_cast<const FlatPoint3D *>(this));
		}

		const FlatPoint3D *operator ->(void) const
		{
			return (reinterpret_cast<const FlatPoint3D *>(this));
		}
	};


	struct ConstLine3D
	{
		float	vx, vy, vz;
		float	mx, my, mz;

		operator const Line3D&(void) const
		{
			return (reinterpret_cast<const Line3D&>(*this));
		}

		const Line3D *operator &(void) const
		{
			return (reinterpret_cast<const Line3D *>(this));
		}

		const Line3D *operator ->(void) const
		{
			return (reinterpret_cast<const Line3D *>(this));
		}
	};


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


	typedef Line3D Bivector4D;
	typedef Plane3D Trivector4D;
	typedef Plane3D Antivector4D;
}


#endif
