#include "MovingAverager.hpp"

MovingAverager::MovingAverager(const std::string& id, size_t windowSize) : Subscriber(id), windowSize(windowSize)
{
}

void MovingAverager::signal(Message message)
{
	messages.push_back(message);
}

int MovingAverager::read() const
{
    if(messages.size() == 0)
    {
        return 0;
    }

    int allData = 0;
    size_t windowTemp = windowSize;

    for (int i = messages.size() - 1; i >= 0; i--)
    {
        if (windowTemp == 0)
        {
            return allData / windowSize;
        }
        allData += messages[i].data;
        windowTemp--;
    }

    return allData / messages.size();
}

Subscriber* MovingAverager::clone() const
{
	return new MovingAverager(*this);
}
