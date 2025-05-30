/*** Autogenerated by WIDL 10.0 from /build/wine-10.0/include/windows.media.render.idl - Do not edit ***/

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

#ifndef __windows_media_render_h__
#define __windows_media_render_h__

/* Forward declarations */

/* Headers for imported files */

#include <windows.foundation.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __cplusplus
typedef enum __x_ABI_CWindows_CMedia_CRender_CAudioRenderCategory __x_ABI_CWindows_CMedia_CRender_CAudioRenderCategory;
#endif /* __cplusplus */

#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
#ifdef __cplusplus
} /* extern "C" */
namespace ABI {
    namespace Windows {
        namespace Media {
            namespace Render {
                enum AudioRenderCategory {
                    AudioRenderCategory_Other = 0,
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
                    AudioRenderCategory_ForegroundOnlyMedia = 1,
#endif /* WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
                    AudioRenderCategory_BackgroundCapableMedia = 2,
#endif /* WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000 */
                    AudioRenderCategory_Communications = 3,
                    AudioRenderCategory_Alerts = 4,
                    AudioRenderCategory_SoundEffects = 5,
                    AudioRenderCategory_GameEffects = 6,
                    AudioRenderCategory_GameMedia = 7,
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
                    AudioRenderCategory_GameChat = 8,
#endif /* WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
                    AudioRenderCategory_Speech = 9,
#endif /* WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
                    AudioRenderCategory_Movie = 10,
#endif /* WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
                    AudioRenderCategory_Media = 11
#endif /* WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000 */
                };
            }
        }
    }
}
extern "C" {
#else
enum __x_ABI_CWindows_CMedia_CRender_CAudioRenderCategory {
    AudioRenderCategory_Other = 0,
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
    AudioRenderCategory_ForegroundOnlyMedia = 1,
#endif /* WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
    AudioRenderCategory_BackgroundCapableMedia = 2,
#endif /* WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000 */
    AudioRenderCategory_Communications = 3,
    AudioRenderCategory_Alerts = 4,
    AudioRenderCategory_SoundEffects = 5,
    AudioRenderCategory_GameEffects = 6,
    AudioRenderCategory_GameMedia = 7,
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
    AudioRenderCategory_GameChat = 8,
#endif /* WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
    AudioRenderCategory_Speech = 9,
#endif /* WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
    AudioRenderCategory_Movie = 10,
#endif /* WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000
    AudioRenderCategory_Media = 11
#endif /* WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000 */
};
#ifdef WIDL_using_Windows_Media_Render
#define AudioRenderCategory __x_ABI_CWindows_CMedia_CRender_CAudioRenderCategory
#endif /* WIDL_using_Windows_Media_Render */
#endif

#endif /* WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x10000 */
/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __windows_media_render_h__ */
