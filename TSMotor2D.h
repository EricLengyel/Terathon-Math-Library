//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSMotor2D_h
#define TSMotor2D_h


#include "TSRigid2D.h"
#include "TSMatrix3D.h"


#define TERATHON_MOTOR2D 1


namespace Terathon
{
	struct ConstMotor2D;


	// ==============================================
	//	Motor2D
	// ==============================================

	/// \brief Encapsulates a 2D motion operator (motor) in rigid geometric algebra.
	///
	/// The $Motor2D$ class encapsulates a 2D motion operator (motor).
	/// It has the general form <i>Q<sub>x</sub></i><b>e</b><sub>1</sub> + <i>Q<sub>y</sub></i><b>e</b><sub>2</sub> + <i>Q<sub>z</sub></i><b>e</b><sub>3</sub> + <i>Q<sub>w</sub></i>&#x1D7D9;.
	///
	/// \also Flector2D

	class Motor2D
	{
		public:

			float		x, y, z, w;

			TERATHON_API static const ConstMotor2D identity;

			/// \brief Default constructor that leaves the components uninitialized.

			inline Motor2D() = default;

			Motor2D(const Motor2D& Q)
			{
				x = Q.x;
				y = Q.y;
				z = Q.z;
				w = Q.w;
			}

			/// \brief Constructor that sets components explicitly.
			/// \param a,b,c,d		The values of the <b>e</b><sub>1</sub>, <b>e</b><sub>2</sub>, <b>e</b><sub>3</sub>, and antiscalar coordinates.

			Motor2D(float a, float b, float c, float d)
			{
				x = a;
				y = b;
				z = c;
				w = d;
			}

			/// \brief Sets all four components of a 2D motor.
			/// \param a,b,c,d		The values of the <b>e</b><sub>1</sub>, <b>e</b><sub>2</sub>, <b>e</b><sub>3</sub>, and antiscalar coordinates.

			Motor2D& Set(float a, float b, float c, float d)
			{
				x = a;
				y = b;
				z = c;
				w = d;
				return (*this);
			}

			void Set(float a, float b, float c, float d) volatile
			{
				x = a;
				y = b;
				z = c;
				w = d;
			}

			Motor2D& operator =(const Motor2D& Q)
			{
				x = Q.x;
				y = Q.y;
				z = Q.z;
				w = Q.w;
				return (*this);
			}

			void operator =(const Motor2D& Q) volatile
			{
				x = Q.x;
				y = Q.y;
				z = Q.z;
				w = Q.w;
			}

			Motor2D& operator +=(const Motor2D& Q)
			{
				x += Q.x;
				y += Q.y;
				z += Q.z;
				w += Q.w;
				return (*this);
			}

			Motor2D& operator -=(const Motor2D& Q)
			{
				x -= Q.x;
				y -= Q.y;
				z -= Q.z;
				w -= Q.w;
				return (*this);
			}

			Motor2D& operator *=(float n)
			{
				x *= n;
				y *= n;
				z *= n;
				w *= n;
				return (*this);
			}

			Motor2D& operator /=(float n)
			{
				n = 1.0F / n;
				x *= n;
				y *= n;
				z *= n;
				w *= n;
				return (*this);
			}

			/// \brief Unitizes the weight of a 2D motor.
			///
			/// The $Unitize()$ function multiplies a motor by the inverse magnitude of its weight, which is made up of its
			/// <b>e</b><sub>3</sub> and antiscalar coordinates.

			Motor2D& Unitize(void)
			{
				return (*this *= InverseSqrt(z * z + w * w));
			}

			/// \brief Returns a 2D motor that represents a rotation about a given center.
			/// \param angle	The angle of rotation, in radians.
			/// \param center	The center about which to rotate.
			///
			/// The $MakeRotation()$ function returns a motor representing a rotation through the angle
			/// given by the $angle$ parameter about the center given by the $center$ parameter.
			/// The resulting motor is unitized.

			static Motor2D MakeRotation(float angle, const Point2D& center)
			{
				Vector2D t = CosSin(angle * 0.5F);
				return (Motor2D(center.x * t.y, center.y * t.y, t.y, t.x));
			}

			/// \brief Returns a 2D motor that represents a translation.
			/// \param offset	The offset vector.
			///
			/// The $MakeTranslation()$ function returns a motor representing a translation by the
			/// direction and magnitude given by the $offset$ parameter.

			static Motor2D MakeTranslation(const Vector2D& offset)
			{
				return (Motor2D(offset.y * -0.5F, offset.x * 0.5F, 0.0F, 1.0F));
			}

			/// \brief Returns the direction to which the <i>x</i> axis is transformed by a 2D motor.
			///
			/// The $GetDirectionX()$ function calculates the 2D vector that results from transforming the direction vector
			/// (1,&nbsp;0) with the motor for which it is called.

			TERATHON_API Vector2D GetDirectionX(void) const;

			/// \brief Returns the direction to which the <i>y</i> axis is transformed by a 2D motor.
			///
			/// The $GetDirectionY()$ function calculates the 2D vector that results from transforming the direction vector
			/// (0,&nbsp;1) with the motor for which it is called.

			TERATHON_API Vector2D GetDirectionY(void) const;

			/// \brief Returns the position to which the origin is transformed by a 2D motor.
			///
			/// The $GetPosition()$ function calculates the 2D point that results from transforming the origin
			/// with the motor for which it is called.

			TERATHON_API Point2D GetPosition(void) const;

			/// \brief Converts a 2D motor to its corresponding 3&#x202F;&times;&#x202F;3 matrix.
			///
			/// The $GetTransformMatrix()$ function converts a motor to the Transform2D object that
			/// represents the same transformation when it premultiplies a Vector2D or Point2D object.

			TERATHON_API Transform2D GetTransformMatrix(void) const;

			/// \brief Converts a 2D motor to the inverse of its corresponding 3&#x202F;&times;&#x202F;3 matrix.
			///
			/// The $GetInverseTransformMatrix()$ function converts a motor to the inverse of the Transform2D object that
			/// represents the same transformation when it premultiplies a Vector2D or Point2D object. Such a matrix
			/// correctly transforms a Line2D object when it postmultiplies it.
			///
			/// This function performs the same amount of computation as the Motor2D::GetTransformMatrix() function, and is thus
			/// significantly faster than calling the Motor2D::GetTransformMatrix() function and inverting the result.

			TERATHON_API Transform2D GetInverseTransformMatrix(void) const;

			/// \brief Converts a 2D motor to its corresponding 3&#x202F;&times;&#x202F;3 matrix and its inverse simultaneously.
			/// \param M		A pointer to the location where the transform matrix is returned.
			/// \param Minv		A pointer to the location where the inverse transform matrix is returned.
			///
			/// The $GetTransformMatrices()$ function converts a motor to the Transform2D object that represents the same
			/// transformation when it premultiplies a Vector2D or Point2D object and stores it in the location specified
			/// by the $M$ parameter. The inverse of this matrix is stored in the location specified by the $Minv$ parameter.
			///
			/// Calling this function is much faster than making separate calls to the Motor2D::GetTransformMatrix() and
			/// Motor2D::GetInverseTransformMatrix() functions.

			TERATHON_API void GetTransformMatrices(Transform2D *M, Transform2D *Minv) const;

			/// \brief Converts a 3&#x202F;&times;&#x202F;3 matrix to its corresponding 2D motor.
			/// \param M	The matrix to convert to a motor.
			///
			/// The $SetTransformMatrix()$ function sets the components of a motor to values that represent
			/// the same rigid motion as the one represented by the matrix specified by the $M$ parameter.
			///
			/// This function expects the matrix $M$ to have a determinant of +1, and it expects the upper-left 2&#x202F;&times;&#x202F;2
			/// portion of the matrix to be orthogonal. If these conditions are not met, then the results are unlikely to be meaningful.

			TERATHON_API Motor2D& SetTransformMatrix(const Transform2D& M);
	};


	/// \brief Returns the negation of the 2D motor $Q$.
	/// \related Motor2D

	inline Motor2D operator -(const Motor2D& Q)
	{
		return (Motor2D(-Q.x, -Q.y, -Q.z, -Q.w));
	}

	/// \brief Returns the product of the 2D motor $Q$ and the scalar $n$.
	/// \related Motor2D

	inline Motor2D operator *(const Motor2D& Q, float n)
	{
		return (Motor2D(Q.x * n, Q.y * n, Q.z * n, Q.w * n));
	}

	/// \brief Returns the product of the 2D motor $Q$ and the scalar $n$.
	/// \related Motor2D

	inline Motor2D operator *(float n, const Motor2D& Q)
	{
		return (Motor2D(n * Q.x, n * Q.y, n * Q.z, n * Q.w));
	}

	/// \brief Returns the product of the 2D motor $Q$ and the inverse of the scalar $n$.
	/// \related Motor2D

	inline Motor2D operator /(const Motor2D& Q, float n)
	{
		n = 1.0F / n;
		return (Motor2D(Q.x * n, Q.y * n, Q.z * n, Q.w * n));
	}

	/// \brief Returns a boolean value indicating whether the two 2D motors $a$ and $b$ are equal.
	/// \related Motor2D

	inline bool operator ==(const Motor2D& a, const Motor2D& b)
	{
		return ((a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w));
	}

	/// \brief Returns a boolean value indicating whether the two 2D motors $a$ and $b$ are not equal.
	/// \related Motor2D

	inline bool operator !=(const Motor2D& a, const Motor2D& b)
	{
		return ((a.x != b.x) || (a.y != b.y) || (a.z != b.z) || (a.w != b.w));
	}

	// ==============================================
	//	Multiplication
	// ==============================================

	/// \brief Returns the geometric antiproduct of the 3D motors $a$ and $b$.
	/// \related Motor3D

	TERATHON_API Motor2D operator *(const Motor2D& a, const Motor2D& b);

	// ==============================================
	//	Transformations
	// ==============================================

	/// \brief Transforms the 2D vector $v$ with the motor $Q$.
	/// \related Motor2D

	TERATHON_API Vector2D Transform(const Vector2D& v, const Motor2D& Q);

	/// \brief Transforms the 2D flat point $p$ with the motor $Q$.
	/// \related Motor2D

	TERATHON_API FlatPoint2D Transform(const FlatPoint2D& p, const Motor2D& Q);

	/// \brief Transforms the 2D Euclidean point $p$ with the motor $Q$.
	/// \related Motor2D

	TERATHON_API Point2D Transform(const Point2D& p, const Motor2D& Q);

	/// \brief Transforms the 2D line $g$ with the motor $Q$.
	/// \related Motor2D

	TERATHON_API Line2D Transform(const Line2D& g, const Motor2D& Q);

	// ==============================================
	//	Reverses
	// ==============================================

	/// \brief Returns the reverse of the 2D motor $Q$.
	/// \related Motor2D

	inline Motor2D Reverse(const Motor2D& Q)
	{
		return (Motor2D(Q.x, Q.y, Q.z, -Q.w));
	}

	/// \brief Returns the antireverse of the 2D motor $Q$.
	/// \related Motor2D

	inline Motor2D Antireverse(const Motor2D& Q)
	{
		return (Motor2D(-Q.x, -Q.y, -Q.z, Q.w));
	}

	inline Motor2D operator ~(const Motor2D& Q) {return (Antireverse(Q));}

	// ==============================================
	//	Norms
	// ==============================================

	/// \brief Returns the squared bulk norm of the 2D motor $Q$.
	/// \related Motor2D

	inline float SquaredBulkNorm(const Motor2D& Q)
	{
		return (Q.x * Q.x + Q.y * Q.y);
	}

	/// \brief Returns the squared weight norm of the 2D motor $Q$.
	/// \related Motor2D

	inline float SquaredWeightNorm(const Motor2D& Q)
	{
		return (Q.z * Q.z + Q.w * Q.w);
	}

	/// \brief Calculates the unitized equivalent of a 2D motor.
	///
	/// The $Unitize()$ function multiplies a 2D motor by the inverse magnitude of its weight, which is made up of its
	/// <b>e</b><sub>3</sub> and antiscalar coordinates.
	///
	/// \related Motor2D

	inline Motor2D Unitize(const Motor2D& Q)
	{
		return (Q * InverseSqrt(Q.z * Q.z + Q.w * Q.w));
	}


	// ==============================================
	//	POD Structures
	// ==============================================

	struct ConstMotor2D
	{
		float	x, y, z, w;

		operator const Motor2D&(void) const
		{
			return (reinterpret_cast<const Motor2D&>(*this));
		}

		const Motor2D *operator &(void) const
		{
			return (reinterpret_cast<const Motor2D *>(this));
		}

		const Motor2D *operator ->(void) const
		{
			return (reinterpret_cast<const Motor2D *>(this));
		}
	};
}


#endif
