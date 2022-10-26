//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2022, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSVector2D_h
#define TSVector2D_h


//# \component	Math Library
//# \prefix		Math/


#include "TSAlgebra.h"


#define TERATHON_VECTOR2D 1
#define TERATHON_POINT2D 1


namespace Terathon
{
	class Vector2D;
	class Origin2D;
	struct ConstVector2D;


	//# \class	Vector2D	Encapsulates a 2D vector.
	//
	//# The $Vector2D$ class encapsulates a 2D vector.
	//
	//# \def	class Vector2D : public Vec2D<TypeVector2D>
	//
	//# \ctor	Vector2D();
	//# \ctor	Vector2D(float a, float b);
	//# \ctor	template <typename type> explicit Vector2D(const Vec2D<type>& v);
	//
	//# \param	a	The value of the <i>x</i> coordinate.
	//# \param	b	The value of the <i>y</i> coordinate.
	//# \param	v	Another 2D vector, possibly with a different component type, that is converted to a $Vector2D$.
	//
	//# \desc
	//# The $Vector2D$ class is used to store a two-dimensional direction vector
	//# having floating-point components <i>x</i> and <i>y</i>. A direction vector
	//# stored in this class is assumed to have a <i>w</i> coordinate of 0 whenever it needs
	//# to be converted to a four-dimensional representation. Two-dimensional points
	//# (for which the <i>w</i> coordinate is 1) should be stored using the $@Point2D@$ class.
	//# The <i>z</i> coordinate of a 2D vector is always assumed to be 0.
	//#
	//# The default constructor leaves the components of the vector undefined.
	//# If the values $a$ and $b$ are supplied, then they are assigned to the
	//# <i>x</i> and <i>y</i> coordinates of the vector, respectively.
	//
	//# \operator	float& operator [](machine k);
	//#				Returns a reference to the $k$-th scalar component of a vector.
	//#				The value of $k$ must be 0 or 1.
	//
	//# \operator	const float& operator [](machine k) const;
	//#				Returns a constant reference to the $k$-th scalar component of a vector.
	//#				The value of $k$ must be 0 or 1.
	//
	//# \operator	Vector2D& operator +=(const Vector2D& v);
	//#				Adds the vector $v$.
	//
	//# \operator	Vector2D& operator -=(const Vector2D& v);
	//#				Subtracts the vector $v$.
	//
	//# \operator	Vector2D& operator *=(const Vector2D& v);
	//#				Calculates the componentwise product with the vector $v$.
	//
	//# \operator	Vector2D& operator *=(float s);
	//#				Multiplies by the scalar $s$.
	//
	//# \operator	Vector2D& operator /=(float s);
	//#				Divides by the scalar $s$.
	//
	//# \action		bool operator ==(const Vector2D& v1, const Vector2D& v2) const;
	//#				Returns a boolean value indicating whether the two vectors $v1$ and $v2$ are equal.
	//
	//# \action		bool operator !=(const Vector2D& v1, const Vector2D& v2) const;
	//#				Returns a boolean value indicating whether the two vectors $v1$ and $v2$ are not equal.
	//
	//# \action		Vector2D operator -(const Vector2D& v) const;
	//#				Returns the negation of the vector $v$.
	//
	//# \action		Vector2D operator +(const Vector2D& a, const Vector2D& b) const;
	//#				Returns the sum of the vectors $a$ and $b$.
	//
	//# \action		Vector2D operator -(const Vector2D& a, const Vector2D& b) const;
	//#				Returns the difference of the vectors $a$ and $b$.
	//
	//# \action		Vector2D operator *(const Vector2D& v, float s) const;
	//#				Returns the product of the vector $v$ and the scalar $s$.
	//
	//# \action		Vector2D operator *(float s, const Vector2D& v);
	//#				Returns the product of the vector $v$ and the scalar $s$.
	//
	//# \action		Vector2D operator /(const Vector2D& v, float s) const;
	//#				Returns the product of the vector $v$ and the inverse of the scalar $s$.
	//
	//# \action		Vector2D operator *(const Vector2D& a, const Vector2D& b) const;
	//#				Returns the componentwise product of the vectors $a$ and $b$.
	//
	//# \action		float Magnitude(const Vector2D& v);
	//#				Returns the magnitude of the vector $v$.
	//
	//# \action		float InverseMag(const Vector2D& v);
	//#				Returns the inverse magnitude of the vector $v$.
	//
	//# \action		float SquaredMag(const Vector2D& v);
	//#				Returns the squared magnitude of the vector $v$.
	//
	//# \action		float Dot(const Vector2D& a, const Vector2D& b);
	//#				Returns the dot product between $a$ and $b$.
	//
	//# \action		Vector2D Project(const Vector2D& a, const Vector2D& b);
	//#				Returns (<b>a</b>&#x202F;&sdot;&#x202F;<b>b</b>)<b>b</b>, which is the projection of $a$ onto $b$ under the assumption that the magnitude of $b$ is one.
	//
	//# \action		Vector2D Reject(const Vector2D& a, const Vector2D& b);
	//#				Returns (<b>a</b>&#x202F;&minus;&#x202F;<b>a</b>&#x202F;&sdot;&#x202F;<b>b</b>)<b>b</b>, which is the rejection of $a$ from $b$ under the assumption that the magnitude of $b$ is one.
	//
	//# \privbase	Vec2D	Vectors use a generic base class to store their components.
	//
	//# \also	$@Point2D@$
	//# \also	$@Vector4D@$


	//# \function	Vector2D::Set		Sets both components of a vector.
	//
	//# \proto	Vector2D& Set(float a, float b);
	//
	//# \param	a	The new <i>x</i> coordinate.
	//# \param	b	The new <i>y</i> coordinate.
	//
	//# \desc
	//# The $Set$ function sets the <i>x</i> and <i>y</i> coordinates of a vector to
	//# the values given by the $a$ and $b$ parameters, respectively.
	//#
	//# The return value is a reference to the vector object.


	//# \function	Vector2D::Normalize		Normalizes a 2D vector.
	//
	//# \proto	Vector2D& Normalize(void);
	//
	//# \desc
	//# The $Normalize$ function multiplies a 2D vector by the inverse of its magnitude,
	//# normalizing it to unit length. Normalizing the zero vector produces undefined results.
	//#
	//# The return value is a reference to the vector object.


	//# \function	Vector2D::Rotate		Rotates a vector in the <i>x</i>-<i>y</i> plane.
	//
	//# \proto	Vector2D& Rotate(float angle);
	//
	//# \param	angle	The angle through which the vector is rotated, in radians.
	//
	//# \desc
	//# The $Rotate$ function rotates a vector in the <i>x</i>-<i>y</i> plane through the
	//# angle given by the $angle$ parameter.
	//#
	//# The return value is a reference to the vector object.


	struct TypeVector2D
	{
		typedef float component_type;
		typedef Vector2D vector2D_type;
	};


	class Vector2D : public Vec2D<TypeVector2D>
	{
		public:

			TERATHON_API static const ConstVector2D zero;

			TERATHON_API static const ConstVector2D x_unit;
			TERATHON_API static const ConstVector2D y_unit;

			TERATHON_API static const ConstVector2D minus_x_unit;
			TERATHON_API static const ConstVector2D minus_y_unit;

			inline Vector2D() = default;

			Vector2D(float a, float b) : Vec2D<TypeVector2D>(a, b) {}

			template <typename type>
			explicit Vector2D(const Vec2D<type>& v) : Vec2D<TypeVector2D>(float(v.x), float(v.y)) {}

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

			Vector2D& operator *=(float s)
			{
				xy *= s;
				return (*this);
			}

			Vector2D& operator /=(float s)
			{
				xy /= s;
				return (*this);
			}

			Vector2D& Normalize(void)
			{
				return (static_cast<Vector2D&>(xy.Normalize()));
			}

			TERATHON_API Vector2D& Rotate(float angle);
	};


	inline Vector2D operator !(const Vector2D& v)
	{
		return (Vector2D(-v.y, v.x));
	}

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

	inline Vector2D operator *(const Vector2D& v, float s)
	{
		return (Vector2D(v.x * s, v.y * s));
	}

	inline Vector2D operator *(float s, const Vector2D& v)
	{
		return (Vector2D(s * v.x, s * v.y));
	}

	inline Vector2D operator /(const Vector2D& v, float s)
	{
		s = 1.0F / s;
		return (Vector2D(v.x * s, v.y * s));
	}

	inline Vector2D operator *(const Vector2D& a, const Vector2D& b)
	{
		return (Vector2D(a.x * b.x, a.y * b.y));
	}

	inline float operator ^(const Vector2D& a, const Vector2D& b)
	{
		return (a.x * b.y - a.y * b.x);
	}

	inline Vector2D Complement(const Vector2D& v)
	{
		return (!v);
	}

	inline float Magnitude(const Vector2D& v)
	{
		return (Sqrt(v.x * v.x + v.y * v.y));
	}

	inline float InverseMag(const Vector2D& v)
	{
		return (InverseSqrt(v.x * v.x + v.y * v.y));
	}

	inline float SquaredMag(const Vector2D& v)
	{
		return (v.x * v.x + v.y * v.y);
	}

	inline Vector2D Normalize(const Vector2D& v)
	{
		return (v * InverseMag(v));
	}

	inline float Antiwedge(const Vector2D& a, const Vector2D& b)
	{
		return (a.x * b.y - a.y * b.x);
	}

	inline float Dot(const Vector2D& a, const Vector2D& b)
	{
		return (a.x * b.x + a.y * b.y);
	}

	inline Vector2D Project(const Vector2D& a, const Vector2D& b)
	{
		return (b * Dot(a, b));
	}

	inline Vector2D Reject(const Vector2D& a, const Vector2D& b)
	{
		return (a - b * Dot(a, b));
	}

	inline Vector2D Floor(const Vector2D& v)
	{
		return (Vector2D(Floor(v.x), Floor(v.y)));
	}

	inline Vector2D Ceil(const Vector2D& v)
	{
		return (Vector2D(Ceil(v.x), Ceil(v.y)));
	}


	//# \class	Point2D		Encapsulates a 2D point.
	//
	//# The $Point2D$ class encapsulates a 2D point.
	//
	//# \def	class Point2D : public Vector2D
	//
	//# \ctor	Point2D();
	//# \ctor	Point2D(float a, float b);
	//
	//# \param	a	The value of the <i>x</i> coordinate.
	//# \param	b	The value of the <i>y</i> coordinate.
	//
	//# \desc
	//# The $Point2D$ class is used to store a two-dimensional point having floating-point
	//# coordinates <i>x</i> and <i>y</i>. The difference between a point and a
	//# vector is that a point is assumed to have a <i>w</i> coordinate of 1 whenever it
	//# needs to be converted to a four-dimensional representation, whereas a vector is
	//# assumed to have a <i>w</i> coordinate of 0. Such a conversion occurs when a vector or
	//# point is assigned to a $@Vector4D@$ object or is multiplied by a $@Transform4D@$ object.
	//#
	//# The default constructor leaves the components of the vector undefined.
	//# If the values $a$ and $b$ are supplied, then they are assigned to the
	//# <i>x</i> and <i>y</i> coordinates of the base vector object, respectively.
	//#
	//# The difference between two points produces a direction vector. A two-dimensional
	//# direction vector is converted to a point by adding it to the identifier $Zero2D$.
	//
	//# \operator	Point2D& operator *=(float s);
	//#				Multiplies by the scalar $s$.
	//
	//# \operator	Point2D& operator /=(float s);
	//#				Divides by the scalar $s$.
	//
	//# \action		Point2D operator -(const Point2D& p);
	//#				Returns the negation of the point $p$.
	//
	//# \action		Point2D operator +(const Point2D& a, const Point2D& b);
	//#				Returns the sum of the points $a$ and $b$.
	//
	//# \action		Point2D operator +(const Point2D& p, const Vector2D& v);
	//#				Returns the sum of the point $p$ and the vector $v$.
	//
	//# \action		Point2D operator -(const Point2D& p, const Vector2D& v);
	//#				Returns the difference of the point $p$ and the vector $v$.
	//
	//# \action		Vector2D operator -(const Point2D& a, const Point2D& b);
	//#				Returns the difference of the points $a$ and $b$.
	//
	//# \action		Point2D operator *(const Point2D& p, float s);
	//#				Returns the product of the point $p$ and the scalar $s$.
	//
	//# \action		Point2D operator *(float s, const Point2D& p);
	//#				Returns the product of the point $p$ and the scalar $s$.
	//
	//# \action		Point2D operator /(const Point2D& p, float s) const;
	//#				Returns the product of the point $p$ and the inverse of the scalar $s$.
	//
	//# \action		Point2D operator *(const Point2D& a, const Point2D& b);
	//#				Returns the componentwise product of the points $a$ and $b$.
	//
	//# \action		Point2D operator *(const Point2D& p, const Vector2D& v);
	//#				Returns the componentwise product of the point $p$ and the vector $v$.
	//
	//# \action		Point2D operator *(const Vector2D& v, const Point2D& p);
	//#				Returns the componentwise product of the vector $v$ and the point $p$.
	//
	//# \base	Vector2D	A $Point2D$ object behaves much like a $@Vector2D@$ object, but some
	//#						properties are altered.
	//
	//# \also	$@Vector2D@$
	//# \also	$@Vector4D@$


	class Point2D : public Vector2D
	{
		public:

			TERATHON_API static const Origin2D origin;

			inline Point2D() = default;

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

			Point2D& operator *=(float s)
			{
				xy *= s;
				return (*this);
			}

			Point2D& operator /=(float s)
			{
				xy /= s;
				return (*this);
			}
	};


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

	inline Point2D operator *(const Point2D& p, float s)
	{
		return (Point2D(p.x * s, p.y * s));
	}

	inline Point2D operator *(float s, const Point2D& p)
	{
		return (Point2D(s * p.x, s * p.y));
	}

	inline Point2D operator /(const Point2D& p, float s)
	{
		s = 1.0F / s;
		return (Point2D(p.x * s, p.y * s));
	}

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


	struct ConstVector2D
	{
		float	x;
		float	y;

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
		float	x;
		float	y;

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
