/**
 * @file Texture.hpp
 * @author Jheng Wei Ciao
 *
 * Interface class for texture usage.
 *
 */
#ifndef GAO_FRAMEWORK_TEXTURE_H
#define GAO_FRAMEWORK_TEXTURE_H

#include "DataType.hpp"
#include "GraphicsDefine.hpp"



namespace Gao
{
    namespace Framework
    {
        class Texture
        {

        public:

            Texture();

            virtual ~Texture();

            virtual GaoBool Create(GaoString& fileName);

            virtual GaoBool Reload();
            
            virtual GaoVoid Unload();
            
            inline GaoInt16 GetWidth() const;
            
            inline GaoInt16 GetHeight() const;
            
            
        protected:
        
            GaoInt16 m_Width;
            GaoInt16 m_Height;

        };
    }
}

#include "Texture.inl"

#endif
