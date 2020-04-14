#include "Regular.h"

std::vector<Vector2> Regular::Sample(int count)
{
	int sampleRow = std::sqrtf(count);

	std::vector<Vector2> result(std::pow(sampleRow, 2));


	for (auto x = 0; x < sampleRow; x++)
	{
		for (auto y = 0; y < sampleRow; y++)
		{
			float fracX = (x + 0.5f) / sampleRow;
			float fracY = (y + 0.5f) / sampleRow;

			int temp = x * sampleRow + y;
			result[temp] = Vector2(fracX, fracY);
		}
	}

	return result;
}
