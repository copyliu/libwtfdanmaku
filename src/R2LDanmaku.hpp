#ifndef _WTF_R2L_DANMAKU_HPP
#define _WTF_R2L_DANMAKU_HPP

#include "Noncopyable.hpp"
#include "BaseDanmaku.hpp"

namespace WTFDanmaku
{
    class IDanmakusRetainer;

    class R2LDanmaku : public BaseDanmaku
    {
    public:
        static DanmakuRef Create()
        {
            return xl::RefPtr<R2LDanmaku>(new R2LDanmaku);
        }

        static std::unique_ptr<IDanmakusRetainer> CreateRetainer();

    public:
        explicit R2LDanmaku() = default;

        ~R2LDanmaku() override;

        DanmakuType GetType() override;

        void Measure(Displayer* displayer, DanmakuConfig* config) override;

        void Layout(Displayer* displayer, DanmakuConfig* config, float x, float y) override;

        bool IsAlive(time_t time) override;

        float GetSpeed() override;

        float GetLeftAtTime(Displayer* displayer, time_t time) override;

        Rect<float> GetRectAtTime(Displayer* displayer, time_t time) override;

    private:
        class R2LRetainer;

    private:
        float y = 0.0f;
        float mSpeed = 0.0f;
    };
}

#endif // _WTF_R2L_DANMAKU_HPP
