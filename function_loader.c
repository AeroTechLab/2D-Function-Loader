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


#include "curve_loader.h"

#include "data_io/interface/data_io.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Curve Curve_Load( const char* curveFilePath )
{
  if( curveFilePath == NULL ) return NULL;
  
  DataHandle curveData = DataIO_LoadFileData( curveFilePath );
  if( curveData == NULL ) return NULL;
  
  Curve newCurve = Curve_Create();
  
  Curve_SetScale( newCurve, DataIO_GetNumericValue( curveData, 1.0, "scale_factor" ) );
  Curve_SetMaxAmplitude( newCurve, DataIO_GetNumericValue( curveData, -1.0, "max_amplitude" ) );

  size_t segmentsNumber = DataIO_GetListSize( curveData, "segments" );

  for( size_t segmentIndex = 0; segmentIndex < segmentsNumber; segmentIndex++ )
  {
    double curveBounds[ 2 ];
    curveBounds[ 0 ] = DataIO_GetNumericValue( curveData, 0.0, "segments.%lu.bounds.0", segmentIndex );
    curveBounds[ 1 ] = DataIO_GetNumericValue( curveData, 1.0, "segments.%lu.bounds.1", segmentIndex );

    int parametersNumber = (int) DataIO_GetListSize( curveData, "segments.%lu.parameters", segmentIndex );

    double* curveParameters = (double*) calloc( parametersNumber, sizeof(double) );
    for( int parameterIndex = 0; parameterIndex < parametersNumber; parameterIndex++ )
      curveParameters[ parametersNumber - parameterIndex - 1 ] = DataIO_GetNumericValue( curveData, 0.0, "segments.%lu.parameters.%d", segmentIndex, parameterIndex );

    const char* curveType = DataIO_GetStringValue( curveData, "", "segments.%lu.type", segmentIndex );
    if( strcmp( curveType, "cubic_spline" ) == 0 && parametersNumber == SPLINE3_COEFFS_NUMBER ) 
      Curve_AddSpline3Segment( newCurve, curveParameters, curveBounds );
    else if( strcmp( curveType, "polynomial" ) == 0 ) 
      Curve_AddPolySegment( newCurve, curveParameters, parametersNumber, curveBounds );

    free( curveParameters );
  }
  
  return newCurve;
}
