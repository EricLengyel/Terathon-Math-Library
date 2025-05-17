//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSQuaternion_h
#define TSQuaternion_h


#include "TSMatrix4D.h"


#define TERATHON_QUATERNION 1


namespace Terathon
{
	struct ConstQuaternion;


	// ==============================================
	//	Quaternion
	// ==============================================

	struct TypeQuaternion
	{
		typedef float component_type;
		typedef Bivector3D vector3D_type;
	};


	/// \brief Encapsulates a quaternion.
	///
	/// The $Quaternion$ class encapsulates a Hamiltonian quaternion having the form
	/// <i>xi</i>&#x202F;+&#x202F;<i>yj</i>&#x202F;+&#x202F;<i>zk</i>&#x202F;+&#x202F;<i>w</i>.
	///
	/// \also Motor3D

	class Quaternion
	{
		public:

			union
			{
				Component<TypeQuaternion, 4, 0>					x;			///< The <i>x</i> coordinate of the bivector part.
				Component<TypeQuaternion, 4, 1>					y;			///< The <i>y</i> coordinate of the bivector part.
				Component<TypeQuaternion, 4, 2>					z;			///< The <i>z</i> coordinate of the bivector part.
				Component<TypeQuaternion, 4, 3>					w;			///< The <i>w</i> coordinate, which is the scalar part.
				Subvec3D<TypeQuaternion, true, 4, 0, 1, 2>		xyz;		///< The <i>x</i>, <i>y</i>, and <i>z</i> coordinates together as a single bivector.
			};

			TERATHON_API static const ConstQuaternion identity;

			/// \brief Default constructor that leaves the components uninitialized.

			inline Quaternion() = default;

			Quaternion(const Quaternion& q)
			{
				xyz = q.xyz;
				w = q.w;
			}

			/// \brief Constructor that sets components explicitly.
			/// \param a,b,c	The components of the bivector part.
			/// \param s		The scalar part.

			Quaternion(float a, float b, float c, float s)
			{
				xyz.Set(a, b, c);
				w = s;
			}

			/// \brief Constructor that sets components explicitly.
			/// \param v		The bivector part.
			/// \param s		The scalar part.

			Quaternion(const Bivector3D& v, float s)
			{
				xyz = v;
				w = s;
			}

			/// \brief Constructor that sets only the bivector part. The scalar part is set to zero.
			/// \param v		The bivector part.

			explicit Quaternion(const Bivector3D& v)
			{
				xyz = v;
				w = 0.0F;
			}

			/// \brief Constructor that sets only the scalar part. The bivector part is set to zero.
			/// \param s		The scalar part.

			explicit Quaternion(float s)
			{
				w = s;
				xyz.Set(0.0F, 0.0F, 0.0F);
			}

			/// \brief Sets all four components of a quaternion.
			/// \param a,b,c	The components of the bivector part.
			/// \param s		The scalar part.

			Quaternion& Set(float a, float b, float c, float s)
			{
				xyz.Set(a, b, c);
				w = s;
				return (*this);
			}

			void Set(float a, float b, float c, float s) volatile
			{
				xyz.Set(a, b, c);
				w = s;
			}

			Quaternion& Set(const Bivector3D& v, float s)
			{
				xyz = v;
				w = s;
				return (*this);
			}

			void Set(const Bivector3D& v, float s) volatile
			{
				xyz = v;
				w = s;
			}

			Quaternion& operator =(const Quaternion& q)
			{
				xyz = q.xyz;
				w = q.w;
				return (*this);
			}

			void operator =(const Quaternion& q) volatile
			{
				xyz = q.xyz;
				w = q.w;
			}

			Quaternion& operator =(const Bivector3D& v)
			{
				xyz = v;
				w = 0.0F;
				return (*this);
			}

			void operator =(const Bivector3D& v) volatile
			{
				xyz = v;
				w = 0.0F;
			}

			Quaternion& operator =(float s)
			{
				w = s;
				xyz.Set(0.0F, 0.0F, 0.0F);
				return (*this);
			}

			void operator =(float s) volatile
			{
				w = s;
				xyz.Set(0.0F, 0.0F, 0.0F);
			}

			Quaternion& operator +=(const Quaternion& q)
			{
				xyz += q.xyz;
				w += q.w;
				return (*this);
			}

			Quaternion& operator +=(const Bivector3D& v)
			{
				xyz += v;
				return (*this);
			}

			Quaternion& operator +=(float s)
			{
				w += s;
				return (*this);
			}

			Quaternion& operator -=(const Quaternion& q)
			{
				xyz -= q.xyz;
				w -= q.w;
				return (*this);
			}

			Quaternion& operator -=(const Bivector3D& v)
			{
				xyz -= v;
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
				xyz *= s;
				w *= s;
				return (*this);
			}

			TERATHON_API Quaternion& operator /=(const Quaternion& q);
			TERATHON_API Quaternion& operator /=(const Bivector3D& v);

			Quaternion& operator /=(float s)
			{
				s = 1.0F / s;
				xyz *= s;
				w *= s;
				return (*this);
			}

			/// \brief Normalizes a quaternion.
			///
			/// The $Normalize()$ function multiplies a quaternion by the inverse of its magnitude,
			/// normalizing it to unit length. Normalizing the zero quaternion produces undefined results.

			Quaternion& Normalize(void)
			{
				return (*this *= InverseSqrt(SquaredMag(xyz) + w * w));
			}

			/// \brief Returns the direction to which the <i>x</i> axis is transformed by a quaternion.
			///
			/// The $GetDirectionX()$ function calculates the 3D vector that results from transforming the direction vector
			/// (1,&nbsp;0,&nbsp;0) with the quaternion for which it is called.

			Vector3D GetDirectionX(void) const
			{
				return (Vector3D(1.0F - 2.0F * (y * y + z * z), 2.0F * (x * y + w * z), 2.0F * (x * z - w * y)));
			}

			/// \brief Returns the direction to which the <i>y</i> axis is transformed by a quaternion.
			///
			/// The $GetDirectionY()$ function calculates the 3D vector that results from transforming the direction vector
			/// (0,&nbsp;1,&nbsp;0) with the quaternion for which it is called.

			Vector3D GetDirectionY(void) const
			{
				return (Vector3D(2.0F * (x * y - w * z), 1.0F - 2.0F * (x * x + z * z), 2.0F * (y * z + w * x)));
			}

			/// \brief Returns the direction to which the <i>z</i> axis is transformed by a quaternion.
			///
			/// The $GetDirectionZ()$ function calculates the 3D vector that results from transforming the direction vector
			/// (0,&nbsp;0,&nbsp;1) with the quaternion for which it is called.

			Vector3D GetDirectionZ(void) const
			{
				return (Vector3D(2.0F * (x * z + w * y), 2.0F * (y * z - w * x), 1.0F - 2.0F * (x * x + y * y)));
			}

			/// \brief Returns a quaternion that represents a rotation about the <i>x</i> axis.
			/// \param angle	The angle of rotation, in radians.
			///
			/// The $MakeRotationX()$ function returns a quaternion representing the rotation through the angle given
			/// by the $angle$ parameter about the <i>x</i> axis. The resulting quaternion has unit length.

			static Quaternion MakeRotationX(float angle)
			{
				Vector2D v = CosSin(angle * 0.5F);
				return (Quaternion(v.y, 0.0F, 0.0F, v.x));
			}

			/// \brief Returns a quaternion that represents a rotation about the <i>y</i> axis.
			/// \param angle	The angle of rotation, in radians.
			///
			/// The $MakeRotationY()$ function returns a quaternion representing the rotation through the angle given
			/// by the $angle$ parameter about the <i>y</i> axis. The resulting quaternion has unit length.

			static Quaternion MakeRotationY(float angle)
			{
				Vector2D v = CosSin(angle * 0.5F);
				return (Quaternion(0.0F, v.y, 0.0F, v.x));
			}

			/// \brief Returns a quaternion that represents a rotation about the <i>z</i> axis.
			/// \param angle	The angle of rotation, in radians.
			///
			/// The $MakeRotationZ()$ function returns a quaternion representing the rotation through the angle given
			/// by the $angle$ parameter about the <i>z</i> axis. The resulting quaternion has unit length.

			static Quaternion MakeRotationZ(float angle)
			{
				Vector2D v = CosSin(angle * 0.5F);
				return (Quaternion(0.0F, 0.0F, v.y, v.x));
			}

			/// \brief Returns a quaternion that represents a rotation about a given axis.
			/// \param angle	The angle of rotation, in radians.
			/// \param axis		The axis about which to rotate. This bivector must have unit magnitude.
			///
			/// The $MakeRotation()$ function returns a quaternion representing a rotation through the angle
			/// given by the $angle$ parameter about the axis given by the $axis$ parameter. The resulting
			/// quaternion has unit length.

			static Quaternion MakeRotation(float angle, const Bivector3D& axis)
			{
				Vector2D v = CosSin(angle * 0.5F);
				return (Quaternion(axis * v.y, v.x));
			}

			/// \brief Converts a quaternion to a 3&#x202F;&times;&#x202F;3 matrix.
			///
			/// The $GetRotationMatrix()$ function converts a unit quaternion to a Matrix3D object that
			/// represents the same rotation when it premultiplies a Vector3D object.

			TERATHON_API Matrix3D GetRotationMatrix(void) const;

			/// \brief Converts a 3&#x202F;&times;&#x202F;3 matrix to a quaternion.
			/// \tparam matrix	Can be Matrix3D or Transform3D.
			/// \param M		The matrix to convert to a quaternion.
			///
			/// The $SetRotationMatrix()$ function sets the components of a quaternion to values that
			/// represent the same rotation as the one represented by the matrix specified by the $M$ parameter.
			///
			/// This function expects the matrix $M$ to be orthogonal and have a determinant of +1.
			/// If these conditions are not met, then the results are unlikely to be meaningful.

			template <class matrix>
			TERATHON_API Quaternion& SetRotationMatrix(const matrix& M);
	};


	/// \brief Returns the negation of the quaternion $q$.
	/// \related Quaternion

	inline Quaternion operator -(const Quaternion& q)
	{
		return (Quaternion(-q.xyz, -q.w));
	}

	/// \brief Returns the sum of the quaternions $q1$ and $q2$.
	/// \related Quaternion

	inline Quaternion operator +(const Quaternion& q1, const Quaternion& q2)
	{
		return (Quaternion(q1.xyz + q2.xyz, q1.w + q2.w));
	}

	inline Quaternion operator +(const Quaternion& q, const Bivector3D& v)
	{
		return (Quaternion(q.xyz + v, q.w));
	}

	inline Quaternion operator +(const Bivector3D& v, const Quaternion& q)
	{
		return (Quaternion(v + q.xyz, q.w));
	}

	inline Quaternion operator +(const Quaternion& q, float s)
	{
		return (Quaternion(q.xyz, q.w + s));
	}

	inline Quaternion operator +(float s, const Quaternion& q)
	{
		return (Quaternion(q.xyz, s + q.w));
	}

	/// \brief Returns the difference of the quaternions $q1$ and $q2$.
	/// \related Quaternion

	inline Quaternion operator -(const Quaternion& q1, const Quaternion& q2)
	{
		return (Quaternion(q1.xyz - q2.xyz, q1.w - q2.w));
	}

	inline Quaternion operator -(const Quaternion& q, const Bivector3D& v)
	{
		return (Quaternion(q.xyz - v, q.w));
	}

	inline Quaternion operator -(const Bivector3D& v, const Quaternion& q)
	{
		return (Quaternion(v - q.xyz, -q.w));
	}

	inline Quaternion operator -(const Quaternion& q, float s)
	{
		return (Quaternion(q.xyz, q.w - s));
	}

	inline Quaternion operator -(float s, const Quaternion& q)
	{
		return (Quaternion(-q.xyz, s - q.w));
	}

	inline Quaternion operator *(const Quaternion& q, float s)
	{
		return (Quaternion(q.xyz * s, q.w * s));
	}

	inline Quaternion operator *(float s, const Quaternion& q)
	{
		return (Quaternion(s * q.xyz, s * q.w));
	}

	inline Quaternion operator /(const Quaternion& q, float s)
	{
		s = 1.0F / s;
		return (Quaternion(q.xyz * s, q.w * s));
	}

	/// \brief Returns a boolean value indicating whether the two quaternions $q1$ and $q2$ are equal.
	/// \related Quaternion

	inline bool operator ==(const Quaternion& q1, const Quaternion& q2)
	{
		return ((q1.xyz == q2.xyz) && (q1.w == q2.w));
	}

	inline bool operator ==(const Quaternion& q, const Bivector3D& v)
	{
		return ((q.xyz == v.xyz) && (q.w == 0.0F));
	}

	inline bool operator ==(const Bivector3D& v, const Quaternion& q)
	{
		return ((q.xyz == v.xyz) && (q.w == 0.0F));
	}

	inline bool operator ==(const Quaternion& q, float s)
	{
		return ((q.w == s) && (q.x == 0.0F) && (q.y == 0.0F) && (q.z == 0.0F));
	}

	inline bool operator ==(float s, const Quaternion& q)
	{
		return ((q.w == s) && (q.x == 0.0F) && (q.y == 0.0F) && (q.z == 0.0F));
	}

	/// \brief Returns a boolean value indicating whether the two quaternions $q1$ and $q2$ are not equal.
	/// \related Quaternion

	inline bool operator !=(const Quaternion& q1, const Quaternion& q2)
	{
		return ((q1.xyz != q2.xyz) || (q1.w != q2.w));
	}

	inline bool operator !=(const Quaternion& q, const Bivector3D& v)
	{
		return ((q.xyz != v.xyz) || (q.w != 0.0F));
	}

	inline bool operator !=(const Bivector3D& v, const Quaternion& q)
	{
		return ((q.xyz != v.xyz) || (q.w != 0.0F));
	}

	inline bool operator !=(const Quaternion& q, float s)
	{
		return ((q.w != s) || (q.x != 0.0F) || (q.y != 0.0F) || (q.z != 0.0F));
	}

	inline bool operator !=(float s, const Quaternion& q)
	{
		return ((q.w != s) || (q.x != 0.0F) || (q.y != 0.0F) || (q.z != 0.0F));
	}

	// ==============================================
	//	Magnitude
	// ==============================================

	/// \brief Returns the magnitude of a quaternion.
	/// \related Quaternion

	inline float Magnitude(const Quaternion& q)
	{
		return (Sqrt(SquaredMag(q.xyz) + q.w * q.w));
	}

	/// \brief Returns the inverse magnitude of a quaternion.
	/// \related Quaternion

	inline float InverseMag(const Quaternion& q)
	{
		return (InverseSqrt(SquaredMag(q.xyz) + q.w * q.w));
	}

	/// \brief Returns the squared magnitude of a quaternion.
	/// \related Quaternion

	inline float SquaredMag(const Quaternion& q)
	{
		return (SquaredMag(q.xyz) + q.w * q.w);
	}

	// ==============================================
	//	Reverse
	// ==============================================

	/// \brief Returns the reverse of a quaternion, also known as its conjugate.
	/// \related Quaternion

	inline Quaternion Reverse(const Quaternion& q)
	{
		return (Quaternion(-q.xyz, q.w));
	}

	// ==============================================
	//	Inverse
	// ==============================================

	/// \brief Returns the inverse of a quaternion.
	/// \related Quaternion

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

	// ==============================================
	//	Dot product
	// ==============================================

	/// \brief Returns the dot product of the quaternions $q1$ and $q2$.
	/// \related Quaternion

	inline float Dot(const Quaternion& q1, const Quaternion& q2)
	{
		return (Dot(q1.xyz, q2.xyz) + q1.w * q2.w);
	}

	// ==============================================
	//	Geometric product
	// ==============================================

	/// \brief Returns the geometric product of the quaternions $q1$ and $q2$.
	/// \related Quaternion

	TERATHON_API Quaternion operator *(const Quaternion& q1, const Quaternion& q2);

	/// \brief Returns the geometric product of the quaternion $q$ and bivector $v$.
	/// \related Quaternion

	TERATHON_API Quaternion operator *(const Quaternion& q, const Bivector3D& v);

	inline Quaternion operator *(const Bivector3D& v, const Quaternion& q)
	{
		return (Quaternion(v) * q);
	}

	/// \brief Returns the geometric product of the quaternion $q1$ and the inverse of the quaternion $q2$.
	/// \related Quaternion

	inline Quaternion operator /(const Quaternion& q1, const Quaternion& q2)
	{
		return (q1 * Inverse(q2));
	}

	/// \brief Returns the geometric product of the quaternion $q$ and the inverse of the bivector $v$.
	/// \related Quaternion

	inline Quaternion operator /(const Quaternion& q, const Bivector3D& v)
	{
		return (q * (-v / SquaredMag(v)));
	}

	inline Quaternion operator /(const Bivector3D& v, const Quaternion& q)
	{
		return (Quaternion(v) * Inverse(q));
	}

	// ==============================================
	//	Square root
	// ==============================================

	/// \brief Returns the square root of a quaternion.
	/// \related Quaternion

	TERATHON_API Quaternion Sqrt(const Quaternion& q);

	// ==============================================
	//	Transformation
	// ==============================================

	/// \brief Transforms the 3D vector $v$ with the quaternion $q$.
	/// \related Quaternion

	TERATHON_API Vector3D Transform(const Vector3D& v, const Quaternion& q);


	// ==============================================
	//	POD Structures
	// ==============================================

	struct ConstQuaternion
	{
		float	x, y, z, w;

		operator const Quaternion&(void) const
		{
			return (reinterpret_cast<const Quaternion&>(*this));
		}

		const Quaternion *operator &(void) const
		{
			return (reinterpret_cast<const Quaternion *>(this));
		}

		const Quaternion *operator ->(void) const
		{
			return (reinterpret_cast<const Quaternion *>(this));
		}
	};
}


#endif
