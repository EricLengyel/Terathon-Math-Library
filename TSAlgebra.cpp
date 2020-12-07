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


#include "TSMatrix4D.h"


using namespace Terathon;


template <typename A_type_struct, int A_count, int A_index_00, int A_index_01, int A_index_10, int A_index_11,
		  typename B_type_struct, int B_count, int B_index_00, int B_index_01, int B_index_10, int B_index_11>
typename A_type_struct::matrix2D_type Terathon::operator *(const Submat2D<A_type_struct, A_count, A_index_00, A_index_01, A_index_10, A_index_11>& A,
														   const Submat2D<B_type_struct, B_count, B_index_00, B_index_01, B_index_10, B_index_11>& B)
{
	return (typename A_type_struct::matrix2D_type(A.data[A_index_00] * B.data[B_index_00] + A.data[A_index_01] * B.data[B_index_10],
												  A.data[A_index_00] * B.data[B_index_01] + A.data[A_index_01] * B.data[B_index_11],
												  A.data[A_index_10] * B.data[B_index_00] + A.data[A_index_11] * B.data[B_index_10],
												  A.data[A_index_10] * B.data[B_index_01] + A.data[A_index_11] * B.data[B_index_11]));
}

template TERATHON_API Matrix2D Terathon::operator *(const Submat2D<TypeMatrix2D, 4, 0, 2, 1, 3>&, const Submat2D<TypeMatrix2D, 4, 0, 2, 1, 3>&);
template TERATHON_API Matrix2D Terathon::operator *(const Submat2D<TypeMatrix2D, 4, 0, 2, 1, 3>&, const Submat2D<TypeMatrix2D, 4, 0, 1, 2, 3>&);
template TERATHON_API Matrix2D Terathon::operator *(const Submat2D<TypeMatrix2D, 4, 0, 1, 2, 3>&, const Submat2D<TypeMatrix2D, 4, 0, 2, 1, 3>&);
template TERATHON_API Matrix2D Terathon::operator *(const Submat2D<TypeMatrix2D, 4, 0, 1, 2, 3>&, const Submat2D<TypeMatrix2D, 4, 0, 1, 2, 3>&);


template <typename A_type_struct, int A_count, int A_index_00, int A_index_01, int A_index_02, int A_index_10, int A_index_11, int A_index_12, int A_index_20, int A_index_21, int A_index_22,
		  typename B_type_struct, int B_count, int B_index_00, int B_index_01, int B_index_02, int B_index_10, int B_index_11, int B_index_12, int B_index_20, int B_index_21, int B_index_22>
typename A_type_struct::matrix3D_type Terathon::operator *(const Submat3D<A_type_struct, A_count, A_index_00, A_index_01, A_index_02, A_index_10, A_index_11, A_index_12, A_index_20, A_index_21, A_index_22>& A,
														   const Submat3D<B_type_struct, B_count, B_index_00, B_index_01, B_index_02, B_index_10, B_index_11, B_index_12, B_index_20, B_index_21, B_index_22>& B)
{
	return (typename A_type_struct::matrix3D_type(A.data[A_index_00] * B.data[B_index_00] + A.data[A_index_01] * B.data[B_index_10] + A.data[A_index_02] * B.data[B_index_20],
												  A.data[A_index_00] * B.data[B_index_01] + A.data[A_index_01] * B.data[B_index_11] + A.data[A_index_02] * B.data[B_index_21],
												  A.data[A_index_00] * B.data[B_index_02] + A.data[A_index_01] * B.data[B_index_12] + A.data[A_index_02] * B.data[B_index_22],
												  A.data[A_index_10] * B.data[B_index_00] + A.data[A_index_11] * B.data[B_index_10] + A.data[A_index_12] * B.data[B_index_20],
												  A.data[A_index_10] * B.data[B_index_01] + A.data[A_index_11] * B.data[B_index_11] + A.data[A_index_12] * B.data[B_index_21],
												  A.data[A_index_10] * B.data[B_index_02] + A.data[A_index_11] * B.data[B_index_12] + A.data[A_index_12] * B.data[B_index_22],
												  A.data[A_index_20] * B.data[B_index_00] + A.data[A_index_21] * B.data[B_index_10] + A.data[A_index_22] * B.data[B_index_20],
												  A.data[A_index_20] * B.data[B_index_01] + A.data[A_index_21] * B.data[B_index_11] + A.data[A_index_22] * B.data[B_index_21],
												  A.data[A_index_20] * B.data[B_index_02] + A.data[A_index_21] * B.data[B_index_12] + A.data[A_index_22] * B.data[B_index_22]));
}

template TERATHON_API Matrix3D Terathon::operator *(const Submat3D<TypeMatrix3D, 9, 0, 3, 6, 1, 4, 7, 2, 5, 8>&, const Submat3D<TypeMatrix3D, 9, 0, 3, 6, 1, 4, 7, 2, 5, 8>&);
template TERATHON_API Matrix3D Terathon::operator *(const Submat3D<TypeMatrix3D, 9, 0, 3, 6, 1, 4, 7, 2, 5, 8>&, const Submat3D<TypeMatrix3D, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8>&);
template TERATHON_API Matrix3D Terathon::operator *(const Submat3D<TypeMatrix3D, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8>&, const Submat3D<TypeMatrix3D, 9, 0, 3, 6, 1, 4, 7, 2, 5, 8>&);
template TERATHON_API Matrix3D Terathon::operator *(const Submat3D<TypeMatrix3D, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8>&, const Submat3D<TypeMatrix3D, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8>&);

template TERATHON_API Matrix3D Terathon::operator *(const Submat3D<TypeMatrix3D, 9, 0, 3, 6, 1, 4, 7, 2, 5, 8>&, const Submat3D<TypeMatrix4D, 16, 0, 4, 8, 1, 5, 9, 2, 6, 10>&);
template TERATHON_API Matrix3D Terathon::operator *(const Submat3D<TypeMatrix3D, 9, 0, 3, 6, 1, 4, 7, 2, 5, 8>&, const Submat3D<TypeMatrix4D, 16, 0, 1, 2, 4, 5, 6, 8, 9, 10>&);
template TERATHON_API Matrix3D Terathon::operator *(const Submat3D<TypeMatrix3D, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8>&, const Submat3D<TypeMatrix4D, 16, 0, 4, 8, 1, 5, 9, 2, 6, 10>&);
template TERATHON_API Matrix3D Terathon::operator *(const Submat3D<TypeMatrix3D, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8>&, const Submat3D<TypeMatrix4D, 16, 0, 1, 2, 4, 5, 6, 8, 9, 10>&);

template TERATHON_API Matrix3D Terathon::operator *(const Submat3D<TypeMatrix4D, 16, 0, 4, 8, 1, 5, 9, 2, 6, 10>&, const Submat3D<TypeMatrix3D, 9, 0, 3, 6, 1, 4, 7, 2, 5, 8>&);
template TERATHON_API Matrix3D Terathon::operator *(const Submat3D<TypeMatrix4D, 16, 0, 1, 2, 4, 5, 6, 8, 9, 10>&, const Submat3D<TypeMatrix3D, 9, 0, 3, 6, 1, 4, 7, 2, 5, 8>&);
template TERATHON_API Matrix3D Terathon::operator *(const Submat3D<TypeMatrix4D, 16, 0, 4, 8, 1, 5, 9, 2, 6, 10>&, const Submat3D<TypeMatrix3D, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8>&);
template TERATHON_API Matrix3D Terathon::operator *(const Submat3D<TypeMatrix4D, 16, 0, 1, 2, 4, 5, 6, 8, 9, 10>&, const Submat3D<TypeMatrix3D, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8>&);

template TERATHON_API Matrix3D Terathon::operator *(const Submat3D<TypeMatrix4D, 16, 0, 4, 8, 1, 5, 9, 2, 6, 10>&, const Submat3D<TypeMatrix4D, 16, 0, 4, 8, 1, 5, 9, 2, 6, 10>&);
template TERATHON_API Matrix3D Terathon::operator *(const Submat3D<TypeMatrix4D, 16, 0, 1, 2, 4, 5, 6, 8, 9, 10>&, const Submat3D<TypeMatrix4D, 16, 0, 4, 8, 1, 5, 9, 2, 6, 10>&);
template TERATHON_API Matrix3D Terathon::operator *(const Submat3D<TypeMatrix4D, 16, 0, 4, 8, 1, 5, 9, 2, 6, 10>&, const Submat3D<TypeMatrix4D, 16, 0, 1, 2, 4, 5, 6, 8, 9, 10>&);
template TERATHON_API Matrix3D Terathon::operator *(const Submat3D<TypeMatrix4D, 16, 0, 1, 2, 4, 5, 6, 8, 9, 10>&, const Submat3D<TypeMatrix4D, 16, 0, 1, 2, 4, 5, 6, 8, 9, 10>&);


template <typename A_type_struct, int A_count, int A_index_00, int A_index_01, int A_index_02, int A_index_03, int A_index_10, int A_index_11, int A_index_12, int A_index_13, int A_index_20, int A_index_21, int A_index_22, int A_index_23, int A_index_30, int A_index_31, int A_index_32, int A_index_33,
		  typename B_type_struct, int B_count, int B_index_00, int B_index_01, int B_index_02, int B_index_03, int B_index_10, int B_index_11, int B_index_12, int B_index_13, int B_index_20, int B_index_21, int B_index_22, int B_index_23, int B_index_30, int B_index_31, int B_index_32, int B_index_33>
typename A_type_struct::matrix4D_type Terathon::operator *(const Submat4D<A_type_struct, A_count, A_index_00, A_index_01, A_index_02, A_index_03, A_index_10, A_index_11, A_index_12, A_index_13, A_index_20, A_index_21, A_index_22, A_index_23, A_index_30, A_index_31, A_index_32, A_index_33>& A,
														   const Submat4D<B_type_struct, B_count, B_index_00, B_index_01, B_index_02, B_index_03, B_index_10, B_index_11, B_index_12, B_index_13, B_index_20, B_index_21, B_index_22, B_index_23, B_index_30, B_index_31, B_index_32, B_index_33>& B)
{
	return (typename A_type_struct::matrix4D_type(A.data[A_index_00] * B.data[B_index_00] + A.data[A_index_01] * B.data[B_index_10] + A.data[A_index_02] * B.data[B_index_20] + A.data[A_index_03] * B.data[B_index_30],
												  A.data[A_index_00] * B.data[B_index_01] + A.data[A_index_01] * B.data[B_index_11] + A.data[A_index_02] * B.data[B_index_21] + A.data[A_index_03] * B.data[B_index_31],
												  A.data[A_index_00] * B.data[B_index_02] + A.data[A_index_01] * B.data[B_index_12] + A.data[A_index_02] * B.data[B_index_22] + A.data[A_index_03] * B.data[B_index_32],
												  A.data[A_index_00] * B.data[B_index_03] + A.data[A_index_01] * B.data[B_index_13] + A.data[A_index_02] * B.data[B_index_23] + A.data[A_index_03] * B.data[B_index_33],
												  A.data[A_index_10] * B.data[B_index_00] + A.data[A_index_11] * B.data[B_index_10] + A.data[A_index_12] * B.data[B_index_20] + A.data[A_index_13] * B.data[B_index_30],
												  A.data[A_index_10] * B.data[B_index_01] + A.data[A_index_11] * B.data[B_index_11] + A.data[A_index_12] * B.data[B_index_21] + A.data[A_index_13] * B.data[B_index_31],
												  A.data[A_index_10] * B.data[B_index_02] + A.data[A_index_11] * B.data[B_index_12] + A.data[A_index_12] * B.data[B_index_22] + A.data[A_index_13] * B.data[B_index_32],
												  A.data[A_index_10] * B.data[B_index_03] + A.data[A_index_11] * B.data[B_index_13] + A.data[A_index_12] * B.data[B_index_23] + A.data[A_index_13] * B.data[B_index_33],
												  A.data[A_index_20] * B.data[B_index_00] + A.data[A_index_21] * B.data[B_index_10] + A.data[A_index_22] * B.data[B_index_20] + A.data[A_index_23] * B.data[B_index_30],
												  A.data[A_index_20] * B.data[B_index_01] + A.data[A_index_21] * B.data[B_index_11] + A.data[A_index_22] * B.data[B_index_21] + A.data[A_index_23] * B.data[B_index_31],
												  A.data[A_index_20] * B.data[B_index_02] + A.data[A_index_21] * B.data[B_index_12] + A.data[A_index_22] * B.data[B_index_22] + A.data[A_index_23] * B.data[B_index_32],
												  A.data[A_index_20] * B.data[B_index_03] + A.data[A_index_21] * B.data[B_index_13] + A.data[A_index_22] * B.data[B_index_23] + A.data[A_index_23] * B.data[B_index_33],
												  A.data[A_index_30] * B.data[B_index_00] + A.data[A_index_31] * B.data[B_index_10] + A.data[A_index_32] * B.data[B_index_20] + A.data[A_index_33] * B.data[B_index_30],
												  A.data[A_index_30] * B.data[B_index_01] + A.data[A_index_31] * B.data[B_index_11] + A.data[A_index_32] * B.data[B_index_21] + A.data[A_index_33] * B.data[B_index_31],
												  A.data[A_index_30] * B.data[B_index_02] + A.data[A_index_31] * B.data[B_index_12] + A.data[A_index_32] * B.data[B_index_22] + A.data[A_index_33] * B.data[B_index_32],
												  A.data[A_index_30] * B.data[B_index_03] + A.data[A_index_31] * B.data[B_index_13] + A.data[A_index_32] * B.data[B_index_23] + A.data[A_index_33] * B.data[B_index_33]));
}

template TERATHON_API Matrix4D Terathon::operator *(const Submat4D<TypeMatrix4D, 16, 0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15>&, const Submat4D<TypeMatrix4D, 16, 0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15>&);
template TERATHON_API Matrix4D Terathon::operator *(const Submat4D<TypeMatrix4D, 16, 0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15>&, const Submat4D<TypeMatrix4D, 16, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>&);
template TERATHON_API Matrix4D Terathon::operator *(const Submat4D<TypeMatrix4D, 16, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>&, const Submat4D<TypeMatrix4D, 16, 0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15>&);
template TERATHON_API Matrix4D Terathon::operator *(const Submat4D<TypeMatrix4D, 16, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>&, const Submat4D<TypeMatrix4D, 16, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>&);
