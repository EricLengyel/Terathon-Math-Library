//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2022, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSVector4D_h
#define TSVector4D_h


//# \component	Math Library
//# \prefix		Math/


#include "TSVector3D.h"


#define TERATHON_VECTOR4D 1


namespace Terathon
{
	class Vector4D;
	struct ConstVector4D;


	//# \class	Vector4D	Encapsulates a 4D vector.
	//
	//# The $Vector4D$ class encapsulates a 4D vector.
	//
	//# \def	class Vector4D : public Vec4D<TypeVector4D>
	//
	//# \ctor	Vector4D();
	//# \ctor	Vector4D(float a, float b, float c, float d);
	//# \ctor	template <typename type> explicit Vector4D(const Vec4D<type>& v);
	//# \ctor	Vector4D(const Vector3D& v, float d);
	//# \ctor	Vector4D(const Vector3D& v);
	//# \ctor	Vector4D(const Point3D& p);
	//# \ctor	Vector4D(const Vector2D& v);
	//# \ctor	Vector4D(const Point2D& p);
	//
	//# \param	a	The value of the <i>x</i> coordinate.
	//# \param	b	The value of the <i>y</i> coordinate.
	//# \param	c	The value of the <i>z</i> coordinate.
	//# \param	d	The value of the <i>w</i> coordinate.
	//# \param	v	(Template constructor) Another 4D vector, possibly with a different component type, that is converted to a $Vector4D$.
	//# \param	v	A 3D vector whose entries are copied to the <i>x</i>, <i>y</i>, and <i>z</i> coordinates.
	//# \param	p	A 3D point whose entries are copied to the <i>x</i>, <i>y</i>, and <i>z</i> coordinates.
	//
	//# \desc
	//# The $Vector4D$ class is used to store a four-dimensional vector
	//# having floating-point components <i>x</i>, <i>y</i>, <i>z</i>, and <i>w</i>.
	//#
	//# The default constructor leaves the components of the vector undefined.
	//# If the values $a$, $b$, $c$, and $d$ are supplied, then they are assigned to the
	//# <i>x</i>, <i>y</i>, <i>z</i>, and <i>w</i> coordinates of the vector, respectively.
	//# If the $Vector4D$ object is constructed using a $@Vector3D@$ or $@Vector2D@$ object,
	//# then the <i>w</i> coordinate is set to 0. If the $Vector4D$ object is constructed
	//# using a $@Point3D@$ or $@Point2D@$ object, then the <i>w</i> coordinate is set to 1.
	//# The <i>z</i> coordinate of a 2D vector or point is assumed to be 0.
	//
	//# \operator	float& operator [](machine k);
	//#				Returns a reference to the $k$-th scalar component of a vector.
	//#				The value of $k$ must be 0, 1, 2, or 3.
	//
	//# \operator	const float& operator [](machine k) const;
	//#				Returns a constant reference to the $k$-th scalar component of a vector.
	//#				The value of $k$ must be 0, 1, 2, or 3.
	//
	//# \operator	Vector4D& operator =(const Vector3D& v);
	//#				Copies the <i>x</i>, <i>y</i>, and <i>z</i> coordinates of $v$, and assigns
	//#				a value of 0 to the <i>w</i> coordinate.
	//
	//# \operator	Vector4D& operator =(const Point3D& p);
	//#				Copies the <i>x</i>, <i>y</i>, and <i>z</i> coordinates of $p$, and assigns
	//#				a value of 1 to the <i>w</i> coordinate.
	//
	//# \operator	Vector4D& operator =(const Vector2D& v);
	//#				Copies the <i>x</i> and <i>y</i> coordinates of $v$, assigns a value of 0 to
	//#				the <i>z</i> coordinate, and assigns a value of 0 to the <i>w</i> coordinate.
	//
	//# \operator	Vector4D& operator =(const Point2D& p);
	//#				Copies the <i>x</i> and <i>y</i> coordinates of $p$, assigns a value of 0 to
	//#				the <i>z</i> coordinate, and assigns a value of 1 to the <i>w</i> coordinate.
	//
	//# \operator	Vector4D& operator +=(const Vector4D& v);
	//#				Adds the vector $v$.
	//
	//# \operator	Vector4D& operator -=(const Vector4D& v);
	//#				Subtracts the vector $v$.
	//
	//# \operator	Vector4D& operator *=(const Vector4D& v);
	//#				Calculates the componentwise product with the vector $v$.
	//
	//# \operator	Vector4D& operator *=(float s);
	//#				Multiplies by the scalar $s$.
	//
	//# \operator	Vector4D& operator /=(float s);
	//#				Multiplies by the inverse of the scalar $s$.
	//
	//# \action		bool operator ==(const Vector4D& v1, const Vector4D& v2) const;
	//#				Returns a boolean value indicating whether the two vectors $v1$ and $v2$ are equal.
	//
	//# \action		bool operator !=(const Vector4D& v1, const Vector4D& v2) const;
	//#				Returns a boolean value indicating whether the two vectors $v1$ and $v2$ are not equal.
	//
	//# \action		Vector4D operator ~(const Vector4D& v);
	//#				Returns the antireverse of the vector $v$.
	//
	//# \action		Vector4D operator -(const Vector4D& v);
	//#				Returns the negation of the vector $v$.
	//
	//# \action		Vector4D operator +(const Vector4D& a, const Vector4D& b);
	//#				Returns the sum of the vectors $a$ and $b$.
	//
	//# \action		Vector4D operator +(const Vector4D& a, const Vector3D& b);
	//#				Returns the sum of the vectors $a$ and $b$. The <i>w</i> coordinate of $b$ is assumed to be 0.
	//
	//# \action		Vector4D operator +(const Vector3D& a, const Vector4D& b);
	//#				Returns the sum of the vectors $a$ and $b$. The <i>w</i> coordinate of $a$ is assumed to be 0.
	//
	//# \action		Vector4D operator +(const Vector4D& a, const Vector2D& b);
	//#				Returns the sum of the vectors $a$ and $b$. The <i>z</i> and <i>w</i> coordinates of $b$ are assumed to be 0.
	//
	//# \action		Vector4D operator +(const Vector2D& a, const Vector4D& b);
	//#				Returns the sum of the vectors $a$ and $b$. The <i>z</i> and <i>w</i> coordinates of $a$ are assumed to be 0.
	//
	//# \action		Vector4D operator -(const Vector4D& a, const Vector4D& b);
	//#				Returns the difference of the vectors $a$ and $b$.
	//
	//# \action		Vector4D operator -(const Vector4D& a, const Vector3D& b);
	//#				Returns the difference of the vectors $a$ and $b$. The <i>w</i> coordinate of $b$ is assumed to be 0.
	//
	//# \action		Vector4D operator -(const Vector3D& a, const Vector4D& b);
	//#				Returns the difference of the vectors $a$ and $b$. The <i>w</i> coordinate of $a$ is assumed to be 0.
	//
	//# \action		Vector4D operator -(const Vector4D& a, const Vector2D& b);
	//#				Returns the difference of the vectors $a$ and $b$. The <i>z</i> and <i>w</i> coordinates of $b$ are assumed to be 0.
	//
	//# \action		Vector4D operator -(const Vector2D& a, const Vector4D& b);
	//#				Returns the difference of the vectors $a$ and $b$. The <i>z</i> and <i>w</i> coordinates of $a$ are assumed to be 0.
	//
	//# \action		Vector4D operator *(const Vector4D& v, float f);
	//#				Returns the product of the vector $v$ and the scalar $f$.
	//
	//# \action		Vector4D operator *(float f, const Vector4D& v);
	//#				Returns the product of the vector $v$ and the scalar $f$.
	//
	//# \action		Vector4D operator /(const Vector4D& v, float f);
	//#				Returns the product of the vector $v$ and the inverse of the scalar $f$.
	//
	//# \action		Vector4D operator *(const Vector4D& a, const Vector4D& b);
	//#				Returns the componentwise product of the vectors $a$ and $b$.
	//
	//# \action		float BulkNorm(const Vector4D& v);
	//#				Returns the bulk norm of the vector $v$.
	//
	//# \action		float WeightNorm(const Vector4D& v);
	//#				Returns the weight norm of the vector $v$.
	//
	//# \action		Point3D Unitize(const Vector4D& v);
	//#				Returns the 3D point represented by the vector $v$ after unitization.
	//
	//# \action		float Magnitude(const Vector4D& v);
	//#				Returns the magnitude of the vector $v$.
	//
	//# \action		float InverseMag(const Vector4D& v);
	//#				Returns the inverse magnitude of the vector $v$.
	//
	//# \action		float SquaredMag(const Vector4D& v);
	//#				Returns the squared magnitude of the vector $v$.
	//
	//# \action		float Dot(const Vector4D& a, const Vector4D& b);
	//#				Returns the four-dimensional dot product between $a$ and $b$.
	//
	//# \action		float Dot(const Vector4D& a, const Vector3D& b);
	//#				Returns the dot product of the vectors $a$ and $b$. The <i>w</i> coordinate of $b$ is assumed to be 0.
	//
	//# \action		float Dot(const Vector3D& a, const Vector4D& b);
	//#				Returns the dot product of the vectors $a$ and $b$. The <i>w</i> coordinate of $a$ is assumed to be 0.
	//
	//# \action		float Dot(const Vector4D& v, const Point3D& p);
	//#				Returns the dot product of the vector $v$ and the point $p$. The <i>w</i> coordinate of $p$ is assumed to be 1.
	//
	//# \action		float Dot(const Point3D& p, const Vector4D& v);
	//#				Returns the dot product of the point $p$ and the vector $v$. The <i>w</i> coordinate of $p$ is assumed to be 1.
	//
	//# \action		float Dot(const Vector4D& a, const Vector2D& b);
	//#				Returns the dot product with the vector $v$. The <i>z</i> and <i>w</i> coordinates of $b$ are assumed to be 0.
	//
	//# \action		float Dot(const Vector2D& a, const Vector4D& b);
	//#				Returns the dot product of the vectors $a$ and $b$. The <i>z</i> and <i>w</i> coordinates of $a$ is assumed to be 0.
	//
	//# \action		float Dot(const Vector4D& v, const Point2D& p);
	//#				Returns the dot product of the vector $v$ and the point $p$. The <i>z</i> coordinate of $p$ is assumed to be 0, and the <i>w</i> coordinate of $p$ is assumed to be 1.
	//
	//# \action		float Dot(const Point2D& p, const Vector4D& v);
	//#				Returns the dot product of the point $p$ and the vector $v$. The <i>z</i> coordinate of $p$ is assumed to be 0, and the <i>w</i> coordinate of $p$ is assumed to be 1.
	//
	//# \action		Vector4D Project(const Vector4D& a, const Vector4D& b);
	//#				Returns (<b>a</b>&nbsp;&sdot;&nbsp;<b>b</b>)<b>b</b>, which is the projection of $a$ onto $b$ under the assumption that the magnitude of $b$ is one.
	//
	//# \action		Vector3D Reject(const Vector3D& a, const Vector3D& b);
	//#				Returns (<b>a</b>&#x202F;&minus;&#x202F;<b>a</b>&nbsp;&sdot;&nbsp;<b>b</b>)<b>b</b>, which is the rejection of $a$ from $b$ under the assumption that the magnitude of $b$ is one.
	//
	//# \privbase	Vec4D	Vectors use a generic base class to store their components.
	//
	//# \also	$@Trivector4D@$
	//# \also	$@Vector3D@$
	//# \also	$@Point3D@$
	//# \also	$@Vector2D@$
	//# \also	$@Point2D@$


	//# \function	Vector4D::Set		Sets all four components of a vector.
	//
	//# \proto	Vector4D& Set(float a, float b, float c, float d);
	//# \proto	Vector4D& Set(const Vector3D& v, float d);
	//
	//# \param	a	The new <i>x</i> coordinate.
	//# \param	b	The new <i>y</i> coordinate.
	//# \param	c	The new <i>z</i> coordinate.
	//# \param	d	The new <i>w</i> coordinate.
	//# \param	v	A 3D vector whose entries are copied to the <i>x</i>, <i>y</i>, and <i>z</i> coordinates.
	//
	//# \desc
	//# The $Set$ function sets the <i>x</i>, <i>y</i>, <i>z</i>, and <i>w</i> coordinates of a vector to
	//# the values given by the $a$, $b$, $c$, and $d$ parameters, respectively.
	//#
	//# The return value is a reference to the vector object.


	//# \function	Vector4D::Normalize		Normalizes a 4D vector.
	//
	//# \proto	Vector4D& Normalize(void);
	//
	//# \desc
	//# The $Normalize$ function multiplies a 4D vector by the inverse of its magnitude,
	//# normalizing it to unit length. Normalizing the zero vector produces undefined results.
	//#
	//# The return value is a reference to the vector object.


	//# \function	Vector4D::Unitize		Unitizes the weight of a 4D vector.
	//
	//# \proto	Vector4D& Unitize(void);
	//
	//# \desc
	//# The $Unitize$ function multiplies a 4D vector by the inverse of its <i>w</i> coordinate,
	//# transforming it into a homogeneous point having a unit weight. If the <i>w</i> coordinate is
	//# zero, then the resulting <i>x</i>, <i>y</i>, and <i>z</i> coordinates are undefined.
	//# In all cases, the <i>w</i> coordinate is 1.0 when this function returns.
	//#
	//# The return value is a reference to the vector object.


	//# \function	Vector4D::RotateAboutX		Rotates a vector about the <i>x</i> axis.
	//
	//# \proto	Vector4D& RotateAboutX(float angle);
	//
	//# \param	angle	The angle through which the vector is rotated, in radians.
	//
	//# \desc
	//# The $RotateAboutX$ function rotates a vector about the <i>x</i> axis through the
	//# angle given by the $angle$ parameter. The <i>w</i> coordinate is not modified.
	//#
	//# The return value is a reference to the vector object.
	//
	//# \also	$@Vector4D::RotateAboutY@$
	//# \also	$@Vector4D::RotateAboutZ@$
	//# \also	$@Vector4D::RotateAboutAxis@$


	//# \function	Vector4D::RotateAboutY		Rotates a vector about the <i>y</i> axis.
	//
	//# \proto	Vector4D& RotateAboutY(float angle);
	//
	//# \param	angle	The angle through which the vector is rotated, in radians.
	//
	//# \desc
	//# The $RotateAboutY$ function rotates a vector about the <i>y</i> axis through the
	//# angle given by the $angle$ parameter. The <i>w</i> coordinate is not modified.
	//#
	//# The return value is a reference to the vector object.
	//
	//# \also	$@Vector4D::RotateAboutX@$
	//# \also	$@Vector4D::RotateAboutZ@$
	//# \also	$@Vector4D::RotateAboutAxis@$


	//# \function	Vector4D::RotateAboutZ		Rotates a vector about the <i>z</i> axis.
	//
	//# \proto	Vector4D& RotateAboutZ(float angle);
	//
	//# \param	angle	The angle through which the vector is rotated, in radians.
	//
	//# \desc
	//# The $RotateAboutZ$ function rotates a vector about the <i>z</i> axis through the
	//# angle given by the $angle$ parameter. The <i>w</i> coordinate is not modified.
	//#
	//# The return value is a reference to the vector object.
	//
	//# \also	$@Vector4D::RotateAboutX@$
	//# \also	$@Vector4D::RotateAboutY@$
	//# \also	$@Vector4D::RotateAboutAxis@$


	//# \function	Vector4D::RotateAboutAxis		Rotates a vector about a given axis.
	//
	//# \proto	Vector4D& RotateAboutAxis(float angle, const Bivector3D& axis);
	//
	//# \param	angle	The angle through which the vector is rotated, in radians.
	//# \param	axis	The axis about which the vector is rotated.
	//
	//# \desc
	//# The $RotateAboutAxis$ function rotates a vector through the angle given by the
	//# $angle$ parameter about the axis given by the $axis$ parameter. The <i>w</i> coordinate is not modified.
	//#
	//# The return value is a reference to the vector object.
	//
	//# \also	$@Vector4D::RotateAboutX@$
	//# \also	$@Vector4D::RotateAboutY@$
	//# \also	$@Vector4D::RotateAboutZ@$


	struct TypeVector4D
	{
		typedef float component_type;
		typedef Vector2D vector2D_type;
		typedef Vector3D vector3D_type;
		typedef Vector4D vector4D_type;
	};


	class Vector4D : public Vec4D<TypeVector4D>
	{
		public:

			TERATHON_API static const ConstVector4D zero;
			TERATHON_API static const ConstVector4D origin;

			TERATHON_API static const ConstVector4D x_unit;
			TERATHON_API static const ConstVector4D y_unit;
			TERATHON_API static const ConstVector4D z_unit;
			TERATHON_API static const ConstVector4D w_unit;

			TERATHON_API static const ConstVector4D minus_x_unit;
			TERATHON_API static const ConstVector4D minus_y_unit;
			TERATHON_API static const ConstVector4D minus_z_unit;
			TERATHON_API static const ConstVector4D minus_w_unit;

			inline Vector4D() = default;

			Vector4D(float a, float b, float c, float d) : Vec4D<TypeVector4D>(a, b, c, d) {}

			template <typename type>
			explicit Vector4D(const Vec4D<type>& v) : Vec4D<TypeVector4D>(float(v.x), float(v.y), float(v.z), float(v.w)) {}

			Vector4D(const Vector3D& v, float d)
			{
				xyz = v.xyz;
				w = d;
			}

			Vector4D(const Vector2D& v1, const Vector2D& v2)
			{
				xy = v1.xy;
				zw = v2.xy;
			}

			Vector4D(const Vector3D& v)
			{
				xyz = v.xyz;
				w = 0.0F;
			}

			Vector4D(const Point3D& p)
			{
				xyz = p.xyz;
				w = 1.0F;
			}

			Vector4D(const Vector2D& v)
			{
				xy = v.xy;
				z = 0.0F;
				w = 0.0F;
			}

			Vector4D(const Point2D& p)
			{
				xy = p.xy;
				z = 0.0F;
				w = 1.0F;
			}

			Vector4D& Set(float a, float b, float c, float d)
			{
				xyzw.Set(a, b, c, d);
				return (*this);
			}

			void Set(float a, float b, float c, float d) volatile
			{
				xyzw.Set(a, b, c, d);
			}

			Vector4D& Set(const Vector3D& v, float d)
			{
				xyzw.Set(v.x, v.y, v.z, d);
				return (*this);
			}

			void Set(const Vector3D& v, float d) volatile
			{
				xyzw.Set(v.x, v.y, v.z, d);
			}

			Vector4D& Set(const Vector2D& v1, const Vector2D& v2)
			{
				xyzw.Set(v1.x, v1.y, v2.x, v2.y);
				return (*this);
			}

			void Set(const Vector2D& v1, const Vector2D& v2) volatile
			{
				xyzw.Set(v1.x, v1.y, v2.x, v2.y);
			}

			Vector4D& Set(const Vector2D& v, float c, float d)
			{
				xyzw.Set(v.x, v.y, c, d);
				return (*this);
			}

			void Set(const Vector2D& v, float c, float d) volatile
			{
				xyzw.Set(v.x, v.y, c, d);
			}

			Vector4D& operator =(const Vector4D& v)
			{
				xyzw = v.xyzw;
				return (*this);
			}

			void operator =(const Vector4D& v) volatile
			{
				xyzw = v.xyzw;
			}

			Vector4D& operator =(const Vector3D& v)
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

			Vector4D& operator =(const Point3D& p)
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

			Vector4D& operator =(const Vector2D& v)
			{
				xy = v.xy;
				z = 0.0F;
				w = 0.0F;
				return (*this);
			}

			void operator =(const Vector2D& v) volatile
			{
				xy = v.xy;
				z = 0.0F;
				w = 0.0F;
			}

			Vector4D& operator =(const Point2D& p)
			{
				xy = p.xy;
				z = 0.0F;
				w = 1.0F;
				return (*this);
			}

			void operator =(const Point2D& p) volatile
			{
				xy = p.xy;
				z = 0.0F;
				w = 1.0F;
			}

			template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
			Vector4D& operator =(const Subvec4D<type_struct, false, count, index_x, index_y, index_z, index_w>& v)
			{
				xyzw = v;
				return (*this);
			}

			template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
			void operator =(const Subvec4D<type_struct, false, count, index_x, index_y, index_z, index_w>& v) volatile
			{
				xyzw = v;
			}

			template <typename type>
			Vector4D& operator =(const Vec4D<type>& v)
			{
				x = float(v.x);
				y = float(v.y);
				z = float(v.z);
				w = float(v.w);
				return (*this);
			}

			Vector4D& operator +=(const Vector4D& v)
			{
				xyzw += v.xyzw;
				return (*this);
			}

			template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
			Vector4D& operator +=(const Subvec4D<type_struct, false, count, index_x, index_y, index_z, index_w>& v)
			{
				xyzw += v;
				return (*this);
			}

			Vector4D& operator -=(const Vector4D& v)
			{
				xyzw -= v.xyzw;
				return (*this);
			}

			template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
			Vector4D& operator -=(const Subvec4D<type_struct, false, count, index_x, index_y, index_z, index_w>& v)
			{
				xyzw -= v;
				return (*this);
			}

			Vector4D& operator *=(const Vector4D& v)
			{
				xyzw *= v.xyzw;
				return (*this);
			}

			template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
			Vector4D& operator *=(const Subvec4D<type_struct, false, count, index_x, index_y, index_z, index_w>& v)
			{
				xyzw *= v;
				return (*this);
			}

			Vector4D& operator *=(float s)
			{
				xyzw *= s;
				return (*this);
			}

			Vector4D& operator /=(float s)
			{
				xyzw /= s;
				return (*this);
			}

			Vector4D& Normalize(void)
			{
				return (static_cast<Vector4D&>(xyzw.Normalize()));
			}

			Vector4D& Unitize(void)
			{
				xyz /= w;
				w = 1.0F;
				return (*this);
			}

			TERATHON_API Vector4D& RotateAboutX(float angle);
			TERATHON_API Vector4D& RotateAboutY(float angle);
			TERATHON_API Vector4D& RotateAboutZ(float angle);
			TERATHON_API Vector4D& RotateAboutAxis(float angle, const Bivector3D& axis);
	};


	inline Vector4D operator ~(const Vector4D& v)
	{
		return (Vector4D(-v.x, -v.y, -v.z, -v.w));
	}

	inline Vector4D operator -(const Vector4D& v)
	{
		return (Vector4D(-v.x, -v.y, -v.z, -v.w));
	}

	inline Vector4D operator +(const Vector4D& a, const Vector4D& b)
	{
		return (Vector4D(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w));
	}

	inline Vector4D operator +(const Vector4D& a, const Vector3D& b)
	{
		return (Vector4D(a.x + b.x, a.y + b.y, a.z + b.z, a.w));
	}

	inline Vector4D operator +(const Vector3D& a, const Vector4D& b)
	{
		return (Vector4D(a.x + b.x, a.y + b.y, a.z + b.z, b.w));
	}

	inline Vector4D operator +(const Vector4D& a, const Vector2D& b)
	{
		return (Vector4D(a.x + b.x, a.y + b.y, a.z, a.w));
	}

	inline Vector4D operator +(const Vector2D& a, const Vector4D& b)
	{
		return (Vector4D(a.x + b.x, a.y + b.y, b.z, b.w));
	}

	inline Vector4D operator -(const Vector4D& a, const Vector4D& b)
	{
		return (Vector4D(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w));
	}

	inline Vector4D operator -(const Vector4D& a, const Vector3D& b)
	{
		return (Vector4D(a.x - b.x, a.y - b.y, a.z - b.z, a.w));
	}

	inline Vector4D operator -(const Vector3D& a, const Vector4D& b)
	{
		return (Vector4D(a.x - b.x, a.y - b.y, a.z - b.z, -b.w));
	}

	inline Vector4D operator -(const Vector4D& a, const Vector2D& b)
	{
		return (Vector4D(a.x - b.x, a.y - b.y, a.z, a.w));
	}

	inline Vector4D operator -(const Vector2D& a, const Vector4D& b)
	{
		return (Vector4D(a.x - b.x, a.y - b.y, -b.z, -b.w));
	}

	inline Vector4D operator *(const Vector4D& v, float s)
	{
		return (Vector4D(v.x * s, v.y * s, v.z * s, v.w * s));
	}

	inline Vector4D operator *(float s, const Vector4D& v)
	{
		return (Vector4D(s * v.x, s * v.y, s * v.z, s * v.w));
	}

	inline Vector4D operator /(const Vector4D& v, float s)
	{
		s = 1.0F / s;
		return (Vector4D(v.x * s, v.y * s, v.z * s, v.w * s));
	}

	inline Vector4D operator *(const Vector4D& a, const Vector4D& b)
	{
		return (Vector4D(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w));
	}

	inline const Vector4D& Reverse(const Vector4D& v)
	{
		return (v);
	}

	inline Vector4D Antireverse(const Vector4D& v)
	{
		return (~v);
	}

	inline float BulkNorm(const Vector4D& v)
	{
		return (Sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	}

	inline float WeightNorm(const Vector4D& v)
	{
		return (Fabs(v.w));
	}

	inline Point3D Unitize(const Vector4D& v)
	{
		float s = 1.0F / v.w;
		return (Point3D(v.x * s, v.y * s, v.z * s));
	}

	inline float Magnitude(const Vector4D& v)
	{
		return (Sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w));
	}

	inline float InverseMag(const Vector4D& v)
	{
		return (InverseSqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w));
	}

	inline float SquaredMag(const Vector4D& v)
	{
		return (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
	}

	inline Vector4D Normalize(const Vector4D& v)
	{
		return (v * InverseMag(v));
	}

	inline float Dot(const Vector4D& a, const Vector4D& b)
	{
		return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
	}

	inline float Dot(const Vector4D& a, const Vector3D& b)
	{
		return (a.x * b.x + a.y * b.y + a.z * b.z);
	}

	inline float Dot(const Vector3D& a, const Vector4D& b)
	{
		return (a.x * b.x + a.y * b.y + a.z * b.z);
	}

	inline float Dot(const Vector4D& v, const Point3D& p)
	{
		return (v.x * p.x + v.y * p.y + v.z * p.z + v.w);
	}

	inline float Dot(const Point3D& a, const Vector4D& b)
	{
		return (a.x * b.x + a.y * b.y + a.z * b.z + b.w);
	}

	inline float Dot(const Vector4D& a, const Vector2D& b)
	{
		return (a.x * b.x + a.y * b.y);
	}

	inline float Dot(const Vector2D& a, const Vector4D& b)
	{
		return (a.x * b.x + a.y * b.y);
	}

	inline float Dot(const Vector4D& v, const Point2D& p)
	{
		return (v.x * p.x + v.y * p.y + v.w);
	}

	inline float Dot(const Point2D& a, const Vector4D& b)
	{
		return (a.x * b.x + a.y * b.y + b.w);
	}

	inline Vector4D Project(const Vector4D& a, const Vector4D& b)
	{
		return (b * Dot(a, b));
	}

	inline Vector4D Reject(const Vector4D& a, const Vector4D& b)
	{
		return (a - b * Dot(a, b));
	}

	inline Vector4D Floor(const Vector4D& v)
	{
		return (Vector4D(Floor(v.x), Floor(v.y), Floor(v.z), Floor(v.w)));
	}

	inline Vector4D Ceil(const Vector4D& v)
	{
		return (Vector4D(Ceil(v.x), Ceil(v.y), Ceil(v.z), Ceil(v.w)));
	}


	struct ConstVector4D
	{
		float	x;
		float	y;
		float	z;
		float	w;

		operator const Vector4D&(void) const
		{
			return (reinterpret_cast<const Vector4D&>(*this));
		}

		const Vector4D *operator &(void) const
		{
			return (reinterpret_cast<const Vector4D *>(this));
		}

		const Vector4D *operator ->(void) const
		{
			return (reinterpret_cast<const Vector4D *>(this));
		}
	};
}


#endif
