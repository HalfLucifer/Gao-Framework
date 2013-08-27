/**
 * @file InputSystem.hpp
 * @author Lucifer Jheng
 *
 * Interface for physical input device (keyboard, mouse, etc) usage.
 *
 */
#ifndef GAO_FRAMEWORK_INPUTSYSTEM_H
#define GAO_FRAMEWORK_INPUTSYSTEM_H

#include "DataType.hpp"
#include "Singleton.hpp"

#define g_InputSystem Gao::Framework::InputSystem::GetSingletonPointer()



namespace Gao
{
    namespace Framework
    {
        /**
         * @brief Interface class for input usage.
         */
        class InputSystem : public Singleton<InputSystem>
        {

        public:

            /**
             * @brief Keyboard's virtual keys.
             */
            enum Key
            {
                Key_Escape, Key_Space, Key_Enter, Key_Back, Key_Tab,
                Key_Up, Key_Down, Key_Left, Key_Right,
                Key_LShift, Key_RShift, Key_LControl, Key_RControl, Key_LAlt, Key_RAlt,
                Key_F1, Key_F2, Key_F3, Key_F4, Key_F5, Key_F6, Key_F7, Key_F8, Key_F9, Key_F10, Key_F11, Key_F12,
                Key_0, Key_1, Key_2, Key_3, Key_4, Key_5, Key_6, Key_7, Key_8, Key_9,
                Key_A, Key_B, Key_C, Key_D, Key_E, Key_F, Key_G, Key_H, Key_I, Key_J, Key_K, Key_L, Key_M,
                Key_N, Key_O, Key_P, Key_Q, Key_R, Key_S, Key_T, Key_U, Key_V, Key_W, Key_X, Key_Y, Key_Z,
                Key_Num0, Key_Num1, Key_Num2, Key_Num3, Key_Num4, Key_Num5, Key_Num6, Key_Num7, Key_Num8, Key_Num9,
                Key_Add, Key_Subtract, Key_Multiply, Key_Divide, Key_Decimal,
                Key_Insert, Key_Delete, Key_Home, Key_End, Key_PageUp, Key_PageDown,
                Key_LWin, Key_RWin, Key_Menu
            };

            /**
             * @brief Mouse's buttons.
             */
            enum MouseButton
            {
                MouseButton_Left,
                MouseButton_Right,
                MouseButton_Middle,
            };


        public:

            /**
             * @brief Class default constructor.
             */
            InputSystem();

            /**
             * @brief Class destructor.
             */
            virtual ~InputSystem();

            /**
             * @brief Update procedure for input system.
             */
            virtual GaoVoid Update();

            /**
             * @brief Determine if the specified key is currently on pressed state.
             * @param key The key to check.
             * @return Pressed or not.
             */
            virtual GaoBool IsKeyPressed(Key key) const;

            /**
             * @brief Determine if the specified key is currently on released state.
             * @param key The key to check.
             * @return Released or not.
             */
            virtual GaoBool IsKeyReleased(Key key) const;

            /**
             * @brief Determine if the specified mouse button is currently pressed.
             * @param button The button to check.
             * @return Pressed or not.
             */
            virtual GaoBool IsMouseButtonPressed(MouseButton button) const;

            /**
             * @brief Determine if the specified mouse button is currently released.
             * @param button The button to check.
             * @return Released or not.
             */
            virtual GaoBool IsMouseButtonReleased(MouseButton button) const;

            /**
             * @brief Show/Hide system default mouse cursor.
             * @param show True for show; false for hide.
             */
            virtual GaoVoid ShowDefaultMouseCursor(GaoBool show);

            /**
             * @brief Set the current position of mouse cursor.
             * @param x The X coordinate.
             * @param y The Y coordinate.
             */
            virtual GaoVoid SetMousePosition(GaoInt16 x, GaoInt16 y);

            /**
             * @brief Get the current position of mouse cursor.
             * @param[out] x The X coordinate.
             * @param[out] y The Y coordinate.
             */
            virtual GaoVoid GetMousePosition(GaoInt16& x, GaoInt16& y);

            /**
             * @brief Get the current X coordinate of mouse cursor.
             * @return The X coordinate.
             */
            virtual GaoInt16 GetMousePositionX() const;

            /**
             * @brief Get the current Y coordinate of mouse cursor.
             * @return The Y coordinate.
             */
            virtual GaoInt16 GetMousePositionY() const;

            /**
             * @brief Get the last movement of mouse wheel.
             * @return The last movement.
             */
            virtual GaoInt16 GetMouseWheelLastMovement() const;

        };
    }
}

#endif
