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


#include "TSBivector3D.h"


using namespace Terathon;


const ConstBivector3D Bivector3D::yz_unit = {1.0F, 0.0F, 0.0F};
const ConstBivector3D Bivector3D::zx_unit = {0.0F, 1.0F, 0.0F};
const ConstBivector3D Bivector3D::xy_unit = {0.0F, 0.0F, 1.0F};

const ConstBivector3D Bivector3D::minus_yz_unit = {-1.0F, 0.0F, 0.0F};
const ConstBivector3D Bivector3D::minus_zx_unit = {0.0F, -1.0F, 0.0F};
const ConstBivector3D Bivector3D::minus_xy_unit = {0.0F, 0.0F, -1.0F};


ConstBivector3D Bizero3DType::zero = {0.0F, 0.0F, 0.0F};

const Bizero3DType Terathon::Bizero3D = {};
