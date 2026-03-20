/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2026 Metrological
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Ids.h"
#include "Module.h"

namespace Thunder {
namespace FunctionalTest {

    // Test POD struct serialization over COM-RPC
    // @json 1.0.0
    struct EXTERNAL ITestStructs : virtual public Core::IUnknown {
        enum { ID = ID_TEST_STRUCTS };

        // ===== Simple POD structs =====

        // @brief Point in 2D space with integer coordinates.
        struct Point {
            /* @brief X coordinate */
            int32_t x;
            /* @brief Y coordinate */
            int32_t y;
        };

        // @brief Rectangle defined by top-left and bottom-right points.
        struct Rectangle {
            /* @brief Top-left corner of the rectangle */
            Point topLeft;
            /* @brief Bottom-right corner of the rectangle */
            Point bottomRight;
        };

        // @brief RGBA color with 8 bits per channel.
        struct Color {
            /* @brief Red channel intensity */
            uint8_t red;
            /* @brief Green channel intensity */
            uint8_t green;
            /* @brief Blue channel intensity */
            uint8_t blue;
            /* @brief Alpha (opacity) channel intensity */
            uint8_t alpha;
        };

        // @brief Statistics for a collection of numbers.
        struct Statistics {
            uint32_t count; /* @brief Number of samples */
            uint64_t total; /* @brief Sum of all samples */
            double average; /* @brief Average value of all samples */
            double min; /* @brief Minimum value in the sample set */
            double max; /* @brief Maximum value in the sample set */
        };

        // ===== Struct as input parameter =====

        // @brief Store a Point for later retrieval via GetPoint.
        // @param point Point to store.
        virtual Core::hresult SetPoint(const Point& point /* @in */) = 0;

        // @brief Store a Rectangle for later retrieval via GetRectangle.
        // @param rect Rectangle to store.
        virtual Core::hresult SetRectangle(const Rectangle& rect /* @in */) = 0;

        // @brief Store a Color for later retrieval via GetColor.
        // @param color Color to store.
        virtual Core::hresult SetColor(const Color& color /* @in */) = 0;

        // ===== Struct as output parameter =====

        // @brief Retrieve the last stored Point.
        // @param point Receives the stored Point.
        // @retval ERROR_ILLEGAL_STATE No Point has been stored yet.
        virtual Core::hresult GetPoint(Point& point /* @out */) const = 0;

        // @brief Retrieve the last stored Rectangle.
        // @param rect Receives the stored Rectangle.
        // @retval ERROR_ILLEGAL_STATE No Rectangle has been stored yet.
        virtual Core::hresult GetRectangle(Rectangle& rect /* @out */) const = 0;

        // @brief Retrieve the last stored Color.
        // @param color Receives the stored Color.
        // @retval ERROR_ILLEGAL_STATE No Color has been stored yet.
        virtual Core::hresult GetColor(Color& color /* @out */) const = 0;

        // ===== Struct as inout parameter =====

        // @brief Translate a Point by (dx, dy) in place.
        // @param point In: original coordinates.  Out: translated coordinates.
        // @param dx    Horizontal displacement (may be negative).
        // @param dy    Vertical displacement (may be negative).
        virtual Core::hresult MovePoint(
            Point& point /* @inout */,
            const int32_t dx /* @in */,
            const int32_t dy /* @in */)
            = 0;

        // @brief Scale a Rectangle uniformly around the origin by factor.
        //        Each coordinate of topLeft and bottomRight is multiplied by factor.
        // @param rect   In: original rectangle.  Out: scaled rectangle.
        // @param factor Scale multiplier (e.g. 2.0 doubles all coordinates).
        virtual Core::hresult ScaleRectangle(
            Rectangle& rect /* @inout */,
            const double factor /* @in */)
            = 0;

        // @brief Add a signed adjustment to every channel of a Color, clamping to [0, 255].
        // @param color      In: original Color.  Out: adjusted Color.
        // @param adjustment Signed delta applied to each channel; clamps instead of wrapping.
        virtual Core::hresult AdjustColor(
            Color& color /* @inout */,
            const int16_t adjustment /* @in */)
            = 0;

        // ===== Multiple struct parameters =====

        // @brief Compute the Euclidean distance between two Points.
        // @param p1       First point.
        // @param p2       Second point.
        // @param distance Receives sqrt((p2.x-p1.x)^2 + (p2.y-p1.y)^2).
        virtual Core::hresult DistanceBetweenPoints(
            const Point& p1 /* @in */,
            const Point& p2 /* @in */,
            double& distance /* @out */) const
            = 0;

        // @brief Determine whether two Rectangles share any area.
        //        Edge-touching (but not overlapping) rectangles are not considered to overlap.
        // @param r1      First rectangle.
        // @param r2      Second rectangle.
        // @param overlap Receives true if r1 and r2 have a non-zero intersection area.
        virtual Core::hresult RectanglesOverlap(
            const Rectangle& r1 /* @in */,
            const Rectangle& r2 /* @in */,
            bool& overlap /* @out */) const
            = 0;

        // @brief Linearly interpolate between two Colors.
        //        Each channel: result = c1 * (1 - ratio) + c2 * ratio, clamped to [0, 255].
        // @param c1     Start Color (ratio == 0.0 returns c1).
        // @param c2     End Color (ratio == 1.0 returns c2).
        // @param ratio  Interpolation factor in [0.0, 1.0].
        // @param result Receives the blended Color.
        virtual Core::hresult BlendColors(
            const Color& c1 /* @in */,
            const Color& c2 /* @in */,
            const double ratio /* @in */,
            Color& result /* @out */) const
            = 0;

        // ===== Struct computation =====

        // @brief Compute the area of a Rectangle.
        //        Area = abs(bottomRight.x - topLeft.x) * abs(bottomRight.y - topLeft.y).
        // @param rect In: rectangle to measure.
        // @param area Receives the computed area in square pixels.
        virtual Core::hresult CalculateRectangleArea(
            const Rectangle& rect /* @in */,
            uint32_t& area /* @out */) const
            = 0;

        // @brief Compute the centre Point of a Rectangle.
        //        center.x = (topLeft.x + bottomRight.x) / 2 (integer division).
        //        center.y = (topLeft.y + bottomRight.y) / 2 (integer division).
        // @param rect   In: rectangle to measure.
        // @param center Receives the centre point.
        virtual Core::hresult GetRectangleCenter(
            const Rectangle& rect /* @in */,
            Point& center /* @out */) const
            = 0;

        // @brief Compute descriptive statistics over a non-empty vector of uint32_t values.
        //        The @ restrict:1..10000 annotation limits the vector to at most 10000 elements
        //        and requires at least 1 (so that min, max, and average are always well-defined).
        // @param values Non-empty vector of samples (1..10000 elements).
        // @param result Receives count, total, average, min, and max.
        // @retval ERROR_INVALID_INPUT values is empty.
        virtual Core::hresult CalculateStatistics(
            const std::vector<uint32_t>& values /* @in @restrict:1..10000 */,
            Statistics& result /* @out */) const
            = 0;

        // ===== Struct arrays =====

        // FIXME: variable-length C arrays of struct are not supported by the generator.
        // Use std::vector instead (see vector methods below).

        // ===== Vector of structs =====

        // @brief Generate count synthetic Point values and return them as a vector.
        //        The @ restrict:1..1000 annotation enforces at least 1 and at most 1000 points.
        // @param count  Number of points to generate (1..1000).
        // @param points Receives the generated Point vector.
        // @retval ERROR_INVALID_INPUT count == 0 or count > 1000.
        virtual Core::hresult GetPoints(
            const uint16_t count /* @in */,
            std::vector<Point>& points /* @out @restrict:1..1000 */) const
            = 0;

        // @brief Store a vector of Points for later retrieval.
        //        The @ restrict:1..1000 annotation enforces at least 1 and at most 1000 points.
        // @param points Non-empty vector of at most 1000 Points to store.
        // @retval ERROR_INVALID_INPUT points is empty or has more than 1000 entries.
        virtual Core::hresult SetPoints(
            const std::vector<Point>& points /* @in @restrict:1..1000 */)
            = 0;

        // @brief Retrieve the stored colour palette.
        //        The @ restrict:1..256 annotation reflects the constraint that a palette must
        //        have at least 1 entry and at most 256 (full 8-bit index range).
        // @param palette Receives the stored palette (1..256 Colors).
        // @retval ERROR_ILLEGAL_STATE No palette has been stored yet.
        virtual Core::hresult GetPalette(
            std::vector<Color>& palette /* @out @restrict:1..256 */) const
            = 0;

        // @brief Store a colour palette for later retrieval.
        //        The @ restrict:1..256 annotation enforces at least 1 and at most 256 entries.
        // @param palette Non-empty vector of at most 256 Colors.
        // @retval ERROR_INVALID_INPUT palette is empty or has more than 256 entries.
        virtual Core::hresult SetPalette(
            const std::vector<Color>& palette /* @in @restrict:1..256 */)
            = 0;

        // @property
        // @brief Raw JSON configuration blob — passed through without deserialisation.
        //        The @ opaque annotation tells the JSON-RPC layer to treat the string as a
        //        pre-serialised JSON object and embed it verbatim rather than re-encoding it.
        virtual Core::hresult GetConfig(string& config /* @out @opaque */) const = 0;

        // @brief Set the JSON configuration blob. The @ opaque annotation has the same effect as on GetConfig.
        virtual Core::hresult SetConfig(const string& config /* @in @opaque */) = 0;

        // @property
        // @brief Point stored at a given slot.
        //        The @ index annotation marks slot as the JSON-RPC property index, making
        //        each slot independently addressable via the property API.
        // @param slot Slot number (index); the valid range is implementation-defined.
        virtual Core::hresult GetSlotPoint(const uint8_t slot /* @index */, Point& point /* @out */) const = 0;

        // @brief Set the Point stored at a given slot. The @ index annotation has the same effect as on GetSlotPoint.
        virtual Core::hresult SetSlotPoint(const uint8_t slot /* @index */, const Point& point /* @in */) = 0;

        // ===== Edge cases =====

        // @brief Echo a Point unchanged (round-trip marshalling test).
        // @param point  Input Point.
        // @param result Receives a copy of point.
        virtual Core::hresult EchoPoint(
            const Point& point /* @in */,
            Point& result /* @out */) const
            = 0;

        // @brief Determine whether a Point has valid (non-NaN, finite) coordinates.
        //        For integer-only points this always returns true; the method is present
        //        to exercise the validation code path.
        // @param point Input Point to validate.
        // @param valid Receives true if the point is valid.
        virtual Core::hresult IsValidPoint(
            const Point& point /* @in */,
            bool& valid /* @out */) const
            = 0;

        // @brief Determine whether a Rectangle is geometrically valid.
        //        A Rectangle is valid when topLeft.x <= bottomRight.x and
        //        topLeft.y <= bottomRight.y (i.e. non-inverted).
        // @param rect  Input Rectangle to validate.
        // @param valid Receives true if the rectangle is non-inverted.
        virtual Core::hresult IsValidRectangle(
            const Rectangle& rect /* @in */,
            bool& valid /* @out */) const
            = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder