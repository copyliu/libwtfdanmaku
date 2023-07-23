#ifndef _WTF_TOP_DANMAKU_HPP
#define _WTF_TOP_DANMAKU_HPP

#include "Noncopyable.hpp"
#include "BaseDanmaku.hpp"

namespace WTFDanmaku
{
    class IDanmakusRetainer;

    class TopDanmaku : public BaseDanmaku
    {
    public:
        static DanmakuRef Create()
        {
            return xl::RefPtr<TopDanmaku>(new TopDanmaku);
        }

        static std::unique_ptr<IDanmakusRetainer> CreateRetainer();

    public:
        explicit TopDanmaku() = default;

        ~TopDanmaku() override;

        DanmakuType GetType() override;

        void Layout(Displayer* displayer, DanmakuConfig* config, float x, float y) override;

        float GetSpeed() override;

        float GetLeftAtTime(Displayer* displayer, time_t time) override;

        Rect<float> GetRectAtTime(Displayer* displayer, time_t time) override;

    private:
        class TopRetainer;

    private:
        float y = 0.0f;
    };
}

#endif // _WTF_TOP_DANMAKU_HPP
