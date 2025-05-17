//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSRigid2D_h
#define TSRigid2D_h


#include "TSVector3D.h"


#define TERATHON_FLATPOINT2D 1
#define TERATHON_LINE2D 1


namespace Terathon
{
	class Line2D;
	struct ConstFlatPoint2D;
	struct ConstLine2D;


	// ==============================================
	//	FlatPoint2D
	// ==============================================

	/// \brief Encapsulates a 2D point in rigid geometric algebra.
	///
	/// The $FlatPoint2D$ class is used to store a two-dimensional flat point with a three-dimensional homogeneous vector representation in rigid geometric algebra.
	///
	/// \also Line2D

	class FlatPoint2D : public Vector3D
	{
		public:

			TERATHON_API static const ConstFlatPoint2D origin;

			/// \brief Default constructor that leaves the components uninitialized.

			inline FlatPoint2D() = default;

			/// \brief Constructor that sets components explicitly.
			/// \param a,b,c		The components of the flat point.

			FlatPoint2D(float a, float b, float c) : Vector3D(a, b, c) {}

			FlatPoint2D(const Point2D& p) : Vector3D(p) {}
			FlatPoint2D(const Vector2D& v) : Vector3D(v) {}
			FlatPoint2D(const Vector2D& v, float c) : Vector3D(v, c) {}
			explicit FlatPoint2D(const Vector3D& p) : Vector3D(p) {}

			FlatPoint2D& operator =(const Vector3D& v)
			{
				xyz = v.xyz;
				return (*this);
			}

			void operator =(const Vector3D& v) volatile
			{
				xyz = v.xyz;
			}

			FlatPoint2D& operator =(const Point2D& p)
			{
				xy = p.xy;
				z = 1.0F;
				return (*this);
			}

			void operator =(const Point2D& p) volatile
			{
				xy = p.xy;
				z = 1.0F;
			}

			FlatPoint2D& operator =(const Vector2D& v)
			{
				xy = v.xy;
				z = 0.0F;
				return (*this);
			}

			void operator =(const Vector2D& v) volatile
			{
				xy = v.xy;
				z = 0.0F;
			}

			template <typename type>
			FlatPoint2D& operator =(const Vec3D<type>& v)
			{
				x = float(v.x);
				y = float(v.y);
				z = float(v.z);
				return (*this);
			}

			FlatPoint2D& operator +=(const Vector3D& v)
			{
				xyz += v.xyz;
				return (*this);
			}

			FlatPoint2D& operator -=(const Vector3D& v)
			{
				xyz -= v.xyz;
				return (*this);
			}

			FlatPoint2D& operator *=(const Vector3D& v)
			{
				xyz *= v.xyz;
				return (*this);
			}

			FlatPoint2D& operator *=(float n)
			{
				xyz *= n;
				return (*this);
			}

			FlatPoint2D& operator /=(float n)
			{
				xyz /= n;
				return (*this);
			}

			FlatPoint2D& Unitize(void)
			{
				xy /= z;
				z = 1.0F;
				return (*this);
			}
	};


	/// \brief Returns the negation of the 2D point $p$.
	/// \related FlatPoint2D

	inline FlatPoint2D operator -(const FlatPoint2D& p)
	{
		return (FlatPoint2D(-p.x, -p.y, -p.z));
	}

	inline FlatPoint2D operator +(const FlatPoint2D& p, const Vector3D& v)
	{
		return (FlatPoint2D(p.x + v.x, p.y + v.y, p.z + v.z));
	}

	inline FlatPoint2D operator +(const Vector3D& v, const FlatPoint2D& p)
	{
		return (FlatPoint2D(v.x + p.x, v.y + p.y, v.z + p.z));
	}

	inline FlatPoint2D operator -(const FlatPoint2D& p, const Vector3D& v)
	{
		return (FlatPoint2D(p.x - v.x, p.y - v.y, p.z - v.z));
	}

	inline FlatPoint2D operator -(const Vector3D& v, const FlatPoint2D& p)
	{
		return (FlatPoint2D(v.x - p.x, v.y - p.y, v.z - p.z));
	}

	/// \brief Returns the product of the 2D point $p$ and the scalar $n$.
	/// \related FlatPoint2D

	inline FlatPoint2D operator *(const FlatPoint2D& p, float n)
	{
		return (FlatPoint2D(p.x * n, p.y * n, p.z * n));
	}

	/// \brief Returns the product of the 2D point $p$ and the scalar $n$.
	/// \related FlatPoint2D

	inline FlatPoint2D operator *(float n, const FlatPoint2D& p)
	{
		return (FlatPoint2D(n * p.x, n * p.y, n * p.z));
	}

	/// \brief Returns the product of the 2D point $p$ and the inverse of the scalar $n$.
	/// \related FlatPoint2D

	inline FlatPoint2D operator /(const FlatPoint2D& p, float n)
	{
		n = 1.0F / n;
		return (FlatPoint2D(p.x * n, p.y * n, p.z * n));
	}

	inline FlatPoint2D operator *(const FlatPoint2D& p, const Vector3D& v)
	{
		return (FlatPoint2D(p.x * v.x, p.y * v.y, p.z * v.z));
	}

	inline FlatPoint2D operator *(const Vector3D& v, const FlatPoint2D& p)
	{
		return (FlatPoint2D(v.x * p.x, v.y * p.y, v.z * p.z));
	}


	// ==============================================
	//	Line2D
	// ==============================================

	struct TypeLine2D
	{
		typedef float component_type;
		typedef Vector2D vector2D_type;
		typedef Line2D vector3D_type;
	};


	/// \brief Encapsulates a 2D line in rigid geometric algebra.
	///
	/// The $Line2D$ class is used to store a two-dimensional line with a three-dimensional bivector representation in rigid geometric algebra.
	///
	/// \also FlatPoint2D

	class Line2D : public Antivec3D<TypeLine2D>
	{
		public:

			TERATHON_API static const ConstLine2D zero;
			TERATHON_API static const ConstLine2D horizon;

			/// \brief Default constructor that leaves the components uninitialized.

			inline Line2D() = default;

			Line2D(const Line2D& v)
			{
				xyz = v.xyz;
			}

			/// \brief Constructor that sets components explicitly.
			/// \param a,b,c	The components of the line corresponding to the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, and <b>e</b><sub>12</sub> basis elements.

			Line2D(float a, float b, float c) : Antivec3D<TypeLine2D>(a, b, c) {}

			Line2D(const Point2D& p, const Point2D& q)
			{
				xyz.Set(p.y - q.y, q.x - p.x, p.x * q.y - p.y * q.x);
			}

			Line2D(const Point2D& p, const Vector2D& v)
			{
				xyz.Set(-v.y, v.x, p.x * v.y - p.y * v.x);
			}

			/// \brief Sets all three components of a 2D line.
			/// \param a,b,c	The components of the line corresponding to the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, and <b>e</b><sub>12</sub> basis elements.

			Line2D& Set(float a, float b, float c)
			{
				xyz.Set(a, b, c);
				return (*this);
			}

			void Set(float a, float b, float c) volatile
			{
				xyz.Set(a, b, c);
			}

			Line2D& Set(const Point2D& p, const Point2D& q)
			{
				xyz.Set(p.y - q.y, q.x - p.x, p.x * q.y - p.y * q.x);
				return (*this);
			}

			void Set(const Point2D& p, const Point2D& q) volatile
			{
				xyz.Set(p.y - q.y, q.x - p.x, p.x * q.y - p.y * q.x);
			}

			Line2D& Set(const Point2D& p, const Vector2D& v)
			{
				xyz.Set(-v.y, v.x, p.x * v.y - p.y * v.x);
				return (*this);
			}

			void Set(const Point2D& p, const Vector2D& v) volatile
			{
				xyz.Set(-v.y, v.x, p.x * v.y - p.y * v.x);
			}

			Line2D& operator =(const Line2D& v)
			{
				xyz = v.xyz;
				return (*this);
			}

			void operator =(const Line2D& v) volatile
			{
				xyz = v.xyz;
			}

			template <typename type_struct, int count, int index_x, int index_y, int index_z>
			Line2D& operator =(const Subvec3D<type_struct, true, count, index_x, index_y, index_z>& v)
			{
				xyz = v;
				return (*this);
			}

			template <typename type_struct, int count, int index_x, int index_y, int index_z>
			void operator =(const Subvec3D<type_struct, true, count, index_x, index_y, index_z>& v) volatile
			{
				xyz = v;
			}

			Line2D& operator *=(float n)
			{
				xyz *= n;
				return (*this);
			}

			Line2D& operator /=(float n)
			{
				xyz /= n;
				return (*this);
			}

			Line2D& Unitize(void)
			{
				return (*this *= InverseSqrt(x * x + y * y));
			}
	};


	/// \brief Returns the negation of the 2D line $g$.
	/// \related Line2D

	inline Line2D operator -(const Line2D& g)
	{
		return (Line2D(-g.x, -g.y, -g.z));
	}

	/// \brief Returns the product of the 2D line $g$ and the scalar $n$.
	/// \related Line2D

	inline Line2D operator *(const Line2D& g, float n)
	{
		return (Line2D(g.x * n, g.y * n, g.z * n));
	}

	/// \brief Returns the product of the 2D line $g$ and the scalar $n$.
	/// \related Line2D

	inline Line2D operator *(float n, const Line2D& g)
	{
		return (Line2D(n * g.x, n * g.y, n * g.z));
	}

	/// \brief Returns the product of the 2D line $g$ and the inverse of the scalar $n$.
	/// \related Line2D

	inline Line2D operator /(const Line2D& g, float n)
	{
		n = 1.0F / n;
		return (Line2D(g.x * n, g.y * n, g.z * n));
	}

	// ==============================================
	//	Complement
	// ==============================================

	/// \brief Returns the complement of the 2D flat point $p$, which is a 2D line.
	/// \related FlatPoint2D

	inline Line2D Complement(const FlatPoint2D& p)
	{
		return (Line2D(-p.x, -p.y, -p.z));
	}

	/// \brief Returns the complement of the 2D line $g$, which is a 2D flat point.
	/// \related FlatPoint2D

	inline FlatPoint2D Complement(const Line2D& g)
	{
		return (FlatPoint2D(-g.x, -g.y, -g.z));
	}

	inline Line2D operator !(const FlatPoint2D& p) {return (Complement(p));}
	inline FlatPoint2D operator !(const Line2D& g) {return (Complement(g));}

	// ==============================================
	//	BulkDual
	// ==============================================

	/// \brief Returns the bulk dual of the 2D flat point $p$, which is a 2D line through the origin.
	/// \related FlatPoint2D

	inline Line2D BulkDual(const FlatPoint2D& p)
	{
		return (Line2D(-p.x, -p.y, 0.0F));
	}

	/// \brief Returns the bulk dual of the 2D line $g$, which is the 2D origin.
	/// \related Line2D

	inline FlatPoint2D BulkDual(const Line2D& g)
	{
		return (FlatPoint2D(0.0F, 0.0F, -g.z));
	}

	// ==============================================
	//	WeightDual
	// ==============================================

	/// \brief Returns the weight dual of the 2D flat point $p$, which is the 2D horizon.
	/// \related FlatPoint2D

	inline Line2D WeightDual(const FlatPoint2D& p)
	{
		return (Line2D(0.0F, 0.0F, -p.z));
	}

	/// \brief Returns the weight dual of the 2D line $g$, which is a 2D flat point in the horizon.
	/// \related Line2D

	inline FlatPoint2D WeightDual(const Line2D& g)
	{
		return (FlatPoint2D(-g.x, -g.y, 0.0F));
	}

	// ==============================================
	//	Support
	// ==============================================

	inline FlatPoint2D Support(const Line2D& g)
	{
		return (FlatPoint2D(-g.x * g.z, -g.y * g.z, g.x * g.x + g.y * g.y));
	}

	// ==============================================
	//	Antisupport
	// ==============================================

	inline Line2D Antisupport(const FlatPoint2D& p)
	{
		return (Line2D(-p.x * p.z, -p.y * p.z, p.x * p.x + p.y * p.y));
	}

	// ==============================================
	//	Reverse
	// ==============================================

	/// \brief Returns the reverse of the 2D flat point $p$.
	/// \related FlatPoint2D

	inline const FlatPoint2D& Reverse(const FlatPoint2D& p)
	{
		return (p);
	}

	/// \brief Returns the reverse of the 2D line $g$.
	/// \related Line2D

	inline Line2D Reverse(const Line2D& g)
	{
		return (Line2D(-g.x, -g.y, -g.z));
	}

	// ==============================================
	//	Antireverse
	// ==============================================

	/// \brief Returns the antireverse of the 2D flat point $p$.
	/// \related FlatPoint2D

	inline FlatPoint2D Antireverse(const FlatPoint2D& p)
	{
		return (FlatPoint2D(-p.x, -p.y, -p.z));
	}

	/// \brief Returns the antireverse of the 2D line $g$.
	/// \related Line2D

	inline const Line2D& Antireverse(const Line2D& g)
	{
		return (g);
	}

	inline FlatPoint2D operator ~(const FlatPoint2D& p) {return (Antireverse(p));}
	inline const Line2D& operator ~(const Line2D& g) {return (g);}

	// ==============================================
	//	Attitude
	// ==============================================

	/// \brief Returns the attitude of the 2D flat point $p$, which is a scalar.
	/// \related FlatPoint2D

	inline float Attitude(const FlatPoint2D& p)
	{
		return (p.z);
	}

	/// \brief Returns the attitude of the 2D line $g$ as a 2D vector.
	/// \related Line3D

	inline Vector2D Attitude(const Line2D& g)
	{
		return (Vector2D(g.y, -g.x));
	}

	// ==============================================
	//	SquaredBulkNorm
	// ==============================================

	/// \brief Returns the squared bulk of the 2D flat point $p$.
	/// \related FlatPoint2D

	inline float SquaredBulkNorm(const FlatPoint2D& p)
	{
		return (p.x * p.x + p.y * p.y);
	}

	/// \brief Returns the squared bulk of the 2D line $g$.
	/// \related Line2D

	inline float SquaredBulkNorm(const Line2D& g)
	{
		return (g.z * g.z);
	}

	// ==============================================
	//	SquaredWeightNorm
	// ==============================================

	/// \brief Returns the squared weight of the 2D flat point $p$.
	/// \related FlatPoint2D

	inline float SquaredWeightNorm(const FlatPoint2D& p)
	{
		return (p.z * p.z);
	}

	/// \brief Returns the squared weight of the 2D line $g$.
	/// \related Line2D

	inline float SquaredWeightNorm(const Line2D& g)
	{
		return (g.x * g.x + g.y * g.y);
	}

	// ==============================================
	//	Unitize
	// ==============================================

	/// \brief Calculates the unitized equivalent of a 2D point.
	///
	/// Multiplies the 2D point $p$ by the inverse magnitude of its weight, which is its <i>z</i> component.
	/// The return value is a Euclidean point having an implicit <i>z</i> coordinate of one.
	///
	/// \related FlatPoint2D

	inline Point2D Unitize(const FlatPoint2D& p)
	{
		float n = 1.0F / p.z;
		return (Point2D(p.x * n, p.y * n));
	}

	/// \brief Calculates the unitized equivalent of a 2D line.
	///
	/// Multiplies the 2D line $g$ by the inverse magnitude of its weight, which is the 2D bivector given by
	/// its <i>x</i> and <i>y</i> coordinates. The returned line has a unit-length normal.
	/// If the <i>x</i> and <i>z</i> coordinates are both zero, then the result is undefined.
	///
	/// \related Line2D

	inline Line2D Unitize(const Line2D& g)
	{
		return (g * InverseSqrt(g.x * g.x + g.y * g.y));
	}

	// ==============================================
	//	Dot
	// ==============================================

	/// \brief Returns the dot product between 2D flat points $a$ and $b$.
	/// \related FlatPoint2D

	inline float Dot(const FlatPoint2D& a, const FlatPoint2D& b)
	{
		return (a.x * b.x + a.y * b.y);
	}

	/// \brief Returns the dot product between 2D lines $g$ and $h$.
	/// \related Line2D

	inline float Dot(const Line2D& g, const Line2D& h)
	{
		return (g.z * h.z);
	}

	// ==============================================
	//	Antidot
	// ==============================================

	/// \brief Returns the antidot product between 2D flat points $a$ and $b$.
	/// \related FlatPoint2D

	inline float Antidot(const FlatPoint2D& a, const FlatPoint2D& b)
	{
		return (a.z * b.z);
	}

	/// \brief Returns the antidot product between 2D lines $g$ and $h$.
	/// \related Line2D

	inline float Antidot(const Line2D& g, const Line2D& h)
	{
		return (g.x * h.x + g.y * h.y);
	}

	// ==============================================
	//	Translate
	// ==============================================

	/// \brief Translates the 2D flat point $p$ by the vector $t$.
	/// \related FlatPoint2D

	inline FlatPoint2D Translate(const FlatPoint2D& p, const Vector2D& t)
	{
		return (FlatPoint2D(p.xy + t.xy * p.z, p.z));
	}

	/// \brief Translates the 2D line $g$ by the vector $t$.
	/// \related Line2D

	inline Line2D Translate(const Line2D& g, const Vector2D& t)
	{
		return (Line2D(g.x, g.y, g.z - g.x * t.x - g.y * t.y));
	}

	// ==============================================
	//	Join
	// ==============================================

	/// \brief Calculates the join of the 2D flat points $p$ and $q$ to produce a 2D line.
	/// \related Line2D

	inline Line2D Wedge(const FlatPoint2D& p, const FlatPoint2D& q)
	{
		return (Line2D(p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x));
	}

	/// \brief Calculates the join of the 2D Euclidean points $p$ and $q$ to produce a 2D line.
	/// \related Line3D

	inline Line2D Wedge(const Point2D& p, const Point2D& q)
	{
		return (Line2D(p.y - q.y, q.x - p.x, p.x * q.y - p.y * q.x));
	}

	/// \brief Calculates the join of the 2D Euclidean point $p$ and 2D direction vector $v$ to produce a 2D line.
	/// \related Line3D

	inline Line2D Wedge(const Point2D& p, const Vector2D& v)
	{
		return (Line2D(-v.y, v.x, p.x * v.y - p.y * v.x));
	}

	inline Line2D operator ^(const FlatPoint2D& p, const FlatPoint2D& q) {return (Wedge(p, q));}
	inline Line2D operator ^(const Point2D& p, const Point2D& q) {return (Wedge(p, q));}
	inline Line2D operator ^(const Point2D& p, const Vector2D& v) {return (Wedge(p, v));}

	// ==============================================
	//	Meet
	// ==============================================

	/// \brief Calculates the meet of the 2D lines $g$ and $h$ to produce a 2D flat point.
	/// \related FlatPoint2D

	inline FlatPoint2D Antiwedge(const Line2D& g, const Line2D& h)
	{
		return (FlatPoint2D(g.z * h.y - g.y * h.z, g.x * h.z - g.z * h.x, g.y * h.x - g.x * h.y));
	}

	inline float Antiwedge(const Point2D& p, const Line2D& g)
	{
		return (-p.x * g.x - p.y * g.y - g.z);
	}

	inline float Antiwedge(const Line2D& g, const Point2D& p)
	{
		return (-p.x * g.x - p.y * g.y - g.z);
	}

	inline FlatPoint2D operator ^(const Line2D& g, const Line2D& h) {return (Antiwedge(g, h));}
	inline float operator ^(const Point2D& p, const Line2D& g) {return (Antiwedge(p, g));}
	inline float operator ^(const Line2D& g, const Point2D& p) {return (Antiwedge(g, p));}

	// ==============================================
	//	Project
	// ==============================================

	/// \brief Returns the projection of the 2D point $p$ onto the 2D line $g$ under the assumption that the line is unitized.

	inline Point2D Project(const Point2D& p, const Line2D& g)
	{
		return (Point2D(p + !g.xy * (p ^ g)));
	}

	// ==============================================
	//	Antiproject
	// ==============================================

	/// \brief Returns the antiprojection of the 2D line $g$ onto the 2D point $p$ (where $p$ is always unitized because it has an implicit <i>z</i> coordinate of 1).

	inline Line2D Antiproject(const Line2D& g, const Point2D& p)
	{
		return (Line2D(g.x, g.y, -p.x * g.x - p.y * g.y));
	}


	// ==============================================
	//	POD Structures
	// ==============================================

	struct ConstFlatPoint2D
	{
		float	x, y, z;

		operator const FlatPoint2D&(void) const
		{
			return (reinterpret_cast<const FlatPoint2D&>(*this));
		}

		const FlatPoint2D *operator &(void) const
		{
			return (reinterpret_cast<const FlatPoint2D *>(this));
		}

		const FlatPoint2D *operator ->(void) const
		{
			return (reinterpret_cast<const FlatPoint2D *>(this));
		}
	};


	struct ConstLine2D
	{
		float	x, y, z;

		operator const Line2D&(void) const
		{
			return (reinterpret_cast<const Line2D&>(*this));
		}

		const Line2D *operator &(void) const
		{
			return (reinterpret_cast<const Line2D *>(this));
		}

		const Line2D *operator ->(void) const
		{
			return (reinterpret_cast<const Line2D *>(this));
		}
	};
}


#endif
