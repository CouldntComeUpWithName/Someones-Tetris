#pragma once
#include"../src/pch.h"
#include "ResourceManager.h"

template<typename ResourceType, typename IdentifierType>
ResourceManager<ResourceType, IdentifierType>* ResourceManager<ResourceType, IdentifierType>::m_manager_ptr = nullptr;

template<typename ResourceType, typename IdentifierType>
template<typename ...Args>
inline bool ResourceManager<ResourceType, IdentifierType>::Load(const IdentifierType& id, Args&&... args)
{
	std::unique_ptr<ResourceType> resource_ptr = std::make_unique<ResourceType>();
	if (!resource_ptr->loadFromFile(std::forward<Args>(args)...))
		return false;

	m_manager_ptr->m_resources.emplace(id, std::move(resource_ptr));
}

template<typename ResourceType, typename IdentifierType>
inline bool ResourceManager<ResourceType, IdentifierType>::Load(const IdentifierType& id)
{
	//Does nothing, but returns 'true' which means loading resources is succeeded
	return true;
}

template<typename ResourceType, typename IdentifierType>
inline ResourceManager<ResourceType, IdentifierType>::ResourceManager()
{
	if (m_manager_ptr != nullptr)
		throw std::runtime_error("FUKC");

	m_manager_ptr = this;
}



template<typename ResourceType, typename IdentifierType>
inline ResourceType& ResourceManager<ResourceType, IdentifierType>::Get(const IdentifierType& id)
{
	return *m_manager_ptr->m_resources[id];
}

template<typename ResourceType, typename IdentifierType>
inline ResourceManager<ResourceType, IdentifierType>::~ResourceManager()
{
	m_manager_ptr = nullptr;
}


