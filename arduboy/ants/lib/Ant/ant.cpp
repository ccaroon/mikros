// #include "Arduino.h"
#include "stdlib.h"

#include "ant.h"
#include "point.h"

Ant::Ant(const char* name, const Point& startPos) {
    // Private vars
    this->isDead   = false;
    this->name     = name;
    this->location = startPos;
    this->campID = 1;

    this->age   = 1;
    this->lastDirection = Direction::none;
    this->nextDirection = this->chooseDirection();
    this->lastAction    = Action::none;
    this->daysCamping   = 0;
    this->isFollowing   = false;

    this->edgeBehavior = EdgeBehavior::hitWall;
}

Direction Ant::randomDirection() {
    
    Direction d;





    return(d);
};

// Direction Ant::chooseDirection() {
//     Direction newDirection = Direction::none;
//
//     this->lastDirection = this->nextDirection;
//     // Make sure we don't go back to where we just left
//     do {
//         newDirection = Math.ceil(Math.random() * 8);
//     } while (Math.abs(newDirection - this.lastDirection) === 4);
//
//     this.nextDirection = newDirection;
//
//     return ();
// };

// Ant::chooseDistance() {
//     int d = random(MIN_DISTANCE, MAX_DISTANCE);
//     // var d = 15;
//     return (d);
// };
//
// Ant::move (distance, maxX, maxY) {
//     var newX = this._location.x, newY = this._location.y;
//
//     switch (this.nextDirection) {
//         case Ant.N:
//             newY -= distance;
//             break;
//         case Ant.NE:
//             newX += distance;
//             newY -= distance;
//             break;
//         case Ant.E:
//             newX += distance;
//             break;
//         case Ant.SE:
//             newX += distance;
//             newY += distance;
//             break;
//         case Ant.S:
//             newY += distance;
//             break;
//         case Ant.SW:
//             newX -= distance;
//             newY += distance;
//             break;
//         case Ant.W:
//             newX -= distance;
//             break;
//         case Ant.NW:
//             newX -= distance;
//             newY -= distance;
//             break;
//     }
//
//     this.age += 1;
//     this.lastAction    = Ant.ACTION_MOVE;
//     this.chooseDirection();
//     this.daysCamping   = 0;
//
//     if (Ant.EDGE_BEHAVIOR === Ant.EDGE_WRAP) {
//         if (newX < 0) {
//             newX = maxX + newX;
//         }
//         if (newX > maxX) {
//             newX = newX - maxX;
//         }
//         if (newY < 0) {
//             newY = maxY + newY;
//         }
//         if (newY > maxY) {
//             newY = newY - maxY;
//         }
//     }
//     else if (Ant.EDGE_BEHAVIOR === Ant.EDGE_HIT_WALL) {
//         if (newX < 0) {
//             newX = 0;
//         }
//         if (newX > maxX) {
//             newX = maxX;
//         }
//         if (newY < 0) {
//             newY = 0;
//         }
//         if (newY > maxY) {
//             newY = maxY;
//         }
//     }
//     else {
//         // EDGE_FALL_OFF
//         if (newX < 0 || newX > maxX || newY < 0 || newY > maxY) {
//             this._isDead = true;
//         }
//     }
//
//     this._location = new Point(newX, newY);
//
//     return (this._location);
// };
//
// Ant::camp() {
//     var loc = this.getLocation(), boundaries;
//
//     if (this.lastAction === Ant.ACTION_MOVE) {
//         boundaries = new Rectangle(
//             loc.x - (Ant.CAMP_SIZE/2),
//             loc.y - (Ant.CAMP_SIZE/2),
//             Ant.CAMP_SIZE,
//             Ant.CAMP_SIZE
//         );
//         this._campLocations.push(
//             {
//                 id:         this._campID++,
//                 location:   loc,
//                 boundaries: boundaries,
//                 direction:  this.nextDirection
//             }
//         );
//     }
//
//     this.age += 1;
//     this.lastAction = Ant.ACTION_CAMP;
//     this.daysCamping += 1;
// };
//
// Ant::followTrail(ant, siteID) {
//     var site = ant.getCampSite(siteID);
//
//     this.isFollowing = true;
//     this._location = site.location;
//     this.nextDirection = site.direction;
// };
//
// Ant::isDead() {
//     return(this._isDead);
// };
//
// Ant::inCampSite(ant) {
//     var i, site, siteID = null, antLoc = ant.getLocation();
//
//     // Reverse lookup. Want the most recent time at a site
//     for (i = this._campLocations.length-1; i >= 0; i-=1) {
//         site = this._campLocations[i];
//
//         if (site.boundaries.containsPoint(antLoc)) {
//             siteID = site.id;
//             break;
//         }
//     }
//
//     return(siteID);
// };
//
// Ant::crossesCampSite(path) {
//     var i, site = null;
//
//     // Reverse lookup. Want the most recent time at a site
//     for (i = this._campLocations.length-1; i >= 0; i-=1) {
//         site = this._campLocations[i];
//
//         if (path.intersectRect(site.boundaries)) {
//             break;
//         }
//         else {
//             site = null;
//         }
//     }
//
//     return(site);
// };
//
// Ant::lastCampSiteLocation() {
//     return(this._campLocations[this._campLocations.length-1]);
// };
//
// Ant::getCampSite(siteID) {
//     return (this._campLocations[siteID-1]);
// };
//
// Ant::getLocation() {
//     return (this._location);
// };
