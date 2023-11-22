//
// Created by ffernandoalves on 18/11/2023.
//

#ifndef NSENGINE_TYPES_HPP
#define NSENGINE_TYPES_HPP

#include <cstdint>
#include <cfloat>
#include <vector>

namespace NSEngine {
    namespace types {
        using u16 = std::uint16_t;
        using u32 = std::uint32_t;
        using u64 = std::uint64_t;
        using f32 = float;
        using f64 = double;
        template<typename T> using vec = std::vector<T>;
        using id_type = std::uint32_t;
    }
}

#endif //NSENGINE_TYPES_HPP
