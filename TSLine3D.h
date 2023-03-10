//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2023, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSLine3D_h
#define TSLine3D_h


//# \component	Math Library
//# \prefix		Math/


#include "TSBivector3D.h"
#include "TSVector4D.h"


#define TERATHON_LINE3D 1


namespace Terathon
{
	struct ConstLine3D;


	//# \class	Line3D		Encapsulates a 3D line.
	//
	//# The $Line3D$ class encapsulates a 3D line.
	//
	//# \def	class Line3D
	//
	//# \ctor	Line3D();
	//# \ctor	Line3D(float vx, float vy, float vz, float mx, float my, float mz);
	//# \ctor	Line3D(const Vector3D& direction, const Bivector3D& moment);
	//
	//# \param	vx,vy,vz	The three components of the direction of the line.
	//# \param	mx,my,mz	The three components of the moment of the line.
	//# \param	direction	A 3D vector corresponding to the direction of the line.
	//# \param	moment		A 3D bivector corresponding to the moment of the line.
	//
	//# \desc
	//# The $Line3D$ class is used to store a three dimensional line represented as a four-dimensional bivector having
	//# six floating-point components. The components of the line are stored as a $@Vector3D@$ member named $direction$
	//# and a $@Bivector3D@$ member named $moment$.
	//#
	//# The default constructor leaves the components of the line undefined.
	//
	//# \operator	Line3D& operator *=(float n);
	//#				Multiplies by the scalar $n$.
	//
	//# \operator	Line3D& operator /=(float n);
	//#				Multiplies by the inverse of the scalar $n$.
	//
	//# \action		bool operator ==(const Line3D& k, const Line3D& l);
	//#				Returns a boolean value indicating whether the two lines $k$ and $l$ are equal.
	//
	//# \action		bool operator !=(const Line3D& k, const Line3D& l);
	//#				Returns a boolean value indicating whether the two lines $k$ and $l$ are not equal.
	//
	//# \action		Line3D operator ~(const Line3D& l);
	//#				Returns the antireverse of the line $l$.
	//
	//# \action		Line3D operator -(const Line3D& l);
	//#				Returns the negation of the line $l$.
	//
	//# \action		Line3D operator *(const Line3D& l, float n);
	//#				Returns the product of the line $l$ and the scalar $n$.
	//
	//# \action		Line3D operator *(float n, const Line3D& l);
	//#				Returns the product of the line $l$ and the scalar $n$.
	//
	//# \action		Line3D operator /(const Line3D& l, float n);
	//#				Returns the product of the line $l$ and the inverse of the scalar $n$.
	//
	//# \action		Line3D operator ^(const Point3D& p, const Point3D& q);
	//#				Returns the wedge product of the points $p$ and $q$. The <i>w</i> coordinates of $p$ and $q$ are assumed to be 1.
	//
	//# \action		float operator ^(const Line3D& k, const Line3D& l);
	//#				Returns the antiwedge product of the lines $k$ and $l$.
	//#				This gives the crossing relationship between the two lines, with positive values representing clockwise crossings and negative values representing counterclockwise crossings.
	//
	//# \action		float BulkNorm(const Line3D& l);
	//#				Returns the bulk norm of the line $l$.
	//
	//# \action		float WeightNorm(const Line3D& l);
	//#				Returns the weight norm of the line $l$.
	//
	//# \action		Point3D Project(const Point3D& p, const Line3D& l);
	//#				Returns the projection of the point $p$ onto the line $l$ under the assumption that the line is unitized.
	//
	//# \action		Line3D Antiproject(const Line3D& l, const Point3D& p);
	//#				Returns the antiprojection of the line $l$ onto the point $p$ (where $p$ is always unitized because it has an implicit <i>w</i> coordinate of 1).
	//
	//# \also	$@Vector4D@$
	//# \also	$@Trivector4D@$
	//# \also	$@Motor4D@$


	//# \function	Line3D::Set		Sets all six components of a line.
	//
	//# \proto	Line3D& Set(float vx, float vy, float vz, float mx, float my, float mz);
	//# \proto	Line3D& Set(const Vector3D& direction, const Bivector3D& moment);
	//
	//# \param	vx,vy,vz	The three components of the direction of the line.
	//# \param	mx,my,mz	The three components of the moment of the line.
	//# \param	direction	A 3D vector corresponding to the direction of the line.
	//# \param	moment		A 3D bivector corresponding to the moment of the line.
	//
	//# \desc
	//# The $Set$ function replaces all six components of a line with new values.
	//#
	//# The return value is a reference to the line object.


	//# \function	Line3D::Unitize		Unitizes the weight of a line.
	//
	//# \proto	Line3D& Unitize(void);
	//
	//# \desc
	//# The $Unitize$ function multiplies a line by the inverse magnitude of its weight, which is the
	//# 3D direction component. After calling this function, the direction component has unit length, and the
	//# magnitude of the moment component is the perpendicular distance between the origin and the line.
	//#
	//# The return value is a reference to the line object.


	class Line3D
	{
		public:

			Vector3D		v;
			Bivector3D		m;

			TERATHON_API static const ConstLine3D zero;

			inline Line3D() = default;

			Line3D(float vx, float vy, float vz, float mx, float my, float mz)
			{
				v.Set(vx, vy, vz);
				m.Set(mx, my, mz);
			}

			Line3D(const Vector3D& direction, const Bivector3D& moment)
			{
				v = direction;
				m = moment;
			}

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

			Vector3D GetSupport(void) const
			{
				return (!v ^ m);
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


	inline Line3D Reverse(const Line3D& l)
	{
		return (Line3D(-l.v.x, -l.v.y, -l.v.z, -l.m.x, -l.m.y, -l.m.z));
	}

	inline Line3D Antireverse(const Line3D& l)
	{
		return (Line3D(-l.v.x, -l.v.y, -l.v.z, -l.m.x, -l.m.y, -l.m.z));
	}

	inline Line3D operator ~(const Line3D& l)
	{
		return (Antireverse(l));
	}

	inline Line3D operator -(const Line3D& l)
	{
		return (Line3D(-l.v.x, -l.v.y, -l.v.z, -l.m.x, -l.m.y, -l.m.z));
	}

	inline Line3D operator *(const Line3D& l, float n)
	{
		return (Line3D(l.v.x * n, l.v.y * n, l.v.z * n, l.m.x * n, l.m.y * n, l.m.z * n));
	}

	inline Line3D operator *(float n, const Line3D& l)
	{
		return (Line3D(n * l.v.x, n * l.v.y, n * l.v.z, n * l.m.x, n * l.m.y, n * l.m.z));
	}

	inline Line3D operator /(const Line3D& l, float n)
	{
		n = 1.0F / n;
		return (Line3D(l.v.x * n, l.v.y * n, l.v.z * n, l.m.x * n, l.m.y * n, l.m.z * n));
	}

	inline bool operator ==(const Line3D& k, const Line3D& l)
	{
		return ((k.v == l.v) && (k.m == l.m));
	}

	inline bool operator !=(const Line3D& k, const Line3D& l)
	{
		return ((k.v != l.v) || (k.m != l.m));
	}

	inline Line3D operator ^(const Point3D& p, const Point3D& q)
	{
		return (Line3D(q.x - p.x, q.y - p.y, q.z - p.z, p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x));
	}

	inline Line3D operator ^(const Point3D& p, const Vector3D& v)
	{
		return (Line3D(v.x, v.y, v.z, p.y * v.z - p.z * v.y, p.z * v.x - p.x * v.z, p.x * v.y - p.y * v.x));
	}

	inline float operator ^(const Line3D& k, const Line3D& l)
	{
		return (-(k.v ^ l.m) - (k.m ^ l.v));
	}

	inline float BulkNorm(const Line3D& l)
	{
		return (Magnitude(l.m));
	}

	inline float WeightNorm(const Line3D& l)
	{
		return (Magnitude(l.v));
	}

	inline Line3D Unitize(const Line3D& l)
	{
		return (l * InverseMag(l.v));
	}

	inline Line3D Wedge(const Point3D& p, const Point3D& q)
	{
		return (p ^ q);
	}

	inline Line3D Wedge(const Point3D& p, const Vector3D& v)
	{
		return (p ^ v);
	}

	inline float Antiwedge(const Line3D& k, const Line3D& l)
	{
		return (k ^ l);
	}

	inline Point3D Project(const Point3D& p, const Line3D& l)
	{
		float d = Dot(l.v, p);
		return (Point3D(d * l.v.x + l.v.y * l.m.z - l.v.z * l.m.y, d * l.v.y + l.v.z * l.m.x - l.v.x * l.m.z, d * l.v.z + l.v.x * l.m.y - l.v.y * l.m.x));
	}

	inline Line3D Antiproject(const Line3D& l, const Point3D& p)
	{
		return (p ^ l.v);
	}

	inline Line3D Translate(const Line3D& l, const Vector3D& t)
	{
		return (Line3D(l.v, l.m + (t ^ l.v)));
	}


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


	typedef Line3D Bivector4D;
}


#endif
