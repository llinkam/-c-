/**
 * 环形buffer是一种先进先出的数据缓冲机制，用于解决数据生产速度与
 * 消费速度不一致的问题。写入端（如串口中断）持续写入数据，读取端
 * （如主循环）按需读取，两端互不阻塞，且内存空间循环复用。
 */

typedef struct {
    uint8_t  *buf;
    uint16_t  head;
    uint16_t  tail;
    uint16_t  size;
} RingBuffer_t;

/**
 * @brief  向环形buffer写入一个字节
 * @param  rb:   环形buffer指针
 * @param  data: 写入的数据
 * @retval 无
 */
void rb_write(RingBuffer_t *rb, uint8_t data) {
    rb->buf[rb->tail] = data;
    rb->tail = (rb->tail + 1) % rb->size;
}

/**
 * @brief  从环形buffer读取一个字节
 * @param  rb: 环形buffer指针
 * @retval 读取到的数据
 */
uint8_t rb_read(RingBuffer_t *rb) {
    uint8_t data;
    data = rb->buf[rb->head];
    rb->head = (rb->head + 1) % rb->size;
    return data;
}

/**
 * @brief  获取环形buffer当前可读字节数
 * @param  rb: 环形buffer指针
 * @retval 可读字节数
 */
uint16_t rb_available(RingBuffer_t *rb) {
    return (rb->tail - rb->head + rb->size) % rb->size;
}
