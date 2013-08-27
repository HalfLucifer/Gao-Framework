#include "LuaFunction.hpp"
#include "GraphicsEngine.hpp"
#include "GraphicsRenderer.hpp"
#include "Transform.hpp"
#include "Texture.hpp"
#include "Sprite.hpp"



namespace Gao
{
    namespace Framework
    {

#ifdef GAO_SCRIPT_LUA_IMPLEMENTATION

        GaoBool RegisterLuaGraphicsFunctions(LuaState state)
		{

#ifdef GAO_SCRIPT_LUABIND_IMPLEMENTATION

			using namespace luabind;
            
			//
			// GraphicsEngine
			//
			module(state)
			[
				class_<GraphicsEngine>("GraphicsEngine")
					.enum_("BlendMode")
					[
						value("BLEND_WHITEOUT", BlendWhiteout),
                        value("BLEND_FADEOUT", BlendFadeout)
					]

					.def(constructor<GraphicsRenderer*>())
                    .def("SetBasePath", (GaoVoid(GraphicsEngine::*)(GaoConstCharPtr, GaoConstCharPtr))&GraphicsEngine::SetBasePath)
                    .def("SetClearColor", &GraphicsEngine::SetClearColor)
                    .def("SetBlendFunction", &GraphicsEngine::SetBlendFunction)
					.def("Render", &GraphicsEngine::Render)
					.def("Flush", &GraphicsEngine::Flush)
					.def("CreateTransform", &GraphicsEngine::CreateTransform)
					.def("CreateTexture", (Texture*(GraphicsEngine::*)(GaoConstCharPtr))&GraphicsEngine::CreateTexture)
                    .def("CreateFilteredTexture", &GraphicsEngine::CreateFilteredTexture)
                    .def("CreateSpecialTexture", &GraphicsEngine::CreateSpecialTexture)
                    .def("DestroySpecialTexture", &GraphicsEngine::DestroySpecialTexture)
                    .def("IsSpecialTextureValid", &GraphicsEngine::IsSpecialTextureValid)
                    .def("CreateSprite", (Sprite*(GraphicsEngine::*)(GaoConstCharPtr))&GraphicsEngine::CreateSprite)
                    .def("CreateSprite", (Sprite*(GraphicsEngine::*)(Transform*, Texture*))&GraphicsEngine::CreateSprite)
					.def("PrecreateSprite", &GraphicsEngine::PrecreateSprite)
					.def("ReloadTexture", &GraphicsEngine::ReloadTexture)
					.def("UnloadTexture", &GraphicsEngine::UnloadTexture)
					.def("DrawPixel", &GraphicsEngine::DrawPixel)
					.def("DrawPixel", &GraphicsEngine::DrawPixel)
					.def("DrawLine", &GraphicsEngine::DrawLine)
					.def("DrawRectangle", &GraphicsEngine::DrawRectangle)
					.def("DrawCircle", &GraphicsEngine::DrawCircle)
					.def("SetLineWidth", &GraphicsEngine::SetLineWidth)
                    .def("SaveScreenshot", (GaoBool(GraphicsEngine::*)(GaoConstCharPtr))&GraphicsEngine::SaveScreenshot)
                    .def("ApplyWorldTransform", (GaoVoid(GraphicsEngine::*)(GaoReal32, GaoReal32))&GraphicsEngine::ApplyWorldTransform)
					.def("RestoreWorldTransform", &GraphicsEngine::RestoreWorldTransform)
			];

            //
            // GraphicsRenderer
            //
			module(state)
			[
				class_<GraphicsRenderer>("GraphicsRenderer")
					.def(constructor<>())
			];

			//
			// Transform
			//
			module(state)
			[
				class_<Transform>("Transform")
					.def(constructor<>())
					.def("SetTranslate", (GaoVoid(Transform::*)(GaoReal32, GaoReal32))&Transform::SetTranslate)
					.def("ModifyTranslate", (GaoVoid(Transform::*)(GaoReal32, GaoReal32))&Transform::ModifyTranslate)
					.def("SetRotateByRadian", &Transform::SetRotateByRadian)
					.def("SetRotateByDegree", &Transform::SetRotateByDegree)
                    .def("ModifyRotateByRadian", &Transform::ModifyRotateByRadian)
                    .def("ModifyRotateByDegree", &Transform::ModifyRotateByDegree)
                    .def("GetRotateByRadian", &Transform::GetRotateByRadian)
                    .def("GetRotateByDegree", &Transform::GetRotateByDegree)
					.def("SetScale", &Transform::SetScale)
                    .def("GetScale", &Transform::GetScale)
					.def("ModifyScale", &Transform::ModifyScale)
					.def("GetTranslateX", &Transform::GetTranslateX)
					.def("GetTranslateY", &Transform::GetTranslateY)
			];

			//
			// Texture
			//
			module(state)
			[
				class_<Texture>("Texture")
					.def(constructor<>())
			];

			//
			// Sprite
			//
			module(state)
			[
				class_<Sprite>("Sprite")
					.def(constructor<>())
                    .def("Draw", (GaoVoid(Sprite::*)())&Sprite::Draw)
                    .def("Draw", (GaoVoid(Sprite::*)(GaoInt16, GaoInt16))&Sprite::Draw)
                    .def("DrawOffset", (GaoVoid(Sprite::*)(GaoInt16, GaoInt16))&Sprite::DrawOffset)
                    .def("SetTexture", &Sprite::SetTexture)
                    .def("SetBlendingMode", &Sprite::SetBlendingMode)
                    .def("SetAlpha", &Sprite::SetAlpha)
                    .def("SetFlip", &Sprite::SetFlip)
					.def("SetTexCoords", &Sprite::SetTexCoords)
                    .def("SetTexCoordsU", &Sprite::SetTexCoordsU)
                    .def("SetTexCoordsV", &Sprite::SetTexCoordsV)
                    .def("SetRenderSize", &Sprite::SetRenderSize)
					.def("SetRenderSizeAndTexCoords", &Sprite::SetRenderSizeAndTexCoords)
                    .def("SetRenderSizeAndRadius", &Sprite::SetRenderSizeAndRadius)
					.def("SetVertexData", &Sprite::SetVertexData)
                    .def("SetQuadVertices", &Sprite::SetQuadVertices)
                    .def("SetQuadTexCoords", &Sprite::SetQuadTexCoords)
					.def("SetTransform", &Sprite::SetTransform)
                    .def("SetOffset", &Sprite::SetOffset)
                    .def("GetOffsetX", &Sprite::GetOffsetX)
                    .def("GetOffsetY", &Sprite::GetOffsetY)
                    .def("ToggleFlipX", &Sprite::ToggleFlipX)
                    .def("ToggleFlipY", &Sprite::ToggleFlipY)
                    .def("ResetFlip", &Sprite::ResetFlip)
                    .def("GetTransform", &Sprite::GetTransform)
					.def("GetWidth", &Sprite::GetWidth)
					.def("GetHeight", &Sprite::GetHeight)
					.def("GetAlpha", &Sprite::GetAlpha)
                    .def("GetTexture", &Sprite::GetTexture)
            ];

#endif // End of GAO_SCRIPT_LUABIND_IMPLEMENTATION

            return TRUE;
        }

#endif // End of GAO_SCRIPT_LUA_IMPLEMENTATION

    }
}
