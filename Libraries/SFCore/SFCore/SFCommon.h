#ifndef INCLUDED_SFCOMMON_H
#define INCLUDED_SFCOMMON_H

#include <cstdint>

typedef uint8_t UInt8;
typedef uint16_t UInt16;
typedef uint32_t UInt32;
typedef uint64_t UInt64;
typedef int8_t Int8;
typedef int16_t Int16;
typedef int32_t Int32;
typedef int64_t Int64;
typedef float Real32;
typedef double Real64;
typedef UInt8 Bool;
typedef UInt32 Size;

#ifndef NULL
#define NULL 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef SF_EXPECT
#include <assert.h>
#define SF_EXPECT(A) assert(A);
#endif

#ifndef SF_NO_IMPLEMENTATION
#define SF_NO_IMPLEMENTATION 
#endif

#ifndef SF_UNUSED_PARAMETER
#define SF_UNUSED_PARAMETER(A) (void)(A);
#endif

namespace SF
{
    typedef void Void;
    typedef Void* VoidPointer;
    typedef const Void* ConstVoidPointer;
    typedef UInt8 Byte;
    typedef Byte* BytePointer;
    typedef char Char;
    typedef Char* CharPointer;
}

#endif // INCLUDED_SFCOMMON_H