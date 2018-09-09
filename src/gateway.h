#ifndef _GATEWAY_H_
#define _GATEWAY_H_

#include <lwip/netif.h>
#include <uv.h>

#define GATEWAY_BUFFER_SIZE 2000

typedef int (*send_packet_func_t)(void *userdata, const void *data, uint16_t len);
struct gateway {
    struct netif netif;
    uv_loop_t loop;
    uv_thread_t loop_thread;
};
struct something {
    int (*init)();
    int (*accept)();
} fuck;

int gateway_init(struct gateway *gateway, send_packet_func_t send_packet, void *userdata);
void gateway_on_packet(struct gateway *gateway, const uint8_t *data, int data_len);

#endif // _GATEWAY_H_