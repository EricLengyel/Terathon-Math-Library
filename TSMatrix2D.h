//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSMatrix2D_h
#define TSMatrix2D_h


#include "TSVector2D.h"


#define TERATHON_MATRIX2D 1


namespace Terathon
{
	class Matrix2D;
	struct ConstMatrix2D;


	// ==============================================
	//	Matrix2D
	// ==============================================

	struct TypeMatrix2D
	{
		typedef float component_type;
		typedef Matrix2D matrix2D_type;
		typedef TypeVector2D column_type_struct;
		typedef TypeVector2D row_type_struct;
	};


	/// \brief Encapsulates a 2&#x202F;&times;&#x202F;2 matrix.
	///
	/// The $Matrix2D$ class is used to store a 2&#x202F;&times;&#x202F;2 matrix. The entries of the matrix
	/// are accessed using the () operator with two indexes specifying the row and column of an entry.
	///
	/// \also Matrix3D
	/// \also Matrix4D
	/// \also Transform2D
	/// \also Transform3D

	class Matrix2D : public Mat2D<TypeMatrix2D>
	{
		public:

			TERATHON_API static const ConstMatrix2D identity;

			/// \brief Default constructor that leaves the entries uninitialized.

			inline Matrix2D() = default;

			Matrix2D(const Matrix2D& m)
			{
				matrix = m.matrix;
			}

			/// \brief Constructor that sets entries explicitly.
			/// \param n00,n01,n10,n11		The entries of the matrix.

			TERATHON_API Matrix2D(float n00, float n01, float n10, float n11);

			/// \brief Constructor that sets columns explicitly.
			/// \param a,b		The columns of the matrix.

			TERATHON_API Matrix2D(const Vector2D& a, const Vector2D& b);

			/// \brief Sets all four entries of a 2&#x202F;&times;&#x202F;2 matrix.
			/// \param n00,n01,n10,n11		The new entries of the matrix.

			TERATHON_API Matrix2D& Set(float n00, float n01, float n10, float n11);

			/// \brief Sets both columns of a 2&#x202F;&times;&#x202F;2 matrix.
			/// \param a,b		The new columns of the matrix.

			TERATHON_API Matrix2D& Set(const Vector2D& a, const Vector2D& b);

			Matrix2D& operator =(const Matrix2D& m)
			{
				matrix = m.matrix;
				return (*this);
			}

			void operator =(const Matrix2D& m) volatile
			{
				matrix = m.matrix;
			}

			template <typename type_struct, int count, int index_00, int index_01, int index_10, int index_11>
			Matrix2D& operator =(const Submat2D<type_struct, count, index_00, index_01, index_10, index_11>& m)
			{
				matrix = m;
				return (*this);
			}

			template <typename type_struct, int count, int index_00, int index_01, int index_10, int index_11>
			void operator =(const Submat2D<type_struct, count, index_00, index_01, index_10, index_11>& m) volatile
			{
				matrix = m;
			}

			TERATHON_API Matrix2D& operator *=(const Matrix2D& m);
			TERATHON_API Matrix2D& operator *=(float s);
			TERATHON_API Matrix2D& operator /=(float s);

			/// \brief Sets a matrix to the 2&#x202F;&times;&#x202F;2 identity matrix.

			TERATHON_API Matrix2D& SetIdentity(void);

			/// \brief Orthogonalizes the columns of a 2&#x202F;&times;&#x202F;2 matrix.
			/// \param column	The index of the column whose direction does not change. This must be 0 or 1.
			///
			/// The $Orthogonalize()$ function uses Gram-Schmidt orthogonalization to orthogonalize the columns
			/// of a matrix. The column whose index is specified by the $column$ parameter is normalized to unit length.
			/// The remaining column is orthogonalized and made unit length. Only the column not specified by the
			/// $column$ parameter can change direction.

			TERATHON_API Matrix2D& Orthogonalize(int32 column);

			/// \brief Returns a 2&#x202F;&times;&#x202F;2 matrix that represents a rotation in the 2D plane.
			/// \param angle	The angle through which to rotate, in radians.

			TERATHON_API static Matrix2D MakeRotation(float angle);

			/// \brief Returns a 2&#x202F;&times;&#x202F;2 matrix that represents a uniform scale.
			/// \param scale	The scale along both axes.

			TERATHON_API static Matrix2D MakeScale(float scale);

			TERATHON_API static Matrix2D MakeScale(float sx, float sy);
			TERATHON_API static Matrix2D MakeScaleX(float sx);
			TERATHON_API static Matrix2D MakeScaleY(float sy);
	};


	template <typename type_struct, int count, int index_x, int index_y>
	inline typename type_struct::vector2D_type operator *(const Matrix2D& m, const Subvec2D<type_struct, count, index_x, index_y>& v)
	{
		return (m.matrix * v);
	}

	template <typename type_struct, int count, int index_x, int index_y>
	inline typename type_struct::vector2D_type operator *(const Subvec2D<type_struct, count, index_x, index_y>& v, const Matrix2D& m)
	{
		return (v * m.matrix);
	}

	template <typename type_struct, int count, int index_00, int index_01, int index_10, int index_11>
	inline Vector2D operator *(const Submat2D<type_struct, count, index_00, index_01, index_10, index_11>& m, const Vector2D& v)
	{
		return (m * v.xy);
	}

	template <typename type_struct, int count, int index_00, int index_01, int index_10, int index_11>
	inline Vector2D operator *(const Vector2D& v, const Submat2D<type_struct, count, index_00, index_01, index_10, index_11>& m)
	{
		return (v.xy * m);
	}

	/// \brief Returns the product of the matrix $m$ and the column vector $v$.
	/// \related Matrix2D

	inline Vector2D operator *(const Matrix2D& m, const Vector2D& v)
	{
		return (m.matrix * v.xy);
	}

	/// \brief Returns the product of the matrix $m$ and the column vector $p$.
	/// \related Matrix2D

	inline Point2D operator *(const Matrix2D& m, const Point2D& p)
	{
		return (Point2D::origin + m.matrix * p.xy);
	}

	/// \brief Returns the product of the row vector $v$ and the matrix $m$.
	/// \related Matrix2D

	inline Vector2D operator *(const Vector2D& v, const Matrix2D& m)
	{
		return (v.xy * m.matrix);
	}

	/// \brief Returns the product of the matrices $m1$ and $m2$.
	/// \related Matrix2D

	inline Matrix2D operator *(const Matrix2D& m1, const Matrix2D& m2)
	{
		return (m1.matrix * m2.matrix);
	}

	template <typename type_struct, int count, int index_00, int index_01, int index_10, int index_11>
	inline Matrix2D operator *(const Matrix2D& m1, const Submat2D<type_struct, count, index_00, index_01, index_10, index_11>& m2)
	{
		return (m1.matrix * m2);
	}

	template <typename type_struct, int count, int index_00, int index_01, int index_10, int index_11>
	inline Matrix2D operator *(const Submat2D<type_struct, count, index_00, index_01, index_10, index_11>& m1, const Matrix2D& m2)
	{
		return (m1 * m2.matrix);
	}


	TERATHON_API Matrix2D operator *(const Matrix2D& m, float s);
	TERATHON_API Matrix2D operator /(const Matrix2D& m, float s);

	inline Matrix2D operator *(float s, const Matrix2D& m)
	{
		return (m * s);
	}


	/// \brief Returns the determinant of the matrix $m$.
	/// \related Matrix2D

	TERATHON_API float Determinant(const Matrix2D& m);

	/// \brief Returns the inverse of the matrix $m$. If $m$ is singular, then the result is undefined.
	/// \related Matrix2D

	TERATHON_API Matrix2D Inverse(const Matrix2D& m);

	/// \brief Returns the adjugate of the matrix $m$.
	/// \related Matrix2D

	TERATHON_API Matrix2D Adjugate(const Matrix2D& m);


	// ==============================================
	//	POD Structures
	// ==============================================

	struct ConstMatrix2D
	{
		float	n[2][2];

		operator const Matrix2D&(void) const
		{
			return (reinterpret_cast<const Matrix2D&>(*this));
		}

		const Matrix2D *operator &(void) const
		{
			return (reinterpret_cast<const Matrix2D *>(this));
		}

		const Matrix2D *operator ->(void) const
		{
			return (reinterpret_cast<const Matrix2D *>(this));
		}

		float operator ()(int32 i, int32 j) const
		{
			return (reinterpret_cast<const Matrix2D&>(*this)(i, j));
		}

		const Vector2D& operator [](machine j) const
		{
			return (reinterpret_cast<const Matrix2D&>(*this)[j]);
		}
	};
}


#endif
