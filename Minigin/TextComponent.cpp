#include <stdexcept>
#include <SDL_ttf.h>
#include "TextComponent.h"
#include "Renderer.h"
#include "Font.h"
#include "Texture2D.h"
#include "Transform.h"




//dae::TextComponent::TextComponent(const std::string& text, std::shared_ptr<Font> font) 
//	: m_needsUpdate(true), m_text(text), m_font(std::move(font)), m_textTexture(nullptr)
//{ }

dae::TextComponent::TextComponent():
	m_needsUpdate(true), m_needsAlwaysUpdate(false)
{
}

void dae::TextComponent::Update(float)
{
	if (m_needsUpdate || m_needsAlwaysUpdate)
	{
		const SDL_Color color = { 255,255,255,255 }; // only white text is supported now
		const auto surf = TTF_RenderText_Blended(m_font->GetFont(), m_text.c_str(), color);
		if (surf == nullptr) 
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr) 
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		m_textTexture = std::make_shared<Texture2D>(texture);
		m_needsUpdate = false;
	}
}

void dae::TextComponent::FixedUpdate(float)
{
}

void dae::TextComponent::Render(glm::vec3 pos) const
{
	if (m_textTexture != nullptr)
	{
		//const auto& pos = m_transform.GetPosition();
		Renderer::GetInstance().RenderTexture(*m_textTexture, pos.x, pos.y);
	}
}

// This implementation uses the "dirty flag" pattern
void dae::TextComponent::SetText(const std::string& text)
{
	m_text = text;
	m_needsAlwaysUpdate = true;
}

void dae::TextComponent::SetPosition(const float x, const float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

void dae::TextComponent::SetFont(std::shared_ptr<Font> font)
{
	m_font = std::move(font);
}

void dae::TextComponent::SetNeedsAlwaysUpdate(bool needsUpdate)
{
	m_needsAlwaysUpdate = needsUpdate;
}


