#ifndef INCLUDED_SFUTILITIES_H
#define INCLUDED_SFUTILITIES_H

#include "SFCommon.h"

namespace SF
{
    class Utilities
    {
    public:
        static VoidPointer memSet(VoidPointer destination, Int32 value, Size length);
        static VoidPointer memCopy(VoidPointer destination, ConstVoidPointer source, Size length);
    };
}

#endif // INCLUDED_SFUTILITIES_H 