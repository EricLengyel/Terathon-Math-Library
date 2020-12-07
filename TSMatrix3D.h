//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2021, Terathon Software LLC
//
// This software is licensed under the GNU General Public License version 3.
// Separate proprietary licenses are available from Terathon Software.
//
// THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
// EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. 
//


#ifndef TSMatrix3D_h
#define TSMatrix3D_h


//# \component	Math Library
//# \prefix		Math/


#include "TSBivector3D.h"
#include "TSMatrix2D.h"


#define TERATHON_MATRIX3D 1


namespace Terathon
{
	class Matrix3D;
	class Matrix4D;
	class Transform4D;


	//# \class	Matrix3D	Encapsulates a 3&#x202F;&times;&#x202F;3 matrix.
	//
	//# The $Matrix3D$ class encapsulates a 3&#x202F;&times;&#x202F;3 matrix.
	//
	//# \def	class Matrix3D : public Mat3D<TypeMatrix3D>
	//
	//# \ctor	Matrix3D();
	//# \ctor	Matrix3D(float n00, float n01, float n02, float n10, float n11, float n12, float n20, float n21, float n22);
	//# \ctor	Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c);
	//
	//# \param	nij		The value of the entry residing in row <i>i</i> and column <i>j</i>.
	//# \param	a		The values of the entries residing in first column.
	//# \param	b		The values of the entries residing in second column.
	//# \param	c		The values of the entries residing in third column.
	//
	//# \desc
	//# The $Matrix3D$ class is used to store a 3&#x202F;&times;&#x202F;3 matrix. The entries of the matrix
	//# are accessed using the $()$ operator with two indexes specifying the row and column of an entry.
	//#
	//# The default constructor leaves the entries of the matrix undefined. If the nine entries are
	//# supplied, then the $n$<i>ij</i> parameter specifies the entry in the <i>i</i>-th row and
	//# <i>j</i>-th column. If the matrix is constructed using the three vectors $a$, $b$, and
	//# $c$, then these vectors initialize the three columns of the matrix.
	//
	//# \operator	float& operator ()(machine i, machine j);
	//#				Returns a reference to the entry in the <i>i</i>-th row and <i>j</i>-th column.
	//#				Both $i$ and $j$ must be 0, 1, or 2.
	//
	//# \operator	const float& operator ()(machine i, machine j) const;
	//#				Returns a constant reference to the entry in the <i>i</i>-th row and <i>j</i>-th column.
	//#				Both $i$ and $j$ must be 0, 1, or 2.
	//
	//# \operator	Vector3D& operator [](machine j);
	//#				Returns a reference to the <i>j</i>-th column of a matrix. $j$ must be 0, 1, or 2.
	//
	//# \operator	const Vector3D& operator [](machine j) const;
	//#				Returns a constant reference to the <i>j</i>-th column of a matrix. $j$ must be 0, 1, or 2.
	//
	//# \operator	Matrix3D& operator *=(const Matrix3D& m);
	//#				Multiplies by the matrix $m$.
	//
	//# \operator	Matrix3D& operator *=(float s);
	//#				Multiplies by the scalar $s$.
	//
	//# \operator	Matrix3D& operator /=(float s);
	//#				Multiplies by the inverse of the scalar $s$.
	//
	//# \action		Matrix3D operator *(const Matrix3D& m1, const Matrix3D& m2);
	//#				Returns the product of the matrices $m1$ and $m2$.
	//
	//# \action		Matrix3D operator *(const Matrix3D& m, float s);
	//#				Returns the product of the matrix $m$ and the scalar $s$.
	//
	//# \action		Matrix3D operator /(const Matrix3D& m, float s);
	//#				Returns the product of the matrix $m$ and the inverse of the scalar $s$.
	//
	//# \action		Vector3D operator *(const Matrix3D& m, const Vector3D& v);
	//#				Returns the product of the matrix $m$ and the column vector $v$.
	//
	//# \action		Point3D operator *(const Matrix3D& m, const Point3D& p);
	//#				Returns the product of the matrix $m$ and the column vector $p$.
	//
	//# \action		Vector3D operator *(const Vector3D& v, const Matrix3D& m);
	//#				Returns the product of the row vector $v$ and the matrix $m$.
	//
	//# \action		Bivector3D operator *(const Bivector3D& v, const Matrix3D& m);
	//#				Returns the product of the row bivector $v$ and the matrix $m$.
	//
	//# \action		float Determinant(const Matrix3D& m);
	//#				Returns the determinant of the matrix $m$.
	//
	//# \action		Matrix3D Inverse(const Matrix3D& m);
	//#				Returns the inverse of the matrix $m$. If $m$ is singular, then the result is undefined.
	//
	//# \action		Matrix3D Adjugate(const Matrix3D& m);
	//#				Returns the adjugate of the matrix $m$.
	//
	//# \privbase	Mat3D	Matrices use a generic base class to store their components.
	//
	//# \also	$@Vector3D@$
	//# \also	$@Matrix4D@$
	//# \also	$@Transform4D@$


	//# \function	Matrix3D::Set		Sets all nine entries of a matrix.
	//
	//# \proto	Matrix3D& Set(float n00, float n01, float n02, float n10, float n11, float n12, float n20, float n21, float n22);
	//# \proto	Matrix3D& Set(const Vector3D& a, const Vector3D& b, const Vector3D& c);
	//
	//# \param	nij		The new value of the entry residing in row <i>i</i> and column <i>j</i>.
	//# \param	a		The new values of the entries residing in first column.
	//# \param	b		The new values of the entries residing in second column.
	//# \param	c		The new values of the entries residing in third column.
	//
	//# \desc
	//# The $Set$ function sets all nine entries of a matrix, either by specifying each entry individually
	//# or by specifying each of the three columns as 3D vectors.
	//#
	//# The return value is a reference to the matrix object.
	//
	//# \also	$@Matrix3D::SetIdentity@$
	//# \also	$@Matrix3D::MakeRotationX@$
	//# \also	$@Matrix3D::MakeRotationY@$
	//# \also	$@Matrix3D::MakeRotationZ@$
	//# \also	$@Matrix3D::MakeRotation@$


	//# \function	Matrix3D::SetIdentity		Sets a matrix to the 3&#x202F;&times;&#x202F;3 identity matrix.
	//
	//# \proto	Matrix3D& SetIdentity(void);
	//
	//# \desc
	//# The $SetIdentity$ function replaces all entries of a matrix with the entries of the identity matrix.
	//#
	//# The return value is a reference to the matrix object.
	//
	//# \also	$@Matrix3D::Set@$
	//# \also	$@Matrix3D::MakeRotationX@$
	//# \also	$@Matrix3D::MakeRotationY@$
	//# \also	$@Matrix3D::MakeRotationZ@$
	//# \also	$@Matrix3D::MakeRotation@$


	//# \function	Matrix3D::Orthogonalize		Orthogonalizes the columns of a matrix.
	//
	//# \proto	Matrix3D& Orthogonalize(column);
	//
	//# \param	column		The index of the column whose direction does not change. This must be 0, 1, or 2.
	//
	//# \desc
	//# The $Orthogonalize$ function uses Gram-Schmidt orthogonalization to orthogonalize the columns
	//# of a matrix. The column whose index is specified by the $column$ parameter is normalized to unit length.
	//# The remaining two columns are orthogonalized and made unit length. Only the two columns not specified
	//# by the $column$ parameter can change direction.


	//# \function	Matrix3D::MakeRotationX		Returns a matrix that represents a rotation about the <i>x</i> axis.
	//
	//# \proto	static Matrix3D MakeRotationX(float angle);
	//
	//# \param	angle	The angle through which to rotate, in radians.
	//
	//# \desc
	//# The $MakeRotationX$ function returns a matrix representing a rotation through the angle given
	//# by the $angle$ parameter about the <i>x</i> axis.
	//
	//# \also	$@Matrix3D::MakeRotationY@$
	//# \also	$@Matrix3D::MakeRotationZ@$
	//# \also	$@Matrix3D::MakeRotation@$
	//# \also	$@Matrix3D::SetIdentity@$
	//# \also	$@Matrix3D::Set@$


	//# \function	Matrix3D::MakeRotationY		Returns a matrix that represents a rotation about the <i>y</i> axis.
	//
	//# \proto	static Matrix3D MakeRotationY(float angle);
	//
	//# \param	angle	The angle through which to rotate, in radians.
	//
	//# \desc
	//# The $MakeRotationY$ function returns a matrix representing a rotation through the angle given
	//# by the $angle$ parameter about the <i>y</i> axis.
	//
	//# \also	$@Matrix3D::MakeRotationX@$
	//# \also	$@Matrix3D::MakeRotationZ@$
	//# \also	$@Matrix3D::MakeRotation@$
	//# \also	$@Matrix3D::SetIdentity@$
	//# \also	$@Matrix3D::Set@$


	//# \function	Matrix3D::MakeRotationZ		Returns a matrix that represents a rotation about the <i>z</i> axis.
	//
	//# \proto	static Matrix3D MakeRotationZ(float angle);
	//
	//# \param	angle	The angle through which to rotate, in radians.
	//
	//# \desc
	//# The $MakeRotationZ$ function returns a matrix representing a rotation through the angle given
	//# by the $angle$ parameter about the <i>z</i> axis.
	//
	//# \also	$@Matrix3D::MakeRotationX@$
	//# \also	$@Matrix3D::MakeRotationY@$
	//# \also	$@Matrix3D::MakeRotation@$
	//# \also	$@Matrix3D::SetIdentity@$
	//# \also	$@Matrix3D::Set@$


	//# \function	Matrix3D::MakeRotation		Returns a matrix that represents a rotation about a given axis.
	//
	//# \proto	static Matrix3D MakeRotation(float angle, const Bivector3D& axis);
	//
	//# \param	angle	The angle through which to rotate, in radians.
	//# \param	axis	The axis about which to rotate. This bivector must have unit magnitude.
	//
	//# \desc
	//# The $MakeRotation$ function returns a matrix representing a rotation through the angle
	//# given by the $angle$ parameter about the axis given by the $axis$ parameter.
	//
	//# \also	$@Matrix3D::MakeRotationX@$
	//# \also	$@Matrix3D::MakeRotationY@$
	//# \also	$@Matrix3D::MakeRotationZ@$
	//# \also	$@Matrix3D::SetIdentity@$
	//# \also	$@Matrix3D::Set@$


	//# \function	Matrix3D::MakeScale		Returns a matrix that represents a scale.
	//
	//# \proto	static Matrix3D MakeScale(float scale);
	//# \proto	static Matrix3D MakeScale(float sx, float sy, float sz);
	//
	//# \param	scale	The scale along all three axes.
	//# \param	sx		The scale along the <i>x</i> axis.
	//# \param	sy		The scale along the <i>y</i> axis.
	//# \param	sz		The scale along the <i>z</i> axis.
	//
	//# \desc
	//# The $MakeScale$ function returns a matrix representing a scale.
	//# If only the $scale$ parameter is specified, then the scale is uniform along all three axes.
	//# If the $sx$, $sy$, and $sz$ parameters are specified, then they correspond to the scale along
	//# the <i>x</i>, <i>y</i>, and <i>z</i> axis, respectively.
	//
	//# \also	$@Matrix3D::SetIdentity@$
	//# \also	$@Matrix3D::Set@$


	struct TypeMatrix3D
	{
		typedef float component_type;
		typedef Matrix2D matrix2D_type;
		typedef Matrix3D matrix3D_type;
		typedef TypeVector3D column_type_struct;
		typedef TypeBivector3D row_type_struct;
	};


	class Matrix3D : public Mat3D<TypeMatrix3D>
	{
		public:

			inline Matrix3D() = default;

			TERATHON_API Matrix3D(float n00, float n01, float n02, float n10, float n11, float n12, float n20, float n21, float n22);
			TERATHON_API Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c);

			TERATHON_API Matrix3D& Set(float n00, float n01, float n02, float n10, float n11, float n12, float n20, float n21, float n22);
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

			TERATHON_API Matrix3D& SetIdentity(void);
			TERATHON_API Matrix3D& Orthogonalize(int32 column);

			TERATHON_API void GetEulerAngles(float *x, float *y, float *z) const;
			TERATHON_API Matrix3D& SetEulerAngles(float x, float y, float z);

			TERATHON_API static Matrix3D MakeRotationX(float angle);
			TERATHON_API static Matrix3D MakeRotationY(float angle);
			TERATHON_API static Matrix3D MakeRotationZ(float angle);
			TERATHON_API static Matrix3D MakeRotation(float angle, const Bivector3D& axis);

			TERATHON_API static Matrix3D MakeReflection(const Vector3D& a);
			TERATHON_API static Matrix3D MakeInvolution(const Vector3D& a);

			TERATHON_API static Matrix3D MakeScaleX(float sx);
			TERATHON_API static Matrix3D MakeScaleY(float sy);
			TERATHON_API static Matrix3D MakeScaleZ(float sz);
			TERATHON_API static Matrix3D MakeScale(float scale);
			TERATHON_API static Matrix3D MakeScale(float sx, float sy, float sz);
			TERATHON_API static Matrix3D MakeScale(float scale, const Vector3D& a);

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
		return (Zero3D + m.matrix * p.xyz);
	}

	inline Bivector3D operator *(const Bivector3D& v, const Matrix3D& m)
	{
		return (v.xyz * m.matrix);
	}

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


	TERATHON_API extern const ConstMatrix3D Identity3D;


	TERATHON_API float Determinant(const Matrix3D& m);
	TERATHON_API Matrix3D Inverse(const Matrix3D& m);
	TERATHON_API Matrix3D Adjugate(const Matrix3D& m);
}


#endif
