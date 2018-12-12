//////////////////////////////////////////////////////////////////////////////////////
//                                                                                  //
//  Copyright (c) 2016-2018 Leonardo Consoni <consoni_2519@hotmail.com>             //
//                                                                                  //
//  This file is part of Function Curves Loader.                                    //
//                                                                                  //
//  Function Curves Loader is free software: you can redistribute it and/or modify  //
//  it under the terms of the GNU Lesser General Public License as published        //
//  by the Free Software Foundation, either version 3 of the License, or            //
//  (at your option) any later version.                                             //
//                                                                                  //
//  Function Curves Loader is distributed in the hope that it will be useful,       //
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                  //
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                    //
//  GNU Lesser General Public License for more details.                             //
//                                                                                  //
//  You should have received a copy of the GNU Lesser General Public License        //
//  along with Function Curves Loader. If not, see <http://www.gnu.org/licenses/>.  //
//                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////


/// @file curve_loader.h
/// @brief Curve description parsing function
///
/// Method for generating a data structure for [Function Curves]() interface from a text format description file, according to @ref curve_description

/// @page curve_description Curve Description
/// The multi-segment curve description (see @ref configuration_levels) is read using the [data I/O interface](https://bitiquinho.github.io/Platform-Utils/structDataIO.html).
///
///
/// The possible variable fields and their values are here exemplified for the case of a JSON format description:
/// @code
/// {                                           
///   "segments": [                                               // List of segments that compose the entire curve
///     { 
///       "type": "polynomial",                                   // Segment defined by a polynomial expression
///       "bounds": [ -0.5, -0.0032 ],                            // Limits of segment function domain
///       "parameters": [ -652.05, -0.3701 ]                      // Polynom coefficients (from bigger to lower order)
///     },
///     { 
///       "type": "cubic_spline",                                 // Segment defined by cubic (4 coefficients) spline points
///       "bounds": [ -0.0032, 0.0032 ],                          // Limits of segment function domain
///       "parameters": [ 1.7165, -652.05, -1.5608, -671.77 ]     // Function value and derivative (respectively) on each spline bound
///     }
///   ],
///   "scale_factor": 1.0                                         // [Optional] Multiply curve value by a factor
/// }
/// @endcode


#ifndef CURVE_LOADER_H
#define CURVE_LOADER_H


#include "curves/curves.h"


/// @brief Load function curve from text format description file
/// @param[in] curveFilePath path (without extension) to file containing curve description
/// @return reference to loaded curve data structure (NULL on errors)
Curve Curve_Load( const char* curveFilePath );


#endif // CURVE_LOADER_H
