//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSMatrix3D_h
#define TSMatrix3D_h


#include "TSMatrix2D.h"
#include "TSBivector3D.h"
#include "TSRigid2D.h"


#define TERATHON_MATRIX3D 1
#define TERATHON_TRANSFORM2D 1


namespace Terathon
{
	class Matrix3D;
	class Matrix4D;
	class Transform2D;
	class Transform3D;
	struct ConstMatrix3D;
	struct ConstTransform2D;


	// ==============================================
	//	Matrix2D
	// ==============================================

	struct TypeMatrix3D
	{
		typedef float component_type;
		typedef Matrix2D matrix2D_type;
		typedef Matrix3D matrix3D_type;
		typedef TypeVector3D column_type_struct;
		typedef TypeLine2D row_type_struct;
	};


	/// \brief Encapsulates a 3&#x202F;&times;&#x202F;3 matrix.
	///
	/// The $Matrix3D$ class is used to store a 3&#x202F;&times;&#x202F;3 matrix. The entries of the matrix
	/// are accessed using the () operator with two indexes specifying the row and column of an entry.
	///
	/// \also Matrix2D
	/// \also Matrix4D
	/// \also Transform2D
	/// \also Transform3D

	class Matrix3D : public Mat3D<TypeMatrix3D>
	{
		public:

			TERATHON_API static const ConstMatrix3D identity;

			/// \brief Default constructor that leaves the entries uninitialized.

			inline Matrix3D() = default;

			Matrix3D(const Matrix3D& m)
			{
				matrix = m.matrix;
			}

			/// \brief Constructor that sets entries explicitly.
			/// \param n00,n01,n02,n10,n11,n12,n20,n21,n22		The entries of the matrix.

			TERATHON_API Matrix3D(float n00, float n01, float n02, float n10, float n11, float n12, float n20, float n21, float n22);

			/// \brief Constructor that sets columns explicitly.
			/// \param a,b,c	The columns of the matrix.

			TERATHON_API Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c);

			/// \brief Sets all nine entries of a 3&#x202F;&times;&#x202F;3 matrix.
			/// \param n00,n01,n02,n10,n11,n12,n20,n21,n22		The new entries of the matrix.

			TERATHON_API Matrix3D& Set(float n00, float n01, float n02, float n10, float n11, float n12, float n20, float n21, float n22);

			/// \brief Sets all three columns of a 3&#x202F;&times;&#x202F;3 matrix.
			/// \param a,b,c	The new columns of the matrix.

			TERATHON_API Matrix3D& Set(const Vector3D& a, const Vector3D& b, const Vector3D& c);

			Matrix3D& operator =(const Matrix3D& m)
			{
				matrix = m.matrix;
				return (*this);
			}

			void operator =(const Matrix3D& m) volatile
			{
				matrix = m.matrix;
			}

			template <typename type_struct, int count, int index_00, int index_01, int index_02, int index_10, int index_11, int index_12, int index_20, int index_21, int index_22>
			Matrix3D& operator =(const Submat3D<type_struct, count, index_00, index_01, index_02, index_10, index_11, index_12, index_20, index_21, index_22>& m)
			{
				matrix = m;
				return (*this);
			}

			template <typename type_struct, int count, int index_00, int index_01, int index_02, int index_10, int index_11, int index_12, int index_20, int index_21, int index_22>
			void operator =(const Submat3D<type_struct, count, index_00, index_01, index_02, index_10, index_11, index_12, index_20, index_21, index_22>& m) volatile
			{
				matrix = m;
			}

			TERATHON_API Matrix3D& operator *=(const Matrix3D& m);
			TERATHON_API Matrix3D& operator *=(float s);
			TERATHON_API Matrix3D& operator /=(float s);

			/// \brief Sets a matrix to the 3&#x202F;&times;&#x202F;3 identity matrix.

			TERATHON_API Matrix3D& SetIdentity(void);

			/// \brief Orthogonalizes the columns of a 3&#x202F;&times;&#x202F;3 matrix.
			/// \param column	The index of the column whose direction does not change. This must be 0, 1, or 2.
			///
			/// The $Orthogonalize()$ function uses Gram-Schmidt orthogonalization to orthogonalize the columns
			/// of a matrix. The column whose index is specified by the $column$ parameter is normalized to unit length.
			/// The remaining two columns are orthogonalized and made unit length. Only the two columns not specified by
			/// the $column$ parameter can change direction.

			TERATHON_API Matrix3D& Orthogonalize(int32 column);

			TERATHON_API void GetEulerAngles(float *x, float *y, float *z) const;
			TERATHON_API Matrix3D& SetEulerAngles(float x, float y, float z);

			/// \brief Returns a 3&#x202F;&times;&#x202F;3 matrix that represents a rotation about the <i>x</i> axis.
			/// \param angle	The angle through which to rotate, in radians.

			TERATHON_API static Matrix3D MakeRotationX(float angle);

			/// \brief Returns a 3&#x202F;&times;&#x202F;3 matrix that represents a rotation about the <i>y</i> axis.
			/// \param angle	The angle through which to rotate, in radians.

			TERATHON_API static Matrix3D MakeRotationY(float angle);

			/// \brief Returns a 3&#x202F;&times;&#x202F;3 matrix that represents a rotation about the <i>z</i> axis.
			/// \param angle	The angle through which to rotate, in radians.

			TERATHON_API static Matrix3D MakeRotationZ(float angle);

			/// \brief Returns a 3&#x202F;&times;&#x202F;3 matrix that represents a rotation about an arbitrary axis.
			/// \param angle	The angle through which to rotate, in radians.
			/// \param axis		The axis about which to rotate. This bivector must have unit magnitude.

			TERATHON_API static Matrix3D MakeRotation(float angle, const Bivector3D& axis);

			TERATHON_API static Matrix3D MakeReflection(const Vector3D& a);
			TERATHON_API static Matrix3D MakeInvolution(const Vector3D& a);

			/// \brief Returns a 3&#x202F;&times;&#x202F;3 matrix that represents a uniform scale.
			/// \param scale	The scale along all three axes.

			TERATHON_API static Matrix3D MakeScale(float scale);
			TERATHON_API static Matrix3D MakeScale(float sx, float sy, float sz);
			TERATHON_API static Matrix3D MakeScale(float scale, const Vector3D& a);
			TERATHON_API static Matrix3D MakeScaleX(float sx);
			TERATHON_API static Matrix3D MakeScaleY(float sy);
			TERATHON_API static Matrix3D MakeScaleZ(float sz);

			TERATHON_API static Matrix3D MakeSkew(float angle, const Vector3D& a, const Vector3D& b);
	};


	template <typename type_struct, int count, int index_x, int index_y, int index_z>
	inline typename type_struct::vector3D_type operator *(const Matrix3D& m, const Subvec3D<type_struct, false, count, index_x, index_y, index_z>& v)
	{
		return (m.matrix * v);
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z>
	inline typename type_struct::vector3D_type operator *(const Subvec3D<type_struct, true, count, index_x, index_y, index_z>& v, const Matrix3D& m)
	{
		return (v * m.matrix);
	}

	template <typename type_struct, int count, int index_00, int index_01, int index_02, int index_10, int index_11, int index_12, int index_20, int index_21, int index_22>
	inline Vector3D operator *(const Submat3D<type_struct, count, index_00, index_01, index_02, index_10, index_11, index_12, index_20, index_21, index_22>& m, const Vector3D& v)
	{
		return (m * v.xyz);
	}

	template <typename type_struct, int count, int index_00, int index_01, int index_02, int index_10, int index_11, int index_12, int index_20, int index_21, int index_22>
	inline Bivector3D operator *(const Bivector3D& v, const Submat3D<type_struct, count, index_00, index_01, index_02, index_10, index_11, index_12, index_20, index_21, index_22>& m)
	{
		return (v.xyz * m);
	}

	inline Vector3D operator *(const Matrix3D& m, const Vector3D& v)
	{
		return (m.matrix * v.xyz);
	}

	inline Point3D operator *(const Matrix3D& m, const Point3D& p)
	{
		return (Point3D::origin + m.matrix * p.xyz);
	}

	inline Bivector3D operator *(const Bivector3D& v, const Matrix3D& m)
	{
		return (v.xyz * m.matrix);
	}

	/// \brief Returns the product of the matrices $m1$ and $m2$.
	/// \related Matrix3D

	inline Matrix3D operator *(const Matrix3D& m1, const Matrix3D& m2)
	{
		return (m1.matrix * m2.matrix);
	}

	template <typename type_struct, int count, int index_00, int index_01, int index_02, int index_10, int index_11, int index_12, int index_20, int index_21, int index_22>
	inline Matrix3D operator *(const Matrix3D& m1, const Submat3D<type_struct, count, index_00, index_01, index_02, index_10, index_11, index_12, index_20, index_21, index_22>& m2)
	{
		return (m1.matrix * m2);
	}

	template <typename type_struct, int count, int index_00, int index_01, int index_02, int index_10, int index_11, int index_12, int index_20, int index_21, int index_22>
	inline Matrix3D operator *(const Submat3D<type_struct, count, index_00, index_01, index_02, index_10, index_11, index_12, index_20, index_21, index_22>& m1, const Matrix3D& m2)
	{
		return (m1 * m2.matrix);
	}


	TERATHON_API Matrix3D operator *(const Matrix3D& m, float s);
	TERATHON_API Matrix3D operator /(const Matrix3D& m, float s);

	inline Matrix3D operator *(float s, const Matrix3D& m)
	{
		return (m * s);
	}


	/// \brief Returns the determinant of the matrix $m$.
	/// \related Matrix3D

	TERATHON_API float Determinant(const Matrix3D& m);

	/// \brief Returns the inverse of the matrix $m$. If $m$ is singular, then the result is undefined.
	/// \related Matrix3D

	TERATHON_API Matrix3D Inverse(const Matrix3D& m);

	/// \brief Returns the adjugate of the matrix $m$.
	/// \related Matrix3D

	TERATHON_API Matrix3D Adjugate(const Matrix3D& m);


	// ==============================================
	//	Transform2D
	// ==============================================

	/// \brief Encapsulates a 3&#x202F;&times;&#x202F;3 matrix whose third row is always (0,&#x202F;0,&#x202F;1).
	///
	/// The $Transform2D$ class is used to store a 3&#x202F;&times;&#x202F;3 matrix whose third row is always (0,&#x202F;0,&#x202F;1).
	/// Such a matrix represents an affine transformation in 2D space.
	///
	/// \also Transform3D

	class Transform2D : public Matrix3D
	{
		public:

			TERATHON_API static const ConstTransform2D identity;

			/// \brief Default constructor that leaves the entries uninitialized.

			inline Transform2D() = default;

			/// \brief Constructor that sets entries explicitly.
			/// \param n00,n01,n02,n10,n11,n12,n20,n21,n22		The entries of first two rows of the matrix.

			TERATHON_API Transform2D(float n00, float n01, float n02, float n10, float n11, float n12);

			TERATHON_API Transform2D(const Vector2D& a, const Vector2D& b, const Point2D& p);
			TERATHON_API Transform2D(const Vector2D& r0, float n02, const Vector2D& r1, float n12);
			TERATHON_API Transform2D(const Matrix2D& m);
			TERATHON_API Transform2D(const Matrix2D& m, const Vector2D& v);

			TERATHON_API Transform2D& Set(float n00, float n01, float n02, float n10, float n11, float n12);
			TERATHON_API Transform2D& Set(const Vector2D& a, const Vector2D& b, const Point2D& p);
			TERATHON_API Transform2D& Set(const Matrix2D& m, const Vector2D& v);

			Vector2D& operator [](machine j)
			{
				return (Matrix3D::operator [](j).xy);
			}

			const Vector2D& operator [](machine j) const
			{
				return (Matrix3D::operator [](j).xy);
			}

			const Point2D& GetTranslation(void) const
			{
				return (Point2D::origin + Matrix3D::operator [](2).xy);
			}

			Transform2D& SetTranslation(float x, float y)
			{
				m02 = x;
				m12 = y;
				return (*this);
			}

			Transform2D& SetTranslation(const Point2D& p)
			{
				m02 = p.x;
				m12 = p.y;
				return (*this);
			}

			TERATHON_API Transform2D& operator *=(const Transform2D& m);
			TERATHON_API Transform2D& operator *=(const Matrix2D& m);

			TERATHON_API Transform2D& SetMatrix2D(const Vector2D& a, const Vector2D& b);
			TERATHON_API Transform2D& Orthogonalize(int32 column);

			TERATHON_API static Transform2D MakeRotation(float angle);
			TERATHON_API static Transform2D MakeScale(float sx, float sy);
			TERATHON_API static Transform2D MakeTranslation(const Vector2D& dv);
	};


	template <typename type_struct, int count, int index_x, int index_y>
	inline Vector2D operator *(const Transform2D& m, const Subvec2D<type_struct, count, index_x, index_y>& v)
	{
		return (m.matrix2D * v);
	}

	template <typename type_struct, int count, int index_x, int index_y>
	inline Vector2D operator *(const Subvec2D<type_struct, count, index_x, index_y>& v, const Transform2D& m)
	{
		return (v * m.matrix2D);
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z>
	Vector3D operator *(const Transform2D& m, const Subvec3D<type_struct, false, count, index_x, index_y, index_z>& v)
	{
		return (Vector3D(m(0,0) * v.data[index_x] + m(0,1) * v.data[index_y] + m(0,2) * v.data[index_z],
		                 m(1,0) * v.data[index_x] + m(1,1) * v.data[index_y] + m(1,2) * v.data[index_z],
		                 v.data[index_z]));
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z>
	Antivector3D operator *(const Subvec3D<type_struct, true, count, index_x, index_y, index_z>& v, const Transform2D& m)
	{
		return (Antivector3D(m(0,0) * v.data[index_x] + m(1,0) * v.data[index_y],
		                     m(0,1) * v.data[index_x] + m(1,1) * v.data[index_y],
		                     m(0,2) * v.data[index_x] + m(1,2) * v.data[index_y] + v.data[index_z]));
	}

	inline Vector3D operator *(const Transform2D& m, const Vector3D& v)
	{
		return (m * v.xyz);
	}

	inline Antivector3D operator *(const Antivector3D& v, const Transform2D& m)
	{
		return (v.xyz * m);
	}

	template <typename type_struct, int count, int index_00, int index_01, int index_10, int index_11>
	inline Transform2D operator *(const Transform2D& m1, const Submat2D<type_struct, count, index_00, index_01, index_10, index_11>& m2)
	{
		Transform2D		transform;

		transform.matrix2D = m1.matrix2D * m2;
		transform[2] = m1[2];

		transform.m20 = transform.m21 = 0.0F;
		transform.m22 = 1.0F;
		return (transform);
	}

	template <typename type_struct, int count, int index_00, int index_01, int index_10, int index_11>
	inline Transform2D operator *(const Submat2D<type_struct, count, index_00, index_01, index_10, index_11>& m1, const Transform2D& m2)
	{
		Transform2D		transform;

		transform.matrix2D = m1 * m2.matrix2D;
		transform[2] = m1 * m2[2];

		transform.m20 = transform.m21 = 0.0F;
		transform.m22 = 1.0F;
		return (transform);
	}

	inline Transform2D operator *(const Transform2D& m1, const Matrix2D& m2)
	{
		return (m1 * m2.matrix);
	}

	inline Transform2D operator *(const Matrix2D& m1, const Transform2D& m2)
	{
		return (m1.matrix * m2);
	}


	TERATHON_API Transform2D operator *(const Transform2D& m1, const Transform2D& m2);
	TERATHON_API Matrix3D operator *(const Matrix3D& m1, const Transform2D& m2);
	TERATHON_API Matrix3D operator *(const Transform2D& m1, const Matrix3D& m2);
	TERATHON_API Vector2D operator *(const Transform2D& m, const Vector2D& v);
	TERATHON_API Vector2D operator *(const Vector2D& v, const Transform2D& m);
	TERATHON_API Point2D operator *(const Transform2D& m, const Point2D& p);

	/// \brief Returns the determinant of the transform $m$.
	/// \related Transform2D

	TERATHON_API float Determinant(const Transform2D& m);

	/// \brief Returns the inverse of the transform $m$. If $m$ is singular, then the result is undefined.
	/// \related Transform2D

	TERATHON_API Transform2D Inverse(const Transform2D& m);

	/// \brief Returns the inverse of the transform $m$ assuming that its determinant is one.
	/// \related Transform2D

	TERATHON_API Transform2D InverseUnitDet(const Transform2D& m);


	// ==============================================
	//	POD Structures
	// ==============================================

	struct ConstMatrix3D
	{
		float	n[3][3];

		operator const Matrix3D&(void) const
		{
			return (reinterpret_cast<const Matrix3D&>(*this));
		}

		const Matrix3D *operator &(void) const
		{
			return (reinterpret_cast<const Matrix3D *>(this));
		}

		const Matrix3D *operator ->(void) const
		{
			return (reinterpret_cast<const Matrix3D *>(this));
		}

		float operator ()(int32 i, int32 j) const
		{
			return (reinterpret_cast<const Matrix3D&>(*this)(i, j));
		}

		const Vector3D& operator [](machine j) const
		{
			return (reinterpret_cast<const Matrix3D&>(*this)[j]);
		}
	};


	struct ConstTransform2D
	{
		float	n[3][3];

		operator const Transform2D&(void) const
		{
			return (reinterpret_cast<const Transform2D&>(*this));
		}

		const Transform2D *operator &(void) const
		{
			return (reinterpret_cast<const Transform2D *>(this));
		}

		const Transform2D *operator ->(void) const
		{
			return (reinterpret_cast<const Transform2D *>(this));
		}

		float operator ()(int32 i, int32 j) const
		{
			return (reinterpret_cast<const Transform2D&>(*this)(i, j));
		}

		const Vector2D& operator [](machine j) const
		{
			return (reinterpret_cast<const Transform2D&>(*this)[j]);
		}
	};
}


#endif
