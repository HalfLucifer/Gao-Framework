
namespace Gao
{
    namespace Framework
    {
        inline GaoUInt32 Timer::GetDeltaTime() const
        {
            return m_DeltaTime;
        }

        inline GaoReal32 Timer::GetDeltaInSecond() const
        {
            return static_cast<GaoReal32>(m_DeltaTime) * 0.001f;
        }
    }
}
