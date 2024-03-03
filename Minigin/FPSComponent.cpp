#include "FPSComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Transform.h"
#include <chrono>
#include "TextComponent.h"
#include "GameObject.h"
#include <iostream>

dae::FPSComponent::FPSComponent(GameObject* gameObject) :
    BaseComponent(gameObject),
    m_FrameCount{0}, m_Fps{0.0f}, m_ElapsedTime{0.0f}, m_TextComponent{}
{
   if (GetOwner() != nullptr) {
       m_TextComponent = GetOwner()->GetComponent<TextComponent>();
       std::cout << "Constructor complete.\n";
       
   }
}
dae::FPSComponent::~FPSComponent()
{
    delete m_TextComponent;
}

void dae::FPSComponent::Update(float deltaTime)
{
    // Increment frame count
    m_FrameCount++;

    // Accumulate elapsed time
    m_ElapsedTime += deltaTime;
   // std::cout << m_ElapsedTime << std::endl;
    // If one second has elapsed, calculate FPSComponent
    if (m_ElapsedTime >= 1.0f) {
        std::cout << "1 sec elapsed\n";
        // Calculate FPSComponent
        m_Fps = static_cast<float>(m_FrameCount) / m_ElapsedTime;
        std::cout << "fps: " << m_Fps << std::endl;
        std::string fpsText = std::format("{:.1f} fps", m_Fps);
        m_TextComponent->SetText(fpsText);
        // Reset frame count and elapsed time for next second
        m_FrameCount = 0;
        m_ElapsedTime -= 1.0f;
    }
}


void dae::FPSComponent::FixedUpdate(float)
{
}

void dae::FPSComponent::Render(glm::vec3) const
{
}

void dae::FPSComponent::SetTextComponent(TextComponent* component)
{
    m_TextComponent = component;
}

float dae::FPSComponent::GetFps() const
{
	return m_Fps;
}


