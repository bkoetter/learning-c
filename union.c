#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef union {
    uint32_t as_u32;
    uint8_t  as_bytes[4];
} packet_u;

typedef enum {
    PACKET_U32,
    PACKET_BYTES
} packet_type_t;

struct packet {
    packet_type_t type;
    packet_u data;
};

//void view_packet(struct packet *p)
int main(int argv, char **args)
{
    struct packet a = {
        .type = PACKET_U32,
        .data = { .as_u32 = 12345678 },
    };
    struct packet *p = &a;
    a.type = PACKET_BYTES;
    /*
        if the packet is a u32 type
        print the packet as a 4 byte hex integer
        ex: 12345678

        if the packet is a bytes type
        print the packet as 4 bytes
        ex: 78 56 34 12

        no newlines
    */
    if (p->type == PACKET_U32) {
        printf("%08x", p->data.as_u32);
    } else if (p->type == PACKET_BYTES) {
        for (int i=0; i<sizeof(p->data.as_u32); i++) {
            printf("%02x", p->data.as_bytes[i]);
            if (i+1 < sizeof(p->data.as_u32)) {
                printf(" ");
            }
        }
    };
}
