#include "PlayState.h"

#include "Ship.h"
#include "GameObjectManager.h"

void PlayState::Start()
{
	m_ship = new Ship();
	GameObjectManager::SpawnObject(m_ship);
}

void PlayState::Update(float _dt)
{

}

void PlayState::Draw()
{

}

void PlayState::OnDestroy()
{
	GameObjectManager::DestroyObject(m_ship);
}
