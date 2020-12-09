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


#ifndef TSVector3D_h
#define TSVector3D_h


//# \component	Math Library
//# \prefix		Math/


#include "TSVector2D.h"


#define TERATHON_VECTOR3D 1
#define TERATHON_POINT3D 1


namespace Terathon
{
	class Vector3D;
	class Bivector3D;
	struct ConstVector3D;


	//# \class	Vector3D	Encapsulates a 3D vector.
	//
	//# The $Vector3D$ class encapsulates a 3D vector.
	//
	//# \def	class Vector3D : public Vec3D<TypeVector3D>
	//
	//# \ctor	Vector3D();
	//# \ctor	Vector3D(float a, float b, float c);
	//# \ctor	template <typename type> explicit Vector3D(const Vec3D<type>& v);
	//
	//# \param	a	The value of the <i>x</i> coordinate.
	//# \param	b	The value of the <i>y</i> coordinate.
	//# \param	c	The value of the <i>z</i> coordinate.
	//# \param	v	Another 3D vector, possibly with a different component type, that is converted to a $Vector3D$.
	//
	//# \desc
	//# The $Vector3D$ class is used to store a three-dimensional direction vector
	//# having floating-point components <i>x</i>, <i>y</i>, and <i>z</i>. A direction vector
	//# stored in this class is assumed to have a <i>w</i> coordinate of 0 whenever it needs
	//# to be converted to a four-dimensional representation. Three-dimensional points
	//# (for which the <i>w</i> coordinate is 1) should be stored using the $@Point3D@$ class.
	//#
	//# The default constructor leaves the components of the vector undefined.
	//# If the values $a$, $b$, and $c$ are supplied, then they are assigned to the
	//# <i>x</i>, <i>y</i>, and <i>z</i> coordinates of the vector, respectively.
	//
	//# \operator	float& operator [](machine k);
	//#				Returns a reference to the $k$-th scalar component of a vector.
	//#				The value of $k$ must be 0, 1, or 2.
	//
	//# \operator	const float& operator [](machine k) const;
	//#				Returns a constant reference to the $k$-th scalar component of a vector.
	//#				The value of $k$ must be 0, 1, or 2.
	//
	//# \operator	Vector3D& operator +=(const Vector3D& v);
	//#				Adds the vector $v$.
	//
	//# \operator	Vector3D& operator -=(const Vector3D& v);
	//#				Subtracts the vector $v$.
	//
	//# \operator	Vector3D& operator *=(const Vector3D& v);
	//#				Calculates the componentwise product with the vector $v$.
	//
	//# \operator	Vector3D& operator *=(float s);
	//#				Multiplies by the scalar $s$.
	//
	//# \operator	Vector3D& operator /=(float s);
	//#				Divides by the scalar $s$.
	//
	//# \action		bool operator ==(const Vector3D& v1, const Vector3D& v2) const;
	//#				Returns a boolean value indicating whether the two vectors $v1$ and $v2$ are equal.
	//
	//# \action		bool operator !=(const Vector3D& v1, const Vector3D& v2) const;
	//#				Returns a boolean value indicating whether the two vectors $v1$ and $v2$ are not equal.
	//
	//# \action		Vector3D operator -(const Vector3D& v);
	//#				Returns the negation of the vector $v$.
	//
	//# \action		Vector3D operator +(const Vector3D& a, const Vector3D& b);
	//#				Returns the sum of the vectors $a$ and $b$.
	//
	//# \action		Vector3D operator -(const Vector3D& a, const Vector3D& b);
	//#				Returns the difference of the vectors $a$ and $b$.
	//
	//# \action		Vector3D operator *(const Vector3D& v, float s);
	//#				Returns the product of the vector $v$ and the scalar $s$.
	//
	//# \action		Vector3D operator *(float s, const Vector3D& v);
	//#				Returns the product of the vector $v$ and the scalar $s$.
	//
	//# \action		Vector3D operator /(const Vector3D& v, float s);
	//#				Returns the product of the vector $v$ and the inverse of the scalar $s$.
	//
	//# \action		Vector3D operator *(const Vector3D& a, const Vector3D& b);
	//#				Returns the componentwise product of the vectors $a$ and $b$
	//
	//# \action		float Magnitude(const Vector3D& v);
	//#				Returns the magnitude of the vector $v$.
	//
	//# \action		float InverseMag(const Vector3D& v);
	//#				Returns the inverse magnitude of the vector $v$.
	//
	//# \action		float SquaredMag(const Vector3D& v);
	//#				Returns the squared magnitude of the vector $v$.
	//
	//# \action		float Dot(const Vector3D& a, const Vector3D& b);
	//#				Returns the dot product between $a$ and $b$.
	//
	//# \action		Vector3D Cross(const Vector3D& a, const Vector3D& b);
	//#				Returns the cross product between $a$ and $b$.
	//
	//# \action		Vector3D Project(const Vector3D& a, const Vector3D& b);
	//#				Returns (<b>a</b>&#x202F;&sdot;&#x202F;<b>b</b>)<b>b</b>, which is the projection of $a$ onto $b$ under the assumption that the magnitude of $b$ is one.
	//
	//# \action		Vector3D Reject(const Vector3D& a, const Vector3D& b);
	//#				Returns (<b>a</b>&#x202F;&minus;&#x202F;<b>a</b>&#x202F;&sdot;&#x202F;<b>b</b>)<b>b</b>, which is the rejection of $a$ from $b$ under the assumption that the magnitude of $b$ is one.
	//
	//# \privbase	Vec3D	Vectors use a generic base class to store their components.
	//
	//# \also	$@Point3D@$
	//# \also	$@Vector4D@$


	//# \function	Vector3D::Set		Sets all three components of a vector.
	//
	//# \proto	Vector3D& Set(float a, float b, float c);
	//
	//# \param	a	The new <i>x</i> coordinate.
	//# \param	b	The new <i>y</i> coordinate.
	//# \param	c	The new <i>z</i> coordinate.
	//
	//# \desc
	//# The $Set$ function sets the <i>x</i>, <i>y</i>, and <i>z</i> coordinates of a vector to
	//# the values given by the $a$, $b$, and $c$ parameters, respectively.
	//#
	//# The return value is a reference to the vector object.


	//# \function	Vector3D::Normalize		Normalizes a 3D vector.
	//
	//# \proto	Vector3D& Normalize(void);
	//
	//# \desc
	//# The $Normalize$ function multiplies a 3D vector by the inverse of its magnitude,
	//# normalizing it to unit length. Normalizing the zero vector produces undefined results.
	//#
	//# The return value is a reference to the vector object.


	//# \function	Vector3D::GetPoint2D		Returns a reference to a $@Point2D@$ object.
	//
	//# \proto	Point2D& GetPoint2D(void);
	//# \proto	const Point2D& GetPoint2D(void) const;
	//
	//# \desc
	//# The $GetPoint2D$ function returns a reference to a $@Point2D@$ object that refers to
	//# the same data contained in the <i>x</i> and <i>y</i> coordinates of a $Vector3D$ object.


	//# \function	Vector3D::RotateAboutX		Rotates a vector about the <i>x</i> axis.
	//
	//# \proto	Vector3D& RotateAboutX(float angle);
	//
	//# \param	angle	The angle through which the vector is rotated, in radians.
	//
	//# \desc
	//# The $RotateAboutX$ function rotates a vector about the <i>x</i> axis through the
	//# angle given by the $angle$ parameter.
	//#
	//# The return value is a reference to the vector object.
	//
	//# \also	$@Vector3D::RotateAboutY@$
	//# \also	$@Vector3D::RotateAboutZ@$
	//# \also	$@Vector3D::RotateAboutAxis@$


	//# \function	Vector3D::RotateAboutY		Rotates a vector about the <i>y</i> axis.
	//
	//# \proto	Vector3D& RotateAboutY(float angle);
	//
	//# \param	angle	The angle through which the vector is rotated, in radians.
	//
	//# \desc
	//# The $RotateAboutY$ function rotates a vector about the <i>y</i> axis through the
	//# angle given by the $angle$ parameter.
	//#
	//# The return value is a reference to the vector object.
	//
	//# \also	$@Vector3D::RotateAboutX@$
	//# \also	$@Vector3D::RotateAboutZ@$
	//# \also	$@Vector3D::RotateAboutAxis@$


	//# \function	Vector3D::RotateAboutZ		Rotates a vector about the <i>z</i> axis.
	//
	//# \proto	Vector3D& RotateAboutZ(float angle);
	//
	//# \param	angle	The angle through which the vector is rotated, in radians.
	//
	//# \desc
	//# The $RotateAboutZ$ function rotates a vector about the <i>z</i> axis through the
	//# angle given by the $angle$ parameter.
	//#
	//# The return value is a reference to the vector object.
	//
	//# \also	$@Vector3D::RotateAboutX@$
	//# \also	$@Vector3D::RotateAboutY@$
	//# \also	$@Vector3D::RotateAboutAxis@$


	//# \function	Vector3D::RotateAboutAxis		Rotates a vector about a given axis.
	//
	//# \proto	Vector3D& RotateAboutAxis(float angle, const Bivector3D& axis);
	//
	//# \param	angle	The angle through which the vector is rotated, in radians.
	//# \param	axis	The axis about which the vector is rotated.
	//
	//# \desc
	//# The $RotateAboutAxis$ function rotates a vector through the angle given by the
	//# $angle$ parameter about the axis given by the $axis$ parameter.
	//#
	//# The return value is a reference to the vector object.
	//
	//# \also	$@Vector3D::RotateAboutX@$
	//# \also	$@Vector3D::RotateAboutY@$
	//# \also	$@Vector3D::RotateAboutZ@$


	struct TypeVector3D
	{
		typedef float component_type;
		typedef Vector2D vector2D_type;
		typedef Vector3D vector3D_type;
	};


	class Vector3D : public Vec3D<TypeVector3D>
	{
		public:

			inline Vector3D() = default;

			Vector3D(float a, float b, float c) : Vec3D<TypeVector3D>(a, b, c) {}

			template <typename type>
			explicit Vector3D(const Vec3D<type>& v) : Vec3D<TypeVector3D>(float(v.x), float(v.y), float(v.z)) {}

			Vector3D(const Vector2D& v)
			{
				xy = v.xy;
				z = 0.0F;
			}

			Vector3D(const Vector2D& v, float c)
			{
				xy = v.xy;
				z = c;
			}

			Vector3D& Set(float a, float b, float c)
			{
				xyz.Set(a, b, c);
				return (*this);
			}

			void Set(float a, float b, float c) volatile
			{
				xyz.Set(a, b, c);
			}

			Vector3D& Set(const Vector2D& v, float c)
			{
				xyz.Set(v.x, v.y, c);
				return (*this);
			}

			void Set(const Vector2D& v, float c) volatile
			{
				xyz.Set(v.x, v.y, c);
			}

			const Point2D& GetPoint2D(void) const
			{
				return (reinterpret_cast<const Point2D&>(x));
			}

			Vector3D& operator =(const Vector3D& v)
			{
				xyz = v.xyz;
				return (*this);
			}

			void operator =(const Vector3D& v) volatile
			{
				xyz = v.xyz;
			}

			Vector3D& operator =(const Vector2D& v)
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

			template <typename type_struct, int count, int index_x, int index_y, int index_z>
			Vector3D& operator =(const Subvec3D<type_struct, false, count, index_x, index_y, index_z>& v)
			{
				xyz = v;
				return (*this);
			}

			template <typename type_struct, int count, int index_x, int index_y, int index_z>
			void operator =(const Subvec3D<type_struct, false, count, index_x, index_y, index_z>& v) volatile
			{
				xyz = v;
			}

			template <typename type>
			Vector3D& operator =(const Vec3D<type>& v)
			{
				x = float(v.x);
				y = float(v.y);
				z = float(v.z);
				return (*this);
			}

			Vector3D& operator +=(const Vector3D& v)
			{
				xyz += v.xyz;
				return (*this);
			}

			template <typename type_struct, int count, int index_x, int index_y, int index_z>
			Vector3D& operator +=(const Subvec3D<type_struct, false, count, index_x, index_y, index_z>& v)
			{
				xyz += v;
				return (*this);
			}

			Vector3D& operator -=(const Vector3D& v)
			{
				xyz -= v.xyz;
				return (*this);
			}

			template <typename type_struct, int count, int index_x, int index_y, int index_z>
			Vector3D& operator -=(const Subvec3D<type_struct, false, count, index_x, index_y, index_z>& v)
			{
				xyz -= v;
				return (*this);
			}

			Vector3D& operator *=(const Vector3D& v)
			{
				xyz *= v.xyz;
				return (*this);
			}

			template <typename type_struct, int count, int index_x, int index_y, int index_z>
			Vector3D& operator *=(const Subvec3D<type_struct, false, count, index_x, index_y, index_z>& v)
			{
				xyz *= v;
				return (*this);
			}

			Vector3D& operator *=(float s)
			{
				xyz *= s;
				return (*this);
			}

			Vector3D& operator /=(float s)
			{
				xyz /= s;
				return (*this);
			}

			Vector3D& Normalize(void)
			{
				return (static_cast<Vector3D&>(xyz.Normalize()));
			}

			TERATHON_API static const ConstVector3D x_unit;
			TERATHON_API static const ConstVector3D y_unit;
			TERATHON_API static const ConstVector3D z_unit;

			TERATHON_API static const ConstVector3D minus_x_unit;
			TERATHON_API static const ConstVector3D minus_y_unit;
			TERATHON_API static const ConstVector3D minus_z_unit;

			TERATHON_API Vector3D& RotateAboutX(float angle);
			TERATHON_API Vector3D& RotateAboutY(float angle);
			TERATHON_API Vector3D& RotateAboutZ(float angle);
			TERATHON_API Vector3D& RotateAboutAxis(float angle, const Bivector3D& axis);
	};


	inline Vector3D operator -(const Vector3D& v)
	{
		return (Vector3D(-v.x, -v.y, -v.z));
	}

	inline Vector3D operator +(const Vector3D& a, const Vector3D& b)
	{
		return (Vector3D(a.x + b.x, a.y + b.y, a.z + b.z));
	}

	inline Vector3D operator +(const Vector3D& a, const Vector2D& b)
	{
		return (Vector3D(a.x + b.x, a.y + b.y, a.z));
	}

	template <typename type_struct, bool anti, int count, int index_x, int index_y, int index_z>
	inline Vector3D operator +(const Vector3D& a, const Subvec3D<type_struct, anti, count, index_x, index_y, index_z>& b)
	{
		return (Vector3D(a.x + b.data[index_x], a.y + b.data[index_y], a.z + b.data[index_z]));
	}

	inline Vector3D operator -(const Vector3D& a, const Vector3D& b)
	{
		return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
	}

	inline Vector3D operator -(const Vector3D& a, const Vector2D& b)
	{
		return (Vector3D(a.x - b.x, a.y - b.y, a.z));
	}

	template <typename type_struct, bool anti, int count, int index_x, int index_y, int index_z>
	inline Vector3D operator -(const Vector3D& a, const Subvec3D<type_struct, anti, count, index_x, index_y, index_z>& b)
	{
		return (Vector3D(a.x - b.data[index_x], a.y - b.data[index_y], a.z - b.data[index_z]));
	}

	inline Vector3D operator *(const Vector3D& v, float s)
	{
		return (Vector3D(v.x * s, v.y * s, v.z * s));
	}

	inline Vector3D operator *(float s, const Vector3D& v)
	{
		return (Vector3D(s * v.x, s * v.y, s * v.z));
	}

	inline Vector3D operator /(const Vector3D& v, float s)
	{
		s = 1.0F / s;
		return (Vector3D(v.x * s, v.y * s, v.z * s));
	}

	inline Vector3D operator *(const Vector3D& a, const Vector3D& b)
	{
		return (Vector3D(a.x * b.x, a.y * b.y, a.z * b.z));
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z>
	inline float operator ^(const Subvec3D<type_struct, true, count, index_x, index_y, index_z>& a, const Vector3D& b)
	{
		return (a.data[index_x] * b.x + a.data[index_y] * b.y + a.data[index_z] * b.z);
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
	inline float operator ^(const Subvec4D<type_struct, true, count, index_x, index_y, index_z, index_w>& a, const Vector3D& b)
	{
		return (a.data[index_x] * b.x + a.data[index_y] * b.y + a.data[index_z] * b.z);
	}

	inline float Dot(const Vector3D& a, const Vector3D& b)
	{
		return (a.x * b.x + a.y * b.y + a.z * b.z);
	}

	inline Vector3D Cross(const Vector3D& a, const Vector3D& b)
	{
		return (Vector3D(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x));
	}

	inline Vector3D Project(const Vector3D& a, const Vector3D& b)
	{
		return (b * Dot(a, b));
	}

	inline Vector3D Reject(const Vector3D& a, const Vector3D& b)
	{
		return (a - b * Dot(a, b));
	}

	inline float Magnitude(const Vector3D& v)
	{
		return (Sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	}

	inline float InverseMag(const Vector3D& v)
	{
		return (InverseSqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	}

	inline float SquaredMag(const Vector3D& v)
	{
		return (v.x * v.x + v.y * v.y + v.z * v.z);
	}

	inline Vector3D Normalize(const Vector3D& v)
	{
		return (v * InverseSqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	}

	inline Vector3D Floor(const Vector3D& v)
	{
		return (Vector3D(Floor(v.x), Floor(v.y), Floor(v.z)));
	}

	inline Vector3D Ceil(const Vector3D& v)
	{
		return (Vector3D(Ceil(v.x), Ceil(v.y), Ceil(v.z)));
	}


	//# \class	Point3D		Encapsulates a 3D point.
	//
	//# The $Point3D$ class encapsulates a 3D point.
	//
	//# \def	class Point3D : public Vector3D
	//
	//# \ctor	Point3D();
	//# \ctor	Point3D(float a, float b, float c);
	//
	//# \param	a	The value of the <i>x</i> coordinate.
	//# \param	b	The value of the <i>y</i> coordinate.
	//# \param	c	The value of the <i>z</i> coordinate.
	//
	//# \desc
	//# The $Point3D$ class is used to store a three-dimensional point having floating-point
	//# coordinates <i>x</i>, <i>y</i>, and <i>z</i>. The difference between a point and a
	//# vector is that a point is assumed to have a <i>w</i> coordinate of 1 whenever it
	//# needs to be converted to a four-dimensional representation, whereas a vector is
	//# assumed to have a <i>w</i> coordinate of 0. Such a conversion occurs when a vector or
	//# point is assigned to a $@Vector4D@$ object or is multiplied by a $@Transform4D@$ object.
	//#
	//# The default constructor leaves the components of the vector undefined.
	//# If the values $a$, $b$, and $c$ are supplied, then they are assigned to the
	//# <i>x</i>, <i>y</i>, and <i>z</i> coordinates of the base vector object, respectively.
	//#
	//# The difference between two points produces a direction vector. A three-dimensional
	//# direction vector is converted to a point by adding it to the identifier $Zero3D$.
	//
	//# \operator	Point3D& operator *=(float s);
	//#				Multiplies by the scalar $s$.
	//
	//# \operator	Point3D& operator /=(float s);
	//#				Divides by the scalar $s$.
	//
	//# \action		Point3D operator -(const Point3D& p);
	//#				Returns the negation of the point $p$.
	//
	//# \action		Point3D operator +(const Point3D& p1, const Point3D& p2);
	//#				Returns the sum of the points $p1$ and $p2$.
	//
	//# \action		Point3D operator +(const Point3D& p, const Vector3D& v);
	//#				Returns the sum of the point $p$ and the vector $v$.
	//
	//# \action		Vector3D operator -(const Point3D& p1, const Point3D& p2);
	//#				Returns the difference of the points $p1$ and $p2$.
	//
	//# \action		Point3D operator -(const Point3D& p, const Vector3D& v);
	//#				Returns the difference of the point $p$ and the vector $v$.
	//
	//# \action		Point3D operator -(const Vector3D& v, const Point3D& p);
	//#				Returns the difference of the vector $v$ and the point $p$.
	//
	//# \action		Point3D operator *(const Point3D& p, float t);
	//#				Returns the product of the point $p$ and the scalar $t$.
	//
	//# \action		Point3D operator *(float t, const Point3D& p);
	//#				Returns the product of the point $p$ and the scalar $t$.
	//
	//# \action		Point3D operator /(const Point3D& p, float t);
	//#				Returns the product of the point $p$ and the inverse of the scalar $t$.
	//
	//# \action		Point3D operator *(const Point3D& p1, const Point3D& p2);
	//#				Returns the componentwise product of the points $p1$ and $p2$.
	//
	//# \action		Point3D operator *(const Point3D& p, const Vector3D& v);
	//#				Returns the componentwise product of the point $p$ and the vector $v$.
	//
	//# \action		Point3D operator *(const Vector3D& v, const Point3D& p);
	//#				Returns the componentwise product of the vector $v$ and the point $p$.
	//
	//# \base	Vector3D	A $Point3D$ object behaves much like a $@Vector3D@$ object, but some
	//#						properties are altered.
	//
	//# \also	$@Vector3D@$
	//# \also	$@Vector4D@$


	class Point3D : public Vector3D
	{
		public:

			inline Point3D() = default;

			Point3D(float a, float b, float c) : Vector3D(a, b, c) {}
			Point3D(const Vector2D& v) : Vector3D(v) {}
			Point3D(const Vector2D& v, float c) : Vector3D(v, c) {}
			Point3D(const Vector3D& p) : Vector3D(p) {}

			Point2D& GetPoint2D(void)
			{
				return (reinterpret_cast<Point2D&>(x));
			}

			const Point2D& GetPoint2D(void) const
			{
				return (reinterpret_cast<const Point2D&>(x));
			}

			Point3D& operator =(const Vector3D& v)
			{
				xyz = v.xyz;
				return (*this);
			}

			void operator =(const Vector3D& v) volatile
			{
				xyz = v.xyz;
			}

			Point3D& operator =(const Vector2D& v)
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
			Point3D& operator =(const Vec3D<type>& v)
			{
				x = float(v.x);
				y = float(v.y);
				z = float(v.z);
				return (*this);
			}

			Point3D& operator +=(const Vector3D& v)
			{
				xyz += v.xyz;
				return (*this);
			}

			Point3D& operator -=(const Vector3D& v)
			{
				xyz -= v.xyz;
				return (*this);
			}

			Point3D& operator *=(const Vector3D& v)
			{
				xyz *= v.xyz;
				return (*this);
			}

			Point3D& operator *=(float s)
			{
				xyz *= s;
				return (*this);
			}

			Point3D& operator /=(float s)
			{
				xyz /= s;
				return (*this);
			}
	};


	inline Point3D operator -(const Point3D& p)
	{
		return (Point3D(-p.x, -p.y, -p.z));
	}

	inline Point3D operator +(const Point3D& a, const Point3D& b)
	{
		return (Point3D(a.x + b.x, a.y + b.y, a.z + b.z));
	}

	inline Point3D operator +(const Point3D& p, const Vector3D& v)
	{
		return (Point3D(p.x + v.x, p.y + v.y, p.z + v.z));
	}

	inline Point3D operator +(const Vector3D& v, const Point3D& p)
	{
		return (Point3D(v.x + p.x, v.y + p.y, v.z + p.z));
	}

	template <typename type_struct, bool anti, int count, int index_x, int index_y, int index_z>
	inline Point3D operator +(const Point3D& p, const Subvec3D<type_struct, anti, count, index_x, index_y, index_z>& v)
	{
		return (Point3D(p.x + v.data[index_x], p.y + v.data[index_y], p.z + v.data[index_z]));
	}

	inline Vector3D operator -(const Point3D& a, const Point3D& b)
	{
		return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
	}

	inline Point3D operator -(const Point3D& p, const Vector3D& v)
	{
		return (Point3D(p.x - v.x, p.y - v.y, p.z - v.z));
	}

	template <typename type_struct, bool anti, int count, int index_x, int index_y, int index_z>
	inline Point3D operator -(const Point3D& p, const Subvec3D<type_struct, anti, count, index_x, index_y, index_z>& v)
	{
		return (Point3D(p.x - v.data[index_x], p.y - v.data[index_y], p.z - v.data[index_z]));
	}

	inline Point3D operator -(const Vector3D& v, const Point3D& p)
	{
		return (Point3D(v.x - p.x, v.y - p.y, v.z - p.z));
	}

	inline Point3D operator *(const Point3D& p, float s)
	{
		return (Point3D(p.x * s, p.y * s, p.z * s));
	}

	inline Point3D operator *(float s, const Point3D& p)
	{
		return (Point3D(s * p.x, s * p.y, s * p.z));
	}

	inline Point3D operator /(const Point3D& p, float s)
	{
		s = 1.0F / s;
		return (Point3D(p.x * s, p.y * s, p.z * s));
	}

	inline Point3D operator *(const Point3D& a, const Point3D& b)
	{
		return (Point3D(a.x * b.x, a.y * b.y, a.z * b.z));
	}

	inline Point3D operator *(const Point3D& p, const Vector3D& v)
	{
		return (Point3D(p.x * v.x, p.y * v.y, p.z * v.z));
	}

	inline Point3D operator *(const Vector3D& v, const Point3D& p)
	{
		return (Point3D(v.x * p.x, v.y * p.y, v.z * p.z));
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
	inline float operator ^(const Subvec4D<type_struct, true, count, index_x, index_y, index_z, index_w>& a, const Point3D& b)
	{
		return (a.data[index_x] * b.x + a.data[index_y] * b.y + a.data[index_z] * b.z + a.data[index_w]);
	}

	inline float Dot(const Point3D& a, const Point3D& b)
	{
		return (a.x * b.x + a.y * b.y + a.z * b.z);
	}

	inline float Dot(const Point3D& p, const Vector3D& v)
	{
		return (p.x * v.x + p.y * v.y + p.z * v.z);
	}

	inline float Dot(const Vector3D& v, const Point3D& p)
	{
		return (v.x * p.x + v.y * p.y + v.z * p.z);
	}


	#ifndef TERATHON_NO_SIMD

		class alignas(16) SimdVector3D : public Vector3D
		{
			public:

				operator vec_float&(void)
				{
					return (reinterpret_cast<vec_float&>(x));
				}

				operator const vec_float&(void) const
				{
					return (reinterpret_cast<const vec_float&>(x));
				}

				SimdVector3D& operator =(vec_float v)
				{
					reinterpret_cast<vec_float&>(x) = v;
					return (*this);
				}

				using Vector3D::operator =;
		};

		class alignas(16) SimdPoint3D : public Point3D
		{
			public:

				operator vec_float&(void)
				{
					return (reinterpret_cast<vec_float&>(x));
				}

				operator const vec_float&(void) const
				{
					return (reinterpret_cast<const vec_float&>(x));
				}

				SimdPoint3D& operator =(vec_float v)
				{
					reinterpret_cast<vec_float&>(x) = v;
					return (*this);
				}

				using Point3D::operator =;
		};

	#else

		typedef Vector3D SimdVector3D;
		typedef Point3D SimdPoint3D;

	#endif


	struct ConstVector3D
	{
		float	x;
		float	y;
		float	z;

		operator const Vector3D&(void) const
		{
			return (reinterpret_cast<const Vector3D&>(*this));
		}

		const Vector3D *operator &(void) const
		{
			return (reinterpret_cast<const Vector3D *>(this));
		}

		const Vector3D *operator ->(void) const
		{
			return (reinterpret_cast<const Vector3D *>(this));
		}
	};


	struct ConstPoint3D
	{
		float	x;
		float	y;
		float	z;

		operator const Point3D&(void) const
		{
			return (reinterpret_cast<const Point3D&>(*this));
		}

		const Point3D *operator &(void) const
		{
			return (reinterpret_cast<const Point3D *>(this));
		}

		const Point3D *operator ->(void) const
		{
			return (reinterpret_cast<const Point3D *>(this));
		}
	};


	class Zero3DType
	{
		private:

			TERATHON_API static ConstPoint3D zero;

		public:

			operator const Vector3D&(void) const
			{
				return (zero);
			}

			operator const Point3D&(void) const
			{
				return (zero);
			}

			const Point3D *operator &(void) const
			{
				return (&zero);
			}
	};


	inline const Point3D& operator +(const Zero3DType&, const Vector3D& v)
	{
		return (static_cast<const Point3D&>(v));
	}

	template <typename type_struct, bool anti, int count, int index_x, int index_y, int index_z>
	inline Point3D operator +(const Zero3DType&, const Subvec3D<type_struct, anti, count, index_x, index_y, index_z>& v)
	{
		return (Point3D(v.data[index_x], v.data[index_y], v.data[index_z]));
	}

	template <typename type_struct, bool anti, int count>
	inline const Point3D& operator +(const Zero3DType&, const Subvec3D<type_struct, anti, count, 0, 1, 2>& v)
	{
		return (reinterpret_cast<const Point3D&>(v.data[0]));
	}

	template <typename type_struct, bool anti, int count>
	inline const Point3D& operator +(const Zero3DType&, const Subvec3D<type_struct, anti, count, 1, 2, 3>& v)
	{
		return (reinterpret_cast<const Point3D&>(v.data[1]));
	}

	inline Point3D operator -(const Zero3DType&, const Vector3D& v)
	{
		return (Point3D(-v.x, -v.y, -v.z));
	}

	template <typename type_struct, bool anti, int count, int index_x, int index_y, int index_z>
	inline Point3D operator -(const Zero3DType&, const Subvec3D<type_struct, anti, count, index_x, index_y, index_z>& v)
	{
		return (Point3D(-v.data[index_x], -v.data[index_y], -v.data[index_z]));
	}


	TERATHON_API extern const Zero3DType Zero3D;
}


#endif
