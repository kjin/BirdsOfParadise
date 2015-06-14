#ifndef _ARRAY_2D_H_
#define _ARRAY_2D_H_

#include <vector>
#include <stdexcept>

/**
 * A class that represents a jagged 2D array of items.
 */
template <class T>
class Array2D
{
private:
	std::vector<std::vector<T> > _arr;
	size_t _bigSize;
	std::vector<size_t> _smallSizes;
public:
	Array2D() : _bigSize(0) {}

	void addRow()
	{
		_arr.push_back(std::vector<T>());
		_bigSize++;
	}
	
	void addNumRows(size_t numRows)
	{
		_bigSize += numRows;
		for (unsigned i = 0; i < numRows; i++)
		{
			_arr.push_back(std::vector<T>());
			_smallSizes.push_back(0);
		}
	}

	void addItem(unsigned vectorID, T item)
	{
		if (vectorID < _bigSize)
		{
			_arr[vectorID].push_back(item);
		}
		else
		{
			throw std::invalid_argument("VectorID is out of bounds.");
		}
	}

	inline unsigned getNumRows() const
	{
		return _bigSize;
	}

	inline unsigned getNumItems(unsigned vectorID) const
	{
		if (vectorID < _bigSize)
		{
			return _smallSizes[vectorID];
		}
		else
		{
			throw std::invalid_argument("VectorID is out of bounds.");
		}
	}

	inline T getItem(unsigned vectorID, unsigned itemID) const
	{
		if (vectorID < _bigSize)
		{
			return _arr[vectorID][itemID];
		}
		else
		{
			throw std::invalid_argument("VectorID is out of bounds.");
		}
	}

	void clearItems(unsigned vectorID)
	{
		if (vectorID < _bigSize)
		{
			_arr[vectorID].clear();
			_smallSizes[vectorID] = 0;
		}
		else
		{
			throw std::invalid_argument("VectorID is out of bounds.");
		}
	}
};

#endif