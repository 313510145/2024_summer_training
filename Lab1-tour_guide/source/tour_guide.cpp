#include "tour_guide.h"

const int tour_guide::TOUR_MAP_SIZE = 5, tour_guide::NUM_DIRECTION = 8;
const coordinate* tour_guide::DIRECTION = new coordinate[tour_guide::NUM_DIRECTION] {
    {.x = -1, .y =  2},
    {.x =  1, .y =  2},
    {.x =  2, .y =  1},
    {.x =  2, .y = -1},
    {.x =  1, .y = -2},
    {.x = -1, .y = -2},
    {.x = -2, .y = -1},
    {.x = -2, .y =  1}
};

const void tour_guide::input_toured_track_and_tour(std::istream& is) {
    unsigned int num_step, i;
    int j;
    step current_step;
    coordinate next_coordinate;
    is >> num_step >> current_step.position.x >> current_step.position.y;   // input first step
    this->tour_map[current_step.position.x][current_step.position.y] = 1;
    for (i = 1; i < num_step; i = i + 1) {                                  // input rest steps
        is >> next_coordinate.x >> next_coordinate.y;
        this->tour_map[next_coordinate.x][next_coordinate.y] = 1;
        for (j = 0; j < this->NUM_DIRECTION; j = j + 1) {                   // find direction
            if (
                (next_coordinate.x - current_step.position.x == this->DIRECTION[j].x) &&
                (next_coordinate.y - current_step.position.y == this->DIRECTION[j].y)
            ) {
                current_step.move_way = j;
                this->tour_track.push(current_step);
                current_step.position = next_coordinate;                    // next position
                break;
            }
        }
    }
    int from_way = 0;
    for (; i < this->TOUR_MAP_SIZE * this->TOUR_MAP_SIZE;) {                // repeatedly try and backtrack
        for (j = from_way; j < this->NUM_DIRECTION; j = j + 1) {
            next_coordinate.x = current_step.position.x + this->DIRECTION[j].x;
            next_coordinate.y = current_step.position.y + this->DIRECTION[j].y;
            if (                                                            // legal position and not toured
                (next_coordinate.x >= 0) &&
                (next_coordinate.y >= 0) &&
                (next_coordinate.x < this->TOUR_MAP_SIZE) &&
                (next_coordinate.y < this->TOUR_MAP_SIZE) &&
                (this->tour_map[next_coordinate.x][next_coordinate.y] == 0)
            ) {
                current_step.move_way = j;
                this->tour_track.push(current_step);
                current_step.position = next_coordinate;                    // next position
                this->tour_map[current_step.position.x][current_step.position.y] = 1;
                from_way = 0;
                i = i + 1;
                break;
            }
        }
        if (this->tour_track.empty()) {
            break;
        }
        else if (j == this->NUM_DIRECTION) {                                // no solution
            this->tour_map[current_step.position.x][current_step.position.y] = 0;
            current_step = this->tour_track.top();
            this->tour_track.pop();
            from_way = current_step.move_way + 1;                           // do backtrack
            i = i - 1;
        }
    }
    current_step.move_way = -1;                                             // all toured
    this->tour_track.push(current_step);                                    // complete touring
}

const void tour_guide::output_tour_map(std::ostream& os) const {
    for (unsigned int i = 0; i < this->TOUR_MAP_SIZE; i = i + 1) {
        for (unsigned int j = 0; j < this->TOUR_MAP_SIZE; j = j + 1) {
            if (this->tour_map[i][j] == 0) {
                os << " ";
            }
            else {
                os << "X";
            }
        }
        os << std::endl;
    }
}

const void tour_guide::output_tour_track(std::ostream& os) const {
    std::stack<step> temp_stack_a = this->tour_track, temp_stack_b;
    while (!(temp_stack_a.empty())) {
        temp_stack_b.push(temp_stack_a.top());
        temp_stack_a.pop();
    }
    while (!(temp_stack_b.empty())) {
        os << temp_stack_b.top().position.x << " " << temp_stack_b.top().position.y << std::endl;
        temp_stack_b.pop();
    }
}

tour_guide::tour_guide() {
    this->tour_map = new bool*[this->TOUR_MAP_SIZE];
    for (unsigned int i = 0; i < this->TOUR_MAP_SIZE; i = i + 1) {
        // this->tour_map[i] = new bool[this->TOUR_MAP_SIZE] ();
        this->tour_map[i] = new bool[this->TOUR_MAP_SIZE] {0};      // or above
    }
}

tour_guide::~tour_guide() {
    for (unsigned int i = 0; i < this->TOUR_MAP_SIZE; i = i + 1) {
        delete [] this->tour_map[i];
    }
    delete [] this->tour_map;
    this->tour_track = std::stack<step> ();
}
