#ifndef TOUR_GUIDE_H
#define TOUR_GUIDE_H

#include <iostream>
#include <stack>

struct coordinate {
    int x, y;
};

struct step {
    coordinate position;
    int move_way;           // direction of next step
};

class tour_guide {
    public:
        const void input_toured_track_and_tour(std::istream& is);
        const void output_tour_map(std::ostream& os) const;
        const void output_tour_track(std::ostream& os) const;
        tour_guide();
        ~tour_guide();
    private:
        static const int TOUR_MAP_SIZE, NUM_DIRECTION;
        static const coordinate* DIRECTION;
        bool** tour_map;
        std::stack<step> tour_track;
};

#endif
