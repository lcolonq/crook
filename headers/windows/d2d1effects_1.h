/*** Autogenerated by WIDL 10.0 from /build/wine-10.0/include/d2d1effects_1.idl - Do not edit ***/

#ifdef _WIN32
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif
#include <rpc.h>
#include <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __d2d1effects_1_h__
#define __d2d1effects_1_h__

/* Forward declarations */

/* Headers for imported files */

#include <d2d1effects.h>

#ifdef __cplusplus
extern "C" {
#endif

DEFINE_GUID(CLSID_D2D1YCbCr, 0x99503cc1,0x66c7,0x45c9,0xa8,0x75,0x8a,0xd8,0xa7,0x91,0x44,0x01);
typedef enum D2D1_YCBCR_PROP {
    D2D1_YCBCR_PROP_CHROMA_SUBSAMPLING = 0x0,
    D2D1_YCBCR_PROP_TRANSFORM_MATRIX = 0x1,
    D2D1_YCBCR_PROP_INTERPOLATION_MODE = 0x2,
    D2D1_YCBCR_PROP_FORCE_DWORD = 0xffffffff
} D2D1_YCBCR_PROP;
typedef enum D2D1_YCBCR_CHROMA_SUBSAMPLING {
    D2D1_YCBCR_CHROMA_SUBSAMPLING_AUTO = 0x0,
    D2D1_YCBCR_CHROMA_SUBSAMPLING_420 = 0x1,
    D2D1_YCBCR_CHROMA_SUBSAMPLING_422 = 0x2,
    D2D1_YCBCR_CHROMA_SUBSAMPLING_444 = 0x3,
    D2D1_YCBCR_CHROMA_SUBSAMPLING_440 = 0x4,
    D2D1_YCBCR_CHROMA_SUBSAMPLING_FORCE_DWORD = 0xffffffff
} D2D1_YCBCR_CHROMA_SUBSAMPLING;
typedef enum D2D1_YCBCR_INTERPOLATION_MODE {
    D2D1_YCBCR_INTERPOLATION_MODE_NEAREST_NEIGHBOR = 0x0,
    D2D1_YCBCR_INTERPOLATION_MODE_LINEAR = 0x1,
    D2D1_YCBCR_INTERPOLATION_MODE_CUBIC = 0x2,
    D2D1_YCBCR_INTERPOLATION_MODE_MULTI_SAMPLE_LINEAR = 0x3,
    D2D1_YCBCR_INTERPOLATION_MODE_ANISOTROPIC = 0x4,
    D2D1_YCBCR_INTERPOLATION_MODE_HIGH_QUALITY_CUBIC = 0x5,
    D2D1_YCBCR_INTERPOLATION_MODE_FORCE_DWORD = 0xffffffff
} D2D1_YCBCR_INTERPOLATION_MODE;
/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __d2d1effects_1_h__ */
