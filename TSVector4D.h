//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSVector4D_h
#define TSVector4D_h


#include "TSVector3D.h"


#define TERATHON_VECTOR4D 1


namespace Terathon
{
	class Vector4D;
	struct ConstVector4D;


	// ==============================================
	//	Vector4D
	// ==============================================

	struct TypeVector4D
	{
		typedef float component_type;
		typedef Vector2D vector2D_type;
		typedef Vector3D vector3D_type;
		typedef Vector4D vector4D_type;
	};


	/// \brief Encapsulates a 4D vector.
	///
	/// The $Vector4D$ class is used to store a four-dimensional direction vector having floating-point
	/// components <i>x</i>, <i>y</i>, <i>z</i>, and <i>w</i>.
	///
	/// \also Vector2D
	/// \also Vector3D

	class Vector4D : public Vec4D<TypeVector4D>
	{
		public:

			TERATHON_API static const ConstVector4D zero;

			TERATHON_API static const ConstVector4D x_unit;
			TERATHON_API static const ConstVector4D y_unit;
			TERATHON_API static const ConstVector4D z_unit;
			TERATHON_API static const ConstVector4D w_unit;

			TERATHON_API static const ConstVector4D minus_x_unit;
			TERATHON_API static const ConstVector4D minus_y_unit;
			TERATHON_API static const ConstVector4D minus_z_unit;
			TERATHON_API static const ConstVector4D minus_w_unit;

			/// \brief Default constructor that leaves the components uninitialized.

			inline Vector4D() = default;

			Vector4D(const Vector4D& v)
			{
				xyzw = v.xyzw;
			}

			/// \brief Constructor that sets components explicitly.
			/// \param a,b,c,d		The components of the vector.

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

			/// \brief Sets all four components of a 4D vector.
			/// \param a,b,c,d		The new components of the vector.

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

			Vector4D& operator *=(float n)
			{
				xyzw *= n;
				return (*this);
			}

			Vector4D& operator /=(float n)
			{
				xyzw /= n;
				return (*this);
			}

			Vector4D& Normalize(void)
			{
				return (static_cast<Vector4D&>(xyzw.Normalize()));
			}

			/// \brief Rotates the vector about the <i>x</i> axis through the angle, in radians,
			/// given by the $angle$ parameter. The <i>w</i> coordinate is not modified.

			TERATHON_API Vector4D& RotateAboutX(float angle);

			/// \brief Rotates the vector about the <i>y</i> axis through the angle, in radians,
			/// given by the $angle$ parameter. The <i>w</i> coordinate is not modified.

			TERATHON_API Vector4D& RotateAboutY(float angle);

			/// \brief Rotates the vector about the <i>z</i> axis through the angle, in radians,
			/// given by the $angle$ parameter. The <i>w</i> coordinate is not modified.

			TERATHON_API Vector4D& RotateAboutZ(float angle);

			/// \brief Rotates the vector about the axis given by the $axis$ parameter through the angle,
			/// in radians, given by the $angle$ parameter. The <i>w</i> coordinate is not modified.

			TERATHON_API Vector4D& RotateAboutAxis(float angle, const Bivector3D& axis);
	};


	/// \brief Returns the negation of the 4D vector $v$.
	/// \related Vector4D

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

	/// \brief Returns the product of the 4D vector $v$ and the scalar $n$.
	/// \related Vector4D

	inline Vector4D operator *(const Vector4D& v, float n)
	{
		return (Vector4D(v.x * n, v.y * n, v.z * n, v.w * n));
	}

	/// \brief Returns the product of the 4D vector $v$ and the scalar $n$.
	/// \related Vector4D

	inline Vector4D operator *(float n, const Vector4D& v)
	{
		return (Vector4D(n * v.x, n * v.y, n * v.z, n * v.w));
	}

	/// \brief Returns the product of the 4D vector $v$ and the inverse of the scalar $n$.
	/// \related Vector4D

	inline Vector4D operator /(const Vector4D& v, float n)
	{
		n = 1.0F / n;
		return (Vector4D(v.x * n, v.y * n, v.z * n, v.w * n));
	}

	/// \brief Returns the componentwise product of the 4D vectors $a$ and $b$.
	/// \related Vector4D

	inline Vector4D operator *(const Vector4D& a, const Vector4D& b)
	{
		return (Vector4D(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w));
	}

	// ==============================================
	//	Magnitude
	// ==============================================

	/// \brief Returns the magnitude of the 4D vector $v$.
	/// \related Vector4D

	inline float Magnitude(const Vector4D& v)
	{
		return (Sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w));
	}

	/// \brief Returns the inverse magnitude of the 4D vector $v$.
	/// \related Vector4D

	inline float InverseMag(const Vector4D& v)
	{
		return (InverseSqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w));
	}

	/// \brief Returns the squared magnitude of the 4D vector $v$.
	/// \related Vector4D

	inline float SquaredMag(const Vector4D& v)
	{
		return (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
	}

	/// \brief Calculates the normalized version of the 4D vector $v$.
	///
	/// Multiplies the 4D vector $v$ by the inverse of its magnitude. The return value is a vector
	/// having unit length that points in the same direction as $v$. If the magnitude of $v$ is zero,
	/// then the result is undefined.
	///
	/// \related Vector4D

	inline Vector4D Normalize(const Vector4D& v)
	{
		return (v * InverseMag(v));
	}

	// ==============================================
	//	Dot
	// ==============================================

	/// \brief Calculates the dot product of the 4D vectors $a$ and $b$.
	/// \related Vector3D

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

	// ==============================================
	//	Projection
	// ==============================================

	/// \brief Returns (<b>a</b>&#x202F;&sdot;&#x202F;<b>b</b>)<b>b</b>, which is the projection of $a$ onto $b$ under the assumption that the magnitude of $b$ is one.
	/// \related Vector4D

	inline Vector4D Project(const Vector4D& a, const Vector4D& b)
	{
		return (b * Dot(a, b));
	}

	/// \brief Returns <b>a</b>&#x202F;&minus;&#x202F;(<b>a</b>&#x202F;&sdot;&#x202F;<b>b</b>)<b>b</b>, which is the rejection of $a$ from $b$ under the assumption that the magnitude of $b$ is one.
	/// \related Vector4D

	inline Vector4D Reject(const Vector4D& a, const Vector4D& b)
	{
		return (a - b * Dot(a, b));
	}

	// ==============================================
	//	Floor / ceiling
	// ==============================================

	/// \brief Returns the componentwise floor of the 4D vector $v$.
	/// \related Vector4D

	inline Vector4D Floor(const Vector4D& v)
	{
		return (Vector4D(Floor(v.x), Floor(v.y), Floor(v.z), Floor(v.w)));
	}

	/// \brief Returns the componentwise ceiling of the 4D vector $v$.
	/// \related Vector4D

	inline Vector4D Ceil(const Vector4D& v)
	{
		return (Vector4D(Ceil(v.x), Ceil(v.y), Ceil(v.z), Ceil(v.w)));
	}


	// ==============================================
	//	POD Structures
	// ==============================================

	struct ConstVector4D
	{
		float	x, y, z, w;

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
