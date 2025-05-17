//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSMatrix4D_h
#define TSMatrix4D_h


#include "TSRigid3D.h"
#include "TSMatrix3D.h"


#define TERATHON_MATRIX4D 1
#define TERATHON_TRANSFORM3D 1


namespace Terathon
{
	class Transform3D;
	struct ConstMatrix4D;
	struct ConstTransform3D;


	// ==============================================
	//	Matrix4D
	// ==============================================

	struct TypeMatrix4D
	{
		typedef float component_type;
		typedef Matrix2D matrix2D_type;
		typedef Matrix3D matrix3D_type;
		typedef Matrix4D matrix4D_type;
		typedef TypeVector4D column_type_struct;
		typedef TypePlane3D row_type_struct;
	};


	/// \brief Encapsulates a 4&#x202F;&times;&#x202F;4 matrix.
	///
	/// The $Matrix3D$ class is used to store a 4&#x202F;&times;&#x202F;4 matrix. The entries of the matrix
	/// are accessed using the () operator with two indexes specifying the row and column of an entry.
	///
	/// \also Matrix2D
	/// \also Matrix3D
	/// \also Transform2D
	/// \also Transform3D

	class Matrix4D : public Mat4D<TypeMatrix4D>
	{
		public:

			TERATHON_API static const ConstMatrix4D identity;

			/// \brief Default constructor that leaves the entries uninitialized.

			inline Matrix4D() = default;

			Matrix4D(const Matrix4D& m)
			{
				matrix = m.matrix;
			}

			/// \brief Constructor that sets entries explicitly.
			/// \param n00,n01,n02,n03,n10,n11,n12,n13,n20,n21,n22,n23,n30,n31,n32,n33		The entries of the matrix.

			TERATHON_API Matrix4D(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23, float n30, float n31, float n32, float n33);

			/// \brief Constructor that sets columns explicitly.
			/// \param a,b,c,d		The columns of the matrix.

			TERATHON_API Matrix4D(const Vector4D& a, const Vector4D& b, const Vector4D& c, const Vector4D& d);

			TERATHON_API Matrix4D(const Bivector3D& r0, float n03, const Bivector3D& r1, float n13, const Bivector3D& r2, float n23, const Bivector3D& r3, float n33);

			/// \brief Sets all 16 entries of a 4&#x202F;&times;&#x202F;4 matrix.
			/// \param n00,n01,n02,n03,n10,n11,n12,n13,n20,n21,n22,n23,n30,n31,n32,n33		The new entries of the matrix.

			TERATHON_API Matrix4D& Set(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23, float n30, float n31, float n32, float n33);

			/// \brief Sets all three columns of a 4&#x202F;&times;&#x202F;4 matrix.
			/// \param a,b,c,d		The new columns of the matrix.

			TERATHON_API Matrix4D& Set(const Vector4D& a, const Vector4D& b, const Vector4D& c, const Vector4D& d);

			Matrix4D& operator =(const Matrix4D& m)
			{
				matrix = m.matrix;
				return (*this);
			}

			void operator =(const Matrix4D& m) volatile
			{
				matrix = m.matrix;
			}

			template <typename type_struct, int count, int index_00, int index_01, int index_02, int index_03, int index_10, int index_11, int index_12, int index_13, int index_20, int index_21, int index_22, int index_23, int index_30, int index_31, int index_32, int index_33>
			Matrix4D& operator =(const Submat4D<type_struct, count, index_00, index_01, index_02, index_03, index_10, index_11, index_12, index_13, index_20, index_21, index_22, index_23, index_30, index_31, index_32, index_33>& m)
			{
				matrix = m;
				return (*this);
			}

			template <typename type_struct, int count, int index_00, int index_01, int index_02, int index_03, int index_10, int index_11, int index_12, int index_13, int index_20, int index_21, int index_22, int index_23, int index_30, int index_31, int index_32, int index_33>
			void operator =(const Submat4D<type_struct, count, index_00, index_01, index_02, index_03, index_10, index_11, index_12, index_13, index_20, index_21, index_22, index_23, index_30, index_31, index_32, index_33>& m) volatile
			{
				matrix = m;
			}

			TERATHON_API Matrix4D& operator *=(const Matrix4D& m);
			TERATHON_API Matrix4D& operator *=(const Matrix3D& m);

			/// \brief Sets a matrix to the 4&#x202F;&times;&#x202F;4 identity matrix.

			TERATHON_API Matrix4D& SetIdentity(void);
	};


	template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
	typename type_struct::vector4D_type operator *(const Matrix4D& m, const Subvec4D<type_struct, false, count, index_x, index_y, index_z, index_w>& v)
	{
		return (m.matrix * v.xyzw);
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
	typename type_struct::vector4D_type operator *(const Subvec4D<type_struct, true, count, index_x, index_y, index_z, index_w>& v, const Matrix4D& m)
	{
		return (v.xyzw * m.matrix);
	}

	template <typename type_struct, int count, int index_00, int index_01, int index_02, int index_03, int index_10, int index_11, int index_12, int index_13, int index_20, int index_21, int index_22, int index_23, int index_30, int index_31, int index_32, int index_33>
	inline Vector3D operator *(const Submat4D<type_struct, count, index_00, index_01, index_02, index_03, index_10, index_11, index_12, index_13, index_20, index_21, index_22, index_23, index_30, index_31, index_32, index_33>& m, const Vector4D& v)
	{
		return (m * v.xyzw);
	}

	template <typename type_struct, int count, int index_00, int index_01, int index_02, int index_03, int index_10, int index_11, int index_12, int index_13, int index_20, int index_21, int index_22, int index_23, int index_30, int index_31, int index_32, int index_33>
	inline Bivector3D operator *(const Antivector4D& v, const Submat4D<type_struct, count, index_00, index_01, index_02, index_03, index_10, index_11, index_12, index_13, index_20, index_21, index_22, index_23, index_30, index_31, index_32, index_33>& m)
	{
		return (v.xyzw * m);
	}

	inline Vector4D operator *(const Matrix4D& m, const Vector4D& v)
	{
		return (m.matrix * v.xyzw);
	}

	inline Antivector4D operator *(const Antivector4D& v, const Matrix4D& m)
	{
		return (v.xyzw * m.matrix);
	}

	/// \brief Returns the product of the matrices $m1$ and $m2$.
	/// \related Matrix4D

	inline Matrix4D operator *(const Matrix4D& m1, const Matrix4D& m2)
	{
		return (m1.matrix * m2.matrix);
	}

	template <typename type_struct, int count, int index_00, int index_01, int index_02, int index_03, int index_10, int index_11, int index_12, int index_13, int index_20, int index_21, int index_22, int index_23, int index_30, int index_31, int index_32, int index_33>
	inline Matrix4D operator *(const Matrix4D& m1, const Submat4D<type_struct, count, index_00, index_01, index_02, index_03, index_10, index_11, index_12, index_13, index_20, index_21, index_22, index_23, index_30, index_31, index_32, index_33>& m2)
	{
		return (m1.matrix * m2);
	}

	template <typename type_struct, int count, int index_00, int index_01, int index_02, int index_03, int index_10, int index_11, int index_12, int index_13, int index_20, int index_21, int index_22, int index_23, int index_30, int index_31, int index_32, int index_33>
	inline Matrix4D operator *(const Submat4D<type_struct, count, index_00, index_01, index_02, index_03, index_10, index_11, index_12, index_13, index_20, index_21, index_22, index_23, index_30, index_31, index_32, index_33>& m1, const Matrix4D& m2)
	{
		return (m1 * m2.matrix);
	}


	TERATHON_API Matrix4D operator *(const Matrix4D& m1, const Matrix3D& m2);
	TERATHON_API Vector4D operator *(const Matrix4D& m, const Vector3D& v);
	TERATHON_API Vector4D operator *(const Vector3D& v, const Matrix4D& m);
	TERATHON_API Vector4D operator *(const Matrix4D& m, const Point3D& p);
	TERATHON_API Vector4D operator *(const Point3D& p, const Matrix4D& m);
	TERATHON_API Vector4D operator *(const Matrix4D& m, const Vector2D& v);
	TERATHON_API Vector4D operator *(const Vector2D& v, const Matrix4D& m);
	TERATHON_API Vector4D operator *(const Matrix4D& m, const Point2D& p);
	TERATHON_API Vector4D operator *(const Point2D& p, const Matrix4D& m);

	/// \brief Returns the determinant of the matrix $m$.
	/// \related Matrix4D

	TERATHON_API float Determinant(const Matrix4D& m);

	/// \brief Returns the inverse of the matrix $m$. If $m$ is singular, then the result is undefined.
	/// \related Matrix4D

	TERATHON_API Matrix4D Inverse(const Matrix4D& m);

	/// \brief Returns the adjugate of the matrix $m$.
	/// \related Matrix4D

	TERATHON_API Matrix4D Adjugate(const Matrix4D& m);


	// ==============================================
	//	Transform3D
	// ==============================================

	/// \brief Encapsulates a 4&#x202F;&times;&#x202F;4 matrix whose fourth row is always (0,&#x202F;0,&#x202F;0,&#x202F;1).
	///
	/// The $Transform3D$ class is used to store a 4&#x202F;&times;&#x202F;4 matrix whose fourth row is always (0,&#x202F;0,&#x202F;0,&#x202F;1).
	/// Such a matrix represents an affine transformation in 3D space.
	///
	/// \also Transform2D

	class Transform3D : public Matrix4D
	{
		public:

			TERATHON_API static const ConstTransform3D identity;

			/// \brief Default constructor that leaves the entries uninitialized.

			inline Transform3D() = default;

			/// \brief Constructor that sets entries explicitly.
			/// \param n00,n01,n02,n03,n10,n11,n12,n13,n20,n21,n22,n23		The entries of first three rows of the transform.

			TERATHON_API Transform3D(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23);

			/// \brief Constructor that sets columns explicitly.
			/// \param a,b,c	The first three columns of the transform.
			/// \param p		The fourth column of the transform.

			TERATHON_API Transform3D(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Point3D& p);

			TERATHON_API Transform3D(const Bivector3D& r0, float n03, const Bivector3D& r1, float n13, const Bivector3D& r2, float n23);
			TERATHON_API Transform3D(const Matrix3D& m);
			TERATHON_API Transform3D(const Matrix3D& m, const Vector3D& v);

			/// \brief Sets all 12 entries of a 3D affine transformation.
			/// \param n00,n01,n02,n03,n10,n11,n12,n13,n20,n21,n22,n23		The new entries of first three rows of the transform.

			TERATHON_API Transform3D& Set(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23);

			/// \brief Sets all four columns of a 3D affine transformation.
			/// \param a,b,c	The first three columns of the transform.
			/// \param p		The fourth column of the transform.

			TERATHON_API Transform3D& Set(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Point3D& p);

			TERATHON_API Transform3D& Set(const Matrix3D& m, const Vector3D& v);

			/// \brief Returns a reference to the <i>j</i>-th column of a transform. $j$ must be 0, 1, or 2.

			Vector3D& operator [](machine j)
			{
				return (Matrix4D::operator [](j).xyz);
			}

			/// \brief Returns a const reference to the <i>j</i>-th column of a transform. $j$ must be 0, 1, or 2.

			const Vector3D& operator [](machine j) const
			{
				return (Matrix4D::operator [](j).xyz);
			}

			/// \brief Returns a const reference to the fourth column of a transform.

			const Point3D& GetTranslation(void) const
			{
				return (Point3D::origin + Matrix4D::operator [](3).xyz);
			}

			/// \brief Sets the entries of the fourth column of a transform. The first three columns of the matrix are not modified.

			Transform3D& SetTranslation(float x, float y, float z)
			{
				m03 = x;
				m13 = y;
				m23 = z;
				return (*this);
			}

			/// \brief Sets the fourth column of a transform to the point $p$. The first three columns of the transform are not modified.

			Transform3D& SetTranslation(const Point3D& p)
			{
				m03 = p.x;
				m13 = p.y;
				m23 = p.z;
				return (*this);
			}

			TERATHON_API Transform3D& operator *=(const Transform3D& m);
			TERATHON_API Transform3D& operator *=(const Matrix3D& m);

			/// \brief Sets the entries of the upper-left 3&#x202F;&times;&#x202F;3 portion of a transform. The fourth column of the transform is not modified.
			/// \param a,b,c	The first three columns of the transform. 

			TERATHON_API Transform3D& SetMatrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c);

			/// \brief Orthogonalizes the first three columns of a transform.
			/// \param column	The index of the column whose direction does not change. This must be 0, 1, or 2.
			///
			/// The $Orthogonalize()$ function uses Gram-Schmidt orthogonalization to orthogonalize the first three columns
			/// of a transform. The column whose index is specified by the $column$ parameter is normalized to unit length.
			/// The remaining two columns are orthogonalized and made unit length. Only the two columns not specified by
			/// the $column$ parameter can change direction. The fourth column of the transform is not modified.

			TERATHON_API Transform3D& Orthogonalize(int32 column);

			TERATHON_API void GetEulerAngles(float *x, float *y, float *z) const;
			TERATHON_API Transform3D& SetEulerAngles(float x, float y, float z);

			/// \brief Returns a 4&#x202F;&times;&#x202F;4 transform that represents a rotation about the <i>x</i> axis.
			/// \param angle	The angle through which to rotate, in radians.

			TERATHON_API static Transform3D MakeRotationX(float angle);

			/// \brief Returns a 4&#x202F;&times;&#x202F;4 transform that represents a rotation about the <i>y</i> axis.
			/// \param angle	The angle through which to rotate, in radians.

			TERATHON_API static Transform3D MakeRotationY(float angle);

			/// \brief Returns a 4&#x202F;&times;&#x202F;4 transform that represents a rotation about the <i>z</i> axis.
			/// \param angle	The angle through which to rotate, in radians.

			TERATHON_API static Transform3D MakeRotationZ(float angle);

			/// \brief Returns a 4&#x202F;&times;&#x202F;4 transform that represents a rotation about an arbitrary axis.
			/// \param angle	The angle through which to rotate, in radians.
			/// \param axis		The axis about which to rotate. This bivector must have unit magnitude.

			TERATHON_API static Transform3D MakeRotation(float angle, const Bivector3D& axis);

			TERATHON_API static Transform3D MakeReflection(const Vector3D& a);
			TERATHON_API static Transform3D MakeInvolution(const Vector3D& a);
			TERATHON_API static Transform3D MakeReflection(const Plane3D& plane);

			/// \brief Returns a 4&#x202F;&times;&#x202F;4 transform that represents a uniform scale.
			/// \param scale	The scale along all three axes.

			TERATHON_API static Transform3D MakeScale(float scale);

			TERATHON_API static Transform3D MakeScale(float sx, float sy, float sz);
			TERATHON_API static Transform3D MakeScale(float scale, const Vector3D& axis);
			TERATHON_API static Transform3D MakeScaleX(float sx);
			TERATHON_API static Transform3D MakeScaleY(float sy);
			TERATHON_API static Transform3D MakeScaleZ(float sz);

			TERATHON_API static Transform3D MakeSkew(float angle, const Vector3D& a, const Vector3D& b);

			TERATHON_API static Transform3D MakeTranslation(const Vector3D& dv);
	};


	template <typename type_struct, int count, int index_x, int index_y, int index_z>
	inline Vector3D operator *(const Transform3D& m, const Subvec3D<type_struct, false, count, index_x, index_y, index_z>& v)
	{
		return (m.matrix3D * v);
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z>
	inline Bivector3D operator *(const Subvec3D<type_struct, true, count, index_x, index_y, index_z>& v, const Transform3D& m)
	{
		return (v * m.matrix3D);
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
	Vector4D operator *(const Transform3D& m, const Subvec4D<type_struct, false, count, index_x, index_y, index_z, index_w>& v)
	{
		return (Vector4D(m(0,0) * v.data[index_x] + m(0,1) * v.data[index_y] + m(0,2) * v.data[index_z] + m(0,3) * v.data[index_w],
		                 m(1,0) * v.data[index_x] + m(1,1) * v.data[index_y] + m(1,2) * v.data[index_z] + m(1,3) * v.data[index_w],
		                 m(2,0) * v.data[index_x] + m(2,1) * v.data[index_y] + m(2,2) * v.data[index_z] + m(2,3) * v.data[index_w],
		                 v.data[index_w]));
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
	Antivector4D operator *(const Subvec4D<type_struct, true, count, index_x, index_y, index_z, index_w>& v, const Transform3D& m)
	{
		return (Antivector4D(m(0,0) * v.data[index_x] + m(1,0) * v.data[index_y] + m(2,0) * v.data[index_z],
		                     m(0,1) * v.data[index_x] + m(1,1) * v.data[index_y] + m(2,1) * v.data[index_z],
		                     m(0,2) * v.data[index_x] + m(1,2) * v.data[index_y] + m(2,2) * v.data[index_z],
		                     m(0,3) * v.data[index_x] + m(1,3) * v.data[index_y] + m(2,3) * v.data[index_z] + v.data[index_w]));
	}

	inline Vector4D operator *(const Transform3D& m, const Vector4D& v)
	{
		return (m * v.xyzw);
	}

	inline Antivector4D operator *(const Antivector4D& v, const Transform3D& m)
	{
		return (v.xyzw * m);
	}

	template <typename type_struct, int count, int index_00, int index_01, int index_02, int index_10, int index_11, int index_12, int index_20, int index_21, int index_22>
	inline Transform3D operator *(const Transform3D& m1, const Submat3D<type_struct, count, index_00, index_01, index_02, index_10, index_11, index_12, index_20, index_21, index_22>& m2)
	{
		Transform3D		transform;

		transform.matrix3D = m1.matrix3D * m2;
		transform[3] = m1[3];

		transform.m30 = transform.m31 = transform.m32 = 0.0F;
		transform.m33 = 1.0F;
		return (transform);
	}

	template <typename type_struct, int count, int index_00, int index_01, int index_02, int index_10, int index_11, int index_12, int index_20, int index_21, int index_22>
	inline Transform3D operator *(const Submat3D<type_struct, count, index_00, index_01, index_02, index_10, index_11, index_12, index_20, index_21, index_22>& m1, const Transform3D& m2)
	{
		Transform3D		transform;

		transform.matrix3D = m1 * m2.matrix3D;
		transform[3] = m1 * m2[3];

		transform.m30 = transform.m31 = transform.m32 = 0.0F;
		transform.m33 = 1.0F;
		return (transform);
	}

	inline Transform3D operator *(const Transform3D& m1, const Matrix3D& m2)
	{
		return (m1 * m2.matrix);
	}

	inline Transform3D operator *(const Matrix3D& m1, const Transform3D& m2)
	{
		return (m1.matrix * m2);
	}


	/// \brief Returns the product of the transforms $m1$ and $m2$.
	/// \related Transform3D

	TERATHON_API Transform3D operator *(const Transform3D& m1, const Transform3D& m2);

	TERATHON_API Matrix4D operator *(const Matrix4D& m1, const Transform3D& m2);
	TERATHON_API Matrix4D operator *(const Transform3D& m1, const Matrix4D& m2);
	TERATHON_API Vector3D operator *(const Transform3D& m, const Vector3D& v);
	TERATHON_API Bivector3D operator *(const Bivector3D& v, const Transform3D& m);
	TERATHON_API Point3D operator *(const Transform3D& m, const Point3D& p);
	TERATHON_API Vector2D operator *(const Transform3D& m, const Vector2D& v);
	TERATHON_API Point2D operator *(const Transform3D& m, const Point2D& p);

	TERATHON_API Transform3D Scale(const Transform3D& m, const Vector3D& v);
	TERATHON_API Matrix3D Transform(const Transform3D& m1, const Matrix3D& m2);

	#ifndef TERATHON_NO_SIMD

		TERATHON_API vec_float TransformVector3D(const Transform3D& m, vec_float v);
		TERATHON_API vec_float TransformPoint3D(const Transform3D& m, vec_float p);

	#endif

	/// \brief Returns the determinant of the transform $m$.
	/// \related Transform3D

	TERATHON_API float Determinant(const Transform3D& m);

	/// \brief Returns the inverse of the transform $m$. If $m$ is singular, then the result is undefined.
	/// \related Transform3D

	TERATHON_API Transform3D Inverse(const Transform3D& m);

	/// \brief Returns the inverse of the transform $m$ assuming that its determinant is one.
	/// \related Transform3D

	TERATHON_API Transform3D InverseUnitDet(const Transform3D& m);

	TERATHON_API Matrix3D InverseUnitDet3D(const Transform3D& m);
	TERATHON_API Vector3D InverseTransform(const Transform3D& m, const Vector3D& v);
	TERATHON_API Point3D InverseTransform(const Transform3D& m, const Point3D& p);
	TERATHON_API Vector3D InverseUnitDetTransform(const Transform3D& m, const Vector3D& v);
	TERATHON_API Point3D InverseUnitDetTransform(const Transform3D& m, const Point3D& p);


	// ==============================================
	//	POD Structures
	// ==============================================

	struct ConstMatrix4D
	{
		alignas(16) float	n[4][4];

		operator const Matrix4D&(void) const
		{
			return (reinterpret_cast<const Matrix4D&>(*this));
		}

		const Matrix4D *operator &(void) const
		{
			return (reinterpret_cast<const Matrix4D *>(this));
		}

		const Matrix4D *operator ->(void) const
		{
			return (reinterpret_cast<const Matrix4D *>(this));
		}

		float operator ()(int32 i, int32 j) const
		{
			return (reinterpret_cast<const Matrix4D&>(*this)(i, j));
		}

		const Vector4D& operator [](machine j) const
		{
			return (reinterpret_cast<const Matrix4D&>(*this)[j]);
		}
	};


	struct ConstTransform3D
	{
		alignas(16) float	n[4][4];

		operator const Transform3D&(void) const
		{
			return (reinterpret_cast<const Transform3D&>(*this));
		}

		const Transform3D *operator &(void) const
		{
			return (reinterpret_cast<const Transform3D *>(this));
		}

		const Transform3D *operator ->(void) const
		{
			return (reinterpret_cast<const Transform3D *>(this));
		}

		float operator ()(int32 i, int32 j) const
		{
			return (reinterpret_cast<const Transform3D&>(*this)(i, j));
		}

		const Vector3D& operator [](machine j) const
		{
			return (reinterpret_cast<const Transform3D&>(*this)[j]);
		}
	};
}


#endif
