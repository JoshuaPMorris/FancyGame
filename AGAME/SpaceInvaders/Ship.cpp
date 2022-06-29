#include "Ship.h"

#include "Assets.h"
#include "Config.h" // lowercase c is for raylib

#include "Gizmos.h"

void Ship::Start()
{
	m_speed = Config::GetFloatValue(SHIP_CATEGORY, "speed");
	m_rotationSpeed = Config::GetFloatValue(SHIP_CATEGORY, "rotationSpeed");

	m_texture = Assets::GetTexture("blue");

	position.x = Config::GetIntValue(PROGRAM_CATEGORY, "width") / 2 - m_texture.width / 2;
	position.y = Config::GetIntValue(PROGRAM_CATEGORY, "height") - m_texture.height / 2;

	rotation = -90;
}

void Ship::Update(float _dt)
{
	rotation += (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * m_rotationSpeed * _dt;
	float input = IsKeyDown(KEY_W) - IsKeyDown(KEY_S);

	// if (Gizmos::drawGizmos)
	// 	Gizmos::DrawRay(Ray2D{ position, Vector2Scale(GetForward(), input), 50.0f }, GREEN);

	position = Vector2Add(position, Vector2Scale(GetForward(), m_speed * _dt));
}

void Ship::Draw()
{
	Rectangle src;
	src.x = 0;
	src.y = 0;
	src.width = m_texture.width;
	src.height = m_texture.height;

	Rectangle dst;
	dst.x = position.x;
	dst.y = position.y;
	dst.width = m_texture.width;
	dst.height = m_texture.height;

	Vector2 origin = { src.width / 2, src.height / 2 };

	DrawTexturePro(m_texture, src, dst, origin, rotation, color);
}

void Ship::OnDestroy()
{

}
