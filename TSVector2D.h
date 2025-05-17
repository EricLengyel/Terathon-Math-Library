//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSVector2D_h
#define TSVector2D_h


/// \component	Math Library
/// \prefix		Math/


#include "TSAlgebra.h"


#define TERATHON_VECTOR2D 1
#define TERATHON_POINT2D 1


namespace Terathon
{
	class Vector2D;
	class Origin2D;
	struct ConstVector2D;


	// ==============================================
	//	Vector2D
	// ==============================================

	struct TypeVector2D
	{
		typedef float component_type;
		typedef Vector2D vector2D_type;
	};


	/// \brief Encapsulates a 2D vector.
	///
	/// The $Vector2D$ class is used to store a two-dimensional direction vector having floating-point
	/// components <i>x</i> and <i>y</i>. A direction vector stored in this class is assumed to have a
	/// <i>w</i> coordinate of 0 whenever it needs to be converted to a four-dimensional representation.
	/// Two-dimensional points (for which the <i>w</i> coordinate is 1) should be stored using the
	/// $Point2D$ class. The <i>z</i> coordinate of a 2D vector is always assumed to be 0.
	///
	/// \also Point2D
	/// \also Vector3D
	/// \also Vector4D

	class Vector2D : public Vec2D<TypeVector2D>
	{
		public:

			TERATHON_API static const ConstVector2D zero;

			TERATHON_API static const ConstVector2D x_unit;
			TERATHON_API static const ConstVector2D y_unit;

			TERATHON_API static const ConstVector2D minus_x_unit;
			TERATHON_API static const ConstVector2D minus_y_unit;

			/// \brief Default constructor that leaves the components uninitialized.

			inline Vector2D() = default;

			Vector2D(const Vector2D& v)
			{
				xy = v.xy;
			}

			/// \brief Constructor that sets components explicitly.
			/// \param a,b		The components of the vector.

			Vector2D(float a, float b) : Vec2D<TypeVector2D>(a, b) {}

			template <typename type>
			explicit Vector2D(const Vec2D<type>& v) : Vec2D<TypeVector2D>(float(v.x), float(v.y)) {}

			/// \brief Sets both components of a 2D vector.
			/// \param a,b		The new components of the vector.

			Vector2D& Set(float a, float b)
			{
				xy.Set(a, b);
				return (*this);
			}

			void Set(float a, float b) volatile
			{
				xy.Set(a, b);
			}

			Vector2D& operator =(const Vector2D& v)
			{
				xy = v.xy;
				return (*this);
			}

			void operator =(const Vector2D& v) volatile
			{
				xy = v.xy;
			}

			template <typename type_struct, int count, int index_x, int index_y>
			Vector2D& operator =(const Subvec2D<type_struct, count, index_x, index_y>& v)
			{
				xy = v;
				return (*this);
			}

			template <typename type_struct, int count, int index_x, int index_y>
			void operator =(const Subvec2D<type_struct, count, index_x, index_y>& v) volatile
			{
				xy = v;
			}

			template <typename type>
			Vector2D& operator =(const Vec2D<type>& v)
			{
				x = float(v.x);
				y = float(v.y);
				return (*this);
			}

			Vector2D& operator +=(const Vector2D& v)
			{
				xy += v.xy;
				return (*this);
			}

			template <typename type_struct, int count, int index_x, int index_y>
			Vector2D& operator +=(const Subvec2D<type_struct, count, index_x, index_y>& v)
			{
				xy += v;
				return (*this);
			}

			Vector2D& operator -=(const Vector2D& v)
			{
				xy -= v.xy;
				return (*this);
			}

			template <typename type_struct, int count, int index_x, int index_y>
			Vector2D& operator -=(const Subvec2D<type_struct, count, index_x, index_y>& v)
			{
				xy -= v;
				return (*this);
			}

			Vector2D& operator *=(const Vector2D& v)
			{
				xy *= v.xy;
				return (*this);
			}

			template <typename type_struct, int count, int index_x, int index_y>
			Vector2D& operator *=(const Subvec2D<type_struct, count, index_x, index_y>& v)
			{
				xy *= v;
				return (*this);
			}

			Vector2D& operator *=(float n)
			{
				xy *= n;
				return (*this);
			}

			Vector2D& operator /=(float n)
			{
				xy /= n;
				return (*this);
			}

			Vector2D& Normalize(void)
			{
				return (static_cast<Vector2D&>(xy.Normalize()));
			}

			/// \brief Rotates the vector in the <i>x</i>-<i>y</i> plane through the
			/// angle, in radians, given by the $angle$ parameter.

			TERATHON_API Vector2D& Rotate(float angle);
	};


	/// \brief Returns the negation of the 2D vector $v$.
	/// \related Vector2D

	inline Vector2D operator -(const Vector2D& v)
	{
		return (Vector2D(-v.x, -v.y));
	}

	inline Vector2D operator +(const Vector2D& a, const Vector2D& b)
	{
		return (Vector2D(a.x + b.x, a.y + b.y));
	}

	template <typename type_struct, int count, int index_x, int index_y>
	inline Vector2D operator +(const Vector2D& a, const Subvec2D<type_struct, count, index_x, index_y>& b)
	{
		return (Vector2D(a.x + b.data[index_x], a.y + b.data[index_y]));
	}

	inline Vector2D operator -(const Vector2D& a, const Vector2D& b)
	{
		return (Vector2D(a.x - b.x, a.y - b.y));
	}

	template <typename type_struct, int count, int index_x, int index_y>
	inline Vector2D operator -(const Vector2D& a, const Subvec2D<type_struct, count, index_x, index_y>& b)
	{
		return (Vector2D(a.x - b.data[index_x], a.y - b.data[index_y]));
	}

	/// \brief Returns the product of the 2D vector $v$ and the scalar $n$.
	/// \related Vector2D

	inline Vector2D operator *(const Vector2D& v, float n)
	{
		return (Vector2D(v.x * n, v.y * n));
	}

	/// \brief Returns the product of the 2D vector $v$ and the scalar $n$.
	/// \related Vector2D

	inline Vector2D operator *(float n, const Vector2D& v)
	{
		return (Vector2D(n * v.x, n * v.y));
	}

	/// \brief Returns the product of the 2D vector $v$ and the inverse of the scalar $n$.
	/// \related Vector2D

	inline Vector2D operator /(const Vector2D& v, float n)
	{
		n = 1.0F / n;
		return (Vector2D(v.x * n, v.y * n));
	}

	/// \brief Returns the componentwise product of the 2D vectors $a$ and $b$.
	/// \related Vector2D

	inline Vector2D operator *(const Vector2D& a, const Vector2D& b)
	{
		return (Vector2D(a.x * b.x, a.y * b.y));
	}


	// ==============================================
	//	Point2D
	// ==============================================

	/// \brief Encapsulates a 2D point.
	///
	/// The $Point2D$ class is used to store a two-dimensional point having floating-point
	/// coordinates <i>x</i> and <i>y</i>. The difference between a point and a vector is that
	/// a point is assumed to have a <i>w</i> coordinate of 1 whenever it needs to be converted
	/// to a four-dimensional representation, whereas a vector is assumed to have a <i>w</i>
	/// coordinate of 0. Such a conversion occurs when a vector or point is assigned to a
	/// $Vector4D$ object or is multiplied by a $Transform3D$ object.
	///
	/// \also Vector2D
	/// \also Vector3D
	/// \also Vector4D

	class Point2D : public Vector2D
	{
		public:

			TERATHON_API static const Origin2D origin;

			/// \brief Default constructor that leaves the components uninitialized.

			inline Point2D() = default;

			/// \brief Constructor that sets components explicitly.
			/// \param a,b		The components of the point.

			Point2D(float a, float b) : Vector2D(a, b) {}

			explicit Point2D(const Vector2D& p) : Vector2D(p) {}

			Point2D& operator =(const Vector2D& v)
			{
				xy = v.xy;
				return (*this);
			}

			void operator =(const Vector2D& v) volatile
			{
				xy = v.xy;
			}

			template <typename type>
			Point2D& operator =(const Vec2D<type>& v)
			{
				x = float(v.x);
				y = float(v.y);
				return (*this);
			}

			Point2D& operator +=(const Vector2D& v)
			{
				xy += v.xy;
				return (*this);
			}

			Point2D& operator -=(const Vector2D& v)
			{
				xy -= v.xy;
				return (*this);
			}

			Point2D& operator *=(const Vector2D& v)
			{
				xy *= v.xy;
				return (*this);
			}

			Point2D& operator *=(float n)
			{
				xy *= n;
				return (*this);
			}

			Point2D& operator /=(float n)
			{
				xy /= n;
				return (*this);
			}
	};


	/// \brief Returns the negation of the 2D point $p$.
	/// \related Point2D

	inline Point2D operator -(const Point2D& p)
	{
		return (Point2D(-p.x, -p.y));
	}

	inline Point2D operator +(const Point2D& a, const Point2D& b)
	{
		return (Point2D(a.x + b.x, a.y + b.y));
	}

	inline Point2D operator +(const Point2D& p, const Vector2D& v)
	{
		return (Point2D(p.x + v.x, p.y + v.y));
	}

	inline Point2D operator +(const Vector2D& v, const Point2D& p)
	{
		return (Point2D(v.x + p.x, v.y + p.y));
	}

	template <typename type_struct, int count, int index_x, int index_y>
	inline Point2D operator +(const Point2D& p, const Subvec2D<type_struct, count, index_x, index_y>& v)
	{
		return (Point2D(p.x + v.data[index_x], p.y + v.data[index_y]));
	}

	inline Vector2D operator -(const Point2D& a, const Point2D& b)
	{
		return (Vector2D(a.x - b.x, a.y - b.y));
	}

	inline Point2D operator -(const Point2D& p, const Vector2D& v)
	{
		return (Point2D(p.x - v.x, p.y - v.y));
	}

	template <typename type_struct, int count, int index_x, int index_y>
	inline Point2D operator -(const Point2D& p, const Subvec2D<type_struct, count, index_x, index_y>& v)
	{
		return (Point2D(p.x - v.data[index_x], p.y - v.data[index_y]));
	}

	/// \brief Returns the product of the 2D point $p$ and the scalar $n$.
	/// \related Point2D

	inline Point2D operator *(const Point2D& p, float n)
	{
		return (Point2D(p.x * n, p.y * n));
	}

	/// \brief Returns the product of the 2D point $p$ and the scalar $n$.
	/// \related Point2D

	inline Point2D operator *(float n, const Point2D& p)
	{
		return (Point2D(n * p.x, n * p.y));
	}

	/// \brief Returns the product of the 2D point $p$ and the inverse of the scalar $n$.
	/// \related Point2D

	inline Point2D operator /(const Point2D& p, float n)
	{
		n = 1.0F / n;
		return (Point2D(p.x * n, p.y * n));
	}

	/// \brief Returns the componentwise product of the 2D points $a$ and $b$.
	/// \related Point2D

	inline Point2D operator *(const Point2D& a, const Point2D& b)
	{
		return (Point2D(a.x * b.x, a.y * b.y));
	}

	inline Point2D operator *(const Point2D& p, const Vector2D& v)
	{
		return (Point2D(p.x * v.x, p.y * v.y));
	}

	inline Point2D operator *(const Vector2D& v, const Point2D& p)
	{
		return (Point2D(v.x * p.x, v.y * p.y));
	}


	// ==============================================
	//	Magnitude
	// ==============================================

	/// \brief Returns the magnitude of the 2D vector $v$.
	/// \related Vector2D

	inline float Magnitude(const Vector2D& v)
	{
		return (Sqrt(v.x * v.x + v.y * v.y));
	}

	/// \brief Returns the inverse magnitude of the 2D vector $v$.
	/// \related Vector2D

	inline float InverseMag(const Vector2D& v)
	{
		return (InverseSqrt(v.x * v.x + v.y * v.y));
	}

	/// \brief Returns the squared magnitude of the 2D vector $v$.
	/// \related Vector2D

	inline float SquaredMag(const Vector2D& v)
	{
		return (v.x * v.x + v.y * v.y);
	}

	/// \brief Calculates the normalized version of the 2D vector $v$.
	///
	/// Multiplies the 2D vector $v$ by the inverse of its magnitude. The return value is a vector
	/// having unit length that points in the same direction as $v$. If the magnitude of $v$ is zero,
	/// then the result is undefined.
	///
	/// \related Vector2D

	inline Vector2D Normalize(const Vector2D& v)
	{
		return (v * InverseMag(v));
	}

	// ==============================================
	//	Dot
	// ==============================================

	/// \brief Calculates the dot product of the 2D vectors $a$ and $b$.
	/// \related Vector2D

	inline float Dot(const Vector2D& a, const Vector2D& b)
	{
		return (a.x * b.x + a.y * b.y);
	}

	inline float Dot(const Point2D& a, const Point2D& b)
	{
		return (a.x * b.x + a.y * b.y);
	}

	inline float Dot(const Point2D& p, const Vector2D& v)
	{
		return (p.x * v.x + p.y * v.y);
	}

	inline float Dot(const Vector2D& v, const Point2D& p)
	{
		return (v.x * p.x + v.y * p.y);
	}

	// ==============================================
	//	Projection
	// ==============================================

	/// \brief Returns (<b>a</b>&#x202F;&sdot;&#x202F;<b>b</b>)<b>b</b>, which is the projection of $a$ onto $b$ under the assumption that the magnitude of $b$ is one.
	/// \related Vector2D

	inline Vector2D Project(const Vector2D& a, const Vector2D& b)
	{
		return (b * Dot(a, b));
	}

	/// \brief Returns <b>a</b>&#x202F;&minus;&#x202F;(<b>a</b>&#x202F;&sdot;&#x202F;<b>b</b>)<b>b</b>, which is the rejection of $a$ from $b$ under the assumption that the magnitude of $b$ is one.
	/// \related Vector2D

	inline Vector2D Reject(const Vector2D& a, const Vector2D& b)
	{
		return (a - b * Dot(a, b));
	}

	// ==============================================
	//	Floor / ceiling
	// ==============================================

	/// \brief Returns the componentwise floor of the 2D vector $v$.
	/// \related Vector2D

	inline Vector2D Floor(const Vector2D& v)
	{
		return (Vector2D(Floor(v.x), Floor(v.y)));
	}

	/// \brief Returns the componentwise ceiling of the 2D vector $v$.
	/// \related Vector2D

	inline Vector2D Ceil(const Vector2D& v)
	{
		return (Vector2D(Ceil(v.x), Ceil(v.y)));
	}

	// ==============================================
	//	Complement
	// ==============================================

	/// \brief Calculates the complement of the 2D vector $v$ with respect to the volume element <b>e</b><sub>12</sub>.
	/// \related Vector2D

	inline Vector2D Complement(const Vector2D& v)
	{
		return (Vector2D(-v.y, v.x));
	}

	inline Vector2D operator !(const Vector2D& v) {return (Complement(v));}

	// ==============================================
	//	Wedge
	// ==============================================

	/// \brief Calculates the antiwedge product of the 2D vectors $a$ and $b$.
	/// \related Vector2D

	inline float Antiwedge(const Vector2D& a, const Vector2D& b)
	{
		return (a.x * b.y - a.y * b.x);
	}

	inline float operator ^(const Vector2D& a, const Vector2D& b) {return (Antiwedge(a, b));}


	// ==============================================
	//	POD Structures
	// ==============================================

	struct ConstVector2D
	{
		float	x, y;

		operator const Vector2D&(void) const
		{
			return (reinterpret_cast<const Vector2D&>(*this));
		}

		const Vector2D *operator &(void) const
		{
			return (reinterpret_cast<const Vector2D *>(this));
		}

		const Vector2D *operator ->(void) const
		{
			return (reinterpret_cast<const Vector2D *>(this));
		}
	};


	struct ConstPoint2D
	{
		float	x, y;

		operator const Point2D&(void) const
		{
			return (reinterpret_cast<const Point2D&>(*this));
		}

		const Point2D *operator &(void) const
		{
			return (reinterpret_cast<const Point2D *>(this));
		}

		const Point2D *operator ->(void) const
		{
			return (reinterpret_cast<const Point2D *>(this));
		}
	};


	class Origin2D
	{
		private:

			TERATHON_API static const ConstPoint2D origin;

		public:

			operator const Point2D&(void) const
			{
				return (origin);
			}

			const Point2D *operator &(void) const
			{
				return (&origin);
			}
	};


	inline const Point2D& operator +(const Origin2D&, const Vector2D& v)
	{
		return (static_cast<const Point2D&>(v));
	}

	template <typename type_struct, int count, int index_x, int index_y>
	inline Point2D operator +(const Origin2D&, const Subvec2D<type_struct, count, index_x, index_y>& v)
	{
		return (Point2D(v.data[index_x], v.data[index_y]));
	}

	template <typename type_struct, int count>
	inline const Point2D& operator +(const Origin2D&, const Subvec2D<type_struct, count, 0, 1>& v)
	{
		return (reinterpret_cast<const Point2D&>(v.data[0]));
	}

	template <typename type_struct, int count>
	inline const Point2D& operator +(const Origin2D&, const Subvec2D<type_struct, count, 1, 2>& v)
	{
		return (reinterpret_cast<const Point2D&>(v.data[1]));
	}

	template <typename type_struct, int count>
	inline const Point2D& operator +(const Origin2D&, const Subvec2D<type_struct, count, 2, 3>& v)
	{
		return (reinterpret_cast<const Point2D&>(v.data[2]));
	}

	inline Point2D operator -(const Origin2D&, const Vector2D& v)
	{
		return (Point2D(-v.x, -v.y));
	}

	template <typename type_struct, int count, int index_x, int index_y>
	inline Point2D operator -(const Origin2D&, const Subvec2D<type_struct, count, index_x, index_y>& v)
	{
		return (Point2D(-v.data[index_x], -v.data[index_y]));
	}


	namespace Math
	{
		inline const Vector2D *GetTrigTable(void)
		{
			return (reinterpret_cast<const Vector2D *>(Math::trigTable));
		}
	}

	inline Vector2D CosSin(float x)
	{
		Vector2D	v;

		CosSin(x, &v.x, &v.y);
		return (v);
	}
}


#endif
