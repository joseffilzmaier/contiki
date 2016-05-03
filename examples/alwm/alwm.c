
#include "project_conf.h"
#include "contiki.h"
#include "stdio.h"
#include "alwm.h"

PROCESS(atmel_lightweight_mesh, "Atmel lwm");
AUTOSTART_PROCESSES(&atmel_lightweight_mesh);

PROCESS_THREAD(atmel_lightweight_mesh, ev, data) {

    PROCESS_BEGIN();

    NwkFrameHeader_t header;


    PROCESS_END();
}
