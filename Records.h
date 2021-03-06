//
// Created by liu_k on 08/12/2020.
//

#ifndef ACT5_2_RECORDS_H
#define ACT5_2_RECORDS_H

#include "Record.h"

class Records {
    private:
        std::vector<Record> data;
    public:
        Records();
        void get_by_year();
        void get_by_brand();
        void get_by_media();
        void get_by_price();

    friend std::ostream& operator<<(std::ostream& os, const Records& obj);
};

#endif //ACT5_2_RECORDS_H
