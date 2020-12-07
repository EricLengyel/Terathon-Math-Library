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


#ifndef TSMatrix4D_h
#define TSMatrix4D_h


//# \component	Math Library
//# \prefix		Math/


#include "TSTrivector4D.h"
#include "TSMatrix3D.h"


#define TERATHON_MATRIX4D 1
#define TERATHON_TRANSFORM4D 1


namespace Terathon
{
	class Transform4D;


	//# \class	Matrix4D	Encapsulates a 4&#x202F;&times;&#x202F;4 matrix.
	//
	//# The $Matrix4D$ class encapsulates a 4&#x202F;&times;&#x202F;4 matrix.
	//
	//# \def	class Matrix4D : public Mat4D<TypeMatrix4D>
	//
	//# \ctor	Matrix4D();
	//# \ctor	Matrix4D(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13,
	//# \ctor2	float n20, float n21, float n22, float n23, float n30, float n31, float n32, float n33);
	//# \ctor	Matrix4D(const Vector4D& a, const Vector4D& b, const Vector4D& c, const Vector4D& d);
	//
	//# \param	nij		The value of the entry residing in row <i>i</i> and column <i>j</i>.
	//# \param	a		The values of the entries residing in first column.
	//# \param	b		The values of the entries residing in second column.
	//# \param	c		The values of the entries residing in third column.
	//# \param	d		The values of the entries residing in fourth column.
	//
	//# \desc
	//# The $Matrix4D$ class is used to store a 4&#x202F;&times;&#x202F;4 matrix. The entries of the matrix
	//# are accessed using the $()$ operator with two indexes specifying the row and column of an entry.
	//#
	//# The default constructor leaves the entries of the matrix undefined. If the 16 entries are
	//# supplied, then the $n$<i>ij</i> parameter specifies the entry in the <i>i</i>-th row and
	//# <i>j</i>-th column. If the matrix is constructed using the four vectors $a$, $b$, $c$, and
	//# $d$, then these vectors initialize the four columns of the matrix.
	//
	//# \operator	float& operator ()(machine i, machine j);
	//#				Returns a reference to the entry in the <i>i</i>-th row and <i>j</i>-th column.
	//#				Both $i$ and $j$ must be 0, 1, 2, or 3.
	//
	//# \operator	const float& operator ()(machine i, machine j) const;
	//#				Returns a constant reference to the entry in the <i>i</i>-th row and <i>j</i>-th column.
	//#				Both $i$ and $j$ must be 0, 1, 2, or 3.
	//
	//# \operator	Vector4D& operator [](machine j);
	//#				Returns a reference to the <i>j</i>-th column of a matrix. $j$ must be 0, 1, 2, or 3.
	//
	//# \operator	const Vector4D& operator [](machine j) const;
	//#				Returns a constant reference to the <i>j</i>-th column of a matrix. $j$ must be 0, 1, 2, or 3.
	//
	//# \operator	Matrix4D& operator =(const Matrix3D& m);
	//#				Assigns the entries of $m$ to the upper-left 3&#x202F;&times;&#x202F;3 portion of a matrix and
	//#				assigns the entries of the identity matrix to the fourth row and fourth column.
	//
	//# \operator	Matrix4D& operator *=(const Matrix4D& m);
	//#				Multiplies by the matrix $m$.
	//
	//# \operator	Matrix4D& operator *=(const Matrix3D& m);
	//#				Multiplies by the matrix $m$. The entries of the fourth row and fourth column of $m$ are assumed
	//#				to be those of the identity matrix.
	//
	//# \action		Matrix4D operator *(const Matrix4D& m1, const Matrix4D& m2);
	//#				Returns the product of the matrices $m1$ and $m2$.
	//
	//# \action		Matrix4D operator *(const Matrix4D& m1, const Matrix3D& m2);
	//#				Returns the product of the matrices $m1$ and $m2$. The entries of the fourth row and fourth column of $m2$
	//#				are assumed to be those of the identity matrix.
	//
	//# \action		Vector4D operator *(const Matrix4D& m, const Vector4D& v);
	//#				Returns the product of the matrix $m$ and the column vector $v$.
	//
	//# \action		Trivector4D operator *(const Trivector4D& v, const Matrix4D& m);
	//#				Returns the product of the trivector $v$ and the matrix $m$.
	//
	//# \action		Vector4D operator *(const Matrix4D& m, const Vector3D& v);
	//#				Returns the product of the matrix $m$ and the column vector $v$. The <i>w</i> coordinate of $v$ is assumed to be 0.
	//
	//# \action		Vector4D operator *(const Vector3D& v, const Matrix4D& m);
	//#				Returns the product of the row vector $v$ and the matrix $m$. The <i>w</i> coordinate of $v$ is assumed to be 0.
	//
	//# \action		Vector4D operator *(const Matrix4D& m, const Point3D& p);
	//#				Returns the product of the matrix $m$ and the column vector $p$. The <i>w</i> coordinate of $p$ is assumed to be 1.
	//
	//# \action		Vector4D operator *(const Point3D& p, const Matrix4D& m);
	//#				Returns the product of the row vector $p$ and the matrix $m$. The <i>w</i> coordinate of $p$ is assumed to be 1.
	//
	//# \action		Vector4D operator *(const Matrix4D& m, const Vector2D& v);
	//#				Returns the product of the matrix $m$ and the column vector $v$. The <i>z</i> and <i>w</i> coordinates of $v$ are assumed to be 0.
	//
	//# \action		Vector4D operator *(const Vector2D& v, const Matrix4D& m);
	//#				Returns the product of the row vector $v$ and the matrix $m$. The <i>z</i> and <i>w</i> coordinates of $v$ are assumed to be 0.
	//
	//# \action		Vector4D operator *(const Matrix4D& m, const Point2D& p);
	//#				Returns the product of the matrix $m$ and the column vector $p$. The <i>z</i> coordinate of $p$ is assumed to be 0,
	//#				and the <i>w</i> coordinate of $p$ is assumed to be 1.
	//
	//# \action		Vector4D operator *(const Point2D& p, const Matrix4D& m);
	//#				Returns the product of the row vector $p$ and the matrix $m$. The <i>z</i> coordinate of $p$ is assumed to be 0,
	//#				and the <i>w</i> coordinate of $p$ is assumed to be 1.
	//
	//# \action		float Determinant(const Matrix4D& m);
	//#				Returns the determinant of the matrix $m$.
	//
	//# \action		Matrix4D Inverse(const Matrix4D& m);
	//#				Returns the inverse of the matrix $m$. If $m$ is singular, then the result is undefined.
	//
	//# \action		Matrix4D Adjugate(const Matrix4D& m);
	//#				Returns the adjugate of the matrix $m$.
	//
	//# \privbase	Mat4D	Matrices use a generic base class to store their components.
	//
	//# \also	$@Vector4D@$
	//# \also	$@Transform4D@$
	//# \also	$@Matrix3D@$
	//# \also	$@Vector3D@$
	//# \also	$@Point3D@$


	//# \function	Matrix4D::Set		Sets all 16 entries of a matrix.
	//
	//# \proto	Set(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13,
	//# \proto2	float n20, float n21, float n22, float n23, float n30, float n31, float n32, float n33);
	//# \proto	Matrix4D& Set(const Vector4D& a, const Vector4D& b, const Vector4D& c, const Vector4D& d);
	//
	//# \param	nij		The new value of the entry residing in row <i>i</i> and column <i>j</i>.
	//# \param	a		The new values of the entries residing in first column.
	//# \param	b		The new values of the entries residing in second column.
	//# \param	c		The new values of the entries residing in third column.
	//# \param	d		The new values of the entries residing in fourth column.
	//
	//# \desc
	//# The $Set$ function sets all 16 entries of a matrix, either by specifying each entry individually
	//# or by specifying each of the four columns as 4D vectors.
	//#
	//# The return value is a reference to the matrix object.
	//
	//# \also	$@Matrix4D::SetIdentity@$


	//# \function	Matrix4D::SetIdentity		Sets a matrix to the 4&#x202F;&times;&#x202F;4 identity matrix.
	//
	//# \proto	Matrix4D& SetIdentity(void);
	//
	//# \desc
	//# The $SetIdentity$ function replaces all entries of a matrix with the entries of the identity matrix.
	//#
	//# The return value is a reference to the matrix object.
	//
	//# \also	$@Matrix4D::Set@$


	struct TypeMatrix4D
	{
		typedef float component_type;
		typedef Matrix2D matrix2D_type;
		typedef Matrix3D matrix3D_type;
		typedef Matrix4D matrix4D_type;
		typedef TypeVector4D column_type_struct;
		typedef TypeTrivector4D row_type_struct;
	};


	class Matrix4D : public Mat4D<TypeMatrix4D>
	{
		public:

			inline Matrix4D() = default;

			TERATHON_API Matrix4D(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23, float n30, float n31, float n32, float n33);
			TERATHON_API Matrix4D(const Vector4D& a, const Vector4D& b, const Vector4D& c, const Vector4D& d);
			TERATHON_API Matrix4D(const Bivector3D& a, float n03, const Bivector3D& b, float n13, const Bivector3D& c, float n23, const Bivector3D& d, float n33);

			TERATHON_API Matrix4D& Set(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23, float n30, float n31, float n32, float n33);
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
	inline Bivector3D operator *(const Trivector4D& v, const Submat4D<type_struct, count, index_00, index_01, index_02, index_03, index_10, index_11, index_12, index_13, index_20, index_21, index_22, index_23, index_30, index_31, index_32, index_33>& m)
	{
		return (v.xyzw * m);
	}

	inline Vector4D operator *(const Matrix4D& m, const Vector4D& v)
	{
		return (m.matrix * v.xyzw);
	}

	inline Trivector4D operator *(const Trivector4D& v, const Matrix4D& m)
	{
		return (v.xyzw * m.matrix);
	}

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

	TERATHON_API Matrix4D operator *(const Matrix4D& m1, const Transform4D& m2);
	TERATHON_API Matrix4D operator *(const Transform4D& m1, const Matrix4D& m2);

	TERATHON_API float Determinant(const Matrix4D& m);
	TERATHON_API Matrix4D Inverse(const Matrix4D& m);
	TERATHON_API Matrix4D Adjugate(const Matrix4D& m);


	//# \class	Transform4D		Encapsulates a 4&#x202F;&times;&#x202F;4 matrix whose fourth row is always (0,&#x202F;0,&#x202F;0,&#x202F;1).
	//
	//# The $Transform4D$ class encapsulates a 4&#x202F;&times;&#x202F;4 matrix whose fourth row is always (0,&#x202F;0,&#x202F;0,&#x202F;1).
	//
	//# \def	class Transform4D : public Matrix4D
	//
	//# \ctor	Transform4D();
	//# \ctor	Transform4D(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13,
	//# \ctor2	float n20, float n21, float n22, float n23);
	//# \ctor	Transform4D(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Point3D& p);
	//# \ctor	Transform4D(const Matrix3D& m);
	//# \ctor	Transform4D(const Matrix3D& m, Vector3D& v);
	//
	//# \param	nij		The value of the entry residing in row <i>i</i> and column <i>j</i>.
	//# \param	a		The values of the entries residing in first column.
	//# \param	b		The values of the entries residing in second column.
	//# \param	c		The values of the entries residing in third column.
	//# \param	p		The values of the entries residing in fourth column.
	//# \param	m		A 3&#x202F;&times;&#x202F;3 matrix that is copied to the upper-left 3&#x202F;&times;&#x202F;3 portion of the matrix.
	//# \param	v		A 3D vector that is copied to the fourth column of the matrix.
	//
	//# \desc
	//# The $Transform4D$ class is used to store a 4&#x202F;&times;&#x202F;4 matrix whose fourth row is always (0,&#x202F;0,&#x202F;0,&#x202F;1).
	//#
	//# The default constructor leaves the entries of the matrix undefined, including the fourth row. All other constructors set
	//# the fourth row to (0,&#x202F;0,&#x202F;0,&#x202F;1).
	//
	//# \operator	Vector3D& operator [](machine j);
	//#				Returns a reference to the <i>j</i>-th column of a matrix. $j$ must be 0, 1, or 2.
	//#				Use the $@Transform4D::GetTranslation@$ and $@Transform4D::SetTranslation@$ functions to access the fourth column.
	//
	//# \operator	const Vector3D& operator [](machine j) const;
	//#				Returns a constant reference to the <i>j</i>-th column of a matrix. $j$ must be 0, 1, or 2.
	//#				Use the $@Transform4D::GetTranslation@$ and $@Transform4D::SetTranslation@$ functions to access the fourth column.
	//
	//# \operator	Transform4D& operator *=(const Transform4D& m);
	//#				Multiplies by the matrix $m$.
	//
	//# \operator	Transform4D& operator *=(const Matrix3D& m);
	//#				Multiplies by the matrix $m$. The entries of the fourth row and fourth column of $m$ are assumed
	//#				to be those of the identity matrix.
	//
	//# \action		Transform4D operator *(const Transform4D& m1, const Transform4D& m2);
	//#				Returns the product of the matrices $m1$ and $m2$.
	//
	//# \action		Transform4D operator *(const Transform4D& m1, const Matrix4D& m2);
	//#				Returns the product of the matrices $m1$ and $m2$.
	//
	//# \action		Transform4D operator *(const Transform4D& m1, const Matrix3D& m2);
	//#				Returns the product of the matrices $m1$ and $m2$. The entries of the fourth row and fourth column of $m2$
	//#				are assumed to be those of the identity matrix.
	//
	//# \action		Vector4D operator *(const Transform4D& m, const Vector4D& v);
	//#				Returns the product of the matrix $m$ and the column vector $v$.
	//
	//# \action		Vector4D operator *(const Trivector4D& v, const Transform4D& m);
	//#				Returns the product of the trivector $v$ and the matrix $m$.
	//
	//# \action		Vector3D operator *(const Transform4D& m, const Vector3D& v);
	//#				Returns the product of the matrix $m$ and the column vector $v$. The <i>w</i> coordinate of $v$ is assumed to be 0.
	//
	//# \action		Bivector3D operator *(const Bivector3D& v, const Transform4D& m);
	//#				Returns the product of the bivector $v$ and the upper-left 3&#x202F;&times;&#x202F;3 portion of the matrix $m$.
	//
	//# \action		Point3D operator *(const Transform4D& m, const Point3D& p);
	//#				Returns the product of the matrix $m$ and the column vector $p$. The <i>w</i> coordinate of $p$ is assumed to be 1.
	//
	//# \action		Vector2D operator *(const Transform4D& m, const Vector2D& v);
	//#				Returns the product of the matrix $m$ and the column vector $v$. The <i>z</i> and <i>w</i> coordinates of $v$ are assumed to be 0.
	//
	//# \action		Point2D operator *(const Transform4D& m, const Point2D& p);
	//#				Returns the product of the matrix $m$ and the column vector $p$. The <i>z</i> coordinate of $p$ is assumed to be 0,
	//#				and the <i>w</i> coordinate of $p$ is assumed to be 1.
	//
	//# \action		float Determinant(const Transform4D& m);
	//#				Returns the determinant of the matrix $m$.
	//
	//# \action		Transform4D Inverse(const Transform4D& m);
	//#				Returns the inverse of the matrix $m$. If $m$ is singular, then the result is undefined.
	//
	//# \action		Transform4D Adjugate(const Transform4D& m);
	//#				Returns the adjugate of the matrix $m$.
	//
	//# \action		Vector3D InverseTransform(const Transform4D& m, const Vector3D& v);
	//#				Returns the product of the inverse of the matrix $m$ and the vector $v$. If $m$ is singular, then the result is undefined.
	//
	//# \action		Point3D InverseTransform(const Transform4D& m, const Point3D& p);
	//#				Returns the product of the inverse of the matrix $m$ and the point $p$. If $m$ is singular, then the result is undefined.
	//
	//# \action		Vector3D AdjugateTransform(const Transform4D& m, const Vector3D& v);
	//#				Returns the product of the adjugate of the matrix $m$ and the vector $v$.
	//
	//# \action		Point3D AdjugateTransform(const Transform4D& m, const Point3D& p);
	//#				Returns the product of the adjugate of the matrix $m$ and the point $p$.
	//
	//# \base	Matrix4D	A $Transform4D$ object behaves much like a $@Matrix4D@$ object,
	//#						except that the fourth row is always (0,&#x202F;0,&#x202F;0,&#x202F;1).
	//
	//# \also	$@Matrix4D@$
	//# \also	$@Matrix3D@$
	//# \also	$@Vector3D@$
	//# \also	$@Point3D@$


	//# \function	Transform4D::SetMatrix3D		Sets the entries of the upper-left 3&#x202F;&times;&#x202F;3 portion of a matrix.
	//
	//# \proto	Transform4D& SetMatrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c);
	//
	//# \param	a		The new values of the entries residing in first column.
	//# \param	b		The new values of the entries residing in second column.
	//# \param	c		The new values of the entries residing in third column.
	//
	//# \desc
	//# The $SetMatrix3D$ function sets the entries of the upper-left 3&#x202F;&times;&#x202F;3 portion of a matrix.
	//# The fourth row and fourth column of the matrix are not modified.
	//
	//# \also	$@Transform4D::GetMatrix3D@$
	//# \also	$@Transform4D::GetTranslation@$
	//# \also	$@Transform4D::SetTranslation@$


	//# \function	Transform4D::GetTranslation		Returns the fourth column of a matrix.
	//
	//# \proto	const Point3D& GetTranslation(void) const;
	//
	//# \desc
	//# The $GetTranslation$ function returns a reference to the fourth column of a matrix as a $@Point3D@$ object.
	//
	//# \also	$@Transform4D::SetTranslation@$
	//# \also	$@Transform4D::GetMatrix3D@$
	//# \also	$@Transform4D::SetMatrix3D@$


	//# \function	Transform4D::SetTranslation		Sets the fourth column of a matrix.
	//
	//# \proto	Transform4D& SetTranslation(float x, float y, float z);
	//# \proto	Transform4D& SetTranslation(const Point3D& p);
	//
	//# \param	x	The <i>x</i> coordinate of the translation.
	//# \param	y	The <i>y</i> coordinate of the translation.
	//# \param	z	The <i>z</i> coordinate of the translation.
	//# \param	p	The 3D point whose entries are copied into the fourth column.
	//
	//# \desc
	//# The $SetTranslation$ function sets the fourth column of a matrix to the point having coordinates $x$, $y$, and $z$
	//# or to the position given by the $p$ parameter. The first three columns and the fourth row of the matrix are not modified.
	//#
	//# The return value is a reference to the matrix object.
	//
	//# \also	$@Transform4D::GetTranslation@$
	//# \also	$@Transform4D::GetMatrix3D@$
	//# \also	$@Transform4D::SetMatrix3D@$


	//# \function	Transform4D::MakeRotationX		Returns a matrix that represents a rotation about the <i>x</i> axis.
	//
	//# \proto	static Transform4D MakeRotationX(float angle);
	//
	//# \param	angle	The angle through which to rotate, in radians.
	//
	//# \desc
	//# The $MakeRotationX$ function returns a matrix representing a rotation through the angle given
	//# by the $angle$ parameter about the <i>x</i> axis.
	//
	//# \also	$@Transform4D::MakeRotationY@$
	//# \also	$@Transform4D::MakeRotationZ@$
	//# \also	$@Transform4D::MakeRotation@$


	//# \function	Transform4D::MakeRotationY		Returns a matrix that represents a rotation about the <i>y</i> axis.
	//
	//# \proto	static Transform4D MakeRotationY(float angle);
	//
	//# \param	angle	The angle through which to rotate, in radians.
	//
	//# \desc
	//# The $MakeRotationY$ function returns a matrix representing a rotation through the angle given
	//# by the $angle$ parameter about the <i>y</i> axis.
	//
	//# \also	$@Transform4D::MakeRotationX@$
	//# \also	$@Transform4D::MakeRotationZ@$
	//# \also	$@Transform4D::MakeRotation@$


	//# \function	Transform4D::MakeRotationZ		Returns a matrix that represents a rotation about the <i>z</i> axis.
	//
	//# \proto	static Transform4D MakeRotationZ(float angle);
	//
	//# \param	angle	The angle through which to rotate, in radians.
	//
	//# \desc
	//# The $MakeRotationZ$ function returns a matrix representing a rotation through the angle given
	//# by the $angle$ parameter about the <i>z</i> axis.
	//
	//# \also	$@Transform4D::MakeRotationX@$
	//# \also	$@Transform4D::MakeRotationY@$
	//# \also	$@Transform4D::MakeRotation@$


	//# \function	Transform4D::MakeRotation		Returns a matrix that represents a rotation about a given axis.
	//
	//# \proto	static Transform4D MakeRotation(float angle, const Bivector3D& axis);
	//
	//# \param	angle	The angle through which to rotate, in radians.
	//# \param	axis	The axis about which to rotate. This bivector must have unit magnitude.
	//
	//# \desc
	//# The $MakeRotation$ function returns a matrix representing a rotation through the angle
	//# given by the $angle$ parameter about the axis given by the $axis$ parameter.
	//
	//# \also	$@Transform4D::MakeRotationX@$
	//# \also	$@Transform4D::MakeRotationY@$
	//# \also	$@Transform4D::MakeRotationZ@$


	//# \function	Transform4D::MakeScale		Returns a matrix that represents a scale.
	//
	//# \proto	static Transform4D MakeScale(float t);
	//# \proto	static Transform4D MakeScale(float r, float s, float t);
	//
	//# \param	s	The scale along the <i>x</i> axis.
	//# \param	r	The scale along the <i>y</i> axis.
	//# \param	t	The scale along the <i>z</i> axis, or if specified by itself, the scale along all three axes.
	//
	//# \desc
	//# The $MakeScale$ function returns a matrix representing a scale.
	//# If only the $t$ parameter is specified, then the scale is uniform along all three axes.
	//# If the $r$, $s$, and $t$ parameters are specified, then they correspond to the scale along
	//# the <i>x</i>-, <i>y</i>, and <i>z</i> axis, respectively.
	//
	//# \also	$@Matrix4D::SetIdentity@$


	class Transform4D : public Matrix4D
	{
		public:

			inline Transform4D() = default;

			TERATHON_API Transform4D(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23);
			TERATHON_API Transform4D(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Point3D& p);
			TERATHON_API Transform4D(const Bivector3D& r0, float n03, const Bivector3D& r1, float n13, const Bivector3D& r2, float n23);
			TERATHON_API Transform4D(const Matrix3D& m);
			TERATHON_API Transform4D(const Matrix3D& m, const Vector3D& v);

			TERATHON_API Transform4D& Set(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23);
			TERATHON_API Transform4D& Set(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Point3D& p);
			TERATHON_API Transform4D& Set(const Matrix3D& m, const Vector3D& v);

			Vector3D& operator [](machine j)
			{
				return (Matrix4D::operator [](j).xyz);
			}

			const Vector3D& operator [](machine j) const
			{
				return (Matrix4D::operator [](j).xyz);
			}

			const Point3D& GetTranslation(void) const
			{
				return (Zero3D + Matrix4D::operator [](3).xyz);
			}

			Transform4D& SetTranslation(float x, float y, float z)
			{
				m03 = x;
				m13 = y;
				m23 = z;
				return (*this);
			}

			Transform4D& SetTranslation(const Point3D& p)
			{
				m03 = p.x;
				m13 = p.y;
				m23 = p.z;
				return (*this);
			}

			TERATHON_API Transform4D& operator *=(const Transform4D& m);
			TERATHON_API Transform4D& operator *=(const Matrix3D& m);

			TERATHON_API Transform4D& SetMatrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c);
			TERATHON_API Transform4D& Orthogonalize(int32 column);

			TERATHON_API void GetEulerAngles(float *x, float *y, float *z) const;
			TERATHON_API Transform4D& SetEulerAngles(float x, float y, float z);

			TERATHON_API static Transform4D MakeRotationX(float angle);
			TERATHON_API static Transform4D MakeRotationY(float angle);
			TERATHON_API static Transform4D MakeRotationZ(float angle);
			TERATHON_API static Transform4D MakeRotation(float angle, const Bivector3D& axis);

			TERATHON_API static Transform4D MakeReflection(const Vector3D& a);
			TERATHON_API static Transform4D MakeInvolution(const Vector3D& a);
			TERATHON_API static Transform4D MakeReflection(const Trivector4D& plane);

			TERATHON_API static Transform4D MakeScaleX(float sx);
			TERATHON_API static Transform4D MakeScaleY(float sy);
			TERATHON_API static Transform4D MakeScaleZ(float sz);
			TERATHON_API static Transform4D MakeScale(float scale);
			TERATHON_API static Transform4D MakeScale(float sx, float sy, float sz);
			TERATHON_API static Transform4D MakeScale(float scale, const Vector3D& axis);

			TERATHON_API static Transform4D MakeSkew(float angle, const Vector3D& a, const Vector3D& b);

			TERATHON_API static Transform4D MakeTranslation(const Vector3D& dv);
	};


	template <typename type_struct, int count, int index_x, int index_y, int index_z>
	inline Vector3D operator *(const Transform4D& m, const Subvec3D<type_struct, false, count, index_x, index_y, index_z>& v)
	{
		return (m.matrix3D * v);
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z>
	inline Bivector3D operator *(const Subvec3D<type_struct, true, count, index_x, index_y, index_z>& v, const Transform4D& m)
	{
		return (v * m.matrix3D);
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
	Vector4D operator *(const Transform4D& m, const Subvec4D<type_struct, false, count, index_x, index_y, index_z, index_w>& v)
	{
		return (Vector4D(m(0,0) * v.data[index_x] + m(0,1) * v.data[index_y] + m(0,2) * v.data[index_z] + m(0,3) * v.data[index_w],
						 m(1,0) * v.data[index_x] + m(1,1) * v.data[index_y] + m(1,2) * v.data[index_z] + m(1,3) * v.data[index_w],
						 m(2,0) * v.data[index_x] + m(2,1) * v.data[index_y] + m(2,2) * v.data[index_z] + m(2,3) * v.data[index_w],
						 v.data[index_w]));
	}

	template <typename type_struct, int count, int index_x, int index_y, int index_z, int index_w>
	Trivector4D operator *(const Subvec4D<type_struct, true, count, index_x, index_y, index_z, index_w>& v, const Transform4D& m)
	{
		return (Trivector4D(m(0,0) * v.data[index_x] + m(1,0) * v.data[index_y] + m(2,0) * v.data[index_z],
							m(0,1) * v.data[index_x] + m(1,1) * v.data[index_y] + m(2,1) * v.data[index_z],
							m(0,2) * v.data[index_x] + m(1,2) * v.data[index_y] + m(2,2) * v.data[index_z],
							m(0,3) * v.data[index_x] + m(1,3) * v.data[index_y] + m(2,3) * v.data[index_z] + v.data[index_w]));
	}

	inline Vector4D operator *(const Transform4D& m, const Vector4D& v)
	{
		return (m * v.xyzw);
	}

	inline Trivector4D operator *(const Trivector4D& v, const Transform4D& m)
	{
		return (v.xyzw * m);
	}

	template <typename type_struct, int count, int index_00, int index_01, int index_02, int index_10, int index_11, int index_12, int index_20, int index_21, int index_22>
	inline Transform4D operator *(const Transform4D& m1, const Submat3D<type_struct, count, index_00, index_01, index_02, index_10, index_11, index_12, index_20, index_21, index_22>& m2)
	{
		Transform4D		transform;

		transform.matrix3D = m1.matrix3D * m2;
		transform[3] = m1[3];

		transform.m30 = transform.m31 = transform.m32 = 0.0F;
		transform.m33 = 1.0F;
		return (transform);
	}

	template <typename type_struct, int count, int index_00, int index_01, int index_02, int index_10, int index_11, int index_12, int index_20, int index_21, int index_22>
	inline Transform4D operator *(const Submat3D<type_struct, count, index_00, index_01, index_02, index_10, index_11, index_12, index_20, index_21, index_22>& m1, const Transform4D& m2)
	{
		Transform4D		transform;

		transform.matrix3D = m1 * m2.matrix3D;
		transform[3] = m1 * m2[3];

		transform.m30 = transform.m31 = transform.m32 = 0.0F;
		transform.m33 = 1.0F;
		return (transform);
	}

	inline Transform4D operator *(const Transform4D& m1, const Matrix3D& m2)
	{
		return (m1 * m2.matrix);
	}

	inline Transform4D operator *(const Matrix3D& m1, const Transform4D& m2)
	{
		return (m1.matrix * m2);
	}


	TERATHON_API Transform4D operator *(const Transform4D& m1, const Transform4D& m2);
	TERATHON_API Matrix4D operator *(const Transform4D& m1, const Matrix4D& m2);
	TERATHON_API Vector3D operator *(const Transform4D& m, const Vector3D& v);
	TERATHON_API Bivector3D operator *(const Bivector3D& v, const Transform4D& m);
	TERATHON_API Point3D operator *(const Transform4D& m, const Point3D& p);
	TERATHON_API Vector2D operator *(const Transform4D& m, const Vector2D& v);
	TERATHON_API Point2D operator *(const Transform4D& m, const Point2D& p);

	TERATHON_API Transform4D Scale(const Transform4D& m, const Vector3D& v);
	TERATHON_API Matrix3D Transform(const Transform4D& m1, const Matrix3D& m2);

	#ifndef TERATHON_NO_SIMD

		TERATHON_API vec_float TransformVector3D(const Transform4D& m, vec_float v);
		TERATHON_API vec_float TransformPoint3D(const Transform4D& m, vec_float p);

	#endif

	TERATHON_API float Determinant(const Transform4D& m);
	TERATHON_API Transform4D Inverse(const Transform4D& m);
	TERATHON_API Transform4D Adjugate(const Transform4D& m);
	TERATHON_API Matrix3D Adjugate3D(const Transform4D& m);
	TERATHON_API Vector3D InverseTransform(const Transform4D& m, const Vector3D& v);
	TERATHON_API Point3D InverseTransform(const Transform4D& m, const Point3D& p);
	TERATHON_API Vector3D AdjugateTransform(const Transform4D& m, const Vector3D& v);
	TERATHON_API Point3D AdjugateTransform(const Transform4D& m, const Point3D& p);


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


	struct ConstTransform4D
	{
		alignas(16) float	n[4][4];

		operator const Transform4D&(void) const
		{
			return (reinterpret_cast<const Transform4D&>(*this));
		}

		const Transform4D *operator &(void) const
		{
			return (reinterpret_cast<const Transform4D *>(this));
		}

		const Transform4D *operator ->(void) const
		{
			return (reinterpret_cast<const Transform4D *>(this));
		}

		float operator ()(int32 i, int32 j) const
		{
			return (reinterpret_cast<const Transform4D&>(*this)(i, j));
		}

		const Vector3D& operator [](machine j) const
		{
			return (reinterpret_cast<const Transform4D&>(*this)[j]);
		}
	};


	TERATHON_API extern const ConstTransform4D Identity4D;
}


#endif
