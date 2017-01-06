#include "include/global.hpp"

WeightedQueue::WeightedQueue()
{

}

void WeightedQueue::push(int weightValue, int nodeId)
{
    WeightedNode weightedNode;

    weightedNode.weightValue = weightValue;
    weightedNode.nodeId = nodeId;

    mNodeVec.push_back(weightedNode);
    std::sort(mNodeVec.begin(), mNodeVec.end(), orderLeastWeight());
}

bool WeightedQueue::empty()
{
    return mNodeVec.empty();
}


int WeightedQueue::get()
{
    int nodeId = mNodeVec.begin()->nodeId;

    mNodeVec.erase(mNodeVec.begin());
    return nodeId;
}
