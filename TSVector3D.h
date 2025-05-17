//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSVector3D_h
#define TSVector3D_h


#include "TSVector2D.h"


#define TERATHON_VECTOR3D 1
#define TERATHON_POINT3D 1


namespace Terathon
{
	class Vector3D;
	class Bivector3D;
	class Origin3D;
	struct ConstVector3D;


	// ==============================================
	//	Vector3D
	// ==============================================

	struct TypeVector3D
	{
		typedef float component_type;
		typedef Vector2D vector2D_type;
		typedef Vector3D vector3D_type;
	};


	/// \brief Encapsulates a 3D vector.
	///
	/// The $Vector3D$ class is used to store a three-dimensional direction vector having floating-point
	/// components <i>x</i>, <i>y</i>, and <i>z</i>. A direction vector stored in this class is assumed to
	/// have a <i>w</i> coordinate of 0 whenever it needs to be converted to a four-dimensional representation.
	/// Three-dimensional points (for which the <i>w</i> coordinate is 1) should be stored using the $Point3D$ class.
	///
	/// \also Point3D
	/// \also Vector2D
	/// \also Vector4D

	class Vector3D : public Vec3D<TypeVector3D>
	{
		public:

			TERATHON_API static const ConstVector3D zero;

			TERATHON_API static const ConstVector3D x_unit;
			TERATHON_API static const ConstVector3D y_unit;
			TERATHON_API static const ConstVector3D z_unit;

			TERATHON_API static const ConstVector3D minus_x_unit;
			TERATHON_API static const ConstVector3D minus_y_unit;
			TERATHON_API static const ConstVector3D minus_z_unit;

			/// \brief Default constructor that leaves the components uninitialized.

			inline Vector3D() = default;

			Vector3D(const Vector3D& v)
			{
				xyz = v.xyz;
			}

			/// \brief Constructor that sets components explicitly.
			/// \param a,b,c	The components of the vector.

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

			/// \brief Sets all three components of a 3D vector.
			/// \param a,b,c	The new components of the vector.

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

			Point2D& GetPoint2D(void)
			{
				Vector2D& v = xy;
				return (static_cast<Point2D&>(v));
			}

			const Point2D& GetPoint2D(void) const
			{
				const Vector2D& v = xy;
				return (static_cast<const Point2D&>(v));
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

			Vector3D& operator *=(float n)
			{
				xyz *= n;
				return (*this);
			}

			Vector3D& operator /=(float n)
			{
				xyz /= n;
				return (*this);
			}

			Vector3D& Normalize(void)
			{
				return (static_cast<Vector3D&>(xyz.Normalize()));
			}

			Vector3D& Unitize(void)
			{
				xy /= z;
				z = 1.0F;
				return (*this);
			}

			/// \brief Rotates the vector about the <i>x</i> axis through the
			/// angle, in radians, given by the $angle$ parameter.

			TERATHON_API Vector3D& RotateAboutX(float angle);

			/// \brief Rotates the vector about the <i>y</i> axis through the
			/// angle, in radians, given by the $angle$ parameter.

			TERATHON_API Vector3D& RotateAboutY(float angle);

			/// \brief Rotates the vector about the <i>z</i> axis through the
			/// angle, in radians, given by the $angle$ parameter.

			TERATHON_API Vector3D& RotateAboutZ(float angle);

			/// \brief Rotates the vector about the axis given by the $axis$ parameter
			/// through the angle, in radians, given by the $angle$ parameter.

			TERATHON_API Vector3D& RotateAboutAxis(float angle, const Bivector3D& axis);
	};


	/// \brief Returns the negation of the 3D vector $v$.
	/// \related Vector3D

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

	/// \brief Returns the product of the 3D vector $v$ and the scalar $n$.
	/// \related Vector3D

	inline Vector3D operator *(const Vector3D& v, float n)
	{
		return (Vector3D(v.x * n, v.y * n, v.z * n));
	}

	/// \brief Returns the product of the 3D vector $v$ and the scalar $n$.
	/// \related Vector3D

	inline Vector3D operator *(float n, const Vector3D& v)
	{
		return (Vector3D(n * v.x, n * v.y, n * v.z));
	}

	/// \brief Returns the product of the 3D vector $v$ and the inverse of the scalar $n$.
	/// \related Vector3D

	inline Vector3D operator /(const Vector3D& v, float n)
	{
		n = 1.0F / n;
		return (Vector3D(v.x * n, v.y * n, v.z * n));
	}

	/// \brief Returns the componentwise product of the 3D vectors $a$ and $b$.
	/// \related Vector3D

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


	// ==============================================
	//	Point3D
	// ==============================================

	/// \brief Encapsulates a 3D point.
	///
	/// The $Point3D$ class is used to store a three-dimensional point having floating-point
	/// coordinates <i>x</i>, <i>y</i>, and <i>z</i>. The difference between a point and a vector
	/// is that a point is assumed to have a <i>w</i> coordinate of 1 whenever it needs to be
	/// converted to a four-dimensional representation, whereas a vector is assumed to have a
	/// <i>w</i> coordinate of 0. Such a conversion occurs when a vector or point is assigned
	/// to a $Vector4D$ object or is multiplied by a $Transform3D$ object.
	///
	/// \also Vector2D
	/// \also Vector3D
	/// \also Vector4D

	class Point3D : public Vector3D
	{
		public:

			TERATHON_API static const Origin3D origin;

			/// \brief Default constructor that leaves the components uninitialized.

			inline Point3D() = default;

			/// \brief Constructor that sets components explicitly.
			/// \param a,b,c	The components of the point.

			Point3D(float a, float b, float c) : Vector3D(a, b, c) {}

			Point3D(const Vector2D& v) : Vector3D(v) {}
			Point3D(const Vector2D& v, float c) : Vector3D(v, c) {}
			explicit Point3D(const Vector3D& p) : Vector3D(p) {}

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

			Point3D& operator *=(float n)
			{
				xyz *= n;
				return (*this);
			}

			Point3D& operator /=(float n)
			{
				xyz /= n;
				return (*this);
			}
	};


	/// \brief Returns the negation of the 3D point $p$.
	/// \related Point3D

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

	/// \brief Returns the product of the 3D point $p$ and the scalar $n$.
	/// \related Point3D

	inline Point3D operator *(const Point3D& p, float n)
	{
		return (Point3D(p.x * n, p.y * n, p.z * n));
	}

	/// \brief Returns the product of the 3D point $p$ and the scalar $n$.
	/// \related Point3D

	inline Point3D operator *(float n, const Point3D& p)
	{
		return (Point3D(n * p.x, n * p.y, n * p.z));
	}

	/// \brief Returns the product of the 3D point $p$ and the inverse of the scalar $n$.
	/// \related Point3D

	inline Point3D operator /(const Point3D& p, float n)
	{
		n = 1.0F / n;
		return (Point3D(p.x * n, p.y * n, p.z * n));
	}

	/// \brief Returns the componentwise product of the 3D points $a$ and $b$.
	/// \related Point3D

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

	// ==============================================
	//	Magnitude
	// ==============================================

	/// \brief Returns the magnitude of the 3D vector $v$.
	/// \related Vector3D

	inline float Magnitude(const Vector3D& v)
	{
		return (Sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	}

	/// \brief Returns the inverse magnitude of the 3D vector $v$.
	/// \related Vector3D

	inline float InverseMag(const Vector3D& v)
	{
		return (InverseSqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	}

	/// \brief Returns the squared magnitude of the 3D vector $v$.
	/// \related Vector3D

	inline float SquaredMag(const Vector3D& v)
	{
		return (v.x * v.x + v.y * v.y + v.z * v.z);
	}

	/// \brief Calculates the normalized version of the 3D vector $v$.
	///
	/// Multiplies the 3D vector $v$ by the inverse of its magnitude. The return value is a vector
	/// having unit length that points in the same direction as $v$. If the magnitude of $v$ is zero,
	/// then the result is undefined.
	///
	/// \related Vector3D

	inline Vector3D Normalize(const Vector3D& v)
	{
		return (v * InverseMag(v));
	}

	// ==============================================
	//	Dot
	// ==============================================

	/// \brief Calculates the dot product of the 3D vectors $a$ and $b$.
	/// \related Vector3D

	inline float Dot(const Vector3D& a, const Vector3D& b)
	{
		return (a.x * b.x + a.y * b.y + a.z * b.z);
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

	template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
	inline float operator ^(const Subvec4D<type_struct, true, count, index_x, index_y, index_z, index_w>& a, const Point3D& b)
	{
		return (a.data[index_x] * b.x + a.data[index_y] * b.y + a.data[index_z] * b.z + a.data[index_w]);
	}

	// ==============================================
	//	Cross
	// ==============================================

	/// \brief Calculates the cross product of the 3D vectors $a$ and $b$.
	/// \related Vector3D

	inline Vector3D Cross(const Vector3D& a, const Vector3D& b)
	{
		return (Vector3D(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x));
	}

	// ==============================================
	//	Projection
	// ==============================================

	/// \brief Returns (<b>a</b>&#x202F;&sdot;&#x202F;<b>b</b>)<b>b</b>, which is the projection of $a$ onto $b$ under the assumption that the magnitude of $b$ is one.
	/// \related Vector3D

	inline Vector3D Project(const Vector3D& a, const Vector3D& b)
	{
		return (b * Dot(a, b));
	}

	/// \brief Returns <b>a</b>&#x202F;&minus;&#x202F;(<b>a</b>&#x202F;&sdot;&#x202F;<b>b</b>)<b>b</b>, which is the rejection of $a$ from $b$ under the assumption that the magnitude of $b$ is one.
	/// \related Vector3D

	inline Vector3D Reject(const Vector3D& a, const Vector3D& b)
	{
		return (a - b * Dot(a, b));
	}

	// ==============================================
	//	Floor / ceiling
	// ==============================================

	/// \brief Returns the componentwise floor of the 3D vector $v$.
	/// \related Vector3D

	inline Vector3D Floor(const Vector3D& v)
	{
		return (Vector3D(Floor(v.x), Floor(v.y), Floor(v.z)));
	}

	/// \brief Returns the componentwise ceiling of the 3D vector $v$.
	/// \related Vector3D

	inline Vector3D Ceil(const Vector3D& v)
	{
		return (Vector3D(Ceil(v.x), Ceil(v.y), Ceil(v.z)));
	}


	// ==============================================
	//	POD Structures
	// ==============================================

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
		float	x, y, z;

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
		float	x, y, z;

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


	class Origin3D
	{
		private:

			TERATHON_API static const ConstPoint3D origin;

		public:

			operator const Point3D&(void) const
			{
				return (origin);
			}

			const Point3D *operator &(void) const
			{
				return (&origin);
			}
	};


	inline const Point3D& operator +(const Origin3D&, const Vector3D& v)
	{
		return (static_cast<const Point3D&>(v));
	}

	template <typename type_struct, bool anti, int count, int index_x, int index_y, int index_z>
	inline Point3D operator +(const Origin3D&, const Subvec3D<type_struct, anti, count, index_x, index_y, index_z>& v)
	{
		return (Point3D(v.data[index_x], v.data[index_y], v.data[index_z]));
	}

	template <typename type_struct, bool anti, int count>
	inline const Point3D& operator +(const Origin3D&, const Subvec3D<type_struct, anti, count, 0, 1, 2>& v)
	{
		return (reinterpret_cast<const Point3D&>(v.data[0]));
	}

	template <typename type_struct, bool anti, int count>
	inline const Point3D& operator +(const Origin3D&, const Subvec3D<type_struct, anti, count, 1, 2, 3>& v)
	{
		return (reinterpret_cast<const Point3D&>(v.data[1]));
	}

	inline Point3D operator -(const Origin3D&, const Vector3D& v)
	{
		return (Point3D(-v.x, -v.y, -v.z));
	}

	template <typename type_struct, bool anti, int count, int index_x, int index_y, int index_z>
	inline Point3D operator -(const Origin3D&, const Subvec3D<type_struct, anti, count, index_x, index_y, index_z>& v)
	{
		return (Point3D(-v.data[index_x], -v.data[index_y], -v.data[index_z]));
	}
}


#endif
