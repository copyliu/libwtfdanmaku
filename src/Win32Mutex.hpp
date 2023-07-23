#ifndef _WTF_WIN32_MUTEX_HPP
#define _WTF_WIN32_MUTEX_HPP

#include <Windows.h>
#include "Noncopyable.hpp"

namespace WTFDanmaku
{
    class Win32Mutex : public Noncopyable
    {
    public:
        explicit Win32Mutex()
        {
            InitializeCriticalSection(&cs);
        }

        ~Win32Mutex()
        {
            DeleteCriticalSection(&cs);
        }

        void lock()
        {
            EnterCriticalSection(&cs);
        }

        void unlock()
        {
            LeaveCriticalSection(&cs);
        }

    private:
        CRITICAL_SECTION cs;
    };
}
#endif // _WTF_WIN32_MUTEX_HPP
