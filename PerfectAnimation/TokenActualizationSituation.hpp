#pragma once

class TokenActualizationSituation
{
public:
	bool isNewFrame;
	bool isFinish;

	TokenActualizationSituation(bool newFrame, bool finish)
	{
		isNewFrame = newFrame;
		isFinish = finish;
	}
};