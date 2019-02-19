# pragma once

namespace BMCPP{
    struct GRBColor final {
        const std::byte green{0};
        const std::byte red{0};
        const std::byte blue{0};
    } __attribute__((packed));
    
    template<auto brightness=100>
    struct Color{
        static_assert(brightness <= 100, "Brightness cant be higher than 100%");
        static_assert(brightness >= 0, "Brightness cant be lower than 0%");
        constexpr static auto intensity = 255*brightness/100;
        constexpr static BMCPP::GRBColor green{std::byte(intensity), std::byte(0), std::byte(0)};
        constexpr static BMCPP::GRBColor blue{std::byte(intensity), std::byte(0), std::byte(intensity)};
        constexpr static BMCPP::GRBColor red{std::byte(0), std::byte(intensity), std::byte(0)};
        constexpr static BMCPP::GRBColor pink{std::byte(intensity/5*3), std::byte(intensity), std::byte(intensity/5*3)};
        constexpr static BMCPP::GRBColor yellow{std::byte(intensity), std::byte(intensity), std::byte(0)};
        constexpr static BMCPP::GRBColor orange{std::byte(intensity/5*2), std::byte(intensity), std::byte(0)};
        constexpr static BMCPP::GRBColor black{std::byte(0), std::byte(0), std::byte(0)};
    };
}