
#ifndef ALWM_H_
#define ALWM_H_

#include "uip.h"


extern unsigned char node_mac[8];

typedef struct NwkFrameHeader_t
{
  uint16_t         macFcf;
  uint8_t          macSeq;
  uint16_t         macDstPanId;
  unsigned char    macDstAddr[8];
  unsigned char    macSrcAddr[8];

  struct
  {
    uint8_t        ackRequest : 1;
    uint8_t        security   : 1;
    uint8_t        linkLocal  : 1;
    uint8_t        multicast  : 1;
    uint8_t        reserved   : 4;
  }                nwkFcf;
  uint8_t          nwkSeq;
  uip_ip6addr_t    nwkSrcAddr;
  uip_ip6addr_t    nwkDstAddr;
  struct
  {
    uint8_t   nwkSrcEndpoint : 4;
    uint8_t   nwkDstEndpoint : 4;
  };
} NwkFrameHeader_t;


#endif //ALWM_H_
