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

#ifndef MIRTK_BoundaryToSquareMapper_H
#define MIRTK_BoundaryToSquareMapper_H

#include "mirtk/BoundarySegmentMapper.h"


namespace mirtk {


/**
 * Map surface boundary to a square
 */
class BoundaryToSquareMapper : public BoundarySegmentMapper
{
  mirtkObjectMacro(BoundaryToSquareMapper);

  // ---------------------------------------------------------------------------
  // Attributes

  /// Length of each side
  mirtkPublicAttributeMacro(double, SideLength);

  /// Copy attributes of this class from another instance
  void CopyAttributes(const BoundaryToSquareMapper &);

  // ---------------------------------------------------------------------------
  // Construction/Destruction

public:

  /// Default constructor
  BoundaryToSquareMapper();

  /// Copy constructor
  BoundaryToSquareMapper(const BoundaryToSquareMapper &);

  /// Assignment operator
  BoundaryToSquareMapper &operator =(const BoundaryToSquareMapper &);

  /// Destructor
  virtual ~BoundaryToSquareMapper();

  /// Create new copy of this instance
  virtual BoundaryMapper *NewCopy() const;

  // ---------------------------------------------------------------------------
  // Execution

  /// Initialize filter after input and parameters are set
  virtual void Initialize();

protected:

  /// Map boundary segment
  ///
  /// \param[in] n         Index of boundary segment.
  /// \param[in] indices   Indices of boundary points forming a closed line strip
  ///                      that discretizes the current surface boundary segment.
  /// \param[in] tvalues   Curve parameter in [0, 1) for each boundary segment point,
  ///                      where the first point has value t=0 and the parameter value
  ///                      for consecutive points is proportional to the distance of
  ///                      the point from the first point along the boundary curve.
  /// \param[in] selection Indices in \p i and \p t arrays corresponding to
  ///                      selected boundary points.
  virtual void MapBoundarySegment(int n, const Array<int>    &indices,
                                         const Array<double> &tvalues,
                                         const Array<int>    &selection);

};


} // namespace mirtk

#endif // MIRTK_BoundaryToSquareMapper_H
