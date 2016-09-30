#include "point.h"

typedef struct {
    int foo;
} CampSite;

enum class Action {
    none, move, camp
};

enum class EdgeBehavior {
    hitWall, fallOff, wrap
};

enum class Direction {
    none,
    N = 1,
    NE,
    E,
    SE,
    S,
    SW,
    W,
    NW
};

const int CAMP_SIZE   = 6;
const int MIN_DISTANCE = 15;
const int MAX_DISTANCE = 30;
// EdgeBehavior EDGE_BEHAVIOR = EdgeBehavior::hitWall;

class Ant {
public:
    Ant();
    Ant(const char*, const Point& startPos);

    Direction chooseDirection();
private:
    bool isDead = false;
    const char* name;
    Point location;
    int campID;
    CampSite campLocation[];

    int age;
    Direction lastDirection;
    Direction nextDirection;
    Action lastAction;
    int daysCamping = 0;
    bool isFollowing = false;

    EdgeBehavior edgeBehavior;
};
