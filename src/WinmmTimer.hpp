#ifndef _WTF_WINMM_TIMER_HPP
#define _WTF_WINMM_TIMER_HPP

#include "ITimer.hpp"

namespace WTFDanmaku
{
    class WinmmTimer : public ITimer
    {
    public:
        static TimerRef Create()
        {
            return std::make_shared<WinmmTimer>();
        }

        static time_t GetGlobalCurrent();

    public:
        explicit WinmmTimer();
        ~WinmmTimer() override;
        void Start() override;
        void Pause() override;
        void Resume() override;
        void Update() override;
        void Stop() override;
        void AddOffset(int64_t offset) override;
        time_t GetMilliseconds() override;

    private:
        int64_t mBeginTime = 0;
        int64_t mTimeBase = 0;
        int64_t mCurrent = 0;
    };
}

#endif // _WTF_WINMM_TIMER_HPP
