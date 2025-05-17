//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSMotor3D_h
#define TSMotor3D_h


#include "TSRigid3D.h"
#include "TSQuaternion.h"


#define TERATHON_MOTOR3D 1


namespace Terathon
{
	struct ConstMotor3D;


	// ==============================================
	//	Motor3D
	// ==============================================

	/// \brief Encapsulates a 3D <a href="https://rigidgeometricalgebra.org/wiki/index.php?title=Motor">motion operator (motor)</a> in rigid geometric algebra.
	///
	/// The $Motor3D$ class encapsulates a 3D motion operator (motor), also known as a dual quaternion.
	/// It has the general form <i>Q<sub>vx</sub></i><b>e</b><sub>41</sub> + <i>Q<sub>vy</sub></i><b>e</b><sub>42</sub> + <i>Q<sub>vz</sub></i><b>e</b><sub>43</sub> + <i>Q<sub>vw</sub></i>&#x1D7D9; + <i>Q<sub>mx</sub></i><b>e</b><sub>23</sub> + <i>Q<sub>my</sub></i><b>e</b><sub>31</sub> + <i>Q<sub>mz</sub></i><b>e</b><sub>12</sub> + <i>Q<sub>mw</sub></i>.
	///
	/// \also Flector3D

	class Motor3D
	{
		public:

			Quaternion		v;			///< The coordinates of the weight components using basis elements <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and <b>e</b><sub>1234</sub>.
			Quaternion		m;			///< The coordinates of the bulk components using basis elements <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, <b>e</b><sub>12</sub>, and <b>1</b>.

			TERATHON_API static const ConstMotor3D identity;

			/// \brief Default constructor that leaves the components uninitialized.

			inline Motor3D() = default;

			Motor3D(const Motor3D& Q)
			{
				v = Q.v;
				m = Q.m;
			}

			/// \brief Constructor that sets components explicitly.
			/// \param vx,vy,vz,vw		The values of the <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and antiscalar coordinates.
			/// \param mx,my,mz,mw		The values of the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, <b>e</b><sub>12</sub>, and scalar coordinates.

			Motor3D(float vx, float vy, float vz, float vw, float mx, float my, float mz, float mw)
			{
				v.Set(vx, vy, vz, vw);
				m.Set(mx, my, mz, mw);
			}

			/// \brief Constructor that converts a quaternion to a 3D motor.
			/// \param q	A quaternion whose entries are copied to the <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and antiscalar coordinates.

			explicit Motor3D(const Quaternion& q)
			{
				v = q;
				m.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			Motor3D(const Quaternion& rotor, const Quaternion& screw)
			{
				v = rotor;
				m = screw;
			}

			/// \brief Constructor that calculates the 3D motor <b>h</b>&#x202F;&#x27C7;&#x202F;<b>g</b>.

			Motor3D(const Plane3D& g, const Plane3D& h)
			{
				v.Set(g.y * h.z - g.z * h.y, g.z * h.x - g.x * h.z, g.x * h.y - g.y * h.x, g.x * h.x + g.y * h.y + g.z * h.z);
				m.Set(g.w * h.x - g.x * h.w, g.w * h.y - g.y * h.w, g.w * h.z - g.z * h.w, 0.0F);
			}

			/// \brief Constructor that calculates the 3D motor <b><i>l</i></b>&#x202F;&#x27C7;&#x202F;<b>k</b>.

			Motor3D(const Line3D& k, const Line3D& l)
			{
				v.Set(k.v ^ l.v, -Dot(k.v, l.v));
				m.Set((l.v ^ !k.m) - (k.v ^ !l.m), -(l.v ^ k.m) - (k.v ^ l.m));
			}

			/// \brief Constructor that calculates the 3D motor <b>q</b>&#x202F;&#x27C7;&#x202F;<b>p</b>.

			Motor3D(const Point3D& p, const Point3D& q)
			{
				v.Set(0.0F, 0.0F, 0.0F, -1.0F);
				m.Set(p.x - q.x, p.y - q.y, p.z - q.z, 0.0F);
			}

			/// \brief Sets all eight components of a 3D motor.
			/// \param vx,vy,vz,vw		The values of the <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and antiscalar coordinates.
			/// \param mx,my,mz,mw		The values of the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, <b>e</b><sub>12</sub>, and scalar coordinates.

			Motor3D& Set(float vx, float vy, float vz, float vw, float mx, float my, float mz, float mw)
			{
				v.Set(vx, vy, vz, vw);
				m.Set(mx, my, mz, mw);
				return (*this);
			}

			void Set(float vx, float vy, float vz, float vw, float mx, float my, float mz, float mw) volatile
			{
				v.Set(vx, vy, vz, vw);
				m.Set(mx, my, mz, mw);
			}

			Motor3D& Set(const Quaternion& rotor, const Quaternion& screw)
			{
				v = rotor;
				m = screw;
				return (*this);
			}

			void Set(const Quaternion& rotor, const Quaternion& screw) volatile
			{
				v = rotor;
				m = screw;
			}

			Motor3D& operator =(const Motor3D& Q)
			{
				v = Q.v;
				m = Q.m;
				return (*this);
			}

			void operator =(const Motor3D& Q) volatile
			{
				v = Q.v;
				m = Q.m;
			}

			Motor3D& operator =(const Quaternion& rotor)
			{
				v = rotor;
				m.Set(0.0F, 0.0F, 0.0F, 0.0F);
				return (*this);
			}

			void operator =(const Quaternion& rotor) volatile
			{
				v = rotor;
				m.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			Motor3D& operator +=(const Motor3D& Q)
			{
				v += Q.v;
				m += Q.m;
				return (*this);
			}

			Motor3D& operator -=(const Motor3D& Q)
			{
				v -= Q.v;
				m -= Q.m;
				return (*this);
			}

			Motor3D& operator *=(float n)
			{
				v *= n;
				m *= n;
				return (*this);
			}

			Motor3D& operator /=(float n)
			{
				n = 1.0F / n;
				v *= n;
				m *= n;
				return (*this);
			}

			/// \brief Unitizes the weight of a 3D motor.
			///
			/// The $Unitize()$ function multiplies a motor by the inverse magnitude of its weight, which is the quaternion
			/// given by its <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and antiscalar coordinates.
			/// After calling this function, the rotor component of the motor is unit-length. If these coordinates are all zero,
			/// then the result is undefined.

			Motor3D& Unitize(void)
			{
				return (*this *= InverseMag(v));
			}

			/// \brief Returns a 3D motor that represents a rotation about a given axis through the origin.
			/// \param angle	The angle of rotation, in radians.
			/// \param axis		The axis about which to rotate. This bivector must have unit magnitude.
			///
			/// The $MakeRotation()$ function returns a motor representing a rotation through the angle
			/// given by the $angle$ parameter about the axis through the origin given by the $axis$ parameter.
			/// The resulting motor is unitized.

			static Motor3D MakeRotation(float angle, const Bivector3D& axis)
			{
				Vector2D t = CosSin(angle * 0.5F);
				return (Motor3D(axis.x * t.y, axis.y * t.y, axis.z * t.y, t.x, 0.0F, 0.0F, 0.0F, 0.0F));
			}

			/// \brief Returns a 3D motor that represents a translation.
			/// \param offset	The offset vector.
			///
			/// The $MakeTranslation()$ function returns a motor representing a translation by the
			/// direction and magnitude given by the $offset$ parameter.

			static Motor3D MakeTranslation(const Vector3D& offset)
			{
				return (Motor3D(0.0F, 0.0F, 0.0F, 1.0F, offset.x * 0.5F, offset.y * 0.5F, offset.z * 0.5F, 0.0F));
			}

			/// \brief Returns a 3D motor that represents a general screw motion.
			/// \param angle	The angle of rotation, in radians.
			/// \param axis		The unitized line about which to rotate.
			/// \param disp		The displacement distance along the line.
			///
			/// The $MakeScrew()$ function returns a motor representing a rotation through the angle
			/// given by the $angle$ parameter about the line given by the $axis$ parameter and a
			/// translation along that line of the distance given by the $disp$ parameter.

			static Motor3D MakeScrew(float angle, const Line3D& axis, float disp)
			{
				disp *= 0.5F;
				Vector2D t = CosSin(angle * 0.5F);
				return (Motor3D(axis.v.x * t.y, axis.v.y * t.y, axis.v.z * t.y, t.x, disp * axis.v.x * t.x + axis.m.x * t.y, disp * axis.v.y * t.x + axis.m.y * t.y, disp * axis.v.z * t.x + axis.m.z * t.y, -disp * t.y));
			}

			/// \brief Returns the direction to which the <i>x</i> axis is transformed by a 3D motor.
			///
			/// The $GetDirectionX()$ function calculates the 3D vector that results from transforming the direction vector
			/// (1,&nbsp;0,&nbsp;0) with the motor for which it is called.

			TERATHON_API Vector3D GetDirectionX(void) const;

			/// \brief Returns the direction to which the <i>y</i> axis is transformed by a 3D motor.
			///
			/// The $GetDirectionY()$ function calculates the 3D vector that results from transforming the direction vector
			/// (0,&nbsp;1,&nbsp;0) with the motor for which it is called.

			TERATHON_API Vector3D GetDirectionY(void) const;

			/// \brief Returns the direction to which the <i>z</i> axis is transformed by a 3D motor.
			///
			/// The $GetDirectionZ()$ function calculates the 3D vector that results from transforming the direction vector
			/// (0,&nbsp;0,&nbsp;1) with the motor for which it is called.

			TERATHON_API Vector3D GetDirectionZ(void) const;

			/// \brief Returns the position to which the origin is transformed by a 3D motor.
			///
			/// The $GetPosition()$ function calculates the 3D point that results from transforming the origin
			/// with the motor for which it is called.

			TERATHON_API Point3D GetPosition(void) const;

			/// \brief Converts a 3D motor to its corresponding 4&#x202F;&times;&#x202F;4 matrix.
			///
			/// The $GetTransformMatrix()$ function converts a motor to the Transform3D object that
			/// represents the same transformation when it premultiplies a Vector3D or Point3D object.

			TERATHON_API Transform3D GetTransformMatrix(void) const;

			/// \brief Converts a 3D motor to the inverse of its corresponding 4&#x202F;&times;&#x202F;4 matrix.
			///
			/// The $GetInverseTransformMatrix()$ function converts a motor to the inverse of the Transform3D object that
			/// represents the same transformation when it premultiplies a Vector3D or Point3D object. Such a matrix
			/// correctly transforms a Plane3D object when it postmultiplies it.
			///
			/// This function performs the same amount of computation as the Motor3D::GetTransformMatrix() function, and is thus
			/// significantly faster than calling the Motor3D::GetTransformMatrix() function and inverting the result.

			TERATHON_API Transform3D GetInverseTransformMatrix(void) const;

			/// \brief Converts a 3D motor to its corresponding 4&#x202F;&times;&#x202F;4 matrix and its inverse simultaneously.
			/// \param M		A pointer to the location where the transform matrix is returned.
			/// \param Minv		A pointer to the location where the inverse transform matrix is returned.
			///
			/// The $GetTransformMatrices()$ function converts a motor to the Transform3D object that represents the same
			/// transformation when it premultiplies a Vector3D or Point3D object and stores it in the location specified
			/// by the $M$ parameter. The inverse of this matrix is stored in the location specified by the $Minv$ parameter.
			///
			/// Calling this function is much faster than making separate calls to the Motor3D::GetTransformMatrix() and
			/// Motor3D::GetInverseTransformMatrix() functions.

			TERATHON_API void GetTransformMatrices(Transform3D *M, Transform3D *Minv) const;

			/// \brief Converts a 4&#x202F;&times;&#x202F;4 matrix to its corresponding 3D motor.
			/// \param M	The matrix to convert to a motor.
			///
			/// The $SetTransformMatrix()$ function sets the components of a motor to values that represent
			/// the same rigid motion as the one represented by the matrix specified by the $M$ parameter.
			///
			/// This function expects the matrix $M$ to have a determinant of +1, and it expects the upper-left 3&#x202F;&times;&#x202F;3
			/// portion of the matrix to be orthogonal. If these conditions are not met, then the results are unlikely to be meaningful.

			TERATHON_API Motor3D& SetTransformMatrix(const Transform3D& M);
	};


	/// \brief Returns the negation of the 3D motor $Q$.
	/// \related Motor3D

	inline Motor3D operator -(const Motor3D& Q)
	{
		return (Motor3D(-Q.v.x, -Q.v.y, -Q.v.z, -Q.v.w, -Q.m.x, -Q.m.y, -Q.m.z, -Q.m.w));
	}

	/// \brief Returns the product of the 3D motor $Q$ and the scalar $n$.
	/// \related Motor3D

	inline Motor3D operator *(const Motor3D& Q, float n)
	{
		return (Motor3D(Q.v.x * n, Q.v.y * n, Q.v.z * n, Q.v.w * n, Q.m.x * n, Q.m.y * n, Q.m.z * n, Q.m.w * n));
	}

	/// \brief Returns the product of the 3D motor $Q$ and the scalar $n$.
	/// \related Motor3D

	inline Motor3D operator *(float n, const Motor3D& Q)
	{
		return (Motor3D(n * Q.v.x, n * Q.v.y, n * Q.v.z, n * Q.v.w, n * Q.m.x, n * Q.m.y, n * Q.m.z, n * Q.m.w));
	}

	/// \brief Returns the product of the 3D motor $Q$ and the inverse of the scalar $n$.
	/// \related Motor3D

	inline Motor3D operator /(const Motor3D& Q, float n)
	{
		n = 1.0F / n;
		return (Motor3D(Q.v.x * n, Q.v.y * n, Q.v.z * n, Q.v.w * n, Q.m.x * n, Q.m.y * n, Q.m.z * n, Q.m.w * n));
	}

	/// \brief Returns a boolean value indicating whether the two 3D motors $a$ and $b$ are equal.
	/// \related Motor3D

	inline bool operator ==(const Motor3D& a, const Motor3D& b)
	{
		return ((a.v == b.v) && (a.m == b.m));
	}

	/// \brief Returns a boolean value indicating whether the two 3D motors $a$ and $b$ are not equal.
	/// \related Motor3D

	inline bool operator !=(const Motor3D& a, const Motor3D& b)
	{
		return ((a.v != b.v) || (a.m != b.m));
	}

	// ==============================================
	//	Multiplication
	// ==============================================

	/// \brief Returns the geometric antiproduct of the 3D motors $a$ and $b$.
	/// \related Motor3D

	TERATHON_API Motor3D operator *(const Motor3D& a, const Motor3D& b);

	/// \brief Returns the geometric antiproduct of the 3D motor $Q$ and the quaternion $r$.
	/// \related Motor3D

	TERATHON_API Motor3D operator *(const Motor3D& Q, const Quaternion& r);

	/// \brief Returns the geometric antiproduct of the quaternion $r$ and the 3D motor $Q$.
	/// \related Motor3D

	TERATHON_API Motor3D operator *(const Quaternion& r, const Motor3D& Q);

	// ==============================================
	//	Square root
	// ==============================================

	/// \brief Returns the square root of a 3D motor with respect to the geometric antiproduct.
	/// \related Motor3D

	TERATHON_API Motor3D Sqrt(const Motor3D& Q);

	// ==============================================
	//	Transformations
	// ==============================================

	/// \brief Transforms the 3D vector $v$ with the motor $Q$.
	/// \related Motor3D

	inline Vector3D Transform(const Vector3D& v, const Motor3D& Q)
	{
		return (Transform(v, Q.v));
	}

	/// \brief Transforms the 3D bivector $v$ with the motor $Q$.
	/// \related Motor3D

	inline Bivector3D Transform(const Bivector3D& v, const Motor3D& Q)
	{
		return (!Transform(!v, Q.v));
	}

	/// \brief Transforms the 3D flat point $p$ with the motor $Q$.
	/// \related Motor3D

	TERATHON_API FlatPoint3D Transform(const FlatPoint3D& p, const Motor3D& Q);

	/// \brief Transforms the 3D Euclidean point $p$ with the motor $Q$.
	/// \related Motor3D

	TERATHON_API Point3D Transform(const Point3D& p, const Motor3D& Q);

	/// \brief Transforms the 3D line $l$ with the motor $Q$.
	/// \related Motor3D

	TERATHON_API Line3D Transform(const Line3D& l, const Motor3D& Q);

	/// \brief Transforms the 3D plane $g$ with the motor $Q$.
	/// \related Motor3D

	TERATHON_API Plane3D Transform(const Plane3D& g, const Motor3D& Q);

	// ==============================================
	//	Reverses
	// ==============================================

	/// \brief Returns the reverse of the 3D motor $Q$.
	/// \related Motor3D

	inline Motor3D Reverse(const Motor3D& Q)
	{
		return (Motor3D(-Q.v.x, -Q.v.y, -Q.v.z, Q.v.w, -Q.m.x, -Q.m.y, -Q.m.z, Q.m.w));
	}

	/// \brief Returns the antireverse of the 3D motor $Q$.
	/// \related Motor3D

	inline Motor3D Antireverse(const Motor3D& Q)
	{
		return (Motor3D(-Q.v.x, -Q.v.y, -Q.v.z, Q.v.w, -Q.m.x, -Q.m.y, -Q.m.z, Q.m.w));
	}

	inline Motor3D operator ~(const Motor3D& Q) {return (Antireverse(Q));}

	// ==============================================
	//	Norms
	// ==============================================

	/// \brief Returns the squared bulk norm of the 3D motor $Q$.
	/// \related Motor3D

	inline float SquaredBulkNorm(const Motor3D& Q)
	{
		return (SquaredMag(Q.m));
	}

	/// \brief Returns the squared weight norm of the 3D motor $Q$.
	/// \related Motor3D

	inline float SquaredWeightNorm(const Motor3D& Q)
	{
		return (SquaredMag(Q.v));
	}

	/// \brief Calculates the unitized equivalent of a 3D motor.
	///
	/// The $Unitize()$ function multiplies a 3D motor by the inverse magnitude of its weight, which is the quaternion
	/// given by its <b>e</b><sub>41</sub>, <b>e</b><sub>42</sub>, <b>e</b><sub>43</sub>, and antiscalar coordinates.
	/// After calling this function, the rotor component of the motor is unit-length. If these coordinates are all zero,
	/// then the result is undefined.
	///
	/// \related Motor3D

	inline Motor3D Unitize(const Motor3D& Q)
	{
		return (Q * InverseMag(Q.v));
	}


	// ==============================================
	//	POD Structures
	// ==============================================

	struct ConstMotor3D
	{
		float	vx, vy, vz, vw;
		float	mx, my, mz, mw;

		operator const Motor3D&(void) const
		{
			return (reinterpret_cast<const Motor3D&>(*this));
		}

		const Motor3D *operator &(void) const
		{
			return (reinterpret_cast<const Motor3D *>(this));
		}

		const Motor3D *operator ->(void) const
		{
			return (reinterpret_cast<const Motor3D *>(this));
		}
	};
}


#endif
