#include "cbuf.h"

void ucharPush(unsigned char data, struct _ucharCircularBuffer* buf){
  buf->head=(buf->head+1)%UCHAR_CIRCULAR_BUFFER_SIZE;
  /*If there is data overwrite, it is not reported; shouldn't be a problem, but increase size if it is, otherwise performance is affected */
  buf->data[buf->head]=data;
}

unsigned char ucharPop(struct _ucharCircularBuffer* buf){
  if(buf->tail!=buf->head){
    buf->tail=(buf->tail+1)%UCHAR_CIRCULAR_BUFFER_SIZE;
    return buf->data[buf->tail];
  }
  /* Dummy return, otherwise push will complicate a lot if tail goes forward wrt head*/
  return 255;
}

unsigned char ucharAvailable(struct _ucharCircularBuffer* buf){
  return buf->head-buf->tail;
}

void uintPush(unsigned int data, struct _uintCircularBuffer* buf){
  buf->head=(buf->head+1)%UINT_CIRCULAR_BUFFER_SIZE;
  /*If there is data overwrite, it is not reported; shouldn't be a problem, but increase size if it is, otherwise performance is affected */
  buf->data[buf->head]=data;
}

unsigned int uintPop(struct _uintCircularBuffer* buf){
  if(buf->tail!=buf->head){
    buf->tail=(buf->tail+1)%UINT_CIRCULAR_BUFFER_SIZE;
    return buf->data[buf->tail];
  }
  /* Dummy return, otherwise push will complicate a lot if tail goes forward wrt head*/
  return 255;
}

unsigned char uintAvailable(struct _uintCircularBuffer* buf){
  return buf->head-buf->tail;
}
