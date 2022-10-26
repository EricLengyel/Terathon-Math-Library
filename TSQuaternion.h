//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2022, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSQuaternion_h
#define TSQuaternion_h


//# \component	Math Library
//# \prefix		Math/


#include "TSMatrix4D.h"


#define TERATHON_QUATERNION 1


namespace Terathon
{
	struct ConstQuaternion;


	//# \class	Quaternion		Encapsulates a quaternion.
	//
	//# The $Quaternion$ class encapsulates a quaternion.
	//
	//# \def	class Quaternion
	//
	//# \data	Quaternion
	//
	//# \ctor	Quaternion();
	//# \ctor	Quaternion(float a, float b, float c, float s);
	//# \ctor	Quaternion(const Vector3D& v, float s);
	//# \ctor	explicit Quaternion(const Vector3D& v);
	//# \ctor	explicit Quaternion(float s);
	//
	//# \desc
	//# The $Quaternion$ class encapsulates a Hamiltonian quaternion having the form
	//# <i>xi</i>&#x202F;+&#x202F;<i>yj</i>&#x202F;+&#x202F;<i>zk</i>&#x202F;+&#x202F;<i>w</i>.
	//#
	//# The default constructor leaves the components of the quaternion undefined.
	//# If the values $a$, $b$, $c$, and $s$ are supplied, then they are assigned to the
	//# <i>x</i>, <i>y</i>, <i>z</i>, and <i>w</i> coordinates of the quaternion, respectively.
	//# The components of $v$ are assigned to the imaginary components <i>x</i>, <i>y</i>, and
	//# <i>z</i> of the quaternion, and the scalar $s$ is assigned to the real component <i>w</i>.
	//# If a quaternion is constructed with only the $@Vector3D@$ object $v$, then the real
	//# coordinate <i>w</i> is set to 0. If a quaternion is constructed with only the scalar $s$,
	//# then the imaginary components <i>x</i>, <i>y</i>, and <i>z</i> are set to 0.
	//#
	//# When performing arithmetic with quaternions, 3D vectors are always treated as quaternions
	//# with <i>w</i>&#x202F;=&#x202F;0, and scalars are always treated as quaternions with
	//# <i>x</i>,<i>y</i>,<i>z</i>&#x202F;=&#x202F;0.
	//
	//# \operator	Quaternion& operator =(const Vector3D& v);
	//#				Assigns the of $v$ to the imaginary components <i>x</i>, <i>y</i>,
	//#				and <i>z</i> of the quaternion. The real component <i>w</i> is set to 0.
	//
	//# \operator	Quaternion& operator =(float s);
	//#				Sets the real component <i>w</i> of the quaternion to $s$, and sets the
	//#				imaginary components <i>x</i>, <i>y</i>, and <i>z</i> to 0.
	//
	//# \operator	Quaternion& operator +=(const Quaternion& q);
	//#				Adds the quaternion $q$.
	//
	//# \operator	Quaternion& operator +=(const Vector3D& v);
	//#				Adds the vector $v$.
	//
	//# \operator	Quaternion& operator +=(float s);
	//#				Adds the scalar $s$.
	//
	//# \operator	Quaternion& operator -=(const Quaternion& q);
	//#				Subtracts the quaternion $q$.
	//
	//# \operator	Quaternion& operator -=(const Vector3D& v);
	//#				Subtracts the vector $v$.
	//
	//# \operator	Quaternion& operator -=(float s);
	//#				Subtracts the scalar $s$.
	//
	//# \operator	Quaternion& operator *=(const Quaternion& q);
	//#				Multiplies by the quaternion $q$.
	//
	//# \operator	Quaternion& operator *=(const Vector3D& v);
	//#				Multiplies by the vector $v$.
	//
	//# \operator	Quaternion& operator *=(float s);
	//#				Multiplies by the scalar $s$.
	//
	//# \operator	Quaternion& operator /=(const Quaternion& q);
	//#				Multiplies by the inverse of the quaternion $q$.
	//
	//# \operator	Quaternion& operator /=(const Vector3D& v);
	//#				Multiplies by the inverse of the vector $v$.
	//
	//# \operator	Quaternion& operator /=(float s);
	//#				Multiplies by the inverse of the scalar $s$.
	//
	//# \action		bool operator ==(const Quaternion& q1, const Quaternion& q2);
	//#				Returns a boolean value indicating whether the two quaternions $q1$ and $q2$ are equal.
	//
	//# \action		bool operator ==(const Quaternion& q, const Vector3D& v);
	//#				Returns a boolean value indicating whether the quaternion $q$ and the vector $v$ are equal.
	//
	//# \action		bool operator ==(const Vector3D& v, const Quaternion& q);
	//#				Returns a boolean value indicating whether the vector $v$ and the quaternion $q$ are equal.
	//
	//# \action		bool operator ==(const Quaternion& q, float s);
	//#				Returns a boolean value indicating whether the quaternion $q$ and the scalar $s$ are equal.
	//
	//# \action		bool operator ==(float s, const Quaternion& q);
	//#				Returns a boolean value indicating whether the scalar $a$ and the quaternion $q$ are equal.
	//
	//# \action		bool operator !=(const Quaternion& q1, const Quaternion& q2);
	//#				Returns a boolean value indicating whether the two quaternions $q1$ and $q2$ are not equal.
	//
	//# \action		bool operator !=(const Quaternion& q, const Vector3D& v);
	//#				Returns a boolean value indicating whether the quaternion $q$ and the vector $v$ are not equal.
	//
	//# \action		bool operator !=(const Vector3D& v, const Quaternion& q);
	//#				Returns a boolean value indicating whether the vector $v$ and the quaternion $q$ are not equal.
	//
	//# \action		bool operator !=(const Quaternion& q, float s);
	//#				Returns a boolean value indicating whether the quaternion $q$ and the scalar $s$ are not equal.
	//
	//# \action		bool operator !=(float s, const Quaternion& q);
	//#				Returns a boolean value indicating whether the scalar $s$ and the quaternion $q$ are not equal.
	//
	//# \action		Quaternion operator -(const Quaternion& q);
	//#				Returns the negation of the quaternion $q$.
	//
	//# \action		Quaternion operator +(const Quaternion& q1, const Quaternion& q2);
	//#				Returns the sum of the quaternions $q1$ and $q2$.
	//
	//# \action		Quaternion operator +(const Quaternion& q, const Vector3D& v);
	//#				Returns the sum of the quaternion $q$ and the vector $v$.
	//
	//# \action		Quaternion operator +(const Vector3D& v, const Quaternion& q);
	//#				Returns the sum of the vector $v$ and the quaternion $q$.
	//
	//# \action		Quaternion operator +(const Quaternion& q, float s);
	//#				Returns the sum of the quaternion $q$ and the scalar $s$.
	//
	//# \action		Quaternion operator +(float s, const Quaternion& q);
	//#				Returns the sum of the scalar $s$ and the quaternion $q$.
	//
	//# \action		Quaternion operator -(const Quaternion& q1, const Quaternion& q2);
	//#				Returns the difference of the quaternions $q1$ and $q2$.
	//
	//# \action		Quaternion operator -(const Quaternion& q, const Vector3D& v);
	//#				Returns the difference of the quaternion $q$ and the vector $v$.
	//
	//# \action		Quaternion operator -(const Vector3D& v, const Quaternion& q);
	//#				Returns the difference of the vector $v$ and the quaternion $q$.
	//
	//# \action		Quaternion operator -(const Quaternion& q, float s);
	//#				Returns the difference of the quaternion $q$ and the scalar $s$.
	//
	//# \action		Quaternion operator -(float s, const Quaternion& q);
	//#				Returns the difference of the scalar $s$ and the quaternion $q$.
	//
	//# \action		Quaternion operator *(const Quaternion& q1, const Quaternion& q2);
	//#				Returns the product of the quaternions $q1$ and $q2$.
	//
	//# \action		Quaternion operator *(const Quaternion& q, const Vector3D& v);
	//#				Returns the product of the quaternion $q$ and the vector $v$.
	//
	//# \action		Quaternion operator *(const Vector3D& v, const Quaternion& q);
	//#				Returns the product of the vector $v$ and the quaternion $q$.
	//
	//# \action		Quaternion operator *(const Quaternion& q, float s);
	//#				Returns the product of the quaternion $q$ and the scalar $s$.
	//
	//# \action		Quaternion operator *(float s, const Quaternion& q);
	//#				Returns the product of the scalar $s$ and the quaternion $q$.
	//
	//# \action		Quaternion operator /(const Quaternion& q1, const Quaternion& q2);
	//#				Returns the quotient of the quaternions $q1$ and $q2$.
	//
	//# \action		Quaternion operator /(const Quaternion& q, const Vector3D& v);
	//#				Returns the quotient of the quaternion $q$ and of the vector $v$.
	//
	//# \action		Quaternion operator /(const Vector3D& v, const Quaternion& q);
	//#				Returns the quotient of the vector $v$ and the quaternion $q$.
	//
	//# \action		Quaternion operator /(const Quaternion& q, float s);
	//#				Returns the quotient of the quaternion $q$ and the scalar $s$.
	//
	//# \action		Quaternion operator /(float s, const Quaternion& q);
	//#				Returns the quotient of the scalar $s$ and the quaternion $q$.
	//
	//# \action		float Magnitude(const Quaternion& q);
	//#				Returns the magnitude of a quaternion.
	//
	//# \action		float SquaredMag(const Quaternion& q);
	//#				Returns the squared magnitude of a quaternion.
	//
	//# \action		Quaternion Reverse(const Quaternion& q);
	//#				Returns the reverse of a quaternion.
	//
	//# \action		Quaternion Inverse(const Quaternion& q);
	//#				Returns the inverse of a quaternion.
	//
	//# \action		Vector3D Transform(const Vector3D& v, const Quaternion& q);
	//#				Transforms the vector $v$ with the quaternion $q$.
	//
	//# \also	$@Vector3D@$
	//# \also	$@Matrix3D@$
	//# \also	$@Motor4D@$


	//# \function	Quaternion::Set		Sets all four components of a quaternion.
	//
	//# \proto	Quaternion& Set(float a, float b, float c, float s);
	//# \proto	Quaternion& Set(const Vector3D& v, float s);
	//
	//# \param	a	The new <i>x</i> coordinate.
	//# \param	b	The new <i>y</i> coordinate.
	//# \param	c	The new <i>z</i> coordinate.
	//# \param	s	The new <i>w</i> coordinate.
	//# \param	v	The new <i>x</i>, <i>y</i>, and <i>z</i> coordinates.
	//
	//# \desc
	//# The $Set$ function sets the <i>x</i>, <i>y</i>, <i>z</i>, and <i>w</i> coordinates of
	//# a quaternion to the values given by the $a$, $b$, $c$, and $s$ parameters, respectively.
	//# If the parameters $v$ and $s$ are supplied, then the <i>x</i>, <i>y</i>, and <i>z</i>
	//# coordinates are set to those of the vector $v$, and the <i>w</i> coordinate is set to
	//# the value given by $s$.
	//#
	//# The return value is a reference to the quaternion object.


	//# \function	Quaternion::Normalize		Normalizes a quaternion.
	//
	//# \proto	Quatnerion& Normalize(void);
	//
	//# \desc
	//# The $Normalize$ function multiplies a quaternion by the inverse of its magnitude,
	//# normalizing it to unit length. Normalizing the zero quaternion produces undefined results.
	//#
	//# The return value is a reference to the quaternion object.


	//# \function	Quaternion::MakeRotationX		Returns a quaternion that represents a rotation about the <i>x</i> axis.
	//
	//# \proto	static Quaternion MakeRotationX(float angle);
	//
	//# \param	angle	The angle of rotation, in radians.
	//
	//# \desc
	//# The $MakeRotationX$ function returns a quaternion representing the rotation through the angle given
	//# by the $angle$ parameter about the <i>x</i> axis. The resulting quaternion has unit length.
	//
	//# \also	$@Quaternion::MakeRotationY@$
	//# \also	$@Quaternion::MakeRotationZ@$
	//# \also	$@Quaternion::MakeRotation@$
	//# \also	$@Quaternion::GetRotationMatrix@$


	//# \function	Quaternion::MakeRotationY		Returns a quaternion that represents a rotation about the <i>y</i> axis.
	//
	//# \proto	static Quaternion MakeRotationY(float angle);
	//
	//# \param	angle	The angle of rotation, in radians.
	//
	//# \desc
	//# The $MakeRotationY$ function returns a quaternion representing the rotation through the angle given
	//# by the $angle$ parameter about the <i>y</i> axis. The resulting quaternion has unit length.
	//
	//# \also	$@Quaternion::MakeRotationX@$
	//# \also	$@Quaternion::MakeRotationZ@$
	//# \also	$@Quaternion::MakeRotation@$
	//# \also	$@Quaternion::GetRotationMatrix@$


	//# \function	Quaternion::MakeRotationZ		Returns a quaternion that represents a rotation about the <i>z</i> axis.
	//
	//# \proto	static Quaternion MakeRotationZ(float angle);
	//
	//# \param	angle	The angle of rotation, in radians.
	//
	//# \desc
	//# The $MakeRotationZ$ function returns a quaternion representing the rotation through the angle given
	//# by the $angle$ parameter about the <i>z</i> axis. The resulting quaternion has unit length.
	//
	//# \also	$@Quaternion::MakeRotationX@$
	//# \also	$@Quaternion::MakeRotationY@$
	//# \also	$@Quaternion::MakeRotation@$
	//# \also	$@Quaternion::GetRotationMatrix@$


	//# \function	Quaternion::MakeRotation		Returns a quaternion that represents a rotation about a given axis.
	//
	//# \proto	static Quaternion MakeRotation(float angle, const Bivector3D& axis);
	//
	//# \param	angle	The angle of rotation, in radians.
	//# \param	axis	The axis about which to rotate. This bivector must have unit magnitude.
	//
	//# \desc
	//# The $MakeRotation$ function returns a quaternion representing a rotation through the angle
	//# given by the $angle$ parameter about the axis given by the $axis$ parameter. The resulting
	//# quaternion has unit length.
	//
	//# \also	$@Quaternion::MakeRotationX@$
	//# \also	$@Quaternion::MakeRotationY@$
	//# \also	$@Quaternion::MakeRotationZ@$
	//# \also	$@Quaternion::GetRotationMatrix@$


	//# \function	Quaternion::GetRotationMatrix		Converts a quaternion to a 3&#x202F;&times;&#x202F;3 matrix.
	//
	//# \proto	Matrix3D GetRotationMatrix(void) const;
	//
	//# \desc
	//# The $GetRotationMatrix$ function converts a unit quaternion to a $@Matrix3D@$ object that
	//# represents the same rotation when it premultiplies a $@Vector3D@$ object.
	//
	//# \also	$@Quaternion::SetRotationMatrix@$
	//# \also	$@Quaternion::MakeRotationX@$
	//# \also	$@Quaternion::MakeRotationY@$
	//# \also	$@Quaternion::MakeRotationZ@$
	//# \also	$@Quaternion::MakeRotation@$


	//# \function	Quaternion::SetRotationMatrix		Converts a 3&#x202F;&times;&#x202F;3 matrix to a quaternion.
	//
	//# \proto	Quaternion& SetRotationMatrix(const Matrix3D& M);
	//
	//# \param	M		The matrix to convert to a quaternion.
	//
	//# \desc
	//# The $SetRotationMatrix$ function sets the components of a quaternion to values that
	//# represent the same rotation as the one represented by the matrix specified by the $M$ parameter.
	//#
	//# This function expects the matrix $M$ to be orthogonal and have a determinant of +1.
	//# If these conditions are not met, then the results are unlikely to be meaningful.
	//
	//# \also	$@Quaternion::GetRotationMatrix@$
	//# \also	$@Quaternion::MakeRotationX@$
	//# \also	$@Quaternion::MakeRotationY@$
	//# \also	$@Quaternion::MakeRotationZ@$
	//# \also	$@Quaternion::MakeRotation@$


	//# \member		Quaternion

	class Quaternion
	{
		public:

			float	x;		//## The <i>x</i> coordinate of the bivector part.
			float	y;		//## The <i>y</i> coordinate of the bivector part.
			float	z;		//## The <i>z</i> coordinate of the bivector part.
			float	w;		//## The <i>w</i> coordinate, which is the scalar part.

			TERATHON_API static const ConstQuaternion identity;

			inline Quaternion() = default;

			Quaternion(float a, float b, float c, float s)
			{
				x = a;
				y = b;
				z = c;
				w = s;
			}

			Quaternion(const Bivector3D& v, float s)
			{
				x = v.x;
				y = v.y;
				z = v.z;
				w = s;
			}

			explicit Quaternion(const Bivector3D& v)
			{
				x = v.x;
				y = v.y;
				z = v.z;
				w = 0.0F;
			}

			explicit Quaternion(float s)
			{
				w = s;
				x = y = z = 0.0F;
			}

			Quaternion& Set(float a, float b, float c, float s)
			{
				x = a;
				y = b;
				z = c;
				w = s;
				return (*this);
			}

			void Set(float a, float b, float c, float s) volatile
			{
				x = a;
				y = b;
				z = c;
				w = s;
			}

			Quaternion& Set(const Bivector3D& v, float s)
			{
				x = v.x;
				y = v.y;
				z = v.z;
				w = s;
				return (*this);
			}

			void Set(const Bivector3D& v, float s) volatile
			{
				x = v.x;
				y = v.y;
				z = v.z;
				w = s;
			}

			Bivector3D& GetBivectorPart(void)
			{
				return (reinterpret_cast<Bivector3D&>(x));
			}

			const Bivector3D& GetBivectorPart(void) const
			{
				return (reinterpret_cast<const Bivector3D&>(x));
			}

			Quaternion& operator =(const Quaternion& q)
			{
				x = q.x;
				y = q.y;
				z = q.z;
				w = q.w;
				return (*this);
			}

			void operator =(const Quaternion& q) volatile
			{
				x = q.x;
				y = q.y;
				z = q.z;
				w = q.w;
			}

			Quaternion& operator =(const Bivector3D& v)
			{
				x = v.x;
				y = v.y;
				z = v.z;
				w = 0.0F;
				return (*this);
			}

			void operator =(const Bivector3D& v) volatile
			{
				x = v.x;
				y = v.y;
				z = v.z;
				w = 0.0F;
			}

			Quaternion& operator =(float s)
			{
				w = s;
				x = y = z = 0.0F;
				return (*this);
			}

			void operator =(float s) volatile
			{
				w = s;
				x = y = z = 0.0F;
			}

			Quaternion& operator +=(const Quaternion& q)
			{
				x += q.x;
				y += q.y;
				z += q.z;
				w += q.w;
				return (*this);
			}

			Quaternion& operator +=(const Bivector3D& v)
			{
				x += v.x;
				y += v.y;
				z += v.z;
				return (*this);
			}

			Quaternion& operator +=(float s)
			{
				w += s;
				return (*this);
			}

			Quaternion& operator -=(const Quaternion& q)
			{
				x -= q.x;
				y -= q.y;
				z -= q.z;
				w -= q.w;
				return (*this);
			}

			Quaternion& operator -=(const Bivector3D& v)
			{
				x -= v.x;
				y -= v.y;
				z -= v.z;
				return (*this);
			}

			Quaternion& operator -=(float s)
			{
				w -= s;
				return (*this);
			}

			TERATHON_API Quaternion& operator *=(const Quaternion& q);
			TERATHON_API Quaternion& operator *=(const Bivector3D& v);

			Quaternion& operator *=(float s)
			{
				x *= s;
				y *= s;
				z *= s;
				w *= s;
				return (*this);
			}

			TERATHON_API Quaternion& operator /=(const Quaternion& q);
			TERATHON_API Quaternion& operator /=(const Bivector3D& v);

			Quaternion& operator /=(float s)
			{
				s = 1.0F / s;
				x *= s;
				y *= s;
				z *= s;
				w *= s;
				return (*this);
			}

			Quaternion& Normalize(void)
			{
				return (*this *= InverseSqrt(x * x + y * y + z * z + w * w));
			}

			Vector3D GetDirectionX(void) const
			{
				return (Vector3D(1.0F - 2.0F * (y * y + z * z), 2.0F * (x * y + w * z), 2.0F * (x * z - w * y)));
			}

			Vector3D GetDirectionY(void) const
			{
				return (Vector3D(2.0F * (x * y - w * z), 1.0F - 2.0F * (x * x + z * z), 2.0F * (y * z + w * x)));
			}

			Vector3D GetDirectionZ(void) const
			{
				return (Vector3D(2.0F * (x * z + w * y), 2.0F * (y * z - w * x), 1.0F - 2.0F * (x * x + y * y)));
			}

			static Quaternion MakeRotationX(float angle)
			{
				Vector2D v = CosSin(angle * 0.5F);
				return (Quaternion(v.y, 0.0F, 0.0F, v.x));
			}

			static Quaternion MakeRotationY(float angle)
			{
				Vector2D v = CosSin(angle * 0.5F);
				return (Quaternion(0.0F, v.y, 0.0F, v.x));
			}

			static Quaternion MakeRotationZ(float angle)
			{
				Vector2D v = CosSin(angle * 0.5F);
				return (Quaternion(0.0F, 0.0F, v.y, v.x));
			}

			static Quaternion MakeRotation(float angle, const Bivector3D& axis)
			{
				Vector2D v = CosSin(angle * 0.5F);
				return (Quaternion(axis * v.y, v.x));
			}

			TERATHON_API Matrix3D GetRotationMatrix(void) const;

			template <class matrix>
			TERATHON_API Quaternion& SetRotationMatrix(const matrix& M);
	};


	inline Quaternion operator -(const Quaternion& q)
	{
		return (Quaternion(-q.x, -q.y, -q.z, -q.w));
	}

	inline Quaternion operator +(const Quaternion& q1, const Quaternion& q2)
	{
		return (Quaternion(q1.x + q2.x, q1.y + q2.y, q1.z + q2.z, q1.w + q2.w));
	}

	inline Quaternion operator +(const Quaternion& q, const Bivector3D& v)
	{
		return (Quaternion(q.x + v.x, q.y + v.y, q.z + v.z, q.w));
	}

	inline Quaternion operator +(const Bivector3D& v, const Quaternion& q)
	{
		return (Quaternion(v.x + q.x, v.y + q.y, v.z + q.z, q.w));
	}

	inline Quaternion operator +(const Quaternion& q, float s)
	{
		return (Quaternion(q.x, q.y, q.z, q.w + s));
	}

	inline Quaternion operator +(float s, const Quaternion& q)
	{
		return (Quaternion(q.x, q.y, q.z, s + q.w));
	}

	inline Quaternion operator -(const Quaternion& q1, const Quaternion& q2)
	{
		return (Quaternion(q1.x - q2.x, q1.y - q2.y, q1.z - q2.z, q1.w - q2.w));
	}

	inline Quaternion operator -(const Quaternion& q, const Bivector3D& v)
	{
		return (Quaternion(q.x - v.x, q.y - v.y, q.z - v.z, q.w));
	}

	inline Quaternion operator -(const Bivector3D& v, const Quaternion& q)
	{
		return (Quaternion(v.x - q.x, v.y - q.y, v.z - q.z, -q.w));
	}

	inline Quaternion operator -(const Quaternion& q, float s)
	{
		return (Quaternion(q.x, q.y, q.z, q.w - s));
	}

	inline Quaternion operator -(float s, const Quaternion& q)
	{
		return (Quaternion(-q.x, -q.y, -q.z, s - q.w));
	}

	inline Quaternion operator *(const Quaternion& q, float s)
	{
		return (Quaternion(q.x * s, q.y * s, q.z * s, q.w * s));
	}

	inline Quaternion operator *(float s, const Quaternion& q)
	{
		return (Quaternion(s * q.x, s * q.y, s * q.z, s * q.w));
	}

	inline Quaternion operator /(const Quaternion& q, float s)
	{
		s = 1.0F / s;
		return (Quaternion(q.x * s, q.y * s, q.z * s, q.w * s));
	}

	inline bool operator ==(const Quaternion& q1, const Quaternion& q2)
	{
		return ((q1.x == q2.x) && (q1.y == q2.y) && (q1.z == q2.z) && (q1.w == q2.w));
	}

	inline bool operator ==(const Quaternion& q, const Bivector3D& v)
	{
		return ((q.x == v.x) && (q.y == v.y) && (q.z == v.z) && (q.w == 0.0F));
	}

	inline bool operator ==(const Bivector3D& v, const Quaternion& q)
	{
		return ((q.x == v.x) && (q.y == v.y) && (q.z == v.z) && (q.w == 0.0F));
	}

	inline bool operator ==(const Quaternion& q, float s)
	{
		return ((q.w == s) && (q.x == 0.0F) && (q.y == 0.0F) && (q.z == 0.0F));
	}

	inline bool operator ==(float s, const Quaternion& q)
	{
		return ((q.w == s) && (q.x == 0.0F) && (q.y == 0.0F) && (q.z == 0.0F));
	}

	inline bool operator !=(const Quaternion& q1, const Quaternion& q2)
	{
		return ((q1.x != q2.x) || (q1.y != q2.y) || (q1.z != q2.z) || (q1.w != q2.w));
	}

	inline bool operator !=(const Quaternion& q, const Bivector3D& v)
	{
		return ((q.x != v.x) || (q.y != v.y) || (q.z != v.z) || (q.w != 0.0F));
	}

	inline bool operator !=(const Bivector3D& v, const Quaternion& q)
	{
		return ((q.x != v.x) || (q.y != v.y) || (q.z != v.z) || (q.w != 0.0F));
	}

	inline bool operator !=(const Quaternion& q, float s)
	{
		return ((q.w != s) || (q.x != 0.0F) || (q.y != 0.0F) || (q.z != 0.0F));
	}

	inline bool operator !=(float s, const Quaternion& q)
	{
		return ((q.w != s) || (q.x != 0.0F) || (q.y != 0.0F) || (q.z != 0.0F));
	}

	inline float Magnitude(const Quaternion& q)
	{
		return (Sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w));
	}

	inline float InverseMag(const Quaternion& q)
	{
		return (InverseSqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w));
	}

	inline float SquaredMag(const Quaternion& q)
	{
		return (q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
	}

	inline Quaternion Reverse(const Quaternion& q)
	{
		return (Quaternion(-q.x, -q.y, -q.z, q.w));
	}

	inline Quaternion Inverse(const Quaternion& q)
	{
		return (Reverse(q) / SquaredMag(q));
	}

	inline Quaternion& Quaternion::operator /=(const Quaternion& q)
	{
		return (*this *= Inverse(q));
	}

	inline Quaternion& Quaternion::operator /=(const Bivector3D& v)
	{
		return (*this *= -v / SquaredMag(v));
	}

	inline Quaternion operator /(float s, const Quaternion& q)
	{
		return (s * Inverse(q));
	}

	inline float Dot(const Quaternion& q1, const Quaternion& q2)
	{
		return (q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w);
	}


	TERATHON_API Quaternion operator *(const Quaternion& q1, const Quaternion& q2);
	TERATHON_API Quaternion operator *(const Quaternion& q, const Bivector3D& v);


	inline Quaternion operator *(const Bivector3D& v, const Quaternion& q)
	{
		return (Quaternion(v) * q);
	}

	inline Quaternion operator /(const Quaternion& q1, const Quaternion& q2)
	{
		return (q1 * Inverse(q2));
	}

	inline Quaternion operator /(const Quaternion& q, const Bivector3D& v)
	{
		return (q * (-v / SquaredMag(v)));
	}

	inline Quaternion operator /(const Bivector3D& v, const Quaternion& q)
	{
		return (Quaternion(v) * Inverse(q));
	}


	TERATHON_API Quaternion Sqrt(const Quaternion& q);
	TERATHON_API Vector3D Transform(const Vector3D& v, const Quaternion& q);


	struct ConstQuaternion
	{
		float	x;
		float	y;
		float	z;
		float	w;

		operator const Quaternion&(void) const
		{
			return (reinterpret_cast<const Quaternion&>(*this));
		}

		const Quaternion *operator &(void) const
		{
			return (reinterpret_cast<const Quaternion *>(this));
		}
	};
}


#endif
