//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSFlector3D_h
#define TSFlector3D_h


#include "TSMotor3D.h"


#define TERATHON_FLECTOR3D 1


namespace Terathon
{
	struct ConstFlector3D;


	// ==============================================
	//	Flector3D
	// ==============================================

	/// \brief Encapsulates a 3D <a href="https://rigidgeometricalgebra.org/wiki/index.php?title=Flector">reflection operator (flector)</a> in rigid geometric algebra.
	///
	/// The $Flector3D$ class encapsulates a 3D reflection operator (flector).
	/// It has the general form <i>F<sub>px</sub></i><b>e</b><sub>1</sub> + <i>F<sub>py</sub></i><b>e</b><sub>2</sub> + <i>F<sub>pz</sub></i><b>e</b><sub>3</sub> + <i>F<sub>pw</sub></i><b>e</b><sub>4</sub> + <i>F<sub>gx</sub></i><b>e</b><sub>234</sub> + <i>F<sub>gy</sub></i><b>e</b><sub>314</sub> + <i>F<sub>gz</sub></i><b>e</b><sub>124</sub> + <i>F<sub>gw</sub></i><b>e</b><sub>321</sub>.
	///
	/// \also Motor3D

	class Flector3D
	{
		public:

			FlatPoint3D		p;		///< The coordinates of the point components using basis elements <b>e</b><sub>1</sub>, <b>e</b><sub>2</sub>, <b>e</b><sub>3</sub>, and <b>e</b><sub>4</sub> coordinates.
			Plane3D			g;		///< The coordinates of the plane components using basis elements <b>e</b><sub>423</sub>, <b>e</b><sub>431</sub>, <b>e</b><sub>412</sub>, and <b>e</b><sub>321</sub> coordinates.

			/// \brief Default constructor that leaves the components uninitialized.

			inline Flector3D() = default;

			Flector3D(const Flector3D& F)
			{
				p = F.p;
				g = F.g;
			}

			/// \brief Constructor that sets components explicitly.
			/// \param px,py,pz,pw		The values of the <b>e</b><sub>1</sub>, <b>e</b><sub>2</sub>, <b>e</b><sub>3</sub>, and <b>e</b><sub>4</sub> coordinates.
			/// \param gx,gy,gz,gw		The values of the <b>e</b><sub>423</sub>, <b>e</b><sub>431</sub>, <b>e</b><sub>412</sub>, and <b>e</b><sub>321</sub> coordinates.

			Flector3D(float px, float py, float pz, float pw, float gx, float gy, float gz, float gw)
			{
				p.Set(px, py, pz, pw);
				g.Set(gx, gy, gz, gw);
			}

			Flector3D(const Vector4D& point, const Plane3D& plane)
			{
				p = point;
				g = plane;
			}

			Flector3D(const Point3D& point, const Plane3D& plane)
			{
				p = point;
				g = plane;
			}

			explicit Flector3D(const Vector4D& point)
			{
				p = point;
				g.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			explicit Flector3D(const Point3D& point)
			{
				p = point;
				g.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			explicit Flector3D(const Plane3D& plane)
			{
				g = plane;
				p.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			/// \brief Sets all eight components of a 3D flector.
			/// \param px,py,pz,pw		The values of the <b>e</b><sub>1</sub>, <b>e</b><sub>2</sub>, <b>e</b><sub>3</sub>, and <b>e</b><sub>4</sub> coordinates.
			/// \param gx,gy,gz,gw		The values of the <b>e</b><sub>423</sub>, <b>e</b><sub>431</sub>, <b>e</b><sub>412</sub>, and <b>e</b><sub>321</sub> coordinates.

			Flector3D& Set(float px, float py, float pz, float pw, float gx, float gy, float gz, float gw)
			{
				p.Set(px, py, pz, pw);
				g.Set(gx, gy, gz, gw);
				return (*this);
			}

			void Set(float px, float py, float pz, float pw, float gx, float gy, float gz, float gw) volatile
			{
				p.Set(px, py, pz, pw);
				g.Set(gx, gy, gz, gw);
			}

			Flector3D& Set(const Vector4D& point, const Plane3D& plane)
			{
				p = point;
				g = plane;
				return (*this);
			}

			void Set(const Vector4D& point, const Plane3D& plane) volatile
			{
				p = point;
				g = plane;
			}

			Flector3D& Set(const Point3D& point, const Plane3D& plane)
			{
				p = point;
				g = plane;
				return (*this);
			}

			void Set(const Point3D& point, const Plane3D& plane) volatile
			{
				p = point;
				g = plane;
			}

			Flector3D& operator =(const Flector3D& F)
			{
				p = F.p;
				g = F.g;
				return (*this);
			}

			void operator =(const Flector3D& F) volatile
			{
				p = F.p;
				g = F.g;
			}

			Flector3D& operator =(const Vector4D& point)
			{
				p = point;
				g.Set(0.0F, 0.0F, 0.0F, 0.0F);
				return (*this);
			}

			void operator =(const Vector4D& point) volatile
			{
				p = point;
				g.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			Flector3D& operator =(const Point3D& point)
			{
				p = point;
				g.Set(0.0F, 0.0F, 0.0F, 0.0F);
				return (*this);
			}

			void operator =(const Point3D& point) volatile
			{
				p = point;
				g.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			Flector3D& operator =(const Plane3D& plane)
			{
				g = plane;
				p.Set(0.0F, 0.0F, 0.0F, 0.0F);
				return (*this);
			}

			void operator =(const Plane3D& plane) volatile
			{
				g = plane;
				p.Set(0.0F, 0.0F, 0.0F, 0.0F);
			}

			Flector3D& operator *=(float n)
			{
				p *= n;
				g *= n;
				return (*this);
			}

			Flector3D& operator /=(float n)
			{
				n = 1.0F / n;
				p *= n;
				g *= n;
				return (*this);
			}

			/// \brief Unitizes the weight of a 3D flector.
			///
			/// The $Unitize()$ function multiplies a flector by the inverse magnitude of its weight, which is made up of its
			/// <b>e</b><sub>4</sub>, <b>e</b><sub>423</sub>, <b>e</b><sub>431</sub>, and <b>e</b><sub>412</sub> coordinates.
			/// If these coordinates are all zero, then the result is undefined.

			Flector3D& Unitize(void)
			{
				return (*this *= InverseSqrt(p.w * p.w + g.x * g.x + g.y * g.y + g.z * g.z));
			}

			/// \brief Returns a 3D flector that represents a translation and reflection.
			/// \param offset	The translation vector.
			/// \param plane	The unitized reflection plane.
			///
			/// The $MakeTransflection()$ function returns a flector representing a translation by the vector given
			/// by the $offset$ parameter and a reflection through the plane given by the $plane$ parameter.
			/// The resulting flector is unitized.

			static Flector3D MakeTransflection(const Vector3D& offset, const Plane3D& plane)
			{
				return (Flector3D((offset.y * plane.z - offset.z * plane.y) * 0.5F, (offset.z * plane.x - offset.x * plane.z) * 0.5F, (offset.x * plane.y - offset.y * plane.x) * 0.5F, 0.0F, plane.x, plane.y, plane.z, plane.w - (offset.x * plane.x + offset.y * plane.y + offset.z * plane.z) * 0.5F));
			}

			/// \brief Returns a 3D flector that represents a rotation and reflection.
			/// \param angle	The angle of rotation, in radians.
			/// \param axis		The unitized line about which to rotate.
			/// \param plane	The unitized reflection plane.
			///
			/// The $MakeRotoreflection()$ function returns a flector representing a rotation through the angle
			/// given by the $angle$ parameter about the line given by the $axis$ parameter and a reflection
			/// across the plane given by the $plane$ parameter.

			static Flector3D MakeRotoreflection(float angle, const Line3D& axis, const Plane3D& plane)
			{
				Vector2D t = CosSin(angle * 0.5F);
				float vx = axis.v.x * t.y;
				float vy = axis.v.y * t.y;
				float vz = axis.v.z * t.y;
				float mx = axis.m.x * t.y;
				float my = axis.m.y * t.y;
				float mz = axis.m.z * t.y;

				return (Flector3D(vx * plane.w + my * plane.z - mz * plane.y,
				                  vy * plane.w + mz * plane.x - mx * plane.z,
				                  vz * plane.w + mx * plane.y - my * plane.x,
				                 -vx * plane.x - vy * plane.y - vz * plane.z,
				                  t.x * plane.x + vy * plane.z - vz * plane.y,
				                  t.x * plane.y + vz * plane.x - vx * plane.z,
				                  t.x * plane.z + vx * plane.y - vy * plane.x,
				                  t.x * plane.w - mx * plane.x - my * plane.y - mz * plane.z));
			}

			static Flector3D MakeRotoreflection(float angle, const Bivector3D& axis, const Plane3D& plane)
			{
				Vector2D t = CosSin(angle * 0.5F);
				float vx = axis.x * t.y;
				float vy = axis.y * t.y;
				float vz = axis.z * t.y;
				return (Flector3D(vx * plane.w, vy * plane.w, vz * plane.w, -vx * plane.x - vy * plane.y - vz * plane.z, t.x * plane.x + vy * plane.z - vz * plane.y, t.x * plane.y + vz * plane.x - vx * plane.z, t.x * plane.z + vx * plane.y - vy * plane.x, t.x * plane.w));
			}

			/// \brief Converts a 3D flector to its corresponding 4&#x202F;&times;&#x202F;4 matrix.
			///
			/// The $GetTransformMatrix()$ function converts a flector to the Transform3D object that
			/// represents the same transformation when it premultiplies a Vector3D or Point3D object.

			TERATHON_API Transform3D GetTransformMatrix(void) const;

			/// \brief Converts a 3D flector to the inverse of its corresponding 4&#x202F;&times;&#x202F;4 matrix.
			///
			/// The $GetInverseTransformMatrix()$ function converts a flector to the inverse of the Transform3D object that
			/// represents the same transformation when it premultiplies a Vector3D or Point3D object. Such a matrix
			/// correctly transforms a Plane3D object when it postmultiplies it.
			///
			/// This function performs the same amount of computation as the Flector3D::GetTransformMatrix() function, and is thus
			/// significantly faster than calling the Flector3D::GetTransformMatrix() function and inverting the result.

			TERATHON_API Transform3D GetInverseTransformMatrix(void) const;

			/// \brief Converts a 3D flector to its corresponding 4&#x202F;&times;&#x202F;4 matrix and its inverse simultaneously.
			/// \param M		A pointer to the location where the transform matrix is returned.
			/// \param Minv		A pointer to the location where the inverse transform matrix is returned.
			///
			/// The $GetTransformMatrices()$ function converts a flector to the Transform3D object that represents the same
			/// transformation when it premultiplies a Vector3D or Point3D object and stores it in the location specified
			/// by the $M$ parameter. The inverse of this matrix is stored in the location specified by the $Minv$ parameter.
			///
			/// Calling this function is much faster than making separate calls to the Flector3D::GetTransformMatrix() and
			/// Flector3D::GetInverseTransformMatrix() functions.

			TERATHON_API void GetTransformMatrices(Transform3D *M, Transform3D *Minv) const;

			/// \brief Converts a 4&#x202F;&times;&#x202F;4 matrix to its corresponding 3D flector.
			/// \param M	The matrix to convert to a flector.
			///
			/// The $SetTransformMatrix()$ function sets the components of a flector to values that represent
			/// the same rigid motion as the one represented by the matrix specified by the $M$ parameter.
			///
			/// This function expects the matrix $M$ to have a determinant of &minus;1, and it expects the upper-left 3&#x202F;&times;&#x202F;3
			/// portion of the matrix to be orthogonal. If these conditions are not met, then the results are unlikely to be meaningful.

			TERATHON_API Flector3D& SetTransformMatrix(const Transform3D& M);
	};


	/// \brief Returns the negation of the 3D flector $f$.
	/// \related Flector3D

	inline Flector3D operator -(const Flector3D& F)
	{
		return (Flector3D(-F.p.x, -F.p.y, -F.p.z, -F.p.w, -F.g.x, -F.g.y, -F.g.z, -F.g.w));
	}

	/// \brief Returns the product of the 3D flector $f$ and the scalar $n$.
	/// \related Flector3D

	inline Flector3D operator *(const Flector3D& F, float n)
	{
		return (Flector3D(F.p.x * n, F.p.y * n, F.p.z * n, F.p.w * n, F.g.x * n, F.g.y * n, F.g.z * n, F.g.w * n));
	}

	/// \brief Returns the product of the 3D flector $f$ and the scalar $n$.
	/// \related Flector3D

	inline Flector3D operator *(float n, const Flector3D& F)
	{
		return (Flector3D(n * F.p.x, n * F.p.y, n * F.p.z, n * F.p.w, n * F.g.x, n * F.g.y, n * F.g.z, n * F.g.w));
	}

	/// \brief Returns the product of the 3D flector $f$ and the inverse of the scalar $n$.
	/// \related Flector3D

	inline Flector3D operator /(const Flector3D& F, float n)
	{
		n = 1.0F / n;
		return (Flector3D(F.p.x * n, F.p.y * n, F.p.z * n, F.p.w * n, F.g.x * n, F.g.y * n, F.g.z * n, F.g.w * n));
	}

	/// \brief Returns a boolean value indicating whether the two 3D flectors $a$ and $b$ are equal.
	/// \related Flector3D

	inline bool operator ==(const Flector3D& a, const Flector3D& b)
	{
		return ((a.p == b.p) && (a.g == b.g));
	}

	/// \brief Returns a boolean value indicating whether the two 3D flectors $a$ and $b$ are not equal.
	/// \related Flector3D

	inline bool operator !=(const Flector3D& a, const Flector3D& b)
	{
		return ((a.p != b.p) || (a.g != b.g));
	}

	// ==============================================
	//	Multiplication
	// ==============================================

	/// \brief Returns the geometric antiproduct of the 3D flectors $a$ and $b$.
	/// \related Flector3D

	TERATHON_API Motor3D operator *(const Flector3D& a, const Flector3D& b);

	/// \brief Returns the geometric antiproduct of the 3D flector $a$ and the 3D motor $b$.
	/// \related Flector3D

	TERATHON_API Flector3D operator *(const Flector3D& a, const Motor3D& b);

	/// \brief Returns the geometric antiproduct of the 3D motor $a$ and the 3D flector $b$.
	/// \related Flector3D

	TERATHON_API Flector3D operator *(const Motor3D& a, const Flector3D& b);

	/// \brief Returns the geometric antiproduct of the 3D flector $f$ and the quaternion $r$.
	/// \related Flector3D

	TERATHON_API Flector3D operator *(const Flector3D& F, const Quaternion& r);

	/// \brief Returns the geometric antiproduct of the quaternion $r$ and the 3D flector $f$.
	/// \related Flector3D

	TERATHON_API Flector3D operator *(const Quaternion& r, const Flector3D& F);

	// ==============================================
	//	Transformations
	// ==============================================

	/// \brief Transforms the 3D vector $v$ with the flector $f$.
	/// \related Flector3D

	TERATHON_API Vector3D Transform(const Vector3D& v, const Flector3D& F);

	/// \brief Transforms the 3D flat point $q$ with the flector $f$.
	/// \related Flector3D

	TERATHON_API FlatPoint3D Transform(const FlatPoint3D& q, const Flector3D& F);

	/// \brief Transforms the 3D Euclidean point $q$ with the flector $f$.
	/// \related Flector3D

	TERATHON_API Point3D Transform(const Point3D& q, const Flector3D& F);

	/// \brief Transforms the 3D line $l$ with the flector $f$.
	/// \related Flector3D

	TERATHON_API Line3D Transform(const Line3D& l, const Flector3D& F);

	/// \brief Transforms the 3D plane $h$ with the flector $f$.
	/// \related Flector3D

	TERATHON_API Plane3D Transform(const Plane3D& h, const Flector3D& F);

	/// \brief Transforms the 3D bivector $v$ with the flector $f$.
	/// \related Flector3D

	inline Bivector3D Transform(const Bivector3D& v, const Flector3D& F)
	{
		return (!Transform(!v, F));
	}

	// ==============================================
	//	Reverses
	// ==============================================

	/// \brief Returns the reverse of the 3D flector $f$.
	/// \related Flector3D

	inline Flector3D Reverse(const Flector3D& F)
	{
		return (Flector3D(-F.p.x, -F.p.y, -F.p.z, -F.p.w, F.g.x, F.g.y, F.g.z, F.g.w));
	}

	/// \brief Returns the antireverse of the 3D flector $f$.
	/// \related Flector3D

	inline Flector3D Antireverse(const Flector3D& F)
	{
		return (Flector3D(-F.p.x, -F.p.y, -F.p.z, -F.p.w, F.g.x, F.g.y, F.g.z, F.g.w));
	}

	inline Flector3D operator ~(const Flector3D& F) {return (Antireverse(F));}

	// ==============================================
	//	Norms
	// ==============================================

	/// \brief Returns the squared bulk norm of the 3D flector $f$.
	/// \related Flector3D

	inline float SquaredBulkNorm(const Flector3D& F)
	{
		return (F.p.x * F.p.x + F.p.y * F.p.y + F.p.z * F.p.z + F.g.w * F.g.w);
	}

	/// \brief Returns the squared weight norm of the 3D flector $f$.
	/// \related Flector3D

	inline float SquaredWeightNorm(const Flector3D& F)
	{
		return (F.p.w * F.p.w + F.g.x * F.g.x + F.g.y * F.g.y + F.g.z * F.g.z);
	}

	/// \brief Calculates the unitized equivalent of a 3D flector.
	///
	/// The $Unitize()$ function multiplies a 3D flector by the inverse magnitude of its weight, which is made up of its
	/// <b>e</b><sub>4</sub>, <b>e</b><sub>423</sub>, <b>e</b><sub>431</sub>, and <b>e</b><sub>412</sub> coordinates.
	/// If these coordinates are all zero, then the result is undefined.
	///
	/// \related Flector3D

	inline Flector3D Unitize(const Flector3D& F)
	{
		return (F * InverseSqrt(F.p.w * F.p.w + F.g.x * F.g.x + F.g.y * F.g.y + F.g.z * F.g.z));
	}


	// ==============================================
	//	POD Structures
	// ==============================================

	struct ConstFlector3D
	{
		float	px, py, pz, pw;
		float	gx, gy, gz, gw;

		operator const Flector3D&(void) const
		{
			return (reinterpret_cast<const Flector3D&>(*this));
		}

		const Flector3D *operator &(void) const
		{
			return (reinterpret_cast<const Flector3D *>(this));
		}

		const Flector3D *operator ->(void) const
		{
			return (reinterpret_cast<const Flector3D *>(this));
		}
	};
}


#endif
