#define UCHAR_CIRCULAR_BUFFER_SIZE 64 /* Should be a power of 2, so it can be processor-optimized */
#define UINT_CIRCULAR_BUFFER_SIZE 64 /* Should be a power of 2, so it can be processor-optimized */

struct _uintCircularBuffer{
  unsigned int data[UINT_CIRCULAR_BUFFER_SIZE];
  unsigned int head;
  unsigned int tail; /* Head points to the last int inserted, tail to the first one */
};

struct _ucharCircularBuffer{
  unsigned char data[UCHAR_CIRCULAR_BUFFER_SIZE];
  unsigned int head;
  unsigned int tail; /* Head points to the last char inserted, tail to the first one */
};

typedef struct _ucharCircularBuffer ucharCircularBuffer;
void ucharPush(unsigned char data, struct _ucharCircularBuffer* buf);
unsigned char ucharPop(struct _ucharCircularBuffer* buf);
unsigned char ucharAvailable(struct _ucharCircularBuffer* buf);
void uintPush(unsigned int data, struct _uintCircularBuffer* buf);
unsigned int uintPop(struct _uintCircularBuffer* buf);
typedef struct _uintCircularBuffer uintCircularBuffer;
unsigned char uintAvailable(struct _uintCircularBuffer* buf);
