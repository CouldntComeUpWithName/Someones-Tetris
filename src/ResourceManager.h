#pragma once
#include"pch.h"


template<typename ResourceType, typename IdentifierType = std::string>
class ResourceManager
{
public:
	ResourceManager();
	
	template<typename ...Args>
	static void Load(const IdentifierType& id, Args&&... args);
	
	static ResourceType& Get(const IdentifierType& id);
	
	~ResourceManager();
private:
	static void Load(const IdentifierType& id);
	
	std::unordered_map<IdentifierType, std::unique_ptr<ResourceType>> m_resources;
	
	static ResourceManager<ResourceType, IdentifierType>* m_manager_ptr;
};



using TextureManager = ResourceManager<sf::Texture, std::string>;
using SoundManager = ResourceManager<sf::Sound, std::string>;
using ShaderManager = ResourceManager<sf::Shader, std::string>;
using FontManager = ResourceManager<sf::Font, std::string>;

#include"ResourceManager.inl"
