//
// This file is part of the Terathon Math Library, by Eric Lengyel.
// Copyright 1999-2022, Terathon Software LLC
//
// This software is distributed under the MIT License.
// Separate proprietary licenses are available from Terathon Software.
//


#include "TSBivector3D.h"


using namespace Terathon;


const ConstBivector3D Bivector3D::zero = {0.0F, 0.0F, 0.0F};

const ConstBivector3D Bivector3D::yz_unit = {1.0F, 0.0F, 0.0F};
const ConstBivector3D Bivector3D::zx_unit = {0.0F, 1.0F, 0.0F};
const ConstBivector3D Bivector3D::xy_unit = {0.0F, 0.0F, 1.0F};

const ConstBivector3D Bivector3D::minus_yz_unit = {-1.0F, 0.0F, 0.0F};
const ConstBivector3D Bivector3D::minus_zx_unit = {0.0F, -1.0F, 0.0F};
const ConstBivector3D Bivector3D::minus_xy_unit = {0.0F, 0.0F, -1.0F};
