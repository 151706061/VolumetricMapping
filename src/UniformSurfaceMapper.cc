/*
 * Medical Image Registration ToolKit (MIRTK)
 *
 * Copyright 2016 Imperial College London
 * Copyright 2016 Andreas Schuh
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mirtk/UniformSurfaceMapper.h"

namespace mirtk {


// =============================================================================
// Construction/destruction
// =============================================================================

// -----------------------------------------------------------------------------
void UniformSurfaceMapper::CopyAttributes(const UniformSurfaceMapper &other)
{
}

// -----------------------------------------------------------------------------
UniformSurfaceMapper::UniformSurfaceMapper()
{
}

// -----------------------------------------------------------------------------
UniformSurfaceMapper::UniformSurfaceMapper(const UniformSurfaceMapper &other)
:
  SymmetricLinearSurfaceMapper(other)
{
  CopyAttributes(other);
}

// -----------------------------------------------------------------------------
UniformSurfaceMapper &UniformSurfaceMapper::operator =(const UniformSurfaceMapper &other)
{
  if (this != &other) {
    SymmetricLinearSurfaceMapper::operator =(other);
    CopyAttributes(other);
  }
  return *this;
}

// -----------------------------------------------------------------------------
UniformSurfaceMapper::~UniformSurfaceMapper()
{
}

// =============================================================================
// Execution
// =============================================================================

// -----------------------------------------------------------------------------
double UniformSurfaceMapper::Weight(int, int) const
{
  return 1.0;
}


} // namespace mirtk