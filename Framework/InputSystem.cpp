#include "InputSystem.hpp"



namespace Gao
{
    namespace Framework
    {
        InputSystem::InputSystem()
        {

        }

        InputSystem::~InputSystem()
        {

        }

        GaoVoid InputSystem::Update()
        {

        }

        GaoBool InputSystem::IsKeyPressed(Key key) const
        {
            return FALSE;
        }

        GaoBool InputSystem::IsKeyReleased(Key key) const
        {
            return FALSE;
        }

        GaoBool InputSystem::IsMouseButtonPressed(MouseButton button) const
        {
            return FALSE;
        }

        GaoBool InputSystem::IsMouseButtonReleased(MouseButton button) const
        {
            return FALSE;
        }

        GaoVoid InputSystem::SetMousePosition(GaoInt16 x, GaoInt16 y)
        {

        }

        GaoVoid InputSystem::GetMousePosition(GaoInt16& x, GaoInt16& y)
        {

        }

        GaoInt16 InputSystem::GetMousePositionX() const
        {
            return 0;
        }

        GaoInt16 InputSystem::GetMousePositionY() const
        {
            return 0;
        }

        GaoVoid InputSystem::ShowDefaultMouseCursor(GaoBool show)
        {

        }

        GaoInt16 InputSystem::GetMouseWheelLastMovement() const
        {
            return 0;
        }
    }
}
