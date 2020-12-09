//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2021, Terathon Software LLC
//
// This software is licensed under the GNU General Public License version 3.
// Separate proprietary licenses are available from Terathon Software.
//
// THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
// EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. 
//


#ifndef TSBivector4D_h
#define TSBivector4D_h


//# \component	Math Library
//# \prefix		Math/


#include "TSTrivector4D.h"


#define TERATHON_BIVECTOR4D 1


namespace Terathon
{
	//# \class	Bivector4D		Encapsulates a 4D bivector.
	//
	//# The $Bivector4D$ class encapsulates a 4D bivector.
	//
	//# \def	class Bivector4D
	//
	//# \ctor	Bivector4D();
	//# \ctor	Bivector4D(float vx, float vy, float vz, float mx, float my, float mz);
	//# \ctor	Bivector4D(const Vector3D& v, const Bivector3D& m);
	//# \ctor	Bivector4D(const Point3D& p, const Point3D& q);
	//# \ctor	Bivector4D(const Point3D& p, const Vector3D& v);
	//# \ctor	Bivector4D(const Trivector4D& f, const Trivector4D& g);
	//
	//# \param	vx,vy,vz	The three components of the direction of the line.
	//# \param	mx,my,mz	The three components of the moment of the line.
	//# \param	v			A 3D vector corresponding to the direction of the line.
	//# \param	m			A 3D bivector corresponding to the moment of the line.
	//# \param	p,q			Two 3D points that lie on the line.
	//# \param	f,g			Two planes that intersect at the line.
	//
	//# \desc
	//# The $Bivector4D$ class is used to store a four-dimensional bivector having six floating-point components.
	//# The components of a 4D bivector are stored as a $@Vector3D@$ member named $direction$ and a $@Bivector3D@$
	//# member named $moment$.
	//#
	//# The default constructor leaves the components of the bivector undefined.
	//#
	//# If points $p$ and $q$ are specified, then the bivector is initialized to the wedge product between homogeneous
	//# extensions of $p$ and $q$ with <i>w</i> coordinates set to 1, giving a representation of the 3D line containing
	//# both points. The direction component of the bivector is assigned the value $q$&#x202F;&minus;&#x202F;$p$, and the
	//# moment component is assigned the value $p$&#x202F;&and;&#x202F;$q$.
	//#
	//# If the point $p$ and the direction $v$ are specified, then the line contains the point $p$ and runs parallel
	//# to the direction $v$. The bivector is initialized to the wedge product between the homogeneous extension of $p$
	//# with <i>w</i> coordinate set to 1 and the homogeneous extension of $v$ with <i>w</i> coordinate set to 0.
	//# The direction component of the bivector is set equal to $v$, and the moment component is assigned the value
	//# $p$&#x202F;&and;&#x202F;$v$.
	//#
	//# If planes $f$ and $g$ are specified, then the bivector is initialized to the antiwedge product between the 4D
	//# trivectors $f$ and $g$, giving a representation of the line where the planes intersect.
	//
	//# \operator	Bivector4D& operator *=(float s);
	//#				Multiplies by the scalar $s$.
	//
	//# \operator	Bivector4D& operator /=(float s);
	//#				Multiplies by the inverse of the scalar $s$.
	//
	//# \action		bool operator ==(const Bivector4D& a, const Bivector4D& b);
	//#				Returns a boolean value indicating whether the two bivectors $a$ and $b$ are equal.
	//
	//# \action		bool operator !=(const Bivector4D& a, const Bivector4D& b);
	//#				Returns a boolean value indicating whether the two bivectors $a$ and $b$ are not equal.
	//
	//# \action		Bivector4D operator -(const Bivector4D& L);
	//#				Returns the negation of the bivector $L$.
	//
	//# \action		Bivector4D operator *(const Bivector4D& L, float s);
	//#				Returns the product of the bivector $L$ and the scalar $s$.
	//
	//# \action		Bivector4D operator *(float s, const Bivector4D& L);
	//#				Returns the product of the bivector $L$ and the scalar $s$.
	//
	//# \action		Bivector4D operator /(const Bivector4D& L, float s);
	//#				Returns the product of the bivector $L$ and the inverse of the scalar $s$.
	//
	//# \action		Bivector4D operator ^(const Point3D& p, const Point3D& q);
	//#				Returns the wedge product of the points $p$ and $q$. The <i>w</i> coordinates of $p$ and $q$ are assumed to be 1.
	//
	//# \action		Bivector4D operator ^(const Trivector4D& f, const Trivector4D& g);
	//#				Returns the antiwedge product of the trivectors $f$ and $g$.
	//#				The result represents the line where the two planes $f$ and $g$ intersect. The direction of the line is equal to the cross product between the normal component of $f$ and the normal component of $g$.
	//
	//# \action		Trivector4D operator ^(const Bivector4D& L, const Point3D& p);
	//#				Returns the wedge product of the bivector $L$ and the point $p$. The <i>w</i> coordinate of $p$ is assumed to be 1.
	//#				The result represents the plane containing the line $L$ and the point $p$, wound from the direction component of $L$ toward the direction to $p$ perpendicular to the line $L$.
	//
	//# \action		Trivector4D operator ^(const Point3D& p, const Bivector4D& L);
	//#				Returns the wedge product of the point $p$ and the bivector $L$, which is the same as $L$&#x202F;&#x2227;&#x202F;$p$. The <i>w</i> coordinate of $p$ is assumed to be 1.
	//
	//# \action		Trivector4D operator ^(const Bivector4D& L, const Vector3D& v);
	//#				Returns the wedge product of the bivector $L$ and the direction $v$. The <i>w</i> coordinate of $v$ is assumed to be 0.
	//#				The result represents the plane containing the line $L$ and the direction $v$, wound from the direction component of $L$ toward the direction $v$.
	//
	//# \action		Trivector4D operator ^(const Vector3D& v, const Bivector4D& L);
	//#				Returns the wedge product of the direction $v$ and the bivector $L$, which is the same as $L$&#x202F;&#x2227;&#x202F;$v$. The <i>w</i> coordinate of $v$ is assumed to be 0.
	//
	//# \action		Vector4D operator ^(const Bivector4D& L, const Trivector4D& f);
	//#				Returns the antiwedge product of the bivector $L$ and the plane $f$.
	//#				The result represents the homogeneous point where the line and plane intersect. The <i>x</i>, <i>y</i>, and <i>z</i> must be divided by the <i>w</i> coordinate to produce a 3D point.
	//
	//# \action		Vector4D operator ^(const Trivector4D& f, const Bivector4D& L);
	//#				Returns the antiwedge product of the plane $f$ and the bivector $L$, which is the same as $L$&#x202F;&#x2228;&#x202F;$f$.
	//
	//# \action		float operator ^(const Bivector4D& K, const Bivector4D& L);
	//#				Returns the antiwedge product of the bivectors $K$ and $L$.
	//#				This gives the crossing relationship between the two lines, with positive values representing clockwise crossings and negative values representing counterclockwise crossings.
	//
	//# \action		Point3D Project(const Point3D& p, const Bivector4D& L);
	//#				Returns the projection of the point $p$ onto the line $L$ under the assumption that the line is unitized.
	//
	//# \action		Bivector4D Project(const Bivector4D& L, const Trivector4D& f);
	//#				Returns the projection of the line $L$ onto the plane $f$ under the assumption that the plane is unitized.
	//
	//# \action		Bivector4D Antiproject(const Bivector4D& L, const Point3D& p);
	//#				Returns the antiprojection of the line $L$ onto the point $p$ (where $p$ is always unitized because it has an implicit <i>w</i> coordinate of 1).
	//
	//# \action		Trivector4D Antiproject(const Trivector4D& f, const Bivector4D& L);
	//#				Returns the antiprojection of the plane $f$ onto the line $L$ under the assumption that the line is unitized.
	//
	//# \also	$@Vector4D@$
	//# \also	$@Trivector4D@$
	//# \also	$@Motor@$


	//# \function	Bivector4D::Set		Sets all six components of a bivector.
	//
	//# \proto	Bivector4D& Set(float vx, float vy, float vz, float mx, float my, float mz);
	//# \proto	Bivector4D& Set(const Vector3D& v, const Bivector3D& m);
	//# \proto	Bivector4D& Set(const Point3D& p, const Point3D& q);
	//# \proto	Bivector4D& Set(const Point3D& p, const Vector3D& v);
	//# \proto	Bivector4D& Set(const Trivector4D& f, const Trivector4D& g);
	//
	//# \param	vx,vy,vz	The three components of the direction of the line.
	//# \param	mx,my,mz	The three components of the moment of the line.
	//# \param	v			A 3D vector corresponding to the direction of the line.
	//# \param	m			A 3D bivector corresponding to the moment of the line.
	//# \param	p,q			Two 3D points that lie on the line.
	//# \param	f,g			Two planes that intersect at the line.
	//
	//# \desc
	//# The $Set$ function replaces all six components of a bivector with new values.
	//#
	//# If points $p$ and $q$ are specified, then the bivector is initialized to the wedge product between homogeneous
	//# extensions of $p$ and $q$ with <i>w</i> coordinates set to 1, giving a representation of the 3D line containing
	//# both points. The direction component of the bivector is assigned the value $q$&#x202F;&minus;&#x202F;$p$, and the
	//# moment component is assigned the value $p$&#x202F;&and;&#x202F;$q$.
	//#
	//# If the point $p$ and the direction $v$ are specified, then the line contains the point $p$ and runs parallel
	//# to the direction $v$. The bivector is initialized to the wedge product between the homogeneous extension of $p$
	//# with <i>w</i> coordinate set to 1 and the homogeneous extension of $v$ with <i>w</i> coordinate set to 0.
	//# The direction component of the bivector is set equal to $v$, and the moment component is assigned the value
	//# $p$&#x202F;&and;&#x202F;$v$.
	//#
	//# If planes $f$ and $g$ are specified, then the bivector is initialized to the antiwedge product between the 4D
	//# trivectors $f$ and $g$, giving a representation of the line where the planes intersect.
	//#
	//# The return value is a reference to the bivector object.


	//# \function	Bivector4D::Unitize		Unitizes the weight of a 4D bivector.
	//
	//# \proto	Bivector4D& Unitize(void);
	//
	//# \desc
	//# The $Unitize$ function multiplies a 4D bivector by the inverse magnitude of its weight, which is the
	//# 3D direction component. After calling this function, the direction component has unit length, and the
	//# magnitude of the moment component is the perpendicular distance between the origin and the line.
	//#
	//# The return value is a reference to the bivector object.


	class Bivector4D
	{
		public:

			Vector3D		direction;
			Bivector3D		moment;

			inline Bivector4D() = default;

			Bivector4D(float vx, float vy, float vz, float mx, float my, float mz)
			{
				direction.Set(vx, vy, vz);
				moment.Set(mx, my, mz);
			}

			Bivector4D(const Vector3D& v, const Bivector3D& m)
			{
				direction = v;
				moment = m;
			}

			Bivector4D(const Point3D& p, const Point3D& q)
			{
				direction.Set(q.x - p.x, q.y - p.y, q.z - p.z);
				moment.Set(p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x);
			}

			Bivector4D(const Point3D& p, const Vector3D& v)
			{
				direction = v;
				moment.Set(p.y * v.z - p.z * v.y, p.z * v.x - p.x * v.z, p.x * v.y - p.y * v.x);
			}

			Bivector4D(const Trivector4D& f, const Trivector4D& g)
			{
				direction.Set(f.y * g.z - f.z * g.y, f.z * g.x - f.x * g.z, f.x * g.y - f.y * g.x);
				moment.Set(f.w * g.x - f.x * g.w, f.w * g.y - f.y * g.w, f.w * g.z - f.z * g.w);
			}

			Bivector4D& Set(float vx, float vy, float vz, float mx, float my, float mz)
			{
				direction.Set(vx, vy, vz);
				moment.Set(mx, my, mz);
				return (*this);
			}

			void Set(float vx, float vy, float vz, float mx, float my, float mz) volatile
			{
				direction.Set(vx, vy, vz);
				moment.Set(mx, my, mz);
			}

			Bivector4D& Set(const Vector3D& v, const Bivector3D& m)
			{
				direction = v;
				moment = m;
				return (*this);
			}

			void Set(const Vector3D& v, const Bivector3D& m) volatile
			{
				direction = v;
				moment = m;
			}

			Bivector4D& Set(const Point3D& p, const Point3D& q)
			{
				direction.Set(q.x - p.x, q.y - p.y, q.z - p.z);
				moment.Set(p.y * q.z - q.y * p.z, p.z * q.x - q.z * p.x, p.x * q.y - q.x * p.y);
				return (*this);
			}

			void Set(const Point3D& p, const Point3D& q) volatile
			{
				direction.Set(q.x - p.x, q.y - p.y, q.z - p.z);
				moment.Set(p.y * q.z - q.y * p.z, p.z * q.x - q.z * p.x, p.x * q.y - q.x * p.y);
			}

			Bivector4D& Set(const Point3D& p, const Vector3D& v)
			{
				direction = v;
				moment.Set(p.y * v.z - v.y * p.z, p.z * v.x - v.z * p.x, p.x * v.y - v.x * p.y);
				return (*this);
			}

			void Set(const Point3D& p, const Vector3D& v) volatile
			{
				direction = v;
				moment.Set(p.y * v.z - v.y * p.z, p.z * v.x - v.z * p.x, p.x * v.y - v.x * p.y);
			}

			Bivector4D& Set(const Trivector4D& f, const Trivector4D& g)
			{
				direction.Set(f.y * g.z - f.z * g.y, f.z * g.x - f.x * g.z, f.x * g.y - f.y * g.x);
				moment.Set(f.w * g.x - f.x * g.w, f.w * g.y - f.y * g.w, f.w * g.z - f.z * g.w);
				return (*this);
			}

			void Set(const Trivector4D& f, const Trivector4D& g) volatile
			{
				direction.Set(f.y * g.z - f.z * g.y, f.z * g.x - f.x * g.z, f.x * g.y - f.y * g.x);
				moment.Set(f.w * g.x - f.x * g.w, f.w * g.y - f.y * g.w, f.w * g.z - f.z * g.w);
			}

			const Vector3D GetSupport(void) const
			{
				return (!direction ^ moment);
			}

			Bivector4D& operator =(const Bivector4D& L)
			{
				direction = L.direction;
				moment = L.moment;
				return (*this);
			}

			void operator =(const Bivector4D& L) volatile
			{
				direction = L.direction;
				moment = L.moment;
			}

			Bivector4D& operator *=(float s)
			{
				direction *= s;
				moment *= s;
				return (*this);
			}

			Bivector4D& operator /=(float s)
			{
				s = 1.0F / s;
				direction *= s;
				moment *= s;
				return (*this);
			}

			Bivector4D& Unitize(void)
			{
				return (*this *= InverseMag(direction));
			}
	};


	inline Bivector4D operator -(const Bivector4D& L)
	{
		return (Bivector4D(-L.direction.x, -L.direction.y, -L.direction.z, -L.moment.x, -L.moment.y, -L.moment.z));
	}

	inline Bivector4D operator *(const Bivector4D& L, float s)
	{
		return (Bivector4D(L.direction.x * s, L.direction.y * s, L.direction.z * s, L.moment.x * s, L.moment.y * s, L.moment.z * s));
	}

	inline Bivector4D operator *(float s, const Bivector4D& L)
	{
		return (Bivector4D(s * L.direction.x, s * L.direction.y, s * L.direction.z, s * L.moment.x, s * L.moment.y, s * L.moment.z));
	}

	inline Bivector4D operator /(const Bivector4D& L, float s)
	{
		s = 1.0F / s;
		return (Bivector4D(L.direction.x * s, L.direction.y * s, L.direction.z * s, L.moment.x * s, L.moment.y * s, L.moment.z * s));
	}

	inline bool operator ==(const Bivector4D& a, const Bivector4D& b)
	{
		return ((a.direction == b.direction) && (a.moment == b.moment));
	}

	inline bool operator !=(const Bivector4D& a, const Bivector4D& b)
	{
		return ((a.direction != b.direction) || (a.moment != b.moment));
	}

	inline Bivector4D operator ^(const Point3D& p, const Point3D& q)
	{
		return (Bivector4D(q.x - p.x, q.y - p.y, q.z - p.z, p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x));
	}

	inline Bivector4D operator ^(const Point3D& p, const Vector3D& v)
	{
		return (Bivector4D(v.x, v.y, v.z, p.y * v.z - p.z * v.y, p.z * v.x - p.x * v.z, p.x * v.y - p.y * v.x));
	}

	inline Bivector4D operator ^(const Trivector4D& f, const Trivector4D& g)
	{
		return (Bivector4D(f.z * g.y - f.y * g.z, f.x * g.z - f.z * g.x, f.y * g.x - f.x * g.y, f.x * g.w - f.w * g.x, f.y * g.w - f.w * g.y, f.z * g.w - f.w * g.z));
	}

	inline Trivector4D operator ^(const Bivector4D& L, const Point3D& p)
	{
		return (Trivector4D(L.direction.y * p.z - L.direction.z * p.y + L.moment.x,
							L.direction.z * p.x - L.direction.x * p.z + L.moment.y,
							L.direction.x * p.y - L.direction.y * p.x + L.moment.z,
						   -L.moment.x * p.x - L.moment.y * p.y - L.moment.z * p.z));
	}

	inline Trivector4D operator ^(const Point3D& p, const Bivector4D& L)
	{
		return (L ^ p);
	}

	inline Trivector4D operator ^(const Bivector4D& L, const Vector3D& v)
	{
		return (Trivector4D(L.direction.y * v.z - L.direction.z * v.y,
							L.direction.z * v.x - L.direction.x * v.z,
							L.direction.x * v.y - L.direction.y * v.x,
						   -L.moment.x * v.x - L.moment.y * v.y - L.moment.z * v.z));
	}

	inline Trivector4D operator ^(const Vector3D& v, const Bivector4D& L)
	{
		return (L ^ v);
	}

	inline Vector4D operator ^(const Bivector4D& L, const Trivector4D& f)
	{
		return (Vector4D(L.moment.y * f.z - L.moment.z * f.y + L.direction.x * f.w,
						 L.moment.z * f.x - L.moment.x * f.z + L.direction.y * f.w,
						 L.moment.x * f.y - L.moment.y * f.x + L.direction.z * f.w,
						-L.direction.x * f.x - L.direction.y * f.y - L.direction.z * f.z));
	}

	inline Vector4D operator ^(const Trivector4D& f, const Bivector4D& L)
	{
		return (L ^ f);
	}

	inline float operator ^(const Bivector4D& K, const Bivector4D& L)
	{
		return (-(K.direction ^ L.moment) - (K.moment ^ L.direction));
	}

	inline Bivector4D Wedge(const Point3D& p, const Point3D& q)
	{
		return (p ^ q);
	}

	inline Bivector4D Wedge(const Point3D& p, const Vector3D& v)
	{
		return (p ^ v);
	}

	inline Bivector4D Antiwedge(const Trivector4D& f, const Trivector4D& g)
	{
		return (f ^ g);
	}

	inline Trivector4D Wedge(const Bivector4D& L, const Point3D& p)
	{
		return (L ^ p);
	}

	inline Trivector4D Wedge(const Point3D& p, const Bivector4D& L)
	{
		return (L ^ p);
	}

	inline Trivector4D Wedge(const Bivector4D& L, const Vector3D& v)
	{
		return (L ^ v);
	}

	inline Trivector4D Wedge(const Vector3D& v, const Bivector4D& L)
	{
		return (L ^ v);
	}

	inline Vector4D Antiwedge(const Bivector4D& L, const Trivector4D& f)
	{
		return (L ^ f);
	}

	inline Vector4D Antiwedge(const Trivector4D& f, const Bivector4D& L)
	{
		return (L ^ f);
	}

	inline float Antiwedge(const Bivector4D& K, const Bivector4D& L)
	{
		return (K ^ L);
	}

	inline Point3D Project(const Point3D& p, const Bivector4D& L)
	{
		float d = Dot(L.direction, p);
		return (Point3D(d * L.direction.x + L.direction.y * L.moment.z - L.direction.z * L.moment.y, d * L.direction.y + L.direction.z * L.moment.x - L.direction.x * L.moment.z, d * L.direction.z + L.direction.x * L.moment.y - L.direction.y * L.moment.x));
	}

	inline Bivector4D Project(const Bivector4D& L, const Trivector4D& f)
	{
		return (Bivector4D(L.direction - !f.xyz * (f.xyz ^ L.direction), f.xyz * (!f.xyz ^ L.moment) - (!f.xyz ^ L.direction) * f.w));
	}

	inline Bivector4D Antiproject(const Bivector4D& L, const Point3D& p)
	{
		return (Bivector4D(p, L.direction));
	}

	inline Trivector4D Antiproject(const Trivector4D& f, const Bivector4D& L)
	{
		return (Trivector4D(f.xyz - !L.direction * (f.xyz ^ L.direction), L.moment ^ !L.direction ^ f.xyz));
	}

	inline Bivector4D Translate(const Bivector4D& L, const Vector3D& t)
	{
		return (Bivector4D(L.direction, L.moment + (t ^ L.direction)));
	}
}


#endif
