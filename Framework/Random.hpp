/**
 * @file Random.hpp
 * @author Jheng Wei Ciao
 *
 * Interface for random usage.
 *
 */
#ifndef GAO_FRAMEWORK_RANDOM_H
#define GAO_FRAMEWORK_RANDOM_H

#include "DataType.hpp"



namespace Gao
{
    namespace Framework
    {
        class Random
        {

        public:

            static inline GaoVoid Seed(GaoUInt32 seed);

            static inline GaoInt32 GetRangedRandom(GaoInt32 min, GaoInt32 max);

            static inline GaoReal32 GetUnitRandom();

            static inline GaoReal32 GetSymmetricRandom();

        };
    }
}

#include "Random.inl"

#endif
