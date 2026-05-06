#include <stdio.h>
#include <stdint.h>
int main()
{

}
typedef struct {
    uint8_t *buf;
    uint16_t head;
    uint16_t tail;
    uint16_t size;
} RingBuffer_t;
// 往环形buffer里写一个字节
void rb_write(RingBuffer_t *rb, uint8_t data) 
{
    rb->buf=data;
}
uint8_t rb_read(RingBuffer_t *rb) 
{   
    uint8_t data;
    data = rb->buf[rb->head];
    rb->head=(rb->head + 1) % rb->size;
    return data;
}
uint16_t rb_available(RingBuffer_t *rb)
{
    uint8_t data;

   if(data=rb->head-rb->tail>0)
   {
       return data;
   }
   else
   {
       return 64-rb->tail+rb->head;
   }
   
}