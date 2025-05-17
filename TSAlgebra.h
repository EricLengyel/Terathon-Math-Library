//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2025, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#ifndef TSAlgebra_h
#define TSAlgebra_h


/// \component	Math Library
/// \prefix		Math/


#include "TSMath.h"


namespace Terathon
{
	template <typename type_struct, int count, int index>
	class Component
	{
		public:

			typedef typename type_struct::component_type component_type;

			component_type		data[count];

			operator component_type&(void)
			{
				return (data[index]);
			}

			operator const component_type&(void) const
			{
				return (data[index]);
			}

			operator volatile component_type&(void) volatile
			{
				return (data[index]);
			}

			operator const volatile component_type&(void) const volatile
			{
				return (data[index]);
			}

			component_type *operator &(void)
			{
				return (&data[index]);
			}

			const component_type *operator &(void) const
			{
				return (&data[index]);
			}

			volatile component_type *operator &(void) volatile
			{
				return (&data[index]);
			}

			const volatile component_type *operator &(void) const volatile
			{
				return (&data[index]);
			}

			Component& operator =(const component_type& value)
			{
				data[index] = value;
				return (*this);
			}

			void operator =(const component_type& value) volatile
			{
				data[index] = value;
			}

			Component& operator =(const Component& value)
			{
				data[index] = value.data[index];
				return (*this);
			}

			void operator =(const Component& value) volatile
			{
				data[index] = value.data[index];
			}

			template <int cnt, int ind>
			Component& operator =(const Component<type_struct, cnt, ind>& value)
			{
				data[index] = value.data[ind];
				return (*this);
			}
	};


	template <int count, typename A_type_struct, int A_index_x, typename B_type_struct, int B_index_x>
	inline bool operator ==(const Component<A_type_struct, count, A_index_x>& A, const Component<B_type_struct, count, B_index_x>& B)
	{
		return (A.data[A_index_x] == B.data[B_index_x]);
	}

	template <int count, typename A_type_struct, int A_index_x, typename B_type_struct, int B_index_x>
	inline bool operator !=(const Component<A_type_struct, count, A_index_x>& A, const Component<B_type_struct, count, B_index_x>& B)
	{
		return (A.data[A_index_x] != B.data[B_index_x]);
	}


	template <typename type_struct, int index_x, int index_y>
	struct ConverterVector2D
	{
		typedef typename type_struct::component_type component_type;
		typedef typename type_struct::vector2D_type vector2D_type;
		typedef typename type_struct::vector2D_type const_vector2D_type;

		static vector2D_type Convert(component_type *data)
		{
			return (vector2D_type(data[index_x], data[index_y]));
		}

		static const_vector2D_type Convert(const component_type *data)
		{
			return (const_vector2D_type(data[index_x], data[index_y]));
		}
	};

	template <typename type_struct>
	struct ConverterVector2D<type_struct, 0, 1>
	{
		typedef typename type_struct::component_type component_type;
		typedef typename type_struct::vector2D_type& vector2D_type;
		typedef const typename type_struct::vector2D_type& const_vector2D_type;

		static vector2D_type Convert(component_type *data)
		{
			return (reinterpret_cast<vector2D_type>(data[0]));
		}

		static const_vector2D_type Convert(const component_type *data)
		{
			return (reinterpret_cast<const_vector2D_type>(data[0]));
		}
	};

	template <typename type_struct>
	struct ConverterVector2D<type_struct, 1, 2>
	{
		typedef typename type_struct::component_type component_type;
		typedef typename type_struct::vector2D_type& vector2D_type;
		typedef const typename type_struct::vector2D_type& const_vector2D_type;

		static vector2D_type Convert(component_type *data)
		{
			return (reinterpret_cast<vector2D_type>(data[1]));
		}

		static const_vector2D_type Convert(const component_type *data)
		{
			return (reinterpret_cast<const_vector2D_type>(data[1]));
		}
	};

	template <typename type_struct>
	struct ConverterVector2D<type_struct, 2, 3>
	{
		typedef typename type_struct::component_type component_type;
		typedef typename type_struct::vector2D_type& vector2D_type;
		typedef const typename type_struct::vector2D_type& const_vector2D_type;

		static vector2D_type Convert(component_type *data)
		{
			return (reinterpret_cast<vector2D_type>(data[2]));
		}

		static const_vector2D_type Convert(const component_type *data)
		{
			return (reinterpret_cast<const_vector2D_type>(data[2]));
		}
	};


	template <typename type_struct, int count, int index_x, int index_y>
	class Subvec2D
	{
		public:

			typedef typename type_struct::component_type component_type;
			typedef typename type_struct::vector2D_type vector2D_type;

			component_type		data[count];

			Subvec2D& Set(const component_type& x, const component_type& y)
			{
				data[index_x] = x;
				data[index_y] = y;
				return (*this);
			}

			void Set(const component_type& x, const component_type& y) volatile
			{
				data[index_x] = x;
				data[index_y] = y;
			}

			operator typename ConverterVector2D<type_struct, index_x, index_y>::vector2D_type(void)
			{
				return (ConverterVector2D<type_struct, index_x, index_y>::Convert(data));
			}

			operator typename ConverterVector2D<type_struct, index_x, index_y>::const_vector2D_type(void) const
			{
				return (ConverterVector2D<type_struct, index_x, index_y>::Convert(data));
			}

			Subvec2D& operator =(const vector2D_type& value)
			{
				data[index_x] = value.x;
				data[index_y] = value.y;
				return (*this);
			}

			void operator =(const vector2D_type& value) volatile
			{
				data[index_x] = value.x;
				data[index_y] = value.y;
			}

			Subvec2D& operator =(const Subvec2D& value)
			{
				data[index_x] = value.data[index_x];
				data[index_y] = value.data[index_y];
				return (*this);
			}

			void operator =(const Subvec2D& value) volatile
			{
				data[index_x] = value.data[index_x];
				data[index_y] = value.data[index_y];
			}

			template <typename type, int cnt, int ind_x, int ind_y>
			Subvec2D& operator =(const Subvec2D<type, cnt, ind_x, ind_y>& value)
			{
				data[index_x] = value.data[ind_x];
				data[index_y] = value.data[ind_y];
				return (*this);
			}

			template <typename type, int cnt, int ind_x, int ind_y>
			void operator =(const Subvec2D<type, cnt, ind_x, ind_y>& value) volatile
			{
				data[index_x] = value.data[ind_x];
				data[index_y] = value.data[ind_y];
			}

			Subvec2D& operator +=(const vector2D_type& value)
			{
				data[index_x] += value.x;
				data[index_y] += value.y;
				return (*this);
			}

			template <typename type, int cnt, int ind_x, int ind_y>
			Subvec2D& operator +=(const Subvec2D<type, cnt, ind_x, ind_y>& value)
			{
				data[index_x] += value.data[ind_x];
				data[index_y] += value.data[ind_y];
				return (*this);
			}

			Subvec2D& operator -=(const vector2D_type& value)
			{
				data[index_x] -= value.x;
				data[index_y] -= value.y;
				return (*this);
			}

			template <typename type, int cnt, int ind_x, int ind_y>
			Subvec2D& operator -=(const Subvec2D<type, cnt, ind_x, ind_y>& value)
			{
				data[index_x] -= value.data[ind_x];
				data[index_y] -= value.data[ind_y];
				return (*this);
			}

			Subvec2D& operator *=(const vector2D_type& value)
			{
				data[index_x] *= value.x;
				data[index_y] *= value.y;
				return (*this);
			}

			template <typename type, int cnt, int ind_x, int ind_y>
			Subvec2D& operator *=(const Subvec2D<type, cnt, ind_x, ind_y>& value)
			{
				data[index_x] *= value.data[ind_x];
				data[index_y] *= value.data[ind_y];
				return (*this);
			}

			Subvec2D& operator *=(const component_type& s)
			{
				data[index_x] *= s;
				data[index_y] *= s;
				return (*this);
			}

			Subvec2D& operator /=(const float& s)
			{
				float t = 1.0F / s;
				data[index_x] *= t;
				data[index_y] *= t;
				return (*this);
			}

			Subvec2D& operator /=(const double& s)
			{
				double t = 1.0 / s;
				data[index_x] *= t;
				data[index_y] *= t;
				return (*this);
			}

			template <typename division_type>
			Subvec2D& operator /=(const division_type& s)
			{
				data[index_x] /= s;
				data[index_y] /= s;
				return (*this);
			}

			Subvec2D& Normalize(void)
			{
				return (*this *= InverseSqrt(data[index_x] * data[index_x] + data[index_y] * data[index_y]));
			}
	};


	template <typename A_type_struct, int A_count, int A_index_x, int A_index_y, typename B_type_struct, int B_count, int B_index_x, int B_index_y>
	inline bool operator ==(const Subvec2D<A_type_struct, A_count, A_index_x, A_index_y>& A, const Subvec2D<B_type_struct, B_count, B_index_x, B_index_y>& B)
	{
		return ((A.data[A_index_x] == B.data[B_index_x]) && (A.data[A_index_y] == B.data[B_index_y]));
	}

	template <typename A_type_struct, int A_count, int A_index_x, int A_index_y, typename B_type_struct, int B_count, int B_index_x, int B_index_y>
	inline bool operator !=(const Subvec2D<A_type_struct, A_count, A_index_x, A_index_y>& A, const Subvec2D<B_type_struct, B_count, B_index_x, B_index_y>& B)
	{
		return ((A.data[A_index_x] != B.data[B_index_x]) || (A.data[A_index_y] != B.data[B_index_y]));
	}


	template <typename type_struct, int index_x, int index_y, int index_z>
	struct ConverterVector3D
	{
		typedef typename type_struct::component_type component_type;
		typedef typename type_struct::vector3D_type vector3D_type;
		typedef typename type_struct::vector3D_type const_vector3D_type;

		static vector3D_type Convert(component_type *data)
		{
			return (vector3D_type(data[index_x], data[index_y], data[index_z]));
		}

		static const_vector3D_type Convert(const component_type *data)
		{
			return (const_vector3D_type(data[index_x], data[index_y], data[index_z]));
		}
	};

	template <typename type_struct>
	struct ConverterVector3D<type_struct, 0, 1, 2>
	{
		typedef typename type_struct::component_type component_type;
		typedef typename type_struct::vector3D_type& vector3D_type;
		typedef const typename type_struct::vector3D_type& const_vector3D_type;

		static vector3D_type Convert(component_type *data)
		{
			return (reinterpret_cast<vector3D_type>(data[0]));
		}

		static const_vector3D_type Convert(const component_type *data)
		{
			return (reinterpret_cast<const_vector3D_type>(data[0]));
		}
	};

	template <typename type_struct>
	struct ConverterVector3D<type_struct, 1, 2, 3>
	{
		typedef typename type_struct::component_type component_type;
		typedef typename type_struct::vector3D_type& vector3D_type;
		typedef const typename type_struct::vector3D_type& const_vector3D_type;

		static vector3D_type Convert(component_type *data)
		{
			return (reinterpret_cast<vector3D_type>(data[1]));
		}

		static const_vector3D_type Convert(const component_type *data)
		{
			return (reinterpret_cast<const_vector3D_type>(data[1]));
		}
	};


	template <typename type_struct, bool anti, int count, int index_x, int index_y, int index_z>
	class Subvec3D
	{
		public:

			typedef typename type_struct::component_type component_type;
			typedef typename type_struct::vector3D_type vector3D_type;

			component_type		data[count];

			Subvec3D& Set(const component_type& x, const component_type& y, const component_type& z)
			{
				data[index_x] = x;
				data[index_y] = y;
				data[index_z] = z;
				return (*this);
			}

			void Set(const component_type& x, const component_type& y, const component_type& z) volatile
			{
				data[index_x] = x;
				data[index_y] = y;
				data[index_z] = z;
			}

			operator typename ConverterVector3D<type_struct, index_x, index_y, index_z>::vector3D_type(void)
			{
				return (ConverterVector3D<type_struct, index_x, index_y, index_z>::Convert(data));
			}

			operator typename ConverterVector3D<type_struct, index_x, index_y, index_z>::const_vector3D_type(void) const
			{
				return (ConverterVector3D<type_struct, index_x, index_y, index_z>::Convert(data));
			}

			Subvec3D& operator =(const vector3D_type& value)
			{
				data[index_x] = value.x;
				data[index_y] = value.y;
				data[index_z] = value.z;
				return (*this);
			}

			void operator =(const vector3D_type& value) volatile
			{
				data[index_x] = value.x;
				data[index_y] = value.y;
				data[index_z] = value.z;
			}

			Subvec3D& operator =(const Subvec3D& value)
			{
				data[index_x] = value.data[index_x];
				data[index_y] = value.data[index_y];
				data[index_z] = value.data[index_z];
				return (*this);
			}

			void operator =(const Subvec3D& value) volatile
			{
				data[index_x] = value.data[index_x];
				data[index_y] = value.data[index_y];
				data[index_z] = value.data[index_z];
			}

			template <typename type, int cnt, int ind_x, int ind_y, int ind_z>
			Subvec3D& operator =(const Subvec3D<type, anti, cnt, ind_x, ind_y, ind_z>& value)
			{
				data[index_x] = value.data[ind_x];
				data[index_y] = value.data[ind_y];
				data[index_z] = value.data[ind_z];
				return (*this);
			}

			template <typename type, int cnt, int ind_x, int ind_y, int ind_z>
			void operator =(const Subvec3D<type, anti, cnt, ind_x, ind_y, ind_z>& value) volatile
			{
				data[index_x] = value.data[ind_x];
				data[index_y] = value.data[ind_y];
				data[index_z] = value.data[ind_z];
			}

			Subvec3D& operator +=(const vector3D_type& value)
			{
				data[index_x] += value.x;
				data[index_y] += value.y;
				data[index_z] += value.z;
				return (*this);
			}

			template <typename type, int cnt, int ind_x, int ind_y, int ind_z>
			Subvec3D& operator +=(const Subvec3D<type, anti, cnt, ind_x, ind_y, ind_z>& value)
			{
				data[index_x] += value.data[ind_x];
				data[index_y] += value.data[ind_y];
				data[index_z] += value.data[ind_z];
				return (*this);
			}

			Subvec3D& operator -=(const vector3D_type& value)
			{
				data[index_x] -= value.x;
				data[index_y] -= value.y;
				data[index_z] -= value.z;
				return (*this);
			}

			template <typename type, int cnt, int ind_x, int ind_y, int ind_z>
			Subvec3D& operator -=(const Subvec3D<type, anti, cnt, ind_x, ind_y, ind_z>& value)
			{
				data[index_x] -= value.data[ind_x];
				data[index_y] -= value.data[ind_y];
				data[index_z] -= value.data[ind_z];
				return (*this);
			}

			Subvec3D& operator *=(const vector3D_type& value)
			{
				data[index_x] *= value.x;
				data[index_y] *= value.y;
				data[index_z] *= value.z;
				return (*this);
			}

			template <typename type, int cnt, int ind_x, int ind_y, int ind_z>
			Subvec3D& operator *=(const Subvec3D<type, anti, cnt, ind_x, ind_y, ind_z>& value)
			{
				data[index_x] *= value.data[ind_x];
				data[index_y] *= value.data[ind_y];
				data[index_z] *= value.data[ind_z];
				return (*this);
			}

			Subvec3D& operator *=(const component_type& s)
			{
				data[index_x] *= s;
				data[index_y] *= s;
				data[index_z] *= s;
				return (*this);
			}

			Subvec3D& operator /=(const float& s)
			{
				float t = 1.0F / s;
				data[index_x] *= t;
				data[index_y] *= t;
				data[index_z] *= t;
				return (*this);
			}

			Subvec3D& operator /=(const double& s)
			{
				double t = 1.0 / s;
				data[index_x] *= t;
				data[index_y] *= t;
				data[index_z] *= t;
				return (*this);
			}

			template <typename division_type>
			Subvec3D& operator /=(const division_type& s)
			{
				data[index_x] /= s;
				data[index_y] /= s;
				data[index_z] /= s;
				return (*this);
			}

			Subvec3D& Normalize(void)
			{
				return (*this *= InverseSqrt(float(data[index_x] * data[index_x] + data[index_y] * data[index_y] + data[index_z] * data[index_z])));
			}
	};


	template <typename A_type_struct, bool A_anti, int A_count, int A_index_x, int A_index_y, int A_index_z, typename B_type_struct, bool B_anti, int B_count, int B_index_x, int B_index_y, int B_index_z>
	inline bool operator ==(const Subvec3D<A_type_struct, A_anti, A_count, A_index_x, A_index_y, A_index_z>& A, const Subvec3D<B_type_struct, B_anti, B_count, B_index_x, B_index_y, B_index_z>& B)
	{
		return ((A.data[A_index_x] == B.data[B_index_x]) && (A.data[A_index_y] == B.data[B_index_y]) && (A.data[A_index_z] == B.data[B_index_z]));
	}

	template <typename A_type_struct, bool A_anti, int A_count, int A_index_x, int A_index_y, int A_index_z, typename B_type_struct, bool B_anti, int B_count, int B_index_x, int B_index_y, int B_index_z>
	inline bool operator !=(const Subvec3D<A_type_struct, A_anti, A_count, A_index_x, A_index_y, A_index_z>& A, const Subvec3D<B_type_struct, B_anti, B_count, B_index_x, B_index_y, B_index_z>& B)
	{
		return ((A.data[A_index_x] != B.data[B_index_x]) || (A.data[A_index_y] != B.data[B_index_y]) || (A.data[A_index_z] != B.data[B_index_z]));
	}


	template <typename type_struct, int index_x, int index_y, int index_z, int index_w>
	struct ConverterVector4D
	{
		typedef typename type_struct::component_type component_type;
		typedef typename type_struct::vector4D_type vector4D_type;
		typedef typename type_struct::vector4D_type const_vector4D_type;

		static vector4D_type Convert(component_type *data)
		{
			return (vector4D_type(data[index_x], data[index_y], data[index_z], data[index_w]));
		}

		static const_vector4D_type Convert(const component_type *data)
		{
			return (const_vector4D_type(data[index_x], data[index_y], data[index_z], data[index_w]));
		}
	};

	template <typename type_struct>
	struct ConverterVector4D<type_struct, 0, 1, 2, 3>
	{
		typedef typename type_struct::component_type component_type;
		typedef typename type_struct::vector4D_type& vector4D_type;
		typedef const typename type_struct::vector4D_type& const_vector4D_type;

		static vector4D_type Convert(component_type *data)
		{
			return (reinterpret_cast<vector4D_type>(data[0]));
		}

		static const_vector4D_type Convert(const component_type *data)
		{
			return (reinterpret_cast<const_vector4D_type>(data[0]));
		}
	};


	template <typename type_struct, bool anti, int count, int index_x, int index_y, int index_z, int index_w>
	class Subvec4D
	{
		public:

			typedef typename type_struct::component_type component_type;
			typedef typename type_struct::vector4D_type vector4D_type;

			component_type		data[count];

			Subvec4D& Set(const component_type& x, const component_type& y, const component_type& z, const component_type& w)
			{
				data[index_x] = x;
				data[index_y] = y;
				data[index_z] = z;
				data[index_w] = w;
				return (*this);
			}

			void Set(const component_type& x, const component_type& y, const component_type& z, const component_type& w) volatile
			{
				data[index_x] = x;
				data[index_y] = y;
				data[index_z] = z;
				data[index_w] = w;
			}

			operator typename ConverterVector4D<type_struct, index_x, index_y, index_z, index_w>::vector4D_type(void)
			{
				return (ConverterVector4D<type_struct, index_x, index_y, index_z, index_w>::Convert(data));
			}

			operator typename ConverterVector4D<type_struct, index_x, index_y, index_z, index_w>::const_vector4D_type(void) const
			{
				return (ConverterVector4D<type_struct, index_x, index_y, index_z, index_w>::Convert(data));
			}

			Subvec4D& operator =(const vector4D_type& value)
			{
				data[index_x] = value.x;
				data[index_y] = value.y;
				data[index_z] = value.z;
				data[index_w] = value.w;
				return (*this);
			}

			void operator =(const vector4D_type& value) volatile
			{
				data[index_x] = value.x;
				data[index_y] = value.y;
				data[index_z] = value.z;
				data[index_w] = value.w;
			}

			Subvec4D& operator =(const Subvec4D& value)
			{
				data[index_x] = value.data[index_x];
				data[index_y] = value.data[index_y];
				data[index_z] = value.data[index_z];
				data[index_w] = value.data[index_w];
				return (*this);
			}

			void operator =(const Subvec4D& value) volatile
			{
				data[index_x] = value.data[index_x];
				data[index_y] = value.data[index_y];
				data[index_z] = value.data[index_z];
				data[index_w] = value.data[index_w];
			}

			template <typename type, int cnt, int ind_x, int ind_y, int ind_z, int ind_w>
			Subvec4D& operator =(const Subvec4D<type, anti, cnt, ind_x, ind_y, ind_z, ind_w>& value)
			{
				data[index_x] = value.data[ind_x];
				data[index_y] = value.data[ind_y];
				data[index_z] = value.data[ind_z];
				data[index_w] = value.data[ind_w];
				return (*this);
			}

			template <typename type, int cnt, int ind_x, int ind_y, int ind_z, int ind_w>
			void operator =(const Subvec4D<type, anti, cnt, ind_x, ind_y, ind_z, ind_w>& value) volatile
			{
				data[index_x] = value.data[ind_x];
				data[index_y] = value.data[ind_y];
				data[index_z] = value.data[ind_z];
				data[index_w] = value.data[ind_w];
			}

			Subvec4D& operator +=(const vector4D_type& value)
			{
				data[index_x] += value.x;
				data[index_y] += value.y;
				data[index_z] += value.z;
				data[index_w] += value.w;
				return (*this);
			}

			template <typename type, int cnt, int ind_x, int ind_y, int ind_z, int ind_w>
			Subvec4D& operator +=(const Subvec4D<type, anti, cnt, ind_x, ind_y, ind_z, ind_w>& value)
			{
				data[index_x] += value.data[ind_x];
				data[index_y] += value.data[ind_y];
				data[index_z] += value.data[ind_z];
				data[index_w] += value.data[ind_w];
				return (*this);
			}

			Subvec4D& operator -=(const vector4D_type& value)
			{
				data[index_x] -= value.x;
				data[index_y] -= value.y;
				data[index_z] -= value.z;
				data[index_w] -= value.w;
				return (*this);
			}

			template <typename type, int cnt, int ind_x, int ind_y, int ind_z, int ind_w>
			Subvec4D& operator -=(const Subvec4D<type, anti, cnt, ind_x, ind_y, ind_z, ind_w>& value)
			{
				data[index_x] -= value.data[ind_x];
				data[index_y] -= value.data[ind_y];
				data[index_z] -= value.data[ind_z];
				data[index_w] -= value.data[ind_w];
				return (*this);
			}

			Subvec4D& operator *=(const vector4D_type& value)
			{
				data[index_x] *= value.x;
				data[index_y] *= value.y;
				data[index_z] *= value.z;
				data[index_w] *= value.w;
				return (*this);
			}

			template <typename type, int cnt, int ind_x, int ind_y, int ind_z, int ind_w>
			Subvec4D& operator *=(const Subvec4D<type, anti, cnt, ind_x, ind_y, ind_z, ind_w>& value)
			{
				data[index_x] *= value.data[ind_x];
				data[index_y] *= value.data[ind_y];
				data[index_z] *= value.data[ind_z];
				data[index_w] *= value.data[ind_w];
				return (*this);
			}

			Subvec4D& operator *=(const component_type& s)
			{
				data[index_x] *= s;
				data[index_y] *= s;
				data[index_z] *= s;
				data[index_w] *= s;
				return (*this);
			}

			Subvec4D& operator /=(const float& s)
			{
				float t = 1.0F / s;
				data[index_x] *= t;
				data[index_y] *= t;
				data[index_z] *= t;
				data[index_w] *= t;
				return (*this);
			}

			Subvec4D& operator /=(const double& s)
			{
				double t = 1.0 / s;
				data[index_x] *= t;
				data[index_y] *= t;
				data[index_z] *= t;
				data[index_w] *= t;
				return (*this);
			}

			template <typename division_type>
			Subvec4D& operator /=(const division_type& s)
			{
				data[index_x] /= s;
				data[index_y] /= s;
				data[index_z] /= s;
				data[index_w] /= s;
				return (*this);
			}

			Subvec4D& Normalize(void)
			{
				return (*this *= InverseSqrt(data[index_x] * data[index_x] + data[index_y] * data[index_y] + data[index_z] * data[index_z] + data[index_w] * data[index_w]));
			}
	};


	template <typename A_type_struct, bool A_anti, int A_count, int A_index_x, int A_index_y, int A_index_z, int A_index_w, typename B_type_struct, bool B_anti, int B_count, int B_index_x, int B_index_y, int B_index_z, int B_index_w>
	inline bool operator ==(const Subvec4D<A_type_struct, A_anti, A_count, A_index_x, A_index_y, A_index_z, A_index_w>& A, const Subvec4D<B_type_struct, B_anti, B_count, B_index_x, B_index_y, B_index_z, B_index_w>& B)
	{
		return ((A.data[A_index_x] == B.data[B_index_x]) && (A.data[A_index_y] == B.data[B_index_y]) && (A.data[A_index_z] == B.data[B_index_z]) && (A.data[A_index_w] == B.data[B_index_w]));
	}

	template <typename A_type_struct, bool A_anti, int A_count, int A_index_x, int A_index_y, int A_index_z, int A_index_w, typename B_type_struct, bool B_anti, int B_count, int B_index_x, int B_index_y, int B_index_z, int B_index_w>
	inline bool operator !=(const Subvec4D<A_type_struct, A_anti, A_count, A_index_x, A_index_y, A_index_z, A_index_w>& A, const Subvec4D<B_type_struct, B_anti, B_count, B_index_x, B_index_y, B_index_z, B_index_w>& B)
	{
		return ((A.data[A_index_x] != B.data[B_index_x]) || (A.data[A_index_y] != B.data[B_index_y]) || (A.data[A_index_z] != B.data[B_index_z]) || (A.data[A_index_w] != B.data[B_index_w]));
	}


	template <typename type_struct>
	class Vec2D
	{
		public:

			typedef typename type_struct::component_type component_type;
			typedef typename type_struct::vector2D_type vector2D_type;

			union
			{
				Component<type_struct, 2, 0>		x;
				Component<type_struct, 2, 1>		y;

				Subvec2D<type_struct, 2, 0, 1>		xy;
				Subvec2D<type_struct, 2, 1, 0>		yx;

				#ifdef TERATHON_SWIZZLE_REPEAT

					const Subvec2D<type_struct, 2, 0, 0>	xx;
					const Subvec2D<type_struct, 2, 1, 1>	yy;

				#endif
			};

		protected:

			inline Vec2D() = default;

			Vec2D(const Vec2D& v)
			{
				xy = v.xy;
			}

			Vec2D(const component_type& a, const component_type& b)
			{
				x = a;
				y = b;
			}

		public:

			component_type& operator [](machine k)
			{
				return ((&x)[k]);
			}

			const component_type& operator [](machine k) const
			{
				return ((&x)[k]);
			}

			Vec2D& operator =(const vector2D_type& v)
			{
				xy = v.xy;
				return (*this);
			}

			void operator =(const vector2D_type& v) volatile
			{
				xy = v.xy;
			}

			Vec2D& operator =(const Vec2D& v)
			{
				xy = v.xy;
				return (*this);
			}

			void operator =(const Vec2D& v) volatile
			{
				xy = v.xy;
			}

			template <typename type, int cnt, int ind_x, int ind_y>
			Vec2D& operator =(const Subvec2D<type, cnt, ind_x, ind_y>& v)
			{
				xy = v;
				return (*this);
			}

			template <typename type, int cnt, int ind_x, int ind_y>
			void operator =(const Subvec2D<type, cnt, ind_x, ind_y>& v) volatile
			{
				xy = v;
			}
	};


	template <typename type_struct>
	inline bool operator ==(const Vec2D<type_struct>& v1, const Vec2D<type_struct>& v2)
	{
		return (v1.xy == v2.xy);
	}

	template <typename type_struct>
	inline bool operator !=(const Vec2D<type_struct>& v1, const Vec2D<type_struct>& v2)
	{
		return (v1.xy != v2.xy);
	}


	template <typename type_struct, bool anti = false>
	class Vec3D
	{
		public:

			typedef typename type_struct::component_type component_type;
			typedef typename type_struct::vector3D_type vector3D_type;

			union
			{
				Component<type_struct, 3, 0>				x;
				Component<type_struct, 3, 1>				y;
				Component<type_struct, 3, 2>				z;

				Subvec2D<type_struct, 3, 0, 1>				xy;
				Subvec2D<type_struct, 3, 0, 2>				xz;
				Subvec2D<type_struct, 3, 1, 0>				yx;
				Subvec2D<type_struct, 3, 1, 2>				yz;
				Subvec2D<type_struct, 3, 2, 0>				zx;
				Subvec2D<type_struct, 3, 2, 1>				zy;

				Subvec3D<type_struct, anti, 3, 0, 1, 2>		xyz;
				Subvec3D<type_struct, anti, 3, 0, 2, 1>		xzy;
				Subvec3D<type_struct, anti, 3, 1, 0, 2>		yxz;
				Subvec3D<type_struct, anti, 3, 1, 2, 0>		yzx;
				Subvec3D<type_struct, anti, 3, 2, 0, 1>		zxy;
				Subvec3D<type_struct, anti, 3, 2, 1, 0>		zyx;

				#ifdef TERATHON_SWIZZLE_REPEAT

					const Subvec2D<type_struct, 3, 0, 0>				xx;
					const Subvec2D<type_struct, 3, 1, 1>				yy;
					const Subvec2D<type_struct, 3, 2, 2>				zz;

					const Subvec3D<type_struct, anti, 3, 0, 0, 0>		xxx;
					const Subvec3D<type_struct, anti, 3, 0, 0, 1>		xxy;
					const Subvec3D<type_struct, anti, 3, 0, 0, 2>		xxz;
					const Subvec3D<type_struct, anti, 3, 0, 1, 0>		xyx;
					const Subvec3D<type_struct, anti, 3, 0, 1, 1>		xyy;
					const Subvec3D<type_struct, anti, 3, 0, 2, 0>		xzx;
					const Subvec3D<type_struct, anti, 3, 0, 2, 2>		xzz;
					const Subvec3D<type_struct, anti, 3, 1, 0, 0>		yxx;
					const Subvec3D<type_struct, anti, 3, 1, 0, 1>		yxy;
					const Subvec3D<type_struct, anti, 3, 1, 1, 0>		yyx;
					const Subvec3D<type_struct, anti, 3, 1, 1, 1>		yyy;
					const Subvec3D<type_struct, anti, 3, 1, 1, 2>		yyz;
					const Subvec3D<type_struct, anti, 3, 1, 2, 1>		yzy;
					const Subvec3D<type_struct, anti, 3, 1, 2, 2>		yzz;
					const Subvec3D<type_struct, anti, 3, 2, 0, 0>		zxx;
					const Subvec3D<type_struct, anti, 3, 2, 0, 2>		zxz;
					const Subvec3D<type_struct, anti, 3, 2, 1, 1>		zyy;
					const Subvec3D<type_struct, anti, 3, 2, 1, 2>		zyz;
					const Subvec3D<type_struct, anti, 3, 2, 2, 0>		zzx;
					const Subvec3D<type_struct, anti, 3, 2, 2, 1>		zzy;
					const Subvec3D<type_struct, anti, 3, 2, 2, 2>		zzz;

				#endif
			};

		protected:

			inline Vec3D() = default;

			Vec3D(const Vec3D& v)
			{
				xyz = v.xyz;
			}

			Vec3D(const component_type& a, const component_type& b, const component_type& c)
			{
				x = a;
				y = b;
				z = c;
			}

		public:

			component_type& operator [](machine k)
			{
				return ((&x)[k]);
			}

			const component_type& operator [](machine k) const
			{
				return ((&x)[k]);
			}

			Vec3D& operator =(const vector3D_type& v)
			{
				xyz = v.xyz;
				return (*this);
			}

			void operator =(const vector3D_type& v) volatile
			{
				xyz = v.xyz;
			}

			Vec3D& operator =(const Vec3D& v)
			{
				xyz = v.xyz;
				return (*this);
			}

			void operator =(const Vec3D& v) volatile
			{
				xyz = v.xyz;
			}

			template <typename type, int cnt, int ind_x, int ind_y, int ind_z>
			Vec3D& operator =(const Subvec3D<type, anti, cnt, ind_x, ind_y, ind_z>& v)
			{
				xyz = v;
				return (*this);
			}

			template <typename type, int cnt, int ind_x, int ind_y, int ind_z>
			void operator =(const Subvec3D<type, anti, cnt, ind_x, ind_y, ind_z>& v) volatile
			{
				xyz = v;
			}
	};


	template <typename type_struct, bool anti>
	inline bool operator ==(const Vec3D<type_struct, anti>& v1, const Vec3D<type_struct, anti>& v2)
	{
		return (v1.xyz == v2.xyz);
	}

	template <typename type_struct, bool anti>
	inline bool operator !=(const Vec3D<type_struct, anti>& v1, const Vec3D<type_struct, anti>& v2)
	{
		return (v1.xyz != v2.xyz);
	}


	template <typename type_struct, bool anti = false>
	class Vec4D
	{
		public:

			typedef typename type_struct::component_type component_type;
			typedef typename type_struct::vector4D_type vector4D_type;

			union
			{
				Component<type_struct, 4, 0>					x;
				Component<type_struct, 4, 1>					y;
				Component<type_struct, 4, 2>					z;
				Component<type_struct, 4, 3>					w;

				Subvec2D<type_struct, 4, 0, 1>					xy;
				Subvec2D<type_struct, 4, 0, 2>					xz;
				Subvec2D<type_struct, 4, 0, 3>					xw;
				Subvec2D<type_struct, 4, 1, 0>					yx;
				Subvec2D<type_struct, 4, 1, 2>					yz;
				Subvec2D<type_struct, 4, 1, 3>					yw;
				Subvec2D<type_struct, 4, 2, 0>					zx;
				Subvec2D<type_struct, 4, 2, 1>					zy;
				Subvec2D<type_struct, 4, 2, 3>					zw;
				Subvec2D<type_struct, 4, 3, 0>					wx;
				Subvec2D<type_struct, 4, 3, 1>					wy;
				Subvec2D<type_struct, 4, 3, 2>					wz;

				Subvec3D<type_struct, anti, 4, 0, 1, 2>			xyz;
				Subvec3D<type_struct, anti, 4, 0, 2, 1>			xzy;
				Subvec3D<type_struct, anti, 4, 0, 1, 3>			xyw;
				Subvec3D<type_struct, anti, 4, 0, 3, 1>			xwy;
				Subvec3D<type_struct, anti, 4, 0, 2, 3>			xzw;
				Subvec3D<type_struct, anti, 4, 0, 3, 2>			xwz;
				Subvec3D<type_struct, anti, 4, 1, 0, 2>			yxz;
				Subvec3D<type_struct, anti, 4, 1, 2, 0>			yzx;
				Subvec3D<type_struct, anti, 4, 1, 0, 3>			yxw;
				Subvec3D<type_struct, anti, 4, 1, 3, 0>			ywx;
				Subvec3D<type_struct, anti, 4, 1, 2, 3>			yzw;
				Subvec3D<type_struct, anti, 4, 1, 3, 2>			ywz;
				Subvec3D<type_struct, anti, 4, 2, 0, 1>			zxy;
				Subvec3D<type_struct, anti, 4, 2, 1, 0>			zyx;
				Subvec3D<type_struct, anti, 4, 2, 0, 3>			zxw;
				Subvec3D<type_struct, anti, 4, 2, 3, 0>			zwx;
				Subvec3D<type_struct, anti, 4, 2, 1, 3>			zyw;
				Subvec3D<type_struct, anti, 4, 2, 3, 1>			zwy;
				Subvec3D<type_struct, anti, 4, 3, 0, 1>			wxy;
				Subvec3D<type_struct, anti, 4, 3, 1, 0>			wyx;
				Subvec3D<type_struct, anti, 4, 3, 0, 2>			wxz;
				Subvec3D<type_struct, anti, 4, 3, 2, 0>			wzx;
				Subvec3D<type_struct, anti, 4, 3, 1, 2>			wyz;
				Subvec3D<type_struct, anti, 4, 3, 2, 1>			wzy;

				Subvec4D<type_struct, anti, 4, 0, 1, 2, 3>		xyzw;
				Subvec4D<type_struct, anti, 4, 0, 1, 3, 2>		xywz;
				Subvec4D<type_struct, anti, 4, 0, 2, 1, 3>		xzyw;
				Subvec4D<type_struct, anti, 4, 0, 2, 3, 1>		xzwy;
				Subvec4D<type_struct, anti, 4, 0, 3, 1, 2>		xwyz;
				Subvec4D<type_struct, anti, 4, 0, 3, 2, 1>		xwzy;
				Subvec4D<type_struct, anti, 4, 1, 0, 2, 3>		yxzw;
				Subvec4D<type_struct, anti, 4, 1, 0, 3, 2>		yxwz;
				Subvec4D<type_struct, anti, 4, 1, 2, 0, 3>		yzxw;
				Subvec4D<type_struct, anti, 4, 1, 2, 3, 0>		yzwx;
				Subvec4D<type_struct, anti, 4, 1, 3, 0, 2>		ywxz;
				Subvec4D<type_struct, anti, 4, 1, 3, 2, 0>		ywzx;
				Subvec4D<type_struct, anti, 4, 2, 0, 1, 3>		zxyw;
				Subvec4D<type_struct, anti, 4, 2, 0, 3, 1>		zxwy;
				Subvec4D<type_struct, anti, 4, 2, 1, 0, 3>		zyxw;
				Subvec4D<type_struct, anti, 4, 2, 1, 3, 0>		zywx;
				Subvec4D<type_struct, anti, 4, 2, 3, 0, 1>		zwxy;
				Subvec4D<type_struct, anti, 4, 2, 3, 1, 0>		zwyx;
				Subvec4D<type_struct, anti, 4, 3, 0, 1, 2>		wxyz;
				Subvec4D<type_struct, anti, 4, 3, 0, 2, 1>		wxzy;
				Subvec4D<type_struct, anti, 4, 3, 1, 0, 2>		wyxz;
				Subvec4D<type_struct, anti, 4, 3, 1, 2, 0>		wyzx;
				Subvec4D<type_struct, anti, 4, 3, 2, 0, 1>		wzxy;
				Subvec4D<type_struct, anti, 4, 3, 2, 1, 0>		wzyx;

				#ifdef TERATHON_SWIZZLE_REPEAT

					const Subvec2D<type_struct, 4, 0, 0>				xx;
					const Subvec2D<type_struct, 4, 1, 1>				yy;
					const Subvec2D<type_struct, 4, 2, 2>				zz;
					const Subvec2D<type_struct, 4, 3, 3>				ww;

					const Subvec3D<type_struct, anti, 4, 0, 0, 0>		xxx;
					const Subvec3D<type_struct, anti, 4, 0, 0, 1>		xxy;
					const Subvec3D<type_struct, anti, 4, 0, 0, 2>		xxz;
					const Subvec3D<type_struct, anti, 4, 0, 0, 3>		xxw;
					const Subvec3D<type_struct, anti, 4, 0, 1, 0>		xyx;
					const Subvec3D<type_struct, anti, 4, 0, 1, 1>		xyy;
					const Subvec3D<type_struct, anti, 4, 0, 2, 0>		xzx;
					const Subvec3D<type_struct, anti, 4, 0, 2, 2>		xzz;
					const Subvec3D<type_struct, anti, 4, 0, 3, 0>		xwx;
					const Subvec3D<type_struct, anti, 4, 0, 3, 3>		xww;
					const Subvec3D<type_struct, anti, 4, 1, 0, 0>		yxx;
					const Subvec3D<type_struct, anti, 4, 1, 0, 1>		yxy;
					const Subvec3D<type_struct, anti, 4, 1, 1, 0>		yyx;
					const Subvec3D<type_struct, anti, 4, 1, 1, 1>		yyy;
					const Subvec3D<type_struct, anti, 4, 1, 1, 2>		yyz;
					const Subvec3D<type_struct, anti, 4, 1, 1, 3>		yyw;
					const Subvec3D<type_struct, anti, 4, 1, 2, 1>		yzy;
					const Subvec3D<type_struct, anti, 4, 1, 2, 2>		yzz;
					const Subvec3D<type_struct, anti, 4, 1, 3, 1>		ywy;
					const Subvec3D<type_struct, anti, 4, 1, 3, 3>		yww;
					const Subvec3D<type_struct, anti, 4, 2, 0, 0>		zxx;
					const Subvec3D<type_struct, anti, 4, 2, 0, 2>		zxz;
					const Subvec3D<type_struct, anti, 4, 2, 1, 1>		zyy;
					const Subvec3D<type_struct, anti, 4, 2, 1, 2>		zyz;
					const Subvec3D<type_struct, anti, 4, 2, 2, 0>		zzx;
					const Subvec3D<type_struct, anti, 4, 2, 2, 1>		zzy;
					const Subvec3D<type_struct, anti, 4, 2, 2, 2>		zzz;
					const Subvec3D<type_struct, anti, 4, 2, 2, 3>		zzw;
					const Subvec3D<type_struct, anti, 4, 2, 3, 2>		zwz;
					const Subvec3D<type_struct, anti, 4, 2, 3, 3>		zww;
					const Subvec3D<type_struct, anti, 4, 3, 0, 0>		wxx;
					const Subvec3D<type_struct, anti, 4, 3, 0, 3>		wxw;
					const Subvec3D<type_struct, anti, 4, 3, 1, 1>		wyy;
					const Subvec3D<type_struct, anti, 4, 3, 1, 3>		wyw;
					const Subvec3D<type_struct, anti, 4, 3, 2, 2>		wzz;
					const Subvec3D<type_struct, anti, 4, 3, 2, 3>		wzw;
					const Subvec3D<type_struct, anti, 4, 3, 3, 0>		wwx;
					const Subvec3D<type_struct, anti, 4, 3, 3, 1>		wwy;
					const Subvec3D<type_struct, anti, 4, 3, 3, 2>		wwz;
					const Subvec3D<type_struct, anti, 4, 3, 3, 3>		www;

					const Subvec4D<type_struct, anti, 4, 0, 0, 0, 0>	xxxx;
					const Subvec4D<type_struct, anti, 4, 0, 0, 0, 1>	xxxy;
					const Subvec4D<type_struct, anti, 4, 0, 0, 0, 2>	xxxz;
					const Subvec4D<type_struct, anti, 4, 0, 0, 0, 3>	xxxw;
					const Subvec4D<type_struct, anti, 4, 0, 0, 1, 0>	xxyx;
					const Subvec4D<type_struct, anti, 4, 0, 0, 1, 1>	xxyy;
					const Subvec4D<type_struct, anti, 4, 0, 0, 1, 2>	xxyz;
					const Subvec4D<type_struct, anti, 4, 0, 0, 1, 3>	xxyw;
					const Subvec4D<type_struct, anti, 4, 0, 0, 2, 0>	xxzx;
					const Subvec4D<type_struct, anti, 4, 0, 0, 2, 1>	xxzy;
					const Subvec4D<type_struct, anti, 4, 0, 0, 2, 2>	xxzz;
					const Subvec4D<type_struct, anti, 4, 0, 0, 2, 3>	xxzw;
					const Subvec4D<type_struct, anti, 4, 0, 0, 3, 0>	xxwx;
					const Subvec4D<type_struct, anti, 4, 0, 0, 3, 1>	xxwy;
					const Subvec4D<type_struct, anti, 4, 0, 0, 3, 2>	xxwz;
					const Subvec4D<type_struct, anti, 4, 0, 0, 3, 3>	xxww;
					const Subvec4D<type_struct, anti, 4, 0, 1, 0, 0>	xyxx;
					const Subvec4D<type_struct, anti, 4, 0, 1, 0, 1>	xyxy;
					const Subvec4D<type_struct, anti, 4, 0, 1, 0, 2>	xyxz;
					const Subvec4D<type_struct, anti, 4, 0, 1, 0, 3>	xyxw;
					const Subvec4D<type_struct, anti, 4, 0, 1, 1, 0>	xyyx;
					const Subvec4D<type_struct, anti, 4, 0, 1, 1, 1>	xyyy;
					const Subvec4D<type_struct, anti, 4, 0, 1, 1, 2>	xyyz;
					const Subvec4D<type_struct, anti, 4, 0, 1, 1, 3>	xyyw;
					const Subvec4D<type_struct, anti, 4, 0, 1, 2, 0>	xyzx;
					const Subvec4D<type_struct, anti, 4, 0, 1, 2, 1>	xyzy;
					const Subvec4D<type_struct, anti, 4, 0, 1, 2, 2>	xyzz;
					const Subvec4D<type_struct, anti, 4, 0, 1, 3, 0>	xywx;
					const Subvec4D<type_struct, anti, 4, 0, 1, 3, 1>	xywy;
					const Subvec4D<type_struct, anti, 4, 0, 1, 3, 3>	xyww;
					const Subvec4D<type_struct, anti, 4, 0, 2, 0, 0>	xzxx;
					const Subvec4D<type_struct, anti, 4, 0, 2, 0, 1>	xzxy;
					const Subvec4D<type_struct, anti, 4, 0, 2, 0, 2>	xzxz;
					const Subvec4D<type_struct, anti, 4, 0, 2, 0, 3>	xzxw;
					const Subvec4D<type_struct, anti, 4, 0, 2, 1, 0>	xzyx;
					const Subvec4D<type_struct, anti, 4, 0, 2, 1, 1>	xzyy;
					const Subvec4D<type_struct, anti, 4, 0, 2, 1, 2>	xzyz;
					const Subvec4D<type_struct, anti, 4, 0, 2, 2, 0>	xzzx;
					const Subvec4D<type_struct, anti, 4, 0, 2, 2, 1>	xzzy;
					const Subvec4D<type_struct, anti, 4, 0, 2, 2, 2>	xzzz;
					const Subvec4D<type_struct, anti, 4, 0, 2, 2, 3>	xzzw;
					const Subvec4D<type_struct, anti, 4, 0, 2, 3, 0>	xzwx;
					const Subvec4D<type_struct, anti, 4, 0, 2, 3, 2>	xzwz;
					const Subvec4D<type_struct, anti, 4, 0, 2, 3, 3>	xzww;
					const Subvec4D<type_struct, anti, 4, 0, 3, 0, 0>	xwxx;
					const Subvec4D<type_struct, anti, 4, 0, 3, 0, 1>	xwxy;
					const Subvec4D<type_struct, anti, 4, 0, 3, 0, 2>	xwxz;
					const Subvec4D<type_struct, anti, 4, 0, 3, 0, 3>	xwxw;
					const Subvec4D<type_struct, anti, 4, 0, 3, 1, 0>	xwyx;
					const Subvec4D<type_struct, anti, 4, 0, 3, 1, 1>	xwyy;
					const Subvec4D<type_struct, anti, 4, 0, 3, 1, 3>	xwyw;
					const Subvec4D<type_struct, anti, 4, 0, 3, 2, 0>	xwzx;
					const Subvec4D<type_struct, anti, 4, 0, 3, 2, 2>	xwzz;
					const Subvec4D<type_struct, anti, 4, 0, 3, 2, 3>	xwzw;
					const Subvec4D<type_struct, anti, 4, 0, 3, 3, 0>	xwwx;
					const Subvec4D<type_struct, anti, 4, 0, 3, 3, 1>	xwwy;
					const Subvec4D<type_struct, anti, 4, 0, 3, 3, 2>	xwwz;
					const Subvec4D<type_struct, anti, 4, 0, 3, 3, 3>	xwww;
					const Subvec4D<type_struct, anti, 4, 1, 0, 0, 0>	yxxx;
					const Subvec4D<type_struct, anti, 4, 1, 0, 0, 1>	yxxy;
					const Subvec4D<type_struct, anti, 4, 1, 0, 0, 2>	yxxz;
					const Subvec4D<type_struct, anti, 4, 1, 0, 0, 3>	yxxw;
					const Subvec4D<type_struct, anti, 4, 1, 0, 1, 0>	yxyx;
					const Subvec4D<type_struct, anti, 4, 1, 0, 1, 1>	yxyy;
					const Subvec4D<type_struct, anti, 4, 1, 0, 1, 2>	yxyz;
					const Subvec4D<type_struct, anti, 4, 1, 0, 1, 3>	yxyw;
					const Subvec4D<type_struct, anti, 4, 1, 0, 2, 0>	yxzx;
					const Subvec4D<type_struct, anti, 4, 1, 0, 2, 1>	yxzy;
					const Subvec4D<type_struct, anti, 4, 1, 0, 2, 2>	yxzz;
					const Subvec4D<type_struct, anti, 4, 1, 0, 3, 0>	yxwx;
					const Subvec4D<type_struct, anti, 4, 1, 0, 3, 1>	yxwy;
					const Subvec4D<type_struct, anti, 4, 1, 0, 3, 3>	yxww;
					const Subvec4D<type_struct, anti, 4, 1, 1, 0, 0>	yyxx;
					const Subvec4D<type_struct, anti, 4, 1, 1, 0, 1>	yyxy;
					const Subvec4D<type_struct, anti, 4, 1, 1, 0, 2>	yyxz;
					const Subvec4D<type_struct, anti, 4, 1, 1, 0, 3>	yyxw;
					const Subvec4D<type_struct, anti, 4, 1, 1, 1, 0>	yyyx;
					const Subvec4D<type_struct, anti, 4, 1, 1, 1, 1>	yyyy;
					const Subvec4D<type_struct, anti, 4, 1, 1, 1, 2>	yyyz;
					const Subvec4D<type_struct, anti, 4, 1, 1, 1, 3>	yyyw;
					const Subvec4D<type_struct, anti, 4, 1, 1, 2, 0>	yyzx;
					const Subvec4D<type_struct, anti, 4, 1, 1, 2, 1>	yyzy;
					const Subvec4D<type_struct, anti, 4, 1, 1, 2, 2>	yyzz;
					const Subvec4D<type_struct, anti, 4, 1, 1, 2, 3>	yyzw;
					const Subvec4D<type_struct, anti, 4, 1, 1, 3, 0>	yywx;
					const Subvec4D<type_struct, anti, 4, 1, 1, 3, 1>	yywy;
					const Subvec4D<type_struct, anti, 4, 1, 1, 3, 2>	yywz;
					const Subvec4D<type_struct, anti, 4, 1, 1, 3, 3>	yyww;
					const Subvec4D<type_struct, anti, 4, 1, 2, 0, 0>	yzxx;
					const Subvec4D<type_struct, anti, 4, 1, 2, 0, 1>	yzxy;
					const Subvec4D<type_struct, anti, 4, 1, 2, 0, 2>	yzxz;
					const Subvec4D<type_struct, anti, 4, 1, 2, 1, 0>	yzyx;
					const Subvec4D<type_struct, anti, 4, 1, 2, 1, 1>	yzyy;
					const Subvec4D<type_struct, anti, 4, 1, 2, 1, 2>	yzyz;
					const Subvec4D<type_struct, anti, 4, 1, 2, 1, 3>	yzyw;
					const Subvec4D<type_struct, anti, 4, 1, 2, 2, 0>	yzzx;
					const Subvec4D<type_struct, anti, 4, 1, 2, 2, 1>	yzzy;
					const Subvec4D<type_struct, anti, 4, 1, 2, 2, 2>	yzzz;
					const Subvec4D<type_struct, anti, 4, 1, 2, 2, 3>	yzzw;
					const Subvec4D<type_struct, anti, 4, 1, 2, 3, 1>	yzwy;
					const Subvec4D<type_struct, anti, 4, 1, 2, 3, 2>	yzwz;
					const Subvec4D<type_struct, anti, 4, 1, 2, 3, 3>	yzww;
					const Subvec4D<type_struct, anti, 4, 1, 3, 0, 0>	ywxx;
					const Subvec4D<type_struct, anti, 4, 1, 3, 0, 1>	ywxy;
					const Subvec4D<type_struct, anti, 4, 1, 3, 0, 3>	ywxw;
					const Subvec4D<type_struct, anti, 4, 1, 3, 1, 0>	ywyx;
					const Subvec4D<type_struct, anti, 4, 1, 3, 1, 1>	ywyy;
					const Subvec4D<type_struct, anti, 4, 1, 3, 1, 2>	ywyz;
					const Subvec4D<type_struct, anti, 4, 1, 3, 1, 3>	ywyw;
					const Subvec4D<type_struct, anti, 4, 1, 3, 2, 1>	ywzy;
					const Subvec4D<type_struct, anti, 4, 1, 3, 2, 2>	ywzz;
					const Subvec4D<type_struct, anti, 4, 1, 3, 2, 3>	ywzw;
					const Subvec4D<type_struct, anti, 4, 1, 3, 3, 0>	ywwx;
					const Subvec4D<type_struct, anti, 4, 1, 3, 3, 1>	ywwy;
					const Subvec4D<type_struct, anti, 4, 1, 3, 3, 2>	ywwz;
					const Subvec4D<type_struct, anti, 4, 1, 3, 3, 3>	ywww;
					const Subvec4D<type_struct, anti, 4, 2, 0, 0, 0>	zxxx;
					const Subvec4D<type_struct, anti, 4, 2, 0, 0, 1>	zxxy;
					const Subvec4D<type_struct, anti, 4, 2, 0, 0, 2>	zxxz;
					const Subvec4D<type_struct, anti, 4, 2, 0, 0, 3>	zxxw;
					const Subvec4D<type_struct, anti, 4, 2, 0, 1, 0>	zxyx;
					const Subvec4D<type_struct, anti, 4, 2, 0, 1, 1>	zxyy;
					const Subvec4D<type_struct, anti, 4, 2, 0, 1, 2>	zxyz;
					const Subvec4D<type_struct, anti, 4, 2, 0, 2, 0>	zxzx;
					const Subvec4D<type_struct, anti, 4, 2, 0, 2, 1>	zxzy;
					const Subvec4D<type_struct, anti, 4, 2, 0, 2, 2>	zxzz;
					const Subvec4D<type_struct, anti, 4, 2, 0, 2, 3>	zxzw;
					const Subvec4D<type_struct, anti, 4, 2, 0, 3, 0>	zxwx;
					const Subvec4D<type_struct, anti, 4, 2, 0, 3, 2>	zxwz;
					const Subvec4D<type_struct, anti, 4, 2, 0, 3, 3>	zxww;
					const Subvec4D<type_struct, anti, 4, 2, 1, 0, 0>	zyxx;
					const Subvec4D<type_struct, anti, 4, 2, 1, 0, 1>	zyxy;
					const Subvec4D<type_struct, anti, 4, 2, 1, 0, 2>	zyxz;
					const Subvec4D<type_struct, anti, 4, 2, 1, 1, 0>	zyyx;
					const Subvec4D<type_struct, anti, 4, 2, 1, 1, 1>	zyyy;
					const Subvec4D<type_struct, anti, 4, 2, 1, 1, 2>	zyyz;
					const Subvec4D<type_struct, anti, 4, 2, 1, 1, 3>	zyyw;
					const Subvec4D<type_struct, anti, 4, 2, 1, 2, 0>	zyzx;
					const Subvec4D<type_struct, anti, 4, 2, 1, 2, 1>	zyzy;
					const Subvec4D<type_struct, anti, 4, 2, 1, 2, 2>	zyzz;
					const Subvec4D<type_struct, anti, 4, 2, 1, 2, 3>	zyzw;
					const Subvec4D<type_struct, anti, 4, 2, 1, 3, 1>	zywy;
					const Subvec4D<type_struct, anti, 4, 2, 1, 3, 2>	zywz;
					const Subvec4D<type_struct, anti, 4, 2, 1, 3, 3>	zyww;
					const Subvec4D<type_struct, anti, 4, 2, 2, 0, 0>	zzxx;
					const Subvec4D<type_struct, anti, 4, 2, 2, 0, 1>	zzxy;
					const Subvec4D<type_struct, anti, 4, 2, 2, 0, 2>	zzxz;
					const Subvec4D<type_struct, anti, 4, 2, 2, 0, 3>	zzxw;
					const Subvec4D<type_struct, anti, 4, 2, 2, 1, 0>	zzyx;
					const Subvec4D<type_struct, anti, 4, 2, 2, 1, 1>	zzyy;
					const Subvec4D<type_struct, anti, 4, 2, 2, 1, 2>	zzyz;
					const Subvec4D<type_struct, anti, 4, 2, 2, 1, 3>	zzyw;
					const Subvec4D<type_struct, anti, 4, 2, 2, 2, 0>	zzzx;
					const Subvec4D<type_struct, anti, 4, 2, 2, 2, 1>	zzzy;
					const Subvec4D<type_struct, anti, 4, 2, 2, 2, 2>	zzzz;
					const Subvec4D<type_struct, anti, 4, 2, 2, 2, 3>	zzzw;
					const Subvec4D<type_struct, anti, 4, 2, 2, 3, 0>	zzwx;
					const Subvec4D<type_struct, anti, 4, 2, 2, 3, 1>	zzwy;
					const Subvec4D<type_struct, anti, 4, 2, 2, 3, 2>	zzwz;
					const Subvec4D<type_struct, anti, 4, 2, 2, 3, 3>	zzww;
					const Subvec4D<type_struct, anti, 4, 2, 3, 0, 0>	zwxx;
					const Subvec4D<type_struct, anti, 4, 2, 3, 0, 2>	zwxz;
					const Subvec4D<type_struct, anti, 4, 2, 3, 0, 3>	zwxw;
					const Subvec4D<type_struct, anti, 4, 2, 3, 1, 1>	zwyy;
					const Subvec4D<type_struct, anti, 4, 2, 3, 1, 2>	zwyz;
					const Subvec4D<type_struct, anti, 4, 2, 3, 1, 3>	zwyw;
					const Subvec4D<type_struct, anti, 4, 2, 3, 2, 0>	zwzx;
					const Subvec4D<type_struct, anti, 4, 2, 3, 2, 1>	zwzy;
					const Subvec4D<type_struct, anti, 4, 2, 3, 2, 2>	zwzz;
					const Subvec4D<type_struct, anti, 4, 2, 3, 2, 3>	zwzw;
					const Subvec4D<type_struct, anti, 4, 2, 3, 3, 0>	zwwx;
					const Subvec4D<type_struct, anti, 4, 2, 3, 3, 1>	zwwy;
					const Subvec4D<type_struct, anti, 4, 2, 3, 3, 2>	zwwz;
					const Subvec4D<type_struct, anti, 4, 2, 3, 3, 3>	zwww;
					const Subvec4D<type_struct, anti, 4, 3, 0, 0, 0>	wxxx;
					const Subvec4D<type_struct, anti, 4, 3, 0, 0, 1>	wxxy;
					const Subvec4D<type_struct, anti, 4, 3, 0, 0, 2>	wxxz;
					const Subvec4D<type_struct, anti, 4, 3, 0, 0, 3>	wxxw;
					const Subvec4D<type_struct, anti, 4, 3, 0, 1, 0>	wxyx;
					const Subvec4D<type_struct, anti, 4, 3, 0, 1, 1>	wxyy;
					const Subvec4D<type_struct, anti, 4, 3, 0, 1, 3>	wxyw;
					const Subvec4D<type_struct, anti, 4, 3, 0, 2, 0>	wxzx;
					const Subvec4D<type_struct, anti, 4, 3, 0, 2, 2>	wxzz;
					const Subvec4D<type_struct, anti, 4, 3, 0, 2, 3>	wxzw;
					const Subvec4D<type_struct, anti, 4, 3, 0, 3, 0>	wxwx;
					const Subvec4D<type_struct, anti, 4, 3, 0, 3, 1>	wxwy;
					const Subvec4D<type_struct, anti, 4, 3, 0, 3, 2>	wxwz;
					const Subvec4D<type_struct, anti, 4, 3, 0, 3, 3>	wxww;
					const Subvec4D<type_struct, anti, 4, 3, 1, 0, 0>	wyxx;
					const Subvec4D<type_struct, anti, 4, 3, 1, 0, 1>	wyxy;
					const Subvec4D<type_struct, anti, 4, 3, 1, 0, 3>	wyxw;
					const Subvec4D<type_struct, anti, 4, 3, 1, 1, 0>	wyyx;
					const Subvec4D<type_struct, anti, 4, 3, 1, 1, 1>	wyyy;
					const Subvec4D<type_struct, anti, 4, 3, 1, 1, 2>	wyyz;
					const Subvec4D<type_struct, anti, 4, 3, 1, 1, 3>	wyyw;
					const Subvec4D<type_struct, anti, 4, 3, 1, 2, 1>	wyzy;
					const Subvec4D<type_struct, anti, 4, 3, 1, 2, 2>	wyzz;
					const Subvec4D<type_struct, anti, 4, 3, 1, 2, 3>	wyzw;
					const Subvec4D<type_struct, anti, 4, 3, 1, 3, 0>	wywx;
					const Subvec4D<type_struct, anti, 4, 3, 1, 3, 1>	wywy;
					const Subvec4D<type_struct, anti, 4, 3, 1, 3, 2>	wywz;
					const Subvec4D<type_struct, anti, 4, 3, 1, 3, 3>	wyww;
					const Subvec4D<type_struct, anti, 4, 3, 2, 0, 0>	wzxx;
					const Subvec4D<type_struct, anti, 4, 3, 2, 0, 2>	wzxz;
					const Subvec4D<type_struct, anti, 4, 3, 2, 0, 3>	wzxw;
					const Subvec4D<type_struct, anti, 4, 3, 2, 1, 1>	wzyy;
					const Subvec4D<type_struct, anti, 4, 3, 2, 1, 2>	wzyz;
					const Subvec4D<type_struct, anti, 4, 3, 2, 1, 3>	wzyw;
					const Subvec4D<type_struct, anti, 4, 3, 2, 2, 0>	wzzx;
					const Subvec4D<type_struct, anti, 4, 3, 2, 2, 1>	wzzy;
					const Subvec4D<type_struct, anti, 4, 3, 2, 2, 2>	wzzz;
					const Subvec4D<type_struct, anti, 4, 3, 2, 2, 3>	wzzw;
					const Subvec4D<type_struct, anti, 4, 3, 2, 3, 0>	wzwx;
					const Subvec4D<type_struct, anti, 4, 3, 2, 3, 1>	wzwy;
					const Subvec4D<type_struct, anti, 4, 3, 2, 3, 2>	wzwz;
					const Subvec4D<type_struct, anti, 4, 3, 2, 3, 3>	wzww;
					const Subvec4D<type_struct, anti, 4, 3, 3, 0, 0>	wwxx;
					const Subvec4D<type_struct, anti, 4, 3, 3, 0, 1>	wwxy;
					const Subvec4D<type_struct, anti, 4, 3, 3, 0, 2>	wwxz;
					const Subvec4D<type_struct, anti, 4, 3, 3, 0, 3>	wwxw;
					const Subvec4D<type_struct, anti, 4, 3, 3, 1, 0>	wwyx;
					const Subvec4D<type_struct, anti, 4, 3, 3, 1, 1>	wwyy;
					const Subvec4D<type_struct, anti, 4, 3, 3, 1, 2>	wwyz;
					const Subvec4D<type_struct, anti, 4, 3, 3, 1, 3>	wwyw;
					const Subvec4D<type_struct, anti, 4, 3, 3, 2, 0>	wwzx;
					const Subvec4D<type_struct, anti, 4, 3, 3, 2, 1>	wwzy;
					const Subvec4D<type_struct, anti, 4, 3, 3, 2, 2>	wwzz;
					const Subvec4D<type_struct, anti, 4, 3, 3, 2, 3>	wwzw;
					const Subvec4D<type_struct, anti, 4, 3, 3, 3, 0>	wwwx;
					const Subvec4D<type_struct, anti, 4, 3, 3, 3, 1>	wwwy;
					const Subvec4D<type_struct, anti, 4, 3, 3, 3, 2>	wwwz;
					const Subvec4D<type_struct, anti, 4, 3, 3, 3, 3>	wwww;

				#endif
			};

		protected:

			inline Vec4D() = default;

			Vec4D(const Vec4D& v)
			{
				xyzw = v.xyzw;
			}

			Vec4D(const component_type& a, const component_type& b, const component_type& c, const component_type& d)
			{
				x = a;
				y = b;
				z = c;
				w = d;
			}

		public:

			component_type& operator [](machine k)
			{
				return ((&x)[k]);
			}

			const component_type& operator [](machine k) const
			{
				return ((&x)[k]);
			}

			Vec4D& operator =(const vector4D_type& v)
			{
				xyzw = v.xyzw;
				return (*this);
			}

			void operator =(const vector4D_type& v) volatile
			{
				xyzw = v.xyzw;
			}

			Vec4D& operator =(const Vec4D& v)
			{
				xyzw = v.xyzw;
				return (*this);
			}

			void operator =(const Vec4D& v) volatile
			{
				xyzw = v.xyzw;
			}

			template <typename type, int cnt, int ind_x, int ind_y, int ind_z, int ind_w>
			Vec4D& operator =(const Subvec4D<type, anti, cnt, ind_x, ind_y, ind_z, ind_w>& v)
			{
				xyzw = v;
				return (*this);
			}

			template <typename type, int cnt, int ind_x, int ind_y, int ind_z, int ind_w>
			void operator =(const Subvec4D<type, anti, cnt, ind_x, ind_y, ind_z, ind_w>& v) volatile
			{
				xyzw = v;
			}
	};


	template <typename type_struct, bool anti>
	inline bool operator ==(const Vec4D<type_struct, anti>& v1, const Vec4D<type_struct, anti>& v2)
	{
		return (v1.xyzw == v2.xyzw);
	}

	template <typename type_struct, bool anti>
	inline bool operator !=(const Vec4D<type_struct, anti>& v1, const Vec4D<type_struct, anti>& v2)
	{
		return (v1.xyzw != v2.xyzw);
	}


	template <typename type_struct> using Antivec3D = Vec3D<type_struct, true>;
	template <typename type_struct> using Antivec4D = Vec4D<type_struct, true>;


	template <typename A_type_struct, bool A_anti, int A_count, int A_index_x, int A_index_y, int A_index_z, typename B_type_struct, int B_count, int B_index_x, int B_index_y, int B_index_z>
	inline float operator ^(const Subvec3D<A_type_struct, A_anti, A_count, A_index_x, A_index_y, A_index_z>& A, const Subvec3D<B_type_struct, !A_anti, B_count, B_index_x, B_index_y, B_index_z>& B)
	{
		return (A.data[A_index_x] * B.data[B_index_x] + A.data[A_index_y] * B.data[B_index_y] + A.data[A_index_z] * B.data[B_index_z]);
	}

	template <typename A_type_struct, int A_count, int A_index_x, int A_index_y, int A_index_z, int A_index_w, typename B_type_struct, int B_count, int B_index_x, int B_index_y, int B_index_z, int B_index_w>
	inline float operator ^(const Subvec4D<A_type_struct, false, A_count, A_index_x, A_index_y, A_index_z, A_index_w>& A, const Subvec4D<B_type_struct, true, B_count, B_index_x, B_index_y, B_index_z, B_index_w>& B)
	{
		return (A.data[A_index_x] * B.data[B_index_x] + A.data[A_index_y] * B.data[B_index_y] + A.data[A_index_z] * B.data[B_index_z] + A.data[A_index_w] * B.data[B_index_w]);
	}

	template <typename A_type_struct, int A_count, int A_index_x, int A_index_y, int A_index_z, int A_index_w, typename B_type_struct, int B_count, int B_index_x, int B_index_y, int B_index_z>
	inline float operator ^(const Subvec4D<A_type_struct, false, A_count, A_index_x, A_index_y, A_index_z, A_index_w>& A, const Subvec3D<B_type_struct, true, B_count, B_index_x, B_index_y, B_index_z>& B)
	{
		return (A.data[A_index_x] * B.data[B_index_x] + A.data[A_index_y] * B.data[B_index_y] + A.data[A_index_z] * B.data[B_index_z]);
	}

	template <typename A_type_struct, int A_count, int A_index_x, int A_index_y, int A_index_z, typename B_type_struct, int B_count, int B_index_x, int B_index_y, int B_index_z, int B_index_w>
	inline float operator ^(const Subvec3D<A_type_struct, false, A_count, A_index_x, A_index_y, A_index_z>& A, const Subvec4D<B_type_struct, true, B_count, B_index_x, B_index_y, B_index_z, B_index_w>& B)
	{
		return (A.data[A_index_x] * B.data[B_index_x] + A.data[A_index_y] * B.data[B_index_y] + A.data[A_index_z] * B.data[B_index_z]);
	}


	template <typename type_struct, int index_00, int index_01, int index_10, int index_11>
	struct ConverterMatrix2D
	{
		typedef typename type_struct::component_type component_type;
		typedef typename type_struct::matrix2D_type matrix2D_type;
		typedef typename type_struct::matrix2D_type const_matrix2D_type;

		static matrix2D_type Convert(component_type *data)
		{
			return (matrix2D_type(data[index_00], data[index_01], data[index_10], data[index_11]));
		}

		static const_matrix2D_type Convert(const component_type *data)
		{
			return (const_matrix2D_type(data[index_00], data[index_01], data[index_10], data[index_11]));
		}
	};

	template <typename type_struct>
	struct ConverterMatrix2D<type_struct, 0, 2, 1, 3>
	{
		typedef typename type_struct::component_type component_type;
		typedef typename type_struct::matrix2D_type& matrix2D_type;
		typedef const typename type_struct::matrix2D_type& const_matrix2D_type;

		static matrix2D_type Convert(component_type *data)
		{
			return (reinterpret_cast<matrix2D_type>(data[0]));
		}

		static const_matrix2D_type Convert(const component_type *data)
		{
			return (reinterpret_cast<const_matrix2D_type>(data[0]));
		}
	};


	template <typename type_struct, int count, int index_00, int index_01, int index_10, int index_11>
	class Submat2D
	{
		public:

			typedef typename type_struct::component_type component_type;
			typedef typename type_struct::matrix2D_type matrix2D_type;

			component_type		data[count];

			Submat2D& Set(const component_type& m00, const component_type& m01, const component_type& m10, const component_type& m11)
			{
				data[index_00] = m00;
				data[index_10] = m10;
				data[index_01] = m01;
				data[index_11] = m11;
				return (*this);
			}

			void Set(const component_type& m00, const component_type& m01, const component_type& m10, const component_type& m11) volatile
			{
				data[index_00] = m00;
				data[index_10] = m10;
				data[index_01] = m01;
				data[index_11] = m11;
			}

			operator typename ConverterMatrix2D<type_struct, index_00, index_01, index_10, index_11>::matrix2D_type(void)
			{
				return (ConverterMatrix2D<type_struct, index_00, index_01, index_10, index_11>::Convert(data));
			}

			operator typename ConverterMatrix2D<type_struct, index_00, index_01, index_10, index_11>::const_matrix2D_type(void) const
			{
				return (ConverterMatrix2D<type_struct, index_00, index_01, index_10, index_11>::Convert(data));
			}

			Submat2D& operator =(const matrix2D_type& value)
			{
				data[index_00] = value.m00;
				data[index_10] = value.m10;
				data[index_01] = value.m01;
				data[index_11] = value.m11;
				return (*this);
			}

			void operator =(const matrix2D_type& value) volatile
			{
				data[index_00] = value.m00;
				data[index_10] = value.m10;
				data[index_01] = value.m01;
				data[index_11] = value.m11;
			}

			Submat2D& operator =(const Submat2D& value)
			{
				data[index_00] = value.data[index_00];
				data[index_10] = value.data[index_10];
				data[index_01] = value.data[index_01];
				data[index_11] = value.data[index_11];
				return (*this);
			}

			void operator =(const Submat2D& value) volatile
			{
				data[index_00] = value.data[index_00];
				data[index_10] = value.data[index_10];
				data[index_01] = value.data[index_01];
				data[index_11] = value.data[index_11];
			}

			template <typename type, int cnt, int ind_00, int ind_01, int ind_10, int ind_11>
			Submat2D& operator =(const Submat2D<type, cnt, ind_00, ind_01, ind_10, ind_11>& value)
			{
				data[index_00] = value.data[ind_00];
				data[index_10] = value.data[ind_10];
				data[index_01] = value.data[ind_01];
				data[index_11] = value.data[ind_11];
				return (*this);
			}

			template <typename type, int cnt, int ind_00, int ind_01, int ind_10, int ind_11>
			void operator =(const Submat2D<type, cnt, ind_00, ind_01, ind_10, ind_11>& value) volatile
			{
				data[index_00] = value.data[ind_00];
				data[index_10] = value.data[ind_10];
				data[index_01] = value.data[ind_01];
				data[index_11] = value.data[ind_11];
			}

			Submat2D& operator *=(const component_type& s)
			{
				data[index_00] *= s;
				data[index_10] *= s;
				data[index_01] *= s;
				data[index_11] *= s;
				return (*this);
			}

			Submat2D& operator /=(const float& s)
			{
				float t = 1.0F / s;
				data[index_00] *= t;
				data[index_10] *= t;
				data[index_01] *= t;
				data[index_11] *= t;
				return (*this);
			}

			Submat2D& operator /=(const double& s)
			{
				double t = 1.0 / s;
				data[index_00] *= t;
				data[index_10] *= t;
				data[index_01] *= t;
				data[index_11] *= t;
				return (*this);
			}

			template <typename division_type>
			Submat2D& operator /=(const division_type& s)
			{
				data[index_00] /= s;
				data[index_10] /= s;
				data[index_01] /= s;
				data[index_11] /= s;
				return (*this);
			}
	};


	template <typename A_type_struct, int A_count, int A_index_00, int A_index_01, int A_index_10, int A_index_11, typename B_type_struct, int B_count, int B_index_00, int B_index_01, int B_index_10, int B_index_11>
	inline bool operator ==(const Submat2D<A_type_struct, A_count, A_index_00, A_index_01, A_index_10, A_index_11>& A, const Submat2D<B_type_struct, B_count, B_index_00, B_index_01, B_index_10, B_index_11>& B)
	{
		return ((A.data[A_index_00] == B.data[B_index_00]) && (A.data[A_index_01] == B.data[B_index_01]) && (A.data[A_index_10] == B.data[B_index_10]) && (A.data[A_index_11] == B.data[B_index_11]));
	}

	template <typename A_type_struct, int A_count, int A_index_00, int A_index_01, int A_index_10, int A_index_11, typename B_type_struct, int B_count, int B_index_00, int B_index_01, int B_index_10, int B_index_11>
	inline bool operator !=(const Submat2D<A_type_struct, A_count, A_index_00, A_index_01, A_index_10, A_index_11>& A, const Submat2D<B_type_struct, B_count, B_index_00, B_index_01, B_index_10, B_index_11>& B)
	{
		return ((A.data[A_index_00] != B.data[B_index_00]) || (A.data[A_index_01] != B.data[B_index_01]) || (A.data[A_index_10] != B.data[B_index_10]) || (A.data[A_index_11] != B.data[B_index_11]));
	}


	template <typename type_struct, int index_00, int index_01, int index_02, int index_10, int index_11, int index_12, int index_20, int index_21, int index_22>
	struct ConverterMatrix3D
	{
		typedef typename type_struct::component_type component_type;
		typedef typename type_struct::matrix3D_type matrix3D_type;
		typedef typename type_struct::matrix3D_type const_matrix3D_type;

		static matrix3D_type Convert(component_type *data)
		{
			return (matrix3D_type(data[index_00], data[index_01], data[index_02], data[index_10], data[index_11], data[index_12], data[index_20], data[index_21], data[index_22]));
		}

		static const_matrix3D_type Convert(const component_type *data)
		{
			return (const_matrix3D_type(data[index_00], data[index_01], data[index_02], data[index_10], data[index_11], data[index_12], data[index_20], data[index_21], data[index_22]));
		}
	};

	template <typename type_struct>
	struct ConverterMatrix3D<type_struct, 0, 3, 6, 1, 4, 7, 2, 5, 8>
	{
		typedef typename type_struct::component_type component_type;
		typedef typename type_struct::matrix3D_type& matrix3D_type;
		typedef const typename type_struct::matrix3D_type& const_matrix3D_type;

		static matrix3D_type Convert(component_type *data)
		{
			return (reinterpret_cast<matrix3D_type>(data[0]));
		}

		static const_matrix3D_type Convert(const component_type *data)
		{
			return (reinterpret_cast<const_matrix3D_type>(data[0]));
		}
	};


	template <typename type_struct, int count, int index_00, int index_01, int index_02, int index_10, int index_11, int index_12, int index_20, int index_21, int index_22>
	class Submat3D
	{
		public:

			typedef typename type_struct::component_type component_type;
			typedef typename type_struct::matrix3D_type matrix3D_type;

			component_type		data[count];

			Submat3D& Set(const component_type& m00, const component_type& m01, const component_type& m02, const component_type& m10, const component_type& m11, const component_type& m12, const component_type& m20, const component_type& m21, const component_type& m22)
			{
				data[index_00] = m00;
				data[index_10] = m10;
				data[index_20] = m20;
				data[index_01] = m01;
				data[index_11] = m11;
				data[index_21] = m21;
				data[index_02] = m02;
				data[index_12] = m12;
				data[index_22] = m22;
				return (*this);
			}

			void Set(const component_type& m00, const component_type& m01, const component_type& m02, const component_type& m10, const component_type& m11, const component_type& m12, const component_type& m20, const component_type& m21, const component_type& m22) volatile
			{
				data[index_00] = m00;
				data[index_10] = m10;
				data[index_20] = m20;
				data[index_01] = m01;
				data[index_11] = m11;
				data[index_21] = m21;
				data[index_02] = m02;
				data[index_12] = m12;
				data[index_22] = m22;
			}

			operator typename ConverterMatrix3D<type_struct, index_00, index_01, index_02, index_10, index_11, index_12, index_20, index_21, index_22>::matrix3D_type(void)
			{
				return (ConverterMatrix3D<type_struct, index_00, index_01, index_02, index_10, index_11, index_12, index_20, index_21, index_22>::Convert(data));
			}

			operator typename ConverterMatrix3D<type_struct, index_00, index_01, index_02, index_10, index_11, index_12, index_20, index_21, index_22>::const_matrix3D_type(void) const
			{
				return (ConverterMatrix3D<type_struct, index_00, index_01, index_02, index_10, index_11, index_12, index_20, index_21, index_22>::Convert(data));
			}

			Submat3D& operator =(const matrix3D_type& value)
			{
				data[index_00] = value.m00;
				data[index_10] = value.m10;
				data[index_20] = value.m20;
				data[index_01] = value.m01;
				data[index_11] = value.m11;
				data[index_21] = value.m21;
				data[index_02] = value.m02;
				data[index_12] = value.m12;
				data[index_22] = value.m22;
				return (*this);
			}

			void operator =(const matrix3D_type& value) volatile
			{
				data[index_00] = value.m00;
				data[index_10] = value.m10;
				data[index_20] = value.m20;
				data[index_01] = value.m01;
				data[index_11] = value.m11;
				data[index_21] = value.m21;
				data[index_02] = value.m02;
				data[index_12] = value.m12;
				data[index_22] = value.m22;
			}

			Submat3D& operator =(const Submat3D& value)
			{
				data[index_00] = value.data[index_00];
				data[index_10] = value.data[index_10];
				data[index_20] = value.data[index_20];
				data[index_01] = value.data[index_01];
				data[index_11] = value.data[index_11];
				data[index_21] = value.data[index_21];
				data[index_02] = value.data[index_02];
				data[index_12] = value.data[index_12];
				data[index_22] = value.data[index_22];
				return (*this);
			}

			void operator =(const Submat3D& value) volatile
			{
				data[index_00] = value.data[index_00];
				data[index_10] = value.data[index_10];
				data[index_20] = value.data[index_20];
				data[index_01] = value.data[index_01];
				data[index_11] = value.data[index_11];
				data[index_21] = value.data[index_21];
				data[index_02] = value.data[index_02];
				data[index_12] = value.data[index_12];
				data[index_22] = value.data[index_22];
			}

			template <typename type, int cnt, int ind_00, int ind_01, int ind_02, int ind_10, int ind_11, int ind_12, int ind_20, int ind_21, int ind_22>
			Submat3D& operator =(const Submat3D<type, cnt, ind_00, ind_01, ind_02, ind_10, ind_11, ind_12, ind_20, ind_21, ind_22>& value)
			{
				data[index_00] = value.data[ind_00];
				data[index_10] = value.data[ind_10];
				data[index_20] = value.data[ind_20];
				data[index_01] = value.data[ind_01];
				data[index_11] = value.data[ind_11];
				data[index_21] = value.data[ind_21];
				data[index_02] = value.data[ind_02];
				data[index_12] = value.data[ind_12];
				data[index_22] = value.data[ind_22];
				return (*this);
			}

			template <typename type, int cnt, int ind_00, int ind_01, int ind_02, int ind_10, int ind_11, int ind_12, int ind_20, int ind_21, int ind_22>
			void operator =(const Submat3D<type, cnt, ind_00, ind_01, ind_02, ind_10, ind_11, ind_12, ind_20, ind_21, ind_22>& value) volatile
			{
				data[index_00] = value.data[ind_00];
				data[index_10] = value.data[ind_10];
				data[index_20] = value.data[ind_20];
				data[index_01] = value.data[ind_01];
				data[index_11] = value.data[ind_11];
				data[index_21] = value.data[ind_21];
				data[index_02] = value.data[ind_02];
				data[index_12] = value.data[ind_12];
				data[index_22] = value.data[ind_22];
			}

			Submat3D& operator *=(const component_type& s)
			{
				data[index_00] *= s;
				data[index_10] *= s;
				data[index_20] *= s;
				data[index_01] *= s;
				data[index_11] *= s;
				data[index_21] *= s;
				data[index_02] *= s;
				data[index_12] *= s;
				data[index_22] *= s;
				return (*this);
			}

			Submat3D& operator /=(const float& s)
			{
				float t = 1.0F / s;
				data[index_00] *= t;
				data[index_10] *= t;
				data[index_20] *= t;
				data[index_01] *= t;
				data[index_11] *= t;
				data[index_21] *= t;
				data[index_02] *= t;
				data[index_12] *= t;
				data[index_22] *= t;
				return (*this);
			}

			Submat3D& operator /=(const double& s)
			{
				double t = 1.0 / s;
				data[index_00] *= t;
				data[index_10] *= t;
				data[index_20] *= t;
				data[index_01] *= t;
				data[index_11] *= t;
				data[index_21] *= t;
				data[index_02] *= t;
				data[index_12] *= t;
				data[index_22] *= t;
				return (*this);
			}

			template <typename division_type>
			Submat3D& operator /=(const division_type& s)
			{
				data[index_00] /= s;
				data[index_10] /= s;
				data[index_20] /= s;
				data[index_01] /= s;
				data[index_11] /= s;
				data[index_21] /= s;
				data[index_02] /= s;
				data[index_12] /= s;
				data[index_22] /= s;
				return (*this);
			}
	};


	template <typename A_type_struct, int A_count, int A_index_00, int A_index_01, int A_index_02, int A_index_10, int A_index_11, int A_index_12, int A_index_20, int A_index_21, int A_index_22, typename B_type_struct, int B_count, int B_index_00, int B_index_01, int B_index_02, int B_index_10, int B_index_11, int B_index_12, int B_index_20, int B_index_21, int B_index_22>
	inline bool operator ==(const Submat3D<A_type_struct, A_count, A_index_00, A_index_01, A_index_02, A_index_10, A_index_11, A_index_12, A_index_20, A_index_21, A_index_22>& A, const Submat3D<B_type_struct, B_count, B_index_00, B_index_01, B_index_02, B_index_10, B_index_11, B_index_12, B_index_20, B_index_21, B_index_22>& B)
	{
		return ((A.data[A_index_00] == B.data[B_index_00]) && (A.data[A_index_01] == B.data[B_index_01]) && (A.data[A_index_02] == B.data[B_index_02]) && (A.data[A_index_10] == B.data[B_index_10]) && (A.data[A_index_11] == B.data[B_index_11]) && (A.data[A_index_12] == B.data[B_index_12]) && (A.data[A_index_20] == B.data[B_index_20]) && (A.data[A_index_21] == B.data[B_index_21]) && (A.data[A_index_22] == B.data[B_index_22]));
	}

	template <typename A_type_struct, int A_count, int A_index_00, int A_index_01, int A_index_02, int A_index_10, int A_index_11, int A_index_12, int A_index_20, int A_index_21, int A_index_22, typename B_type_struct, int B_count, int B_index_00, int B_index_01, int B_index_02, int B_index_10, int B_index_11, int B_index_12, int B_index_20, int B_index_21, int B_index_22>
	inline bool operator !=(const Submat3D<A_type_struct, A_count, A_index_00, A_index_01, A_index_02, A_index_10, A_index_11, A_index_12, A_index_20, A_index_21, A_index_22>& A, const Submat3D<B_type_struct, B_count, B_index_00, B_index_01, B_index_02, B_index_10, B_index_11, B_index_12, B_index_20, B_index_21, B_index_22>& B)
	{
		return ((A.data[A_index_00] != B.data[B_index_00]) || (A.data[A_index_01] != B.data[B_index_01]) || (A.data[A_index_02] != B.data[B_index_02]) || (A.data[A_index_10] != B.data[B_index_10]) || (A.data[A_index_11] != B.data[B_index_11]) || (A.data[A_index_12] != B.data[B_index_12]) || (A.data[A_index_20] != B.data[B_index_20]) || (A.data[A_index_21] != B.data[B_index_21]) || (A.data[A_index_22] != B.data[B_index_22]));
	}


	template <typename type_struct, int index_00, int index_01, int index_02, int index_03, int index_10, int index_11, int index_12, int index_13, int index_20, int index_21, int index_22, int index_23, int index_30, int index_31, int index_32, int index_33>
	struct ConverterMatrix4D
	{
		typedef typename type_struct::component_type component_type;
		typedef typename type_struct::matrix4D_type matrix4D_type;
		typedef typename type_struct::matrix4D_type const_matrix4D_type;

		static matrix4D_type Convert(component_type *data)
		{
			return (matrix4D_type(data[index_00], data[index_01], data[index_02], data[index_03], data[index_10], data[index_11], data[index_12], data[index_13], data[index_20], data[index_21], data[index_22], data[index_23], data[index_30], data[index_31], data[index_32], data[index_33]));
		}

		static const_matrix4D_type Convert(const component_type *data)
		{
			return (const_matrix4D_type(data[index_00], data[index_01], data[index_02], data[index_03], data[index_10], data[index_11], data[index_12], data[index_13], data[index_20], data[index_21], data[index_22], data[index_23], data[index_30], data[index_31], data[index_32], data[index_33]));
		}
	};

	template <typename type_struct>
	struct ConverterMatrix4D<type_struct, 0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15>
	{
		typedef typename type_struct::component_type component_type;
		typedef typename type_struct::matrix4D_type& matrix4D_type;
		typedef const typename type_struct::matrix4D_type& const_matrix4D_type;

		static matrix4D_type Convert(component_type *data)
		{
			return (reinterpret_cast<matrix4D_type>(data[0]));
		}

		static const_matrix4D_type Convert(const component_type *data)
		{
			return (reinterpret_cast<const_matrix4D_type>(data[0]));
		}
	};


	template <typename type_struct, int count, int index_00, int index_01, int index_02, int index_03, int index_10, int index_11, int index_12, int index_13, int index_20, int index_21, int index_22, int index_23, int index_30, int index_31, int index_32, int index_33>
	class Submat4D
	{
		public:

			typedef typename type_struct::component_type component_type;
			typedef typename type_struct::matrix4D_type matrix4D_type;

			component_type		data[count];

			Submat4D& Set(const component_type& m00, const component_type& m01, const component_type& m02, const component_type& m03, const component_type& m10, const component_type& m11, const component_type& m12, const component_type& m13, const component_type& m20, const component_type& m21, const component_type& m22, const component_type& m23, const component_type& m30, const component_type& m31, const component_type& m32, const component_type& m33)
			{
				data[index_00] = m00;
				data[index_10] = m10;
				data[index_20] = m20;
				data[index_30] = m30;
				data[index_01] = m01;
				data[index_11] = m11;
				data[index_21] = m21;
				data[index_31] = m31;
				data[index_02] = m02;
				data[index_12] = m12;
				data[index_22] = m22;
				data[index_32] = m32;
				data[index_03] = m03;
				data[index_13] = m13;
				data[index_23] = m23;
				data[index_33] = m33;
				return (*this);
			}

			void Set(const component_type& m00, const component_type& m01, const component_type& m02, const component_type& m03, const component_type& m10, const component_type& m11, const component_type& m12, const component_type& m13, const component_type& m20, const component_type& m21, const component_type& m22, const component_type& m23, const component_type& m30, const component_type& m31, const component_type& m32, const component_type& m33) volatile
			{
				data[index_00] = m00;
				data[index_10] = m10;
				data[index_20] = m20;
				data[index_30] = m30;
				data[index_01] = m01;
				data[index_11] = m11;
				data[index_21] = m21;
				data[index_31] = m31;
				data[index_02] = m02;
				data[index_12] = m12;
				data[index_22] = m22;
				data[index_32] = m32;
				data[index_03] = m03;
				data[index_13] = m13;
				data[index_23] = m23;
				data[index_33] = m33;
			}

			operator typename ConverterMatrix4D<type_struct, index_00, index_01, index_02, index_03, index_10, index_11, index_12, index_13, index_20, index_21, index_22, index_23, index_30, index_31, index_32, index_33>::matrix4D_type(void)
			{
				return (ConverterMatrix4D<type_struct, index_00, index_01, index_02, index_03, index_10, index_11, index_12, index_13, index_20, index_21, index_22, index_23, index_30, index_31, index_32, index_33>::Convert(data));
			}

			operator typename ConverterMatrix4D<type_struct, index_00, index_01, index_02, index_03, index_10, index_11, index_12, index_13, index_20, index_21, index_22, index_23, index_30, index_31, index_32, index_33>::const_matrix4D_type(void) const
			{
				return (ConverterMatrix4D<type_struct, index_00, index_01, index_02, index_03, index_10, index_11, index_12, index_13, index_20, index_21, index_22, index_23, index_30, index_31, index_32, index_33>::Convert(data));
			}

			Submat4D& operator =(const matrix4D_type& value)
			{
				data[index_00] = value.m00;
				data[index_10] = value.m10;
				data[index_20] = value.m20;
				data[index_30] = value.m30;
				data[index_01] = value.m01;
				data[index_11] = value.m11;
				data[index_21] = value.m21;
				data[index_31] = value.m31;
				data[index_02] = value.m02;
				data[index_12] = value.m12;
				data[index_22] = value.m22;
				data[index_32] = value.m32;
				data[index_03] = value.m03;
				data[index_13] = value.m13;
				data[index_23] = value.m23;
				data[index_33] = value.m33;
				return (*this);
			}

			void operator =(const matrix4D_type& value) volatile
			{
				data[index_00] = value.m00;
				data[index_10] = value.m10;
				data[index_20] = value.m20;
				data[index_30] = value.m30;
				data[index_01] = value.m01;
				data[index_11] = value.m11;
				data[index_21] = value.m21;
				data[index_31] = value.m31;
				data[index_02] = value.m02;
				data[index_12] = value.m12;
				data[index_22] = value.m22;
				data[index_32] = value.m32;
				data[index_03] = value.m03;
				data[index_13] = value.m13;
				data[index_23] = value.m23;
				data[index_33] = value.m33;
			}

			Submat4D& operator =(const Submat4D& value)
			{
				data[index_00] = value.data[index_00];
				data[index_10] = value.data[index_10];
				data[index_20] = value.data[index_20];
				data[index_30] = value.data[index_30];
				data[index_01] = value.data[index_01];
				data[index_11] = value.data[index_11];
				data[index_21] = value.data[index_21];
				data[index_31] = value.data[index_31];
				data[index_02] = value.data[index_02];
				data[index_12] = value.data[index_12];
				data[index_22] = value.data[index_22];
				data[index_32] = value.data[index_32];
				data[index_03] = value.data[index_03];
				data[index_13] = value.data[index_13];
				data[index_23] = value.data[index_23];
				data[index_33] = value.data[index_33];
				return (*this);
			}

			void operator =(const Submat4D& value) volatile
			{
				data[index_00] = value.data[index_00];
				data[index_10] = value.data[index_10];
				data[index_20] = value.data[index_20];
				data[index_30] = value.data[index_30];
				data[index_01] = value.data[index_01];
				data[index_11] = value.data[index_11];
				data[index_21] = value.data[index_21];
				data[index_31] = value.data[index_31];
				data[index_02] = value.data[index_02];
				data[index_12] = value.data[index_12];
				data[index_22] = value.data[index_22];
				data[index_32] = value.data[index_32];
				data[index_03] = value.data[index_03];
				data[index_13] = value.data[index_13];
				data[index_23] = value.data[index_23];
				data[index_33] = value.data[index_33];
			}

			template <typename type, int cnt, int ind_00, int ind_01, int ind_02, int ind_03, int ind_10, int ind_11, int ind_12, int ind_13, int ind_20, int ind_21, int ind_22, int ind_23, int ind_30, int ind_31, int ind_32, int ind_33>
			Submat4D& operator =(const Submat4D<type, cnt, ind_00, ind_01, ind_02, ind_03, ind_10, ind_11, ind_12, ind_13, ind_20, ind_21, ind_22, ind_23, ind_30, ind_31, ind_32, ind_33>& value)
			{
				data[index_00] = value.data[ind_00];
				data[index_10] = value.data[ind_10];
				data[index_20] = value.data[ind_20];
				data[index_30] = value.data[ind_30];
				data[index_01] = value.data[ind_01];
				data[index_11] = value.data[ind_11];
				data[index_21] = value.data[ind_21];
				data[index_31] = value.data[ind_31];
				data[index_02] = value.data[ind_02];
				data[index_12] = value.data[ind_12];
				data[index_22] = value.data[ind_22];
				data[index_32] = value.data[ind_32];
				data[index_03] = value.data[ind_03];
				data[index_13] = value.data[ind_13];
				data[index_23] = value.data[ind_23];
				data[index_33] = value.data[ind_33];
				return (*this);
			}

			template <typename type, int cnt, int ind_00, int ind_01, int ind_02, int ind_03, int ind_10, int ind_11, int ind_12, int ind_13, int ind_20, int ind_21, int ind_22, int ind_23, int ind_30, int ind_31, int ind_32, int ind_33>
			void operator =(const Submat4D<type, cnt, ind_00, ind_01, ind_02, ind_03, ind_10, ind_11, ind_12, ind_13, ind_20, ind_21, ind_22, ind_23, ind_30, ind_31, ind_32, ind_33>& value) volatile
			{
				data[index_00] = value.data[ind_00];
				data[index_10] = value.data[ind_10];
				data[index_20] = value.data[ind_20];
				data[index_30] = value.data[ind_30];
				data[index_01] = value.data[ind_01];
				data[index_11] = value.data[ind_11];
				data[index_21] = value.data[ind_21];
				data[index_31] = value.data[ind_31];
				data[index_02] = value.data[ind_02];
				data[index_12] = value.data[ind_12];
				data[index_22] = value.data[ind_22];
				data[index_32] = value.data[ind_32];
				data[index_03] = value.data[ind_03];
				data[index_13] = value.data[ind_13];
				data[index_23] = value.data[ind_23];
				data[index_33] = value.data[ind_33];
			}

			Submat4D& operator *=(const component_type& s)
			{
				data[index_00] *= s;
				data[index_10] *= s;
				data[index_20] *= s;
				data[index_30] *= s;
				data[index_01] *= s;
				data[index_11] *= s;
				data[index_21] *= s;
				data[index_31] *= s;
				data[index_02] *= s;
				data[index_12] *= s;
				data[index_22] *= s;
				data[index_32] *= s;
				data[index_03] *= s;
				data[index_13] *= s;
				data[index_23] *= s;
				data[index_33] *= s;
				return (*this);
			}

			Submat4D& operator /=(const float& s)
			{
				float t = 1.0F / s;
				data[index_00] *= t;
				data[index_10] *= t;
				data[index_20] *= t;
				data[index_30] *= t;
				data[index_01] *= t;
				data[index_11] *= t;
				data[index_21] *= t;
				data[index_31] *= t;
				data[index_02] *= t;
				data[index_12] *= t;
				data[index_22] *= t;
				data[index_32] *= t;
				data[index_03] *= t;
				data[index_13] *= t;
				data[index_23] *= t;
				data[index_33] *= t;
				return (*this);
			}

			Submat4D& operator /=(const double& s)
			{
				double t = 1.0 / s;
				data[index_00] *= t;
				data[index_10] *= t;
				data[index_20] *= t;
				data[index_30] *= t;
				data[index_01] *= t;
				data[index_11] *= t;
				data[index_21] *= t;
				data[index_31] *= t;
				data[index_02] *= t;
				data[index_12] *= t;
				data[index_22] *= t;
				data[index_32] *= t;
				data[index_03] *= t;
				data[index_13] *= t;
				data[index_23] *= t;
				data[index_33] *= t;
				return (*this);
			}

			template <typename division_type>
			Submat4D& operator /=(const division_type& s)
			{
				data[index_00] /= s;
				data[index_10] /= s;
				data[index_20] /= s;
				data[index_30] /= s;
				data[index_01] /= s;
				data[index_11] /= s;
				data[index_21] /= s;
				data[index_31] /= s;
				data[index_02] /= s;
				data[index_12] /= s;
				data[index_22] /= s;
				data[index_32] /= s;
				data[index_03] /= s;
				data[index_13] /= s;
				data[index_23] /= s;
				data[index_33] /= s;
				return (*this);
			}
	};


	template <typename A_type_struct, int A_count, int A_index_00, int A_index_01, int A_index_02, int A_index_03, int A_index_10, int A_index_11, int A_index_12, int A_index_13, int A_index_20, int A_index_21, int A_index_22, int A_index_23, int A_index_30, int A_index_31, int A_index_32, int A_index_33, typename B_type_struct, int B_count, int B_index_00, int B_index_01, int B_index_02, int B_index_03, int B_index_10, int B_index_11, int B_index_12, int B_index_13, int B_index_20, int B_index_21, int B_index_22, int B_index_23, int B_index_30, int B_index_31, int B_index_32, int B_index_33>
	inline bool operator ==(const Submat4D<A_type_struct, A_count, A_index_00, A_index_01, A_index_02, A_index_03, A_index_10, A_index_11, A_index_12, A_index_13, A_index_20, A_index_21, A_index_22, A_index_23, A_index_30, A_index_31, A_index_32, A_index_33>& A, const Submat4D<B_type_struct, B_count, B_index_00, B_index_01, B_index_02, B_index_03, B_index_10, B_index_11, B_index_12, B_index_13, B_index_20, B_index_21, B_index_22, B_index_23, B_index_30, B_index_31, B_index_32, B_index_33>& B)
	{
		return ((A.data[A_index_00] == B.data[B_index_00]) && (A.data[A_index_01] == B.data[B_index_01]) && (A.data[A_index_02] == B.data[B_index_02]) && (A.data[A_index_03] == B.data[B_index_03]) && (A.data[A_index_10] == B.data[B_index_10]) && (A.data[A_index_11] == B.data[B_index_11]) && (A.data[A_index_12] == B.data[B_index_12]) && (A.data[A_index_13] == B.data[B_index_13]) && (A.data[A_index_20] == B.data[B_index_20]) && (A.data[A_index_21] == B.data[B_index_21]) && (A.data[A_index_22] == B.data[B_index_22]) && (A.data[A_index_23] == B.data[B_index_23]) && (A.data[A_index_30] == B.data[B_index_30]) && (A.data[A_index_31] == B.data[B_index_31]) && (A.data[A_index_32] == B.data[B_index_32]) && (A.data[A_index_33] == B.data[B_index_33]));
	}

	template <typename A_type_struct, int A_count, int A_index_00, int A_index_01, int A_index_02, int A_index_03, int A_index_10, int A_index_11, int A_index_12, int A_index_13, int A_index_20, int A_index_21, int A_index_22, int A_index_23, int A_index_30, int A_index_31, int A_index_32, int A_index_33, typename B_type_struct, int B_count, int B_index_00, int B_index_01, int B_index_02, int B_index_03, int B_index_10, int B_index_11, int B_index_12, int B_index_13, int B_index_20, int B_index_21, int B_index_22, int B_index_23, int B_index_30, int B_index_31, int B_index_32, int B_index_33>
	inline bool operator !=(const Submat4D<A_type_struct, A_count, A_index_00, A_index_01, A_index_02, A_index_03, A_index_10, A_index_11, A_index_12, A_index_13, A_index_20, A_index_21, A_index_22, A_index_23, A_index_30, A_index_31, A_index_32, A_index_33>& A, const Submat4D<B_type_struct, B_count, B_index_00, B_index_01, B_index_02, B_index_03, B_index_10, B_index_11, B_index_12, B_index_13, B_index_20, B_index_21, B_index_22, B_index_23, B_index_30, B_index_31, B_index_32, B_index_33>& B)
	{
		return ((A.data[A_index_00] != B.data[B_index_00]) || (A.data[A_index_01] != B.data[B_index_01]) || (A.data[A_index_02] != B.data[B_index_02]) || (A.data[A_index_03] != B.data[B_index_03]) || (A.data[A_index_10] != B.data[B_index_10]) || (A.data[A_index_11] != B.data[B_index_11]) || (A.data[A_index_12] != B.data[B_index_12]) || (A.data[A_index_13] != B.data[B_index_13]) || (A.data[A_index_20] != B.data[B_index_20]) || (A.data[A_index_21] != B.data[B_index_21]) || (A.data[A_index_22] != B.data[B_index_22]) || (A.data[A_index_23] != B.data[B_index_23]) || (A.data[A_index_30] != B.data[B_index_30]) || (A.data[A_index_31] != B.data[B_index_31]) || (A.data[A_index_32] != B.data[B_index_32]) || (A.data[A_index_33] != B.data[B_index_33]));
	}


	template <typename type_struct>
	class Mat2D
	{
		public:

			typedef typename type_struct::component_type component_type;
			typedef typename type_struct::column_type_struct column_type_struct;
			typedef typename type_struct::row_type_struct row_type_struct;

			union
			{
				Component<type_struct, 4, 0>				m00;
				Component<type_struct, 4, 1>				m10;
				Component<type_struct, 4, 2>				m01;
				Component<type_struct, 4, 3>				m11;
				Subvec2D<column_type_struct, 4, 0, 1>		col0;
				Subvec2D<column_type_struct, 4, 2, 3>		col1;
				Subvec2D<row_type_struct, 4, 0, 2>			row0;
				Subvec2D<row_type_struct, 4, 1, 3>			row1;
				Submat2D<type_struct, 4, 0, 2, 1, 3>		matrix;
				Submat2D<type_struct, 4, 0, 1, 2, 3>		transpose;
			};

		protected:

			inline Mat2D() = default;

			Mat2D(const Mat2D& m)
			{
				matrix = m.matrix;
			}

			Mat2D(const component_type& n00, const component_type& n01, const component_type& n10, const component_type& n11)
			{
				matrix.Set(n00, n01, n10, n11);
			}

		public:

			component_type& operator ()(machine i, machine j)
			{
				return (matrix.data[j * 2 + i]);
			}

			const component_type& operator ()(machine i, machine j) const
			{
				return (matrix.data[j * 2 + i]);
			}

			typename column_type_struct::vector2D_type& operator [](machine j)
			{
				return (reinterpret_cast<typename column_type_struct::vector2D_type&>(matrix.data[j * 2]));
			}

			const typename column_type_struct::vector2D_type& operator [](machine j) const
			{
				return (reinterpret_cast<const typename column_type_struct::vector2D_type&>(matrix.data[j * 2]));
			}

			Mat2D& operator =(const Mat2D& m)
			{
				matrix = m.matrix;
				return (*this);
			}

			void operator =(const Mat2D& m) volatile
			{
				matrix = m.matrix;
			}

			template <typename type, int cnt, int ind_00, int ind_01, int ind_10, int ind_11>
			Mat2D& operator =(const Submat2D<type, cnt, ind_00, ind_01, ind_10, ind_11>& m)
			{
				matrix = m;
				return (*this);
			}

			template <typename type, int cnt, int ind_00, int ind_01, int ind_10, int ind_11>
			void operator =(const Submat2D<type, cnt, ind_00, ind_01, ind_10, ind_11>& m) volatile
			{
				matrix = m;
			}
	};


	template <typename type_struct>
	inline bool operator ==(const Mat2D<type_struct>& m1, const Mat2D<type_struct>& m2)
	{
		return (m1.matrix == m2.matrix);
	}

	template <typename type_struct>
	inline bool operator !=(const Mat2D<type_struct>& m1, const Mat2D<type_struct>& m2)
	{
		return (m1.matrix != m2.matrix);
	}


	template <typename type_struct>
	class Mat3D
	{
		public:

			typedef typename type_struct::component_type component_type;
			typedef typename type_struct::column_type_struct column_type_struct;
			typedef typename type_struct::row_type_struct row_type_struct;

			union
			{
				Component<type_struct, 9, 0>							m00;
				Component<type_struct, 9, 1>							m10;
				Component<type_struct, 9, 2>							m20;
				Component<type_struct, 9, 3>							m01;
				Component<type_struct, 9, 4>							m11;
				Component<type_struct, 9, 5>							m21;
				Component<type_struct, 9, 6>							m02;
				Component<type_struct, 9, 7>							m12;
				Component<type_struct, 9, 8>							m22;
				Subvec3D<column_type_struct, false, 9, 0, 1, 2>			col0;
				Subvec3D<column_type_struct, false, 9, 3, 4, 5>			col1;
				Subvec3D<column_type_struct, false, 9, 6, 7, 8>			col2;
				Subvec3D<row_type_struct, true, 9, 0, 3, 6>				row0;
				Subvec3D<row_type_struct, true, 9, 1, 4, 7>				row1;
				Subvec3D<row_type_struct, true, 9, 2, 5, 8>				row2;
				Submat2D<type_struct, 9, 0, 3, 1, 4>					matrix2D;
				Submat2D<type_struct, 9, 0, 1, 3, 4>					transpose2D;
				Submat3D<type_struct, 9, 0, 3, 6, 1, 4, 7, 2, 5, 8>		matrix;
				Submat3D<type_struct, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8>		transpose;
			};

		protected:

			inline Mat3D() = default;

			Mat3D(const Mat3D& m)
			{
				matrix = m.matrix;
			}

			Mat3D(const component_type& n00, const component_type& n01, const component_type& n02, const component_type& n10, const component_type& n11, const component_type& n12, const component_type& n20, const component_type& n21, const component_type& n22)
			{
				matrix.Set(n00, n01, n02, n10, n11, n12, n20, n21, n22);
			}

		public:

			component_type& operator ()(machine i, machine j)
			{
				return (matrix.data[j * 3 + i]);
			}

			const component_type& operator ()(machine i, machine j) const
			{
				return (matrix.data[j * 3 + i]);
			}

			typename column_type_struct::vector3D_type& operator [](machine j)
			{
				return (reinterpret_cast<typename column_type_struct::vector3D_type&>(matrix.data[j * 3]));
			}

			const typename column_type_struct::vector3D_type& operator [](machine j) const
			{
				return (reinterpret_cast<const typename column_type_struct::vector3D_type&>(matrix.data[j * 3]));
			}

			Mat3D& operator =(const Mat3D& m)
			{
				matrix = m.matrix;
				return (*this);
			}

			void operator =(const Mat3D& m) volatile
			{
				matrix = m.matrix;
			}

			template <typename type, int cnt, int ind_00, int ind_01, int ind_02, int ind_10, int ind_11, int ind_12, int ind_20, int ind_21, int ind_22>
			Mat3D& operator =(const Submat3D<type, cnt, ind_00, ind_01, ind_02, ind_10, ind_11, ind_12, ind_20, ind_21, ind_22>& m)
			{
				matrix = m;
				return (*this);
			}

			template <typename type, int cnt, int ind_00, int ind_01, int ind_02, int ind_10, int ind_11, int ind_12, int ind_20, int ind_21, int ind_22>
			void operator =(const Submat3D<type, cnt, ind_00, ind_01, ind_02, ind_10, ind_11, ind_12, ind_20, ind_21, ind_22>& m) volatile
			{
				matrix = m;
			}
	};


	template <typename type_struct>
	inline bool operator ==(const Mat3D<type_struct>& m1, const Mat3D<type_struct>& m2)
	{
		return (m1.matrix == m2.matrix);
	}

	template <typename type_struct>
	inline bool operator !=(const Mat3D<type_struct>& m1, const Mat3D<type_struct>& m2)
	{
		return (m1.matrix != m2.matrix);
	}


	template <typename type_struct>
	class Mat4D
	{
		public:

			typedef typename type_struct::component_type component_type;
			typedef typename type_struct::column_type_struct column_type_struct;
			typedef typename type_struct::row_type_struct row_type_struct;

			union
			{
				alignas(16) Component<type_struct, 16, 0>														m00;
				alignas(16) Component<type_struct, 16, 1>														m10;
				alignas(16) Component<type_struct, 16, 2>														m20;
				alignas(16) Component<type_struct, 16, 3>														m30;
				alignas(16) Component<type_struct, 16, 4>														m01;
				alignas(16) Component<type_struct, 16, 5>														m11;
				alignas(16) Component<type_struct, 16, 6>														m21;
				alignas(16) Component<type_struct, 16, 7>														m31;
				alignas(16) Component<type_struct, 16, 8>														m02;
				alignas(16) Component<type_struct, 16, 9>														m12;
				alignas(16) Component<type_struct, 16, 10>														m22;
				alignas(16) Component<type_struct, 16, 11>														m32;
				alignas(16) Component<type_struct, 16, 12>														m03;
				alignas(16) Component<type_struct, 16, 13>														m13;
				alignas(16) Component<type_struct, 16, 14>														m23;
				alignas(16) Component<type_struct, 16, 15>														m33;
				alignas(16) Subvec4D<column_type_struct, false, 16, 0, 1, 2, 3>									col0;
				alignas(16) Subvec4D<column_type_struct, false, 16, 4, 5, 6, 7>									col1;
				alignas(16) Subvec4D<column_type_struct, false, 16, 8, 9, 10, 11>								col2;
				alignas(16) Subvec4D<column_type_struct, false, 16, 12, 13, 14, 15>								col3;
				alignas(16) Subvec4D<row_type_struct, true, 16, 0, 4, 8, 12>									row0;
				alignas(16) Subvec4D<row_type_struct, true, 16, 1, 5, 9, 13>									row1;
				alignas(16) Subvec4D<row_type_struct, true, 16, 2, 6, 10, 14>									row2;
				alignas(16) Subvec4D<row_type_struct, true, 16, 3, 7, 11, 15>									row3;
				alignas(16) Submat2D<type_struct, 16, 0, 4, 1, 5>												matrix2D;
				alignas(16) Submat2D<type_struct, 16, 0, 1, 4, 5>												transpose2D;
				alignas(16) Submat3D<type_struct, 16, 0, 4, 8, 1, 5, 9, 2, 6, 10>								matrix3D;
				alignas(16) Submat3D<type_struct, 16, 0, 1, 2, 4, 5, 6, 8, 9, 10>								transpose3D;
				alignas(16) Submat4D<type_struct, 16, 0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15>		matrix;
				alignas(16) Submat4D<type_struct, 16, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15>		transpose;
			};

		protected:

			inline Mat4D() = default;

			Mat4D(const Mat4D& m)
			{
				matrix = m.matrix;
			}

			Mat4D(const component_type& n00, const component_type& n01, const component_type& n02, const component_type& n03, const component_type& n10, const component_type& n11, const component_type& n12, const component_type& n13, const component_type& n20, const component_type& n21, const component_type& n22, const component_type& n23, const component_type& n30, const component_type& n31, const component_type& n32, const component_type& n33)
			{
				matrix.Set(n00, n01, n02, n03, n10, n11, n12, n13, n20, n21, n22, n23, n30, n31, n32, n33);
			}

		public:

			component_type& operator ()(machine i, machine j)
			{
				return (matrix.data[j * 4 + i]);
			}

			const component_type& operator ()(machine i, machine j) const
			{
				return (matrix.data[j * 4 + i]);
			}

			typename column_type_struct::vector4D_type& operator [](machine j)
			{
				return (reinterpret_cast<typename column_type_struct::vector4D_type&>(matrix.data[j * 4]));
			}

			const typename column_type_struct::vector4D_type& operator [](machine j) const
			{
				return (reinterpret_cast<const typename column_type_struct::vector4D_type&>(matrix.data[j * 4]));
			}

			Mat4D& operator =(const Mat4D& m)
			{
				#ifndef TERATHON_NO_SIMD

					VecStore(VecLoad(&m.matrix.data[0]), &matrix.data[0]);
					VecStore(VecLoad(&m.matrix.data[4]), &matrix.data[4]);
					VecStore(VecLoad(&m.matrix.data[8]), &matrix.data[8]);
					VecStore(VecLoad(&m.matrix.data[12]), &matrix.data[12]);

				#else

					matrix = m.matrix;

				#endif

				return (*this);
			}

			void operator =(const Mat4D& m) volatile
			{
				matrix = m.matrix;
			}

			template <typename type, int cnt, int ind_00, int ind_01, int ind_02, int ind_03, int ind_10, int ind_11, int ind_12, int ind_13, int ind_20, int ind_21, int ind_22, int ind_23, int ind_30, int ind_31, int ind_32, int ind_33>
			Mat4D& operator =(const Submat4D<type, cnt, ind_00, ind_01, ind_02, ind_03, ind_10, ind_11, ind_12, ind_13, ind_20, ind_21, ind_22, ind_23, ind_30, ind_31, ind_32, ind_33>& m)
			{
				matrix = m;
				return (*this);
			}

			template <typename type, int cnt, int ind_00, int ind_01, int ind_02, int ind_03, int ind_10, int ind_11, int ind_12, int ind_13, int ind_20, int ind_21, int ind_22, int ind_23, int ind_30, int ind_31, int ind_32, int ind_33>
			void operator =(const Submat4D<type, cnt, ind_00, ind_01, ind_02, ind_03, ind_10, ind_11, ind_12, ind_13, ind_20, ind_21, ind_22, ind_23, ind_30, ind_31, ind_32, ind_33>& m) volatile
			{
				matrix = m;
			}
	};


	template <typename type_struct>
	inline bool operator ==(const Mat4D<type_struct>& m1, const Mat4D<type_struct>& m2)
	{
		return (m1.matrix == m2.matrix);
	}

	template <typename type_struct>
	inline bool operator !=(const Mat4D<type_struct>& m1, const Mat4D<type_struct>& m2)
	{
		return (m1.matrix != m2.matrix);
	}


	template <typename m_type_struct, int m_count, int m_index_00, int m_index_01, int m_index_10, int m_index_11,
			  typename v_type_struct, int v_count, int v_index_x, int v_index_y>
	inline typename v_type_struct::vector2D_type operator *(const Submat2D<m_type_struct, m_count, m_index_00, m_index_01, m_index_10, m_index_11>& m,
															const Subvec2D<v_type_struct, v_count, v_index_x, v_index_y>& v)
	{
		return (typename v_type_struct::vector2D_type(m.data[m_index_00] * v.data[v_index_x] + m.data[m_index_01] * v.data[v_index_y],
													  m.data[m_index_10] * v.data[v_index_x] + m.data[m_index_11] * v.data[v_index_y]));
	}

	template <typename v_type_struct, int v_count, int v_index_x, int v_index_y,
			  typename m_type_struct, int m_count, int m_index_00, int m_index_01, int m_index_10, int m_index_11>
	inline typename v_type_struct::vector2D_type operator *(const Subvec2D<v_type_struct, v_count, v_index_x, v_index_y>& v,
															const Submat2D<m_type_struct, m_count, m_index_00, m_index_01, m_index_10, m_index_11>& m)
	{
		return (typename v_type_struct::vector2D_type(m.data[m_index_00] * v.data[v_index_x] + m.data[m_index_10] * v.data[v_index_y],
													  m.data[m_index_01] * v.data[v_index_x] + m.data[m_index_11] * v.data[v_index_y]));
	}

	template <typename A_type_struct, int A_count, int A_index_00, int A_index_01, int A_index_10, int A_index_11,
			  typename B_type_struct, int B_count, int B_index_00, int B_index_01, int B_index_10, int B_index_11>
	TERATHON_API typename A_type_struct::matrix2D_type operator *(const Submat2D<A_type_struct, A_count, A_index_00, A_index_01, A_index_10, A_index_11>& A,
													 const Submat2D<B_type_struct, B_count, B_index_00, B_index_01, B_index_10, B_index_11>& B);


	template <typename m_type_struct, int m_count, int m_index_00, int m_index_01, int m_index_02, int m_index_10, int m_index_11, int m_index_12, int m_index_20, int m_index_21, int m_index_22,
			  typename v_type_struct, int v_count, int v_index_x, int v_index_y, int v_index_z>
	inline typename v_type_struct::vector3D_type operator *(const Submat3D<m_type_struct, m_count, m_index_00, m_index_01, m_index_02, m_index_10, m_index_11, m_index_12, m_index_20, m_index_21, m_index_22>& m,
															const Subvec3D<v_type_struct, false, v_count, v_index_x, v_index_y, v_index_z>& v)
	{
		return (typename v_type_struct::vector3D_type(m.data[m_index_00] * v.data[v_index_x] + m.data[m_index_01] * v.data[v_index_y] + m.data[m_index_02] * v.data[v_index_z],
													  m.data[m_index_10] * v.data[v_index_x] + m.data[m_index_11] * v.data[v_index_y] + m.data[m_index_12] * v.data[v_index_z],
													  m.data[m_index_20] * v.data[v_index_x] + m.data[m_index_21] * v.data[v_index_y] + m.data[m_index_22] * v.data[v_index_z]));
	}

	template <typename v_type_struct, int v_count, int v_index_x, int v_index_y, int v_index_z,
			  typename m_type_struct, int m_count, int m_index_00, int m_index_01, int m_index_02, int m_index_10, int m_index_11, int m_index_12, int m_index_20, int m_index_21, int m_index_22>
	inline typename v_type_struct::vector3D_type operator *(const Subvec3D<v_type_struct, true, v_count, v_index_x, v_index_y, v_index_z>& v,
															const Submat3D<m_type_struct, m_count, m_index_00, m_index_01, m_index_02, m_index_10, m_index_11, m_index_12, m_index_20, m_index_21, m_index_22>& m)
	{
		return (typename v_type_struct::vector3D_type(m.data[m_index_00] * v.data[v_index_x] + m.data[m_index_10] * v.data[v_index_y] + m.data[m_index_20] * v.data[v_index_z],
													  m.data[m_index_01] * v.data[v_index_x] + m.data[m_index_11] * v.data[v_index_y] + m.data[m_index_21] * v.data[v_index_z],
													  m.data[m_index_02] * v.data[v_index_x] + m.data[m_index_12] * v.data[v_index_y] + m.data[m_index_22] * v.data[v_index_z]));
	}

	template <typename A_type_struct, int A_count, int A_index_00, int A_index_01, int A_index_02, int A_index_10, int A_index_11, int A_index_12, int A_index_20, int A_index_21, int A_index_22,
			  typename B_type_struct, int B_count, int B_index_00, int B_index_01, int B_index_02, int B_index_10, int B_index_11, int B_index_12, int B_index_20, int B_index_21, int B_index_22>
	TERATHON_API typename A_type_struct::matrix3D_type operator *(const Submat3D<A_type_struct, A_count, A_index_00, A_index_01, A_index_02, A_index_10, A_index_11, A_index_12, A_index_20, A_index_21, A_index_22>& A,
													 const Submat3D<B_type_struct, B_count, B_index_00, B_index_01, B_index_02, B_index_10, B_index_11, B_index_12, B_index_20, B_index_21, B_index_22>& B);


	template <typename m_type_struct, int m_count, int m_index_00, int m_index_01, int m_index_02, int m_index_03, int m_index_10, int m_index_11, int m_index_12, int m_index_13, int m_index_20, int m_index_21, int m_index_22, int m_index_23, int m_index_30, int m_index_31, int m_index_32, int m_index_33,
			  typename v_type_struct, int v_count, int v_index_x, int v_index_y, int v_index_z, int v_index_w>
	inline typename v_type_struct::vector4D_type operator *(const Submat4D<m_type_struct, m_count, m_index_00, m_index_01, m_index_02, m_index_03, m_index_10, m_index_11, m_index_12, m_index_13, m_index_20, m_index_21, m_index_22, m_index_23, m_index_30, m_index_31, m_index_32, m_index_33>& m,
															const Subvec4D<v_type_struct, false, v_count, v_index_x, v_index_y, v_index_z, v_index_w>& v)
	{
		return (typename v_type_struct::vector4D_type(m.data[m_index_00] * v.data[v_index_x] + m.data[m_index_01] * v.data[v_index_y] + m.data[m_index_02] * v.data[v_index_z] + m.data[m_index_03] * v.data[v_index_w],
													  m.data[m_index_10] * v.data[v_index_x] + m.data[m_index_11] * v.data[v_index_y] + m.data[m_index_12] * v.data[v_index_z] + m.data[m_index_13] * v.data[v_index_w],
													  m.data[m_index_20] * v.data[v_index_x] + m.data[m_index_21] * v.data[v_index_y] + m.data[m_index_22] * v.data[v_index_z] + m.data[m_index_23] * v.data[v_index_w],
													  m.data[m_index_30] * v.data[v_index_x] + m.data[m_index_31] * v.data[v_index_y] + m.data[m_index_32] * v.data[v_index_z] + m.data[m_index_33] * v.data[v_index_w]));
	}

	template <typename v_type_struct, int v_count, int v_index_x, int v_index_y, int v_index_z, int v_index_w,
			  typename m_type_struct, int m_count, int m_index_00, int m_index_01, int m_index_02, int m_index_03, int m_index_10, int m_index_11, int m_index_12, int m_index_13, int m_index_20, int m_index_21, int m_index_22, int m_index_23, int m_index_30, int m_index_31, int m_index_32, int m_index_33>
	inline typename v_type_struct::vector4D_type operator *(const Subvec4D<v_type_struct, true, v_count, v_index_x, v_index_y, v_index_z, v_index_w>& v,
															const Submat4D<m_type_struct, m_count, m_index_00, m_index_01, m_index_02, m_index_03, m_index_10, m_index_11, m_index_12, m_index_13, m_index_20, m_index_21, m_index_22, m_index_23, m_index_30, m_index_31, m_index_32, m_index_33>& m)
	{
		return (typename v_type_struct::vector4D_type(m.data[m_index_00] * v.data[v_index_x] + m.data[m_index_10] * v.data[v_index_y] + m.data[m_index_20] * v.data[v_index_z] + m.data[m_index_30] * v.data[v_index_w],
													  m.data[m_index_01] * v.data[v_index_x] + m.data[m_index_11] * v.data[v_index_y] + m.data[m_index_21] * v.data[v_index_z] + m.data[m_index_31] * v.data[v_index_w],
													  m.data[m_index_02] * v.data[v_index_x] + m.data[m_index_12] * v.data[v_index_y] + m.data[m_index_22] * v.data[v_index_z] + m.data[m_index_32] * v.data[v_index_w],
													  m.data[m_index_03] * v.data[v_index_x] + m.data[m_index_13] * v.data[v_index_y] + m.data[m_index_23] * v.data[v_index_z] + m.data[m_index_33] * v.data[v_index_w]));
	}

	template <typename A_type_struct, int A_count, int A_index_00, int A_index_01, int A_index_02, int A_index_03, int A_index_10, int A_index_11, int A_index_12, int A_index_13, int A_index_20, int A_index_21, int A_index_22, int A_index_23, int A_index_30, int A_index_31, int A_index_32, int A_index_33,
			  typename B_type_struct, int B_count, int B_index_00, int B_index_01, int B_index_02, int B_index_03, int B_index_10, int B_index_11, int B_index_12, int B_index_13, int B_index_20, int B_index_21, int B_index_22, int B_index_23, int B_index_30, int B_index_31, int B_index_32, int B_index_33>
	TERATHON_API typename A_type_struct::matrix4D_type operator *(const Submat4D<A_type_struct, A_count, A_index_00, A_index_01, A_index_02, A_index_03, A_index_10, A_index_11, A_index_12, A_index_13, A_index_20, A_index_21, A_index_22, A_index_23, A_index_30, A_index_31, A_index_32, A_index_33>& A,
													 const Submat4D<B_type_struct, B_count, B_index_00, B_index_01, B_index_02, B_index_03, B_index_10, B_index_11, B_index_12, B_index_13, B_index_20, B_index_21, B_index_22, B_index_23, B_index_30, B_index_31, B_index_32, B_index_33>& B);
}


#endif
