#include "queue.hh"
#include "iostream"
// Implement the member functions of Queue here

Queue::Queue(unsigned int cycle)
{
    cycle_ = cycle;
    how_many_passes_left_ = cycle;
}

Queue::~Queue()
{
    Vehicle *temp = first_;
    while (first_ != nullptr) {
        first_ = first_->next;
        delete temp;
        temp = first_;
    }
}

void Queue::enqueue(const string &reg)
{
    if (is_green_) {
        --how_many_passes_left_;
        cout << "GREEN: The vehicle "<< reg <<" need not stop to wait" << endl;
//        if (how_many_passes_left_ == 0){
//           is_green_ = false;
//           return;
//        }
//        --how_many_passes_left_;


    } else {
        add_car(reg);
    }
}

void Queue::switch_light()
{
    if (is_green_){ // vaihtuu punaiseksi
        is_green_ = false;
        std::cout << "RED: No vehicles waiting in traffic lights" << std::endl;

    } else { // vaihtuu vihreäksi
        is_green_ = true;
        how_many_passes_left_ = cycle_;

        std::cout << "GREEN: ";

        if (first_ == nullptr){
            std::cout << "No vehicles waiting in traffic lights" << std::endl;
            return;
        }
        std::cout << "Vehicle(s) ";
        while (how_many_passes_left_ != 0) {
            --how_many_passes_left_;
            if (not dequeue()) {
                break;
            }
        }
        cout << "can go on" << std::endl;
        how_many_passes_left_ = 0;
        is_green_ = false;
    }
}

void Queue::reset_cycle(unsigned int cycle)
{
    cycle_ = cycle;
}

void Queue::print() const
{
    if (is_green_){
        std::cout << "GREEN: ";

    } else {
        std::cout << "RED: ";

    }
    if (first_ == nullptr){
        std::cout << "No vehicles waiting in traffic lights" << std::endl;

    } else {
        std::cout << "Vehicle(s) ";

        Vehicle *current_car = first_;
        while(current_car !=nullptr){
            std::cout << current_car->reg_num << " ";
            current_car = current_car->next;
        }
        std::cout << "waiting in traffic lights" << std::endl;

    }
}

void Queue::add_car(string reg_num)
{
    Vehicle *new_car = new Vehicle;
    new_car->reg_num = reg_num;
    new_car->next = nullptr;

    if (first_ == nullptr){
        first_ = new_car;
        last_ = new_car;
    } else {
        last_->next = new_car;
    }

    last_ = new_car;
}

bool Queue::dequeue()
{
    if (first_ == nullptr){
        return false;
    }
    Vehicle *temp = first_;
    first_ = first_->next;

    cout << temp->reg_num << " ";

    delete temp;
    return true;
}
