#ifndef _WTF_BOTTOM_DANMAKU_HPP
#define _WTF_BOTTOM_DANMAKU_HPP

#include "TopDanmaku.hpp"

namespace WTFDanmaku
{
    class BottomDanmaku : public TopDanmaku
    {
    public:
        static DanmakuRef Create()
        {
            return xl::RefPtr<BottomDanmaku>(new BottomDanmaku);
        }

        static std::unique_ptr<IDanmakusRetainer> CreateRetainer();

    public:
        explicit BottomDanmaku() = default;
        ~BottomDanmaku() override;
        DanmakuType GetType() override;

    private:
        class BottomRetainer;
    };
}


#endif // _WTF_BOTTOM_DANMAKU_HPP
