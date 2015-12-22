#include "TranslationTransformation.hpp"

TranslationTransformation::TranslationTransformation(sf::Sprite* spriteTraget)
	:LinearTransformation(spriteTraget)
{

}

void TranslationTransformation::placeSpriteToTheEndOfTransformation()
{
	m_spriteTarget->setPosition(m_targetPoint);
}

void TranslationTransformation::doTheTransformation(sf::Vector2f const& deplacement)
{
	m_spriteTarget->move(deplacement);
}