
#include "project_conf.h"
#include "contiki.h"
#include "stdio.h"
#include "rime-test.h"
#include "net/rime/mesh.h"
#include "random.h"
#include "node-id.h"

#define MESSAGE "Hello"

PROCESS(atmel_lightweight_mesh, "Atmel lwm");
AUTOSTART_PROCESSES(&atmel_lightweight_mesh);

static struct mesh_conn mesh;

static void
sent(struct mesh_conn *c)
{
  printf("packet sent\n");
}

static void
timedout(struct mesh_conn *c)
{
  printf("packet timedout\n");
}

static void
recv(struct mesh_conn *c, const linkaddr_t *from, uint8_t hops)
{
  printf("Data received from %d.%d: %.*s (%d)\n",
	 from->u8[0], from->u8[1],
	 packetbuf_datalen(), (char *)packetbuf_dataptr(), packetbuf_datalen());

  packetbuf_copyfrom(MESSAGE, strlen(MESSAGE));
  mesh_send(&mesh, from);
}

const static struct mesh_callbacks callbacks = {recv, sent, timedout};

PROCESS_THREAD(atmel_lightweight_mesh, ev, data) {

    PROCESS_BEGIN();
    //PROCESS_EXITHANDLER(mesh_close(&mesh);)
    
    mesh_open(&mesh, 132, &callbacks);
    
    //while(1) {
        linkaddr_t addr;
        
        /* Wait for button click before sending the first message. */
        /*PROCESS_WAIT_EVENT_UNTIL(ev == sensors_event && data == &button_sensor);

        printf("Button clicked\n");*/
        
        if ((node_id & 0xff) == 2){
            clock_delay(1000);

            /* Send a message to node number 1. */
            if (node_id & 0xff)
            packetbuf_copyfrom(MESSAGE, strlen(MESSAGE));
            addr.u8[0] = 1;
            addr.u8[1] = 0;
            printf("Sending to addr ");
            printf("%d,%d", addr.u8[0], addr.u8[1]);
            mesh_send(&mesh, &addr);
        }
        else {
            while (1);
        }
        
    //}
    
    //NwkFrameHeader_t header;

    PROCESS_END();
}
