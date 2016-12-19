class InputMomentum
{

public:

InputMomentum();
~InputMomentum();

const PointInt & decay();
void update(const int & x, const int & y);

private:

PointInt mMomentum;
PointDouble mDecayRate;

int mDecayCounter;
int mDecayCounterLimit;

};
