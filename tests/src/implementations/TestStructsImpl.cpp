/*
 * Copyright 2026 Metrological - Apache 2.0
 */

#include "TestRegistry.h"
#include <ITestStructs.h>
#include <cmath>
#include <algorithm>
#include <map>

namespace Thunder {
namespace TestImplementations {

    using namespace FunctionalTest;

    class TestStructsImpl : public ITestStructs {
    public:
        TestStructsImpl()
            : _pointSet(false)
            , _rectSet(false)
            , _colorSet(false)
            , _point{0, 0}
            , _rect{{0, 0}, {0, 0}}
            , _color{0, 0, 0, 255}
            , _config("{}")
        {
        }
        ~TestStructsImpl() override = default;

        TestStructsImpl(const TestStructsImpl&) = delete;
        TestStructsImpl& operator=(const TestStructsImpl&) = delete;

        // ===== Store =====

        Core::hresult SetPoint(const Point& point) override
        { _point = point; _pointSet = true; return Core::ERROR_NONE; }

        Core::hresult SetRectangle(const Rectangle& rect) override
        { _rect = rect; _rectSet = true; return Core::ERROR_NONE; }

        Core::hresult SetColor(const Color& color) override
        { _color = color; _colorSet = true; return Core::ERROR_NONE; }

        // ===== Retrieve =====

        Core::hresult GetPoint(Point& point) const override
        {
            if (!_pointSet) return Core::ERROR_ILLEGAL_STATE;
            point = _point;
            return Core::ERROR_NONE;
        }

        Core::hresult GetRectangle(Rectangle& rect) const override
        {
            if (!_rectSet) return Core::ERROR_ILLEGAL_STATE;
            rect = _rect;
            return Core::ERROR_NONE;
        }

        Core::hresult GetColor(Color& color) const override
        {
            if (!_colorSet) return Core::ERROR_ILLEGAL_STATE;
            color = _color;
            return Core::ERROR_NONE;
        }

        // ===== Inout =====

        Core::hresult MovePoint(Point& point, const int32_t dx, const int32_t dy) override
        { point.x += dx; point.y += dy; return Core::ERROR_NONE; }

        Core::hresult ScaleRectangle(Rectangle& rect, const double factor) override
        {
            rect.topLeft.x     = static_cast<int32_t>(rect.topLeft.x     * factor);
            rect.topLeft.y     = static_cast<int32_t>(rect.topLeft.y     * factor);
            rect.bottomRight.x = static_cast<int32_t>(rect.bottomRight.x * factor);
            rect.bottomRight.y = static_cast<int32_t>(rect.bottomRight.y * factor);
            return Core::ERROR_NONE;
        }

        Core::hresult AdjustColor(Color& color, const int16_t adjustment) override
        {
            auto Clamp = [](int32_t v) -> uint8_t {
                return static_cast<uint8_t>(v < 0 ? 0 : v > 255 ? 255 : v);
            };
            color.red   = Clamp(color.red   + adjustment);
            color.green = Clamp(color.green + adjustment);
            color.blue  = Clamp(color.blue  + adjustment);
            return Core::ERROR_NONE;
        }

        // ===== Computations =====

        Core::hresult DistanceBetweenPoints(const Point& p1, const Point& p2, double& distance) const override
        {
            int32_t dx = p2.x - p1.x;
            int32_t dy = p2.y - p1.y;
            distance = std::sqrt(static_cast<double>(dx * dx + dy * dy));
            return Core::ERROR_NONE;
        }

        Core::hresult RectanglesOverlap(const Rectangle& r1, const Rectangle& r2, bool& overlap) const override
        {
            overlap = !(r1.bottomRight.x <= r2.topLeft.x ||
                        r2.bottomRight.x <= r1.topLeft.x ||
                        r1.bottomRight.y <= r2.topLeft.y ||
                        r2.bottomRight.y <= r1.topLeft.y);
            return Core::ERROR_NONE;
        }

        Core::hresult BlendColors(const Color& c1, const Color& c2, const double ratio, Color& result) const override
        {
            auto Blend = [&](uint8_t a, uint8_t b) -> uint8_t {
                return static_cast<uint8_t>(a * (1.0 - ratio) + b * ratio);
            };
            result.red   = Blend(c1.red,   c2.red);
            result.green = Blend(c1.green, c2.green);
            result.blue  = Blend(c1.blue,  c2.blue);
            result.alpha = Blend(c1.alpha, c2.alpha);
            return Core::ERROR_NONE;
        }

        Core::hresult CalculateRectangleArea(const Rectangle& rect, uint32_t& area) const override
        {
            int32_t w = std::abs(rect.bottomRight.x - rect.topLeft.x);
            int32_t h = std::abs(rect.bottomRight.y - rect.topLeft.y);
            area = static_cast<uint32_t>(w * h);
            return Core::ERROR_NONE;
        }

        Core::hresult GetRectangleCenter(const Rectangle& rect, Point& center) const override
        {
            center.x = (rect.topLeft.x + rect.bottomRight.x) / 2;
            center.y = (rect.topLeft.y + rect.bottomRight.y) / 2;
            return Core::ERROR_NONE;
        }

        Core::hresult CalculateStatistics(const std::vector<uint32_t>& values, Statistics& result) const override
        {
            if (values.empty()) {
                return Core::ERROR_INVALID_INPUT_LENGTH;
            }
            result.count   = static_cast<uint32_t>(values.size());
            result.total   = 0;
            result.min     = values[0];
            result.max     = values[0];
            for (uint32_t v : values) {
                result.total += v;
                if (v < result.min) result.min = v;
                if (v > result.max) result.max = v;
            }
            result.average = static_cast<double>(result.total) / result.count;
            return Core::ERROR_NONE;
        }

        // ===== Vectors =====

        Core::hresult GetPoints(const uint16_t count, std::vector<Point>& points) const override
        {
            points.clear();
            points.reserve(count);
            for (uint16_t i = 0; i < count; ++i) {
                points.push_back({ static_cast<int32_t>(i) * 10, static_cast<int32_t>(i) * 10 });
            }
            return Core::ERROR_NONE;
        }

        Core::hresult SetPoints(const std::vector<Point>& points) override
        {
            _pointsVector = points;
            if (!points.empty()) {
                _point = points[0];
                _pointSet = true;
            }
            return Core::ERROR_NONE;
        }

        Core::hresult GetPalette(std::vector<Color>& palette) const override
        {
            if (!_palette.empty()) {
                palette = _palette;
                return Core::ERROR_NONE;
            }
            if (!_colorSet) {
                return Core::ERROR_ILLEGAL_STATE;
            }
            // Return default 6-color palette
            palette = {
                {255, 0,   0,   255},
                {0,   255, 0,   255},
                {0,   0,   255, 255},
                {255, 255, 0,   255},
                {255, 0,   255, 255},
                {0,   255, 255, 255}
            };
            return Core::ERROR_NONE;
        }

        Core::hresult SetPalette(const std::vector<Color>& palette) override
        {
            _palette = palette;
            if (!palette.empty()) {
                _color    = palette[0];
                _colorSet = true;
            }
            return Core::ERROR_NONE;
        }

        // ===== Config property =====

        Core::hresult GetConfig(string& config) const override
        { config = _config; return Core::ERROR_NONE; }

        Core::hresult SetConfig(const string& config) override
        { _config = config; return Core::ERROR_NONE; }

        // ===== SlotPoint indexed property =====

        Core::hresult GetSlotPoint(const uint8_t slot, Point& point) const override
        {
            auto it = _slots.find(slot);
            if (it == _slots.end()) return Core::ERROR_NOT_EXIST;
            point = it->second;
            return Core::ERROR_NONE;
        }

        Core::hresult SetSlotPoint(const uint8_t slot, const Point& point) override
        {
            _slots[slot] = point;
            return Core::ERROR_NONE;
        }

        // ===== Edge cases =====

        Core::hresult EchoPoint(const Point& point, Point& result) const override
        { result = point; return Core::ERROR_NONE; }

        Core::hresult IsValidPoint(const Point& point, bool& valid) const override
        {
            // Always valid for integer coordinates — present to exercise the code path
            (void)point;
            valid = true;
            return Core::ERROR_NONE;
        }

        Core::hresult IsValidRectangle(const Rectangle& rect, bool& valid) const override
        {
            valid = (rect.topLeft.x <= rect.bottomRight.x &&
                     rect.topLeft.y <= rect.bottomRight.y);
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestStructsImpl)
        INTERFACE_ENTRY(ITestStructs)
        END_INTERFACE_MAP

    private:
        bool                  _pointSet;
        bool                  _rectSet;
        bool                  _colorSet;
        Point                 _point;
        Rectangle             _rect;
        Color                 _color;
        string                _config;
        std::vector<Point>    _pointsVector;
        std::vector<Color>    _palette;
        std::map<uint8_t, Point> _slots;
    };

    static TestRegistry::ImplementationRegistrar<ITestStructs, TestStructsImpl> g_structsRegistrar;

} // namespace TestImplementations
} // namespace Thunder
