//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2022, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSMatrix2D_h
#define TSMatrix2D_h


//# \component	Math Library
//# \prefix		Math/


#include "TSVector2D.h"


#define TERATHON_MATRIX2D 1


namespace Terathon
{
	class Matrix2D;
	struct ConstMatrix2D;


	//# \class	Matrix2D	Encapsulates a 2&#x202F;&times;&#x202F;2 matrix.
	//
	//# The $Matrix2D$ class encapsulates a 2&#x202F;&times;&#x202F;2 matrix.
	//
	//# \def	class Matrix2D : public Mat2D<TypeMatrix2D>
	//
	//# \ctor	Matrix2D();
	//# \ctor	Matrix2D(float n00, float n01, float n10, float n11);
	//# \ctor	Matrix2D(const Vector2D& a, const Vector2D& b);
	//
	//# \param	nij		The value of the entry residing in row <i>i</i> and column <i>j</i>.
	//# \param	a		The values of the entries residing in first column.
	//# \param	b		The values of the entries residing in second column.
	//
	//# \desc
	//# The $Matrix2D$ class is used to store a 2&#x202F;&times;&#x202F;2 matrix. The entries of the matrix
	//# are accessed using the $()$ operator with two indexes specifying the row and column of an entry.
	//#
	//# The default constructor leaves the entries of the matrix undefined. If the four entries are
	//# supplied, then the $n$<i>ij</i> parameter specifies the entry in the <i>i</i>-th row and
	//# <i>j</i>-th column. If the matrix is constructed using the two vectors $a$ and $b$, then
	//# these vectors initialize the two columns of the matrix.
	//
	//# \operator	float& operator ()(machine i, machine j);
	//#				Returns a reference to the entry in the <i>i</i>-th row and <i>j</i>-th column.
	//#				Both $i$ and $j$ must be 0 or 1.
	//
	//# \operator	const float& operator ()(machine i, machine j) const;
	//#				Returns a constant reference to the entry in the <i>i</i>-th row and <i>j</i>-th column.
	//#				Both $i$ and $j$ must be 0 or 1.
	//
	//# \operator	Vector2D& operator [](machine j);
	//#				Returns a reference to the <i>j</i>-th column of a matrix. $j$ must be 0 or 1.
	//
	//# \operator	const Vector2D& operator [](machine j) const;
	//#				Returns a constant reference to the <i>j</i>-th column of a matrix. $j$ must be 0 or 1.
	//
	//# \operator	Matrix2D& operator *=(const Matrix2D& m);
	//#				Multiplies by the matrix $m$.
	//
	//# \operator	Matrix2D& operator *=(float s);
	//#				Multiplies by the scalar $s$.
	//
	//# \operator	Matrix2D& operator /=(float s);
	//#				Multiplies by the inverse of the scalar $s$.
	//
	//# \action		Matrix2D operator *(const Matrix2D& m1, const Matrix2D& m2);
	//#				Returns the product of the matrices $m1$ and $m2$.
	//
	//# \action		Matrix2D operator *(const Matrix2D& m, float s);
	//#				Returns the product of the matrix $m$ and the scalar $s$.
	//
	//# \action		Matrix2D operator /(const Matrix2D& m, float s);
	//#				Returns the product of the matrix $m$ and the inverse of the scalar $s$.
	//
	//# \action		Vector2D operator *(const Matrix2D& m, const Vector2D& v);
	//#				Returns the product of the matrix $m$ and the column vector $v$.
	//
	//# \action		Point2D operator *(const Matrix2D& m, const Point2D& p);
	//#				Returns the product of the matrix $m$ and the column vector $p$.
	//
	//# \action		Vector2D operator *(const Vector2D& v, const Matrix2D& m);
	//#				Returns the product of the row vector $v$ and the matrix $m$.
	//
	//# \action		float Determinant(const Matrix2D& m);
	//#				Returns the determinant of the matrix $m$.
	//
	//# \action		Matrix2D Inverse(const Matrix2D& m);
	//#				Returns the inverse of the matrix $m$. If $m$ is singular, then the result is undefined.
	//
	//# \action		Matrix2D Adjugate(const Matrix2D& m);
	//#				Returns the adjugate of the matrix $m$.
	//
	//# \privbase	Mat2D	Matrices use a generic base class to store their components.
	//
	//# \also	$@Vector2D@$


	//# \function	Matrix2D::Set		Sets all four entries of a matrix.
	//
	//# \proto	Matrix2D& Set(float n00, float n01, float n10, float n11);
	//# \proto	Matrix2D& Set(const Vector2D& a, const Vector2D& b);
	//
	//# \param	nij		The new value of the entry residing in row <i>i</i> and column <i>j</i>.
	//# \param	a		The new values of the entries residing in first column.
	//# \param	b		The new values of the entries residing in second column.
	//
	//# \desc
	//# The $Set$ function sets all four entries of a matrix, either by specifying each entry individually
	//# or by specifying each of the two columns as 2D vectors.
	//#
	//# The return value is a reference to the matrix object.
	//
	//# \also	$@Matrix2D::SetIdentity@$
	//# \also	$@Matrix2D::MakeRotation@$


	//# \function	Matrix2D::SetIdentity		Sets a matrix to the 2&#x202F;&times;&#x202F;2 identity matrix.
	//
	//# \proto	Matrix2D& SetIdentity(void);
	//
	//# \desc
	//# The $SetIdentity$ function replaces all entries of a matrix with the entries of the identity matrix.
	//#
	//# The return value is a reference to the matrix object.
	//
	//# \also	$@Matrix2D::Set@$
	//# \also	$@Matrix2D::MakeRotation@$


	//# \function	Matrix2D::Orthogonalize		Orthogonalizes the columns of a matrix.
	//
	//# \proto	Matrix2D& Orthogonalize(column);
	//
	//# \param	column		The index of the column whose direction does not change. This must be 0 or 1.
	//
	//# \desc
	//# The $Orthogonalize$ function uses Gram-Schmidt orthogonalization to orthogonalize the columns
	//# of a matrix. The column whose index is specified by the $column$ parameter is normalized to unit length.
	//# The remaining column is orthogonalized and made unit length. Only the column not specified
	//# by the $column$ parameter can change direction.


	//# \function	Matrix2D::MakeRotation		Returns a matrix that represents a rotation in the 2D plane.
	//
	//# \proto	static Matrix2D MakeRotation(float angle);
	//
	//# \param	angle	The angle through which to rotate, in radians.
	//
	//# \desc
	//# The $MakeRotation$ function returns a matrix representing a rotation through the angle given
	//# by the $angle$ parameter in the 2D plane.
	//
	//# \also	$@Matrix2D::SetIdentity@$
	//# \also	$@Matrix2D::Set@$


	//# \function	Matrix2D::MakeScale		Returns a matrix that represents a scale.
	//
	//# \proto	static Matrix2D MakeScale(float scale);
	//# \proto	static Matrix2D MakeScale(float sx, float sy);
	//
	//# \param	scale	The scale along both axes.
	//# \param	sx		The scale along the <i>x</i> axis.
	//# \param	sy		The scale along the <i>y</i> axis.
	//
	//# \desc
	//# The $MakeScale$ function returns a matrix representing a scale.
	//# If only the $scale$ parameter is specified, then the scale is uniform along both axes.
	//# If the $sx$ and $sy$ parameters are specified, then they correspond to the scale along
	//# the <i>x</i> and <i>y</i> axis, respectively.
	//
	//# \also	$@Matrix2D::SetIdentity@$
	//# \also	$@Matrix2D::Set@$


	struct TypeMatrix2D
	{
		typedef float component_type;
		typedef Matrix2D matrix2D_type;
		typedef TypeVector2D column_type_struct;
		typedef TypeVector2D row_type_struct;
	};


	class Matrix2D : public Mat2D<TypeMatrix2D>
	{
		public:

			TERATHON_API static const ConstMatrix2D identity;

			inline Matrix2D() = default;

			TERATHON_API Matrix2D(float n00, float n01, float n10, float n11);
			TERATHON_API Matrix2D(const Vector2D& a, const Vector2D& b);

			TERATHON_API Matrix2D& Set(float n00, float n01, float n10, float n11);
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

			TERATHON_API Matrix2D& SetIdentity(void);
			TERATHON_API Matrix2D& Orthogonalize(int32 column);

			TERATHON_API static Matrix2D MakeRotation(float angle);

			TERATHON_API static Matrix2D MakeScaleX(float sx);
			TERATHON_API static Matrix2D MakeScaleY(float sy);
			TERATHON_API static Matrix2D MakeScale(float scale);
			TERATHON_API static Matrix2D MakeScale(float sx, float sy);
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

	inline Vector2D operator *(const Matrix2D& m, const Vector2D& v)
	{
		return (m.matrix * v.xy);
	}

	inline Point2D operator *(const Matrix2D& m, const Point2D& p)
	{
		return (Point2D::origin + m.matrix * p.xy);
	}

	inline Vector2D operator *(const Vector2D& v, const Matrix2D& m)
	{
		return (v.xy * m.matrix);
	}

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


	TERATHON_API float Determinant(const Matrix2D& m);
	TERATHON_API Matrix2D Inverse(const Matrix2D& m);
	TERATHON_API Matrix2D Adjugate(const Matrix2D& m);
}


#endif
