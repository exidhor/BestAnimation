#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <map>
#include <vector>
#include "Transformation.hpp"
#include "TimeAnim.hpp"

class TranslationTransformation : public Transformation
{
private:
	sf::Vector2f m_targetPoint;
	float m_speedOrd;
	TimeAnim m_time;
	bool m_isDeterminedByTime;
public:
	TranslationTransformation(sf::Sprite* spriteTarget);

	void initTranslationByTargetPoint(double time, sf::Vector2f const& targetPoint);
	void initTranslationBySpeed(double time, sf::Vector2f const& speedPerSecond);

	virtual bool actualize(double time);
};