#include <stdint.h>
/* 64-bits machine */
uint64_t* read_mem(uint64_t addr) {
    uint64_t* p = (uint64_t*) addr;
    return *p;
}

void write_mem(uint64_t addr, uint64_t data) {
    uint64_t* p = (uint64_t*) addr;
    *p = data;
}
