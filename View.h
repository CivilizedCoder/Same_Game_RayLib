#ifndef VIEW_H
#define VIEW_H

#include "Themodel.h"

class View {
private:
    Themodel* board;

public:
    View(Themodel &b);
    void display();
};

#endif
