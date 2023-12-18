#ifndef __DCMEDIA_API_
#define __DCMEDIA_API_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#include "rkmedia_api.h"

/************************************
 * DCMEDIA Common Data type
************************************/
typedef RK_U8 DC_U8;
typedef RK_U16 DC_U16;
typedef RK_U32 DC_U32;

typedef RK_S8 DC_S8;
typedef RK_S16 DC_S16;
typedef RK_S32 DC_S32;

typedef RK_UL DC_UL;
typedef RK_SL DC_SL;

typedef RK_FLOAT DC_FLOAT;
typedef RK_DOUBLE DC_DOUBLE;

typedef RK_CHAR DC_CHAR;

typedef enum {
    DC_TRUE,
    DC_FALSE
}DC_BOOL;

#ifndef _M_IX86
typedef RK_U64 DC_U64;
typedef RK_S64 DC_S64;
#else
typedef RK_U64 DC_U64;
typedef RK_S64 DC_S64;
#endif
#define DC_VOID void

typedef unsigned int DC_HANDLE;

/************************************
 * DCMEDIA Const defination
************************************/

#define DC_NULL 0L
#define DC_SUCCESS 0
#define DC_FAILURE (-1)

#define MAX_FILE_PATH_LEN 256

enum {
  /***********************************
   * DCMEDIA Common error types
   **********************************/
    DC_ERR_SYS_OK = 0,
    DC_ERR_SYS_NULL_PTR,
    DC_ERR_SYS_NOTREADY,
    DC_ERR_SYS_NOT_PERM,
    DC_ERR_SYS_NOMEM,
    DC_ERR_SYS_ILLEGAL_PARAM,
    DC_ERR_SYS_BUSY,
    DC_ERR_SYS_NOT_SUPPORT,
    DC_ERR_SYS_OP_REPEAT,
    DC_ERR_SYS_ERR_STATUS,

  /***********************************
   * VideoInput error types
   **********************************/
  /* invlalid channel ID */
    DC_ERR_VI_INVALID_CHNID = 10,
  /* system is busy*/
    DC_ERR_VI_BUSY,
  /* channel exists */
    DC_ERR_VI_EXIST,
    DC_ERR_VI_NOT_CONFIG,
    DC_ERR_VI_TIMEOUT,
    DC_ERR_VI_BUF_EMPTY,
    DC_ERR_VI_ILLEGAL_PARAM,
    DC_ERR_VI_NOTREADY,

  /***********************************
   * VideoEncoder error types
   **********************************/
  /* invlalid channel ID */
    DC_ERR_VENC_INVALID_CHNID = 20,
  /* at lease one parameter is illagal ,eg, an illegal enumeration value  */
    DC_ERR_VENC_ILLEGAL_PARAM,
  /* channel exists */
    DC_ERR_VENC_EXIST,
  /* channel exists */
    DC_ERR_VENC_UNEXIST,
  /* using a NULL point */
    DC_ERR_VENC_NULL_PTR,
  /* try to enable or initialize system,device or channel,
     before configing attrib */
    DC_ERR_VENC_NOT_CONFIG,
  /* operation is not supported by NOW */
    DC_ERR_VENC_NOT_SUPPORT,
  /* operation is not permitted ,eg, try to change stati attribute */
    DC_ERR_VENC_NOT_PERM,
  /* failure caused by malloc memory */
    DC_ERR_VENC_NOMEM,
  /* failure caused by malloc buffer */
    DC_ERR_VENC_NOBUF,
  /* no data in buffer */
    DC_ERR_VENC_BUF_EMPTY,
  /* no buffer for new data */
    DC_ERR_VENC_BUF_FULL,
  /* system is not ready,had not initialed or loaded*/
    DC_ERR_VENC_NOTREADY,
  /* system is busy*/
    DC_ERR_VENC_BUSY,

  /***********************************
   * AI::Audio input error types
   **********************************/
  /* invlalid device ID */
    DC_ERR_AI_INVALID_CHNID = 40,
  /* system is busy*/
    DC_ERR_AI_BUSY,
    DC_ERR_AI_EXIST,
  /* system is not open, had not initaled or enabled*/
    DC_ERR_AI_NOTOPEN,
    DC_ERR_AI_NOT_CONFIG,

  /***********************************
   * AO::Audio output error types
   **********************************/
  /* invlalid device ID */
    DC_ERR_AO_INVALID_CHNID = 50,
  /* system is busy*/
    DC_ERR_AO_BUSY,
  /* system is not ready,had not initialed or loaded*/
    DC_ERR_AO_NOTREADY,
  /* system is not open, had not initaled or enabled*/
    DC_ERR_AO_NOTOPEN,
    DC_ERR_AO_ILLEGAL_PARAM,

  /***********************************
   * AENC::Audio encoder error types
   **********************************/
  /* invlalid device ID */
    DC_ERR_AENC_INVALID_CHNID = 60,
  /* system is busy*/
    DC_ERR_AENC_BUSY,
  /* codec not support*/
    DC_ERR_AENC_CODEC_NOT_SUPPORT,
    DC_ERR_AENC_NOTREADY,

  /***********************************
   * Algorithm::MoveDetection error types
   **********************************/
  /* invlalid channel ID */
    DC_ERR_ALGO_MD_INVALID_CHNID = 70,
  /* system is busy*/
    DC_ERR_ALGO_MD_BUSY,
  /* channel exists */
    DC_ERR_ALGO_MD_EXIST,
    DC_ERR_ALGO_MD_NOT_CONFIG,
  /* at lease one parameter is illagal ,eg, an illegal enumeration value  */
    DC_ERR_ALGO_MD_ILLEGAL_PARAM,

  /***********************************
   * Algorithm::OcclusionDetection error types
   **********************************/
  /* invlalid channel ID */
    DC_ERR_ALGO_OD_INVALID_CHNID = 80,
  /* system is busy*/
    DC_ERR_ALGO_OD_BUSY,
  /* channel exists */
    DC_ERR_ALGO_OD_EXIST,
    DC_ERR_ALGO_OD_NOT_CONFIG,
  /* at lease one parameter is illagal ,eg, an illegal enumeration value  */
    DC_ERR_ALGO_OD_ILLEGAL_PARAM,

  /***********************************
   * RGA::rga error types
   **********************************/
  /* invlalid channel ID */
    DC_ERR_RGA_INVALID_CHNID = 90,
  /* system is busy*/
    DC_ERR_RGA_BUSY,
  /* channel exists */
    DC_ERR_RGA_EXIST,
    DC_ERR_RGA_NOT_CONFIG,
  /* at lease one parameter is illagal ,eg, an illegal enumeration value  */
    DC_ERR_RGA_ILLEGAL_PARAM,
    DC_ERR_RGA_NOTREADY,

  /***********************************
   * ADEC::Audio decoder error types
   **********************************/
  /* invlalid device ID */
    DC_ERR_ADEC_INVALID_CHNID = 100,
  /* system is busy*/
    DC_ERR_ADEC_BUSY,
  /* codec not support*/
    DC_ERR_ADEC_CODEC_NOT_SUPPORT,

  /***********************************
   * VO::Video Output error types
   **********************************/
    DC_ERR_VO_INVALID_CHNID = 110,
    DC_ERR_VO_BUSY,
    DC_ERR_VO_EXIST,
    DC_ERR_VO_NOT_CONFIG,
    DC_ERR_VO_TIMEOUT,
    DC_ERR_VO_BUF_EMPTY,
    DC_ERR_VO_ILLEGAL_PARAM,
    DC_ERR_VO_NOTREADY,

  /***********************************
   * VDEC::Video Output error types
   **********************************/
    DC_ERR_VDEC_INVALID_CHNID = 120,
    DC_ERR_VDEC_BUSY,
    DC_ERR_VDEC_EXIST,
    DC_ERR_VDEC_NOT_CONFIG,
    DC_ERR_VDEC_TIMEOUT,
    DC_ERR_VDEC_BUF_EMPTY,
    DC_ERR_VDEC_ILLEGAL_PARAM,
    DC_ERR_VDEC_NOTREADY,

  /***********************************
   * VMIX::Video Mixer error types
   **********************************/
    DC_ERR_VMIX_INVALID_DEVID = 130,
    DC_ERR_VMIX_INVALID_CHNID,
    DC_ERR_VMIX_BUSY,
    DC_ERR_VMIX_EXIST,
    DC_ERR_VMIX_ILLEGAL_PARAM,
    DC_ERR_VMIX_NOTREADY,
    DC_ERR_VMIX_NOTOPEN,

  /***********************************
   * MUXER::Muxer error types
   **********************************/
    DC_ERR_MUXER_INVALID_CHNID = 140,
    DC_ERR_MUXER_BUSY,
    DC_ERR_MUXER_EXIST,
    DC_ERR_MUXER_ILLEGAL_PARAM,
    DC_ERR_MUXER_NOTREADY,
    DC_ERR_MUXER_NOTSUPPORT,

  /***********************************
   * VideoProcess error types
   **********************************/
  /* invlalid channel ID */
    DC_ERR_VP_INVALID_CHNID = 150,
  /* system is busy*/
    DC_ERR_VP_BUSY,
  /* channel exists */
    DC_ERR_VP_EXIST,
    DC_ERR_VP_NOT_CONFIG,
    DC_ERR_VP_TIMEOUT,
    DC_ERR_VP_BUF_EMPTY,
    DC_ERR_VP_ILLEGAL_PARAM,
    DC_ERR_VP_NOTREADY,

    DC_ERR_BUIT,
};










/********************************************************************
 * DCMEDIA SYS Ctrl api
 ********************************************************************/
_CAPI DC_S32 DC_MPI_SYS_Init();

_CAPI RK_VOID DC_MPI_SYS_DumpChn(MOD_ID_E enModId);

_CAPI DC_S32 DC_MPI_SYS_Bind(const MPP_CHN_S *pstSrcChn, const MPP_CHN_S *pstDestChn);

_CAPI DC_S32 DC_MPI_SYS_UnBind(const MPP_CHN_S *pstSrcChn, const MPP_CHN_S *pstDestChn);

_CAPI DC_S32 DC_MPI_SYS_RegisterOutCb(const MPP_CHN_S *pstChn, OutCbFunc cb);

_CAPI DC_S32 DC_MPI_SYS_RegisterOutCbEx(const MPP_CHN_S *pstChn, OutCbFuncEx cb, DC_VOID *pHandle);

_CAPI DC_S32 DC_MPI_SYS_RegisterEventCb(const MPP_CHN_S *pstChn, DC_VOID *pHandle, EventCbFunc cb);

_CAPI DC_S32 DC_MPI_SYS_SendMediaBuffer(MOD_ID_E enModID, DC_S32 s32ChnID, MEDIA_BUFFER buffer);

_CAPI DC_S32 DC_MPI_SYS_DevSendMediaBuffer(MOD_ID_E enModID, DC_S32 s32DevId, DC_S32 s32ChnID, MEDIA_BUFFER buffer);

_CAPI DC_S32 DC_MPI_SYS_SetMediaBufferDepth(MOD_ID_E enModID, DC_S32 s32ChnID, DC_S32 u32Depth);

_CAPI DC_S32 DC_MPI_SYS_StartGetMediaBuffer(MOD_ID_E enModID, DC_S32 s32ChnID);

_CAPI DC_S32 DC_MPI_SYS_StopGetMediaBuffer(MOD_ID_E enModID, DC_S32 s32ChnID);

_CAPI MEDIA_BUFFER DC_MPI_SYS_GetMediaBuffer(MOD_ID_E enModID, DC_S32 s32ChnID, DC_S32 s32MilliSec);

_CAPI DC_S32 DC_MPI_SYS_SetFrameRate(MOD_ID_E enModID, DC_S32 s32ChnID, MPP_FPS_ATTR_S *pstFpsAttr);

_CAPI DC_S32 DC_MPI_SYS_StartRecvFrame(MOD_ID_E enModID, DC_S32 s32ChnID, const MPP_RECV_PIC_PARAM_S *pstRecvParam);

_CAPI DC_S32 DC_MPI_LOG_SetLevelConf(LOG_LEVEL_CONF_S *pstConf);

_CAPI DC_S32 DC_MPI_LOG_GetLevelConf(LOG_LEVEL_CONF_S *pstConf);



/********************************************************************
 * Vi api
 ********************************************************************/
_CAPI DC_S32 DC_MPI_VI_SetChnAttr(VI_PIPE ViPipe, VI_CHN ViChn, const VI_CHN_ATTR_S *pstChnAttr);

_CAPI DC_S32 DC_MPI_VI_GetChnAttr(VI_PIPE ViPipe, VI_CHN ViChn, VI_CHN_ATTR_S *pstChnAttr);

_CAPI DC_S32 DC_MPI_VI_EnableChn(VI_PIPE ViPipe, VI_CHN ViChn);

_CAPI DC_S32 DC_MPI_VI_DisableChn(VI_PIPE ViPipe, VI_CHN ViChn);

_CAPI DC_S32 DC_MPI_VI_StartRegionLuma(VI_CHN ViChn);

_CAPI DC_S32 DC_MPI_VI_StopRegionLuma(VI_CHN ViChn);

_CAPI DC_S32 DC_MPI_VI_GetChnRegionLuma(VI_PIPE ViPipe, VI_CHN ViChn, const VIDEO_REGION_INFO_S *pstRegionInfo, 
                                        DC_U64 *pu64LumaData, DC_S32 s32MilliSec);

_CAPI DC_S32 DC_MPI_VI_StartStream(VI_PIPE ViPipe, VI_CHN ViChn);

_CAPI DC_S32 DC_MPI_VI_SetUserPic(VI_CHN ViChn, VI_USERPIC_ATTR_S *pstUsrPicAttr);

_CAPI DC_S32 DC_MPI_VI_EnableUserPic(VI_CHN ViChn);

_CAPI DC_S32 DC_MPI_VI_DisableUserPic(VI_CHN ViChn);

_CAPI DC_S32 DC_MPI_VI_RGN_SetCover(VI_PIPE ViPipe, VI_CHN ViChn, const OSD_REGION_INFO_S *pstRgnInfo,
                                    const COVER_INFO_S *pstCoverInfo);

_CAPI DC_S32 DC_MPI_VI_RGN_SetBitMap(VI_PIPE ViPipe, VI_CHN ViChn, const OSD_REGION_INFO_S *pstRgnInfo,
                                     const BITMAP_S *pstBitmap);

_CAPI DC_S32 DC_MPI_VI_GetStatus(VI_CHN ViChn);



/********************************************************************
 * Venc api
 ********************************************************************/
_CAPI DC_S32 DC_MPI_VENC_CreateChn(VENC_CHN VencChn, VENC_CHN_ATTR_S *stVencChnAttr);

_CAPI DC_S32 DC_MPI_VENC_CreateJpegLightChn(VENC_CHN VencChn, VENC_CHN_ATTR_S *stVencChnAttr);

_CAPI DC_S32 DC_MPI_VENC_GetVencChnAttr(VENC_CHN VencChn, VENC_CHN_ATTR_S *stVencChnAttr);

_CAPI DC_S32 DC_MPI_VENC_SetVencChnAttr(VENC_CHN VencChn, VENC_CHN_ATTR_S *stVencChnAttr);

_CAPI DC_S32 DC_MPI_VENC_GetChnParam(VENC_CHN VencChn, VENC_CHN_PARAM_S *stVencChnParam);

_CAPI DC_S32 DC_MPI_VENC_SetChnParam(VENC_CHN VencChn, VENC_CHN_PARAM_S *stVencChnParam);

_CAPI DC_S32 DC_MPI_VENC_GetRcParam(VENC_CHN VencChn, VENC_RC_PARAM_S *pstRcParam);

_CAPI DC_S32 DC_MPI_VENC_SetRcParam(VENC_CHN VencChn, const VENC_RC_PARAM_S *pstRcParam);

_CAPI DC_S32 DC_MPI_VENC_SetJpegParam(VENC_CHN VencChn, const VENC_JPEG_PARAM_S *pstJpegParam);

_CAPI DC_S32 DC_MPI_VENC_SetRcMode(VENC_CHN VencChn, VENC_RC_MODE_E RcMode);

_CAPI DC_S32 DC_MPI_VENC_SetRcQuality(VENC_CHN VencChn, VENC_RC_QUALITY_E RcQuality);

_CAPI DC_S32 DC_MPI_VENC_SetBitrate(VENC_CHN VencChn, DC_U32 u32BitRate, DC_U32 u32MinBitRate, DC_U32 u32MaxBitRate);

_CAPI DC_S32 DC_MPI_VENC_RequestIDR(VENC_CHN VencChn, DC_BOOL bInstant);

_CAPI DC_S32 DC_MPI_VENC_SetFps(VENC_CHN VencChn, DC_U8 u8OutNum, DC_U8 u8OutDen, DC_U8 u8InNum, DC_U8 u8InDen);

_CAPI DC_S32 DC_MPI_VENC_SetGop(VENC_CHN VencChn, DC_U32 u32Gop);

_CAPI DC_S32 DC_MPI_VENC_SetAvcProfile(VENC_CHN VencChn, DC_U32 u32Profile, DC_U32 u32Level);

_CAPI DC_S32 DC_MPI_VENC_InsertUserData(VENC_CHN VencChn, DC_U8 *pu8Data, DC_U32 u32Len);

_CAPI DC_S32 DC_MPI_VENC_SetResolution(VENC_CHN VencChn, VENC_RESOLUTION_PARAM_S stResolutionParam);

_CAPI DC_S32 DC_MPI_VENC_SetRotation(VENC_CHN VeChn, VENC_ROTATION_E rotation_rate);

_CAPI DC_S32 DC_MPI_VENC_GetRoiAttr(VENC_CHN VencChn, VENC_ROI_ATTR_S *pstRoiAttr, DC_S32 roi_index);

_CAPI DC_S32 DC_MPI_VENC_SetRoiAttr(VENC_CHN VencChn, const VENC_ROI_ATTR_S *pstRoiAttr, DC_S32 region_cnt);

_CAPI DC_S32 DC_MPI_VENC_SetGopMode(VENC_CHN VencChn, VENC_GOP_ATTR_S *pstGopModeAttr);

_CAPI DC_S32 DC_MPI_VENC_RGN_Init(VENC_CHN VencChn, VENC_COLOR_TBL_S *stColorTbl);

_CAPI DC_S32 DC_MPI_VENC_RGN_SetBitMap(VENC_CHN VencChn, const OSD_REGION_INFO_S *pstRgnInfo, const BITMAP_S *pstBitmap);

_CAPI DC_S32 DC_MPI_VENC_RGN_SetCover(VENC_CHN VencChn, const OSD_REGION_INFO_S *pstRgnInfo, const COVER_INFO_S *pstCoverInfo);

_CAPI DC_S32 DC_MPI_VENC_RGN_SetCoverEx(VENC_CHN VencChn, const OSD_REGION_INFO_S *pstRgnInfo, 
                                        const COVER_INFO_S *pstCoverInfo);

_CAPI DC_S32 DC_MPI_VENC_RGN_SetPaletteId(VENC_CHN VencChn, const OSD_REGION_INFO_S *pstRgnInfo, 
                                          const OSD_COLOR_PALETTE_BUF_S *pstColPalBuf);

_CAPI DC_S32 DC_MPI_VENC_StartRecvFrame(VENC_CHN VencChn, const VENC_RECV_PIC_PARAM_S *pstRecvParam);

_CAPI DC_S32 DC_MPI_VENC_DestroyChn(VENC_CHN VencChn);

_CAPI DC_S32 DC_MPI_VENC_GetFd(VENC_CHN VencChn);

_CAPI DC_S32 DC_MPI_VENC_QueryStatus(VENC_CHN VencChn, VENC_CHN_STATUS_S *pstStatus);

_CAPI DC_S32 DC_MPI_VENC_SetSuperFrameStrategy(VENC_CHN VeChn, const VENC_SUPERFRAME_CFG_S *pstSuperFrmParam);

_CAPI DC_S32 DC_MPI_VENC_GetSuperFrameStrategy(VENC_CHN VeChn, VENC_SUPERFRAME_CFG_S *pstSuperFrmParam);

/********************************************************************
 * Algorithm::Move Detection api
 ********************************************************************/
_CAPI DC_S32 DC_MPI_ALGO_MD_CreateChn(ALGO_MD_CHN MdChn, const ALGO_MD_ATTR_S *pstChnAttr);

_CAPI DC_S32 DC_MPI_ALGO_MD_DestroyChn(ALGO_MD_CHN MdChn);

_CAPI DC_S32 DC_MPI_ALGO_MD_SetRegions(ALGO_MD_CHN MdChn, RECT_S *stRoiRects, DC_S32 regionNum);

_CAPI DC_S32 DC_MPI_ALGO_MD_EnableSwitch(ALGO_MD_CHN MdChn, DC_BOOL bEnable);

/********************************************************************
 * Algorithm::Occlusion Detection api
 ********************************************************************/
_CAPI DC_S32 DC_MPI_ALGO_OD_CreateChn(ALGO_OD_CHN OdChn, const ALGO_OD_ATTR_S *pstChnAttr);

_CAPI DC_S32 DC_MPI_ALGO_OD_DestroyChn(ALGO_OD_CHN OdChn);

_CAPI DC_S32 DC_MPI_ALGO_OD_EnableSwitch(ALGO_OD_CHN OdChn, DC_BOOL bEnable);

/********************************************************************
 * Rga api
 ********************************************************************/
_CAPI DC_S32 DC_MPI_RGA_CreateChn(RGA_CHN RgaChn, RGA_ATTR_S *pstAttr);

_CAPI DC_S32 DC_MPI_RGA_DestroyChn(RGA_CHN RgaChn);

_CAPI DC_S32 DC_MPI_RGA_SetChnAttr(RGA_CHN RgaChn, const RGA_ATTR_S *pstAttr);

_CAPI DC_S32 DC_MPI_RGA_GetChnAttr(RGA_CHN RgaChn, RGA_ATTR_S *pstAttr);

_CAPI DC_S32 DC_MPI_RGA_RGN_SetBitMap(RGA_CHN RgaChn, const OSD_REGION_INFO_S *pstRgnInfo,
                                      const BITMAP_S *pstBitmap);

_CAPI DC_S32 DC_MPI_RGA_GetChnRegionLuma(RGA_CHN RgaChn, const VIDEO_REGION_INFO_S *pstRegionInfo,
                                         DC_U64 *pu64LumaData, DC_S32 s32MilliSec);

_CAPI DC_S32 DC_MPI_RGA_RGN_SetCover(RGA_CHN RgaChn, const OSD_REGION_INFO_S *pstRgnInfo,
                                     const COVER_INFO_S *pstCoverInfo);

/********************************************************************
 * Mediabuffer api
 ********************************************************************/
_CAPI void *DC_MPI_MB_GetPtr(MEDIA_BUFFER mb);

_CAPI int DC_MPI_MB_GetFD(MEDIA_BUFFER mb);

_CAPI int DC_MPI_MB_GetHandle(MEDIA_BUFFER mb);

_CAPI int DC_MPI_MB_GetDevFD(MEDIA_BUFFER mb);

_CAPI size_t DC_MPI_MB_GetSize(MEDIA_BUFFER mb);

_CAPI MOD_ID_E DC_MPI_MB_GetModeID(MEDIA_BUFFER mb);

_CAPI DC_S16 DC_MPI_MB_GetChannelID(MEDIA_BUFFER mb);

_CAPI DC_U64 DC_MPI_MB_GetTimestamp(MEDIA_BUFFER mb);

_CAPI DC_S32 DC_MPI_MB_ReleaseBuffer(MEDIA_BUFFER mb);

_CAPI MEDIA_BUFFER DC_MPI_MB_CreateBuffer(DC_U32 u32Size, DC_BOOL boolHardWare, DC_U8 u8Flag);

_CAPI MEDIA_BUFFER DC_MPI_MB_ConvertToImgBuffer(MEDIA_BUFFER mb, MB_IMAGE_INFO_S *pstImageInfo);

_CAPI MEDIA_BUFFER DC_MPI_MB_ConvertToAudBufferExt(MEDIA_BUFFER mb, MB_AUDIO_INFO_S *pstAudioInfo);

_CAPI MEDIA_BUFFER DC_MPI_MB_ConvertToAudBuffer(MEDIA_BUFFER mb);

_CAPI MEDIA_BUFFER DC_MPI_MB_CreateImageBuffer(MB_IMAGE_INFO_S *pstImageInfo, DC_BOOL boolHardWare, DC_U8 u8Flag);

_CAPI MEDIA_BUFFER DC_MPI_MB_CreateAudioBufferExt(MB_AUDIO_INFO_S *pstAudioInfo, DC_BOOL boolHardWare, DC_U8 u8Flag);

_CAPI MEDIA_BUFFER DC_MPI_MB_CreateAudioBuffer(DC_U32 u32BufferSize, DC_BOOL boolHardWare);

_CAPI DC_S32 DC_MPI_MB_SetSize(MEDIA_BUFFER mb, DC_U32 size);

_CAPI DC_S32 DC_MPI_MB_SetTimestamp(MEDIA_BUFFER mb, DC_U64 timestamp);

_CAPI DC_S32 DC_MPI_MB_GetFlag(MEDIA_BUFFER mb);

_CAPI DC_S32 DC_MPI_MB_GetTsvcLevel(MEDIA_BUFFER mb);

_CAPI DC_BOOL DC_MPI_MB_IsViFrame(MEDIA_BUFFER mb);

_CAPI DC_S32 DC_MPI_MB_GetImageInfo(MEDIA_BUFFER mb, MB_IMAGE_INFO_S *pstImageInfo);

_CAPI DC_S32 DC_MPI_MB_GetAudioInfo(MEDIA_BUFFER mb, MB_AUDIO_INFO_S *pstAudioInfo);

_CAPI DC_S32 DC_MPI_MB_BeginCPUAccess(MEDIA_BUFFER mb, DC_BOOL bReadonly);

_CAPI DC_S32 DC_MPI_MB_EndCPUAccess(MEDIA_BUFFER mb, DC_BOOL bReadonly);

_CAPI DC_S32 DC_MPI_MB_TsNodeDump(MEDIA_BUFFER mb);

_CAPI MEDIA_BUFFER DC_MPI_MB_Copy(MEDIA_BUFFER mb, DC_BOOL bZeroCopy);

_CAPI MEDIA_BUFFER_POOL DC_MPI_MB_POOL_Create(MB_POOL_PARAM_S *pstPoolParam);

_CAPI DC_S32 DC_MPI_MB_POOL_Destroy(MEDIA_BUFFER_POOL MBPHandle);

_CAPI MEDIA_BUFFER DC_MPI_MB_POOL_GetBuffer(MEDIA_BUFFER_POOL MBPHandle, DC_BOOL bIsBlock);



#ifdef __cplusplus
}
#endif
#endif //__DCMEDIA_API_