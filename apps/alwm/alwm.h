#ifndef ALWM_H_
#define ALWM_H_

typedef struct NwkFrameHeader_t
{
    uint16_t    macFcf;
    uint8_t     macSeq;
    uint16_t    macDstPanId;
    uint16_t    macDstAddr;
    uint16_t    macSrcAddr;

    struct
    {
        uint8_t   ackRequest : 1;
        uint8_t   security   : 1;
        uint8_t   linkLocal  : 1;
        uint8_t   multicast  : 1;
        uint8_t   reserved   : 4;
    }           nwkFrameControl;

    uint8_t     nwkSeq;
    uint16_t    nwkSrcAddr;
    uint16_t    nwkDstAddr;
    struct
    {
        uint8_t   nwkSrcEndpoint : 4;
        uint8_t   nwkDstEndpoint : 4;
    };
} NwkFrameHeader_t;

#endif //ALWM_H_
