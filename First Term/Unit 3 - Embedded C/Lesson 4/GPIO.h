#define _GPIOF 0x40025000

#define _GPIO_DATA_OFFSET 0x3fc
#define _GPIO_DIR_OFFSET 0x400
#define _GPIO_DEN_OFFSET 0x51c

#define GPIOF_DATA_R *((volatile unsigned long *)(_GPIOF + _GPIO_DATA_OFFSET))
#define GPIOF_DIR_R *((volatile unsigned long *)(_GPIOF + _GPIO_DIR_OFFSET))
#define GPIOF_DEN_R *((volatile unsigned long *)(_GPIOF + _GPIO_DEN_OFFSET))

#define SYSCTL_RCGC2_R *((volatile unsigned long *)(0x400FE108))
