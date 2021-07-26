#ifndef STD_TYPES
#define STD_TYPES

typedef unsigned char 				uint8_t;
typedef signed char 				int8_t;

typedef unsigned short int 			uint16_t;
typedef unsigned long int 			uint32_t;
typedef unsigned long long int 		uint64_t;

typedef signed short int 			int16_t;
typedef signed long int 			int32_t;
typedef signed long long int 		int64_t;

typedef float						float32_t;
typedef double						float64_t;
typedef long double					float128_t;


#define uint8_max		0xFF
#define uint8_min		0x00

#define int8_max		0x7F
#define int8_min		0x80

#define uint16_max		0xFFFF
#define uint32_max		0xFFFFFFFF
#define uint64_max		0xFFFFFFFFFFFFFFFF

#define uint16_min		0x00
#define uint32_min		0x00
#define uint64_min		0x00

#define int16_max		0x7FFF
#define int32_max		0x7FFFFFFF
#define int64_max		0x7FFFFFFFFFFFFFFF

#define int16_min		0x8000
#define int32_min		0x80000000
#define int64_min		0x8000000000000000

#endif
