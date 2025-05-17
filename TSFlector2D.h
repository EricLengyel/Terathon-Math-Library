//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSFlector2D_h
#define TSFlector2D_h


#include "TSMotor2D.h"


#define TERATHON_FLECTOR2D 1


namespace Terathon
{
	struct ConstFlector2D;


	// ==============================================
	//	Flector2D
	// ==============================================

	/// \brief Encapsulates a 2D reflection operator (flector) in rigid geometric algebra.
	///
	/// The $Flector2D$ class encapsulates a 2D reflection operator (flector).
	/// It has the general form <i>F<sub>x</sub></i><b>e</b><sub>23</sub> + <i>F<sub>y</sub></i><b>e</b><sub>31</sub> + <i>F<sub>z</sub></i><b>e</b><sub>12</sub> + <i>F<sub>w</sub></i><b>1</b>.
	///
	/// \also Motor2D

	class Flector2D
	{
		public:

			float		x, y, z, w;

			/// \brief Default constructor that leaves the components uninitialized.

			inline Flector2D() = default;

			Flector2D(const Flector2D& F)
			{
				x = F.x;
				y = F.y;
				z = F.z;
				w = F.w;
			}

			/// \brief Constructor that sets components explicitly.
			/// \param a,b,c,d		The values of the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, <b>e</b><sub>12</sub>, and scalar coordinates.

			Flector2D(float a, float b, float c, float d)
			{
				x = a;
				y = b;
				z = c;
				w = d;
			}

			/// \brief Sets all four components of a 3D flector.
			/// \param a,b,c,d		The values of the <b>e</b><sub>23</sub>, <b>e</b><sub>31</sub>, <b>e</b><sub>12</sub>, and scalar coordinates.

			Flector2D& Set(float a, float b, float c, float d)
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

			Flector2D& operator =(const Flector2D& F)
			{
				x = F.x;
				y = F.y;
				z = F.z;
				w = F.w;
				return (*this);
			}

			void operator =(const Flector2D& F) volatile
			{
				x = F.x;
				y = F.y;
				z = F.z;
				w = F.w;
			}

			Flector2D& operator *=(float n)
			{
				x *= n;
				y *= n;
				z *= n;
				w *= n;
				return (*this);
			}

			Flector2D& operator /=(float n)
			{
				n = 1.0F / n;
				x *= n;
				y *= n;
				z *= n;
				w *= n;
				return (*this);
			}

			/// \brief Unitizes the weight of a 2D flector.
			///
			/// The $Unitize()$ function multiplies a flector by the inverse magnitude of its weight, which is made up of its
			/// <b>e</b><sub>23</sub> and <b>e</b><sub>31</sub> coordinates. If these coordinates are all zero, then the result is undefined.

			Flector2D& Unitize(void)
			{
				return (*this *= InverseSqrt(x * x + y * y));
			}

			/// \brief Returns a 2D flector that represents a translation and reflection.
			/// \param offset	The translation vector.
			/// \param line		The unitized reflection line.
			///
			/// The $MakeTransflection()$ function returns a flector representing a translation by the vector given
			/// by the $offset$ parameter and a reflection through the line given by the $line$ parameter.
			/// The resulting flector is unitized.

			static Flector2D MakeTransflection(const Vector2D& offset, const Line2D& line)
			{
				return (Flector2D(line.x, line.y, (offset.x * line.x + offset.y * line.y) * 0.5F + line.z, (offset.y * line.x - offset.x * line.y) * 0.5F));
			}

			/// \brief Converts a 2D flector to its corresponding 3&#x202F;&times;&#x202F;3 matrix.
			///
			/// The $GetTransformMatrix()$ function converts a flector to the Transform2D object that
			/// represents the same transformation when it premultiplies a Vector2D or Point2D object.

			TERATHON_API Transform2D GetTransformMatrix(void) const;

			/// \brief Converts a 2D flector to the inverse of its corresponding 3&#x202F;&times;&#x202F;3 matrix.
			///
			/// The $GetInverseTransformMatrix()$ function converts a flector to the inverse of the Transform2D object that
			/// represents the same transformation when it premultiplies a Vector2D or Point2D object. Such a matrix
			/// correctly transforms a Line2D object when it postmultiplies it.
			///
			/// This function performs the same amount of computation as the Flector2D::GetTransformMatrix() function, and is thus
			/// significantly faster than calling the Flector2D::GetTransformMatrix() function and inverting the result.

			TERATHON_API Transform2D GetInverseTransformMatrix(void) const;

			/// \brief Converts a 2D flector to its corresponding 3&#x202F;&times;&#x202F;3 matrix and its inverse simultaneously.
			/// \param M		A pointer to the location where the transform matrix is returned.
			/// \param Minv		A pointer to the location where the inverse transform matrix is returned.
			///
			/// The $GetTransformMatrices()$ function converts a flector to the Transform2D object that represents the same
			/// transformation when it premultiplies a Vector2D or Point2D object and stores it in the location specified
			/// by the $M$ parameter. The inverse of this matrix is stored in the location specified by the $Minv$ parameter.
			///
			/// Calling this function is much faster than making separate calls to the Flector2D::GetTransformMatrix() and
			/// Flector2D::GetInverseTransformMatrix() functions.

			TERATHON_API void GetTransformMatrices(Transform2D *M, Transform2D *Minv) const;

			/// \brief Converts a 3&#x202F;&times;&#x202F;3 matrix to its corresponding 2D flector.
			/// \param M	The matrix to convert to a flector.
			///
			/// The $SetTransformMatrix()$ function sets the components of a flector to values that represent
			/// the same rigid motion as the one represented by the matrix specified by the $M$ parameter.
			///
			/// This function expects the matrix $M$ to have a determinant of &minus;1, and it expects the upper-left 2&#x202F;&times;&#x202F;2
			/// portion of the matrix to be orthogonal. If these conditions are not met, then the results are unlikely to be meaningful.

			TERATHON_API Flector2D& SetTransformMatrix(const Transform2D& M);
	};


	/// \brief Returns the negation of the 2D flector $f$.
	/// \related Flector2D

	inline Flector2D operator -(const Flector2D& F)
	{
		return (Flector2D(-F.x, -F.y, -F.z, -F.w));
	}

	/// \brief Returns the product of the 2D flector $f$ and the scalar $n$.
	/// \related Flector2D

	inline Flector2D operator *(const Flector2D& F, float n)
	{
		return (Flector2D(F.x * n, F.y * n, F.z * n, F.w * n));
	}

	/// \brief Returns the product of the 2D flector $f$ and the scalar $n$.
	/// \related Flector2D

	inline Flector2D operator *(float n, const Flector2D& F)
	{
		return (Flector2D(n * F.x, n * F.y, n * F.z, n * F.w));
	}

	/// \brief Returns the product of the 2D flector $f$ and the inverse of the scalar $n$.
	/// \related Flector2D

	inline Flector2D operator /(const Flector2D& F, float n)
	{
		n = 1.0F / n;
		return (Flector2D(F.x * n, F.y * n, F.z * n, F.w * n));
	}

	/// \brief Returns a boolean value indicating whether the two 2D flectors $a$ and $b$ are equal.
	/// \related Flector2D

	inline bool operator ==(const Flector2D& a, const Flector2D& b)
	{
		return ((a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w));
	}

	/// \brief Returns a boolean value indicating whether the two 2D flectors $a$ and $b$ are not equal.
	/// \related Flector2D

	inline bool operator !=(const Flector2D& a, const Flector2D& b)
	{
		return ((a.x != b.x) || (a.y != b.y) || (a.z != b.z) || (a.w != b.w));
	}

	// ==============================================
	//	Multiplication
	// ==============================================

	/// \brief Returns the geometric antiproduct of the 2D flectors $a$ and $b$.
	/// \related Flector2D

	TERATHON_API Motor2D operator *(const Flector2D& a, const Flector2D& b);

	/// \brief Returns the geometric antiproduct of the 2D flector $a$ and the 2D motor $b$.
	/// \related Flector2D

	TERATHON_API Flector2D operator *(const Flector2D& a, const Motor2D& b);

	/// \brief Returns the geometric antiproduct of the 2D motor $a$ and the 2D flector $b$.
	/// \related Flector2D

	TERATHON_API Flector2D operator *(const Motor2D& a, const Flector2D& b);

	// ==============================================
	//	Transformations
	// ==============================================

	/// \brief Transforms the 2D vector $v$ with the flector $f$.
	/// \related Flector2D

	TERATHON_API Vector2D Transform(const Vector2D& v, const Flector2D& F);

	/// \brief Transforms the 2D flat point $q$ with the flector $f$.
	/// \related Flector2D

	TERATHON_API FlatPoint2D Transform(const FlatPoint2D& q, const Flector2D& F);

	/// \brief Transforms the 2D Euclidean point $q$ with the flector $f$.
	/// \related Flector2D

	TERATHON_API Point2D Transform(const Point2D& q, const Flector2D& F);

	/// \brief Transforms the 2D line $h$ with the flector $f$.
	/// \related Flector2D

	TERATHON_API Line2D Transform(const Line2D& h, const Flector2D& F);

	// ==============================================
	//	Reverses
	// ==============================================

	/// \brief Returns the reverse of the 2D flector $f$.
	/// \related Flector2D

	inline Flector2D Reverse(const Flector2D& F)
	{
		return (Flector2D(-F.x, -F.y, -F.z, F.w));
	}

	/// \brief Returns the antireverse of the 2D flector $f$.
	/// \related Flector2D

	inline Flector2D Antireverse(const Flector2D& F)
	{
		return (Flector2D(F.x, F.y, F.z, -F.w));
	}

	inline Flector2D operator ~(const Flector2D& F) {return (Antireverse(F));}

	// ==============================================
	//	Norms
	// ==============================================

	/// \brief Returns the squared bulk norm of the 2D flector $f$.
	/// \related Flector2D

	inline float SquaredBulkNorm(const Flector2D& F)
	{
		return (F.z * F.z + F.w * F.w);
	}

	/// \brief Returns the squared weight norm of the 2D flector $f$.
	/// \related Flector2D

	inline float SquaredWeightNorm(const Flector2D& F)
	{
		return (F.x * F.x + F.y * F.y);
	}

	/// \brief Calculates the unitized equivalent of a 2D flector.
	///
	/// The $Unitize()$ function multiplies a 3D flector by the inverse magnitude of its weight, which is made up of its
	/// <b>e</b><sub>23</sub> and <b>e</b><sub>31</sub> coordinates. If these coordinates are all zero, then the result is undefined.
	///
	/// \related Flector2D

	inline Flector2D Unitize(const Flector2D& F)
	{
		return (F * InverseSqrt(F.x * F.x + F.y * F.y));
	}


	// ==============================================
	//	POD Structures
	// ==============================================

	struct ConstFlector2D
	{
		float	x, y, z, w;

		operator const Flector2D&(void) const
		{
			return (reinterpret_cast<const Flector2D&>(*this));
		}

		const Flector2D *operator &(void) const
		{
			return (reinterpret_cast<const Flector2D *>(this));
		}

		const Flector2D *operator ->(void) const
		{
			return (reinterpret_cast<const Flector2D *>(this));
		}
	};
}


#endif
