
namespace Gao
{
    namespace Framework
    {
        inline GaoVoid Random::Seed(GaoUInt32 seed)
        {
            ::srand(seed);
        }

        inline GaoInt32 Random::GetRangedRandom(GaoInt32 min, GaoInt32 max)
        {
#ifdef GAO_PLATFORM_WINTEL32
            return (((max - min + 1) * ::rand() / (RAND_MAX + 1)) + min);
#else
			// NOTE: MacOSX impelementation
			// When min >= 0, then min <= result <= max
			// When min < 0, then min < result <= max
            return static_cast<GaoInt32>(static_cast<GaoReal32>(::rand()) / static_cast<GaoReal32>(RAND_MAX) * (max - min + 1) + min);
#endif
        }

        inline GaoReal32 Random::GetUnitRandom()
        {
            return (static_cast<GaoReal32>(::rand()) / static_cast<GaoReal32>(RAND_MAX));
        }

        inline GaoReal32 Random::GetSymmetricRandom()
        {
            return (-1.0f + 2.0f * static_cast<GaoReal32>(::rand()) / static_cast<GaoReal32>(RAND_MAX));
        }
    }
}
