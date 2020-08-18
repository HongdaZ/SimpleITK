/*=========================================================================
*
*  Copyright Insight Software Consortium
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*         http://www.apache.org/licenses/LICENSE-2.0.txt
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*
*=========================================================================*/
#ifndef sitkCenteredTransformInitializerFilter_h
#define sitkCenteredTransformInitializerFilter_h

/*
 * WARNING: DO NOT EDIT THIS FILE!
 * THIS FILE IS AUTOMATICALLY GENERATED BY THE SIMPLEITK BUILD PROCESS.
 * Please look at sitkImageFilterTemplate.h.in to make changes.
 */

#include <memory>

#include "sitkBasicFilters.h"
#include "sitkProcessObject.h"
#include "sitkMemberFunctionFactory.h"

namespace itk {
  namespace simple {

    /**\class  CenteredTransformInitializerFilter
\brief  CenteredTransformInitializerFilter is a helper class intended to initialize the center of rotation and the translation of Transforms having the center of rotation among their parameters.

This class is connected to the fixed image, moving image and transform involved in the registration. Two modes of operation are possible:


\li Geometrical,

\li Center of mass

In the first mode, the geometrical center of the moving image is
passed as initial center of rotation to the transform and the vector
from the center of the fixed image to the center of the moving image
is passed as the initial translation. This mode basically assumes that
the anatomical objects to be registered are centered in their
respective images. Hence the best initial guess for the registration
is the one that superimposes those two centers.

In the second mode, the moments of gray level values are computed for
both images. The center of mass of the moving image is then used as
center of rotation. The vector between the two centers of mass is
passes as the initial translation to the transform. This second
approach assumes that the moments of the anatomical objects are
similar for both images and hence the best initial guess for
registration is to superimpose both mass centers. Note that this
assumption will probably not hold in multi-modality registration.

\sa itk::CenteredTransformInitializer
     */
    class SITKBasicFilters_EXPORT  CenteredTransformInitializerFilter : public ProcessObject {
    public:
      typedef  CenteredTransformInitializerFilter Self;

      /** Destructor */
      virtual ~CenteredTransformInitializerFilter();

      /** Default Constructor that takes no arguments and initializes
       * default parameters */
       CenteredTransformInitializerFilter();

      /** Define the pixels types supported by this filter */
      typedef BasicPixelIDTypeList  PixelIDTypeList;


      typedef enum {GEOMETRY,MOMENTS} OperationModeType;

      /**
       */
      SITK_RETURN_SELF_TYPE_HEADER SetOperationMode ( OperationModeType OperationMode ) { this->m_OperationMode = OperationMode; return *this; }

      /**
       */
        OperationModeType GetOperationMode() const { return this->m_OperationMode; }
      /** Name of this class */
      std::string GetName() const { return std::string ("CenteredTransformInitializerFilter"); }

      /** Print ourselves out */
      std::string ToString() const;


      /** Execute the filter on the input image */
      Transform Execute ( const Image & fixedImage, const Image & movingImage, const Transform & transform );


      /** Execute the filter on the input image with the given parameters */
      Transform Execute ( const Image & fixedImage, const Image & movingImage, const Transform & transform,  CenteredTransformInitializerFilter::OperationModeType operationMode );


      /** Select between using the geometrical center of the images or using the center of mass given by the image intensities. */
      SITK_RETURN_SELF_TYPE_HEADER MomentsOn( ) { this->SetOperationMode( MOMENTS ); return *this; }

      /** Select between using the geometrical center of the images or using the center of mass given by the image intensities. */
      SITK_RETURN_SELF_TYPE_HEADER GeometryOn( ) { this->SetOperationMode( GEOMETRY ); return *this; }


    private:

      /** Setup for member function dispatching */

      typedef Transform (Self::*MemberFunctionType)( const Image * fixedImage, const Image * movingImage, const itk::simple::Transform * transform );
      template <class TImageType> Transform ExecuteInternal ( const Image * fixedImage, const Image * movingImage, const itk::simple::Transform * transform );


      friend struct detail::MemberFunctionAddressor<MemberFunctionType>;

      nsstd::auto_ptr<detail::MemberFunctionFactory<MemberFunctionType> > m_MemberFactory;


      OperationModeType  m_OperationMode;
    };

    /**
     * \brief CenteredTransformInitializer is a helper class intended to initialize the center of rotation and the translation of Transforms having the center of rotation among their parameters.
     *
     * This function directly calls the execute method of CenteredTransformInitializerFilter
     * in order to support a procedural API
     *
     * \sa itk::simple::CenteredTransformInitializerFilter for the object oriented interface
     */
     SITKBasicFilters_EXPORT Transform CenteredTransformInitializer ( const Image & fixedImage,
                                                                      const Image & movingImage,
                                                                      const Transform & transform,
                                                                      CenteredTransformInitializerFilter::OperationModeType operationMode = itk::simple::CenteredTransformInitializerFilter::MOMENTS );

  }
}
#endif
