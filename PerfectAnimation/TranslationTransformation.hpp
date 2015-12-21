#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <map>
#include <vector>
#include "Transformation.hpp"

class TranslationTransformation : public Transformation
{
private:
	sf::Vector2f m_targetPoint;
	bool m_endDeterminedByDeplacement;
	float m_speedOrd;
public:
	TranslationTransformation(sf::Sprite* spriteTarget);

	void initTranslationByTime(sf::Vector2f const& targetPoint, double time);
	void initTranslationByDeplacement(sf::Vector2f const& speedPerSecond, sf::Vector2f const& targetPoint);

	virtual bool actualize(double time);
};