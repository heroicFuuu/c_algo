/* MAX */
#define MAX(a, b) ((a) > (b)) ? (a) : (b)

/* numbers of array element */
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

/* set bit */
#define set_bit(b, n) ((b) |= ((n) << 1))

/* clear bit */
#define clear_bit(b, n) ((b) &= ~((n) << 1))

/* toggle bit */
#define toggle_bit(b, n) ((b) ^= ((n) << 1))
