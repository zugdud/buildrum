struct WeightedNode
{
    int nodeId;
    int weightValue;
};

struct orderLeastWeight
{
    inline bool operator()(const WeightedNode& weightedNode1, const WeightedNode& weightedNode2)
    {
        return (weightedNode1.weightValue < weightedNode2.weightValue);
    }
};

// The Weighted queue always returns the lowest weight value node from get()
class WeightedQueue {
public:

WeightedQueue();
int get();       // return the item with the lowest weight value and remove it from the map
void push(int weight, int NodeId);     // add item
bool empty();     // is it empty

private:

std::vector <WeightedNode> mNodeVec;     //  nodeId

};
