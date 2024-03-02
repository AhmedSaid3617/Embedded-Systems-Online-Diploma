#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

#define CPU_TYPE CPU_TYPE_32
#define CPU_BIT_ORDER MSB_FIRST
#define CPU_BYTE_ORDER LOW_BYTE_FIRST

typedef unsigned char boolean;
#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef False
#define False 0
#endif

#ifndef True
#define True 0
#endif

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;

typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef signed long long sint64;

typedef uint8 uint8_least;
typedef uint16 uint16_least;
typedef uint32 uint32_least;

typedef sint8 sint8_least;
typedef sint16 sint16_least;
typedef sint32 sint32_least;

typedef float float32;
typedef double float64;

typedef void* VoidPtr;
typedef const void* ConstVoidPointer;


#endif