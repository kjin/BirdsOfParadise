#include "Sprite3DModel.h"
#include <string>
#include "StringUtils.h"

using namespace cocos2d;
using namespace std;

bool Sprite3DModel::init()
{
	return true;
}

static Sprite3DModel* createFromFile(const char* fileName)
{
	Data data = FileUtils::getInstance()->getDataFromFile(fileName);
	string str((char*)(data.getBytes()));
	bop::StringDelimiter lines = bop::StringDelimiter(bop::StringUtils::ConvertToUnixLineEndings(str), '\n');
	int lineNo = 0;
	// for each pixel
	while (lines.hasNext())
	{
		// definitely some room for improvement here.
		float x = 0;
		float y = 0;
		float z = 0;
		bool success = false;
		bop::StringDelimiter coordinates = bop::StringDelimiter(lines.getNext(), ' ');
		if (coordinates.hasNext())
		{
			x = atof(coordinates.getNext().c_str());
			if (coordinates.hasNext())
			{
				y = atof(coordinates.getNext().c_str());
				if (coordinates.hasNext())
				{
					z = atof(coordinates.getNext().c_str());
					success = true;
				}
			}
		}
		if (!success)
		{
			CCLOG("BoP warning: invalid input in file %s, line %d.", fileName, lineNo);
		}
		lineNo++;
	}
}
